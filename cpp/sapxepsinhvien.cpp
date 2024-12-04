#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class SinhVien{
private:
    string ten;
    int msv;
    float dtb;
public:
    SinhVien(){
        ten = "";
        msv = 0;
        dtb = 0;
    }

    ~SinhVien(){
        cout << "Da huy doi tuong"  << endl;
    }

    SinhVien(string ten, int msv, float dtb){
        this->ten = ten;
        this->msv = msv;
        this->dtb = dtb;
    }

    void nhap(){
        cout << "Nhap ten sinh vien: " << endl;
        cin.ignore();
        getline(cin, ten);
        cout << "Nhap ma sinh vien: " << endl;
        cin >> msv;
        cout << "Nhap diem trung binh: " << endl;
        cin >> dtb;
    }

    void xuat(){
        cout << "Ten sinh vien: " << ten << endl;
        cout << "Ma sinh vien: " << msv << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }   


    //Tìm sinh viên có điểm trung bình lớn nhất
    bool operator>(const SinhVien& b){
        return dtb > b.dtb;
    }

};

int main(){
    cout << "Danh sach sinh vien: " << endl;
    int n;
    cout << "Nhap so luong sinh vien: " << endl;
    cin >> n;
    SinhVien* sv = new SinhVien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        sv[i].nhap();
    }

    cout << "Thong tin sinh vien: " << endl;
    for(int i = 0; i < n; i++){
        sv[i].xuat();
    }

    SinhVien max = sv[0];
    for(int i = 1; i < n; i++){
        if(sv[i] > max){
            max = sv[i];
        }
    }

    cout << "Sinh vien co diem trung binh cao nhat: " << endl;
    max.xuat();

    delete[] sv;
    return 0;
}