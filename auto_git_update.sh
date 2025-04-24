#!/bin/bash

# Check if the user provided a commit message
if [ -z "$1" ]; then
  echo "Usage: $0 \"Your commit message\""
  exit 1
fi

git add .
git status
git commit -m "$1"
git push

