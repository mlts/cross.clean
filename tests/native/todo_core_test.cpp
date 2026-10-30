/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_core_test.cpp                                    +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:26:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "todo_core.h"

#include <cassert>
#include <cstring>
#include <cstdint>

void test_todoCore_withValidTitle_addsTodo() {
  todo_app_t* app = todo_app_create();
  std::uint64_t id = 0;
  assert(todo_add(app, "  Ship Todo  ", &id) == TODO_OK);
  assert(id == 1);
  assert(todo_count(app) == 1);
  char title[16]{};
  todo_item_view_t view{id, false, title, sizeof(title), 0};
  assert(todo_get(app, 0, &view) == TODO_OK);
  assert(std::strcmp(view.title, "Ship Todo") == 0);
  todo_app_destroy(app);
}

void test_todoCore_withBlankTitle_rejectsTodo() {
  todo_app_t* app = todo_app_create();
  std::uint64_t id = 0;
  assert(todo_add(app, "   ", &id) == TODO_INVALID_TITLE);
  const char* long_title =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  assert(todo_add(app, long_title, &id) == TODO_INVALID_TITLE);
  assert(todo_count(app) == 0);
  todo_app_destroy(app);
}

void test_todoCore_withExistingTodo_togglesCompletion() {
  todo_app_t* app = todo_app_create();
  std::uint64_t id = 0;
  assert(todo_add(app, "Test each platform", &id) == TODO_OK);
  assert(todo_toggle(app, id) == TODO_OK);
  char title[32]{};
  todo_item_view_t view{id, false, title, sizeof(title), 0};
  assert(todo_get(app, 0, &view) == TODO_OK);
  assert(view.completed);
  assert(std::strcmp(view.title, "Test each platform") == 0);
  assert(todo_remove(app, id) == TODO_OK);
  assert(todo_count(app) == 0);
  todo_app_destroy(app);
}

void test_todoCore_withInvalidQueries_returnsTypedErrors() {
  todo_app_t* app = todo_app_create();
  assert(todo_toggle(app, 42) == TODO_NOT_FOUND);
  std::uint64_t id = 0;
  assert(todo_add(app, "Long", &id) == TODO_OK);
  char title[2]{};
  todo_item_view_t view{id, false, title, sizeof(title), 0};
  assert(todo_get(app, 0, &view) == TODO_BUFFER_TOO_SMALL);
  assert(view.title_length == 4);
  todo_app_destroy(app);
}

int main() {
  test_todoCore_withValidTitle_addsTodo();
  test_todoCore_withBlankTitle_rejectsTodo();
  test_todoCore_withExistingTodo_togglesCompletion();
  test_todoCore_withInvalidQueries_returnsTypedErrors();
  return 0;
}
