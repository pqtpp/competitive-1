#!/bin/bash
# accnewスクリプト

# 入力を受け取る
read -p "ID・URL: " input_string

# https://atcoder.jp/contests/ を含んでいたら取り除く
clean_string=$(echo "$input_string" | sed 's|https://atcoder.jp/contests/||g')

# AtCoder のディレクトリへ移動して新規作成
cd atcoder || exit 1
acc n "$clean_string"
cd ../

# `clean_string` に対応するディレクトリの `main.cpp` を、フォルダ名が大きい順に開く
contest_dir="$HOME/competitive/atcoder/$clean_string"

if [ -d "$contest_dir" ]; then
    find "$contest_dir" -mindepth 1 -maxdepth 1 -type d | sort -r | while read -r dir; do
        if [ -f "$dir/main.cpp" ]; then
            code "$dir/main.cpp"
        fi
    done
else
    echo "Error: Contest directory $contest_dir does not exist."
    exit 1
fi
