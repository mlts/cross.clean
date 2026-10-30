# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    todo_query.py                                             +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:27:00 by lucas                                     #
#    Updated: 2026/10/30 09:44:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import ctypes

from bindings.python.todo_client import TodoClient
from bindings.python.todo_ffi import TodoItemView
from bindings.python.todo_model import TodoItem, TodoStatus, check_status


def _read_item(client: TodoClient, index: int) -> TodoItem:
    """Read one item using the C ABI two-pass buffer contract."""
    probe = ctypes.create_string_buffer(1)
    view = TodoItemView(
        title=ctypes.cast(probe, ctypes.c_void_p),
        title_capacity=len(probe),
    )
    status = client.library.todo_get(
        client.handle,
        index,
        ctypes.byref(view),
    )
    if status != TodoStatus.BUFFER_TOO_SMALL:
        check_status(status)
    title = ctypes.create_string_buffer(view.title_length + 1)
    view.title = ctypes.cast(title, ctypes.c_void_p)
    view.title_capacity = len(title)
    status = client.library.todo_get(
        client.handle,
        index,
        ctypes.byref(view),
    )
    check_status(status)
    value = title.value.decode("utf-8")
    return TodoItem(view.identifier, value, view.completed)


def list_items(client: TodoClient) -> tuple[TodoItem, ...]:
    """Return an immutable snapshot from the native Todo core."""
    count = client.library.todo_count(client.handle)
    return tuple(_read_item(client, index) for index in range(count))
