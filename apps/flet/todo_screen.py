# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    todo_screen.py                                            +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:30:00 by lucas                                     #
#    Updated: 2026/10/30 09:30:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import flet as ft

from apps.flet.todo_controls import todo_control
from apps.flet.todo_presenter import TodoPresenter


class TodoScreen:
    """Own the small Flet view state and delegate all rules inward."""

    def __init__(self, page: ft.Page, presenter: TodoPresenter) -> None:
        self.page = page
        self.presenter = presenter
        self.title = ft.TextField(label="What needs doing?", expand=True)
        self.todos = ft.Column(spacing=8)
        add = ft.FilledButton("Add", on_click=self.add)
        page.add(ft.Text("Todo", size=36, weight=ft.FontWeight.BOLD))
        page.add(ft.Row([self.title, add]), self.todos)
        self.refresh()

    def add(self, _event: ft.Event[ft.Control]) -> None:
        """Add the entered title and clear the input."""
        self.presenter.add(self.title.value or "")
        self.title.value = ""
        self.refresh()

    def toggle(self, identifier: int) -> None:
        """Toggle one Todo and refresh the view."""
        self.presenter.toggle(identifier)
        self.refresh()

    def remove(self, identifier: int) -> None:
        """Remove one Todo and refresh the view."""
        self.presenter.remove(identifier)
        self.refresh()

    def refresh(self) -> None:
        """Replace controls from the immutable presenter snapshot."""
        self.todos.controls = [
            todo_control(item, self.toggle, self.remove)
            for item in self.presenter.items()
        ]
        self.page.update()
