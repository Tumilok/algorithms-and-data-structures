# Sorting-Algoritms
With the help of this repository, I'm trying to demonstrate my knowledge of different sorting algorithms and the ability to implement it in my way. Here you can find implementations of the following sorting algorithms on both arrays and linked lists:

* Sorting algorithms on arrays (_ArraySorts.cpp_):
    1. Bubble Sort
    2. Selection Sort
    3. Insertion Sort
    4. Merge Sort
    5. Quick Sort
    6. Heap Sort
    7. Counting Sort
    8. Bucket Sort
    9. Radix Sort 
* Sorting algorithms on linked list (_ListSorts.cpp_):
    1. Bubble Sort
    2. Selection Sort
    3. Insertion Sort
    4. Merge Sort
    5. Quick Sort


Group of _O(N^2)_ time complexity and _O(1)_ space complexity sorting algorithms:

* **Bubble Sort** is implemented with boolean flag which will the optimistic time complexity _O(N)_, stable
* **Selection Sort** has always time complexity _O(N^2)_, unstable
* **Insertion Sort** is probably the best sorting algorithm among _O(N^2)_ time complexity sorting algorithms, as it's time complexity can decrease down to _O(N)_ in case if array is sorted or contains the same numbers.

Group of _O(N*logN)_ time complexity soring algorithms:

* **Merge Sort** is the most reliable among "quick" sorting algorithms, as it's time complexity will be always _O(N*logN)_ and it's stable, but Merge sort has the biggest space complexity _O(N)_.
* **Quick Sort** has in most cases complexity _O(N*logN)_, but in the worst cases (when array or list would be sorted) time complexity increases up to _O(N^2)_, on the other hand, space complexity is _O(log*N)_ and it's unstable.
* **Heap Sort** has time complexity _O(N*logN)_ and the smallest space complexity among "quick" sorting algorithms _O(1)_, but it's unstable.

Other sorting algorithms:

* **Counting Sort** has time complexity _O(N + K)_, where K is a range of numbers contained in array, space complexity is _O(N + K)_ and it's stable.
* **Bucket Sort** is using for sorting fractional numbers. Time complexity is _O(N)_, but it can increase in worst cases, space complexity _O(K)_, where K is a range of numbers, stable.
* **Radix Sort** has time complexity _O(D*(N + K))_, where K is a range of numbers and D is an amount of numbers (positions). Space complexity is _O(N)_ and it's stable
