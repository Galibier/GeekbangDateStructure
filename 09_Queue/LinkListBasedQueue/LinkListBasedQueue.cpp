#include <iostream>
#include "LinkListBasedQueue.h"

using namespace std;

template<class T>
LinkListBasedQueue<T>::LinkListBasedQueue() {
    this->cnt = 0;
    this->head = new ListNode;
    this->head->next = nullptr;
    this->tail = this->head;
}

template<class T>
LinkListBasedQueue<T>::~LinkListBasedQueue() {
    ListNode *ptr, *tmp;
    ptr = head;
    while (ptr->next != nullptr) {
        tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
    }
    delete head;
    this->head = nullptr;
    this->cnt = 0;
}

template<class T>
void LinkListBasedQueue<T>::push(const T &data) {
    ListNode *tmp = new ListNode;
    tmp->data = data;
    this->tail->next = tmp;
    this->tail = this->tail->next;
    this->cnt++;
    cout << "push data : " << this->tail->data << endl;
}

template<class T>
T LinkListBasedQueue<T>::front() {
    return this->head->next->data;
}

template<class T>
void LinkListBasedQueue<T>::pop() {
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
int LinkListBasedQueue<T>::size() const {
    return this->cnt;
}

int main(int argc, char const *argv[]) {
    cout << " === LinkListBaseQueue test begin ===" << endl;
    LinkListBasedQueue<float> queue;
    cout << "size===" << queue.size() << endl;
    queue.push(10.1);
    queue.push(20.2);
    queue.push(30.0);
    queue.push(40.4);
    queue.push(50.5);
    queue.push(60.6);
    cout << "size===" << queue.size() << endl;
    cout << "queue front  " << queue.front() << endl;
    queue.pop();
    cout << "queue front  " << queue.front() << endl;
    queue.pop();
    cout << "queue front  " << queue.front() << endl;
    queue.pop();
    cout << "size===" << queue.size() << endl;
    cout << "queue front  " << queue.front() << endl;
    queue.pop();
    while(queue.size()!=0){
        cout << "size===" << queue.size() << endl;
        cout << "queue front  " << queue.front() << endl;
        queue.pop();
    }
    return 0;
}