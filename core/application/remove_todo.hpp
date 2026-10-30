/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    remove_todo.hpp                                       +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:20:09 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:20:09 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_TODO_HPP
#define REMOVE_TODO_HPP

#include "todo_writer.hpp"

#include <cstdint>

namespace todo {

class RemoveTodo final {
 public:
  explicit RemoveTodo(TodoWriter& writer) noexcept;
  [[nodiscard]] bool execute(std::uint64_t id);

 private:
  TodoWriter& writer_;
};

}

#endif
