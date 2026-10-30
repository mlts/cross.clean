/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    state.rs                                              +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:39:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:39:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use todo_core::{TodoClient, TodoError, TodoItem};

pub struct TodoState {
    client: TodoClient,
    items: Vec<TodoItem>,
}

impl TodoState {
    pub fn new() -> Result<Self, TodoError> {
        let client = TodoClient::new()?;
        let items = client.items()?;
        Ok(Self { client, items })
    }

    pub fn add(&mut self, title: &str) -> Result<(), TodoError> {
        self.client.add(title)?;
        self.items = self.client.items()?;
        Ok(())
    }

    pub fn toggle(&mut self, identifier: u64) -> Result<(), TodoError> {
        self.client.toggle(identifier)?;
        self.items = self.client.items()?;
        Ok(())
    }

    pub fn remove(&mut self, identifier: u64) -> Result<(), TodoError> {
        self.client.remove(identifier)?;
        self.items = self.client.items()?;
        Ok(())
    }

    pub fn items(&self) -> &[TodoItem] {
        &self.items
    }
}
