//Link : https://leetcode.com/problems/max-dot-product-of-two-subsequences/


class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int arr[n1][n2];
        arr[0][0]=nums1[0]*nums2[0];
        //here we fill the first column, we try to store the max of current element
        //of the num1 and first element of num2.
        for(int i=1;i<n1;i++)
            arr[i][0]=max(arr[i-1][0],nums1[i]*nums2[0]);
        //here we fill the first column, we try to store the max of current element
        //of the num2 and first element of num1.
        for(int i=1;i<n2;i++)
            arr[0][i]=max(arr[0][i-1],nums1[0]*nums2[i]);
        for(int i=1;i<n1;i++)
        {
            for(int j=1;j<n2;j++)
            {
                //case 1: pick arr[i-1][j] skip ith of nums2 for consideration of set
                //case 2: pick arr[i][j-1] skip jth of nums1 for consideration of set
                //case 1: we are considering ith of nums2 and jth of nums1 and we check
                //if arr[i-1][j-1] is negative or not. if negative it we drop it and
                //do not consider previous sets.
                arr[i][j]=max(max(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1]>0?arr[i-1][j-1]+(nums1[i]*nums2[j]):(nums1[i]*nums2[j]));
            }
        }

        return arr[n1-1][n2-1];
    }
};
