class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int result = 0;
        vector<int> num_in_ages(121);
        vector<int> sum_in_ages(121);
        sum_in_ages[0] = 0;
        for (int i = 0; i < ages.size(); i++) num_in_ages[ages[i]]++;
        for (int i = 1; i < 121; i++) sum_in_ages[i] = sum_in_ages[i-1] + num_in_ages[i];
        for (int i = 15; i < 121; i++) {
            int count = sum_in_ages[i] - sum_in_ages[i/2+7];
            result += ((count * num_in_ages[i]) - num_in_ages[i]);
        }
        return result;
    }
};