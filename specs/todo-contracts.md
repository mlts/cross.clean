# Todo Domain and Port Contracts

## Domain

`TodoItem` contains an immutable positive identifier, a non-empty trimmed
title of at most 120 Unicode scalar values, and a completion flag.

`TodoList` preserves insertion order and owns item identity. It supports:

- add a valid title and return the created item;
- toggle an existing item and return its new state;
- remove an existing item;
- list an immutable snapshot of all items.

Invalid titles return `TODO_INVALID_TITLE`. Unknown identifiers return
`TODO_NOT_FOUND`. Allocation failures return `TODO_NO_MEMORY`. Boundaries
never expose C++ exceptions, STL types, or framework values.

## C ABI

The public header exposes an opaque `todo_list` handle and versioned,
documented functions. Callers own created handles and returned snapshots
according to explicit matching destroy functions.

## Application ports

Each language adapter exposes the same narrow use-case interface:

```text
add(title) -> TodoItem | DomainError
toggle(id) -> TodoItem | DomainError
remove(id) -> void | DomainError
list() -> readonly TodoItem[]
```

## UI adapters

- Flet: Python presenter and `ctypes` repository adapter.
- React Native: TypeScript presenter and C++ TurboModule adapter.
- Dioxus: Rust presenter and `extern "C"` adapter.
- Bare-metal web: semantic HTML/CSS/TypeScript and WebAssembly adapter.

## SOLID example

- SRP: the domain validates and changes Todo state; UIs render it.
- OCP: a new UI implements the same port without changing the domain.
- LSP: native, WebAssembly, fake, and FFI adapters share contract tests.
- ISP: the UI receives only add, toggle, remove, and list operations.
- DIP: presenters depend on the Todo port, never on FFI or a framework.

