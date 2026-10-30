# Four-Tier Test Matrix

| Tier | Contract | Primary gates |
| --- | --- | --- |
| Unit | Title rules and item state | CTest, Python, Node, Cargo |
| Functional | Add/toggle/remove/list flow | In-memory port suites |
| Integration | C ABI and each language boundary | Native, ctypes, FFI, WASM |
| E2E | User adds and completes a Todo | Web/browser and app smoke |

## Platform build matrix

| Target | Flet | React Native | Dioxus | Required runner |
| --- | --- | --- | --- | --- |
| Web | Static Pyodide | Web adapter | Web | Linux CI |
| macOS | Desktop | N/A | Desktop | macOS CI |
| Linux | Desktop | N/A | Desktop | Linux CI |
| Windows | Desktop | N/A | Desktop | Windows CI |
| iOS | Mobile | Native | Mobile | macOS CI + Xcode |
| Android | Mobile | Native | Mobile | Linux CI + SDK/NDK |

Each supported product target must compile on its named runner. A successful
host build does not substitute for another target. Signed store artifacts are
outside this example's acceptance boundary; unsigned simulator/debug builds
are sufficient for E2E smoke tests.

