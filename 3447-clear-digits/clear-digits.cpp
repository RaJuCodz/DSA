class Solution {
public:
    string clearDigits(string s) {
        string ans ="";
        stack<char> t;
        for(auto x : s){
            if(x>='0' && x<='9'){
                t.pop();
            }
            else t.push(x);
        }
        while(t.size()){
            ans+=t.top();
            t.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};