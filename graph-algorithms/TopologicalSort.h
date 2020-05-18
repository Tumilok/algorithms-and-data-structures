//
// Created by Uladzislau Tumilovich
//

#ifndef GRAPHS_TOPOLOGICALSORT_H
#define GRAPHS_TOPOLOGICALSORT_H

#include <iostream>
#include <stack>
#include "Utils.h"

void matrixVisitTopologicalSort(int **G, int v, int s, int *color, std::stack<int> &stack);
void matrixTopologicalSort(int **G, int v);
void runMatrixTopologicalSort();

void listVisitTopologicalSort(vertex **G, int v, int s, int *color, std::stack<int> &stack);
void listTopologicalSort(vertex **G, int v);
void runListTopologicalSort();


#endif //GRAPHS_TOPOLOGICALSORT_H
