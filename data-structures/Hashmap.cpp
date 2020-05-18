//
// created by Uladzislau Tumilovich
//

#include "Hashmap.h"

// Function creates a hashmap
HashMap *createHashMap(int maxSize)
{
    HashMap *hashmap = new HashMap;

    hashmap->maxSize = maxSize;
    hashmap->size = 0;
    hashmap->array = new HashElement[maxSize];

    return hashmap;
}

// Function inserts an element to Hashmap
void hashMapInsert(HashMap *hashmap, std::string data)
{
    int key = hash(data) % hashmap->maxSize;

    while (true)
    {
        if (hashmap->array[key].status == FREE)
        {
            hashmap->size++;
            hashmap->array[key].status = BOOKED;
            hashmap->array[key].data = data;

            break;
        }
        else
            key = (key + 1) % hashmap->maxSize;
    }
    
    if (hashMapLoadFactor(hashmap)) hashMapReorganization(hashmap);
}

// Function removes an element from Hashmap
bool hashMapRemove(HashMap *hashmap, std::string data)
{
    int key = hashMapFind(hashmap, data);

    if (key == -1) return false;

    hashmap->size--;
    hashmap->array[key].data = "";
    hashmap->array[key].status == FREE;

    return true;
}

// Function finds a Hash Element using data
int hashMapFind(HashMap *hashmap, std::string data)
{
    int key = hash(data) % hashmap->maxSize;
    int guard = key;

    do
    {
        if (hashmap->array[key].status == BOOKED && hashmap->array[key].data == data) return key;
        else key = (key + 1) % hashmap->maxSize;
    }
    while (key != guard);
    
    return -1;
}

// Function twice expends the max size of hashmap
void hashMapReorganization(HashMap *hashmap)
{
    HashElement *array = hashmap->array;
    hashmap->array = new HashElement[hashmap->maxSize * 2];
    hashmap->maxSize *= 2;
    hashmap->size = 0;

    for (int i = 0; i < hashmap->maxSize / 2; i++)
    {
        if (array[i].status == BOOKED)
        {
            hashMapInsert(hashmap, array[i].data);
        }
    }        
    
    delete [] array;
}

// Function culculates the number using data

int hash(std::string data)
{
    int result = 0;
    for (int i = 0; data[i] != '\0'; i++) result += (int)data[i] * 1337;

    return result;
}

// Function check whether function is overloaded or not
bool hashMapLoadFactor(HashMap *hashmap)
{  
    return (double)hashmap->size / (double)hashmap->maxSize >= 0.75 ? true : false;
}

// Function gives an amount of elements in HashMap
int hashMapSize(HashMap *hashmap)
{
    return hashmap->size;
}

// Function gives a max size of Hashmap
int hashMapMaxSize(HashMap *hashmap)
{
    return hashmap->maxSize;
}

// Function deletes Hashmap
void deleteHashMap(HashMap *hashmap)
{
    delete [] hashmap->array;
    delete hashmap;
}