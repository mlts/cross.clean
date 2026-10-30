/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    mutations.cpp                                         +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:20:09 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "todo_mutations.h"

#include "app_context.hpp"
#include "remove_todo.hpp"
#include "todo_use_cases.hpp"

#include <new>
#include <stdexcept>

todo_status_t todo_add(todo_app_t* app, const char* title, uint64_t* id) {
  if (app == nullptr || title == nullptr || id == nullptr) {
    return TODO_INVALID_ARGUMENT;
  }
  try {
    const uint64_t candidate = app->next_id;
    todo::AddTodo{app->repository}.execute(candidate, title);
    app->next_id++;
    *id = candidate;
    return TODO_OK;
  } catch (const std::invalid_argument&) {
    return TODO_INVALID_TITLE;
  } catch (const std::bad_alloc&) {
    return TODO_NO_MEMORY;
  }
}

todo_status_t todo_toggle(todo_app_t* app, uint64_t id) {
  if (app == nullptr) {
    return TODO_INVALID_ARGUMENT;
  }
  return todo::ToggleTodo{app->repository}.execute(id) ? TODO_OK
                                                       : TODO_NOT_FOUND;
}

todo_status_t todo_remove(todo_app_t* app, uint64_t id) {
  if (app == nullptr) {
    return TODO_INVALID_ARGUMENT;
  }
  return todo::RemoveTodo{app->repository}.execute(id) ? TODO_OK
                                                       : TODO_NOT_FOUND;
}
