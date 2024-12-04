#include<bits/stdc++.h>

using namespace std;

template<class T>
class SinhVien{
private:
    T msv;
    string name;
    float diem;
public:
    SinhVien(){
        msv = 0;
        name = "";
        diem = 0;
    }

    SinhVien(T msv, string name, float diem){
        this->msv = msv;
        this->name = name;
        this->diem = diem;
    }
    
    void nhap(){
        cout << "Nhap MSV: ";
        cin >> msv;
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap diem: ";
        cin >> diem;
    }


    void show(){
        cout << "MSV: " << msv << endl;
        cout << "Name: " << name << endl;
        cout << "Diem: " << diem << endl;
    }

};

int main(){
    SinhVien<int> sv1(1, "Nguyen Van A", 9.5);
    sv1.show();
    cout <<"--------------------------\n" << endl;
    SinhVien<string> sv2("2", "Nguyen Van B", 8.5);
    sv2.show();
    cout <<"--------------------------\n" << endl;
    SinhVien<float> sv3(3, "Nguyen Van C", 7.5);
    sv3.show();
    return 0;
}