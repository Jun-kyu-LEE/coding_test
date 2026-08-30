// 유니온 파인드 (Disjoint Set Union)
// 그래프 연결성, MST(크루스칼), 그룹 묶기
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rnk;

    explicit DSU(int n) : parent(n), rnk(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {                       // 경로 압축
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {              // 이미 같은 집합이면 false
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) ++rnk[a];
        return true;
    }

    bool same(int a, int b) { return find(a) == find(b); }
};

// 크루스칼 MST 예시
long long kruskal(int n, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end());       // (비용, u, v) 순
    DSU dsu(n);
    long long total = 0;
    for (auto [cost, u, v] : edges)
        if (dsu.unite(u, v)) total += cost;
    return total;
}
