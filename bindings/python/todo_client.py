# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    todo_client.py                                            +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:27:00 by lucas                                     #
#    Updated: 2026/10/30 09:33:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import ctypes

from bindings.python.todo_model import TodoError, check_status


class TodoClient:
    """Own a Todo core handle and expose its command port."""

    def __init__(
        self,
        library: ctypes.CDLL,
        handle: ctypes.c_void_p | None = None,
    ) -> None:
        self.library = library
        self._owned = handle is None
        self.handle = handle or library.todo_app_create()
        if not self.handle:
            raise TodoError("native Todo core allocation failed")

    def close(self) -> None:
        """Release an owned native handle exactly once."""
        if not self._owned or not self.handle:
            return
        self.library.todo_app_destroy(self.handle)
        self.handle = ctypes.c_void_p()

    def add(self, title: str) -> int:
        """Add a title and return its core-assigned identifier."""
        identifier = ctypes.c_uint64()
        status = self.library.todo_add(
            self.handle,
            title.encode("utf-8"),
            ctypes.byref(identifier),
        )
        check_status(status)
        return identifier.value

    def toggle(self, identifier: int) -> None:
        """Toggle an existing Todo item."""
        check_status(self.library.todo_toggle(self.handle, identifier))

    def remove(self, identifier: int) -> None:
        """Remove an existing Todo item."""
        check_status(self.library.todo_remove(self.handle, identifier))
