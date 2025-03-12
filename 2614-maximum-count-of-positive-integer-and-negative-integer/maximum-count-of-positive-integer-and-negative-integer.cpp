class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos =-1; int neg =-1;
        int n=nums.size();
        int L =0;
        int R = n-1;
        while(L<=R){
             int mid = (L+R)/2;
            if(nums[mid]<=0){
                L=mid+1;
            }
            else {
                R=mid-1;
                pos=mid;
            }
        }
        L=0;R=n-1;
        while(L<=R){
            int mid = (L+R)/2;
            if(nums[mid]>=0){
                R=mid-1;
            }
            else {
                L=mid+1;
                neg=mid;
            }
        }
        if(pos==-1 && neg==-1) return 0;
        if(pos==-1) return neg+1;
        if(neg==-1) return n-pos;
        return max(n-max(0,pos),max(0,neg)+1);
    }
};