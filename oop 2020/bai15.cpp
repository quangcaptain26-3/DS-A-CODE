#include<bits/stdc++.h>

using namespace std;

class HocVien{
private:
    int mahv;
    string hoten;
    string nganhhoc;
public:
    HocVien(){
        mahv = 0;
        hoten = "";
        nganhhoc = "";
    }

    HocVien(int mahv, string hoten, string nganhhoc){
        this->mahv = mahv;
        this->hoten = hoten;
        this->nganhhoc = nganhhoc;
    }

    int getMahv(){
        return mahv;
    }

    void setMahv(int mahv){
        this->mahv = mahv;
    }

    string getHoten(){
        return hoten;
    }

    void setHoten(string hoten){
        this->hoten = hoten;
    }

    string getNganhhoc(){
        return nganhhoc;
    }

    void setNganhhoc(string nganhhoc){
        this->nganhhoc = nganhhoc;
    }

     void nhap(){
        cout << "Nhap ma hoc vien: ";
        cin >> mahv;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap nganh hoc: ";
        getline(cin, nganhhoc);
    }

     void xuat(){
        cout << "Ma hoc vien: " << mahv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Nganh hoc: " << nganhhoc << endl;
    }
};

int main(){
    int n;
    cout << "Nhap so luong hoc vien: ";
    cin >> n;
    HocVien *a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap hoc vien thu " << i + 1 << endl;
        a[i] = new HocVien;
        a[i]->nhap();
    }
    cout <<"--------------------------" << endl;
    cout << "Cac hoc vien vua nhap la: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Hoc vien thu " << i + 1 << endl;
        a[i]->xuat();
    }

    string nganh;
    cout << "Nhap nganh hoc: ";
    cin.ignore();
    getline(cin, nganh);
    cout << "Danh sach hoc vien theo nganh hoc " << nganh << " la: " << endl;
    for(int i = 0; i < n; i++){
        if(a[i]->getNganhhoc() == nganh)
            a[i]->xuat();
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++)
            if(a[i]->getHoten() > a[j]->getHoten())
                swap(a[i], a[j]);
    }
    cout <<"--------------------------" << endl;
    cout << "Danh sach hoc vien sau khi sap xep tang dan theo ho ten: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Hoc vien thu " << i + 1 << endl;
        a[i]->xuat();
    }

    return 0;

}