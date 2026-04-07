/*
 * Problem 146: LRU Cache
 * Language: C++
 */
class Node{
    Node* prev, *next;
    int key, val;
    Node(int k, int v){
        prev = NULL;
        next = NULL;
        key = k;
        val = v;
    }
}
class LRUCache {
public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */