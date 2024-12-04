#include<bits/stdc++.h> 

using namespace std;

class NhanVien{
private:
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

    //tính lương nhân viên
    int tinhLuong(){
        return luongcoban * songaycong;
    }

    //toán tử >>
    friend istream &operator>>(istream &is, NhanVien &nv){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, nv.hoten);
        cout << "Nhap nam sinh: ";
        is >> nv.namsinh;
        cout << "Nhap luong co ban: ";
        is >> nv.luongcoban;
        cout << "Nhap so ngay cong: ";
        is >> nv.songaycong;
        return is;
    }

    //toán tử <<
    friend ostream &operator<<(ostream &os, NhanVien &nv){
        os << "Ho ten: " << nv.hoten << endl;
        os << "Nam sinh: " << nv.namsinh << endl;
        os << "Luong co ban: " << nv.luongcoban << endl;
        os << "So ngay cong: " << nv.songaycong << endl;
        os << "Luong: " << nv.tinhLuong() << endl;
        return os;
    }

    friend class BangLuong;
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
            cout << "Nhap nhan vien thu " << i + 1 << endl;
            cin >> dsnv[i];
        }
    }

    void xuat(){
        for(int i = 0; i < soluongnv; i++){
            cout << "Nhan vien thu " << i + 1 << endl;
            cout << dsnv[i];
        }
    }
    
    //hàm friend tìm nhân viên có lương dưới 5 triệu
    friend void timNhanVien(BangLuong &bl);
};

void timNhanVien(BangLuong &bl){
    for(int i = 0; i < bl.soluongnv; i++){
        if(bl.dsnv[i].tinhLuong() < 5000000){
            cout << "Nhan vien co luong duoi 5 trieu: " << endl;
            cout << bl.dsnv[i];
        }
    }
}

int main(){
    BangLuong bl;
    bl.nhap();
    bl.xuat();
    timNhanVien(bl);
    return 0;
}