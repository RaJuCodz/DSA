class NumberContainers {
public:
    unordered_map<int,int> M;
    unordered_map<int,set<int>> Z;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(M.count(index)){
            int X = M[index];
            Z[X].erase(index);
        }
        M[index]=number;
        Z[number].insert(index);
    }
    
    int find(int number) {
        if(Z[number].size()==0) return -1;
        return *Z[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */