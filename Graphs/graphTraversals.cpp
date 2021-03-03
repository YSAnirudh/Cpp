#include <iostream>
#include <unordered_map>
#include <queue>

template <typename T>
class Graph
{
public:
    int v;
    List<int> *graph;
    Graph()
    {
        this->v = v;
        graph = new List<int>[v];
    }

    void addVertex(int v, int u, bool bDir = true)
    {
        graph[v].push_back(u);
        if (bDir)
        {
            graph[u].push_back(v);
        }
    }

    void dfsHelper(int src, unordered_set<int> &visited)
    {
        visited.insert(src);

        for (int neighbour : graph[src])
        {
            if (visited.count(neighbour) == 0)
            {
                dfsHelper(neighbour, &visited);
            }
        }
    }

    void DFS()
    {
        unordered_set<int> visited;
        for (int i = 0; i < this->v; i++)
        {
            if (visited.count(i) == 0)
            {
                dfsHelper(i, visited);
            }
        }
    }

    void bfsHelper(int src, bool *visited)
    {
        queue<int> tracker;
        tracker.push(src);
        visited[src] = true;

        while (!tracker.empty())
        {
            int curr = tracker.front();
            tracker.pop();
            for (int neighbour : graph[curr])
            {
                if (!visited[neighbour])
                {
                    tracker.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void BFS()
    {
        bool *visited = new bool[this->v];
        for (int i = 0; i < this->v; i++)
        {
            if (!visited[i])
            {
                bfsHelper(0, visited);
            }
        }
        delete[] visited;
    }

    int noOfComps()
    {
        int count = 0;
        unordered_set<int> visited;
        for (int i = 0; i < this->v; i++)
        {
            if (visited.count(i) == 0)
            {
                count++;
                dfsHelper(i, visited);
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}