
1. Subarray Sum Equals K  ( LC 560)

  class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        vector<int>prefix(nums.size()+1 , 0);
        prefix[0]=nums[0];
       for(int i=1;i<nums.size();i++){
          prefix[i] = prefix[i-1] + nums[i];
       }
       unordered_map<int,int>umap;
       for(int i=0;i<nums.size();i++){
        if(prefix[i] == k) 
           cnt++;
        if(umap.find(prefix[i] - k) != umap.end()){
            cnt+=umap[prefix[i]-k];
        }
        umap[prefix[i]]++;
       }
       return cnt;
    }
};
