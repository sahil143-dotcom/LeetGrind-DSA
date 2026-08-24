struct Node
{
    int key , value;
    Node *next , *prev;
    Node(int key , int value)
    {
        this->key = key;
        this->value = value;
    }
};



class LRUCache {
    int _capacity;
    unordered_map<int,Node*>um;
    Node *head = new Node(-1 , -1);
    Node* tail = new Node(-1 , -1);
        void deleteNode(Node* delNode)
    {
        Node* nextDelNode = delNode->next;
        Node* prevDelNode = delNode->prev;
        nextDelNode->prev = prevDelNode;
        prevDelNode->next = nextDelNode;
    }

    void addNode(Node* addNode)
    {
        Node *temp = head->prev;
        head->prev = addNode;
        addNode->next = head;
        addNode->prev = temp;
        temp->next = addNode;
    }
public:
    LRUCache(int capacity) {
        head->prev = tail;
        tail->next = head;
        _capacity = capacity;
    }
    
    int get(int key) {
        if(um.find(key) == um.end()) return -1;
        Node* getNode = um[key];
        deleteNode(getNode); // Deletes the node at any position 
        addNode(getNode); // Add it towards the right most side that is prev of head
        return getNode->value;
    }
    
    void put(int key, int value) {
        if(um.find(key)== um.end())
        {
            if(_capacity==um.size())
            {
                Node* lruNode = tail->next;
                deleteNode(lruNode);
                um.erase(lruNode->key);
                delete(lruNode);
            }
            Node* _addNode = new Node(key , value);
            addNode(_addNode);
            um[key] = _addNode;
        }else
        {
            Node*putNode = um[key];
            deleteNode(putNode);
            putNode->value = value;
            addNode(putNode);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */