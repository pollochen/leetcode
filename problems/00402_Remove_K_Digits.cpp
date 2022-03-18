class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int res_size = num.length() - k;
        for (int i = 0; i < num.length(); i++) {
            while ((k != 0) && (res.length() > 0) && res.back() > num[i]) {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }

        res = res.substr(0, res_size);
        // remove leading 0
        while ((res.empty() == false) && (res[0] == '0')) {
            res.erase(res.begin());
        }
        // check empty
        if (res.empty() == true) return "0";
        else return res;
    }
};