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