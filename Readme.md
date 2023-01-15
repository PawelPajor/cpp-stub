# Read me

- [Read me](#read-me)
  - [To initialise project from this repo](#to-initialise-project-from-this-repo)
  - [Conan](#conan)

## To initialise project from this repo

- Copy all files/directories from of `project-with-*` directory to the new directory
- In `./CMakeLists.txt` change project name from `stub` to your project name
- In all `*.cpp *.hpp` files change namespace from `stub` to your namespace

## Conan

The dependencies are managed by [conan](https://conan.io). Before compilation:
- ensure that you have [conan](https://conan.io) installed
- install all the dependencies to appropriate directories. For example if you are using CLion you will:
  ```
  conan install --install-folder cmake-build-debug . --build=missing
  conan install --install-folder cmake-build-release . --build=missing
  ```
  