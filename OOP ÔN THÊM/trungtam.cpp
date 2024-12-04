#include<bits/stdc++.h>

using namespace std;

class HocVien{
private:
    int mahv;
    string hoten;
    string lop;
    float diemdauvao;
public:
    //hàm tạo mặc định
    HocVien(){
        mahv = 0;
        hoten = "";
        lop = "";
        diemdauvao = 0;
    }

    //hàm tạo có tham số
    HocVien(int mahv, string hoten, string lop, float diemdauvao){
        this->mahv = mahv;
        this->hoten = hoten;
        this->lop = lop;
        this->diemdauvao = diemdauvao;
    }

    //quá tải toán tử nhập
    friend istream &operator>>(istream &is, HocVien &hv){
        cout << "Nhap ma hoc vien: ";
        is >> hv.mahv;
        cout << "Nhap ho ten: ";
        is.ignore();
        getline(is, hv.hoten);
        cout << "Nhap lop: ";
        is.ignore();
        getline(is, hv.lop);
        cout << "Nhap diem dau vao: ";
        is >> hv.diemdauvao;
        return is;
    }

    //quá tải toán tử xuất
    friend ostream &operator<<(ostream &os, HocVien &hv){
        os << "Ma hoc vien: " << hv.mahv << endl;
        os << "Ho ten: " << hv.hoten << endl;
        os << "Lop: " << hv.lop << endl;
        os << "Diem dau vao: " << hv.diemdauvao << endl;
        return os;
    }

    //quá tải toán tử so sánh 2 học viên theo điểm đầu vào
    friend bool operator>(HocVien &hv1, HocVien &hv2){
        if(hv1.diemdauvao > hv2.diemdauvao){
            return true;
        }
        return false;
    }
};

int main(){
    int n;
    cout << "Nhap so luong hoc vien: ";
    cin >> n;
    HocVien *a = new HocVien[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin hoc vien thu " << i + 1 << endl;
        cin >> a[i];
    }
    cout << "Danh sach hoc vien vua nhap la: " << endl;
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << "Danh sach hoc vien tang dan theo diem dau vao la: " << endl;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n ; j++){
            if(a[i] > a[j]){
                HocVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}