class Solution {
public:
    set<string> st;
    vector<string> ans;
    void rec(string cur,string s){
        if(s.empty()){
            cur.pop_back();
            ans.push_back(cur); 
        }
        for(int i =1;i<=s.size();i++){
            if(st.count(s.substr(0,i))){
                string nt = cur + s.substr(0, i) + " ";
                rec(nt,s.substr(i));
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& w) {
        for(auto x : w){
            st.insert(x);
        }
        string z ="";
        rec(z,s);
        return ans;
    }
};