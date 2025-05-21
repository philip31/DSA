#include <utility>

using namespace std;

void insertion_sort(int s[], int n)
{
    int i, j; /* counters */
    int min;  /* index of minimum */
    for (i = 1; i < n; i++)
    {
        j = i;
        while ((j > 0) && (s[j] < s[j - 1]))
        {
            swap(s[j], s[j - 1]);
            j = j - 1;
        }
    }
}

int main()
{
    int arr[] = {10, 5, 1, 7, -2};
    insertion_sort(arr, 5);
}