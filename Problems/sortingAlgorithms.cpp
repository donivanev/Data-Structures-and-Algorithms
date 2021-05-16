#include <iostream>
#include <vector>

void selectionSort(int arr[], unsigned size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        int min = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int helper = arr[min];
            arr[min] = arr[i];
            arr[i] = helper;
        }
    }
}

void bubbleSort(int arr[], unsigned size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (size_t j = 1; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                if (j != j - 1)
                {
                    int helper = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = helper;
                }

                swapped = true;
            }
        }

        if (!swapped) return;
    }
}

void insertionSort(int arr[], unsigned size)
{
    for (size_t i = 1; i < size; i++)
    {
        int j = i, key = arr[i];

        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            --j;
        }
        
        arr[j] = key;
    }
}

void heapify(int arr[], int n, int root)
{
    int largest = root, left = root * 2 + 1, right = root * 2 + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        std::swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void mergeSorted(int arr[], int start1, int end1, int start2, int end2)
{
    std::vector<int> help;
    int index1 = start1, index2 = start2;

    while (index1 <= end1 && index2 <= end2)
    {
        if (arr[index1] < arr[index2])
        {
            help.push_back(arr[index1]);
            index1++;
        }
        else
        {
            help.push_back(arr[index2]);
            index2++;
        }
    }

    while (index1 <= end1)
    {
        help.push_back(arr[index1]);
        index1++;
    }

    while (index2 <= end2)
    {
        help.push_back(arr[index2]);
        index2++;
    }
    
    for (int i = start1; i <= end2; i++)
    {
        arr[i] = help[i - start1];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (end - start < 1) return;

    int middle = (end - start) / 2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);

    mergeSorted(arr, start, middle, middle + 1, end);
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start], i = start, j = end;

    while (true)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        
        while (arr[j] > pivot)
        {
            j--;
        }
    
        if (i >= j)
        {
            return j;
        }

        std::swap(arr[i], arr[j]);   
    }
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, end);
    }
}

int main()
{
    int arr[] = { 5, 1, 8, 2, 3 };
    //selectionSort(arr, 5);
    bubbleSort(arr, 5);
    //insertionSort(arr, 5);
    //heapSort(arr, 5);
    //mergeSort(arr, 0, 5);
    //quickSort(arr, 0, 5);

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}