//
// created by Uladzislau Tumilovich
//

#include <iostream>
#include <vector>
#include <algorithm>

class Sort
{
private:
    int m_size;                 // size of the array to sort
    int *m_array;               // array to sort
    float *m_floatArray;        // array to sort only by bucket sort


// Aditional functions used in different sortings
private:
    // Function swaps two intergers
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // Function returns max integer of array
    int getMax()
    {
        int max = m_array[0];

        for(int i = 1; i < m_size; i++)
            if (m_array[i] > max)
                max = m_array[i];

        return max;
    }

    // Function returns min integer of array
    int getMin()
    {
        int min = m_array[0];

        for(int i = 1; i < m_size; i++)
            if(m_array[i] < min)
                min = m_array[i];

        return min;
    }

    // Function sorts and merges two parts of array in one 
    void merge(int l1, int middle, int r2)
    {
        int *newArray = new int[m_size];
        int i = l1, start = l1;

        int r1 = middle;
        int l2 = middle+1;

        while (l1 <= r1 && l2 <= r2) 
            m_array[l1] > m_array[l2] ? newArray[i++] = m_array[l2++] : newArray[i++] = m_array[l1++];

        while(l1 <= r1) newArray[i++] = m_array[l1++];
        while(l2 <= r2) newArray[i++] = m_array[l2++];

        for(int j = start; j <= r2; j++) m_array[j] = newArray[j];

        delete [] newArray;
    }

    // Function sorts an array relatively to pivot element
    int partition(int low, int high)
    {
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (m_array[j] <= m_array[high])
            {
                i++;
                swap(m_array[j], m_array[i]);
            }
        }

        swap(m_array[i + 1], m_array[high]);
        
        return i + 1;
    }

    // Function puts given element into the right place
    void heapify(int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && m_array[left] > m_array[largest]) largest = left;
        if (right < n && m_array[right] > m_array[largest]) largest = right;
        if (largest != i)
        {
            swap(m_array[largest], m_array[i]);
            heapify(n, largest);
        }
    }

    // Function makes counting sort by given position
    void sortByPosition(int position)
    {
        int *newArray = new int[10];
        int *finalArray = new int[m_size];

        for (int i = 0; i < 10; i++) newArray[i] = 0;
        for (int i = 0; i < m_size; i++) newArray[(m_array[i] / position) % 10]++;

        for(int i = 1; i < 10; i++) newArray[i] = newArray[i] + newArray[i - 1];

        for(int i = m_size - 1; i >= 0; i--)
        {
            finalArray[newArray[(m_array[i] / position) % 10] - 1] = m_array[i];
            newArray[(m_array[i] / position) % 10]--;
        }

        for(int i = 0; i < m_size; i++) m_array[i] = finalArray[i];

        delete[] newArray;
        delete[] finalArray;
    }


// Sort Functions
public:
    // Bubble Sort
    void bubbleSort()
    {
        bool isEnd;

	    for (int i = 0; i < m_size; i++)
        {
            isEnd = true;
		    for (int j = 1; j < m_size - i; j++)
            {
			    if (m_array[j - 1] > m_array[j])
                {
                    swap(m_array[j - 1], m_array[j]);
                    isEnd = false;
                }
            }
        }
        if (isEnd) return;
    }

    // Selection Sort
    void selectionSort()
    {
	    int minIndex;

	    for (int i = 0; i < m_size; i++)
    	{
	    	minIndex = i;
		
		    for (int j = i + 1; j < m_size; j++)
            {
			    if (m_array[minIndex] > m_array[j])
				    minIndex = j;
            }

    		swap(m_array[minIndex], m_array[i]);
	    }
    }

    // Insertion Sort
    void insertionSort()
    {
	    int temp, j;

	    for (int i = 1; i < m_size; i++)
    	{
	    	temp = m_array[i];
		    j = i - 1;

	        while (j >= 0 && temp < m_array[j])
		    {
			    m_array[j + 1] = m_array[j];
			    j--;
		    }

	    	m_array[j + 1] = temp;
	    }

    }

    // Merge Sort
    void mergeSort(int left, int right)
    {
	    if (left < right)
	    {
    		int middle = left + (right - left) / 2;

	    	mergeSort(left, middle);
		    mergeSort(middle + 1, right);

		    merge(left, middle, right);
	    }
    }

    // Quick Sort
    void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(low, high);

            quickSort(low, pivot - 1);
            quickSort(pivot + 1, high);
        }
    }

    // Heap Sort
    void heapSort(int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--) heapify(n, i);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(m_array[0], m_array[i]);
            heapify(i, 0);
        }
    }

    // Counting Sort
    void countingSort() // Range of intergers [0 .. size^2 - 1)
    {
        int *newArray = new int[m_size * m_size - 1];
        int *finalArray = new int[m_size];
        
        for (int i = 0; i < m_size * m_size - 1; i++) newArray[i] = 0;
        for (int i = 0; i < m_size; i++) newArray[m_array[i]]++;

        for (int i = 1; i < m_size * m_size - 1; i++) newArray[i] += newArray[i - 1];

        for (int i = 0; i < m_size; i++)
        {
            finalArray[newArray[m_array[i]] - 1] = m_array[i];
            newArray[m_array[i]]--;
        }

        for (int i = 0; i < m_size; i++) m_array[i] = finalArray[i];
        
        delete [] newArray;
        delete [] finalArray;
    }

    // Bucket Sort
    void bucketSort()
    { 
        std::vector<float> b[m_size]; 
     
        for (int i = 0; i < m_size; i++) 
        { 
            int bi = m_size * m_floatArray[i]; // Index in bucket 
            b[bi].push_back(m_floatArray[i]); 
        } 
     
        for (int i = 0; i < m_size; i++) 
            sort(b[i].begin(), b[i].end()); 
    
        int index = 0; 
        for (int i = 0; i < m_size; i++) 
            for (int j = 0; j < b[i].size(); j++) 
                m_floatArray[index++] = b[i][j]; 

    } 

    // Radix Sort
    void radixSort()
    {
        int maxLength = 1, tmp;
        tmp = getMax();

        while (tmp > 0)
        {
            tmp /= 10;
            maxLength *= 10;
        }

        for (int position = 1; position < maxLength; position *= 10)
            sortByPosition(position);
    }

    // Function assigns size of the array to m_size
    void setSize(int size)
    {
        m_size = size;
    }

    // Function assigns array to m_array
    void setArray(int *array)
    {
        m_array = array;
    }

    // Function assigns array to m_floatArray
    void setFloatArray(float *array)
    {
        m_floatArray = array;
    }

    // Function prints array
    void printArray()
    {
        for (int i = 0; i < m_size; i++) std::cout << m_array[i] << " ";
        std::cout << std::endl;
    }

    // Function prints float array
    void printFloatArray()
    {
        for (int i = 0; i < m_size; i++) std::cout << m_floatArray[i] << " ";
        std::cout << std::endl;
    }
};

// Function to run a program
void runSort()
{
    int size;
    int *array;
    Sort sort;

    std::cout << "Bubble Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.bubbleSort();
    sort.printArray();

    delete [] array;

    std::cout << "Selection Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.selectionSort();
    sort.printArray();

    delete [] array;

    std::cout << "Insertion Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.insertionSort();
    sort.printArray();

    delete [] array;

    std::cout << "Merge Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.mergeSort(0, size - 1);
    sort.printArray();

    delete [] array;

    std::cout << "Quick Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.quickSort(0, size - 1);
    sort.printArray();

    delete [] array;

    std::cout << "Heap Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.heapSort(size);
    sort.printArray();

    delete [] array;

    std::cout << "Counting Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.countingSort();  
    sort.printArray();

    delete [] array;

    std::cout << "Bucket Sort: " << std::endl;
    std::cin >> size;

    float *floatArray = new float[size];
    for (int i = 0; i < size; i++) std::cin >> floatArray[i];

    sort.setSize(size);
    sort.setFloatArray(floatArray);
    sort.printFloatArray();
    sort.bucketSort();  
    sort.printFloatArray();

    delete [] floatArray;

    std::cout << "Radix Sort: " << std::endl;
    std::cin >> size;

    array = new int[size];
    for (int i = 0; i < size; i++) std::cin >> array[i];

    sort.setSize(size);
    sort.setArray(array);
    sort.printArray();
    sort.radixSort();  
    sort.printArray();

    delete [] array;
}



int main()
{
    runSort();

    return 0;
}