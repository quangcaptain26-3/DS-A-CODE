#include<bits/stdc++.h>
using namespace std;

class Thuoc{
protected:
    string tenthuoc;
    int ma;
    int gia;
    int soluong;
public:
    Thuoc(string tenthuoc, int ma, int gia, int soluong){
        this->tenthuoc = tenthuoc;
        this->ma = ma;
        this->gia = gia;
        this->soluong = soluong;
    }

    Thuoc(){
        this->tenthuoc = "";
        this->ma = 0;
        this->gia = 0;
        this->soluong = 0;
    }

    ~Thuoc(){
        cout << "Da huy" << endl;
    }

    void nhap(){
        cout << "Nhap ten thuoc: ";
        cin.ignore();
        getline(cin, tenthuoc);
        cout << "Nhap ma: ";
        cin >> ma;
        cout << "Nhap gia: ";
        cin >> gia;
        cout << "Nhap so luong: ";
        cin >> soluong;
        
    }

    void xuat()
    {
        cout << "Ten thuoc: " << this->tenthuoc << endl;
        cout << "Ma: " << this->ma << endl;
        cout << "Gia: " << this->gia << endl;
        cout << "So luong: " << this->soluong << endl;
    }

    //sắp xếp theo tên thuốc
    void sapxep(Thuoc *a, int n){
       //sắp xếp theo tên thuốc, cùng tên theo mã
           for(int i = 0; i < n - 1; i++){
                for(int j = i + 1; j < n; j++){
                    if(a[i].tenthuoc > a[j].tenthuoc){
                        Thuoc temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                    else if(a[i].tenthuoc == a[j].tenthuoc){
                        if(a[i].ma > a[j].ma){
                            Thuoc temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }
            }  
    }
};

//main function
int main(){
    int n;
    cout << "Nhap so luong thuoc: ";
    cin >> n;
    Thuoc *a = new Thuoc[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin thuoc thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "Danh sach thuoc vua nhap: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Thong tin thuoc thu " << i + 1 << endl;
        a[i].xuat();
    }
    cout << "Danh sach thuoc sau khi sap xep: " << endl;
    a[0].sapxep(a, n);
    for(int i = 0; i < n; i++){
        cout << "Thong tin thuoc thu " << i + 1 << endl;
        a[i].xuat();
    }
    delete[] a;
    return 0;
}