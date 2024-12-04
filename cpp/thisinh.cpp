#include<iostream>
#include<string.h>

using namespace std;

class TS{
private:
    string hoten;
    float diemTB;
    float diemTA;

public:
    TS(){
        hoten = " ";
        diemTB = 0.0;
        diemTA = 0.0;
    }

    ~TS(){
        cout << "Da huy doi tuong" << endl;
    }

    TS(string hoten, float diemTB, float diemTA){
        this->hoten = hoten;
        this->diemTB = diemTB;
        this->diemTA = diemTA;
    }

    void nhap(){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap diem TB: ";
        cin >> diemTB;
        cout << "Nhap diem TA: ";
        cin >> diemTA;
    }

    void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Diem TB: " << diemTB << endl;
        cout << "Diem TA: " << diemTA << endl;
    }

   
    bool XetTuyen(){
        return (diemTB >= 7.0 && diemTA >= 400);
    }


};


class UT : public TS{
private:
    float diemUT;
public:
    UT() : TS(){
        diemUT = 0.0;
    }

    UT(string hoten, float diemTB, float diemTA, float diemUT) : TS(hoten, diemTB, diemTA){
        this->diemUT = diemUT;
    }

    void nhap(){
        TS::nhap();
        cout << "Nhap diem UT: ";
        cin >> diemUT;
    }

    void xuat(){
        TS::xuat();
        cout << "Diem UT: " << diemUT << endl;
    }

};

int main(){
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    TS *a = new TS[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
        cout << "1. Thi sinh" << endl;
        cout << "2. Uu tien" << endl;
        int chon;
        cout << "Nhap lua chon: ";
        cin >> chon;
        if(chon == 1){
            a[i].nhap();
        }
        else{
            a[i] = UT();
            a[i].nhap();
        }
    }

    for(int i = 0; i < n; i++){
        cout << "Thong tin thi sinh thu " << i + 1 << endl;
        a[i].xuat();
    }

    int dem = (int)(n * 0.3);
    cout << "Danh sach thi sinh trung tuyen khong vuot qua 30%: " << endl;
    for(int  i = 0; i < n; i++){
        if(a[i].XetTuyen()){
            cout << "Thi sinh thu " << i + 1 << endl;
            a[i].xuat();
            dem--;
            if(dem == 0){
                break;
            }
        }
    }


    delete[] a;
    return 0;

}