//
// Created by Uladzislau Tumilovich
//

#ifndef GRAPHS_DFS_H
#define GRAPHS_DFS_H

#include <iostream>
#include "Utils.h"

void matrixVisitDFS(int **G, int v, int s, int *color);
void matrixDFS(int **G, int v);
void runMatrixDFS();

void listVisitDFS(vertex **G, int v, int s, int *color);
void listDFS(vertex **G, int v);
void runListDFS();

#endif //GRAPHS_DFS_H
