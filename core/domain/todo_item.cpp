/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_item.cpp                                         +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:26:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "todo_item.hpp"
#include "title_policy.hpp"

#include <utility>

namespace todo {

TodoItem::TodoItem(std::uint64_t id, std::string title)
    : id_(id), title_(normalize_title(std::move(title))) {}

std::uint64_t TodoItem::id() const noexcept { return id_; }

const std::string& TodoItem::title() const noexcept { return title_; }

bool TodoItem::completed() const noexcept { return completed_; }

void TodoItem::toggle() noexcept { completed_ = !completed_; }

}
