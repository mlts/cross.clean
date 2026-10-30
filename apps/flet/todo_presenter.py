# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    todo_presenter.py                                         +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:30:00 by lucas                                     #
#    Updated: 2026/10/30 09:30:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

from bindings.python.todo_client import TodoClient
from bindings.python.todo_model import TodoItem
from bindings.python.todo_query import list_items


class TodoPresenter:
    """Translate Flet UI intent into the shared Todo application port."""

    def __init__(self, client: TodoClient) -> None:
        self.client = client

    def add(self, title: str) -> tuple[TodoItem, ...]:
        """Add a Todo and return the refreshed snapshot."""
        self.client.add(title)
        return list_items(self.client)

    def toggle(self, identifier: int) -> tuple[TodoItem, ...]:
        """Toggle a Todo and return the refreshed snapshot."""
        self.client.toggle(identifier)
        return list_items(self.client)

    def remove(self, identifier: int) -> tuple[TodoItem, ...]:
        """Remove a Todo and return the refreshed snapshot."""
        self.client.remove(identifier)
        return list_items(self.client)

    def items(self) -> tuple[TodoItem, ...]:
        """Return the current immutable Todo snapshot."""
        return list_items(self.client)
