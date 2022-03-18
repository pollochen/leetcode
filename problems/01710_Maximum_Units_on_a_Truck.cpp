bool compareInterval(vector<int> i1, vector<int> i2)
{
	return (i1[1] > i2[1]);
}
class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		int result = 0;
		sort(boxTypes.begin(), boxTypes.end(), compareInterval);
		int idx = 0;
		while ((truckSize != 0) && (idx < boxTypes.size())) {
			if (boxTypes[idx][0] > 0) {
				result += boxTypes[idx][1];
				boxTypes[idx][0]--;
			}
			if (boxTypes[idx][0] == 0) idx++;
			truckSize--;
		}
		return result;
	}
};