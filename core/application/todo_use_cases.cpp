/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_use_cases.cpp                                    +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "todo_use_cases.hpp"

#include <utility>

namespace todo {

AddTodo::AddTodo(TodoWriter& writer) noexcept : writer_(writer) {}

void AddTodo::execute(std::uint64_t id, std::string title) {
  writer_.add(TodoItem{id, std::move(title)});
}

ToggleTodo::ToggleTodo(TodoReader& reader) noexcept : reader_(reader) {}

bool ToggleTodo::execute(std::uint64_t id) noexcept {
  TodoItem* item = reader_.find(id);
  if (item == nullptr) {
    return false;
  }
  item->toggle();
  return true;
}

}
