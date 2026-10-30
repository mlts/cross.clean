/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    query.rs                                              +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:36:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:44:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use std::ffi::c_char;

use crate::{TodoClient, TodoError, TodoItem, raw, status_result};

impl TodoClient {
    pub fn items(&self) -> Result<Vec<TodoItem>, TodoError> {
        // SAFETY: The handle is valid and borrowed immutably by this call.
        let count = unsafe { raw::todo_count(self.raw.as_ptr()) };
        (0..count).map(|index| self.read_item(index)).collect()
    }

    fn read_item(&self, index: usize) -> Result<TodoItem, TodoError> {
        let mut probe = [0_u8; 1];
        let mut view = raw::TodoItemView {
            identifier: 0,
            completed: false,
            title: probe.as_mut_ptr().cast::<c_char>(),
            title_capacity: probe.len(),
            title_length: 0,
        };
        // SAFETY: The view pointer is valid and caller-owned.
        let status =
            unsafe { raw::todo_get(self.raw.as_ptr(), index, &mut view) };
        if status != 4 {
            status_result(status)?;
        }
        self.read_title(index, view)
    }

    fn read_title(
        &self,
        index: usize,
        mut view: raw::TodoItemView,
    ) -> Result<TodoItem, TodoError> {
        let mut title = vec![0_u8; view.title_length + 1];
        view.title = title.as_mut_ptr().cast::<c_char>();
        view.title_capacity = title.len();
        // SAFETY: The allocated title buffer matches the declared capacity.
        let status =
            unsafe { raw::todo_get(self.raw.as_ptr(), index, &mut view) };
        status_result(status)?;
        title.truncate(view.title_length);
        let title =
            String::from_utf8(title).map_err(|_| TodoError::InvalidUtf8)?;
        Ok(TodoItem {
            identifier: view.identifier,
            title,
            completed: view.completed,
        })
    }
}
