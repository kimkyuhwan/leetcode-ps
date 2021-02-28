// Median of Two Sorted Arrays
class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> merged;
        int n = nums1.size();
        int m = nums2.size();
        int j = 0;
        for(int i=0;i<n;){
            if(j < m && nums2[j] < nums1[i]){
                merged.push_back(nums2[j]);
                j++;
            }
            else{
                merged.push_back(nums1[i]);
                i++;
            }
        }
        for(int i=j;i<m;i++){
            merged.push_back(nums2[i]);
        }
        return merged;
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int size = n+m;
        vector<int> merged;
        if(n < m) merged = merge(nums1, nums2);
        else merged = merge(nums2, nums1);
    
        double ret = 0.0;
        if(size > 0){
            int mid = (size/2);
            if(size%2 == 0) ret = (merged[mid-1] + merged[mid])/2.0;
            else ret = merged[mid];
        }
        return ret;
        
    }
};