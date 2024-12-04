#include<iostream>
#include<string.h>

using namespace std;

class Thuoc{
private:
    string TenThuoc;
    int MaThuoc;
    int SoLuong;
    float Giaban;
public:
 ~Thuoc(){
    cout << "Da huy doi tuong" << endl;
 }

 Thuoc(){
    TenThuoc = " ";
    MaThuoc = 0;
    SoLuong = 0;
    Giaban = 0.0;
 }

 Thuoc(string TenThuoc, int MaThuoc, int SoLuong, float Giaban){
    this->TenThuoc = TenThuoc;
    this->MaThuoc = MaThuoc;
    this->SoLuong = SoLuong;
    this->Giaban = Giaban;
 }

 void nhap(){
    cout << "Nhap ten thuoc: ";
    cin.ignore();
    getline(cin, TenThuoc);
    cout << "Nhap ma thuoc: ";
    cin >> MaThuoc;
    cout << "Nhap so luong: ";
    cin >> SoLuong;
    cout << "Nhap gia ban: ";
    cin >> Giaban;
 }

 void xuat(){
    cout << "Ten thuoc: " << TenThuoc << endl;
    cout << "Ma thuoc: " << MaThuoc << endl;
    cout << "So luong: " << SoLuong << endl;
    cout << "Gia ban: " << Giaban << endl;
 }

 
    void sapxep(Thuoc *a, int n){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i].TenThuoc > a[j].TenThuoc){
                    Thuoc temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
};

int main(){
    int n;
    cout << "Nhap so luong thuoc: ";
    cin >> n;
    Thuoc *a = new Thuoc[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin thuoc thu " << i + 1 << endl;
        a[i].nhap();
    }

    cout << "Danh sach thuoc vua nhap: " << endl;
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }

    cout << "Danh sach thuoc sau khi sap xep: " << endl;
    a[0].sapxep(a, n);
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }

    delete[] a;
    return 0;
}
