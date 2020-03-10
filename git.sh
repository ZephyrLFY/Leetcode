#! /bin/sh

read content

git add .
git commit -m "$content"
git push
