#pragma once

#include <iostream>

class List {
private:
    struct Node {
    private:
        int val = 0;
        Node* next = nullptr;
        Node* prev = nullptr;

    public:
        Node() = delete;
        explicit Node(int val_) : val(val_) { }

    public:
        // getters
        int GetVal() { return val; }
        Node* GetNext() { return next; }
        Node* GetPrev() { return prev; }

        // setters
        void SetVal(int val_) { val = val_; }
        void SetNext(Node* next_) { next = next_; }
        void SetPrev(Node* prev_) { prev = prev_; }
    };      // struct Node

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    List() = default;

public:     // methods
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    void Add(int val_);
    
    void Remove(int val_);
    void Reverse();
    int GetMax();
    List Split_half();
    bool Is_unique();
    void ElevationShuffle();

    void PrintAddresses();

    int GetSize() { return size; }
};