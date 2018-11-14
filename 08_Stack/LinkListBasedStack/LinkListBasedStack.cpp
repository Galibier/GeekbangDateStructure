#include <iostream>
#include "LinkListBasedStack.h"

using namespace std;

template<class T>
LinkListBaseStack<T>::LinkListBaseStack() {
    this->cnt = 0;
    this->head = new ListNode;
    this->head->next = nullptr;
}

template<class T>
LinkListBaseStack<T>::~LinkListBaseStack() {
    ListNode *ptr, *tmp;
    ptr = head;
    while (ptr->next != nullptr) {
        tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
    }
    delete head;
    this->head = nullptr;
}

template<class T>
void LinkListBaseStack<T>::push(const T &data) {
    ListNode *tmp = new ListNode;
    tmp->data = data;
    tmp->next = this->head->next;
    head->next = tmp;
    this->cnt++;
    cout << "push data : " << this->head->next->data << endl;
}

template<class T>
T LinkListBaseStack<T>::top() {
    return this->head->next->data;
}

template<class T>
void LinkListBaseStack<T>::pop() {
    if (this->cnt == 0 || this->head->next == nullptr) {
        cout << " stack is empty, pop fail" << endl;
    } else {
        ListNode *tmp = this->head->next;
        this->head->next = tmp->next;
        delete tmp;
        this->cnt--;
    }
    return;
}

template<class T>
int LinkListBaseStack<T>::size() const {
    return this->cnt;
}

int main(int argc, char const *argv[]) {
    cout << " === StackBasedOnLinkedList test begin ===" << endl;
    LinkListBaseStack<float> stack;
    cout << "size===" << stack.size() << endl;
    stack.push(10.1);
    stack.push(20.2);
    stack.push(30.);
    stack.push(40.4);
    stack.push(50.5);
    stack.push(60.6);
    cout << "size===" << stack.size() << endl;
    cout << "stack top  " << stack.top() << endl;
    cout << "size===" << stack.size() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout << "size===" << stack.size() << endl;
    cout << "stack top  " << stack.top() << endl;
    stack.push(110.1);
    stack.push(120.2);
    stack.push(130.3);
    stack.push(140.4);
    stack.push(150.5);
    stack.push(160.6);
    cout << "size===" << stack.size() << endl;
    stack.pop();
    cout << "stack top  " << stack.top() << endl;
    stack.pop();
    cout << "stack top  " << stack.top() << endl;
    stack.pop();
    cout << "stack top  " << stack.top() << endl;
    return 0;
}