class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        queue<string> q;
        q.push("1");
        q.push("0");
        set<string> s;
        for(auto x : nums) s.insert(x);
        while(q.size()){
            auto t = q.front();
            q.pop();
            if(t.size()==n){
                if(s.count(t)==false) return t;
            }
            if(t.size()<n){
                q.push(t+"1");
                q.push(t+"0");
            }
        }
        return "";
    }
};