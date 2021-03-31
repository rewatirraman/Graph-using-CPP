/*
    ------------------------------
    Detect cycle in Directed Graph
    ------------------------------

        - For detecting cycle in the graph i am using modified DFS.
        - DFS for a connected graph produces a tree, There is a cycle in a graph if there exist a back edge in the graph.
        - A back edge is an edge that is from node to itsef (self loop) or one of its ancestors.

    ------------------------------
    Detect cycle in UnDirected Graph
    ------------------------------    

        - Here also i will use DFS with some modification.
        - For every visited vertex `v`, if there is an adjacent `u` such that that
            `u` is already visited and `u` is not the parent of `y`, then there is a cycle in the graph.
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;
    int numOfVertex;
    
    public:
        Graph(){}
        Graph(int v) {
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
                    cout << v << ",";
                } cout << endl;
            }
        }

        void addEdge(int u, int v, bool bidir = false)
        {
            adjList[u].push_back(v);
            if(bidir)
                adjList[v].push_back(u);
        }

        int getvertexCount() {return numOfVertex;}

        map<int, list<int>> getAdjList() {return adjList;}
};


class DirectedGraph : public Graph
{
    string *color;
    bool isCyclic = false;

    void checkForCycle_Util(map<int, list<int>> &myList, int u)
    {
        color[u] = "GREY";
    
        for (auto v : myList[u])
        {
            if (color[v] == "WHITE") {
                // This node is not visited.
                checkForCycle_Util(myList, v);
            } 
            else if (color[v] == "GREY")
            {
                // Back edge found, hence cycle exist in the graph.
                isCyclic = true;
            }
        }
        color[u] = "BLACK";      
    }

    public:
        DirectedGraph(){}
        DirectedGraph(int v) : Graph(v) {}
    
        void checkForCycle()
        {
            color = new string[getvertexCount()];
            map<int, list<int>> myList = getAdjList();
            
            for (int i = 0; i < getvertexCount(); i++)
            {
                color[i] = "WHITE";
            }
            
            for (auto rows : myList)
            {
                int u  = rows.first;
                if (color[u] == "WHITE")
                    checkForCycle_Util(myList, u);
            }

            // for (int i = 0; i < getvertexCount() ; i++)
            // {
            //     cout << color[i] << " ";
            // } cout << endl;
            
            if (isCyclic)
                cout << "Graph contains cycle." << endl;
            else
                cout << "Graph does not contains cycle." << endl;
                
        }
};


class UnDirectedGraph : public Graph
{
    string *color;
    int *parent;
    bool isCyclic = false;

    void checkForCycle_Util(map<int, list<int>> &myList, int u)
    {
        color[u] = "GREY";
    
        for (auto v : myList[u])
        {
            if (color[v] == "WHITE") {
                // This node is not visited.
                parent[v] = u;
                checkForCycle_Util(myList, v);
            } 
            else if ( (color[v] == "GREY") && (parent[v] != u) )
            {
                // Back edge found, hence cycle exist in the graph.
                isCyclic = true;
            }
        }
        color[u] = "BLACK";      
    }

    public:
        UnDirectedGraph(){}
        UnDirectedGraph(int v) : Graph(v) {}
    
        void checkForCycle()
        {
            color = new string[getvertexCount()];
            parent = new int[getvertexCount()];

            map<int, list<int>> myList = getAdjList();
            
            for (int i = 0; i < getvertexCount(); i++)
            {
                color[i] = "WHITE";
                parent[i] = -1;
            }
            
            for (auto rows : myList)
            {
                int u  = rows.first;
                if (color[u] == "WHITE")
                    checkForCycle_Util(myList, u);
            }

            // for (int i = 0; i < getvertexCount() ; i++)
            // {
            //     cout << color[i] << " ";
            // } cout << endl;
            
            if (isCyclic)
                cout << "Graph contains cycle." << endl;
            else
                cout << "Graph does not contains cycle." << endl;
                
        }
};

int main()
{
/*Directed Graph Test Cases*/
    /*This Graph contains cycle in it.*/
    // DirectedGraph g1(4);
    // g1.addEdge(0, 1);
    // g1.addEdge(0, 2);
    // g1.addEdge(1, 2);
    // g1.addEdge(2, 0);
    // g1.addEdge(2, 3);
    // g1.addEdge(3, 3);
    // g1.printGraph();
    // g1.checkForCycle();

    /*This graph does not contains cycle.*/
    // DirectedGraph g2(4);
    // g2.addEdge(0, 1);
    // g2.addEdge(0, 2);
    // g2.addEdge(1, 2);
    // g2.addEdge(2, 3);
    // g2.printGraph();
    // g2.checkForCycle();

/*Undirected Graph test cases.*/
    /*This graph contains cycle.*/
    UnDirectedGraph g3(4);
    g3.addEdge(1, 0, true);
    g3.addEdge(0, 2, true);
    g3.addEdge(2, 1, true);
    g3.addEdge(2, 3, true);
    g3.printGraph();
    g3.checkForCycle();

    /*This graph does not contains cycle.*/
    UnDirectedGraph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);  
    g4.printGraph();
    g4.checkForCycle();  
    return 0;
}