

#include <stdlib.h>

void merge(int arr[], size_t low, size_t mid, size_t high)
{
    size_t size_arr_1 = mid - low + 1;
    size_t size_arr_2 = high - mid;

    int arr_1[size_arr_1];
    int arr_2[size_arr_2];

    size_t j = low;
    for (size_t i = 0; i < size_arr_1; ++i)
    {
        arr_1[i] = arr[j++];
    }

    for (size_t i = 0; i < size_arr_2; ++i)
    {
        arr_2[i] = arr[j++];
    }

    size_t i = 0;
    j = 0;
    size_t k = low;
    while (i < size_arr_1 && j < size_arr_2)
    {
        if (arr_1[i] < arr_2[j])
            arr[k++] = arr_1[i++];
        else
            arr[k++] = arr_2[j++];
    }

    while (i < size_arr_1)
        arr[k++] = arr_1[i++];

    while (j < size_arr_2)
        arr[k++] = arr_2[j++];
}

void merge_sort(int arr[], size_t low, size_t high)
{
    size_t mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {10, 23, 4, 12, 5, 1};
    size_t highest_element_index = sizeof(arr) / sizeof(arr[0]) - 1;
    merge_sort(arr, 0, highest_element_index);
    return 0;
}