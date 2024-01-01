#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
void mergesort(vector<int>& nums)
{
    int size = nums.size();

    if (size == 1)
        return;
    vector<int> left(nums.begin(), nums.begin() + size / 2);
    vector<int> right(nums.begin() + size / 2, nums.end());
    mergesort(left);
    mergesort(right);
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            nums[k++] = left[i++];
        }
        else
        {
            nums[k++] = right[j++];
        }
    }
    while (i < left.size())
    {
        nums[k++] = left[i++];
    }
    while (j < right.size())
    {
        nums[k++] = right[j++];
    }
}

int partition(vector<int>& nums, int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    int smallPos = low - 1;
    int temp = nums[random];
    nums[random] = nums[high];
    nums[high] = temp;
    int pivot = nums[high];
    if (low < high)
    {
        for (int i = low; i <= high; ++i)
        {
            if (nums[i] < pivot)
            {
                smallPos++;
                int temp = nums[i];
                nums[i] = nums[smallPos];
                nums[smallPos] = temp;
            }
        }
    }
    swap(nums[++smallPos], nums[high]);
    return smallPos;
}

void quicksort(vector<int>& nums, int low, int high)
{
    if (low < high)
    {
        int newLow = partition(nums, low, high);
        quicksort(nums, low, newLow);
        quicksort(nums, newLow + 1, high);
    }
}

