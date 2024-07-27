# A simple `SQLite` clone written in `C++`

This is an attempt to build a simple _in-process_ DB i.e., `SQLite` to grok its internal workings from the very ground up.

- `clang++` is used as the compiler front end for this project.
- `cmake` is used as the build system generator.
- `make` is used as the build system.

## Housekeeping - `pre-commit` hooks

[`pre-commit`](https://pre-commit.com/#install) hooks are used for general _code_ housekeeping.

Ensure a `python` virtual environment and install [`pre-commit`](https://pre-commit.com/#install) as per instructions [here](https://pre-commit.com/#1-install-pre-commit).

The following hooks are used in this repository:

1. Out of the box hooks from [`pre-commit/pre-commit-hooks`](https://github.com/pre-commit/pre-commit-hooks).
2. [`commitizen`](https://github.com/commitizen-tools/commitizen): For enforcing [conventional commits](https://www.conventionalcommits.org/) specification for commit messages.
3. _Custom_ hooks using binaries available in the `PATH` for `C++` specific code formatting and static analysis. The following are used for this purpose:

   - `clang-format`
   - `clang-tidy`
   - `cppcheck`
   - `cpplint`
   - `include-what-you-use`

   Specifically for `include-what-you-use`, care needs to be taken to install the version compatible with the particular `clang++` version being used, as per instructions [here](https://github.com/include-what-you-use/include-what-you-use?tab=readme-ov-file#clang-compatibility).

   `clang-tidy` requires a compilation database to work. Instructions to generate it are in the [<b>Generating build files using `CMake`</b>](#generating-build-files-using-cmake) section below.

### `macOS` specific tweaks

`macOS` ships with `clang++`, but not `clang-format` or `clang-tidy`. A convenient way to get these working on `macOS` is to install `llvm` and then using `clang-format` and `clang-tidy` that come shipped with it.

However, `llvm` installed via `brew` is keg-only, which means it and its associated binaries are not symlinked to Homebrew's installation path. Therefore, `clang-format` and `clang-tidy` have to manually be symlinked to one of the directories in the environment's `PATH` to make the corresponding hooks work. Below are commands to symlink these binaries to Homebrew's installation path:

- ```sh
    ln -s "$(brew --prefix llvm)/bin/clang-format" "$(brew --prefix)/bin/clang-format"
  ```

- ```sh
    ln -s "$(brew --prefix llvm)/bin/clang-tidy" "$(brew --prefix)/bin/clang-tidy"
  ```

### Installing the hooks

Run the following CLI command to install the hooks:

```sh
pre-commit install
```

## Generating build files using `CMake`

Run the following CLI command in the project's root directory to generate the build files:

```sh
cmake \
-DCMAKE_BUILD_TYPE:STRING=Debug \
-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
-DCMAKE_CXX_COMPILER:FILEPATH=path/to/clang++ \
-S. \
-B./build \
-G="Unix Makefiles"
```

The `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` generates the compilation database.

## Building and running the project binary

Run the following CLI command in the project's root directory to build the binary:

```sh
make -C build/
```

Run the following CLI command in the project's root directory to run the built binary:

```sh
./build/dgSqlite
```
