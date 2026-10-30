/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_types.h                                          +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:17:52 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:20:09 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODO_TYPES_H
#define TODO_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(_WIN32)
#if defined(TODO_CORE_BUILD)
#define TODO_API __declspec(dllexport)
#else
#define TODO_API __declspec(dllimport)
#endif
#else
#define TODO_API __attribute__((visibility("default")))
#endif

typedef struct todo_app todo_app_t;

typedef enum todo_status {
  TODO_OK = 0,
  TODO_INVALID_ARGUMENT = 1,
  TODO_INVALID_TITLE = 2,
  TODO_NOT_FOUND = 3,
  TODO_BUFFER_TOO_SMALL = 4,
  TODO_NO_MEMORY = 5
} todo_status_t;

typedef struct todo_item_view {
  uint64_t id;
  bool completed;
  char* title;
  size_t title_capacity;
  size_t title_length;
} todo_item_view_t;

#endif
