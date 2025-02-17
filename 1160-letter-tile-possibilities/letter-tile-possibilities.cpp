class Solution {
public:
    set<string> s;
    void rec(int i , string &K,string &t){
        if(i==t.size()){
            if(K.size()) s.insert(K);
            return;
        }
        K+=t[i];
        rec(i+1,K,t);
        K.pop_back();
        rec(i+1,K,t);

    }
    int numTilePossibilities(string tiles) {
        string temp= "";
        sort(tiles.begin(),tiles.end());
        do{
            temp="";
            rec(0,temp,tiles);
        }
        while(next_permutation(tiles.begin(),tiles.end()));
        return s.size();
    }
};