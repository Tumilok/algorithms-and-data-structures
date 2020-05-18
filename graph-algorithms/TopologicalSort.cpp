//
//  created by Uladzislau Tumilovich
//

#include "TopologicalSort.h"

// Topological sort using adjacency matrix

void matrixVisitTopologicalSort(int **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;

    for(int i = 0; i < v; i++)
    {
        if(G[s][i] == 1 && color[i] == WHITE)
        {
            matrixVisitTopologicalSort(G, v, i, color, stack);
        }
    }

    color[s] = BLACK;
    stack.push(s);
}

void matrixTopologicalSort(int **G, int v)
{
    std::stack<int> stack;

    int color[v];
    for(int i = 0; i < v; i++) color[i] = WHITE;

    for(int i = 0; i < v; i++)
    {
        if(color[i] == WHITE)
        {
            matrixVisitTopologicalSort(G, v, i, color, stack);
        }
    }

    printStack(stack);
}

// Topological sort using adjacency list

void listVisitTopologicalSort(vertex **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;

    for(vertex *temp = G[s]; temp; temp = temp->next)
    {
        if(color[temp->value] == WHITE)
        {
            listVisitTopologicalSort(G, v, temp->value, color, stack);
        }
    }

    color[s] = BLACK;
    stack.push(s);
}

void listTopologicalSort(vertex **G, int v)
{
    std::stack<int> stack;
    
    int color[v];
    for(int i = 0; i < v; i++) color[i] = WHITE;

    for(int i = 0; i < v; i++)
    {
        if(color[i] == WHITE)
        {
            listVisitTopologicalSort(G, v, i, color, stack);
        }
    }

    printStack(stack);
}

// Function to run a program

void runMatrixTopologicalSort()
{
    int **matrix;
    int v, e;

    std::cout << "Topological sort of undirected Graph: " << std::endl;
    std::cin >> v >> e;
    matrix = createUndirectedMatrixGraph(v, e); // creating undirected graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixTopologicalSort(matrix, v);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;

    std::cout << "Topological sort of directed Graph: " << std::endl;
    std::cin >> v >> e;
    matrix = createDirectedMatrixGraph(v, e);   // creating directed graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixTopologicalSort(matrix, v);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;
}

void runListTopologicalSort()
{
    vertex **list;
    int v, e;

    std::cout << "Topological sort of undirected Graph: " << std::endl;
    std::cin >> v >> e;
    list = createUndirectedListGraph(v, e);     // creating undirected graph using adjacency list
    printListGraph(list, v);
    listTopologicalSort(list, v);
    deleteListGraph(list, v);
    std::cout << std::endl;

    std::cout << "Topological sort of directed Graph: " << std::endl;
    std::cin >> v >> e;
    list = createDirectedListGraph(v, e);       // creating directed graph using adjacency list
    printListGraph(list, v);
    listTopologicalSort(list, v);
    deleteListGraph(list, v);
    std::cout << std::endl;
}