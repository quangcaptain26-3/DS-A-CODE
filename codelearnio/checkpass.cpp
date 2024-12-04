#include<bits/stdc++.h>
using namespace std;

bool checkStrongPassword(string password) {

  if (password.length() < 6) {
    cout << "Vui long nhap du 6 ky tu\n";
    return false;
  }


  string p = "!@#$%^&*()-+";
  string s = password;

  bool kt1 = false;  // Có ký tự chữ in hoa
  bool kt2 = false;  // Có ký tự chữ thường
  bool kt3 = false;  // Có ký tự số
  bool kt4 = false;  // Có ký tự đặc biệt

  for (int i = 0; i < password.length(); i++) {
    if (s[i] >= 65 && s[i] <= 90) {
      kt1 = true;
    } else if (s[i] >= 97 && s[i] <= 122) {
      kt2 = true;
    } else if (s[i] >= 48 && s[i] <= 57) {
      kt3 = true;
    } else if (p.find(s[i]) != -1) {
      kt4 = true;
    }
  }


  if (!kt1 || !kt2 || !kt3 || !kt4) {
    cout << "Mat khau khong du manh, vui long nhap lai mat khau\n";
    return false;
  }

  cout << "Mat khau manh\n";
  return true;
}

int main(){
    cout <<"Nhap mat khau:";
    string s;
    cin >> s;
    cout << checkStrongPassword(s);
    return 0;
}