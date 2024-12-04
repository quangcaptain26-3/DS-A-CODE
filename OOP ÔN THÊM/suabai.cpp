#include<bits/stdc++.h>

using namespace std;

class Sach{
private:
    string tensach;
    string tacgia;
    int namxuatban;
    string nhaxuatban;
public:
    Sach(){
        tensach = "";
        tacgia = "";
        namxuatban = 0;
        nhaxuatban = "";
    }

    Sach(string tensach, string tacgia, int namxuatban, string nhaxuatban){
        this->tensach = tensach;
        this->tacgia = tacgia;
        this->namxuatban = namxuatban;
        this->nhaxuatban = nhaxuatban;
    }

    void nhap(){
        cout << "Ten sach: ";
        cin.ignore();
        getline(cin, tensach);
        cout << "Tac gia: ";
        cin.ignore();
        getline(cin, tacgia);
        cout << "Nam xuat ban: ";
        cin >> namxuatban;
        cout << "Nha xuat ban: ";
        cin.ignore();
        getline(cin, nhaxuatban);
    }

    void xuat(){
        cout << "Ten sach: " << tensach << endl;
        cout << "Tac gia: " << tacgia << endl;
        cout << "Nam xuat ban: " << namxuatban << endl;
        cout << "Nha xuat ban: " << nhaxuatban << endl;
    }

    friend class DocGia;
};

class DocGia{
private:
    string hoten;
    int ma;
    string khoa;
    string lop;
    int sosach;
    Sach *a;
public:
    DocGia(){
        hoten = "";
        ma = 0;
        khoa = "";
        lop = "";
        sosach = 0;
        a = NULL;
    }

    DocGia(string hoten, int ma, string khoa, string lop, int sosach, Sach *a){
        this->hoten = hoten;
        this->ma = ma;
        this->khoa = khoa;
        this->lop = lop;
        this->sosach = sosach;
        this->a = a;
    }

    void nhap(){
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Ma: ";
        cin >> ma;
        cout << "Khoa: ";
        cin.ignore();
        getline(cin, khoa);
        cout << "Lop: ";
        cin.ignore();
        getline(cin, lop);
        cout << "So sach: ";
        cin >> sosach;
        a = new Sach[sosach];
        for(int i = 0; i < sosach; i++){
            cout << "Nhap quyen sach thu " << i + 1 << endl;
            a[i].nhap();
        }
    }

    void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Ma: " << ma << endl;
        cout << "Khoa: " << khoa << endl;
        cout << "Lop: " << lop << endl;
        cout << "So sach: " << sosach << endl;
        for(int i = 0; i < sosach; i++){
            cout << "Quyen sach thu " << i + 1 << endl;
            a[i].xuat();
        }
    }
    friend void max(DocGia[], int n);
};

void max(DocGia a[], int n){
    DocGia max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i].sosach > max.sosach){
            max = a[i];
        }
    }
    max.xuat();
}

int main(){
    int n;
    cout << "Nhap so luong doc gia: ";
    cin >> n;
    DocGia *a = new DocGia[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap doc gia thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "Doc gia muon nhieu sach nhat la: " << endl;
    max(a, n);
    return 0;
}

