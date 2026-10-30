/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_mutations.h                                      +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:20:09 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_MUTATIONS_H
#define TODO_MUTATIONS_H

#include "todo_types.h"

#ifdef __cplusplus
extern "C" {
#endif

TODO_API todo_status_t todo_add(todo_app_t* app, const char* title,
                                uint64_t* id);
TODO_API todo_status_t todo_toggle(todo_app_t* app, uint64_t id);
TODO_API todo_status_t todo_remove(todo_app_t* app, uint64_t id);

#ifdef __cplusplus
}
#endif

#endif
