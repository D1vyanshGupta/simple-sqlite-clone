# A simple `SQLite` clone written in `C++`

This is an attempt to build a simple _in-process_ DB i.e., `SQLite` to grok its internal workings from the very ground up.

- `clang++` is used as the compiler front end for this project.
- `cmake` is used as the build-system generator.
- `make` is used as the build system.

## Generating build files using `CMake`

Run the following CLI command in the project's root directory to generate the build files:

```sh
cmake -Bbuild -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ./
```

- Explicitly set `clang++` as the `C++` compiler using `-DCMAKE_CXX_COMPILER=clang++`.
- Generate a compilation database using `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON`.

## Housekeeping - `pre-commit` hooks

[`pre-commit`](https://pre-commit.com/#install) hooks are used for general _code_ housekeeping.

Ensure a `python` virtual environment and install [`pre-commit`](https://pre-commit.com/#install) as per instructions [here](https://pre-commit.com/#1-install-pre-commit).

The following hooks are used in this repository:

1. Out of the box hooks from [`pre-commit/pre-commit-hooks`](https://github.com/pre-commit/pre-commit-hooks).
2. [`commitizen`](https://github.com/commitizen-tools/commitizen): For enforcing [conventional commits](https://www.conventionalcommits.org/) specification for commit messages.
3. [`pocc/pre-commit-hooks`](https://github.com/pocc/pre-commit-hooks?tab=readme-ov-file#pre-commit-hooks): For `C++` specific code formatting and static analysis.

### Installing dependencies for [`pocc/pre-commit-hooks`](https://github.com/pocc/pre-commit-hooks?tab=readme-ov-file#pre-commit-hooks)

[`pocc/pre-commit-hooks`](https://github.com/pocc/pre-commit-hooks?tab=readme-ov-file#pre-commit-hooks) assumes all dependencies are pre-installed. Therefore, manually install the required dependencies as per instructions [here](https://github.com/pocc/pre-commit-hooks?tab=readme-ov-file#installation). Only `clang-format` is used for code formatting.

### `macOS` specific tweaks

1. `macOS` ships with `clang++`, but not `clang-format` or `clang-tidy`. A convenient way to get these working on `macOS` is to install `llvm` and then using `clang-format` and `clang-tidy` that come shipped with it.

   However, `llvm` installed via `brew` is keg-only, which means it and its associated binaries are not symlinked to Homebrew's installation path. Therefore, `clang-format` and `clang-tidy` have to manually be symlinked to one of the directories in the environment's `PATH` to make the corresponding hooks work. Below are commands to symlink these binaries to Homebrew's installation path:

   - ```sh
       ln -s "$(brew --prefix llvm)/bin/clang-format" "$(brew --prefix)/bin/clang-format"
     ```

   - ```sh
       ln -s "$(brew --prefix llvm)/bin/clang-tidy" "$(brew --prefix)/bin/clang-tidy"
     ```

2. `oclint` comes shipped with several dylibs that are dynamically loaded when `oclint` needs the specific rule to lint the source code. All these dylibs needs to be manually approved in the [Gatekeeper](https://support.apple.com/en-sg/guide/security/sec5599b66df/web) prompt. To approve all `oclint` specific dylibs in one-shot, run the following commands as per instructions [here](https://ingo-richter.io/post/2022/adding-multiple-files-to-macos-gatekeeper/):
   - adding `OCLint` label to the dylibs:
     ```sh
     find $(brew --prefix)/Caskroom/oclint/22.02/oclint-22.02/lib/oclint -name "*.dylib" -print0 | xargs -0 sudo spctl --add --label "OCLint"
     ```
   - enabling all labelled dylibs:
     ```sh
     sudo spctl --enable --label "OCLint"
     ```

### Installing the hooks

Run the following CLI command to install the hooks:

```sh
pre-commit install
```

## Building and running the project binary

Run the following CLI command in the project's root directory to build the binary:

```sh
make -C build/
```

Run the following CLI command in the project's root directory to run the built binary:

```sh
./build/dgSqlite
```
