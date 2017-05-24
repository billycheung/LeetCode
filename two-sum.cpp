#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* https://leetcode.com/problems/two-sum

Sample Input:
4 9
2 7 11 15
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result(2);
        for (int i=0; i<nums.size(); i++){
            int num = nums[i];
            if (m.find(target-num) != m.end()){
                result[0] = m[target-num];
                result[1] = i;
                break;
            } else{
                m[num] = i;
            }
        }
        return result;
    }
} solution;

int main() {
    int n, target, tmp;
    cin >> n >> target;
    vector<int> nums;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        nums.push_back(tmp);
    }
    vector<int> result = solution.twoSum(nums, target);
    for (auto e:result){
        cout << e << endl;
    }
    return 0;
}
