//
//  created by Uladzislau Tumilovich
//

#include <iostream>

// Structure for linked list
struct Node
{
	int value;  //value of a node
	Node *next; //pointer to a next node
};

////////////////////////////////////////////////////
// Aditional functions used in different sortings //
////////////////////////////////////////////////////

// Function return size of given list
int listSize(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

// Function prints list
void printList(Node *head)
{
	while (head != NULL)
	{
		std::cout << head->value << " ";
		head = head->next;
	}
    std::cout << std::endl;
}

// Function gets last node of given list
Node *getLastNode(Node *head)
{
	while (head->next != NULL) head = head->next;

	return head;
}

// Function adds node to given list
void addNode(Node *&head, Node *newNode)
{
    if(head == NULL) head = newNode;
    else
    {
        Node *p = getLastNode(head);
        p->next = newNode;
    }
}

// Function creates new list
void createList(Node *&head, int size)
{
    head = new Node;
    head->next = NULL;
    std::cin >> head->value;

    int count = size - 1;
    while(count > 0)
    {
        Node *newNode = new Node;
        newNode->next = NULL;
        std::cin >> newNode->value;
        addNode(head, newNode);
        count--;
    }
}

// Function frees memory
void deleteList(Node *head)
{
    Node *p;
    while(head)
    {
        p = head;
        head = head->next;
        delete p;
    }
    head = NULL;
}

///////////////////////////////
// Actual sorting algorithms //
///////////////////////////////

// Bubble sort
void bubbleSort(Node *&head)
{
	if (head == NULL || head->next == NULL) return;

    Node *current = NULL;
    Node *last = NULL;
    Node *next = NULL;
    bool isEnd;

	for (int i = 0; i < listSize(head); i++)
    {
        isEnd = true;
        current = head;
        next = current->next;
        last = NULL;

		while (current->next != NULL)
		{
			if (current->value > next->value)
            {
				if (last == NULL)
                {
                    head = next;
                    current->next = next->next;
                    next->next = current;
                    last = next;
                    next = current->next;
                }
                else
                {
                    current->next = next->next;
                    next->next = current;
                    last->next = next;
                    last = next;
                    next = current->next;
                }

                isEnd = false;
            }
            else
            {
                last = current;
                current = next;
                next = next->next;
            }
		}

        if (isEnd) return;
	}
}

// Selection sort
void selectionSort(Node *&head)
{
	if (head == NULL || head->next == NULL) return;

    Node *current = head;
    Node *last = NULL;	

	while (current->next != NULL)
	{
		Node *minNode = current;
		Node *it = current->next;

		while (it != NULL)
		{
			if (it->value < minNode->value) minNode = it;
			it = it->next;
		}

        if (minNode != current)
        {
            Node *prevMinNode = current;
            while (prevMinNode->next != minNode) prevMinNode = prevMinNode->next;


            if (current->next == minNode)
            {
                current->next = minNode->next;
                minNode->next = current;
                if (last != NULL) last->next = minNode;
                else head = minNode;

                last = minNode;
            }
		    else
            {
                prevMinNode->next = minNode->next;
                minNode->next = current->next;
                if (last != NULL) last->next = minNode;
                else head = minNode;
                current->next = prevMinNode->next;
                prevMinNode->next = current;
                
                last = minNode;
                current = last->next;
            }
        }
        else
        {
            last = current;
            current = current->next; 
        }		
	}
}

// Insertion sort
void insertSort(Node *&head)
{
	if (head == NULL || head->next == NULL) return;

	Node *current = head->next;
	Node *last = head;
	Node *temp = NULL;

	while (current != NULL)
	{
		temp = current->next;

		if (current->value < last->value)
		{
			last->next = temp;

			if (current->value < head->value)
			{
				current->next = head;
				head = current;
			}
			else
			{
				Node *p = head;

				while (p->next->value < current->value)	p = p->next;

				current->next = p->next;
				p->next = current;
			}

			current = temp;
		}
		else
		{
			current = current->next;
			last = last->next;
        }
	}
}

// Merge sort
Node *merge(Node *left, Node *right)
{
	Node *p = new Node;
	Node *head = p;

	while (left != NULL && right != NULL)
	{
		if (left->value <= right->value)
		{
			p->next = left;
			left = left->next;
		}
		else
		{
			p->next = right;
			right = right->next;
		}

		p = p->next;
		p->next = NULL;
	}

	while (left != NULL)
	{
		p->next = left;
		left = left->next;
		p = p->next;
		p->next = NULL;
	}

	while (right != NULL)
	{
		p->next = right;
		right = right->next;
		p = p->next;
		p->next = NULL;
	}

    p = head->next;
    delete head;
	return p;
}

void mergeSort(Node *&head)
{
	if (head == NULL || head->next == NULL) return;
	else
	{
		Node *first = head;
		Node *second = head;

		while (first->next != NULL)
		{
			first = first->next;

			if (first->next != NULL)
			{
				first = first->next;
				second = second->next;
			}
		}

		Node *temp = second->next;
		second->next = NULL;
		second = temp;
		first = head;

		mergeSort(first);
		mergeSort(second);

		head = merge(first, second);
	}
}

// Quick sort
Node *partition(Node *head, Node *end, Node *&newHead, Node *&newEnd)
{
	Node *pivot = end;
	Node *last = NULL, *current = head, *tail = pivot;

	while (current != pivot)
	{
		if (current->value < pivot->value)
		{
			if (newHead == NULL) newHead = current;

			last = current;
			current = current->next;
		}
		else
		{
			if (last != NULL) last->next = current->next;

			Node *temp = current->next;
			current->next = NULL;
			tail->next = current;
			tail = current;
			current = temp;
		}
	}

	if (newHead == NULL) newHead = pivot;

	newEnd = tail;

	return pivot;
}

Node *quickSortRecursive(Node *head, Node *end)
{
	if (head == NULL || head == end) return head;

	Node *newHead = NULL;
	Node *newEnd = NULL;

	Node *pivot = partition(head, end, newHead, newEnd);

	if (newHead != pivot)
	{
		Node *temp = newHead;
		while (temp->next != pivot) temp = temp->next;
		temp->next = NULL;

		newHead = quickSortRecursive(newHead, temp);

		temp = getLastNode(newHead);
		temp->next = pivot;
	}

	pivot->next = quickSortRecursive(pivot->next, newEnd);

	return newHead;
}

void quickSort(Node *&head)
{
	head = quickSortRecursive(head, getLastNode(head));
}

// Function to run a program
void runListSort()
{
    int size;
    Node *head = NULL;

    std::cin >> size;

    std::cout << "Bubble Sort:" << std::endl;
    createList(head, size);
    printList(head);
    bubbleSort(head);
    printList(head);
    deleteList(head);

    std::cout << "Selection Sort:" << std::endl;
    createList(head, size);
    printList(head);
    selectionSort(head);
    printList(head);
    deleteList(head);
  
    std::cout << "Insertion Sort:" << std::endl;
    createList(head, size);
    printList(head);
    insertSort(head);
    printList(head);
    deleteList(head);
   
    std::cout << "Merge Sort:" << std::endl;
    createList(head, size);
    printList(head);
    mergeSort(head);
    printList(head);
    deleteList(head);

    std::cout << "Quick Sort:" << std::endl;
    createList(head, size);
    printList(head);
    quickSort(head);
    printList(head);
    deleteList(head);
}

int main()
{
    runListSort();

    return 0;
}
