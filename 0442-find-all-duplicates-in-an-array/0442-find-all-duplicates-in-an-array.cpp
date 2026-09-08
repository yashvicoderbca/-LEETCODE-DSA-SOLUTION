# include <vector>
# include <cmath>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i<nums.size(); i++){
            // get the corresponding 0-based index for the current number
            int index = abs(nums[i]) - 1;
            // if the element at this index is already negative it means we have seen this number before
            if(nums[index]<0){
                result.push_back(abs(nums[i]));
            } else{
                // first time visiting this number: mark the element at 'index' as negative
                nums[index] = -nums[index];
            }
        }
        return result;
    }
};