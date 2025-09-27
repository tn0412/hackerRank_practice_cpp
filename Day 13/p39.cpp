#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
   int curr_size;
   void deleteNode(Node* node){
      if(node->prev != NULL)
         node->prev->next = node->next;
      else
         head = node->next;

      if(node->next != NULL)
         node->next->prev = node->prev;
      else
         tail = node->prev;
   }

   void addToHead(Node* node){
      node->next = head;
      node->prev = NULL;

      if(head != NULL)
         head->prev = node;

      head = node;

      if(tail == NULL)
         tail = head;
   }

   public:
   LRUCache(int capacity) {
      cp = capacity;
      curr_size = 0;
      head = NULL;
      tail = NULL;
   }

   int get(int key) {
      if(mp.find(key) != mp.end()){
         Node* node = mp[key];
         int result = node->value;
         deleteNode(node);
         addToHead(node);
         mp[key] = head; 
         return result;
      }
      return -1;
   }

   void set(int key, int value) {
      if(mp.find(key) != mp.end()){
         Node* node = mp[key];
         node->value = value;
         deleteNode(node);
         addToHead(node);
         mp[key] = head; 
      } else {
         Node* newNode = new Node(key, value);
         if(curr_size < cp){
            curr_size++;
            addToHead(newNode);
            mp[key] = head; 
         } else {
            mp.erase(tail->key);
            Node* oldTail = tail;
            deleteNode(tail);
            delete oldTail; // Giải phóng bộ nhớ
            curr_size--;    // Giảm kích thước
            addToHead(newNode);
            mp[key] = head; 
            curr_size++;    // Tăng lại kích thước
         }
      }
   }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
