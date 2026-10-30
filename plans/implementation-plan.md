# Todo Cross-Platform Implementation Plan

## Outcome

Build a public `cross.clean` monorepo for a Todo application whose C++
domain is reused by Python/Flet, TypeScript/React Native, and Rust/Dioxus.
Keep every UI adapter replaceable and every domain rule framework-free.

## Delivery sequence

1. Record contracts, architecture, risks, and the four-tier test matrix.
2. Initialize Git and establish deterministic repository hygiene.
3. Test-drive the C-compatible API over the C++ Todo domain.
4. Add the Python adapter and a Flet UI with adapter tests.
5. Add the TypeScript adapter and React Native UI contract tests.
6. Add the Rust FFI crate and Dioxus UI contract tests.
7. Add a bare-metal web Todo demo using the shared WebAssembly contract.
8. Add portable build scripts and platform CI matrices.
9. Add brand assets, README Mermaid diagrams, and runbooks.
10. Verify all locally available tiers twice for idempotency.
11. Commit atomic slices and create the public GitHub repository.
12. Add the cross-platform article and repository link to the portfolio.

## Architecture decision

Use one stable C ABI as the language-neutral boundary. The domain remains
C++20 and exposes opaque handles plus explicit status codes. Python uses
`ctypes`, Rust uses `extern "C"`, browser TypeScript uses an Emscripten
WebAssembly build, and React Native uses a pure C++ Turbo Native Module.

## Constraints

- No business rule may depend on Flet, React Native, Dioxus, or an OS API.
- UI migrations replace only adapters and composition roots.
- Every target has a build gate; tests are never inferred from another OS.
- Framework dependencies requested by the brief are allowed and locked.
- Optional libraries require a separate decision before introduction.
- Functions stay at or below 25 lines and accept at most four parameters.
- Source files contain at most five functions and lines stay within 80 cols.

## Rollback

Each micro-slice is an atomic commit. Roll back one slice with
`git revert <commit>` after its affected test tier is rerun.

