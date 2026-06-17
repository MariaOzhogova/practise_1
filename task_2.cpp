// минимальное число новых линий = количество компонент - 1 =>
// ищем количество компонент связности через дфс: запускаем 
// дфс в вершине, проверяем, есть ли вершины, которых он не затронул,
// если есть, то + компонента и запускаем дфс в этой вершине и так далее,
// пока все вершины не проверим
#include <iostream>
#include <vector>
#include <algorithm>
void Dfs(int v2, const std::vector<std::vector<int>>& afj, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            Dfs(v, adj, visited);
        }
    }
}
int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<bool> visited(n + 1, false)
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            Dfs(i, adj, visited)
        }
    }
    std::cour << components - 1;
    std::cout << std::endl;
    return 0;
}
