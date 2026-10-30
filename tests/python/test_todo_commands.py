# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    test_todo_commands.py                                     +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:25:00 by lucas                                     #
#    Updated: 2026/10/30 09:25:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import ctypes
import unittest
from types import SimpleNamespace
from unittest.mock import Mock

from bindings.python.todo_client import TodoClient


def _library() -> SimpleNamespace:
    """Return a deterministic fake for the C ABI command surface."""
    library = SimpleNamespace()
    library.todo_add = Mock(return_value=0)
    library.todo_toggle = Mock(return_value=0)
    library.todo_remove = Mock(return_value=0)
    return library


def _set_identifier(_handle: object, _title: bytes, output: object) -> int:
    """Populate the C ABI output identifier."""
    output._obj.value = 41
    return 0


class TestTodoCommands(unittest.TestCase):
    """Verify Python commands translate values to the C ABI."""

    def test_add_with_valid_title_returns_identifier(self) -> None:
        library = _library()
        library.todo_add.side_effect = _set_identifier
        client = TodoClient(library, ctypes.c_void_p(7))

        identifier = client.add("Ship adapters")

        self.assertEqual(identifier, 41)

    def test_toggle_and_remove_with_identifier_call_core(self) -> None:
        library = _library()
        client = TodoClient(library, ctypes.c_void_p(7))

        client.toggle(9)
        client.remove(9)

        library.todo_toggle.assert_called_once()
        library.todo_remove.assert_called_once()


if __name__ == "__main__":
    unittest.main()
