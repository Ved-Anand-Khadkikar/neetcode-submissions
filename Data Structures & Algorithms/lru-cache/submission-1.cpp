class LRUCache {
   public:
    class Node {
       public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    void addNode(Node* newNode) {
        Node* headNext = head->next;
        head->next = newNode;
        newNode->next = headNext;
        headNext->prev = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node* delNode) {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }

    int limit;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            addNode(node);
            return node->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            deleteNode(mp[key]);
            delete mp[key];
            mp.erase(key);
        }
        if (mp.size() == limit) {
            Node* delNode = tail->prev;
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            delete (delNode);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
