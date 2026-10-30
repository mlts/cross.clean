/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    queries.cpp                                           +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "todo_queries.h"

#include "app_context.hpp"

#include <cstring>

size_t todo_count(const todo_app_t* app) {
  return app == nullptr ? 0 : app->repository.count();
}

todo_status_t todo_get(const todo_app_t* app, size_t index,
                       todo_item_view_t* view) {
  if (app == nullptr || view == nullptr || view->title == nullptr) {
    return TODO_INVALID_ARGUMENT;
  }
  const todo::TodoItem* item = app->repository.at(index);
  if (item == nullptr) {
    return TODO_NOT_FOUND;
  }
  view->title_length = item->title().size();
  if (view->title_capacity <= view->title_length) {
    return TODO_BUFFER_TOO_SMALL;
  }
  std::memcpy(view->title, item->title().data(), view->title_length);
  view->title[view->title_length] = '\0';
  view->id = item->id();
  view->completed = item->completed();
  return TODO_OK;
}
