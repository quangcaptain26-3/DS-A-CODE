#include<iostream>

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
            cout << v[i] << " ";
        }
        cout << endl;
    }

    VT operator+(const VT& ot){
        VT kq;
        kq.n = n;
            kq.v = new double[n];
            for(int i = 0; i < n; i++){
                kq.v[i] = v[i] + ot.v[i];
            }
            return kq;
    }

    VT operator*(double k){
        VT kq;
        kq.n = n;
        kq.v = new double[n];
        for(int  i = 0; i < n; i++){
            kq.v[i] = v[i] * k;
        }    
        return kq;
    }

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
        cout << "Nhap vt thu" << i + 1 << endl;
        a[i].nhap();
    }

    cout << "DS cac VT da nhap: " << endl;
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }

    VT sum = a[0];
    for(int i = 0; i < n; i++){
        sum = sum + a[i];
    }


    cout << "Tong cac VT: " << endl;
    sum.xuat();


    delete[] a;
    return 0;
}