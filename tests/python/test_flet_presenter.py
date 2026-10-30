# **************************************************************************** #
#                                                                              #
#                                                              +#              #
#    test_flet_presenter.py                                    +##             #
#                                                            +###+             #
#    By: lucas <lucas@tsiaraso.com>                                            #
#                                                            +###+             #
#    Created: 2026/10/30 09:29:00 by lucas                                     #
#    Updated: 2026/10/30 09:41:00 by lucas                                     #
#                                                               #+             #
# **************************************************************************** #

import unittest
from unittest.mock import Mock, patch

from apps.flet.todo_presenter import TodoPresenter


class TestTodoPresenter(unittest.TestCase):
    """Verify UI actions depend only on the Todo application port."""

    @patch("apps.flet.todo_presenter.list_items")
    def test_add_with_title_refreshes_snapshot(self, items: Mock) -> None:
        client = Mock()
        items.return_value = ("snapshot",)
        presenter = TodoPresenter(client)

        result = presenter.add("Ship Todo")

        client.add.assert_called_once_with("Ship Todo")
        self.assertEqual(result, ("snapshot",))

    @patch("apps.flet.todo_presenter.list_items")
    def test_toggle_refreshes_snapshot(self, items: Mock) -> None:
        client = Mock()
        presenter = TodoPresenter(client)

        presenter.toggle(7)

        client.toggle.assert_called_once_with(7)
        items.assert_called_once_with(client)


if __name__ == "__main__":
    unittest.main()
