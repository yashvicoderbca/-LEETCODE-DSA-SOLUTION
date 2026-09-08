# include <vector>
# include <unordered_map>
# include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freqMap;
        for(int num :arr){
            freqMap[num]++;
        }
        unordered_set<int> freqSet;
        for(auto pair: freqMap){
            int count = pair.second;
            if (freqSet.find(count)!= freqSet.end()){
                return false;
            }
            freqSet.insert(count);
        }
        return true;
    }
};