class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> t; int m=part.size();
        reverse(part.begin(),part.end());
        for(auto x : s){
            int j =0;
            t.push(x);
            string Z ="";
            while(t.size() && t.top()==part[j] && j<m){
                j++;
                Z+=t.top();
                t.pop();
            }
            if(j==m){
                continue;
            }
            else{
                reverse(Z.begin(),Z.end());
                for(auto y : Z){
                    t.push(y);
                }               
            }
        }
        string ans ="";
        while(t.size()){
            ans+=t.top();
            t.pop();
        }
         reverse(ans.begin(),ans.end());
         return ans;
        
    }
};