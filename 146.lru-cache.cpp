/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class LRUCache {
private:
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> kv;  // key -> (value, pointer to key_recency position)
    list<int> key_recency; // list from least recent to most recent keys.
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    // make key last (most recent) in recency list.
    void make_recent(int key){
        if (kv.count(key)){
            key_recency.erase(kv[key].second);
        }
        key_recency.push_back(key);
        kv[key] = {kv.count(key) ? kv[key].first : -1, --key_recency.end()};
    }
    
    int get(int key) {
        if (!kv.count(key)) return -1;
        make_recent(key);
        return kv[key].first;
    }
    
    void put(int key, int value) {
        // if at capacity, have to delete least recently used key
        if (kv.size() == cap && !kv.count(key)){
            kv.erase(*key_recency.begin());
            key_recency.erase(key_recency.begin());
        }
        
        make_recent(key);
        kv[key].first = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

