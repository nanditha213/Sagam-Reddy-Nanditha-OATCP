class Solution {

    static bool compare(string a, string b){
        if(a+b > b+a){
            return true;
        }
        else{
            return false;
        }
        // return a+b > b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>v;
        for(int i=0; i<n; i++){
            string temp = to_string(nums[i]);
            v.push_back(temp);

        }
        
        
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum==0){
            return "0";
        }
        else{
            sort(v.begin(), v.end(), compare);
            string fin="";
            for(int i=0; i<n; i++){
                fin+=v[i];
            }
            return fin;

        }
        
    }
};
