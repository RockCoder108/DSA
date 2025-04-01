class Solution {
public:
    int minMaxDifference(int num) {
    string s = to_string(num);

    string maxStr = s;
    for (char &c : maxStr) {
        if (c != '9') {
            char target = c;
            for (char &x : maxStr) {
                if (x == target) x = '9';
            }
            break;
        }
    }

    string minStr = s;
    char target = minStr[0]; // First digit
    for (char &x : minStr) {
        if (x == target) x = '0';
    }

    return stoi(maxStr) - stoi(minStr);
}

};