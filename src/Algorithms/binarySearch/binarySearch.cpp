
#include <iostream>

int binary_search(int s[], int key, int low, int high)
{

    int middle;

    /* index of middle element */

    if (low > high)
    {
        return high;
    }

    /* key not found */
    middle = (low + high) / 2;

    if (s[middle] > key)
    {
        return (binary_search(s, key, low, middle - 1));
    }
    else
    {
        return (binary_search(s, key, middle + 1, high));
    }
}

int main()
{
    int arr[] = {0, 1, 1, 1, 1, 1, 1, 1, 2};
    int indexHigh = binary_search(arr, 1, 0, 9);
    std::cout << indexHigh;
    return 0;
}