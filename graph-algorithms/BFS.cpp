//
//  created by Uladzislau Tumilovich
//

#include "BFS.h"

// Breadth First Search using adjacency matrix

void matrixBFS(int **G, int v, int s)
{
    int *color = new int[v];
    int *distance = new int[v];
    int *predecessor = new int[v];

    for(int i = 0; i < v; i++)
    {
        color[i] = WHITE;
        distance[i] = MAX;
        predecessor[i] = -1;
    }
    
    std::queue<int> q;
    q.push(s);

    color[s] = GREY;
    distance[s] = 0;
    predecessor[s] = -1;

    int current;

    while(!q.empty())
    {
        current = q.front();
        q.pop();

        std::cout << current << " ";

        for(int i = 0; i < v; i++)
        {
            if(G[current][i] == 1 && color[i] == WHITE)
            {
                color[i] = GREY;
                distance[i] = distance[current] + 1;
                predecessor[i] = current;
                q.push(i);
            }
        }
        color[current] = BLACK;
    }

    std::cout << std::endl;
    for(int i = 0; i < v; i++)
    {
        std::cout << "index: " << i << ", distance: " 
            << distance[i] << ", predecessor: " 
                << predecessor[i] << std::endl;
    }

    delete [] color;
    delete [] distance;
    delete [] predecessor;
}

// Breadth First Search using adjacency list

void listBFS(vertex **G, int v, int s)
{
    int *color = new int[v];
    int *distance = new int[v];
    int *predecessor = new int[v];

    for(int i = 0; i < v; i++)
    {
        color[i] = WHITE;
        distance[i] = MAX;
        predecessor[i] = -1;
    }

    std::queue<int> q;
    q.push(s);

    color[s] = GREY;
    distance[s] = 0;
    predecessor[s] = -1;

    int current;

    while(!q.empty())
    {
        current = q.front();
        q.pop();

        std::cout << current << " ";

        for(vertex *temp = G[current]; temp; temp = temp->next)
        {
            if(color[temp->value] == WHITE)
            {
                color[temp->value] = GREY;
                distance[temp->value] = distance[current] + 1;
                predecessor[temp->value] = current;
                q.push(temp->value);
            }
        }
        color[current] = BLACK;
    }

    std::cout << std::endl;
    for(int i = 0; i < v; i++)
    {
        std::cout << "index: " << i << ", distance: "
            << distance[i] << ", predecessor: "
                 << predecessor[i] << std::endl;
    }

    delete [] color;
    delete [] distance;
    delete [] predecessor;
}

// Functions to run a program

void runMatrixBFS()
{
    int **matrix;
    int v, e, s;

    std::cout << "BFS on undirected Graph: " << std::endl;
    std::cin >> v >> e >> s;
    matrix = createUndirectedMatrixGraph(v, e); // creating undirected graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixBFS(matrix, v, s);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;

    std::cout << "BFS on directed Graph: " << std::endl;
    std::cin >> v >> e >> s;
    matrix = createDirectedMatrixGraph(v, e);   // creating directed graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixBFS(matrix, v, s);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;
}

void runListBFS()
{
    vertex **list;
    int v, e, s;

    std::cout << "BFS on undirected Graph: " << std::endl;
    std::cin >> v >> e >> s;
    list = createUndirectedListGraph(v, e);     // creating undirected graph using adjacency list
    printListGraph(list, v);
    listBFS(list, v, s);
    deleteListGraph(list, v);
    std::cout << std::endl;

    std::cout << "BFS on directed Graph: " << std::endl;
    std::cin >> v >> e >> s;
    list = createDirectedListGraph(v, e);       // creating directed graph using adjacency list
    printListGraph(list, v);
    listBFS(list, v, s);
    deleteListGraph(list, v);
    std::cout << std::endl;
}