#include<bits/stdc++.h>
using namespace std;

bool isTandem(string input){
    string s = input;
    if(input.length() % 2 != 0) return false;
    
    if(s.substr(0, input.length() / 2) != s.substr(input.length() / 2, input.length() / 2)) return false;
        return true;
    return false;
}

int main(){
    string s;
    cin >> s;
    cout << isTandem(s);
    return 0;
}