//
// created by Uladzislau Tumilovich
//

#include "Test.h"

// Tests for BST
void BST_Tests()
{
  {
	BSTNode *root = NULL;

	assert(BSTSize(root) == 0);
	assert(findBSTMinNode(root) == NULL);
	assert(findBSTMaxNode(root) == NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);
	
	assert(!removeBSTNode(root, 1));

	assert(BSTSize(root) == 0);
	assert(findBSTMinNode(root) == NULL);
	assert(findBSTMaxNode(root) == NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);
  }
  
  {
	BSTNode *root = NULL;

	assert(BSTSize(root) == 0);
	assert(findBSTMinNode(root) == NULL);
	assert(findBSTMaxNode(root) == NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);

  insertBSTNode(root, 3);

	assert(BSTSize(root) == 1);
	assert(findBSTMinNode(root)->value == 3);
	assert(findBSTMaxNode(root)->value == 3);
	assert(findBSTNode(root, 3) != NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);

	insertBSTNode(root, 1);

	assert(BSTSize(root) == 2);
	assert(findBSTMinNode(root)->value == 1);
	assert(findBSTMaxNode(root)->value == 3);
	assert(findBSTNode(root, 3) != NULL);
	assert(findBSTNode(root, 1) != NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root)->value == 1);
	assert(findSuccessorNode(findBSTNode(root, 1))->value == 3);
	assert(findPredecessorNode(findBSTNode(root, 1)) == NULL);

	insertBSTNode(root, 5);

	assert(BSTSize(root) == 3);
	assert(findBSTMinNode(root)->value == 1);
	assert(findBSTMaxNode(root)->value == 5);
	assert(findBSTNode(root, 3) != NULL);
	assert(findBSTNode(root, 1) != NULL);
	assert(findBSTNode(root, 5) != NULL);
	assert(findSuccessorNode(root)->value == 5);
	assert(findPredecessorNode(root)->value == 1);
	assert(findSuccessorNode(findBSTNode(root, 1))->value == 3);
	assert(findPredecessorNode(findBSTNode(root, 1)) == NULL);
	assert(findSuccessorNode(findBSTNode(root, 5)) == NULL);
	assert(findPredecessorNode(findBSTNode(root, 5))->value == 3);

	assert(removeBSTNode(root, 1));

	assert(BSTSize(root) == 2);
	assert(findBSTMinNode(root)->value == 3);
	assert(findBSTMaxNode(root)->value == 5);
	assert(findBSTNode(root, 3) != NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findBSTNode(root, 5) != NULL);
	assert(findSuccessorNode(root)->value == 5);
	assert(findPredecessorNode(root) == NULL);
	assert(findSuccessorNode(findBSTNode(root, 5)) == NULL);
	assert(findPredecessorNode(findBSTNode(root, 5))->value == 3);

	assert(removeBSTNode(root, 5));

	assert(BSTSize(root) == 1);
	assert(findBSTMinNode(root)->value == 3);
	assert(findBSTMaxNode(root)->value == 3);
	assert(findBSTNode(root, 3) != NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findBSTNode(root, 5) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);

	assert(removeBSTNode(root, 3));

	assert(BSTSize(root) == 0);
	assert(findBSTMinNode(root) == NULL);
	assert(findBSTMaxNode(root) == NULL);
	assert(findBSTNode(root, 3) == NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findBSTNode(root, 5) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);
  }
  {
	BSTNode *root = NULL;

	insertBSTNode(root, 3);
	insertBSTNode(root, 1);
	insertBSTNode(root, 5);

	assert(BSTSize(root) == 3);
	assert(findBSTMinNode(root)->value == 1);
	assert(findBSTMaxNode(root)->value == 5);
	assert(findBSTNode(root, 3) != NULL);
	assert(findBSTNode(root, 1) != NULL);
	assert(findBSTNode(root, 5) != NULL);
	assert(findSuccessorNode(root)->value == 5);
	assert(findPredecessorNode(root)->value == 1);
	assert(findSuccessorNode(findBSTNode(root, 1))->value == 3);
	assert(findPredecessorNode(findBSTNode(root, 1)) == NULL);
	assert(findSuccessorNode(findBSTNode(root, 5)) == NULL);
	assert(findPredecessorNode(findBSTNode(root, 5))->value == 3);

	assert(removeBSTNode(root, 3));

	assert(BSTSize(root) == 2);
	assert(findBSTMinNode(root)->value == 1);
	assert(findBSTMaxNode(root)->value == 5);
	assert(findBSTNode(root, 3) == NULL);
	assert(findBSTNode(root, 1) != NULL);
	assert(findBSTNode(root, 5) != NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root)->value == 1);
	assert(findSuccessorNode(findBSTNode(root, 1))->value == 5);
	assert(findPredecessorNode(findBSTNode(root, 1)) == NULL);

  assert(removeBSTNode(root, 5));

	assert(BSTSize(root) == 1);
	assert(findBSTMinNode(root)->value == 1);
	assert(findBSTMaxNode(root)->value == 1);
	assert(findBSTNode(root, 3) == NULL);
	assert(findBSTNode(root, 1) != NULL);
	assert(findBSTNode(root, 5) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);

	deleteBST(root);

	assert(BSTSize(root) == 0);
	assert(findBSTMinNode(root) == NULL);
	assert(findBSTMaxNode(root) == NULL);
	assert(findBSTNode(root, 3) == NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findBSTNode(root, 5) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);
  }
  {
	BSTNode *root = NULL;

	insertBSTNode(root, 3);
	insertBSTNode(root, 1);
	insertBSTNode(root, 5);

	assert(BSTSize(root) == 3);
	assert(findBSTMinNode(root)->value == 1);
	assert(findBSTMaxNode(root)->value == 5);
	assert(findBSTNode(root, 3) != NULL);
	assert(findBSTNode(root, 1) != NULL);
	assert(findBSTNode(root, 5) != NULL);
	assert(findSuccessorNode(root)->value == 5);
	assert(findPredecessorNode(root)->value == 1);
	assert(findSuccessorNode(findBSTNode(root, 1))->value == 3);
	assert(findPredecessorNode(findBSTNode(root, 1)) == NULL);
	assert(findSuccessorNode(findBSTNode(root, 5)) == NULL);
	assert(findPredecessorNode(findBSTNode(root, 5))->value == 3);

	assert(removeBSTNode(root, 1));

	assert(BSTSize(root) == 2);
	assert(findBSTMinNode(root)->value == 3);
	assert(findBSTMaxNode(root)->value == 5);
	assert(findBSTNode(root, 3) != NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findBSTNode(root, 5) != NULL);
	assert(findSuccessorNode(root)->value == 5);
	assert(findPredecessorNode(root) == NULL);
	assert(findSuccessorNode(findBSTNode(root, 5)) == NULL);
	assert(findPredecessorNode(findBSTNode(root, 5))->value == 3);

	assert(removeBSTNode(root, 3));

	assert(BSTSize(root) == 1);
	assert(findBSTMinNode(root)->value == 5);
	assert(findBSTMaxNode(root)->value == 5);
	assert(findBSTNode(root, 3) == NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findBSTNode(root, 5) != NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);

	assert(removeBSTNode(root, 5));

	assert(BSTSize(root) == 0);
	assert(findBSTMinNode(root) == NULL);
	assert(findBSTMaxNode(root) == NULL);
	assert(findBSTNode(root, 3) == NULL);
	assert(findBSTNode(root, 1) == NULL);
	assert(findBSTNode(root, 5) == NULL);
	assert(findSuccessorNode(root) == NULL);
	assert(findPredecessorNode(root) == NULL);
  }
}

// Tests for doubly linked list
void doublyLinkedListTests()
{
  {
    Node *list = NULL;

    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
  }
  {
    Node *list = NULL;

    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
    assert(findDoublyLinkedListNode(list, 1) == NULL);

    assert(!removeDoublyLinkedListNode(list, 45));

    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
    assert(findDoublyLinkedListNode(list, 1) == NULL);
  
    pushDoublyLinkedListNode(list, 1);

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 1);
    assert(findDoublyLinkedListNode(list, 1) != NULL);

    assert(removeDoublyLinkedListNode(list, 1));

    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
    assert(findDoublyLinkedListNode(list, 1) == NULL);

    appendDoublyLinkedListNode(list, 2);

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 1);
    assert(findDoublyLinkedListNode(list, 2) != NULL);

    assert(removeDoublyLinkedListNode(list, 2));

    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
    assert(findDoublyLinkedListNode(list, 2) == NULL);

    assert(!insertDoublyLinkedListNodeBefore(list, list, 3));

    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
    assert(findDoublyLinkedListNode(list, 3) == NULL);

    assert(!insertDoublyLinkedListNodeAfter(list, 4));
    
    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
    assert(findDoublyLinkedListNode(list, 4) == NULL);

    pushDoublyLinkedListNode(list, 5);

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 1);
    assert(findDoublyLinkedListNode(list, 5) != NULL);

    assert(insertDoublyLinkedListNodeBefore(list, list, 6));

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 2);
    assert(findDoublyLinkedListNode(list, 6) != NULL);

    assert(insertDoublyLinkedListNodeAfter(list->next, 7));

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 3);
    assert(findDoublyLinkedListNode(list, 7) != NULL);

    assert(insertDoublyLinkedListNodeAfter(list, 8));

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 4);
    assert(findDoublyLinkedListNode(list, 8) != NULL);

    assert(insertDoublyLinkedListNodeBefore(list, list->next, 9));

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 5);
    assert(findDoublyLinkedListNode(list, 9) != NULL);

    assert(removeDoublyLinkedListNode(list, 7));

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 4);
    assert(findDoublyLinkedListNode(list, 7) == NULL);

    assert(removeDoublyLinkedListNode(list, 9));

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 3);
    assert(findDoublyLinkedListNode(list, 9) == NULL);

    assert(removeDoublyLinkedListNode(list, 5));

    assert(!isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 2);
    assert(findDoublyLinkedListNode(list, 5) == NULL);

    deleteDoublyLinkedList(list);     

    assert(isDoublyLinkedListEmpty(list));
    assert(doublyLinkedListSize(list) == 0);
  }
}

// Tests for Find & Union
void findUnionTests()
{
  {
    Subset *first = createSubset(1);
    Subset *second = createSubset(2);
    Subset *third = createSubset(3);
    Subset *fourth = createSubset(4);
    Subset *fifth = createSubset(5);
  
    assert(Find(first) == first);
    assert(Find(second) == second);
    assert(Find(third) == third);
    assert(Find(fourth) == fourth);
    assert(Find(fifth) == fifth);

    deleteSubset(first);
    deleteSubset(second);
    deleteSubset(third);
    deleteSubset(fourth);
    deleteSubset(fifth);

  }
  {
    Subset *first = createSubset(1);
    Subset *second = createSubset(2);
    Subset *third = createSubset(3);
    Subset *fourth = createSubset(4);
    Subset *fifth = createSubset(5);

    assert(Union(first, second));

    assert(Find(first) == first);
    assert(Find(second) == first);
    assert(Find(third) == third);
    assert(Find(fourth) == fourth);
    assert(Find(fifth) == fifth);

    assert(Union(fourth, fifth));

    assert(Find(first) == first);
    assert(Find(second) == first);
    assert(Find(third) == third);
    assert(Find(fourth) == fourth);
    assert(Find(fifth) == fourth);

    assert(Union(third, fifth));

    assert(Find(first) == first);
    assert(Find(second) == first);
    assert(Find(third) == fourth);
    assert(Find(fourth) == fourth);
    assert(Find(fifth) == fourth);

    assert(Union(third, second));

    assert(Find(first) == fourth);
    assert(Find(second) == fourth);
    assert(Find(third) == fourth);
    assert(Find(fourth) == fourth);
    assert(Find(fifth) == fourth);

    assert(!Union(first, second));

    assert(Find(first) == fourth);
    assert(Find(second) == fourth);
    assert(Find(third) == fourth);
    assert(Find(fourth) == fourth);
    assert(Find(fifth) == fourth);

    deleteSubset(first);
    deleteSubset(second);
    deleteSubset(third);
    deleteSubset(fourth);
    deleteSubset(fifth);
  }
}

// Tests for Hash Map
void hashMapTests()
{
  {
    HashMap *hashmap = createHashMap(2);

    assert(hashMapSize(hashmap) == 0);
    assert(hashMapMaxSize(hashmap) == 2);

    deleteHashMap(hashmap);
  }
  {
    HashMap *hashmap = createHashMap(2);

    assert(hashMapSize(hashmap) == 0);
    assert(hashMapMaxSize(hashmap) == 2);

    assert(!hashMapRemove(hashmap, "data"));

    assert(hashMapSize(hashmap) == 0);
    assert(hashMapMaxSize(hashmap) == 2);

    hashMapInsert(hashmap, "first data");

    assert(hashMapSize(hashmap) == 1);
    assert(hashMapMaxSize(hashmap) == 2);

    hashMapInsert(hashmap, "second data");

    assert(hashMapSize(hashmap) == 2);
    assert(hashMapMaxSize(hashmap) == 4);

    hashMapInsert(hashmap, "third data");

    assert(hashMapSize(hashmap) == 3);
    assert(hashMapMaxSize(hashmap) == 8);

    hashMapInsert(hashmap, "fourth data");

    assert(hashMapSize(hashmap) == 4);
    assert(hashMapMaxSize(hashmap) == 8);

    assert(hashMapRemove(hashmap, "first data"));

    assert(hashMapSize(hashmap) == 3);
    assert(hashMapMaxSize(hashmap) == 8);

    assert(hashMapRemove(hashmap, "second data"));

    assert(hashMapSize(hashmap) == 2);
    assert(hashMapMaxSize(hashmap) == 8); 

    assert(hashMapRemove(hashmap, "third data"));

    assert(hashMapSize(hashmap) == 1);
    assert(hashMapMaxSize(hashmap) == 8);

    assert(hashMapRemove(hashmap, "fourth data"));

    assert(hashMapSize(hashmap) == 0);
    assert(hashMapMaxSize(hashmap) == 8);

    deleteHashMap(hashmap);
  }
}

// Tests for Priority Queue
void heapTests()
{
  {
    PriorityQueue *heap = createHeap(4);
    
    assert(isHeapEmpty(heap));
    assert(heapSize(heap) == 0);
    assert(heapMaxSize(heap) == 4);

    deleteHeap(heap);
  }
  {
    PriorityQueue *heap = createHeap(4);

    assert(isHeapEmpty(heap));
    assert(heapSize(heap) == 0);
    assert(heapMaxSize(heap) == 4);

    assert(heapExtract(heap) == MAX);

    assert(isHeapEmpty(heap));
    assert(heapSize(heap) == 0);
    assert(heapMaxSize(heap) == 4);

    assert(heapInsert(heap, 3));

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 1);
    assert(heapMaxSize(heap) == 4);

    assert(heapInsert(heap, 2));

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 2);
    assert(heapMaxSize(heap) == 4);

    assert(heapInsert(heap, 4));

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 3);
    assert(heapMaxSize(heap) == 4);

    assert(heapInsert(heap, 1));

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 4);
    assert(heapMaxSize(heap) == 4);

    assert(!heapInsert(heap, 5));

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 4);
    assert(heapMaxSize(heap) == 4);

    assert(heapExtract(heap) == 1);

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 3);
    assert(heapMaxSize(heap) == 4);

    assert(heapExtract(heap) == 2);

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 2);
    assert(heapMaxSize(heap) == 4);

    assert(heapExtract(heap) == 3);

    assert(!isHeapEmpty(heap));
    assert(heapSize(heap) == 1);
    assert(heapMaxSize(heap) == 4);

    assert(heapExtract(heap) == 4);

    assert(isHeapEmpty(heap));
    assert(heapSize(heap) == 0);
    assert(heapMaxSize(heap) == 4);

    deleteHeap(heap);
  }
}

// Tests for Queue
void queueTests()
{
  {
    Queue *queue = createQueue(3);

    assert(isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 0);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == INT16_MIN);
    assert(back(queue) == INT16_MIN);

    deleteQueue(queue);
  }
  {
    Queue *queue = createQueue(3);

    assert(isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 0);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == INT16_MIN);
    assert(back(queue) == INT16_MIN);

    assert(!dequeue(queue));

    assert(isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 0);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == INT16_MIN);
    assert(back(queue) == INT16_MIN);

    assert(enqueue(queue, 1));

    assert(!isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 1);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 1);
    assert(back(queue) == 1);

    assert(enqueue(queue, 2));

    assert(!isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 2);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 2);
    assert(back(queue) == 1);

    assert(enqueue(queue, 3));

    assert(!isQueueEmpty(queue));
    assert(isQueueFull(queue));
    assert(queueSize(queue) == 3);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 3);
    assert(back(queue) == 1);

    assert(!enqueue(queue, 4));

    assert(!isQueueEmpty(queue));
    assert(isQueueFull(queue));
    assert(queueSize(queue) == 3);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 3);
    assert(back(queue) == 1);

    assert(dequeue(queue));

    assert(!isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 2);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 3);
    assert(back(queue) == 2);

    assert(dequeue(queue));

    assert(!isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 1);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 3);
    assert(back(queue) == 3);

    assert(enqueue(queue, 5));

    assert(!isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 2);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 5);
    assert(back(queue) == 3);

    assert(enqueue(queue, 6));

    assert(!isQueueEmpty(queue));
    assert(isQueueFull(queue));
    assert(queueSize(queue) == 3);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 6);
    assert(back(queue) == 3);

    assert(!enqueue(queue, 7));

    assert(!isQueueEmpty(queue));
    assert(isQueueFull(queue));
    assert(queueSize(queue) == 3);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 6);
    assert(back(queue) == 3);

    assert(dequeue(queue));

    assert(!isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 2);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 6);
    assert(back(queue) == 5);

    assert(dequeue(queue));

    assert(!isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 1);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == 6);
    assert(back(queue) == 6);

    assert(dequeue(queue));

    assert(isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 0);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == INT16_MIN);
    assert(back(queue) == INT16_MIN);

    assert(!dequeue(queue));

    assert(isQueueEmpty(queue));
    assert(!isQueueFull(queue));
    assert(queueSize(queue) == 0);
    assert(queueMaxSize(queue) == 3);
    assert(front(queue) == INT16_MIN);
    assert(back(queue) == INT16_MIN);

    deleteQueue(queue);
  }
}

// Tests for SkipList
void skipListTests()
{
  {
    SkipList skiplist = createSkipList(3);

    assert(is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 0);

    deleteSkipList(skiplist);

    assert(is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 0);
  }
  {
    SkipList skiplist = createSkipList(3);

    assert(is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 0);

    assert(!removeSkipListNode(skiplist, 1));

    assert(is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 0);

    insertSkipListNode(skiplist, 5);

    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 1);
    assert(findSkipListNode(skiplist, 5) != NULL);

    insertSkipListNode(skiplist, 3);

    assert(findSkipListNode(skiplist, 5) != NULL);
    assert(findSkipListNode(skiplist, 3) != NULL);
    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 2);

    insertSkipListNode(skiplist, 7);

    assert(findSkipListNode(skiplist, 5) != NULL);
    assert(findSkipListNode(skiplist, 3) != NULL);
    assert(findSkipListNode(skiplist, 7) != NULL);
    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 3);

    insertSkipListNode(skiplist, 4);

    assert(findSkipListNode(skiplist, 5) != NULL);
    assert(findSkipListNode(skiplist, 3) != NULL);
    assert(findSkipListNode(skiplist, 7) != NULL);
    assert(findSkipListNode(skiplist, 4) != NULL);
    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 4);

    insertSkipListNode(skiplist, 6);

    assert(findSkipListNode(skiplist, 5) != NULL);
    assert(findSkipListNode(skiplist, 3) != NULL);
    assert(findSkipListNode(skiplist, 7) != NULL);
    assert(findSkipListNode(skiplist, 4) != NULL);
    assert(findSkipListNode(skiplist, 6) != NULL);
    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 5);

    assert(removeSkipListNode(skiplist, 5));

    assert(findSkipListNode(skiplist, 3) != NULL);
    assert(findSkipListNode(skiplist, 7) != NULL);
    assert(findSkipListNode(skiplist, 4) != NULL);
    assert(findSkipListNode(skiplist, 6) != NULL);
    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 4);

    assert(removeSkipListNode(skiplist, 7));

    assert(findSkipListNode(skiplist, 3) != NULL);
    assert(findSkipListNode(skiplist, 4) != NULL);
    assert(findSkipListNode(skiplist, 6) != NULL);
    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 3);

    assert(removeSkipListNode(skiplist, 3));

    assert(findSkipListNode(skiplist, 4) != NULL);
    assert(findSkipListNode(skiplist, 6) != NULL);
    assert(!is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 2);

    deleteSkipList(skiplist);

    assert(is_SkipListEmpty(skiplist));
    assert(SkipListSize(skiplist) == 0);
  }
}

// Tests for Stack
void stackTests() 
{
  {
    Stack *stack = createStack(2);

    assert(isStackEmpty(stack));
    assert(!isStackFull(stack));
    assert(stackSize(stack) == 0);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == INT16_MIN);

    deleteStack(stack);
  }
  {
    Stack *stack = createStack(2);
    
    assert(isStackEmpty(stack));
    assert(!isStackFull(stack));
    assert(stackSize(stack) == 0);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == INT16_MIN);

    assert(!pop(stack));

    assert(isStackEmpty(stack));
    assert(!isStackFull(stack));
    assert(stackSize(stack) == 0);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == INT16_MIN);

    assert(push(stack, 1));

    assert(!isStackEmpty(stack));
    assert(!isStackFull(stack));
    assert(stackSize(stack) == 1);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == 1);

    assert(push(stack, 2));

    assert(!isStackEmpty(stack));
    assert(isStackFull(stack));
    assert(stackSize(stack) == 2);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == 2);

    assert(!push(stack, 3));

    assert(!isStackEmpty(stack));
    assert(isStackFull(stack));
    assert(stackSize(stack) == 2);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == 2);

    assert(pop(stack));

    assert(!isStackEmpty(stack));
    assert(!isStackFull(stack));
    assert(stackSize(stack) == 1);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == 1);

    assert(pop(stack));

    assert(isStackEmpty(stack));
    assert(!isStackFull(stack));
    assert(stackSize(stack) == 0);
    assert(stackMaxSize(stack) == 2);
    assert(top(stack) == INT16_MIN);

    deleteStack(stack);
  }
}