# Lib for get informartion from GitHub

# Installing Conan and CMake

```bash

conan install . -s build_type=Debug -s compiler.cppstd=23 --output-folder=build --build missing

conan install . -s build_type=Release -s compiler.cppstd=23 --output-folder=build --build missing

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

cmake --build build

cmake --build build -t help

cmake --build build -t unit_tests%

```

# to test the code

```bash

ctest --test-dir build --output-on-failure

# ctest --test-dir build --output-on-failure -R Day03

# ctest --test-dir build --output-on-failure -R Day03_Address.Get_next_address_with_multiple_movements -V

```
