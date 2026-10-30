/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    remove_todo.cpp                                       +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:20:09 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:20:09 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "remove_todo.hpp"

namespace todo {

RemoveTodo::RemoveTodo(TodoWriter& writer) noexcept : writer_(writer) {}

bool RemoveTodo::execute(std::uint64_t id) { return writer_.remove(id); }

}
