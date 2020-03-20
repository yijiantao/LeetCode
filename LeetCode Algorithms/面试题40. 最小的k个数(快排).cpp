#include<bits/stdc++.h>

using namespace std;

class Solution {
    int partition(vector<int>& a, int l, int r)
    {
        int i = l;
        int j = r + 1;
        int v = a[l];
        
        while (true) {
            while (a[--j] > v);
            while (i < j && a[++i] < v);
            
            if (i == j)
            {
                break;
            }
            swap(a[i], a[j]);
        }
        
        swap(a[i], a[l]);
        
        return i;
    }

    void quick_sort(vector<int>& a, int l, int r)
    {
        if (l < r) {
            int m = partition(a, l, r);
            quick_sort(a, l, m - 1);
            quick_sort(a, m + 1, r);
        }
    }

public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        vector<int> res;
        quick_sort(arr, 0, arr.size() - 1);
        for (int _index = 0; _index < k; ++_index) res.push_back(arr[_index]);
        for (int _v: res) cout << _v << endl;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {0,0,1,2,4,2,2,3,1,4};
    int k = 8;
    s.getLeastNumbers(arr, k);
    return 0;
}
