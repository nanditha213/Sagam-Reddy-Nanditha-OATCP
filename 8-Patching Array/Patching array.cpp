#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int minPatches(vector<int>& nums, int target) {
    int size = nums.size();
    long long maxLimit = 0;
    int patchCount = 0;
    
    for (int i = 0; i < size; i++) {
        while (nums[i] > (maxLimit + 1)) {
            maxLimit = 2 * maxLimit + 1;
            patchCount++;
            if (maxLimit >= target) {
                return patchCount;
            }
        }
        maxLimit += nums[i];
        if (maxLimit >= target) {
            return patchCount;
        }
    }
    
    while (maxLimit < target) {
        maxLimit = 2 * maxLimit + 1;
        patchCount++;
    }
    
    return patchCount;
}
int main() {
   
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n') {
            cin.ignore(); // Ignore the newline character
            break;
        }
    }

    int n;
    cin >> n;
    int result = minPatches(nums, n);
    cout << result;

}
