class Solution {
public:
    int qa(vector<int>& nums1, vector<int>& nums2) {
        int x=0,s=0,a=0;
        for(int i=0;i<nums1.size();++i) {
            x+=nums1[i];
            int v=nums2[i]-nums1[i];
            s=max(s,0)+v;
            a=max(a,s);
        }
        return x+a;
    }
    int maximumsSplicedArray(vector<int>& num1, vector<int>& num2) {
        return max(qa(num1,num2),qa(num2,num1));
    }
};