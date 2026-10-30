/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    lifecycle.cpp                                         +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "todo_lifecycle.h"

#include "app_context.hpp"

#include <new>

todo_app_t* todo_app_create(void) {
  return new (std::nothrow) todo_app_t{};
}

void todo_app_destroy(todo_app_t* app) { delete app; }
