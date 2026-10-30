# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    todo_model.py                                             +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:27:00 by lucas                                     #
#    Updated: 2026/10/30 09:27:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

from dataclasses import dataclass
from enum import IntEnum


class TodoStatus(IntEnum):
    """Stable status values exported by the Todo C ABI."""

    OK = 0
    INVALID_ARGUMENT = 1
    INVALID_TITLE = 2
    NOT_FOUND = 3
    BUFFER_TOO_SMALL = 4
    NO_MEMORY = 5


class TodoError(RuntimeError):
    """Report a typed failure returned by the shared Todo core."""


@dataclass(frozen=True, slots=True)
class TodoItem:
    """Immutable Todo snapshot safe to expose to Python UIs."""

    identifier: int
    title: str
    completed: bool


def check_status(status: int) -> None:
    """Raise TodoError unless the C ABI returned success."""
    if status == TodoStatus.OK:
        return
    try:
        name = TodoStatus(status).name
    except ValueError as error:
        raise TodoError(f"unknown Todo status: {status}") from error
    raise TodoError(name.lower().replace("_", " "))
