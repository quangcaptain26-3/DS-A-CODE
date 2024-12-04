#include<iostream>
#include<math.h>

using namespace std;
class PhanSo{
private:
    int tu, mau;
public:
    PhanSo(int t = 1, int m = 2){
        tu = t;
        mau = m;
    }
    void nhap(){
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
    }

    void xuat(){
        cout << tu << "/" << mau << endl;
    }

    friend PhanSo cong(PhanSo a, PhanSo b);
};

PhanSo cong(PhanSo a, PhanSo b){
    PhanSo c;
    c.tu = a.tu * b.mau + b.tu * a.mau;
    c.mau = a.mau * b.mau;
    return c;
}

int main(){
    PhanSo a, b, c;
    a.nhap();
    b.nhap();
    c = cong(a, b);
    c.xuat();
    return 0;
}