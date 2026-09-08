# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high= nums.size()-1;
        while(mid<=high){
            if (nums[mid]==0){
                // swap 0 to the low zone and increment both low and mid pointers
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]== 1){
                // 1 is in the correct relative zone, move mid pointer forward
                mid++;
            }
            else {
                // nums[mid] == 2
                // swap 2 to the high zone and decrement high pointer
                swap(nums[mid],nums[high]);
                high--;
                // note: do not increment mid here because the newly swapped element at mid from high still needs to be proccessed 
            }
        }
    }
};