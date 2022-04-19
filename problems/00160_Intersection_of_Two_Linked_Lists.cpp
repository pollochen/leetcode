/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b) {
            if (a == NULL) a = headB;
            else a = a->next;
            if (b == NULL) b = headA;
            else b = b->next;
        }
        return a;
    }
};

// count length and start from same level of nodes
// Runtime: 84 ms, faster than 21.36% of C online submissions for Intersection of Two Linked Lists.
// Memory Usage: 14 MB, less than 37.21% of C online submissions for Intersection of Two Linked Lists.
int get_length(struct ListNode *head)
{
    int cnt = 0;
    while (head != NULL) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len_a = get_length(headA);
    int len_b = get_length(headB);
    if (len_a == 0 || len_b == 0) return NULL;
    int diff;
    if (len_a >= len_b) {
        diff = len_a - len_b;
        for (int i = 0; i < diff; i++) headA = headA->next;
    } else {
        diff = len_b - len_a;
        for (int i = 0; i < diff; i++) headB = headB->next;
    }

    while (headA != NULL && headB != NULL) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

// 2 pointer
// Runtime: 52 ms, faster than 53.20% of C online submissions for Intersection of Two Linked Lists.
// Memory Usage: 13.8 MB, less than 73.40% of C online submissions for Intersection of Two Linked Lists.
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *la = headA;
    struct ListNode *lb = headB;
    while (la != NULL && lb != NULL) {
        la = la->next;
        lb = lb -> next;
    }
    if (la == NULL) {
        struct ListNode *l1 = headB;
        while (lb != NULL) {
            lb = lb->next;
            l1 = l1->next;
        }
        lb = l1;
        la = headA;
        while (la != NULL && lb != NULL) {
            if (la == lb) return la;
            la = la->next;
            lb = lb -> next;
        }
    } else {
        struct ListNode *l1 = headA;
        while (la != NULL) {
            la = la->next;
            l1 = l1->next;
        }
        la = l1;
        lb = headB;
        while (la != NULL && lb != NULL) {
            if (la == lb) return la;
            la = la->next;
            lb = lb -> next;
        }
    }
    return NULL;
}