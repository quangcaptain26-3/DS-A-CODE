#include <iostream>
using namespace std;

class MT{
	private:
		int n,m;
		int** data;
	public:
		MT(int h = 5, int c = 5) : n(h), m(c) {
	        data = new int*[m];
	        for (int i = 0; i < m; i++) {
	            data[i] = new int[n];
	        }
	    }
		~MT(){
			for (int i = 0; i < m; i++) {
            	delete[] data[i];
        	}
        	delete[] data;
		}
		friend MT operator+(const MT& a, const MT& b);
		friend istream& operator>>(istream& is, MT& x);
		friend ostream& operator<<(ostream& os, const MT& x);
		friend bool operator==(const MT& a, const MT& b);
};

istream& operator>>(istream& is, MT& x) {
    cout << "Nhap ma tran (nhap " << x.m << " hang va " << x.n << " cot):" << endl;
    for (int i = 0; i < x.m; i++) {
        for (int j = 0; j < x.n; j++) {
            is >> x.data[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const MT& x) {
    os << "Ma tran [" << x.m << "," << x.n << "]:" << endl;
    for (int i = 0; i < x.m; i++) {
        for (int j = 0; j < x.n; j++) {
            os << x.data[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}

MT operator+(const MT& a, const MT& b) {
    MT result(a.m, a.n);
    for (int i = 0; i < a.m; i++) {
        for (int j = 0; j < a.n; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}
bool operator==(const MT& a, const MT& b) {
    if (a.m != b.m || a.n != b.n) {
        return false;
    }

    for (int i = 0; i < a.m; i++) {
        for (int j = 0; j < a.n; j++) {
            if (a.data[i][j] != b.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}
int main() {
    MT mat;
    MT mat2; 
    cin >> mat;
    cin >> mat2;
	cout<<"Hai ma tran vua nhap:"<<endl;
	cout<<"Mtran 1: "<<endl;
	cout<<mat;
	cout<<"Mtran 2: "<<endl;
	cout<<mat2;
	cout<<endl; 
	MT sum = mat + mat2;
	cout << "Tong hai ma tran:" << endl;
	cout << sum;
	cout<<endl;
	if (mat == mat2) {
	    cout << "Hai ma tran giong nhau." << endl;
	} else {
	    cout << "Hai ma tran khac nhau." << endl;
	}
    return 0;
}