#!/usr/bin/env bash

read -p "URL: " input_string

// URLが空でないか確認
if [[ -z "$input_string" ]]; then
    echo "url is empty"
    exit
fi

URL="$input_string"

# タイトル取得
if [[ "$URL" == *"judge.yosupo.jp/problem/"* ]]; then
    # Yosupo Library Checker
    TITLE="yosupo-$(basename "$URL")"
elif [[ "$URL" == *"judge.u-aizu.ac.jp"* ]]; then
    # Aizu Online Judge
    TITLE="aizu-$(echo "$URL" | sed -n 's/.*[?&]id=\([^&#]*\).*/\1/p')"
else
    # fallback: URL末尾
    TITLE=$(basename "$URL")
fi


# 保存先とテンプレートパス
OUT_DIR="/workspaces/competitive/library/verify"
OUT_FILE="${OUT_DIR}/${TITLE}.test.cpp"
TEMPLATE="/workspaces/competitive/library/main.cpp"

# ディレクトリが存在しなければ作る
mkdir -p "$OUT_DIR"

# ファイル作成
{
    echo "#define PROBLEM \"$URL\"\n"
    cat "$TEMPLATE"
} > "$OUT_FILE"

echo "✅ Created: $OUT_FILE"
