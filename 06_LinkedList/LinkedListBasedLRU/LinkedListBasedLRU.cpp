#include "LinkedListBasedLRU.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = new SNode;
    head->next = nullptr;
    this->maxSize = 10;
    this->length = 0;
}

LinkedList::LinkedList(int maxSize) {
    head = new SNode;
    head->next = nullptr;
    this->maxSize = maxSize;
    this->length = 0;
}

LinkedList::~LinkedList() {
    SNode *ptr, *tmp;
    ptr = head;
    while (ptr->next != nullptr) {
        tmp = ptr->next;
        ptr->next = ptr->next->next;
        delete tmp;
    }
    delete head;
    this->head = nullptr;
    this->length = 0;
}

void LinkedList::insertElemAtBegin(DataType x) {
    SNode *ptr = new SNode;
    ptr->data = x;

    ptr->next = head->next;
    head->next = ptr;
    this->length++;
}

bool LinkedList::findElem(DataType x) {
    SNode *ptr = head;
    while (ptr->next != nullptr) {
        if (ptr->next->data == x) {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

void LinkedList::deleteElemAtEnd() {
    SNode *ptr = head, *tmp = nullptr;
    while (ptr->next != nullptr && ptr->next->next != nullptr) {
        ptr = ptr->next;
    }
    tmp = ptr->next;
    ptr->next = tmp->next;
    this->length--;
    delete tmp;
}

bool LinkedList::deleteElem(DataType x) {
    SNode *ptr = head, *tmp = nullptr;
    while (ptr->next != nullptr) {
        if (ptr->next != nullptr) {
            tmp = ptr->next;
            ptr->next = tmp->next;
            delete tmp;
            this->length--;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

bool LinkedList::isEmpty() {
    if (this->length == 0) {
        return false;
    } else {
        return true;
    }
}

bool LinkedList::isFull() {
    if (this->length == this->maxSize) {
        return false;
    } else {
        return true;
    }
}

void LinkedList::printAll() {
    SNode *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        cout << ptr->data << "  ";
    }
    cout << endl;
}

void *LinkedList::findElemOptimal(DataType x) {
    SNode *ptr = head;
    while (ptr->next != nullptr) {
        if (ptr->next->data == x) {
            return (void *) ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void LinkedList::deleteElemOptimal(void *snode) {
    SNode *ptr = (SNode *) snode;
    SNode *tmp = ptr->next;
    ptr->next = tmp->next;
    this->length--;
    delete tmp;
}

//test case:
int main(int argc, char const *argv[]) {
    cout << "test " << endl;
    LinkedList slist(10);
    int num = 0;
    while (1) {
        cout << "please enter a number,99999 == exit" << endl;
        cin >> num;
        if (num == 99999)
            break;
        /*
        if(slist.findElem(num)){
            slist.deleteElem(num);
            slist.intsertElemAtBegin(num);
        }
        */

        SNode *prePtr = (SNode *) slist.findElemOptimal(num);
        if (prePtr != NULL) {
            slist.deleteElemOptimal(prePtr);
            slist.insertElemAtBegin(num);
        } else {
            if (slist.isFull()) {
                slist.insertElemAtBegin(num);
            } else {
                slist.deleteElemAtEnd();
                slist.insertElemAtBegin(num);
            }
        }
        slist.printAll();
    }
    return 0;
}