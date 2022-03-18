    ListNode* reverseList(ListNode* head) {
        ListNode *n_prev = NULL;
        ListNode *result = NULL;

        while (head != NULL) {
            ListNode *tmp = head->next;
            if (tmp == NULL) result = head;

            head->next = n_prev;
            n_prev = head;
            head = tmp;
        }
        return result;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *result = head;
        ListNode *list1_start = NULL;
        ListNode *list1_end = NULL;
        ListNode *list_head = NULL;
        ListNode *list_tail = NULL;
        ListNode *node_pre = NULL;
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            if (cnt == left) {
                list1_start = head;
                list_head = node_pre;
                if (list_head != NULL) {
                    list_head->next = NULL;
                }
            }

            if (cnt == right) {
                list_tail = head->next;
                list1_end = head;
                list1_end->next = NULL;

                // do revert
                ListNode *rl = reverseList(list1_start);

                // re-chain
                if (list_head != NULL) {
                    list_head->next = rl;
                } else {
                    // the reverse node is the first node.
                    // need to set rl as result.
                    result = rl;
                }
                list1_start->next = list_tail;

                break;

            }
            node_pre = head;
            head = head->next;
        }

        return result;
    }