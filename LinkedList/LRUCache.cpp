#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <unordered_map>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cacheList; // List to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // Map to store key and its corresponding iterator in the list

    LRUCache(int capacity)  {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }
        // Move the accessed node to the front of the list
        auto it = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, it);
        return it->second; // Return the value
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key already exists, update the value and move it to the front
            auto it = cacheMap[key];
            it->second = value; // Update value
            cacheList.splice(cacheList.begin(), cacheList, it); // Move to front
        } else {
            // Key does not exist, insert new key-value pair
            if (cacheList.size() == capacity) {
                // Cache is full, remove the least recently used item
                auto last = cacheList.back();
                cacheMap.erase(last.first); // Remove from map
                cacheList.pop_back(); // Remove from list
            }
            cacheList.emplace_front(key, value); // Insert at front
            cacheMap[key] = cacheList.begin(); // Update map with new iterator
        }
    }
};

int main() {
    LRUCache cache(2); // Cache capacity of 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1

    cache.put(3, 3); // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)

    cache.put(4, 4); // evicts key 3
    cout << cache.get(3) << endl; // returns -1 (not found)
    cout << cache.get(4) << endl; // returns 4

    return 0;
}