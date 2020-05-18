//
// created by Uladzislau Tumilovich
//

#include "FindUnion.h"

// Function creates Subsets of a given value
Subset *createSubset(int value)
{
    Subset *subset = new Subset;

    subset->value = value;
    subset->rank = 0;
    subset->parent = subset;
    
    return subset;
}

// Function finds to which set given subset is belongs to
Subset *Find(Subset *subset)
{
    if (subset->parent != subset) Find(subset->parent);
    else return subset;
}

// Function unites two subsets into one 
bool Union(Subset *subset_1, Subset *subset_2)
{
    if (subset_1 == NULL || subset_2 == NULL) return false;

    subset_1 = Find(subset_1);
    subset_2 = Find(subset_2);

    if (subset_1 == subset_2) return false;

    if(subset_1->rank < subset_2->rank) subset_1->parent = subset_2;
    else subset_2->parent = subset_1;

    if (subset_1->rank == subset_2->rank) subset_1->rank++;

    return true;
}

// Function deletes subset
void deleteSubset(Subset *subset)
{
    delete(subset);
}