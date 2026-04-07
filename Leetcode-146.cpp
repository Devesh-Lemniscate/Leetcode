/*
 * Problem 146: LRU Cache
 * Language: C++
 */
class Node{
public:
    Node* prev, *next;
    int key, val;
    Node(int k, int v){
        prev = NULL;
        next = NULL;
        key = k;
        val = v;
    }
};
class LRUCache {
public:
    int cap;
    Node* head, *tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = tail;
        temp->prev = tail->prev;
        tail->prev->next = temp;
        tail->prev = temp;
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* temp = mp[key];
            
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->val = value;

            temp->next = tail;
            temp->prev = tail->prev;
            tail->prev->next = temp;
            tail->prev =temp;
        }else{
            if(mp.size() == cap){
                mp.erase(head->next->key);
                Node* temp = head->next;
                head->next = head->next->next;
                head->next->prev = head;
                delete temp;
            }
            Node *temp = new Node(key, value);
            temp->next = tail;
            temp->prev = tail->prev;
            tail->prev->next = temp;
            tail->prev =temp;
            mp[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */