#ifndef DATASTRUCTURE_LINKEDLISTBASEDLRU_H
#define DATASTRUCTURE_LINKEDLISTBASEDLRU_H

typedef int DataType;

class SNode {
public:
    DataType data;
    SNode *next;
};

class LinkedList {
public:
    LinkedList();

    LinkedList(int MaxSize);

    ~LinkedList();

    void insertElemAtBegin(DataType x);

    bool findElem(DataType x);

    void deleteElemAtEnd();

    bool deleteElem(DataType x);

    bool isEmpty();

    bool isFull();

    void printAll();

    void *findElemOptimal(DataType x);

    void deleteElemOptimal(void *snode);

private:
    int maxSize;       // 链表可以存放最大的数据
    int length;             // 链表的长度
    SNode *head;          // 指向头节点
};

#endif //DATASTRUCTURE_LINKEDLISTBASEDLRU_H
