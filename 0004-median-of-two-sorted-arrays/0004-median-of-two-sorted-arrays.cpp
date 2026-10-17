class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {

                if ((m + n) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;

                return max(left1, left2);
            }

            else if (left1 > right2)
                high = cut1 - 1;

            else
                low = cut1 + 1;
        }

        return 0.0;
    }
};

/* class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        if(n % 2 != 0)
            return nums1[n/2];
        else
            return (nums1[n/2 - 1]+nums1[n/2])/2.0;
    }
};

*/ 
/* class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int nums3[m+n];
        double ans = 0.0;
        for(int i =0;i<m;i++){
            nums3[i] = nums1[i];
        }
        for(int i =0;i<n;i++){
            nums3[i+m] = nums2[i];
        }
        sort(nums3 , nums3 + (m+n));
        if (((m+n) % 2) != 0){
            ans = double(nums3[((m+n)+1 - 1)/2]);
        } else {
            ans = (nums3[(m+n)/2 - 1] + nums3[(m+n)/2 + 1 - 1])/2.0;
        }
        return ans;
    }
};  */ 