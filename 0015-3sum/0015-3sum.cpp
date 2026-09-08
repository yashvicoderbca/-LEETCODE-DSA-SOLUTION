# include <vector>
# include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // step 1 : sort the array to use the two-pointer technique
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2; i++){
            //optimization: since array is sorted, if the nums[i]>0, sum can never be 0 
            if (nums[i]>0) break;
            // skip duplicates element for the first position 'i'
            if (i>0 && nums[i]== nums[i-1]) continue;
            int j = i+ 1; // left pointer
            int k = n-1; // right pointer 
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0 ){
                    // valid triplet found 
                    result.push_back({nums[i], nums[j],nums[k]});
                    j++;
                    k--;
                    // skip duplicate element for the left pointer 
                    while(j<k && nums[j]==nums[j-1]) j++;
                    // skip duplicate element for the left pointer 
                    while(j<k && nums[k]==nums[k+1]) k--;
                }else if (sum<0){
                    j++; // sum is too small, move left pointer rightwards to increase the sum 
                }
                else{
                    k--; // sum id too large move right pointer leftwards to decrease the sum 
                }
            }
        }
        return result;
    }
};