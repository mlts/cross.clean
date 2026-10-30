# Todo Solution Architecture

```mermaid
flowchart LR
  F[Flet UI] --> P[Todo application port]
  N[React Native UI] --> P
  D[Dioxus UI] --> P
  W[Bare-metal web UI] --> P
  P --> A[Language adapter]
  A --> C[C ABI]
  C --> U[Todo use cases]
  U --> M[C++ domain model]
```

Dependencies point inward. The framework-facing applications translate user
events into application-port calls. Language adapters translate values and
ownership across the C ABI. The core alone enforces Todo invariants.

```mermaid
flowchart TB
  subgraph Drivers
    UI[Flet / React Native / Dioxus / Web]
  end
  subgraph Adapters
    PY[Python ctypes]
    TS[TypeScript WASM or TurboModule]
    RS[Rust FFI]
  end
  subgraph Application
    PORT[Todo port]
  end
  subgraph Domain
    TODO[TodoList and TodoItem]
  end
  UI --> PY & TS & RS
  PY & TS & RS --> PORT
  PORT --> TODO
```

