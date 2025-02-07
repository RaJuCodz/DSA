class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    
        unordered_map<int,int> color;
        unordered_map<int,int> curr;
        vector<int> ans;
        for( auto  q : queries){
            if(color[q[0]]>0){
                int col = color[q[0]];
                curr[col]--;
                if(curr[col]==0){
                    curr.erase(col);
                }
            }
            color[q[0]]=q[1];
            curr[q[1]]++;
            
            ans.push_back(curr.size());
        }
        return ans;
        
    }
};