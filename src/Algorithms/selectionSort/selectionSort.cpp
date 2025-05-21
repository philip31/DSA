#include <utility>
using namespace std;

void selection_sort(int s[], int n)
{
    int i, j; /* counters */
    int min;  /* index of minimum */
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (s[j] < s[min])
            {
                min = j;
            }
        }
        swap(s[i], s[min]);
    }
}

int main()
{
    int arr[] = {10, 5, 1, 7, -2};
    selection_sort(arr, 5);
}