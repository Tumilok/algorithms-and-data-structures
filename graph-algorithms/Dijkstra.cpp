//
//  created by Uladzislau Tumilovich
//

#include "Dijkstra.h"

// Dijkstra's algrorithm using adjacency matrix

void matrixDijkstra(int **G, int v, int s)
{
    int *distance = new int[v];
    int *parent = new int[v];

    for (int i = 0; i < v; i++)
    {
        distance[i] = INF;
        parent[i] = -1;
    }

    PriorityQueue *heap = createHeap(v);

    heapInsertData(heap, s, 0);
    distance[s] = 0;

    Data vertex;

    while (!empty(heap))
    {
        vertex = heapExtractData(heap);

        for (int i = 0; i < v; i++)
        {
            if (G[vertex.value][i] != 0 && (distance[vertex.value] + G[vertex.value][i]) < distance[i])
            {
                parent[i] = vertex.value;                                       // save current starting vertex as a parent
                distance[i] = distance[vertex.value] + G[vertex.value][i];      //  update distance
                heapInsertData(heap, i, distance[i]);                           //  insert the vertex into queue
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        std::cout << i <<" - weight: " << distance[i] << ", path: ";

        int j = i;
        while(j != s)
        {
            std::cout << j << " ";
            j = parent[j];
        }

        std::cout << s << std::endl;
    }
}

// Function to run a program

void runMatrixDijkstra()
{
    int **matrix;
    int v, e, s;
   
    std::cout << "Dijkstra on wieghted uedirected Graph: " << std::endl;
    std::cin >> v >> e >> s;
    matrix = createWeightedUndirectedMatrixGraph(v, e); // creating weighted undirected graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixDijkstra(matrix, v, s);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;

    std::cout << "Dijkstra on wieghted directed Graph: " << std::endl;
    std::cin >> v >> e >> s;
    matrix = createWeightedDirectedMatrixGraph(v, e);   // creating weighted directed graph using adjacency matrix
    printMatrixGraph(matrix, v);
    matrixDijkstra(matrix, v, s);
    deleteMatrixGraph(matrix, v);
    std::cout << std::endl;
}