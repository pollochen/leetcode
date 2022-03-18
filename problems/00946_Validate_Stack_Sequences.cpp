class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> stk;

		int idx_push = 0;
		int idx_pop = 0;
		stk.push(pushed[idx_push++]);
		while (idx_pop < popped.size() && idx_push < pushed.size()) {
			while ((stk.empty() == false) && (stk.top() == popped[idx_pop])) {
				stk.pop();
				idx_pop++;
			}
			stk.push(pushed[idx_push++]);
		}

		while ((stk.empty() == false) && (stk.top() == popped[idx_pop])) {
			stk.pop();
			idx_pop++;
		}

		if (stk.empty() == true) {
			return true;
		} else {
			return false;
		}        
    }
};

void test_00946_Validate_Stack_Sequences(void)
{
	Solution s;
	printf("%d\n", s.validateStackSequences(vector<int>{1, 2, 3, 4, 5}, vector<int>{4, 5, 3, 2, 1}));
	printf("%d\n", s.validateStackSequences(vector<int>{1, 2, 3, 4, 5}, vector<int>{4, 3, 5, 1, 2}));
}