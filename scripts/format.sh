#!/bin/bash

clang-format -i $(find . -name '*.cpp' -o -name '*.h')

echo "All files have been formatted!"
