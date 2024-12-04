#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class SV{
private:
    string hoten;
    int msv;
    float dtb;

public:
    SV(){
        hoten = " ";
        msv = 0;
        dtb = 0.0;
    }


    SV(string hoten, int msv, float dtb){
        this->hoten = hoten;
        this->msv = msv;
        this->dtb = dtb;
    }

    void nhap(){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap ma sinh vien: ";
        cin >> msv;
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
    }

    void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Ma sinh vien: " << msv << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }

    friend void sapxep(SV *a, int n);
    friend void timkiem(SV *a, int n);

};

void sapxep(SV *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i].dtb < a[j].dtb){
                SV temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void timkiem(SV *a, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i].msv > a[j].msv){
                SV temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main(){
//make a menu
cout << ".-------------------------------------." << endl;
cout << "|1. Nhap danh sach sinh vien          |" << endl;
cout << "|2. Xuat danh sach sinh vien          |" << endl;
cout << "|3. Sap xep sinh vien theo DTB        |" << endl;
cout << "|4. Sap xep sinh vien theo msv        |" << endl;
cout << "|5. Thoat                             |" << endl;
cout << ".-------------------------------------." << endl;

cout << "Nhap lua chon: ";
int choice;
cin >> choice;

SV *a;
int n;
a = new SV[n];

while(choice != 5){
    switch(choice){
        case 1:
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                cout << "Nhap sinh vien thu " << i + 1 << endl;
                a[i].nhap();
            }
            break;
        case 2:
            for(int i = 0; i < n; i++){
                cout << "Sinh vien thu " << i + 1 << endl;
                a[i].xuat();
            }
            break;
        case 3:
            sapxep(a, n);
            cout << "Danh sach sinh vien sau khi sap xep theo DTB: " << endl;
            for(int i = 0; i < n; i++){
                cout << "Sinh vien thu " << i + 1 << endl;
                a[i].xuat();
            }
            break;
        case 4:
            timkiem(a, n);
            cout << "Danh sach sinh vien sau khi sap xep theo msv: " << endl;
            for(int i = 0; i < n; i++){
                cout << "Sinh vien thu " << i + 1 << endl;
                a[i].xuat();
            }
            break;
        case 5:
            cout << "Thoat chuong trinh!" << endl;
            break;
        default:
            cout << "Nhap sai, nhap lai!" << endl;
            break;

    }
    cout << "Nhap lua chon: ";
    cin >> choice;
}


return 0;
}
