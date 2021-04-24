/*
    https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

    Given an undirected graph with n vertices find the minimum number of colors needed to color all the vertices of the Graph.

    This minimum number of color is called chromatic number.

    Condition to be taken care while coloring are :
        1. Every vertex should be colored.
        2. No adjcent vertex should be colored with the same color.
        3. You should use minimum number of colors.

    There is no efficient algo to color the graph with minimum number of colors.
    
    Below is the basic algo that guarantees an upper bound on the number of colors = d+1,
        where d is the maximum degree of a vertex in the graph.

    **Algo**
        1. Color the first vertex with first color.
        2. Do the following for the remaining n-1 vertices:
            a. Consider the currently picked vertex & color it with the lowest numbered color that has not been used on any
                previously colored adjacent vertices.
*/

#include<bits/stdc++.h>
using namespace std;

class VertexColor
{
    int numVertex;
    map<int, list<int>> adjList;
    public:
        VertexColor(){}
        VertexColor(int v){
            numVertex = v;
            for (int i = 0; i < numVertex; i++) { adjList[i] = {}; }
        }

        void printGraph()
        {
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

        void addEdge(int u, int v)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int findMinColor()
        {
            int color[numVertex]={-1};
            color[0] = 0;
            for (int u = 1; u < numVertex; u++)
            {
                bool availableColor[numVertex] = {false};
                for (auto v : adjList[u])
                {
                    if (color[v] != -1)
                    {
                        // This vertex is already colored.
                        availableColor[color[v]] = true;
                    }
                }
                
                for (int i = 0; i < numVertex; i++)
                {
                    cout << availableColor[i] << " ";
                    if(!availableColor[i])
                    {
                        // This color is not used by the adjacent vertices,
                        // So, we can use this color for the current vertex.
                        color[u] = i;
                        break;
                    }
                }cout << endl;
            }
            
            // for (int i = 0; i < numVertex; i++)
            // {
            //     cout << color[i] << " ";
            // } cout << endl;
            
            return 0;
        }
};


int main()
{
    VertexColor g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.printGraph();
    g1.findMinColor();

    return 0;
}