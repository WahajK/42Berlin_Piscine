#!/bin/bash

# Change to the Git repository root directory
repo_root=$(git rev-parse --show-toplevel)

# If the repository root is found, list ignored files
if [ -n "$repo_root" ]; then
  git -C "$repo_root" ls-files --others --ignored --exclude-standard
else
  echo "Not a git repository."
fi
