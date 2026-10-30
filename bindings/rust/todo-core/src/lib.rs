/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    lib.rs                                                +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:36:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:36:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

mod commands;
mod model;
mod query;
mod raw;

use std::ffi::c_void;
use std::ptr::NonNull;

pub use model::{TodoError, TodoItem, status_result};

pub struct TodoClient {
    raw: NonNull<c_void>,
}

impl TodoClient {
    pub fn new() -> Result<Self, TodoError> {
        // SAFETY: The C function has no inputs and returns an owned handle.
        let raw = unsafe { raw::todo_app_create() };
        let raw = NonNull::new(raw).ok_or(TodoError::NullHandle)?;
        Ok(Self { raw })
    }
}

impl Drop for TodoClient {
    fn drop(&mut self) {
        // SAFETY: TodoClient uniquely owns this non-null native handle.
        unsafe { raw::todo_app_destroy(self.raw.as_ptr()) };
    }
}
