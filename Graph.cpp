#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;

    // Below things are required for DFS.
    string* color_DFS;
    int* distance_DFS;
    int* parent_DFS;
    int* discoveryTime_DFS;
    int* completionTime_DFS;
    int time;

    void DFS_VISIT(int src)
    {
        discoveryTime_DFS[src] = time;
        time++;
        color_DFS[src] = "GREY";
        
        cout << src << " ";  // this will give in order of discovery time.
        
        for (auto v : adjList[src])
        {
            if (color_DFS[v] == "WHITE")
            {
                distance_DFS[v] = discoveryTime_DFS[src]+1;
                parent_DFS[v] = src;
                DFS_VISIT(v);
            }
        }

        color_DFS[src] = "BLACK";
        completionTime_DFS[src] = time;
        time++;

        // cout << src << " "; this will give in order of compeletion time.
    }

    public:
        Graph(){}

        //  Add edges in the Graph.
        void addEdge(int u, int v, bool bidir=true)
        {
            adjList[u].push_back(v);
            if (bidir)
                adjList[v].push_back(u);
        }

        // Display the adjecency list.
        void printGraphEdges()
        {
            for (auto rows : adjList)
            {
                int u = rows.first;
                cout << u << "\t->\t";
                for (auto v : rows.second)
                {
                    cout << v << ",";
                } cout << endl;
            }
        }

        void BFS(int src) {
            int numOfVertex = adjList.size();
            vector<string> color(numOfVertex, "WHITE");
            vector<int> distance(numOfVertex, INT_MAX);
            vector<int> parent(numOfVertex, -1);

            distance[src] = 0;
            parent[src] = -1;
            color[src] = "GREY";

            queue<int> Q;
            Q.push(src);

            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();

                for (auto v : adjList[u])
                {
                    if (color[v] == "WHITE")
                    {
                        color[v] = "GREY";
                        distance[v] = distance[u]+1;
                        parent[v] = u;
                        Q.push(v);
                    }
                }
                
                color[u] = "BLACK";
                cout << u << " ";
            } cout << endl;
        }

        void DFS(int src)
        {
            int numOfVertex = adjList.size();
            
            time = 0;

            color_DFS = new string[numOfVertex];
            distance_DFS = new int[numOfVertex];
            parent_DFS = new int[numOfVertex];
            discoveryTime_DFS = new int[numOfVertex];
            completionTime_DFS = new int[numOfVertex];

            for (int i = 0; i < numOfVertex ; i++)
            {
                color_DFS[i] = "WHITE";
                distance_DFS[i] = INT_MAX;
                parent_DFS[i] = -1;
                discoveryTime_DFS[i] = -1;
                completionTime_DFS[i] = -1;
            }
            
            color_DFS[src] = "GREY";
            parent_DFS[src] = -1;
            distance_DFS[src] = 0;

            DFS_VISIT(src);

            for (auto rows : adjList)
            {
                int u = rows.first;
                if (color_DFS[u] == "WHITE")
                {
                    DFS_VISIT(u);
                }
            }

            cout << endl;
        }
};

int main() {
    Graph g;

    g.addEdge(0, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 0, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 3, false);

    cout << "=====Adjacency List=====" << endl;
    g.printGraphEdges();

    cout << "=====Result of BFS=====" << endl;
    g.BFS(2);

    cout << "=====Result of DFS=====" << endl;
    g.DFS(2);
    return 0;
}