# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    todo_ffi.py                                               +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:27:00 by lucas                                     #
#    Updated: 2026/10/30 09:33:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import ctypes
from pathlib import Path


class TodoItemView(ctypes.Structure):
    """Mirror the caller-owned item buffer from todo_core.h."""

    _fields_ = [
        ("identifier", ctypes.c_uint64),
        ("completed", ctypes.c_bool),
        ("title", ctypes.c_void_p),
        ("title_capacity", ctypes.c_size_t),
        ("title_length", ctypes.c_size_t),
    ]


def _configure_lifecycle(library: ctypes.CDLL) -> None:
    """Declare ownership signatures for app handles."""
    library.todo_app_create.argtypes = []
    library.todo_app_create.restype = ctypes.c_void_p
    library.todo_app_destroy.argtypes = [ctypes.c_void_p]
    library.todo_app_destroy.restype = None


def _configure_commands(library: ctypes.CDLL) -> None:
    """Declare mutation signatures for Todo commands."""
    library.todo_add.argtypes = [
        ctypes.c_void_p,
        ctypes.c_char_p,
        ctypes.POINTER(ctypes.c_uint64),
    ]
    library.todo_add.restype = ctypes.c_int
    library.todo_toggle.argtypes = [ctypes.c_void_p, ctypes.c_uint64]
    library.todo_toggle.restype = ctypes.c_int
    library.todo_remove.argtypes = [ctypes.c_void_p, ctypes.c_uint64]
    library.todo_remove.restype = ctypes.c_int


def _configure_queries(library: ctypes.CDLL) -> None:
    """Declare snapshot signatures for Todo queries."""
    library.todo_count.argtypes = [ctypes.c_void_p]
    library.todo_count.restype = ctypes.c_size_t
    library.todo_get.argtypes = [
        ctypes.c_void_p,
        ctypes.c_size_t,
        ctypes.POINTER(TodoItemView),
    ]
    library.todo_get.restype = ctypes.c_int


def load_library(path: str | Path) -> ctypes.CDLL:
    """Load and configure the shared Todo core from an explicit path."""
    library = ctypes.CDLL(str(path))
    _configure_lifecycle(library)
    _configure_commands(library)
    _configure_queries(library)
    return library
