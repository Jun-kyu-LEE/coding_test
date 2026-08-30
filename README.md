# coding_test

코딩테스트 풀이 모음. **SWEA** 중심, **C++17**.

```
swea/         문제번호.cpp        (예: 1289.cpp, 1949_2.cpp = 재풀이)
baekjoon/
programmers/
practice/     번호 없는 연습 코드 (유형별)
templates/    자주 쓰는 코드 조각
```

## 새 문제 풀 때

```bash
./new.sh 11315
```

`swea/11315.cpp` 가 SWEA 기본 틀로 만들어집니다. 풀고 나서:

```bash
git add . && git commit -m "SWEA 11315" && git push
```

## templates

| 파일 | 내용 |
|---|---|
| `swea_base.cpp` | SWEA 입출력 기본 틀 |
| `bruteforce.cpp` | 부분집합 · 순열 · 조합 |
| `grid_bfs_dfs.cpp` | 격자 BFS/DFS |
| `simulation.cpp` | 배열 회전, 방향 전환 |
| `dsu.cpp` | 유니온 파인드, 크루스칼 |
| `dijkstra.cpp` | 최단경로 |
| `binary_search.cpp` | 이분탐색, 파라메트릭 서치 |

## 메모

- 출력 형식: `#테스트케이스번호 답`
- 예전 풀이들은 CP949 → UTF-8 변환하고 문제 지문 주석을 제거한 상태입니다.
