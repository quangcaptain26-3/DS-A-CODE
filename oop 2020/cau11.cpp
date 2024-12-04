#include<bits/stdc++.h>

using namespace std;

class MaTran{
private:
    int data [2][2];
public:
    void nhap(){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout << "Nhap data[" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void xuat(){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    int tinhdinhthuc(){
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    MaTran cong(const MaTran &mt){
        MaTran kq;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                kq.data[i][j] = data[i][j] + mt.data[i][j];
            }
        }
        return kq;
    }

    int* operator[](int i){
        return data[i];
    }
};

int main(){
    int n;
    cout << "Nhap so luong ma tran: ";
    cin >> n;
    MaTran *a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap ma tran thu " << i + 1 << endl;
        a[i] = new MaTran;
        a[i]->nhap();
    }
    cout << "Cac ma tran vua nhap la: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Ma tran thu " << i + 1 << endl;
        a[i]->xuat();
    }
    cout << "Tinh tong cac ma tran vua nhap: " << endl;
    MaTran tong = *a[0];
    for(int i = 1; i < n; i++){
        tong = tong.cong(*a[i]);
    }
    tong.xuat();
}