/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    build.rs                                              +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:39:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:39:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use std::env;

fn main() {
    println!("cargo:rerun-if-env-changed=TODO_CORE_LIB_DIR");
    if let Ok(path) = env::var("TODO_CORE_LIB_DIR") {
        println!("cargo:rustc-link-search=native={path}");
    }
    println!("cargo:rustc-link-lib=dylib=todo_core");
}
