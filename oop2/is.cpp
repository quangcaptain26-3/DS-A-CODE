#include<bits/stdc++.h>

using namespace std;

class MT{
private:
    int n, m;
    double** a;

public:
    MT(){
        n = 0;
        m = 0;
        a = nullptr;
    }

    MT(int n, int m){
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

    ~MT(){
        if(a != nullptr){
            for(int i = 0; i < n; i++){
                delete[] a[i];
            }
            delete[] a;
        }
    }

    friend istream& operator >>(istream& in, MT& m){
        for(int i = 0; i < m.n; i++){
            for(int j = 0; j < m.n; j++){
                cout << "a[" << i << "][" << j << "] = ";
                in >> m.a[i][j];
                
            }
        }
        return in;
    }

    friend ostream& operator <<(ostream& out, MT& m){
        for(int i = 0; i < m.n; i++){
            for(int j = 0; j < m.n; j++){
                out << m.a[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }


    MT operator+(const MT& b){
        MT c(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                c.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return c;
    }

    bool operator== (const MT& b){
        if(n != b.n || m != b.m){
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
    MT A(5, 5);
    
    cin >> A;

    MT B(5, 5);

    cin >> B;

    MT C = A + B;

    cout << C;

    if(A==B){
        cout << "A == B" << endl;
    }else{
        cout << "A != B" << endl;
    }
    return 0;
}