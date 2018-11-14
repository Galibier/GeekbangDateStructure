#ifndef DATASTRUCTURE_LINKLISTBASEDSTACK_H
#define DATASTRUCTURE_LINKLISTBASEDSTACK_H

template<typename T>
class LinkListBaseStack {
public:
    LinkListBaseStack();

    ~LinkListBaseStack();

    void push(const T &data);

    T top();

    void pop();

    int size() const;

private:
    int cnt;
    struct ListNode {
        T data;
        ListNode *next;
    };
    ListNode *head;
};

#endif //DATASTRUCTURE_LINKLISTBASEDSTACK_H
