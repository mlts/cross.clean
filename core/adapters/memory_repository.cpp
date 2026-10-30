/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    memory_repository.cpp                                 +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:19:55 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "memory_repository.hpp"

#include <utility>

namespace todo {

void MemoryRepository::add(TodoItem item) {
  items_.push_back(std::move(item));
}

TodoItem* MemoryRepository::find(std::uint64_t id) {
  for (TodoItem& item : items_) {
    if (item.id() == id) {
      return &item;
    }
  }
  return nullptr;
}

bool MemoryRepository::remove(std::uint64_t id) {
  for (auto found = items_.begin(); found != items_.end(); ++found) {
    if (found->id() == id) {
      items_.erase(found);
      return true;
    }
  }
  return false;
}

std::size_t MemoryRepository::count() const noexcept {
  return items_.size();
}

const TodoItem* MemoryRepository::at(std::size_t index) const {
  return index < items_.size() ? &items_[index] : nullptr;
}

}
