#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NV {
    string ten;
    int ma;
    double hsl;
    int pc;
    int namct;
public:
    NV();
    ~NV() {
        cout << "Ham huy cua NV " << this << endl;
    }
    double luong() const {
        return hsl * 2000 + pc;
    }
    bool ktra() const {
        if (namct > 1 && (namct - 1) % 3 == 0) return true;
        return false;
    }
    friend class DSNV;
};

class DSNV {
    NV* a;
    int n;
public:
    DSNV();
    ~DSNV() {
        cout << "Ham huy cua DSNV " << this << endl;
        delete[] a;
    }
    void nhap();
    void xuat();
    void sapxep();
    void tangluong();
};

void DSNV::nhap() {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    a = new NV[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap nhan vien thu " << i + 1 << endl;
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, a[i].ten);
        cout << "Nhap ma: ";
        cin >> a[i].ma;
        cout << "Nhap he so luong: ";
        cin >> a[i].hsl;
        cout << "Nhap phu cap: ";
        cin >> a[i].pc;
        cout << "Nhap nam cong tac: ";
        cin >> a[i].namct;
    }
}

void DSNV::sapxep() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].luong() < a[j].luong()) {
                NV temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void DSNV::xuat() {
    cout << "Danh sach nhan vien: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhan vien thu " << i + 1 << endl;
        cout << "Ten: " << a[i].ten << endl;
        cout << "Ma: " << a[i].ma << endl;
        cout << "He so luong: " << a[i].hsl << endl;
        cout << "Phu cap: " << a[i].pc << endl;
        cout << "Nam cong tac: " << a[i].namct << endl;
        cout << "Luong: " << fixed << setprecision(3) << a[i].luong() << endl;
    }
}

void DSNV::tangluong() {
    cout << "Danh sach nhan vien duoc tang luong: " << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].ktra()) {
            cout << a[i].ten << endl;
        }
    }
}

NV::NV() {
    ten = "";
    ma = 0;
    hsl = 0;
    pc = 0;
    namct = 0;
}

DSNV::DSNV(){
    a = nullptr;
    n = 0;
}
int main() {
    DSNV ds;
    ds.nhap();
    ds.sapxep();
    ds.xuat();
    ds.tangluong();
    return 0;
}