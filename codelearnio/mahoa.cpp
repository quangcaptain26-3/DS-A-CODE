#include<bits/stdc++.h>
using namespace std;

string toString(int n){
    string s = "";
    while(n > 0){
        s = char(n % 10 + '0') + s;
        n /= 10;    
    }
    return s;
}

string lineCode(string s){
    string res = "";
    int count = 1;
    s = s + " ";
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i + 1]) count++;
        else{
            res = res + toString(count) + s[i];
            count = 1;
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    cout << lineCode(s);
    return 0;
}