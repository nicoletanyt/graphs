/*
Question: https://brilliant.org/practice/breadth-first-search/
*/

#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
  int V;
  list<int> *l;

public:
  Graph(int v) {
    V = v;
    l = new list<int>[V];
  }

  void addEdge(int i, int j, bool undir = false) {
    l[i].push_back(j);
    if (undir) {
      l[j].push_back(i);
    }
  }

  void printList() {
    for (int i = 1; i < V; i++) {
      cout << i << "--> ";
      for (auto node : l[i]) {
        cout << node << ", ";
      }
      cout << endl;
    }
  }

  void bfs(int source) {
    queue<int> q;
    bool *visited = new bool[V]{0};
    int *parent = new int[V];
    for (int i = 0; i < V; i++) {
      parent[i] = -1;
    }
    q.push(source);
    visited[source] = true;
    parent[source] = source;
    while (!q.empty()) {
      int front = q.front();
      cout << front << endl;
      q.pop();
      l[front].sort();
      l[front].reverse();
      for (auto nbr : l[front]) {
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;
          parent[nbr] = front;
        }
      }
    }
  }
};

int main() {
  Graph g(6);

  g.addEdge(3, 5);
  g.addEdge(5, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 4, true);

  // g.printList();
  g.bfs(1);

  return 0;
}
