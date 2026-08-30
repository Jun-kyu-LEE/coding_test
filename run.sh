#!/usr/bin/env bash
# 컴파일 + 실행 (input.txt 를 표준입력으로 넣어준다)
#   ./run.sh swea/d3/1289_원재의메모리복구하기
set -e

if [ $# -lt 1 ]; then
    echo "사용법: ./run.sh <문제폴더경로>"
    exit 1
fi

DIR="$1"
SRC="$DIR/solution.cpp"
BIN="$DIR/a.exe"

[ -f "$SRC" ] || { echo "solution.cpp 없음: $SRC"; exit 1; }

# SWEA 채점 환경과 동일한 표준으로 컴파일
g++ -std=c++17 -O2 -Wall -o "$BIN" "$SRC"

if [ -s "$DIR/input.txt" ]; then
    "$BIN" < "$DIR/input.txt"
else
    echo "(input.txt 가 비어있음 — 직접 입력하세요)"
    "$BIN"
fi
