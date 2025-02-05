class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt =0;
        int n =s2.size();
        if(s1.size()!=n)return false;
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(s1[i]!=s2[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()%2 || ans.size()>2) return false;
        if(ans.size()==0) return true;
        return (s1[ans[0]]== s2[ans[1]]) && (s1[ans[1]]==s2[ans[0]]);
    }
};