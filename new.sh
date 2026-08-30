#!/usr/bin/env bash
# 새 문제 파일을 만든다.
#   ./new.sh 11315            -> swea/11315.cpp
#   ./new.sh baekjoon 1000    -> baekjoon/1000.cpp
set -e

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [ $# -eq 1 ]; then
    DIR="swea"; NUM="$1"
elif [ $# -eq 2 ]; then
    DIR="$1"; NUM="$2"
else
    echo "사용법: ./new.sh <번호>  또는  ./new.sh <baekjoon|programmers> <번호>"
    exit 1
fi

TARGET="$ROOT/$DIR/$NUM.cpp"
[ -d "$ROOT/$DIR" ] || { echo "없는 폴더: $DIR"; exit 1; }
[ -e "$TARGET" ] && { echo "이미 있음: $DIR/$NUM.cpp"; exit 1; }

cp "$ROOT/templates/swea_base.cpp" "$TARGET"
echo "$DIR/$NUM.cpp"

# 에디터에서 바로 열기
if command -v code >/dev/null 2>&1; then
    code "$TARGET"
fi
