/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    app_context.hpp                                       +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:17:52 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_CONTEXT_HPP
#define APP_CONTEXT_HPP

#include "memory_repository.hpp"

#include <cstdint>

struct todo_app {
  todo::MemoryRepository repository;
  std::uint64_t next_id{1};
};

#endif
