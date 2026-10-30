/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    memory_repository.hpp                                 +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_REPOSITORY_HPP
#define MEMORY_REPOSITORY_HPP

#include "todo_reader.hpp"
#include "todo_writer.hpp"

#include <vector>

namespace todo {

class MemoryRepository final : public TodoReader, public TodoWriter {
 public:
  void add(TodoItem item) override;
  [[nodiscard]] TodoItem* find(std::uint64_t id) override;
  [[nodiscard]] bool remove(std::uint64_t id) override;
  [[nodiscard]] std::size_t count() const noexcept override;
  [[nodiscard]] const TodoItem* at(std::size_t index) const override;

 private:
  std::vector<TodoItem> items_;
};

}

#endif
