#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string temp = "";
        int count = 1;
        for (int i = 0; i < word.size(); i++) {
            if (i < word.size() - 1 && word[i] == word[i + 1]) {
                count += 1;
            }
            else {

                if (count <= 9) {
                    temp += to_string(count) + word[i];
                }
                else {
                    for (int j = 0; j < count / 9; j++) {
                        temp += to_string(9) + word[i];
                    }
                    if (count % 9 != 0) {
                        temp += to_string(count % 9) + word[i];
                    }
                }
                count = 1;
            }
        }

        return temp;
    }
};

int main() {
    string word = "abcde";
    cout << Solution().compressedString(word);

    return 0;
}