/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_item.hpp                                         +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_ITEM_HPP
#define TODO_ITEM_HPP

#include <cstdint>
#include <string>

namespace todo {

class TodoItem final {
 public:
  TodoItem(std::uint64_t id, std::string title);
  [[nodiscard]] std::uint64_t id() const noexcept;
  [[nodiscard]] const std::string& title() const noexcept;
  [[nodiscard]] bool completed() const noexcept;
  void toggle() noexcept;

 private:
  std::uint64_t id_;
  std::string title_;
  bool completed_{false};
};

}

#endif
