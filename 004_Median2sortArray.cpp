#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
    double findMedianSortedArrays(const vector<int>&nums1, const vector<int> &nums2)
    {
        vector <int> merge_nums;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merge_nums));
        sort(merge_nums.begin(), merge_nums.end());
        int n = merge_nums.size();
        if (n % 2 != 0){
            return  merge_nums[n/2];
        }
        else{
            return  (merge_nums[n/2-1] + merge_nums[n/2]) / 2.0;
        }
        return 0;
    }

};

void vec_output(vector <int> vec_input)
{
    
    for (int i = 0; i < vec_input.size(); i++)
    {
        cout << vec_input[i] << ' ';
    }
    cout << endl;
}

int main(){
    // vector <int> v1{1,1,1,1,1,1,1,1,1,1,4,4};
    // vector <int> v2{1,3,4,4,4,4,4,4,4,4,4};
    // vector <int> v3;
    //v3.resize(v1.size() + v2.size());
    
    // merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    // cout << v3.size() << endl;
    // sort(v3.begin(), v3.end());
    // vec_output(v3);

    /*whaz different between set_union and merge*/

    Solution Sol1;
    cout << Sol1.findMedianSortedArrays({1,3},{2}) << endl;
    cout << Sol1.findMedianSortedArrays({0,0},{0,0}) << endl;
    cout << Sol1.findMedianSortedArrays({1,2},{3,4}) << endl;
    cout << Sol1.findMedianSortedArrays({},{1}) << endl;
    cout << Sol1.findMedianSortedArrays({2},{}) << endl;
    cout << Sol1.findMedianSortedArrays({1,1,1,1,1,1,1,1,1,1,4,4},{1,3,4,4,4,4,4,4,4,4,4})<< endl;

    return 0;
}

