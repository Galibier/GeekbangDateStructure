#include "ArrayBasedStack.h"
#include <iostream>

using namespace std;

template<typename T>
ArrayStack<T>::ArrayStack() {
    this->cnt = 10;
    this->flag = 0;
    this->array = new T[this->cnt];
    if (!this->array) {
        cout << "array malloc memory failure" << endl;
    }
}

template<typename T>
ArrayStack<T>::ArrayStack(int cnt) {
    this->cnt = cnt;
    this->flag = 0;
    this->array = new T[this->cnt];
    if (!this->array) {
        cout << "array malloc memory failure" << endl;
    }
}

template<typename T>
ArrayStack<T>::~ArrayStack() {
    this->cnt = 0;
    this->flag = 0;
    if (this->array) {
        delete[] this->array;
        this->array = nullptr;
    }
}

template<typename T>
void ArrayStack<T>::push(T data) {
    if (this->flag == this->cnt) {
        cout << "The stack is full , so need to enlarge 1.5x! " << endl;
        this->cnt = int(1.5 * this->cnt);
        T *tmp = new T[this->cnt];
        for (int i = 0; i < this->flag; i++) {
            tmp[i] = this->array[i];
        }
        delete[] this->array;
        tmp[this->flag] = data;
        this->flag++;
        this->array = tmp;
    } else {
        this->array[this->flag] = data;
        this->flag++;
    }
}

template<typename T>
void ArrayStack<T>::pop() {
    this->flag--;
}

template<typename T>
T ArrayStack<T>::top() {
    T tmp = this->array[this->flag - 1];
    return tmp;
}

template<typename T>
int ArrayStack<T>::size() {
    return this->flag;
}

int main(int argc, char const *argv[]) {
    cout << " === test begin ===" << endl;
    ArrayStack<int> arrstack(12);
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

    cout << "peek , not delete " << arrstack.top() << endl;

    arrstack.push(210);
    arrstack.push(220);

    cout << "peek , not delete " << arrstack.top() << endl;
    
    return 0;
}