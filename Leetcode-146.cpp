/*
 * Problem 146: LRU Cache
 * Language: C++
 */
class LRUCache {
private:
    class Node{
    public:
        Node *next, *prev;
        int key;
        int val;
        Node(int key ,int val){
            this->key = key;
            this->val = val;
        }
    };
public:
    Node *head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void del(Node *temp){
        Node *prv = temp->prev;
        Node *nxt = temp->next;
        nxt->prev = prv;
        prv->next = nxt;
    }
    void add(Node* temp){
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
    }
    int get(int key) {
        int res = -1;
        if(mp.find(key)  != mp.end()){
            Node* ans = mp[key];
            res = ans->val;
            del(ans);
            add(ans);
            return res;
        }else return res;
    }
    
    void put(int key, int val) {
        if(mp.find(key) != mp.end()){
            Node* ans = mp[key];
            del(ans);
            add(new Node(key, val));
            mp[key] = head->next;
            return;
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            del(tail->prev);
            add(new Node(key, val));
            mp[key] = head->next;
        }else{
            add(new Node(key, val));
            mp[key] = head->next;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */