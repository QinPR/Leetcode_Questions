// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        int first_length = nums1.size();
        int second_length = nums2.size();
        int i = 0;    // the index of first array;
        int j = 0;    // the index of the second array
        vector<int> merge_arr (first_length+second_length);
        for (int k = 0; k < first_length + second_length; k++){
            if (i == first_length){
                merge_arr[k] = (nums2[j]);
                j += 1;
                continue;
            }
            if (j == second_length){
                merge_arr[k] = (nums1[i]);
                i += 1;
                continue;
            }
            if (nums1[i] <= nums2[j]){
                merge_arr[k] = (nums1[i]);
                i += 1;
            }else{
                merge_arr[k] = (nums2[j]);
                j += 1;
            }
        }
        if ((first_length + second_length) % 2 == 1){
            median = merge_arr[(first_length + second_length-1)/2];
        }else{
            int intermedia = (merge_arr[(first_length + second_length-2)/2] + merge_arr[(first_length + second_length)/2]);
            median = (double)intermedia/2;
        }
        return median;
    }
};
