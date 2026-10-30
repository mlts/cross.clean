# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    test_todo_lifecycle.py                                    +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:32:00 by lucas                                     #
#    Updated: 2026/10/30 09:32:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import ctypes
import unittest
from types import SimpleNamespace
from unittest.mock import Mock

from bindings.python.todo_client import TodoClient


class TestTodoLifecycle(unittest.TestCase):
    """Verify ownership follows the native lifecycle contract."""

    def test_client_without_handle_owns_returned_core_pointer(self) -> None:
        library = SimpleNamespace()
        library.todo_app_create = Mock(return_value=ctypes.c_void_p(19))
        library.todo_app_destroy = Mock()

        client = TodoClient(library)
        client.close()

        library.todo_app_create.assert_called_once_with()
        library.todo_app_destroy.assert_called_once()


if __name__ == "__main__":
    unittest.main()
