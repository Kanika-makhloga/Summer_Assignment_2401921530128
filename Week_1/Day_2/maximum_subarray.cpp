class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int PrevSum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
              if((PrevSum + nums[i]) > nums[i])
              {
                   PrevSum = PrevSum + nums[i];
              }
              else
              {
                  PrevSum = nums[i];
              }

           maxsum = max(maxsum, PrevSum);
        }

       return maxsum;
    }
};
