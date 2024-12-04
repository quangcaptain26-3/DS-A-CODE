#include<iostream>
#include<iomanip>
using namespace std;

class VT{
private:
    int n;
    double* v;
public:
    VT(){
        n = 0;
        v = nullptr;
    }

    VT(int n){
        this->n = n;
        v = new double[n];
    }

    ~VT(){
        if(v != nullptr){
            delete[] v;
        }
    }

    void nhap(){
        cout << "Nhap chieu dai: ";
        cin >> n;
        v = new double[n];
        for(int i = 0; i < n; i++){
            cout << "Nhap v[" << i + 1 << "]: ";
            cin >> v[i];
        }
    }

    void xuat(){
        for(int i = 0; i < n; i++){
            //cout with suprecision 2
            cout << fixed << setprecision(2) << v[i] << " ";
        }
        cout << endl;
    }

    VT operator+(const VT& ot){
        VT kq(n);
        for(int i = 0; i < n; i++){
            kq.v[i] = v[i] + ot.v[i];
        }
        return kq;
    }

    VT operator*(double k){
        VT kq(n);
        for(int  i = 0; i < n; i++){
            kq.v[i] = v[i] * k;
        }    
        return kq;
    }

    //hàm toán tử chỉ số
    double& operator[](int i){
        return v[i];
    }
};

int main(){
  
    int n;
    cout << "Nhap so VT: ";
    cin >> n;

    VT* a = new VT[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap VT thu " << i + 1 << endl;
        a[i].nhap();
    }

    for(int i = 0; i < n; i++){
        cout << "VT thu " << i + 1 << ": ";
        a[i].xuat();
    }

  
    VT tong;
    tong = a[0];
    for(int i = 1; i < n; i++){
        tong = tong + a[i];
    }
    cout << "Tong cac VT: ";
    tong.xuat();

    delete[] a;

    return 0;
}