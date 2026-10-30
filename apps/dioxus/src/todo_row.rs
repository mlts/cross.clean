/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    todo_row.rs                                           +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:39:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:39:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use dioxus::prelude::*;
use todo_core::TodoItem;

#[component]
pub fn TodoRow(
    item: TodoItem,
    on_toggle: EventHandler<u64>,
    on_remove: EventHandler<u64>,
) -> Element {
    let identifier = item.identifier;
    rsx! {
        li { class: "todo-row",
            input {
                r#type: "checkbox",
                checked: item.completed,
                onchange: move |_| on_toggle.call(identifier),
            }
            span { class: if item.completed { "done" } else { "" },
                "{item.title}"
            }
            button {
                aria_label: "Remove Todo",
                onclick: move |_| on_remove.call(identifier),
                "Remove"
            }
        }
    }
}
