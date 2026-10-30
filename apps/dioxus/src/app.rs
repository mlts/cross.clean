/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    app.rs                                                +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:39:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:41:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use dioxus::prelude::*;

use crate::state::TodoState;
use crate::todo_row::TodoRow;

#[component]
pub fn App() -> Element {
    let state = use_signal(|| TodoState::new().ok());
    rsx! {
        main { class: "todo-shell",
            h1 { "Todo" }
            AddForm { state }
            TodoList { state }
        }
    }
}

#[component]
fn AddForm(mut state: Signal<Option<TodoState>>) -> Element {
    let mut title = use_signal(String::new);
    rsx! {
        section { class: "todo-create",
            input {
                value: "{title}",
                placeholder: "What needs doing?",
                oninput: move |event| title.set(event.value()),
            }
            button { onclick: move |_| {
                let value = title.read().clone();
                if let Some(model) = state.write().as_mut() {
                    let _ = model.add(&value);
                    title.set(String::new());
                }
            }, "Add" }
        }
    }
}

#[component]
fn TodoList(mut state: Signal<Option<TodoState>>) -> Element {
    rsx! {
        ul { for item in state.read().iter().flat_map(TodoState::items) {
                TodoRow {
                    item: item.clone(),
                    on_toggle: move |id| if let Some(model) =
                        state.write().as_mut() { let _ = model.toggle(id); },
                    on_remove: move |id| if let Some(model) =
                        state.write().as_mut() { let _ = model.remove(id); },
                }
        } }
    }
}
