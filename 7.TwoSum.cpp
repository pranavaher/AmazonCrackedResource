class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int, int> > nums2;
        
        for(int i=0;i<nums.size();i++){
            pair<int, int> temp(nums[i],i);
            nums2.push_back(temp);
        }
        
        sort(nums2.begin(),nums2.end());
        
        int i = 0;
        int j = nums2.size() - 1;
        
        while(i < j){
            if(nums2[i].first+nums2[j].first == target){
                vector <int> ans{nums2[i].second,nums2[j].second};
                return ans;
            }
            else if(nums2[i].first+nums2[j].first > target){
                j--;
            } else{
                i++;
            }
        }
        return {};
    }
};