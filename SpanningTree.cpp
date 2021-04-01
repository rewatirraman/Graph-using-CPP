#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int parent;
    int rank;
};

struct Edges
{
    int u;
    int v;
    int w;

    bool operator<(const Edges& r){
        return (w < r.w);
    }
};

class SpanningTree
{
    vector<Node> dsuf;
    vector<Edges> edgeList;
    vector<Edges> mstKruskal;
    vector<Edges> mstPrims;
    int numVertex;
    int numEdges=0;;
    public:
        SpanningTree(){}
        SpanningTree(int vertex) {
            numVertex = vertex;
            dsuf.resize(numVertex);
            // Creating disjoint set equal to the number of vertices.
            for (int i = 0; i < numVertex; i++)
            {
                dsuf[i].parent = -1;
                dsuf[i].rank = 0;
            }
        }
        vector<Node> get_dsuf(){ return dsuf;}
        vector<Edges> get_edgeList(){ return edgeList;}
        void addEdge(int u, int v, int w)
        {
            struct Edges temp;
            temp.u = u;
            temp.v = v;
            temp.w = w;
            edgeList.push_back(temp);
            numEdges++;
        }

        void printGraph()
        {
            for (auto edge : edgeList)
            {
                cout << "(" << edge.u << ", " << edge.v << ", " <<  edge.w << ")" << endl;
            }
        }

        void sortEdges()
        {
            sort(edgeList.begin(), edgeList.end());
        }


        int findSet(int u)
        {
            if (dsuf[u].parent == -1) {return u;}
            else dsuf[u].parent = findSet(dsuf[u].parent);   // Path compression.
        }

        void unionSet(int u, int v)
        {
            u = findSet(u);
            v = findSet(v);

            if (dsuf[u].rank > dsuf[v].rank)
            {
                dsuf[v].parent = u;
            }
            else if (dsuf[u].rank < dsuf[v].rank)
            {
                dsuf[u].parent = v;
            }
            else
            {
                dsuf[u].parent = v;
                dsuf[v].rank += 1;
            }
        }

        void MST_Kruskal();
        void MST_Prims();

        int getMinDistanceVertexIndex(vector<int> distance, vector<bool> visited)
        {
            int min=INT_MAX, min_index = -1;
            for (int i = 0; i < numVertex; i++)
            {
                if (!visited[i] && distance[i] < min)
                {
                    min = distance[i];
                    min_index = i;
                }                
            }
            return min_index;
        }

};

void SpanningTree::MST_Kruskal()
{  
    cout << "Edges present in the Graph.\n";
    printGraph();
    // Sort the edges in non-decreasing order by there edges weight.
    sortEdges();

    int i=0, j=0;
    cout << "Number of edges = " << numEdges << endl;
    while(i<numVertex-1 && j<numEdges)
    {
        int u = edgeList[j].u;
        int v = edgeList[j].v;

        if (findSet(u) != findSet(v)) {
            mstKruskal.push_back(edgeList[j]);
            unionSet(u, v);
            i++;
        }

        j++;
        // else case just ignore b/c by Adding the edge in the tree cycle will be formed.
    }

    cout << "Edges present in the minimum spanning tree\n";
    for (auto edge : mstKruskal)
    {
        cout << "(" << edge.u << ", " << edge.v << ", " <<  edge.w << ")" << endl;
    }
}


void SpanningTree::MST_Prims()
{
    vector<int> distance(numVertex, INT_MAX);
    vector<int> parent(numVertex, -1);
    vector<bool> visited(numVertex, false);
    // <u, <<v, w>>>
    map<int, list<pair<int, int>>> adjList;
    for (int i=0; i<numVertex; i++) { adjList[i] = {}; }
    
    for (auto edg : edgeList)
    {
        adjList[edg.u].push_back({edg.v, edg.w});
        adjList[edg.v].push_back({edg.u, edg.w});
    }
    
    distance[0] = 0;    // making first vertex as starting vertex

    for(int i=0; i<numVertex-1; i++)
    {
        int u = getMinDistanceVertexIndex(distance, visited);
        for (auto v : adjList[u])
        {
            if (!visited[v.first] &&  (distance[v.first] > distance[u]))
            {
                distance[v.first] = distance[u];
                parent[v.first] = u;
            }
        }
        visited[u] = true;
    }

    for (int i = 0; i < numVertex; i++)
    {
        cout << "vertex=" << i << ", parent=" << parent[i] << endl;
    }  
}

int main()
{
    SpanningTree st1(9);

    st1.addEdge(8, 2, 2);
    st1.addEdge(6, 5, 2);
    st1.addEdge(0, 1, 4);
    st1.addEdge(2, 5, 4);
    st1.addEdge(2, 3, 7);
    st1.addEdge(7, 8, 7);
    st1.addEdge(3, 5, 14);
    st1.addEdge(0, 7, 8);
    st1.addEdge(1, 2, 8);
    st1.addEdge(3, 4, 9);
    st1.addEdge(5, 4, 10);
    st1.addEdge(1, 7, 11);
    st1.addEdge(8, 6, 6);
    st1.addEdge(7, 6, 1);    

    st1.MST_Kruskal();
    st1.MST_Prims();

    return 0;
}