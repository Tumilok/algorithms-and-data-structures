//
// Created by Uladzislau Tumilovich
//

#ifndef GRAPHS_BFS_H
#define GRAPHS_BFS_H

#include <iostream>
#include <queue>
#include "Utils.h"

#define MAX INT16_MAX

void matrixBFS(int **G, int v, int s);
void runMatrixBFS();

void listBFS(vertex **G, int v, int s);
void runListBFS();


#endif //GRAPHS_BFS_H
