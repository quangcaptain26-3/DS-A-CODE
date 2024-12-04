#include<iostream>

using namespace std;

class SinhVien{
protected:
    string ten;
    int msv;
    float dtb;
public:
    SinhVien(){
        ten = "";
        msv = 0;
        dtb = 0;
    }

    SinhVien(string ten, int msv, float dtb){
        this->ten = ten;
        this->msv = msv;
        this->dtb = dtb;
    }

    ~SinhVien(){
        cout << "Da huy" << endl;
    }

    void nhap(){
        cout << "Nhap ten: ";
        cin >> ten;
        cout << "Nhap ma sinh vien: ";
        cin >> msv;
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
    }

    void xuat(){
        cout << "Danh sach cac sinh vien da nhap" << endl;
        cout << "Ten: " << ten << endl;
        cout << "Ma sinh vien: " << msv << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }

    void sapxep(SinhVien *sv, int n){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(sv[i].dtb > sv[j].dtb){
                    SinhVien temp = sv[i];
                    sv[i] = sv[j];
                    sv[j] = temp;
                }
            }
        }
    }

    //tìm sinh viên có điểm trung bình cao nhất
    SinhVien timSV(SinhVien *sv, int n){
        SinhVien max = sv[0];
        for(int i = 1; i < n; i++){
            if(sv[i].dtb > max.dtb){
                max = sv[i];
            }
        }
        return max;
    }


};


int main(){
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien *sv = new SinhVien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        sv[i].nhap();
    }
    cout << "--------------------------" << endl;
    cout << "Danh sach sinh vien vua nhap" << endl;
    
    for(int i = 0; i < n; i++){
        sv[i].xuat();
    }
    
    cout << "--------------------------" << endl;
    cout << "Sinh vien co diem trung binh cao nhat" << endl;
    SinhVien max = sv->timSV(sv, n);
    max.xuat();
    
    sv->sapxep(sv, n);
    cout << "--------------------------" << endl;
    cout << "Danh sach sinh vien sau khi sap xep" << endl;
    
    for(int i = 0; i < n; i++){
        sv[i].xuat();
    }
    delete[] sv;
    return 0;
}