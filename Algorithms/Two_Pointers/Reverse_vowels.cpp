// Problem: Reverse Vowels of a String (Two Pointers)

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        return true;
    } else {
        return false;
    }
}

int main() {
    string str;
    cin >> str;
    
    int n = str.length();
    int i = 0;
    int j = n - 1;
    
    while (i < j) {
        if (!isVowel(str[i])) {
            i++;
        } else if (!isVowel(str[j])) {
            j--;
        } else {
            swap(str[i], str[j]);
            i++;
            j--; 
        }
    }
    
    cout << str << "\n"; 
    
    return 0;
}