/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    raw.rs                                                +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:36:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:36:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use std::ffi::{c_char, c_int, c_void};

#[repr(C)]
pub struct TodoItemView {
    pub identifier: u64,
    pub completed: bool,
    pub title: *mut c_char,
    pub title_capacity: usize,
    pub title_length: usize,
}

unsafe extern "C" {
    pub fn todo_app_create() -> *mut c_void;
    pub fn todo_app_destroy(app: *mut c_void);
    pub fn todo_add(
        app: *mut c_void,
        title: *const c_char,
        id: *mut u64,
    ) -> c_int;
    pub fn todo_toggle(app: *mut c_void, id: u64) -> c_int;
    pub fn todo_remove(app: *mut c_void, id: u64) -> c_int;
    pub fn todo_count(app: *const c_void) -> usize;
    pub fn todo_get(
        app: *const c_void,
        index: usize,
        view: *mut TodoItemView,
    ) -> c_int;
}
