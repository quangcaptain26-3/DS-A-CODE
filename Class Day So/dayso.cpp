#include<iostream>
#include<math.h>

using namespace std;

class DS{
int spt;
float *a;

public:
    DS(int n = 5){
        this->spt = n;
        if(n == 0){
            this->a = NULL;
    } else {
        this->a = new float[this->spt];
        for(int i = 0; i < this -> spt; i++)
            a[i] = 0;
        }
    }

    DS(const DS &p){
        this->spt = p.spt;
        this->a = new float[spt];
        for(int i = 0; i < this->spt; i++)
            a[i] = p.a[i];
    }
    ~DS(){
        if(this->a != NULL)
            delete[] a;
    }
    void nhap(){
        cout << "Nhap so phan tu: ";
        cin >> this->spt;
        this->a = new float[this->spt];
        for(int i = 0; i < this->spt; i++){
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            cin >> this->a[i];
        }
    }
    void xuat(){
        for(int i = 0; i < this->spt; i++)
            cout << this->a[i] << " ";
        cout << endl;
    }
    
};

int main(){
    DS a;
    a.nhap();
    a.xuat();
    return 0;

}