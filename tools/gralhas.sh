#!/bin/bash

grep -R --include="*.md" --include="*.cpp" --include="*.h" --line-number --color=always "$1" ../

