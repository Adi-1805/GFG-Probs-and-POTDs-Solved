#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

class LRUCache {
public:
    Node* head;
    unordered_map<int, int> mp;
    int size, cap;

    LRUCache(int cap) {
        this->cap = cap;
        this->size = 0;
        this->head = NULL;
    }

    int get(int key) {
        if (mp.count(key) == 0) return -1;

        Node* temp = head;
        Node* prev = NULL;

        while (temp && temp->val != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) return -1;

        // Move node to head
        if (prev) {
            prev->next = temp->next;
            temp->next = head;
            head = temp;
        }

        return mp[key];
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key] = value;
            get(key); // move to head
            return;
        }

        mp[key] = value;
        insertAtHead(head, key);
        size++;

        // Remove LRU if capacity exceeded
        if (size > cap) {
            Node* temp = head;
            Node* prev = NULL;

            while (temp->next) {
                prev = temp;
                temp = temp->next;
            }

            // temp = last node (LRU)
            if (prev) prev->next = NULL;
            else head = NULL;

            mp.erase(temp->val);
            delete temp;
            size--;
        }
    }
};