#include<bits/stdc++.h>

using namespace std;

class NhanVien{
protected:
    string hoten;
    int namsinh;
    int luongcoban;
    int songaycong;
public:
    NhanVien(){
        hoten = "";
        namsinh = 0;
        luongcoban = 0;
        songaycong = 0;
    }

    NhanVien(string hoten, int namsinh, int luongcoban, int songaycong){
        this->hoten = hoten;
        this->namsinh = namsinh;
        this->luongcoban = luongcoban;
        this->songaycong = songaycong;
    }

    ~NhanVien(){
        cout << "Da huy nhan vien " << hoten << endl;
    }

    void nhap(){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap nam sinh: ";
        cin >> namsinh;
        cout << "Nhap luong co ban: ";
        cin >> luongcoban;
        cout << "Nhap so ngay cong: ";
        cin >> songaycong;
    }

    void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Nam sinh: " << namsinh << endl;
        cout << "Luong co ban: " << luongcoban << endl;
        cout << "So ngay cong: " << songaycong << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }

    int tinhLuong(){
        return luongcoban * songaycong;
    }
};


class BangLuong{
private:
    int soluongnv;
    NhanVien *dsnv;
public:
    BangLuong(){
        soluongnv = 0;
        dsnv = NULL;
    }

    ~BangLuong(){
        delete[] dsnv;
    }

    void nhap(){
        cout << "Nhap so luong nhan vien: ";
        cin >> soluongnv;
        dsnv = new NhanVien[soluongnv];
        for(int i = 0; i < soluongnv; i++){
            cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
            dsnv[i].nhap();
        }
    }

    void xuat(){
        for(int i = 0; i < soluongnv; i++){
            cout <<"------------------------------------\n" << endl;
            cout << "Thong tin nhan vien thu " << i + 1 << endl;
            dsnv[i].xuat();
        }
    }

    void thongke(){
        for(int i = 0; i < soluongnv; i++){
            if(dsnv[i].tinhLuong() < 5000000){
                cout <<"------------------------------------\n" << endl;
                cout << "Nhan vien co luong thap hon 5 trieu:" << endl;
                cout << "Thong tin nhan vien thu " << i + 1 << endl;
                dsnv[i].xuat();
            }
        }
    }
};

int main(){
    BangLuong a;
    a.nhap();
    a.xuat();
    a.thongke();
    return 0;
}