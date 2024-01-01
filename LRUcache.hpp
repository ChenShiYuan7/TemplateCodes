#include <unordered_map>
typedef struct DblNode {
    int key;
    int val;
    DblNode* prev;
    DblNode* next;
    DblNode() : val(0), prev(nullptr), next(nullptr) {}
    DblNode(int newVal) : val(newVal), prev(nullptr), next(nullptr) {
    }
    DblNode(int newVal, DblNode* prev, DblNode* next) : val(newVal), prev(prev), next(next) {
    }
}DblNode;

class LRUCache {
public:

    std::unordered_map<int, DblNode*> mapNodes = {};
    int limit = 0;
    DblNode* head;
    LRUCache(int capacity) : limit(capacity), head(nullptr), mapNodes() {

    }
    ~LRUCache() {
        while (head != nullptr)
        {
            DblNode* next = head->next;
            delete head;
            head = next;
        }
    }

    int get(int key);
    void put(int key, int value);
    void remove(DblNode* item);
    void removeAndDelete(DblNode* item);
    DblNode* getLatest();
    void addToHead(DblNode* item);

};