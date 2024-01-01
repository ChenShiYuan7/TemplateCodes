#include "LRUcache.hpp"

int LRUCache::get(int key) {
    if (mapNodes.find(key) != mapNodes.end())
    {
        DblNode* item = mapNodes[key];
        remove(item);
        addToHead(item);
        return item->val;
    }
    else
        return -1;

}

void LRUCache::put(int key, int value) {

    DblNode* newItem = new DblNode(value);
    newItem->key = key;
    removeAndDelete(mapNodes[key]);
    mapNodes.erase(key);
    mapNodes[key] = newItem;
    addToHead(newItem);
    if (mapNodes.size() > limit)
    {
        DblNode* item = getLatest();
        removeAndDelete(item);
    }
}
void LRUCache::remove(DblNode* item)
{
    if (item == nullptr)
        return;
    DblNode* prev = item->prev;
    DblNode* next = item->next;
    if (item == head)
        head = next;
    if (prev != nullptr)
        prev->next = next;
    if (next != nullptr)
        next->prev = prev;
}
void LRUCache::removeAndDelete(DblNode* item)
{
    if (item == nullptr)
        return;
    remove(item);
    //if (item == nullptr)
    //    return;
    //DblNode* prev = item->prev;
    //DblNode* next = item->next;
    //if (item == head)
    //{
    //    head = next;
    //}
    //if (prev != nullptr)
    //    prev->next = next;
    //if (next != nullptr)
    //    next->prev = prev;
    mapNodes.erase(item->key);
    delete item;
}
DblNode* LRUCache::getLatest()
{
    DblNode* last = head;
    while (last->next != nullptr)
        last = last->next;
    return last;
}
void LRUCache::addToHead(DblNode* item)
{
    item->next = head;
    item->prev = nullptr;
    if (head != nullptr)
        head->prev = item;
    head = item;
}