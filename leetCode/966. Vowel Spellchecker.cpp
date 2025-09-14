966. Vowel Spellchecker
Solved
Medium
Topics
premium lock icon
Companies
Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
Example 2:

Input: wordlist = ["yellow"], queries = ["YellOw"]
Output: ["yellow"]
 

Constraints:

1 <= wordlist.length, queries.length <= 5000
1 <= wordlist[i].length, queries[i].length <= 7
wordlist[i] and queries[i] consist only of only English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
112,241/184.7K
Acceptance Rate
60.8%
Topics
Array
Hash Table
String
Weekly Contest 117

// --------------------------------------------------------------------------------------------------------------------------------
  class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
      unordered_set<string> words(wordlist.begin(), wordlist.end()); // Rule 1: exact match
        unordered_map<string, string> caseInsensitive; // Rule 2
        unordered_map<string, string> vowelInsensitive; // Rule 3

        // Step 1: Preprocess the wordlist
        for (string w : wordlist) {
            string lower = toLower(w);
            string devowel = devowelString(lower);

            if (!caseInsensitive.count(lower)) {
                caseInsensitive[lower] = w;   // first word wins
            }
            if (!vowelInsensitive.count(devowel)) {
                vowelInsensitive[devowel] = w;
            }
        }

        // Step 2: Answer the queries
        vector<string> result;
        for (string q : queries) {
            if (words.count(q)) {
                result.push_back(q);   // Rule 1: exact match
            } else {
                string lower = toLower(q);
                string devowel = devowelString(lower);

                if (caseInsensitive.count(lower)) {
                    result.push_back(caseInsensitive[lower]); // Rule 2
                } else if (vowelInsensitive.count(devowel)) {
                    result.push_back(vowelInsensitive[devowel]); // Rule 3
                } else {
                    result.push_back(""); // No match
                }
            }
        }

        return result;
    }

private:
    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }

    string devowelString(string s) {
        for (char &c : s) {
            if (isVowel(c)) c = '*';
        }
        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
       
    }
};
