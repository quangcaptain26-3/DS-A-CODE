#include<iostream>

using namespace std;

class Matrix{
private:
    int n;
    int m;
    double** a;

    public:
        Matrix(){
            n = 0;
            m = 0;
            a = nullptr;
        }

        Matrix(int n, int m){
            this->n = n;
            this->m = m;
            a = new double*[n];
            for(int i = 0; i < n; i++){
                a[i] = new double[m];
                for(int j = 0; j < m; j++){
                    a[i][j] = 0;
                }
            }
        }
    ~Matrix(){
    if(a != nullptr){
        for(int i = 0; i < n; i++){
            delete[] a[i];
        }
        delete[] a;
    }
}

void input(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void output(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix operator+(const Matrix& b){
    Matrix c(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            c.a[i][j] = a[i][j] + b.a[i][j];
        }
    }

    return c;
}


bool operator==(const Matrix& b){
    if (n != b.n || m != b.m){
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b.a[i][j]){
                return false;
            }
        }
    }
    return true;
}

};

int main(){
  
    int n, m;
    cout << "Nhap so hang: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;
    Matrix a(n, m);
    cout << "Nhap ma tran a: " << endl;
    a.input();
    cout << "Nhap ma tran b: " << endl;
    Matrix b(n, m);
    b.input();
    Matrix c = a + b;
    cout << "Ma tran c: " << endl;
    c.output();
    if(a == b){
        cout << "a == b" << endl;  
    }else{
        cout << "a != b" << endl;
    }
    return 0;

}



