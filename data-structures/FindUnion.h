//
// created by Uladzislau Tumilovich
//

#ifndef FIND_UNION_H
#define FIND_UNION_H

#include <iostream>

struct Subset
{
    int value;
    int rank;
    Subset *parent;
};

Subset *createSubset(int value);
Subset *Find(Subset *subset);
bool Union(Subset *subset_1, Subset *subset_2);
void deleteSubset(Subset *subset);


#endif //FIND_UNION_H