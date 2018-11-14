#ifndef DATASTRUCTURE_ARRAYBASEDQUEUE_H
#define DATASTRUCTURE_ARRAYBASEDQUEUE_H

template<typename T>
class ArrayBasedQueue {
public:
    ArrayBasedQueue();

    ArrayBasedQueue(int cnt);

    ~ArrayBasedQueue();

    void push(const T &data);

    void pop();

    T front();

    int size();
    int cap();

    int capacity;
    int cnt;
    int head;
    int tail;
    T *array;
};

#endif //DATASTRUCTURE_ARRAYBASEDQUEUE_H
