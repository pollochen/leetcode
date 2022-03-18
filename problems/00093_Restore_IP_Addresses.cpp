class Solution {
public:
    bool is_valid_ip_number(string &s)
    {
        int len = s.length();
        if (len == 1) {
            // valid: '0' ~ '9'
            return true;
        } else if (len == 2) {
            // valid: '1' ~ '99'
            if (s[0] == '0') return false; // '0X'
            return true;
        } else if (len == 3) {
            // vaild '100' ~ '255'
            if (s[0] == '0' || s[0] > '2') return false; // '0XX' or '3XX'
            if (s[0] == '2') {
                if (s[1] > '5') {
                    return false;
                } else if (s[1] == '5' && s[2] > '5') {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }
    void restoreIpAddressesX(string &s, int pos_start, string out, int count, vector<string> &result)
    {
        if (count == 0) {
            if (pos_start == s.length()) {
                // for nums and end of string
                result.push_back(out);
            }
            return;
        }

        int length = s.length() - pos_start;
        if (((length - count) < 0) || (length > (count * 3))) {
            return;
        }

        int min_len = min(length, 3);
        for (int i = 1; i <= min_len; i++) {
            string sub_str = s.substr(pos_start, i);
            if (is_valid_ip_number(sub_str) == true) {
                if (count == 1) {
                    restoreIpAddressesX(s, pos_start + i, out + sub_str, count-1, result);
                } else {
                    restoreIpAddressesX(s, pos_start + i, out + sub_str + ".", count-1, result);
                }
            }
            if (sub_str[0] == '0') break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string out;
        restoreIpAddressesX(s, 0, out, 4, result);
        return result;
    }
};

void print_vector_string(vector<string> &vec)
{
    printf("[\n");
    for (int i = 0; i < vec.size(); i++) {
        printf("    %s,\n", vec[i].c_str());
    }
    printf("]\n");
}

void test_00093_Restore_IP_Addresses(void)
{
    Solution s;

    print_vector_string(s.restoreIpAddresses("000256"));
    print_vector_string(s.restoreIpAddresses("172162541"));
    print_vector_string(s.restoreIpAddresses("010010"));
    print_vector_string(s.restoreIpAddresses("25525511135"));
    print_vector_string(s.restoreIpAddresses("0000"));
    print_vector_string(s.restoreIpAddresses("101023"));
}