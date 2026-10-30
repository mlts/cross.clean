# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    todo_controls.py                                          +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:30:00 by lucas                                     #
#    Updated: 2026/10/30 09:30:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

from collections.abc import Callable

import flet as ft

from bindings.python.todo_model import TodoItem


def todo_control(
    item: TodoItem,
    on_toggle: Callable[[int], None],
    on_remove: Callable[[int], None],
) -> ft.Control:
    """Render one Todo row with injected actions."""
    checkbox = ft.Checkbox(
        label=item.title,
        value=item.completed,
        on_change=lambda _: on_toggle(item.identifier),
        expand=True,
    )
    remove = ft.IconButton(
        icon=ft.Icons.DELETE_OUTLINE,
        tooltip="Remove Todo",
        on_click=lambda _: on_remove(item.identifier),
    )
    return ft.Row([checkbox, remove])
