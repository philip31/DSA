
#include <vector>
#include <unordered_map>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    size_t maxIndex1 = m - 1;
    size_t maxIndex2 = n - 1;
    size_t maxSumIndex = m + n - 1;
    while (maxSumIndex > -1 && maxIndex1 > -1 && maxIndex2 > -1)
    {
        if (nums1.at(maxIndex1) < nums2.at(maxIndex2))
            nums1.at(maxSumIndex--) = nums2.at(maxIndex2--);
        else
            nums1.at(maxSumIndex--) = nums1.at(maxIndex1--);
    }
}

int main()
{
    // nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    return 0;
}