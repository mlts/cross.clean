/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    commands.rs                                           +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:36:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:36:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use std::ffi::CString;

use crate::{TodoClient, TodoError, raw, status_result};

impl TodoClient {
    pub fn add(&mut self, title: &str) -> Result<u64, TodoError> {
        let title = CString::new(title).map_err(|_| TodoError::InvalidTitle)?;
        let mut identifier = 0;
        // SAFETY: The handle, string, and output pointer remain valid.
        let status = unsafe {
            raw::todo_add(self.raw.as_ptr(), title.as_ptr(), &mut identifier)
        };
        status_result(status)?;
        Ok(identifier)
    }

    pub fn toggle(&mut self, identifier: u64) -> Result<(), TodoError> {
        // SAFETY: The handle is owned by self for the duration of this call.
        let status = unsafe { raw::todo_toggle(self.raw.as_ptr(), identifier) };
        status_result(status)
    }

    pub fn remove(&mut self, identifier: u64) -> Result<(), TodoError> {
        // SAFETY: The handle is owned by self for the duration of this call.
        let status = unsafe { raw::todo_remove(self.raw.as_ptr(), identifier) };
        status_result(status)
    }
}
