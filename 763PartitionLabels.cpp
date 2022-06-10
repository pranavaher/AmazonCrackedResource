class Solution {
public:
    // O(n^2)+O(n) in worst case
    vector<int> partitionLabels(string s) {
        // storing the last index of each char in map
        unordered_map<char,int>mp;        
        for(int i=0;i<s.size();i++){ //O(n)
            char c = s[i];
            mp[c]=i;
        }
        
        vector<int> ans;
        int prev=-1;
        int maxIdx = 0;
        
        
        for(int i=0;i<s.size();i++){
            // getting the last occurance of each char
            maxIdx = max(maxIdx,mp[s[i]]); //O(n) for finding char in map
            // if current index is equal to it then pushing it to the answer 
            // and updating prev.  
            if(maxIdx==i){
                ans.push_back(maxIdx-prev);
                prev=maxIdx;
            }                
        }
        return ans;
    }
};