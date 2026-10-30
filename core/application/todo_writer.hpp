/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_writer.hpp                                       +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_WRITER_HPP
#define TODO_WRITER_HPP

#include "todo_item.hpp"

#include <cstdint>

namespace todo {

class TodoWriter {
 public:
  virtual ~TodoWriter() = default;
  virtual void add(TodoItem item) = 0;
  [[nodiscard]] virtual bool remove(std::uint64_t id) = 0;
};

}

#endif
