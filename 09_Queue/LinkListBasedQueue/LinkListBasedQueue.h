#ifndef DATASTRUCTURE_LINKLISTBASEDQUEUE_H
#define DATASTRUCTURE_LINKLISTBASEDQUEUE_H

template<typename T>
class LinkListBasedQueue {
public:
    LinkListBasedQueue();

    ~LinkListBasedQueue();

    void push(const T &data);

    T front();

    void pop();

    int size() const;

private:
    int cnt;
    struct ListNode {
        T data;
        ListNode *next;
    };
    ListNode *head;
    ListNode *tail;
};

#endif //DATASTRUCTURE_LINKLISTBASEDQUEUE_H
