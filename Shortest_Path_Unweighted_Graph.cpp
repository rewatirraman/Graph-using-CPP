#include<bits/stdc++.h>
using namespace std;

class ShortestPath
{
    map<int, list<int>> adjList;
    int numVertex;
    public:
        ShortestPath(){}
        ShortestPath(int v){ numVertex = v; }
        
        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printGraph(){
            for (auto rows : adjList)
            {
                int u = rows.first;
                cout << u << "->";
                for (auto v : adjList[u])
                {
                    cout << v << ",";
                } cout << endl;
            }
        }

        void displayPath(vector<int> parent, int node)
        {
            if (parent[node] == -1) {
                cout << node << " ";
                return;
            }
            displayPath(parent, parent[node]);
            cout << node << " ";
        }

        int minDistance(int src, int dest)
        {
            int distance[numVertex] = {-1};
            vector<int> parent(numVertex, -1);
            vector<bool> color(numVertex, false);
            queue<int> Q;
            
            Q.push(src);
            color[src] = true;
            distance[src] = 0;

            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (auto v : adjList[u])
                {
                    if (!color[v])
                    {
                        color[v] = true;
                        distance[v] = distance[u]+1;
                        parent[v] = u;
                        Q.push(v);
                        //if (dest == v) {return distance[v];}
                    }
                }
            }
            cout << "Minimum path connecting " << src << " & " << dest << " is ==> ";
            displayPath(parent, dest);
            cout << endl;
            return distance[dest];
        }
};

int main()
{
    ShortestPath g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 7);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);    
    g.printGraph(); 
    
    cout << "Enter src and destionation node in space separated format" << endl;
    int src, dest;
    cin >> src >> dest;
    cout << "Minimum distance b/w node "<< src <<  " & " << dest <<" is " << g.minDistance(src, dest) << endl;
    return 0;
}