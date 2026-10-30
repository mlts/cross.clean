/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_lifecycle.h                                      +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:20:09 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_LIFECYCLE_H
#define TODO_LIFECYCLE_H

#include "todo_types.h"

#ifdef __cplusplus
extern "C" {
#endif

TODO_API todo_app_t* todo_app_create(void);
TODO_API void todo_app_destroy(todo_app_t* app);

#ifdef __cplusplus
}
#endif

#endif
