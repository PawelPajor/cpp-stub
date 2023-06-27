#!/bin/bash

conan install . --output-folder=cmake-build-debug --build=missing --profile=debug
conan install . --output-folder=cmake-build-release --build=missing --profile=release
