//
//  created by Uladzislau Tumilovich
//

#include "DFS.h"

// Depth First Search using adjacency matrix

void matrixVisitDFS(int **G, int v, int s, int *color)
{
    color[s] = GREY;
    std::cout << s << " ";

    for(int i = 0; i < v; i++)
    {
        if(G[s][i] == 1 && color[i] == WHITE)
        {
            matrixVisitDFS(G, v, i, color);
        }
    }

    color[s] = BLACK;
}

void matrixDFS(int **G, int v)
{
    int color[v];
    for(int i = 0; i < v; i++) color[i] = WHITE;

    for(int i = 0; i < v; i++)
    {
        if(color[i] == WHITE)
        {
            matrixVisitDFS(G, v, i, color);
        }
    }

    std::cout << std::endl;
}

// Depth First Search using adjacency list

void listVisitDFS(vertex **G, int v, int s, int *color)
{
    color[s] = GREY;
    std::cout << s << " ";

    for(vertex *tempVertex = G[s]; tempVertex; tempVertex = tempVertex->next)
    {
        if(color[tempVertex->value] == WHITE)
        {
            listVisitDFS(G, v, tempVertex->value, color);
        }
    }

    color[s] = BLACK;
}

void listDFS(vertex **G, int v)
{
    int color[v];
    for(int i = 0; i < v; i++) color[i] = WHITE;

    for(int i = 0; i < v; i++)
    {
        if(color[i] == WHITE)
        {
            listVisitDFS(G, v, i, color);
        }
    }

    std::cout << std::endl;
}

// Functions to run a program

void runMatrixDFS()
{
    int **matrix;
    int v, e;

    std::cout << "DFS on undirected Graph: " << std::endl;
    std::cin >> v >> e;
    matrix = createUndirectedMatrixGraph(v, e); // creating undirected graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixDFS(matrix, v);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;

    std::cout << "BFS on directed Graph: " << std::endl;
    std::cin >> v >> e;
    matrix = createDirectedMatrixGraph(v, e);   // creating directed graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixDFS(matrix, v);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;
}

void runListDFS()
{
    vertex **list;
    int v, e;

    std::cout << "BFS on undirected Graph: " << std::endl;
    std::cin >> v >> e;
    list = createUndirectedListGraph(v, e);     // creating undirected graph using adjacency list
    printListGraph(list, v);
    listDFS(list, v);
    deleteListGraph(list, v);
    std::cout << std::endl;

    std::cout << "BFS on directed Graph: " << std::endl;
    std::cin >> v >> e;
    list = createDirectedListGraph(v, e);       // creating directed graph using adjacency list
    printListGraph(list, v);
    listDFS(list, v);
    deleteListGraph(list, v);
    std::cout << std::endl;
}