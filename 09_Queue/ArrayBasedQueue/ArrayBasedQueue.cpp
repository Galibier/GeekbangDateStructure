#include "ArrayBasedQueue.h"
#include <iostream>

using namespace std;

template<typename T>
ArrayBasedQueue<T>::ArrayBasedQueue() {
    this->cnt = 0;
    this->head = 0;
    this->tail = 0;
    this->capacity = 10;
    this->array = new T[this->capacity];
    if (!this->array) {
        cout << "array malloc memory failure" << endl;
    }
}

template<typename T>
ArrayBasedQueue<T>::ArrayBasedQueue(int cap) {
    this->cnt = 0;
    this->head = 0;
    this->tail = 0;
    this->capacity = cap + 1;
    this->array = new T[this->capacity];
    if (!this->array) {
        cout << "array malloc memory failure" << endl;
    }
}

template<typename T>
ArrayBasedQueue<T>::~ArrayBasedQueue() {
    if (this->array) {
        delete[] this->array;
        this->array = nullptr;
    }
}

template<typename T>
void ArrayBasedQueue<T>::push(const T &data) {
    if ((this->tail + 1) % this->capacity == this->head) {
        int newCapacity = int(1.5 * this->capacity);
        T *tmp = new T[newCapacity];
        for (int i = head; i < this->cnt; i++) {
            tmp[i % newCapacity] = this->array[i % this->capacity];
        }
        delete[] this->array;
        this->tail = (this->head + this->cnt);
        this->capacity = newCapacity;
    }
    this->cnt++;
    this->array[this->tail] = data;
    this->tail = (this->tail + 1) % this->capacity;
}

template<typename T>
void ArrayBasedQueue<T>::pop() {
    this->cnt--;
    this->head = (this->head + 1) % capacity;
}

template<typename T>
T ArrayBasedQueue<T>::front() {
    return this->array[this->head];
}

template<typename T>
int ArrayBasedQueue<T>::size() {
    return this->cnt;
}

template<typename T>
int ArrayBasedQueue<T>::cap() {
    return this->capacity;
}

int main(int argc, char const *argv[]) {
    cout << " === ArrayBaseQueue test begin ===" << endl;
    ArrayBasedQueue<float> queue;
    cout << "size===" << queue.size() << endl;
    queue.push(10.1);
    queue.push(20.2);
    queue.push(30.0);
    queue.push(40.4);
    queue.push(50.5);
    queue.push(60.6);

    cout << "size===" << queue.size() << endl;
    cout << "size===" << queue.cap() << endl;
    cout << "queue front  " << queue.front() << " " << queue.head << endl;
    queue.pop();
    cout << "queue front  " << queue.front() << " " << queue.head << endl;
    queue.pop();
    cout << "queue front  " << queue.front() << " " << queue.head << endl;
    queue.pop();
    cout << "size===" << queue.size() << endl;
    cout << "queue front  " << queue.front() << " " << queue.head << endl;
    queue.pop();
    while (queue.size() > 0) {
        cout << "size===" << queue.size() << endl;
        cout << "queue front  " << queue.front() << " " << queue.head << endl;
        queue.pop();
    }
    return 0;
}