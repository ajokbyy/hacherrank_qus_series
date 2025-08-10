-----------------------------------------------------***-------------------------------------------------------------
  869. Reordered Power of 2
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
 

Constraints:

1 <= n <= 109

  --------------------------------------------------------***--------------------------------------------------------------------------
  class Solution {
public:
    // Helper: Return digit count as a vector of length 10
    vector<int> countDigits(int n) {
        vector<int> count(10, 0);
        while (n) {
            count[n % 10]++;
            n /= 10;
        }
        return count;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> original = countDigits(n);
        // Check powers of 2 up to 10^9 (largest n constraint)
        for (int i = 0; i < 31; ++i) {
            if (original == countDigits(1 << i))
                return true;
        }
        return false;
    }
};




// class Solution {
// public:
//     bool reorderedPowerOf2(int n) {
//         string s = sortDigits(n);

//         for(int i = 0; i<31; i++){
//             int power = 1 << i;
//             if(s == sortDigits(power)){
//                 return true;
//             }
//         }
//         return false;
//     }


//         string sortDigits(int num) {
//         string s = to_string(num);
//         sort(s.begin(), s.end());
//         return s;
//     }
// };better code
------------------------------------------***---------------------------------------------------------------------------------------------------------------
