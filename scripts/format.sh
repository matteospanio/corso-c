#!/usr/bin/env bash
clang-format --verbose -i -style=microsoft $(find . -name '*.c' -o -name '*.h')
