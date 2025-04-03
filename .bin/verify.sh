#!/bin/bash
set -e

cd ~/competitive/library
oj-verify run
oj-verify docs
cd .verify-helper/markdown
git add .
git commit -m "update markdown files"
git push
