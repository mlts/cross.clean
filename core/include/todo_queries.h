/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_queries.h                                        +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:20:09 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_QUERIES_H
#define TODO_QUERIES_H

#include "todo_types.h"

#ifdef __cplusplus
extern "C" {
#endif

TODO_API size_t todo_count(const todo_app_t* app);
TODO_API todo_status_t todo_get(const todo_app_t* app, size_t index,
                                todo_item_view_t* view);

#ifdef __cplusplus
}
#endif

#endif
