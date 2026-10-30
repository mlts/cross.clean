# *************************************************************************** #
#                                                                             #
#                                                            +#               #
#    CMakeLists.txt                                        +##                #
#                                                         +###+               #
#    By: lucas <lucas@tsiaraso.com>                     +########+            #
#                                                           +###+             #
#    Created: 2026/10/30 09:18:18 by lucas                  ##+               #
#    Updated: 2026/10/30 09:18:18 by lucas                 #+                 #
#                                                                             #
# *************************************************************************** #

cmake_minimum_required(VERSION 3.25)
project(todo_core VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(TODO_SOURCES
  core/adapters/memory_repository.cpp
  core/application/remove_todo.cpp
  core/application/todo_use_cases.cpp
  core/domain/todo_item.cpp
  core/domain/title_policy.cpp
  core/ffi/lifecycle.cpp
  core/ffi/mutations.cpp
  core/ffi/queries.cpp
)

add_library(todo_core SHARED ${TODO_SOURCES})
target_compile_definitions(todo_core PRIVATE TODO_CORE_BUILD)
target_include_directories(todo_core PUBLIC core/include)
target_include_directories(todo_core PRIVATE
  core/adapters
  core/application
  core/domain
  core/ffi
)

if(MSVC)
  target_compile_options(todo_core PRIVATE /W4 /WX)
else()
  target_compile_options(todo_core PRIVATE
    -Wall -Wextra -Werror -Wpedantic
  )
endif()

enable_testing()
add_executable(todo_core_test tests/native/todo_core_test.cpp)
target_include_directories(todo_core_test PRIVATE core/include)
target_link_libraries(todo_core_test PRIVATE todo_core)
add_test(NAME todo_core_acceptance COMMAND todo_core_test)
