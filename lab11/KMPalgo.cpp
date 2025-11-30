#include <iostream>
#include <string>
using namespace std;

void computeLPS(const string &pattern, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];  // go back
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    int *lps = new int[m];
    computeLPS(pattern, m, lps);

    int i = 0;  // text pointer
    int j = 0;  // pattern pointer

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        // match found
        if (j == m) {
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    delete [] lps;
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    KMP(text, pattern);

    return 0;
}
