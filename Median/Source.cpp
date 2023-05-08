#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Пусть nums1 всегда будет меньшим массивом для упрощения кода
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int imin = 0, imax = m;
    int half_len = (m + n + 1) / 2;

    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;

        if (i < m && nums2[j - 1] > nums1[i]) {
            imin = i + 1;
        }
        else if (i > 0 && nums1[i - 1] > nums2[j]) {
            imax = i - 1;
        }
        else {
            int max_left = 0;
            if (i == 0) {
                max_left = nums2[j - 1];
            }
            else if (j == 0) {
                max_left = nums1[i - 1];
            }
            else {
                max_left = max(nums1[i - 1], nums2[j - 1]);
            }

            if ((m + n) % 2 == 1) {
                return max_left;
            }

            int min_right = 0;
            if (i == m) {
                min_right = nums2[j];
            }
            else if (j == n) {
                min_right = nums1[i];
            }
            else {
                min_right = min(nums1[i], nums2[j]);
            }

            return (max_left + min_right) / 2.0;
        }
    }

    return 0.0;
}

int main() {
    vector<int> nums1{ 1, 3 };
    vector<int> nums2{ 2 };
    vector<int> nums3{ 1, 2 };
    vector<int> nums4{ 3, 4 };

    // Тест 1: nums1 + nums2 = [1,2,3] => 2 
    double median1 = findMedianSortedArrays(nums1, nums2);
    cout << "Median of nums1 + nums2: " << median1 << endl;

    // Тест 2: nums3 + nums4 = [1,2,3,4] => 3 и 4 => (+3)/2
    double median2 = findMedianSortedArrays(nums3, nums4);
    cout << "Median of nums3 + nums4: " << median2 << endl;

    return 0;
}
