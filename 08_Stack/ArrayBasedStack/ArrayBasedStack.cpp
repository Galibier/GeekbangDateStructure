#include "ArrayBasedStack.h"
#include <iostream>

using namespace std;

template<typename T>
ArrayBasedStack<T>::ArrayBasedStack() {
    this->cnt = 0;
    this->capacity = 10;
    this->array = new T[this->capacity];
    if (!this->array) {
        cout << "array malloc memory failure" << endl;
    }
}

template<typename T>
ArrayBasedStack<T>::ArrayBasedStack(int cap) {
    this->cnt = 0;
    this->capacity = cap;
    this->array = new T[this->capacity];
    if (!this->array) {
        cout << "array malloc memory failure" << endl;
    }
}

template<typename T>
ArrayBasedStack<T>::~ArrayBasedStack() {
    if (this->array) {
        delete[] this->array;
        this->array = nullptr;
    }
}

template<typename T>
void ArrayBasedStack<T>::push(const T &data) {
    if (this->capacity == this->cnt) {
        this->capacity = int(1.5 * this->cnt);
        T *tmp = new T[this->capacity];
        for (int i = 0; i < this->cnt; i++) {
            tmp[i] = this->array[i];
        }
        delete[] this->array;
        this->array = tmp;
    }
    this->array[this->cnt++] = data;
}

template<typename T>
void ArrayBasedStack<T>::pop() {
    this->cnt--;
}

template<typename T>
T ArrayBasedStack<T>::top() {
    return this->array[this->cnt - 1];
}

template<typename T>
int ArrayBasedStack<T>::size() {
    return this->cnt;
}

int main(int argc, char const *argv[]) {
    cout << " === test begin ===" << endl;
    ArrayBasedStack<int> arrstack(6);
    arrstack.push(10);
    arrstack.push(20);
    arrstack.push(30);
    arrstack.push(40);
    arrstack.push(50);
    arrstack.push(60);
    arrstack.push(70);
    arrstack.push(80);
    arrstack.push(90);
    arrstack.push(100);
    arrstack.push(110);
    arrstack.push(120);
    arrstack.push(130);
    arrstack.push(140);
    arrstack.push(150);
    while (arrstack.size() != 0) {
        cout << "top() = " << arrstack.top() << endl;
        arrstack.pop();
    }

    return 0;
}