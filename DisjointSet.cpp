/*
    Time complexity = O(n*m)
        n = number of vertices
        m = number of Edges
*/

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> dsuf;

// int findSet(int vertex)
// {
//     if (dsuf[vertex] == -1) { return vertex;}
//     return findSet(dsuf[vertex]);
// }

// void unionSet(int u, int v)
// {
//     int AR_u = findSet(u);
//     int AR_v = findSet(v);
//     dsuf[AR_u] = AR_v;
// }

// bool isCyclic(vector<pair<int, int>> edgeList)
// {
//     for (auto edg : edgeList)
//     {
//         int AR_u = findSet(edg.first);
//         int AR_v = findSet(edg.second);
//         if (AR_u == AR_v) { return true; }

//         unionSet(AR_u, AR_v);
//     }
    
//     return false;
// }

// int main()
// {
//     int numEdge, numVertex;

//     cout << "Enter number of Vertices & Edges separated by space :" << endl;
//     cin >> numVertex >> numEdge;

//     // Consider all the vertices as separate set, by making parent to itself.
//     dsuf.resize(numVertex, -1);

//     vector<pair<int, int>> edgeList;
//     for (int i = 0; i < numEdge; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         edgeList.push_back({u, v});
//     }
    
//     if (isCyclic(edgeList)){
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }

//     return 0;
// }


/*
    ------------------
    Optimized approach
    ------------------
 */ 

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int parent;
    int rank;
};

vector<Node> dsuf;

int findSet(int u)
{
    if (dsuf[u].parent == -1) {return u;}
    return dsuf[u].parent=findSet(dsuf[u].parent);  // Path compression
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
        dsuf[v].rank+=1;
    }
}

bool isCyclic(vector<pair<int, int>> edgeList)
{
    for (auto edg : edgeList)
    {
        int u = edg.first;
        int v = edg.second;

        if (findSet(u) == findSet(v)) {return true;}

        unionSet(u, v);
    }
    
    return false;
}

int main()
{
    int numVertex, numEdge;
    cout << "Enter number of Vertices & Edges in space separated format" << endl;
    cin >> numVertex >> numEdge;
    
    dsuf.resize(numVertex);

    for (int i = 0; i < numVertex; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < numEdge; i++)
    {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }

    if (isCyclic(edgeList)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}