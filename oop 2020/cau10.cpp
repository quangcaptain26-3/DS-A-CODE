#include<bits/stdc++.h>

using namespace std;    

class BenhNhan{
protected:
    string hoten;
    int mahoso;
    int namsinh;
    string chuandoanbenh;
    string tenkhoadieutri;
public:
    BenhNhan(){
        hoten = "";
        mahoso = 0;
        namsinh = 0;
        chuandoanbenh = "";
        tenkhoadieutri = "";
    }

    BenhNhan(string hoten, int mahoso, int namsinh, string chuandoanbenh, string tenkhoadieutri){
        this->hoten = hoten;
        this->mahoso = mahoso;
        this->namsinh = namsinh;
        this->chuandoanbenh = chuandoanbenh;
        this->tenkhoadieutri = tenkhoadieutri;
    }

    string getHoten(){
        return hoten;
    }

    void setHoten(string hoten){
        this->hoten = hoten;
    }

    int getMahoso(){
        return mahoso;
    }

    void setMahoso(int mahoso){
        this->mahoso = mahoso;
    }

    int getNamsinh(){
        return namsinh;
    }

    void setNamsinh(int namsinh){
        this->namsinh = namsinh;
    }

    string getChuandoanbenh(){
        return chuandoanbenh;
    }

    void setChuandoanbenh(string chuandoanbenh){
        this->chuandoanbenh = chuandoanbenh;
    }

    string getTenkhoadieutri(){
        return tenkhoadieutri;
    }

    void setTenkhoadieutri(string tenkhoadieutri){
        this->tenkhoadieutri = tenkhoadieutri;
    }

    virtual void nhap(){
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Nhap ma ho so: ";
        cin >> mahoso;
        cout << "Nhap nam sinh: ";
        cin >> namsinh;
        cout << "Nhap chuan doan benh: ";
        fflush(stdin);
        getline(cin, chuandoanbenh);
        cout << "Nhap ten khoa dieu tri: ";
        fflush(stdin);
        getline(cin, tenkhoadieutri);
    }

    virtual void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Ma ho so: " << mahoso << endl;
        cout << "Nam sinh: " << namsinh << endl;
        cout << "Chuan doan benh: " << chuandoanbenh << endl;
        cout << "Ten khoa dieu tri: " << tenkhoadieutri << endl;
    }
};

class NoiTru: public BenhNhan{
protected: 
    int maphong;
    int sogiuong;
public:     
    NoiTru(): BenhNhan(){
        maphong = 0;
        sogiuong = 0;
    }

    NoiTru(string hoten, int mahoso, int namsinh, string chuandoanbenh, string tenkhoadieutri, int maphong, int sogiuong): BenhNhan(hoten, mahoso, namsinh, chuandoanbenh, tenkhoadieutri){
        this->maphong = maphong;
        this->sogiuong = sogiuong;
    }

    int getMaphong(){
        return maphong;
    }

    void setMaphong(int maphong){
        this->maphong = maphong;
    }

    int getSogiuong(){
        return sogiuong;
    }

    void setSogiuong(int sogiuong){
        this->sogiuong = sogiuong;
    }

    void nhap(){
        BenhNhan::nhap();
        cout << "Nhap ma phong: ";
        cin >> maphong;
        cout << "Nhap so giuong: ";
        cin >> sogiuong;
    }

    void xuat(){
        BenhNhan::xuat();
        cout << "Ma phong: " << maphong << endl;
        cout << "So giuong: " << sogiuong << endl;
    }
};

class NgoaiTru: public BenhNhan{
protected:
    string donthuoc;
public:
    NgoaiTru(): BenhNhan(){
        donthuoc = "";
    }

    NgoaiTru(string hoten, int mahoso, int namsinh, string chuandoanbenh, string tenkhoadieutri, string donthuoc): BenhNhan(hoten, mahoso, namsinh, chuandoanbenh, tenkhoadieutri){
        this->donthuoc = donthuoc;
    }

    string getDonthuoc(){
        return donthuoc;
    }

    void setDonthuoc(string donthuoc){
        this->donthuoc = donthuoc;
    }

    void nhap(){
        BenhNhan::nhap();
        cout << "Nhap don thuoc: ";
        fflush(stdin);
        getline(cin, donthuoc);
    }

    void xuat(){
        BenhNhan::xuat();
        cout << "Don thuoc: " << donthuoc << endl;
    }
};

int main(){
    int n;
    cout << "Nhap so luong benh nhan: ";
    cin >> n;
    BenhNhan *a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin benh nhan thu " << i + 1 << endl;
        int loai;
        cout << "Nhap loai benh nhan (1: Noi tru, 2: Ngoai tru): ";
        cin >> loai;
        if(loai == 1){
            a[i] = new NoiTru();
            a[i]->nhap();
        }
        else{
            a[i] = new NgoaiTru();
            a[i]->nhap();
        }
    }
    cout << "------------------------------------" << endl;
    cout << "Danh sach benh nhan: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Benh nhan thu " << i + 1 << endl;
        a[i]->xuat();
    }

    //sắp xếp theo mã hồ sơ
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++)
            if(a[i]->getMahoso() > a[j]->getMahoso())
                swap(a[i], a[j]);
    }
    cout << "------------------------------------" << endl;
    cout << "Danh sach benh nhan sau khi sap xep: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Benh nhan thu " << i + 1 << endl;
        a[i]->xuat();
    }
    return 0;
}