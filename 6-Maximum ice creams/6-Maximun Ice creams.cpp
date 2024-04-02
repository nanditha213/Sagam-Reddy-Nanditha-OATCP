class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       int arr[100001] = {0};
       for(int i=0; i<costs.size(); i++){
        arr[costs[i]]++;
       }

       int cnt = 0;
       for(int i=1; i<=100000; i++){
        if(arr[i]){
            long long curr = (long long)arr[i]*i;

            if(curr<=coins){
                cnt+=arr[i];
                coins-=curr;
            }
            else{
                cnt+=(coins/i);
                break;
            }
        }
       }

       return cnt;

        
    }
};
