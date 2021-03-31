/*
    -------------------
    Topological Sorting
    -------------------
        Topological sorting for Directed acyclic grah (DAG) is a linear ordering of vertices,
        such that for every directed edge uv, vertex u comes before v in the ordering.

        - DAG always have atleast one node with inDegree=0 & another with outDegree=0;
            -- The above mentioned point holds true b/c longest path b/w 2 nodes in a DAG is finite.

        *Topological sort Vs DFS * 
            - DFS can be performed on directed or undirected graphs, 
                Topological sort is only possible for acyclic directed graph.
            - In DFS, we print the vertex when we discover it for the first time.
            - In Topological sort, we print the vertex when we complete recursively visiting
                all the neighbours of this vertex.

        *Application*
            - Task scheduling from the given dependencies among the tasks.
            - Build systems.
            - pre-requisite problems.
            - Advance packaging tools (apt-get)
        
        *Implementation*
            - Using DFS.
            - Using Kahn's algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;
    int numOfVertex;
    public:
        Graph(){}
        Graph(int v)
        {
            numOfVertex = v;
            for (int i = 0; i < numOfVertex; i++)
            {
                adjList[i] = {};
            }
        }

        void printGraph()
        {
            for (auto rows : adjList)
            {
                int u = rows.first;
                cout << u << "->";
                for (auto v : rows.second)
                {
                    cout << v << " ";
                } cout << endl;
            }
        }

        void addEdge(int u, int v, bool bidir=false)
        {
            adjList[u].push_back(v);
            if (bidir)
                adjList[v].push_back(u);
        }

        int getvertexCount() {return numOfVertex;}

        map<int, list<int>> getAdjList() {return adjList;}        
};

class TopologicalSort_DFS : public Graph
{
    //int *completionTime;
    string *color;
    stack<int> result;
    map<int, list<int>> myList;
    void topoSortUtil(int u)
    {
        color[u] = "GREY";

        for (auto v : myList[u])
        {
            if (color[v] == "WHITE")
            {
                topoSortUtil(v);
            }
        }
        // At this point of time the all the child of this vertex is visited.
        color[u] = "BLACK";
        //cout << u << " ";
        result.push(u);
    }

    public:
        TopologicalSort_DFS(){}
        TopologicalSort_DFS(int v) : Graph(v) {}
        void topoSort()
        {
            //completionTime =  new int[getvertexCount()];
            color =  new string[getvertexCount()];
            myList = getAdjList();
            for (int i = 0; i < getvertexCount(); i++)
            {
                color[i] = "WHITE";
                //completionTime[i] = INT_MAX;
            }
            
            for (auto rows : myList)
            {
                int u = rows.first;
                if (color[u] == "WHITE")
                {  
                    topoSortUtil(u);
                }
            }

            while (!result.empty())
            {
                cout << result.top() << " ";
                result.pop();
            } cout << endl;             
        }
};

/*This algo uses BFS*/
class KahnAlgo : public Graph
{
    public:
        KahnAlgo(){}
        KahnAlgo(int v) : Graph(v) {}

        void topoSort()
        {
            map<int, list<int>> myList = getAdjList();
            int *inDegree = new int[getvertexCount()];
            string *color = new string[getvertexCount()];

            for (int i = 0; i < getvertexCount(); i++)
            {
                color[i] = "WHITE";
                inDegree[i] = 0;
            }

            // find the in-degree of all the vertex
            for (auto rows : myList)
            {
                for (auto v : rows.second)
                {
                    inDegree[v]++;
                }
            }

            queue<int> Q;
            
            for (int i = 0; i < getvertexCount(); i++)
            {
                if (inDegree[i] == 0) {
                    Q.push(i);
                }
            }

            while (!Q.empty())
            {
                int u = Q.front();
                cout << u << " ";
                Q.pop();
                color[u] = "GREY";
                for (auto v : myList[u])
                {
                    if (color[v] == "WHITE")
                    {
                        inDegree[v] -= 1;
                        if (inDegree[v] == 0)
                            Q.push(v);
                    }
                }
            } cout << endl;   
        }
};

int main()
{
    // TopologicalSort_DFS g(6);
    // g.addEdge(5, 2);
    // g.addEdge(5, 0);
    // g.addEdge(4, 0);
    // g.addEdge(4, 1);
    // g.addEdge(2, 3);
    // g.addEdge(3, 1);
    // g.printGraph();
    // g.topoSort();


    // KahnAlgo g1(6);
    // g1.addEdge(5, 2);
    // g1.addEdge(5, 0);
    // g1.addEdge(4, 0);
    // g1.addEdge(4, 1);
    // g1.addEdge(2, 3);
    // g1.addEdge(3, 1);
    // g1.printGraph();
    // g1.topoSort(); 

    KahnAlgo g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(3, 4);
    g2.addEdge(3, 2);
    g2.printGraph();
    g2.topoSort(); 

    return 0;
}
