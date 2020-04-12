//Dynamic Programming

//Author: Abhishek Kumar Suman
//Roll number:181210002
//Branch: CSE 2nd year

//Given two strings str1 and str2 and below operations that can performed on str1. Find
//minimum number of edits(operations) required to convert ‘str1’ into ‘str2’.

//Valid operations are:
//          1.Replace
//          2.Remove
//          3.Insert

//Input : str1 = "sunday", str2 = "saturday"
//Output : 3
//The above input requires three operations. Bascially, we need to convert "un" to "atur", so we can
//replace n with r and insert "a" and "t".

//Time complexity:Since we are iterating through all the characters of all the strings, so time complexity is O(NM),
//where N is the length of str1
//      M is the length of str2.

//Code
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum of three numbers
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistDP(string str1, string str2, int m, int n)
{

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        { // If first string is empty, only option is to
            // isnert all characters of second string
            if (i == 0)
                dp[i][j] = j;

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i;

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }
    return dp[m][n];
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    cout << editDistDP(str1, str2, str1.length(), str2.length());
    return 0;
}