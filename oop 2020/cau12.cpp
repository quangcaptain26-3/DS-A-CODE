#include<bits/stdc++.h>

using namespace std;

class ThuVien{
protected:
    int mathe;
    int songaymuon;
    int phimuontheongay;
public:
    ThuVien(){
        mathe = 0;
        songaymuon = 0;
        phimuontheongay = 0;
    }

    ThuVien(int mathe, int songaymuon, int phimuontheongay){
        this->mathe = mathe;
        this->songaymuon = songaymuon;
        this->phimuontheongay = phimuontheongay;
    }

    int getMathe(){
        return mathe;
    }

    void setMathe(int mathe){
        this->mathe = mathe;
    }

    int getSongaymuon(){
        return songaymuon;
    }

    void setSongaymuon(int songaymuon){
        this->songaymuon = songaymuon;
    }

    int getPhimuontheongay(){
        return phimuontheongay;
    }

    void setPhimuontheongay(int phimuontheongay){
        this->phimuontheongay = phimuontheongay;
    }

    virtual float tinhphithemuon(){
        return songaymuon * phimuontheongay;
    }

    virtual void nhap(){
        cout << "Nhap ma the: ";
        cin >> mathe;
        cout << "Nhap so ngay muon: ";
        cin >> songaymuon;
        cout << "Nhap phi muon theo ngay: ";
        cin >> phimuontheongay;
    }

    virtual void xuat(){
        cout << "Ma the: " << mathe << endl;
        cout << "So ngay muon: " << songaymuon << endl;
        cout << "Phi muon theo ngay: " << phimuontheongay << endl;
        cout << "Phi muon: " << tinhphithemuon() << endl;
    }
};

class TheThuVien: public ThuVien{
protected:
    float tilegiamgia;
public:
    TheThuVien(): ThuVien(){
        tilegiamgia = 0;
    }

    TheThuVien(int mathe, int songaymuon, int phimuontheongay, float tilegiamgia): ThuVien(mathe, songaymuon, phimuontheongay){
        this->tilegiamgia = tilegiamgia;
    }

    float getTilegiamgia(){
        return tilegiamgia;
    }

    void setTilegiamgia(float tilegiamgia){
        this->tilegiamgia = tilegiamgia;
    }

    float tinhphithemuon(){
        return songaymuon * phimuontheongay * (1 - tilegiamgia);
    }

    void nhap(){
        ThuVien::nhap();
        cout << "Nhap ti le giam gia: ";
        cin >> tilegiamgia;
    }

    void xuat(){
        ThuVien::xuat();
        cout << "Ti le giam gia: " << tilegiamgia << endl;
    }
};

int main(){
    int n;
    cout << "Nhap so luong the thu vien: ";
    cin >> n;
    ThuVien *a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin the thu vien thu " << i + 1 << endl;
        int loai;
        cout << "Nhap loai the thu vien (1: Thuong, 2: Uu tien): ";
        cin >> loai;
        if(loai == 1){
            a[i] = new ThuVien();
            a[i]->nhap();
        }
        else{
            a[i] = new TheThuVien();
            a[i]->nhap();
        }
    }
    cout << "------------------------------------" << endl;
    cout << "Danh sach the thu vien: " << endl;
    for(int i = 0; i < n; i++){
        cout << "The thu vien thu " << i + 1 << endl;
        a[i]->xuat();
    }

    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i]->getSongaymuon() > 10)
            dem++;
    }
    int k = dem / 10;
    if(dem % 10 != 0)
        k++;
    cout << "------------------------------------" << endl;
    cout << "Danh sach " << k << " the thu vien co phi muon cao nhat va so ngay muon > 10: " << endl;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++)
            if(a[i]->tinhphithemuon() < a[j]->tinhphithemuon())
                swap(a[i], a[j]);
    }
    for(int i = 0; i < k; i++){
        cout << "The thu vien thu " << i + 1 << endl;
        a[i]->xuat();
    }
    return 0;    
    
}

