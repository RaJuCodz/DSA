class Solution {
public:
    string smallestNumber(string p) {
        string ans ="123456789"; int n=p.size();
       do{
           bool ok = true;
            for(int i =0;i<n;i++){
                int x = ans[i]-'0';
                int y = ans[i+1]-'0';
                if(p[i]=='I'){
                    if(x>y) ok = false;
                }
                else{
                    if(y>x) ok = false;
                }
            }
           if(ok) {
               string m ="";
               for(int i =0;i<=n;i++){
                   m+=ans[i];
               }
               return m;
           }
       }
        while(next_permutation(ans.begin(),ans.end()));
        return ans;
    }
};