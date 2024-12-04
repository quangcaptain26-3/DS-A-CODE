#include<bits/stdc++.h>

using namespace std;

class Hang{
private:
    string tenhang;
    int mahang;
    float giaban;
public:
    Hang(){
        tenhang = "";
        mahang = 0;
        giaban = 0;
    }

    Hang(string tenhang, int mahang, float giaban){
        this->tenhang = tenhang;
        this->mahang = mahang;
        this->giaban = giaban;
    }

    void nhap(){
        cout << "Ten hang: ";
        cin.ignore();
        getline(cin, tenhang);
        cout << "Ma hang: ";
        cin >> mahang;
        cout << "Gia ban: ";
        cin >> giaban;
    }

    void xuat(){
        cout << "Ten hang: " << tenhang << endl;
        cout << "Ma hang: " << mahang << endl;
        cout << "Gia ban: " << giaban << endl;
    }

    friend class KhachHang;
};

class KhachHang{
private:
    string hoten;
    int ma;
    int sosanpham;
    Hang *a;
public:
    KhachHang(){
        hoten = "";
        ma = 0;
        sosanpham = 0;
        a = NULL;
    }

    KhachHang(string hoten, int ma, int sosanpham, Hang *a){
        this->hoten = hoten;
        this->ma = ma;
        this->sosanpham = sosanpham;
        this->a = a;
    }

    void nhap(){
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Ma: ";
        cin >> ma;
        cout << "So san pham: ";
        cin >> sosanpham;
        a = new Hang[sosanpham];
        for(int i = 0; i < sosanpham; i++){
            cout << "Nhap san pham thu " << i + 1 << endl;
            a[i].nhap();
        }
    }

    void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Ma: " << ma << endl;
        cout << "So san pham: " << sosanpham << endl;
        for(int i = 0; i < sosanpham; i++){
            cout << "San pham thu " << i + 1 << endl;
            a[i].xuat();
        }
    }

    friend void max(KhachHang[], int);
};

void max(KhachHang a[], int n){
    KhachHang max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i].sosanpham > max.sosanpham){
            max = a[i];
        }
    }
    max.xuat();
}

int main(){
    KhachHang *a;
    int n;
    cin >> n;
    a = new KhachHang[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap khach hang thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "Danh sach khach hang: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Khach hang thu " << i + 1 << endl;
        a[i].xuat();
    }

    cout << "Khach hang mua nhieu san pham nhat: " << endl;
    max(a, n);
    return 0;
}



