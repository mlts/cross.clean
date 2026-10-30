# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    main.py                                                   +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:30:00 by lucas                                     #
#    Updated: 2026/10/30 09:30:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import os
from pathlib import Path

import flet as ft

from apps.flet.todo_presenter import TodoPresenter
from apps.flet.todo_screen import TodoScreen
from bindings.python.todo_client import TodoClient
from bindings.python.todo_ffi import load_library


def main(page: ft.Page) -> None:
    """Compose the Flet driver with the native Todo adapter."""
    library_path = os.environ.get("TODO_CORE_LIBRARY")
    if not library_path:
        raise RuntimeError("TODO_CORE_LIBRARY must name the native core")
    client = TodoClient(load_library(Path(library_path)))
    page.title = "Todo"
    page.theme_mode = ft.ThemeMode.DARK
    page.padding = 24
    page.on_disconnect = lambda _: client.close()
    TodoScreen(page, TodoPresenter(client))


if __name__ == "__main__":
    ft.run(main)
