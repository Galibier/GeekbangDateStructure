#ifndef DATASTRUCTURE_ARRAYBASEDSTACK_H
#define DATASTRUCTURE_ARRAYBASEDSTACK_H

template <typename T>
class ArrayStack{
public:
    ArrayStack();
    ArrayStack(int cnt);
    ~ArrayStack();

    void push(const T &data);
    void pop();
    T top();
    int size();

private:
    int flag;
    int cnt;
    T *array;
};

#endif //DATASTRUCTURE_ARRAYBASEDSTACK_H
