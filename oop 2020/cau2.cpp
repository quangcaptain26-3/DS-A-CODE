#include<bits/stdc++.h>

using namespace std;

class NhanVien{
protected:
    string hoten;
    float hsl;
    int pc;
public: 
    NhanVien(){
        hoten = "";
        hsl = 0;
        pc = 0;
    }

    NhanVien(string hoten, float hsl, int pc){
        this->hoten = hoten;
        this->hsl = hsl;
        this->pc = pc;
    }


    string getHoten(){
        return hoten;
    }

    void setHoten(string hoten){
        this->hoten = hoten;
    }

    float getHsl(){
        return hsl;
    }

    void setHsl(float hsl){
        this->hsl = hsl;
    }

    int getPc(){
        return pc;
    }

    void setPc(int pc){
        this->pc = pc;
    }

    virtual void nhap(){
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Nhap he so luong: ";
        cin >> hsl;
        cout << "Nhap phu cap: ";
        cin >> pc;
    }

    virtual float tinhluong(){
        return hsl * 1310 + pc;
    }

    virtual void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "He so luong: " << hsl << endl;
        cout << "Phu cap: " << pc << endl;
        cout << "Luong: " << setprecision(2) << fixed << tinhluong() << endl;
    }
};

class CanBo : public NhanVien{
private:
    float hscv;
public:
    CanBo() : NhanVien(){
        hscv = 0;
    }

    CanBo(string hoten, float hsl, int pc, float hscv) : NhanVien(hoten, hsl, pc){
        this->hscv = hscv;
    }

    float getHscv(){
        return hscv;
    }

    void setHscv(float hscv){
        this->hscv = hscv;
    }

    void nhap(){
        NhanVien::nhap();
        cout << "Nhap he so chuc vu: ";
        cin >> hscv;
    }

    float tinhluong(){
        return (hsl + hscv) * 1310 + pc;
    }

    void xuat(){
        NhanVien::xuat();
        cout << "He so chuc vu: " << hscv << endl;
    }
};


int main(){
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    NhanVien *nv[n];
    int loai;
    for(int i = 0; i < n; i++){
        cout << "Nhap loai nhan vien (1: Nhan vien, 2: Can bo): ";
        cin >> loai;
        if(loai == 1){
            nv[i] = new NhanVien();
        }else{
            nv[i] = new CanBo();
        }
        nv[i]->nhap();
    }

    cout << "----------------Danh sach nhan vien----------------" << endl;
    for(int i = 0; i < n; i++){
        nv[i]->xuat();
    }

    float minluong = nv[0]->tinhluong();
    for(int i = 1; i < n; i++){
        if(nv[i]->tinhluong() < minluong){
            minluong = nv[i]->tinhluong();
        }
    }
    cout << "----------------Nhan vien co luong thap nhat----------------" << endl;
    for(int i = 0; i < n; i++){
        if(nv[i]->tinhluong() == minluong && nv[i]->getHsl() < 3){
            nv[i]->xuat();
        }
    }
    return 0;
}