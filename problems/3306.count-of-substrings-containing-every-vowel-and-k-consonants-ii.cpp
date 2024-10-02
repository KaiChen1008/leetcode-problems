/*
 * @lc app=leetcode id=3306 lang=cpp
 *
 * [3306] Count of Substrings Containing Every Vowel and K Consonants II
 */
#include <string>
#include <unordered_set>
// @lc code=start
using namespace std;
using LL = long long;
class Solution
{
public:
    long long countOfSubstrings(string word, int k)
    {
        int numVowels = 0;     // number of vowel types
        int numConsonants = 0; // number of consonants
        int n = word.size();
        LL ans = 0;
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        unordered_map<char, int> vowelMap;

        // count how many continues vowels after it
        vector<int> A(n, 0);
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (vowels.find(word[i]) != vowels.end())
            {
                count++;
                A[i] = count;
            }
            else
            {
                count = 0;
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < n && (numVowels < 5 || numConsonants < k))
            {
                if (vowels.find(word[j]) != vowels.end())
                {
                    vowelMap[word[j]]++;
                    if (vowelMap[word[j]] == 1)
                        numVowels++;
                }
                else
                    numConsonants++;
                j++;
            }

            // numVowels == 5 && numConsonats == k
            if (numVowels == 5 && numConsonants == k)
            {
                ans += 1 + (j == n ? 0 : A[j]);
            }

            if (vowels.find(word[i]) != vowels.end())
            {
                vowelMap[word[i]]--;
                if (vowelMap[word[i]] == 0)
                    numVowels--;
            }
            else
            {
                numConsonants--;
            }
        }
        return ans;
    }
};
// @lc code=end
