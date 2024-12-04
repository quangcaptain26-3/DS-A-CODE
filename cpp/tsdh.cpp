#include<iostream>
#include<string.h>
#include<vector>
#include<iomanip>

using namespace std;

class NhanVien{
private:
    string hoten;
    int namsinh;
    float luongcoban;
    int songaycong;
public:
    NhanVien(){
        hoten = " ";
        namsinh = 0;
        luongcoban = 0.0;
        songaycong = 0;
    }

    ~NhanVien(){
        cout << "Da huy doi tuong" << endl;
    }

    NhanVien(string hoten, int namsinh, float luongcoban, int songaycong){
        this->hoten = hoten;
        this->namsinh = namsinh;
        this->luongcoban = luongcoban;
        this->songaycong = songaycong;
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
      
        cout << fixed << setprecision(2) << "Luong co ban: " << luongcoban << endl;
        cout << "So ngay cong: " << songaycong << endl;
    }

    float tinhluong(){
        return luongcoban * songaycong;
    }
};

class BangLuong : public NhanVien{
private:
    int soluong;
    vector<NhanVien> dsnv;
public:
    BangLuong() : NhanVien(){
        soluong = 0;
    }

    BangLuong(string hoten, int namsinh, float luongcoban, int songaycong, int soluong) : NhanVien(hoten, namsinh, luongcoban, songaycong){
        this->soluong = soluong;
    }

    void nhap(){
        cout << "Nhap so luong nhan vien: ";
        cin >> soluong;
        for(int i = 0; i < soluong; i++){
            NhanVien nv;
            nv.nhap();
            dsnv.push_back(nv);
        }
    }

    void xuat(){
        for(int i = 0; i < soluong; i++){
            dsnv[i].xuat();
        }
    }

    void sapxep(){
        for(int i = 0; i < soluong - 1; i++){
            for(int j = i + 1; j < soluong; j++){
                if(dsnv[i].tinhluong() < dsnv[j].tinhluong()){
                    NhanVien temp = dsnv[i];
                    dsnv[i] = dsnv[j];
                    dsnv[j] = temp;
                }
            }
        }
    }

 
    void luongthapnhat(){
        float min = dsnv[0].tinhluong();
        for(int i = 1; i < soluong; i++){
            if(dsnv[i].tinhluong() < min){
                min = dsnv[i].tinhluong();
            }
        }
        for(int i = 0; i < soluong; i++){
            if(dsnv[i].tinhluong() == min){
                dsnv[i].xuat();
            }
        }
    }
};

int main(){
    cout << "Nhap thong tin bang luong: " << endl;
    BangLuong a;
    a.nhap();
    a.xuat();
    a.sapxep();
    cout << "Danh sach nhan vien sau khi sap xep: " << endl;
    a.xuat();
    cout << "Nhan vien co luong thap nhat: " << endl;
    a.luongthapnhat();
    return 0;
}


