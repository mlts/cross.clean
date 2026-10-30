/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_reader.hpp                                       +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_READER_HPP
#define TODO_READER_HPP

#include "todo_item.hpp"

#include <cstddef>
#include <cstdint>

namespace todo {

class TodoReader {
 public:
  virtual ~TodoReader() = default;
  [[nodiscard]] virtual TodoItem* find(std::uint64_t id) = 0;
  [[nodiscard]] virtual std::size_t count() const noexcept = 0;
  [[nodiscard]] virtual const TodoItem* at(std::size_t index) const = 0;
};

}

#endif
