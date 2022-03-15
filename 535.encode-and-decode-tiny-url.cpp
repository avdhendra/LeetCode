/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution {
public:
//this map is our database which stores key->val in this order
    // Encodes a URL to a shortened URL.
    map<string,string> database;
    string encode(string longUrl) {
        //base string which is common for all TinyURL
        string urlBase="https:tinyurl.com/";
        //declaring as static so that it does not conflict with any other url
        static int num=0;
        string store=""; //this will contain the new tinyurl
        store=urlBase+to_string(num);
        database[store]=longUrl;//storing the tinyurl in the database
        num++;//incrementing the num so that when a new URL is given it will have a new URL.
        return store;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //if the given short url is valid returing the value of the shortURL
   return database[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

