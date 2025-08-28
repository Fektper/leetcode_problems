#include <vector>
#include <stdio.h>
#include <limits.h>

using namespace std;

double simpleMedian(vector<int>& nums){
    int n = nums.size();

    if (n%2 == 1){
        return nums[n/2];
    }
    else {
        return ((double)nums[(n-1) / 2] + (double)nums[n/2]) / 2;
    }
}

double kLessMean(vector<int>& nums, int k){
    int n = nums.size();
    int total = n + k;
    if (total % 2 == 1){
        return nums[total / 2 - k];
    }

    int i1 = (total - 1) / 2 - k;
    int i2 = (total / 2) - k;

    return ((double)(nums[i1] + nums[i2])) / 2.0;
}

double middleTwoMedian(int a1, int a2, int b1, int b2){
    return ((double)(std::min(a2, b2) + std::max(a1, b1))) / 2.0;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Not the optimal O(log(n+m)) solution, but O(n+m). Shoudl still be fast enough
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0){
            return simpleMedian(nums2);
        }
        if (m == 0){
            return simpleMedian(nums1);
        }
         // Both arrays have atleast 1 element
        int total = n+m;
        int stop = total / 2;

        int i = 0; int j = 0;
        while(i+j < stop){
            if (i == n){
                return kLessMean(nums2, n);
            }
            if (j == m){
                return kLessMean(nums1, m);
            }
            if (nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        // Either both i and j are valid, or one of them is n or m
        if (total % 2 == 1){
            if (i == n){
                return nums2[j];
            } else if (j == m){
                return nums1[i];
            } else{
                return std::min(nums1[i], nums2[j]);
            }
        }
        else {
            if (i == n){
                if (j == 0){
                    return ((double)(nums1[i-1] + nums2[0])) / 2.0;
                }
                return middleTwoMedian(nums1[i-1], INT_MAX, nums2[j-1], nums2[j]);
            }
            else if (j == m){
                if (i == 0){
                    return ((double)(nums1[0] + nums2[j-1])) / 2.0;
                }
                return middleTwoMedian(nums1[i-1], nums1[i], nums2[j-1], INT_MAX);
            } else{
                if (i == 0){
                    return middleTwoMedian(INT_MIN, nums1[i], nums2[j-1], nums2[j]);
                }
                else if (j == 0){
                    return middleTwoMedian(nums1[i-1], nums1[i], INT_MIN, nums2[j]);
                }
                else {
                    return middleTwoMedian(nums1[i-1], nums1[i], nums2[j-1], nums2[j]);
                }
            }
        }
        return 0; // Never reachable
    }
};


int main(){
    vector<int> list1 = {1, 3, 4};
    vector<int> list2 = {2};

    double target_result = 2.5;
    Solution solver = Solution();
    double res = solver.findMedianSortedArrays(list1, list2);

    if (target_result == res){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed! Expected %f but got %f\n", target_result, res);
    }
}