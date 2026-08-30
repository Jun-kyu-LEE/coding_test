#!/usr/bin/env bash
# 새 문제 폴더를 만든다.
#   ./new.sh d3 1289 원재의메모리복구하기
#   ./new.sh baekjoon 1000 A+B
set -e

if [ $# -lt 2 ]; then
    echo "사용법: ./new.sh <d1~d5|baekjoon|programmers> <문제번호> [문제이름]"
    exit 1
fi

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
LEVEL="$1"
NUM="$2"
NAME="${3:-}"

case "$LEVEL" in
    d1|d2|d3|d4|d5) DIR="$ROOT/swea/$LEVEL" ;;
    baekjoon|programmers) DIR="$ROOT/$LEVEL" ;;
    *) echo "알 수 없는 위치: $LEVEL"; exit 1 ;;
esac

TARGET="$DIR/${NUM}${NAME:+_$NAME}"

if [ -d "$TARGET" ]; then
    echo "이미 있음: $TARGET"
    exit 1
fi

mkdir -p "$TARGET"
cp "$ROOT/templates/swea_base.cpp" "$TARGET/solution.cpp"
sed -e "s/{문제번호}/$NUM/" -e "s/{문제이름}/$NAME/" -e "s/{난이도}/${LEVEL#d}/" \
    "$ROOT/templates/note.md" > "$TARGET/note.md"
: > "$TARGET/input.txt"

echo "생성됨: $TARGET"
echo "  solution.cpp  note.md  input.txt"
