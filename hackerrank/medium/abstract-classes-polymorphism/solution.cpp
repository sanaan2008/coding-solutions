
class LRUCache : public Cache {
public:
    LRUCache(int cap) {
        cp = cap;
        head = nullptr;
        tail = nullptr;
    }

    void set(int key, int val) override {
        // Case 1: Key already exists in the cache
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = val;

            // Move this node to the front (head) if not already there
            if (node != head) {
                if (node == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                node->prev = nullptr;
                node->next = head;
                head->prev = node;
                head = node;
            }
            return;
        }

        // Case 2: New key inserted
        Node* newNode = new Node(key, val);

        // If cache is empty
        if (!head) {
            head = tail = newNode;
            mp[key] = newNode;
            return;
        }

        // Insert at the front (head)
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        mp[key] = newNode;

        // Evict LRU element if capacity is exceeded
        if ((int)mp.size() > cp) {
            mp.erase(tail->key);
            Node* oldTail = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            delete oldTail;
        }
    }

    int get(int key) override {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move accessed node to head (most recently used)
        if (node != head) {
            if (node == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }

        return node->value;
    }
};
