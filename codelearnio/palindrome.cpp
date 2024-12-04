#include<bits/stdc++.h>
using namespace std;

bool checkPalind(string inputString){
    for(int i = 0; i < inputString.length()/2; i++){
        if(inputString[i] != inputString[inputString.length()-1-i])
            return false;
    }

    return true;
}

int main(){
    string inputString;
    cin >> inputString;

    cout << checkPalind(inputString) << endl;
    return 0;
}