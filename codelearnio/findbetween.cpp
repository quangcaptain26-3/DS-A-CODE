#include<bits/stdc++.h>

using namespace std;

int commonCount(string s1, string s2){
    vector <int> a(256);
    vector <int> b(256);

    for(int i = 0; i < s1.length(); i++)
        a[s1[i]]++;
    for(int i = 0; i < s2.length(); i++)    
        b[s2[i]]++;
    int d = 0;
    for(int i = 97; i <= 122; i++)
        d += min(a[i], b[i]);
    return d;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << commonCount(s1, s2);
    return 0;
}