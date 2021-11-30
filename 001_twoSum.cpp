#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(const vector<int>&nums, int target)
    {
        //nums.push_back(5);
        map <int, int> hash_map;
        vector <int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int t = target - nums[i];
            if(hash_map.find(t) == hash_map.end())
            {
                hash_map[nums[i]] = i;
            }
            else{
                res.push_back(hash_map[t]);
                res.push_back(i);
                return res;

            }
        }   
        return res;     
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
    Solution Sol1;
   // vector <int> v1 {1,2,3};
    //Sol1.twoSum(v1, 8);
    
    vec_output(Sol1.twoSum({2,7,11,15}, 9));
    vec_output(Sol1.twoSum({3,2,4}, 6));
    vec_output(Sol1.twoSum({3,3}, 6));
    return 0;
}
