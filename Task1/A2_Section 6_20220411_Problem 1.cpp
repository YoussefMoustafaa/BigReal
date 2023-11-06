#include <bits/stdc++.h>

using namespace std;

class OneSentence {
private:
    string s;
public:
    void getSentence() {
        getline(cin, s, '.');
    }
    string fixSentence() {
        string new_string;
        int first_index = 0;

        while (s[first_index] == ' ')
            first_index++;

        if (islower(s[first_index]))
            s[first_index] = (char) toupper(s[first_index]);

        new_string += s[first_index];
        first_index++;

        for (int i = first_index; i < s.length(); ++i) {
            if (s[i] == ' ' && s[i-1] == ' ')
                continue;
            else if (s[i] == ' ' || s[i] == '\n')
                new_string += ' ';
            else if (isupper(s[i]))
                new_string += (char) tolower(s[i]);
            else
                new_string += s[i];

        }
        new_string += '.';
        return new_string;
    }
};



int main() {

    OneSentence str;
    str.getSentence();
    cout << str.fixSentence();

    return 0;
}