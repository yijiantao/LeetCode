/*
 * 所有的排序算法；
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    vector<int> instertSort(vector<int>& arr) {
        // 选择排序（原地排序，稳定）
        for (int _index = 1; _index < arr.size(); ++_index) {
            int value = arr[_index];
            int curIndex = _index - 1;
            for (;curIndex >= 0; --curIndex) {
                if (arr[curIndex] > value) arr[curIndex + 1] = arr[curIndex];
                else break;
            }
            arr[curIndex + 1] = value;
        }
        return arr;
    }
    
    //快速排序（从小到大）
    void quickSort(int left, int right, vector<int>& arr)
    {
        if(left >= right)    // 递归边界条件
            return;
        int i, j, base, temp;
        i = left, j = right;
        base = arr[left];  //取最左边的数为基准数
        while (i < j)
        {
            while (arr[j] >= base && i < j)
                j--;
            while (arr[i] <= base && i < j)
                i++;
            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //基准数归位
        arr[left] = arr[i];
        arr[i] = base;
        quickSort(left, i - 1, arr);//递归左边
        quickSort(i + 1, right, arr);//递归右边
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size() - 1, nums);
        return nums;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {11,45,2,32,89,0};
    // 快排 - 适合大批量数据
    for (int _v: s.sortArray(nums)) cout << _v << " ";
    // 选择排序 - 适合小批量数据
    for (int _v: s.instertSort(nums)) cout << _v << " ";
    return 0;
}
