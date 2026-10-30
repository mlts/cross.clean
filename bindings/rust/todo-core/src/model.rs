/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    model.rs                                              +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:36:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:36:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#[derive(Clone, Debug, Eq, PartialEq)]
pub struct TodoItem {
    pub identifier: u64,
    pub title: String,
    pub completed: bool,
}

#[derive(Clone, Debug, Eq, PartialEq)]
pub enum TodoError {
    NullHandle,
    InvalidArgument,
    InvalidTitle,
    NotFound,
    BufferTooSmall,
    NoMemory,
    InvalidUtf8,
    UnknownStatus(i32),
}

pub fn status_result(status: i32) -> Result<(), TodoError> {
    match status {
        0 => Ok(()),
        1 => Err(TodoError::InvalidArgument),
        2 => Err(TodoError::InvalidTitle),
        3 => Err(TodoError::NotFound),
        4 => Err(TodoError::BufferTooSmall),
        5 => Err(TodoError::NoMemory),
        value => Err(TodoError::UnknownStatus(value)),
    }
}
