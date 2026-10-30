/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    status_contract.rs                                    +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:35:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:35:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

use todo_core::{TodoError, status_result};

#[test]
fn test_status_result_with_success_returns_ok() {
    assert_eq!(status_result(0), Ok(()));
}

#[test]
fn test_status_result_with_unknown_code_returns_typed_error() {
    assert_eq!(status_result(99), Err(TodoError::UnknownStatus(99)));
}
