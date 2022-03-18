typedef struct {
	int min;
	int buffer[100000];
	int idx;
} MinStack;


MinStack* minStackCreate() {
	MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
	stack->idx = 0;
	stack->min = INT_MAX;
	return stack;
}

void minStackPush(MinStack* obj, int val) {
	if (val <= obj->min) {
		// push 2nd min first
		obj->buffer[obj->idx] = obj->min;
		obj->idx++;
		// set min value
		obj->min = val;
	}
	// push value
	obj->buffer[obj->idx] = val;
	obj->idx++;
}

void minStackPop(MinStack* obj) {
	int val = obj->buffer[obj->idx-1];
	obj->idx--;
	if (val == obj->min) {
		// pop min value, need to recover 2nd min
		obj->min = obj->buffer[obj->idx - 1];
		obj->idx--;
	}
}

int minStackTop(MinStack* obj) {
	return obj->buffer[obj->idx-1];
}

int minStackGetMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj);
}

/**
* Your MinStack struct will be instantiated and called as such:
* MinStack* obj = minStackCreate();
* minStackPush(obj, val);

* minStackPop(obj);

* int param_3 = minStackTop(obj);

* int param_4 = minStackGetMin(obj);

* minStackFree(obj);
*/