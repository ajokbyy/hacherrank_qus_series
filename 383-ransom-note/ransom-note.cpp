class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
          vector<int> freq(26, 0);

        // Count characters in magazine
        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        // Check characters required for ransomNote
        for (char ch : ransomNote) {
            if (freq[ch - 'a'] == 0) {
                return false; // character not available
            }
            freq[ch - 'a']--; // use character
        }

        return true;
    }
};