# Algorithm Practice

코딩테스트 준비 저장소. 주력은 **SWEA**, 언어는 **C++17**.
푼 코드를 아카이빙하는 용도입니다. 로컬 채점은 하지 않고, 정답 확인은 SWEA 사이트에서 합니다.

## 폴더 구조

```
algo/
├── swea/
│   ├── d1/ ~ d5/          # 난이도별
│   │   └── 1289_원재의메모리복구하기/
│   │       ├── solution.cpp
│   │       └── note.md    # 접근법 / 막혔던 지점
├── baekjoon/
├── programmers/
├── templates/             # 자주 쓰는 코드 조각
└── new.sh                 # 문제 폴더 생성
```

## 사용법

새 문제를 시작할 때:

```bash
./new.sh d3 1289 원재의메모리복구하기
```

`swea/d3/1289_원재의메모리복구하기/` 에 `solution.cpp`(SWEA 기본 틀)와 `note.md`가 만들어집니다.
SWEA에서 통과한 코드를 `solution.cpp`에 붙여넣고 커밋하면 끝입니다.

```bash
git add . && git commit -m "SWEA D3 1289 원재의 메모리 복구하기"
```

## SWEA 메모

- 출력 형식은 **`#테스트케이스번호 답`** — `#`와 번호 사이에 공백 없음, 번호와 답 사이에 공백 하나.
- SWEA 채점기는 g++ 기준이라 `#include <bits/stdc++.h>`가 동작합니다. (MSVC에서는 안 됩니다)
- 재귀 깊이가 깊은 문제는 스택 오버플로가 날 수 있습니다. 반복문 BFS로 바꾸는 걸 우선 고려하세요.

## templates

| 파일 | 내용 |
|---|---|
| `swea_base.cpp` | SWEA 입출력 기본 틀 |
| `bruteforce.cpp` | 부분집합 · 순열 · 조합 (완전탐색 3종) |
| `grid_bfs_dfs.cpp` | 격자 BFS/DFS, 4방향 델타 |
| `simulation.cpp` | 배열 회전, 방향 전환, 8방향 델타 |
| `dsu.cpp` | 유니온 파인드, 크루스칼 MST |
| `dijkstra.cpp` | 가중치 최단경로 |
| `binary_search.cpp` | 이분탐색, 파라메트릭 서치 |

## 진행 현황

| 날짜 | 문제 | 난이도 | 분류 | 결과 |
|---|---|---|---|---|
| | | | | |

## 취약 유형 메모

<!-- 틀린 문제의 유형을 여기 쌓아두고, 주기적으로 이 목록만 다시 푼다. -->

-
