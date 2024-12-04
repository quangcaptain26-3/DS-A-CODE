#include<bits/stdc++.h>

using namespace std;

class ThiSinh{
protected:
    string hoten;
    int sbd;
    float d1, d2, d3;
public:
    ThiSinh(){
        hoten = "";
        sbd = 0;
        d1 = 0;
        d2 = 0;
        d3 = 0;
    }

    ThiSinh(string hoten, int sbd, float d1, float d2, float d3){
        this->hoten = hoten;
        this->sbd = sbd;
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
    }

    //getter and setter
    string getHoten(){
        return hoten;
    }

    void setHoten(string hoten){
        this->hoten = hoten;
    }

    int getSbd(){
        return sbd;
    }

    void setSbd(int sbd){
        this->sbd = sbd;
    }

    float getD1(){
        return d1;
    }

    void setD1(float d1){
        this->d1 = d1;
    }

    float getD2(){
        return d2;
    }

    void setD2(float d2){
        this->d2 = d2;
    }

    float getD3(){
        return d3;
    }

    void setD3(float d3){
        this->d3 = d3;
    }

    //tính tổng điểm
    virtual float tongdiem(){
        return d1 + d2 + d3;
    }

    //toán tử nhập
    friend istream& operator >> (istream& is, ThiSinh &ts){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(is, ts.hoten);
        cout << "Nhap so bao danh: ";
        is >> ts.sbd;
        cout << "Nhap diem 1: ";
        is >> ts.d1;
        cout << "Nhap diem 2: ";
        is >> ts.d2;
        cout << "Nhap diem 3: ";
        is >> ts.d3;
        return is;
    }

    //toán tử xuất
    friend ostream& operator << (ostream& os, ThiSinh ts){
        os << "Ho ten: " << ts.hoten << endl;
        os << "So bao danh: " << ts.sbd << endl;
        os << "Diem 1: " << ts.d1 << endl;
        os << "Diem 2: " << ts.d2 << endl;
        os << "Diem 3: " << ts.d3 << endl;
        os << "Tong diem: " << ts.tongdiem() << endl;
        return os;
    }

    //Điều kiện thi đỗ là không môn nào bị điểm 0 và tổng điểm >=15.
    virtual bool duthi(){
        if(d1 == 0 || d2 == 0 || d3 == 0 || tongdiem() < 15){
            return false;
        }
        return true;
    }
};

class ThiSinhUuTien : public ThiSinh{
private:
    float diemuutien;
public:
    ThiSinhUuTien() : ThiSinh(){
        diemuutien = 0;
    }

    ThiSinhUuTien(string hoten, int sbd, float d1, float d2, float d3, float diemuutien) : ThiSinh(hoten, sbd, d1, d2, d3){
        this->diemuutien = diemuutien;
    }

    float getDiemuutien(){
        return diemuutien;
    }

    void setDiemuutien(float diemuutien){
        this->diemuutien = diemuutien;
    }

    float tongdiemuutien(){
        return d1 + d2 + d3 + diemuutien;
    }

    bool duthi(){
        if(d1 == 0 || d2 == 0 || d3 == 0 || tongdiem() < 15){
            return false;
        }
        return true;
    }

    friend istream& operator >> (istream& is, ThiSinhUuTien &ts){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(is, ts.hoten);
        cout << "Nhap so bao danh: ";
        is >> ts.sbd;
        cout << "Nhap diem 1: ";
        is >> ts.d1;
        cout << "Nhap diem 2: ";
        is >> ts.d2;
        cout << "Nhap diem 3: ";
        is >> ts.d3;
        cout << "Nhap diem uu tien: ";
        is >> ts.diemuutien;
        return is;
    }

    friend ostream& operator << (ostream& os, ThiSinhUuTien ts){
        os << "Ho ten: " << ts.hoten << endl;
        os << "So bao danh: " << ts.sbd << endl;
        os << "Diem 1: " << ts.d1 << endl;
        os << "Diem 2: " << ts.d2 << endl;
        os << "Diem 3: " << ts.d3 << endl;
        os << "Diem uu tien: " << ts.diemuutien << endl;
        os << "Tong diem: " << ts.tongdiemuutien() << endl;
        return os;
    }
};


int main(){
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    ThiSinh *a = new ThiSinh[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
        int loai;
        cout << "Nhap loai thi sinh (1: thuong, 2: uu tien): ";
        cin >> loai;
        if(loai == 1){
            cin >> a[i];
        }
        else if(loai == 2){
            cin >> (ThiSinhUuTien&)a[i];
        }
    }
    cout << "--------------------------" << endl;
    cout << "Danh sach thi sinh: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Thong tin thi sinh thu " << i + 1 << endl;
        cout << a[i];
    }

    cout << "--------------------------" << endl;
    cout << "Danh sach thi sinh trung tuyen: " << endl;
    for(int i = 0; i < n; i++){
        if(a[i].duthi()){
            cout << "Thong tin thi sinh thu " << i + 1 << endl;
            cout << a[i];
        }
    }
    return 0; 
}