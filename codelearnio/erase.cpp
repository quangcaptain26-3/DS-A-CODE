#include<bits/stdc++.h>
using namespace std;

string formarString(string input){
    string s = input;
    while (s[0] == ' ')
        s.erase(0, 1);
	while (s[s.length()-1] == ' ')
        s.erase(s.length()-1, 1);
	while (s.find("  ") != -1)
        s.erase(s.find("  "), 1);
    return s;
}

int main(){
    string s;
    cin >> s;
    cout << formarString(s);
    return 0;
}