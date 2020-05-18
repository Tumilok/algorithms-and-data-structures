//
// created by Uladzislau Tumilovich
//

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>

enum elementStatus
{
    FREE,
    BOOKED
};

struct HashElement
{
    elementStatus status = FREE;
    std::string data = "";
};

struct HashMap
{
    int size;
    int maxSize;
    HashElement *array;
};

HashMap *createHashMap(int maxSize);
void hashMapInsert(HashMap *hashmap, std::string data);
bool hashMapRemove(HashMap *hashmap, std::string data);
int hashMapFind(HashMap *hashmap, std::string data);
void hashMapReorganization(HashMap *hashmap);
int hash(std::string data);
bool hashMapLoadFactor(HashMap *hashmap);
int hashMapSize(HashMap *hashmap);
int hashMapMaxSize(HashMap *hashmap);
void deleteHashMap(HashMap *hashmap);

#endif //HASH_TABLE_H