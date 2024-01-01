#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> graph(5);
    
    graph[0].push_back(1);
    graph[0].push_back(4);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(0);
    graph[4].push_back(3);
    
    return 0;
}
