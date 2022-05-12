#include <vector>
#include <queue>
#include <iostream>
#include <string> 
#include <sstream>


const std::string input_string = "7 13 \
0 1 \
0 2 \
1 2 \
1 6 \
1 4 \
1 3 \
2 3 \
2 4 \
3 4 \
3 6 \
3 5 \
4 5 \
5 0";

void bfs(int startVertex, int n, std::vector<std::vector<int> > &adj, std::vector<bool> &visited) {
    std::queue<int> queue;
    // YOUR CODE HERE
    
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        // YOUR CODE HERE 
        
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i]; // v is a neighbor of u
            //YOUR CODE HERE
            
        }
    }
}

void dfs(int startVertex, int n, std::vector<std::vector<int> > &adj, std::vector<bool> &visited) {
    int u = startVertex;
    // YOUR CODE HERE

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i]; // v is a neighbor of u
        // YOUR CODE HERE

    }
}

int main() {
    int n, m; // n is the number of vertices, m is the number of edeges
    std::istringstream input(input_string);
    std::cin.rdbuf(input.rdbuf());
    std::cin >> n >> m;

    std::vector<std::vector<int> > adj(n, std::vector<int>()); // adj is the adjacency list in which adj[u] contains a list of neighbors of u 
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v; // (u, v) is an indirected edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<bool> visisted(n, false); // visisted is used to know which vertex has been visisted (e.g. visited[u] == true if vertex u has been visited)
    
    std::cout << "BFS Order Star From 0: " << std::endl;
    bfs(0, n, adj, visisted);
    std::cout << std::endl;
    
    visisted = std::vector<bool>(n, false);
    std::cout << "DFS Order Star From 0: " << std::endl;
    dfs(0, n, adj, visisted);
    std::cout << std::endl;

}
