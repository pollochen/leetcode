
typedef struct {
	int *buffer;
	int size;
	int num;
	int flag_static;
} IntStack;

IntStack *IntStackCreate(int Num, int *Buffer)
{
	IntStack *ret = (IntStack *)malloc(sizeof(IntStack));
	if (Buffer == NULL) {
		ret->buffer = (int *)malloc(sizeof(int) * Num);
		ret->flag_static = 0;
	} else {
		ret->buffer = Buffer;
		ret->flag_static = 1;
	}
	ret->num = Num;
	ret->size = 0;
	return ret;
}

bool IntStacKIsEmpty(IntStack *Stk)
{
	if (Stk->size == 0) return true;
	else return false;
}

int IntStackTop(IntStack *Stk)
{
	if (Stk->size > 0) {
		return Stk->buffer[Stk->size - 1];
	} else {
		return 0;
	}
}

void IntStackPop(IntStack *Stk)
{
	if (Stk->size > 0) {
		Stk->size--;
	}
}

void IntStackPush(IntStack *Stk, int Value)
{
	Stk->size++;
	Stk->buffer[Stk->size - 1] = Value;
}

void IntStackFree(IntStack *Stk)
{
	if (Stk->flag_static == 0) {
		free(Stk->buffer);
	}
	free(Stk);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int buffer_1[200];
	int buffer_2[200];
	int buffer_3[200];
	IntStack *stk_1 = IntStackCreate(200, buffer_1);
	IntStack *stk_2 = IntStackCreate(200, buffer_2);
	IntStack *stk_3 = IntStackCreate(200, buffer_3);

	while ((l1 != NULL || l2 != NULL)) {
		if (l1 != NULL) {
			IntStackPush(stk_1, l1->val);
			l1 = l1->next;
		}
		if (l2 != NULL) {
			IntStackPush(stk_2, l2->val);
			l2 = l2->next;
		}
	}

	int flag_carry = 0;

	while ((IntStacKIsEmpty(stk_1) == false) || IntStacKIsEmpty(stk_2) == false) {
		int val = flag_carry;
		if (IntStacKIsEmpty(stk_1) == false) {
			val += IntStackTop(stk_1);
			IntStackPop(stk_1);
		}
		if (IntStacKIsEmpty(stk_2) == false) {
			val += IntStackTop(stk_2);
			IntStackPop(stk_2);
		}

		flag_carry = val / 10;
		val = val % 10;

		// push
		IntStackPush(stk_3, val);
	}

	if (flag_carry > 0) {
		IntStackPush(stk_3, 1);
	}    
    
	struct ListNode *node_root = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node_cur = node_root;

	while (IntStacKIsEmpty(stk_3) == false) {
		struct ListNode *node_new = (struct ListNode *)malloc(sizeof(struct ListNode));
		node_new->val = IntStackTop(stk_3);
		node_new->next = NULL;
		IntStackPop(stk_3);
		node_cur->next = node_new;
		node_cur = node_new;
	}

	IntStackFree(stk_1);
	IntStackFree(stk_2);
	IntStackFree(stk_3);
	return node_root->next;
}