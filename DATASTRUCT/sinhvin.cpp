#include<bits/stdc++.h>

using namespace std;

class SinhVien{
private:
    string ten;
    int msv;
    float dtb;

public:
    void nhap();
    void xuat();
    float getDTB();
    //array sort ten
    friend void sortTen(SinhVien *sv, int n);

};

void SinhVien::nhap(){
    cout << "Nhap ten: ";
    fflush(stdin);
    getline(cin, ten);
    cout << "Nhap msv: ";
    cin >> msv;
    cout << "Nhap dtb: ";
    cin >> dtb;
}

void SinhVien::xuat(){
    cout << "Ten: " << ten << endl;
    cout << "MSV: " << msv << endl;
    cout << "DTB: " << dtb << endl;
}

float SinhVien::getDTB(){
    return dtb;
}

void sortTen(SinhVien *sv, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(sv[i].ten > sv[j].ten){
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

int main(){
    SinhVien *sv;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    sv = new SinhVien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        sv[i].nhap();
    }
    cout << "Danh sach sinh vien vua nhap: " << endl;
    for(int i = 0; i < n; i++){
        sv[i].xuat();
    }
    cout << "Danh sach sinh vien sau khi sap xep theo ten: " << endl;
    sortTen(sv, n);
    for(int i = 0; i < n; i++){
        sv[i].xuat();
    }
    
    return 0;
}