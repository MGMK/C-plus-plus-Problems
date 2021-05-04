#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string word) {
    int n = word.size();
    if (n % 2 != 0)
        word.erase(0, 1);

    stack<char> s;
    for (int i = 0; i < n / 2; i++) {
        s.push(word[i]);
        word.erase(i, 1);
    }
    /// if Stack is Empty End function and this word will be palindrome .
    if (s.empty())
        return true;

    /// compare the Top Element in stack With First Element in word to check palindrome .
    while (n != 0){ /// Stack is not Empty .
        if (s.top() == word[0]) {
            s.pop();
            word.erase(0, 1);

            /// return true only when our stack is empty
            if (s.empty())
                return true;
        }
        else  /// if one char in stack not equal one char in word this word will not palindrome .
            return false;
    }
}

int main(){
    string str;
    cout << "Enter Your String :";
    cin >> str;

    if(isPalindrome(str) )
        cout << "This Word is Palindrome.\n";
    else
        cout << "This Word is not Palindrome.\n";
}
