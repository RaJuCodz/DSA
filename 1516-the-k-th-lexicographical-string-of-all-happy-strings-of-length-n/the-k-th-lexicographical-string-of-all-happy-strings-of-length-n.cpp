class Solution {
public:
vector<string> s;
int n; int k;
void rec(int i , string &cur){
    if(s.size()>=k) return;
    if(i==n) {
        s.push_back(cur);
        return;
    }
    if(i==0){
        string z ="a";
        rec(i+1,z);
        
         z ="b";
          rec(i+1,z);
         z ="c";
          rec(i+1,z);
    }
    else{
        if(cur.back()=='a'){
            string ns = cur+"b";
            rec(i+1,ns);
             string nf = cur+"c";
            rec(i+1,nf);
        }
        else if(cur.back()=='b'){
            string ns = cur+"a";
            rec(i+1,ns);
             string nf = cur+"c";
            rec(i+1,nf);
        }
        else{
             string nf = cur+"a";
            rec(i+1,nf);
            string ns = cur+"b";
            rec(i+1,ns);
            
        }
    }
}
    string getHappyString(int N, int K) {
        n=N;
        k=K;
        string empty = "";
        rec(0,empty);
        sort(s.begin(),s.end());
        // for(auto x : s) cout<<x<<" ";
        return s.size()<k?"":s[k-1];
    }
};