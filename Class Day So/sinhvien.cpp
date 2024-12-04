#include<iostream>  
#include<string>
#include<iomanip>

using namespace std;

class SV{
    string ten;
    int ma;
    double d1, d2, d3;
public:
    SV();
    ~SV(){
        cout<<"Da huy"<<this<<endl;
    }
    double tongdiem() const{
        return d1 + d2 + d3;
    }
    friend class DSSV;
};

class DSSV{
    SV *a;
    int n;
public:
    DSSV();
    ~DSSV(){
        cout << "Da huy" << this << endl;
        delete []a;
    }

    void nhap();
    void xuat();
    void sapxep();
    void timkiem();
};

SV::SV(){
    ten = "";
    ma = 0;
    d1 = d2 = d3 = 0;
}

DSSV::DSSV(){
    a = nullptr;
    n = 0;
}

void DSSV::nhap(){
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    a = new SV[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap sinh vien thu " << i + 1 << endl;
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, a[i].ten);
        cout << "Nhap ma: ";
        cin >> a[i].ma;
        cout << "Nhap diem 1: ";
        cin >> a[i].d1;
        cout << "Nhap diem 2: ";
        cin >> a[i].d2;
        cout << "Nhap diem 3: ";
        cin >> a[i].d3;

    }
}

void DSSV::sapxep(){
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i].ten < a[j].ten){
                SV temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void DSSV::xuat(){
    cout << "Danh sach sinh vien: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Sinh vien thu: " << i + 1 << endl;
        cout << "Ten: " << a[i].ten << endl;
        cout << "Ma: " << a[i].ma << endl;
        cout << "Diem 1: " << a[i].d1 << endl;
        cout << "Diem 2: " << a[i].d2 << endl;
        cout << "Diem 3: " << a[i].d3 << endl;
        cout << "Tong diem: " << a[i].tongdiem() << endl;
    }
}

void DSSV::timkiem(){
    cout << "Danh sach sinh vien co diem thap nhat: " << endl;
    for(int i = 0; i < n; i++){
        if(a[i].tongdiem() <= 4){
            cout << a[i].ten << endl;
        }
    }
}


int main(){
    DSSV a;
    a.nhap();
    a.sapxep();
    a.xuat();
    a.timkiem();
    return 0;
}

