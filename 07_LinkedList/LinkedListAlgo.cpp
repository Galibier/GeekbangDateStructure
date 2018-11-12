struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *ret = new ListNode(-1);
    ret->next = head;
    ListNode *pre = ret;
    ListNode *cur = head;

    while (head != nullptr && head->next != nullptr) {
        ListNode *tmp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = tmp;
    }
    return ret->next;
}

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode preHead(-1);
    ListNode *curr = &;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    curr->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode preHead(-1);
    preHead.next = head;
    ListNode *t1 = &preHead, *t2 = head;

    for (int i = 1; i < n; ++i) {
        t2 = t2->next;
    }
    while (t2->next != NULL) {
        t1 = t1->next;
        t2 = t2->next;
    }
    t1->next = t1->next->next;

    return preHead.next;
}

ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next, fast = fast->next->next;
    }

    return slow;
}