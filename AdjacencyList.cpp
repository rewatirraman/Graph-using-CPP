#include<bits/stdc++.h>
using namespace std;


// Graph using Array of List.
class Graph
{
    int numVertex;
    list<int> *adjList;

    public:
        Graph(){}
        Graph(int v) {
            numVertex = v;
            adjList = new list<int>[numVertex];
        }

        void addEdge(int u, int v, bool bidir=true) {
            adjList[u].push_back(v);
            if (bidir)
                adjList[v].push_back(u);
        }

        void printGraph(){
            for (int i = 0; i < numVertex; i++)
            {
                cout << i << "->";
                for (auto node : adjList[i])
                {
                    cout << node << ",";
                } cout << endl;
            }
        }
};


template<typename T>
class Graph_using_map
{
    map<T, list<T>> adjList;

    public:
        Graph_using_map(){}
        void addEdge(T u, T v, bool bidir=true)
        {
            adjList[u].push_back(v);
            if (bidir)
                adjList[v].push_back(u);
        }

        void printGraph()
        {
            for (auto row : adjList)
            {
                T key = row.first;
                cout << key << "->";
                for (T node : row.second)
                {
                    cout << node << ",";
                } cout << endl;
            }
        }
};


int main()
{
    Graph firstGraph(6);

    firstGraph.addEdge(0, 1);
    firstGraph.addEdge(1, 2);
    firstGraph.addEdge(0, 4);
    firstGraph.addEdge(2, 4);
    firstGraph.addEdge(3, 2);
    firstGraph.addEdge(2, 3);
    firstGraph.addEdge(3, 5);
    firstGraph.addEdge(3, 4);

    firstGraph.printGraph();


    // Graph_using_map<string> secondGraph;

    // secondGraph.addEdge("Amritsar", "Delhi");
    // secondGraph.addEdge("Amritsar", "Jaipur");
    // secondGraph.addEdge("Delhi", "Patna");
    // secondGraph.addEdge("Delhi", "Banglore");
    // secondGraph.addEdge("Delhi", "Agra");
    // secondGraph.addEdge("Amritsar", "Patna");

    // secondGraph.printGraph();    
    return 0;
}