/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_use_cases.hpp                                    +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_USE_CASES_HPP
#define TODO_USE_CASES_HPP

#include "todo_reader.hpp"
#include "todo_writer.hpp"

#include <cstdint>
#include <string>

namespace todo {

class AddTodo final {
 public:
  explicit AddTodo(TodoWriter& writer) noexcept;
  void execute(std::uint64_t id, std::string title);

 private:
  TodoWriter& writer_;
};

class ToggleTodo final {
 public:
  explicit ToggleTodo(TodoReader& reader) noexcept;
  [[nodiscard]] bool execute(std::uint64_t id) noexcept;

 private:
  TodoReader& reader_;
};

}

#endif
