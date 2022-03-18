// https://leetcode.com/problems/gas-station/discuss/1705957/Java-A-very-detailed-explanation-or-Intuition-behind-logic-or-Brute-Force-to-Optimised
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total_cost = 0;
		int total_gas = 0;
		for (int i = 0; i < gas.size(); i++) {
			total_cost += cost[i];
			total_gas += gas[i];
		}
		// if the cost > gas, no way to complete
		if (total_cost > total_gas) {
			return -1;
		}

		// find the start position
		int start = 0;
		int x = 0;
		int i = 0;
		for (int i = 0; i < gas.size(); i++) {
			x = x + gas[i] - cost[i];
			if (x < 0) {
				start = i + 1;
				x = 0;
			}
		}
		return start;
	}
};