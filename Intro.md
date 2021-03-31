Graph:
------
    It is a data structure which is represented as a finite set of nodes (Vertex) & edges.

-------------
Applications:
-------------
    1. Shorted paths in Google Maps.
        Vertex  ->  Cities / Landmark
        Edge    ->  Roads / Flights
    2. Social Networking (FB, LinkedIn, Instagram, etc....)
        Vertex  ->  People
        Edge    -> connections
    3. Cicuit Design (Minimum length of the wire that supplies current to all the nodes & complete the circuits.)
        Vertex  ->  Resistors
        Edge    ->  Wire
    4. Routing algorithms
        Vertex  ->  routers across the globe
        Edge    ->  Time taken for packets to flow.
    5. Resolving dependencies.
        Vertex  ->  Api calls / software installations
        Edge    ->  Dependencies b/w tasks
    6. Deep learning
        Vertes  ->  Neurons
        Edge    ->  Connections b/w them.
    7. Web Document
        Vertex  ->  Dom elements
        Edge    ->  Connections

--------------------
Graph representation
--------------------
    1. Adjacency Matrix     --> Recommended to use for Dense Graph.
    2. Adjacency Lists (AdjacencyList.cpp)    --> Recommended to use for Sparse Graph.

    *Pros of Adjacency Matrix*
        - Easy to implement.
        - Removing an edge will take O(1) time.
        - Queries like whether there is an edge from vertex `u` to vertex `v` can be done in O(1).
    
    *Cons of Adjacency Matrxi*
        - It will consume `O(n*n)` space, where `n` is the number of vertex in the graph.
        - Addition of a new vertex will take `O(n)` time.
            For addition of a new vertex we need to increase both the row & column of the existing adjacency matrix,
            and then intialize the new elements related to that vertex to 0.
        - Removing of an vertex will take `O(n*n)` time.
            To remove a vertex we need to check if that vertex exists or not, then
            we need to shift the rows to the left & columns to upward.
            

    *Pros of Adjacency Lists*
        - Saves space O(m+n) : n is number of vertex & m is number of edges.
            Worst case space is O(n*n)
        - Adding a vertex is easier.

    *Cons of Adjacency Lists*
        - Query like whether there is an edge from vertex u to vertex v or not is O(n).


---------------
Graph Traversal
---------------
                    BFS (Breadth first search)                               DFS (Depth first search)
            
            - Iterative way                                         - Recursive way.
            - Uses Queue.                                           - Uses stack.

                
---------------
Graph Traversal     `BFS`
---------------
    - It traverses graph 'Breadth first', starting from source, then direct neighbours of source vertex,
        & then next layer and so on.....

    - Finding Shorted path of unweighted graph.

    - Snake & Ladder problem.

---------------
Graph Traversal     `DFS`
---------------


------------------------
Snakes N Ladders Problem
------------------------

![snakeNLadder](snakesNLadders.png)

    - This problem can be thought as a `Unweighted Directed Graph` problem, where from each cell we go to another cell.
    - Eg. 
        From 1  -> 2
        From 2  -> 15
        
    - Unweighted b/c we need one dice throw to move from one node to another.
    - We need to handle `snakes` & `ladders`,
        like if we reach at cell 2, it will take me to cell 15.
        similarly, if we reach at cell 34, it will take me to cell 12.
        * For handlig this we can create a mapping like below
            2   ->  +13
            5   ->  +2
            9   ->  +18
            17  ->  -13            
            18  ->  +11
            20  ->  -14
            24  ->  -8            
            25  ->  +10
            32  ->  -2
            34  ->  -22


        


    