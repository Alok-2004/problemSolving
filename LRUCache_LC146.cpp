/*
146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/
class Node{
public:
    int key , value;
    Node *next , *prev;

    Node(int key , int value){
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    unordered_map<int , Node*>uM;
    int size;
    int cap;
    Node* head;
    Node* tail;
public:

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int key, int val) {
        Node* temp = new Node(key, val);
        uM[key] = temp;
        if (size < cap) { 
            if (size == 0) {
                head = temp;
                tail = head;
            } else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            size++;
        } else {
            uM.erase(tail->key);
            
            if (tail->prev != nullptr) {
                tail = tail->prev;
                tail->next = nullptr;
            }else if(tail->prev ==  nullptr){
                head = nullptr;
            }
            temp->next = head;
            if (head != nullptr) head->prev = temp;
            head = temp;
        }
    }

    void update(int key, int val = INT_MIN){
        if(uM.find(key) !=  uM.end()){
            if (val != INT_MIN) uM[key]->value = val;
        }else{
            insert(key , val);
            return ;
        }
        Node* temp = uM[key];

        
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        

        if (temp == tail) tail = tail->prev;
        if (tail == nullptr) tail = temp;

        temp->next = head;
        if (head != nullptr) head->prev = temp;
        head = temp;
        temp->prev = nullptr;
    }


    int get(int key) {
        if(size != 0 and uM.find(key) != uM.end() ){
            update(key);
            // cout<<head->key<<endl;
            return uM[key]->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        update(key , value);
        // cout<<head->key<<endl;
    }
};

