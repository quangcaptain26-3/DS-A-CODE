#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

class TheThuVien{
protected:
    int ma;
    int songaymuon;
    int phimuon = 5000; // 5000 VND/ngay

public:
    TheThuVien(int ma, int songaymuon){
        this->ma = ma;
        this->songaymuon = songaymuon;
    }

    virtual int tinhTien(){
        return songaymuon * phimuon;
    }

    virtual void nhap(){
        cout << "Nhap ma the: ";
        cin >> ma;
        cout << "Nhap so ngay muon: ";
        cin >> songaymuon;
    }

    virtual void xuat(){
        cout << "Ma the: " << ma << endl;
        cout << "So ngay muon: " << songaymuon << endl;
        cout << "Phi muon: " << phimuon << endl;
    }
};

class TheUuTien : public TheThuVien{
private:
    float tilegiamgia;

public:
    TheUuTien(int ma, int songaymuon, float tilegiamgia) : TheThuVien(ma, songaymuon){
        this->tilegiamgia = tilegiamgia;
    }

    int tinhTien(){
        return songaymuon * phimuon * (1 - tilegiamgia);
    }

    void nhap(){
        TheThuVien::nhap();
        cout << "Nhap ti le giam gia: ";
        cin >> tilegiamgia;
    }

    void xuat(){
        TheThuVien::xuat();
        cout << "Ti le giam gia: " << tilegiamgia << endl;
    }
};


int main(){
    TheThuVien *a[100];
    int n;
    cout << "Nhap so luong the: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Nhap the thu " << i + 1 << endl;
        int loai;
        cout << "Nhap loai the (1: thuong, 2: uu tien): ";
        cin >> loai;
        if(loai == 1){
            a[i] = new TheThuVien(0, 0);
            a[i]->nhap();
        }
        else{
            a[i] = new TheUuTien(0, 0, 0);
            a[i]->nhap();
        }
    }

    cout << "Danh sach the thu vien" << endl;
    for(int i = 0; i < n; i++){
        cout << "The thu " << i + 1 << endl;
        a[i]->xuat();
        cout << "Tien phai tra: " << a[i]->tinhTien() << endl;
    }

    cout << "Danh sach 10% the co phi muon cao nhat va so ngay muon > 10" << endl;
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i]->tinhTien() > 10 && a[i]->tinhTien() > a[i + 1]->tinhTien()){
            dem++;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i]->tinhTien() > 10 && a[i]->tinhTien() > a[i + 1]->tinhTien()){
            a[i]->xuat();
            cout << "Tien phai tra: " << a[i]->tinhTien() << endl;
        }
    }

    return 0;
}