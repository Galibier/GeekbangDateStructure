#ifndef DATASTRUCTURE_ARRAYBASEDSTACK_H
#define DATASTRUCTURE_ARRAYBASEDSTACK_H

template<typename T>
class ArrayBasedStack {
public:
    ArrayBasedStack();

    ArrayBasedStack(int cnt);

    ~ArrayBasedStack();

    void push(const T &data);

    void pop();

    T top();

    int size();

private:
    int capacity;
    int cnt;
    T *array;
};

#endif //DATASTRUCTURE_ARRAYBASEDSTACK_H
