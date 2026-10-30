# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    test_todo_query.py                                        +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:25:00 by lucas                                     #
#    Updated: 2026/10/30 09:44:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import ctypes
import unittest
from types import SimpleNamespace
from unittest.mock import Mock

from bindings.python.todo_client import TodoClient
from bindings.python.todo_query import list_items


def _get_item(_handle: object, _index: int, output: object) -> int:
    """Fill either the sizing view or the allocated title buffer."""
    view = output._obj
    view.identifier = 12
    view.completed = True
    view.title_length = 4
    if view.title_capacity <= view.title_length:
        return 4
    ctypes.memmove(view.title, b"Test\0", 5)
    return 0


class TestTodoQuery(unittest.TestCase):
    """Verify snapshots cross the C ABI without leaking ownership."""

    def test_list_with_native_item_returns_immutable_model(self) -> None:
        library = SimpleNamespace()
        library.todo_count = Mock(return_value=1)
        library.todo_get = Mock(side_effect=_get_item)
        client = TodoClient(library, ctypes.c_void_p(7))

        items = list_items(client)

        self.assertEqual(items[0].title, "Test")
        self.assertTrue(items[0].completed)


if __name__ == "__main__":
    unittest.main()
