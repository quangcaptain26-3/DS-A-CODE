#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class NhanVien{
protected:
    string hoten;
    float hesoluong;
    int phucap;
public:
    NhanVien(string hoten, float hesoluong, int phucap){
        this->hoten = hoten;
        this->hesoluong = hesoluong;
        this->phucap = phucap;
    }

    NhanVien(){
        this->hoten = "";
        this->hesoluong = 0;
        this->phucap = 0;
    }


    string getHoten(){
        return hoten;
    }
    
    void setHoten(string hoten){
        this->hoten = hoten;
    }

    float getHesoluong(){
        return hesoluong;
    }

    void setHesoluong(float hesoluong){
        this->hesoluong = hesoluong;
    }

    int getPhucap(){
        return phucap;
    }

    void setPhucap(int phucap){
        this->phucap = phucap;
    }

    virtual void nhap(){
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Nhap he so luong: ";
        cin >> hesoluong;
        cout << "Nhap phu cap: ";
        cin >> phucap;
    }

    virtual float tinhLuong(){
        return hesoluong * 1310 + phucap;
    }

    virtual float thuong(){
        return 3 * tinhLuong();
    }

    virtual void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "He so luong: " << hesoluong << endl;
        cout << "Phu cap: " << phucap << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
        cout << "Thuong: " << fixed << setprecision(2) << thuong() << endl;
    }
};

class CanBo: public NhanVien{
private:
    int phucapdacbiet;
public:
    CanBo(string hoten, float hesoluong, int phucap, int phucapdacbiet): NhanVien(hoten, hesoluong, phucap){
        this->phucapdacbiet = phucapdacbiet;
    }

    CanBo(): NhanVien(){
        this->phucapdacbiet = 0;
    }

    int getPhucapdacbiet(){
        return phucapdacbiet;
    }

    void setPhucapdacbiet(int phucapdacbiet){
        this->phucapdacbiet = phucapdacbiet;
    }

    virtual void nhap(){
        NhanVien::nhap();
        cout << "Nhap phu cap dac biet: ";
        cin >> phucapdacbiet;
    }

    virtual float tinhLuong(){
        return NhanVien::tinhLuong() + phucapdacbiet;
    }

    virtual float thuong(){
        return 3.5 * tinhLuong();
    }

    virtual void xuat(){
        NhanVien::xuat();
        cout << "Phu cap dac biet: " << phucapdacbiet << endl;
    }
};



int main(){
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    NhanVien *nv[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        int loai;
        cout << "Nhap loai nhan vien (1: Nhan vien, 2: Can bo): ";
        cin >> loai;
        if(loai == 1){
            nv[i] = new NhanVien();
            nv[i]->nhap();
        }
        else{
            nv[i] = new CanBo();
            nv[i]->nhap();
        }
    }
    cout << "------------------------------------------" << endl;
    cout << "Danh sach nhan vien: " << endl;
    for(int i = 0; i < n; i++){
        nv[i]->xuat();
    }


    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(nv[i]->tinhLuong() > nv[j]->tinhLuong()){
                NhanVien *temp = nv[i];
                nv[i] = nv[j];
                nv[j] = temp;
            }
        }
    }

    cout << "------------------------------------------" << endl;
        cout << "Danh sach nhan vien co luong thap nhat va he so luong < 3 de nhan ho tro: " << endl;
        int i = 0, dem = 0;
        while (i < n && dem <= n * 20 / 100)
        {
            if (nv[i]->getHesoluong() < 3.00)
            {
                nv[i]->xuat();
                dem++;
            }
            i++;
        }
    return 0;
}