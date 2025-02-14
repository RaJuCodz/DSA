class ProductOfNumbers {
public:
    bool hasZero = false;
    vector<int> a;
    int ans;
    int ind;
    ProductOfNumbers() {
        ans=1; ind=1;
        a.clear();
        a.reserve(40001);
        a.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            a.clear();
            a.push_back(1);
            return;
        }
        a.push_back(a.back()*(num));
    }
    
    int getProduct(int k) {
        if(a.size()==1) return 0;
        int l = a.size()-k-1;
        if(l<=-1) return 0;
        // cout<<a.size()<<" ";
        return a.back()/a[l];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */