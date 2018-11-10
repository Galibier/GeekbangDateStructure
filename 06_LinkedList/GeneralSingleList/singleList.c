#include "singleList.h"

#include <string.h>

linkedList *listCreate() {
    linkedList *list = NULL;
    list = malloc(sizeof(*list));
    if (NULL == list) {
        return NULL;
    }

    list->dup = NULL;
    list->free = NULL;
    list->match = NULL;
    list->head = NULL;
    list->len = 0;

    return list;
}

void listRelease(linkedList *list) {
    if (NULL == list) {
        return;
    }
    listEmpty(list);
    free(list);
    list = NULL;
}

void listEmpty(linkedList *list) {
    if (NULL == list) {
        return;
    }
    while (NULL != list->head) {
        listNode *pNode = list->head;
        list->head = pNode->next;
        if (NULL != list->free) {
            list->free(pNode->value);
        } else {
            free(pNode->value);
        }
        pNode->next = NULL;
        free(pNode);
        pNode = NULL;
    }
}

linkedList *listAddNodeHead(linkedList *list, void *value) {
    if (NULL == list || NULL == value) {
        return list;
    }
    listNode *node = NULL;
    node = malloc(sizeof(*node));
    if (NULL == node) {
        return list;
    }
    node->value = value;
    node->next = list->head;
    list->head = node;

    ++list->len;
    return list;
}

linkedList *listAddNodeTail(linkedList *list, void *value) {
    if (NULL == list || NULL == value) {
        return list;
    }
    listNode *node = NULL;
    node = malloc(sizeof(*node));
    if (NULL == node) {
        return list;
    }
    node->value = value;
    node->next = NULL;

    if (NULL == list->head && list->len == 0) {
        list->head = node;
    } else {
        listNode *tail = list->head;
        listNode *pre = list->head;
        while (NULL != tail) {
            pre = tail;
            tail = tail->next;
        }
        pre->next = node;
    }
    ++list->len;
    return list;
}

linkedList *listInsertNode(linkedList *list, listNode *oldNode, void *value, bool after) {
    if (NULL == list || NULL == oldNode) {
        return list;
    }

    listNode *pNode = NULL;
    pNode = malloc(sizeof(*pNode));
    if (NULL == pNode) {
        return list;
    }
    pNode->value = value;
    if (after) {
        pNode->next = oldNode->next;
        oldNode->next = pNode;
    } else {
        listNode *pre = list->head;
        while (pre->next != oldNode) {
            pre = pre->next;
        }
        if (NULL != pre) {
            pre->next = pNode;
            pNode->next = oldNode;
        }
    }
    ++list->len;
    return list;
}

void listDelNode(linkedList *list, listNode *node) {
    if (NULL == list || NULL == node) {
        return;
    }

    listNode *pre = list->head;
    listNode *cur = list->head;
    while (NULL != cur && cur != node) {
        pre = cur;
        cur = cur->next;
    }

    if (NULL == pre) {
        return;
    }

    pre->next = node->next;
    node->next = NULL;
    --list->len;

    if (NULL != list->free) {
        list->free(node->value);
        free(node);
        node = NULL;
    }
}


listNode *listSearchKey(linkedList *list, void *key) {
    if (NULL == list) {
        return NULL;
    }
    listNode *node = list->head;
    while (NULL != node) {
        if (NULL != list->match) {
            if (list->match(key, node->value) == 0) {
                return node;
            }
        } else {
            if (key == node->value) {
                return node;
            }
        }

        node = node->next;
    }

    return NULL;
}

listNode *listIndex(linkedList *list, long index) {
    if (NULL == list) {
        return NULL;
    }

    if (index <= 0 || index > list->len) {
        return NULL;
    }

    listNode *pNode = list->head;
    for (long i = 0; i < index; ++i) {
        pNode = pNode->next;
    }

    return pNode;
}

linkedList *listRewind(linkedList *list) {
    if (NULL == list) {
        return NULL;
    }

    listNode *head = list->head;
    listNode *pre = NULL;
    listNode *next = NULL;
    while (NULL != head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    list->head = pre;
    return list;
}


size_t listLength(linkedList *list) {
    if (NULL == list) {
        return 0;
    }

    return list->len;
}
