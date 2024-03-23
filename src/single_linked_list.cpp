#include <limits>
#include <set>
#include <vector>

#include "single_linked_list.h"

void List::Add(int val_) {
    if (size == 0) {
        // create first
        head = new Node(val_);
        tail = head;
        size = 1;
    }
    else {
        // add to tail
        Node* tmp = new Node(val_);
        tail->SetNext(tmp);
        tmp->SetPrev(tail);
        ++size;
        tail = tmp;
    }
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    List::Node* runner = list.head;
    while (runner != nullptr) {
        os << runner->GetVal() << " ";
        runner = runner->GetNext();
    }
    os << std::endl;
    return os;
}

void List::Remove(int val_) {
    List::Node* runner = head;

    while (runner != nullptr) {
        if (runner->GetVal() == val_) {
            // delete this
            List::Node* prev = runner->GetPrev();
            List::Node* next = runner->GetNext();

            prev->SetNext(next);
            next->SetPrev(prev);

            delete runner;
            return;
        }
        else {
            runner = runner->GetNext();
        }
    }
    return;
}

int List::GetMax() {
    Node* runner = head;
    int curr_max = std::numeric_limits<int>::min();

    while (runner != nullptr) {
        if (runner->GetVal() > curr_max) {
            curr_max = runner->GetVal();
        }
        runner = runner->GetNext();
    }

    return curr_max;
}

List List::Split_half() {
    List ret;

    Node* runner = head;
    for (int i = 0; i < size / 2; ++i) {
        runner = runner->GetNext();
    }

    // tie new list
    ret.head = runner;
    ret.tail = tail;
    ret.size = size - (size / 2);

    // cut old list
    size = size / 2;
    tail = runner->GetPrev();

    // cut links
    runner->GetPrev()->SetNext(nullptr);
    runner->SetPrev(nullptr);

    return ret;    
}

bool List::Is_unique() {
    Node* first = head;
    Node* second = head;

    int counter = 0;

    while (first != nullptr) {
        int curr_val = first->GetVal();

        second = head;
        while (second != nullptr && second != first) {
            counter++;
            if (second->GetVal() == curr_val) {
                // element is NOT unique
                std::cout << "Enter loop " << counter << " times" << std::endl;
                return false;
            }
            second = second->GetNext();
        }
        first = first->GetNext();
    }
    std::cout << "Enter loop " << counter << " times" << std::endl;
    return true;
}

void List::ElevationShuffle() {
    Node* left = head;
    Node* right = tail;

    std::vector<Node*> v;
    v.reserve(size);

    for (int i = 0; i < size / 2; ++i) {
        v.push_back(left);
        v.push_back(right);

        left = left->GetNext();
        right = right->GetPrev();
    }

    for (int i = 1; i < size; ++i) {
        v[i-1]->SetNext(v[i]);
        v[i]->SetPrev(v[i-1]);
    }

    v.back()->SetNext(nullptr);
    v.back()->SetPrev(v[size - 2]);
    head = v[0];
    tail = v.back();
}