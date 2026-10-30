# Verification Report

## Baseline

- Host: Apple Silicon macOS.
- C/C++: Apple Clang is available.
- Python, Node, Rust, Xcode, and Java are available.
- CMake, Flet, Dioxus CLI, Android SDK/NDK, and Rust cross targets were absent.
- GitHub CLI credentials were expired at discovery time.

## Completion rule

Results are appended only from fresh commands. A missing target is reported as
blocked, never inferred from another host. CI jobs complement but do not replace
physical-device release testing.

## Fresh local evidence

- Native C++20 acceptance test passed twice under ASan and UBSan.
- Shared macOS library exported all seven documented C symbols.
- Python 3.11 unit and real `ctypes` integration checks passed: 6 tests.
- Rust formatting, Clippy with denied warnings, and 2 contract tests passed.
- Dioxus manifest resolution and source formatting passed.
- Bare-web Node contract tests passed: 2 tests.
- Portfolio cross-platform section passed 12 tests across 5 suites.
- Portfolio application TypeScript check and `git diff --check` passed.

## Known unavailable gates

- CMake generation was not run locally because CMake is not installed.
- Flet and Dioxus framework builds need their locked dependencies installed.
- Android compilation needs the Android SDK and NDK.
- Windows and Linux compilation require their CI runners.
- iOS simulator execution is blocked by the sandbox simulator service.
- Portfolio production build retains its baseline Angular 20/CLI 22 abort.
- GitHub publication is blocked until `gh auth login -h github.com` succeeds.

