#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class NV{
private: 
    string hoten;
    float hsl;
    float pc;

public:
    NV(){
        hoten = " ";
        hsl = 0.0;
        pc = 0;
    }

    NV(string hoten, float hsl, float pc){
        this->hoten = hoten;
        this->hsl = hsl;
        this->pc = pc;
    }

    void nhap(){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap he so luong: ";
        cin >> hsl;
        cout << "Nhap phu cap: ";
        cin >> pc;
    }

    void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "He so luong: " << hsl << endl;
        cout << "Phu cap: " << pc << endl;
        cout << "Luong: " << hsl * 1310 + pc << endl;
    }


    float tinhluong(){
        return hsl * 1310 + pc;
    }
};

class CB : public NV{
private:
    float hscv;
public:
    CB() : NV(){
        hscv = 0.0;
    }

    CB(string hoten, float hsl, float pc, float hscv) : NV(hoten, hsl, pc){
        this->hscv = hscv;
    }

    void nhap(){
        NV::nhap();
        cout << "Nhap he so chuc vu: ";
        cin >> hscv;
    }

    void xuat(){
        NV::xuat();
        cout << "He so chuc vu: " << hscv << endl;
    }

    float tinhluong(){
        return NV::tinhluong() * hscv;
    }
};

int main(){
   int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    NV *nv[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        cout << "1. Nhan vien" << endl;
        cout << "2. Can bo" << endl;
        int chon;
        cout << "Nhap lua chon: ";
        cin >> chon;
        if(chon == 1){
            nv[i] = new NV();
            nv[i]->nhap();
        }
        else{
            nv[i] = new CB();
            nv[i]->nhap();
        }
    }
    for(int i = 0; i < n; i++){
        cout << "Thong tin nhan vien thu " << i + 1 << endl;
        nv[i]->xuat();
    }
    float min = nv[0]->tinhluong();
    int index = 0;
    for(int i = 0; i < n; i++){
        if(nv[i]->tinhluong() < min){
            min = nv[i]->tinhluong();
            index = i;
        }
    }
    cout << "Nhan vien co thu nhap thap nhat: " << endl;
    nv[index]->xuat();
    return 0;
}