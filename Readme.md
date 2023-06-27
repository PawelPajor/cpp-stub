# Read me

- [Read me](#read-me)
  - [To initialise project from this repo](#to-initialise-project-from-this-repo)
  - [Conan pre 2.0 with Clion](#conan-pre-20-with-clion)
  - [Conan 2.0 with Clion](#conan-20-with-clion)

## To initialise project from this repo

- Copy all files/directories from of `project-with-*` directory to the new directory
- In `./CMakeLists.txt` change project name from `stub` to your project name
- In all `*.cpp *.hpp` files change namespace from `stub` to your namespace

## Conan pre 2.0 with Clion

The dependencies are managed by [conan](https://conan.io). Before compilation:
- ensure that you have [conan](https://conan.io) installed
- install all the dependencies to appropriate directories. For example if you are using CLion you will:
  ```
  conan install --install-folder cmake-build-debug . --build=missing
  conan install --install-folder cmake-build-release . --build=missing
  ```

## Conan 2.0 with Clion

- Prepare `conanfile.txt` according to Conan documentation, for example:

```
[requires]
nlohmann_json/3.11.2

[generators]
CMakeDeps
CMakeToolchain
```

- Install Conan dependencies, as in example below. 
  These commands are also provided as a shell script `project/install_conan.sh`.

```sh
conan install . --output-folder=cmake-build-debug --build=missing --profile=debug
conan install . --output-folder=cmake-build-release --build=missing --profile=release
```

- In Clion `Settings -> Build, Execution, Deployment -> CMake -> CMake Options`
  add the following options for each profile:
  - `-DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake`
  - `-DCMAKE_BUILD_TYPE=Release` or `-DCMAKE_BUILD_TYPE=Debug`
