    string prefix="http://tinyurl.com/";
    int count=0;
    unordered_map<string,string> mp;
    string encode(string longUrl) {
        string suffix = to_string(++count);
        string key = prefix+suffix;
        mp[key]=longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
         return mp[shortUrl];
    }
