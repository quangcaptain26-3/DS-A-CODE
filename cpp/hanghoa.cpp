#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class HH{
private:
    int ma;
    string ten;
    int gianhap;
    int giaban;
    int soluong;
public:
    HH(){
        ma = 0;
        ten = "";
        gianhap = 0;
        giaban = 0;
        soluong = 0;
    }

   
   ~HH(){
    cout << "Da huy" << endl;
   }

   void nhap(){
    cout << "Nhap ma: ";
    cin >> ma;
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap gia nhap: ";
    cin >> gianhap;
    cout << "Nhap gia ban: ";
    cin >> giaban;
    cout << "Nhap so luong: ";
    cin >> soluong;
   }

   void xuat(){
    cout << "Ma: " << ma << endl;
    cout << "Ten: " << ten << endl;
    cout << "Gia nhap: " << gianhap << endl;
    cout << "Gia ban: " << giaban << endl;
    cout << "So luong: " << soluong << endl;
   }

   float tinhtien(){
    return (giaban - gianhap) * soluong;
   }
};

int main(){
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    HH *hh = new HH[n];

    for(int i = 0; i < n; i++){
        cout << "Nhap hang hoa thu " << i + 1 << endl;
        hh[i].nhap();
    }

    for(int i = 0; i < n; i++){
        cout << "Thong tin hang hoa thu " << i + 1 << endl;
        hh[i].xuat();
    }

    float tongloinhuan = 0;
    for(int i = 0; i < n; i++){
        tongloinhuan += hh[i].tinhtien();
    }
    //cout tongloinhuan with setprecision(2)
    cout << "Tong loi nhuan: " << fixed << setprecision(2) << tongloinhuan << endl;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++ ){
            if(hh[i].tinhtien() < hh[j].tinhtien()){
                HH temp = hh[i];
                hh[i] = hh[j];
                hh[j] = temp;
            }
        }
    }

    //+ In ra danh sách tối đa 10% mặt hàng bán lãi nhất có số lượng bán > 5
    /*int dem = 0;
    for(int i = 0; i < n; i++){
        if(hh[i].tinhtien() > 0 && hh[i].soluong > 5){
            cout << "Hang hoa thu " << i + 1 << endl;
            hh[i].xuat();
            dem++;
        }
        if(dem == n * 0.1){
            break;
        }
    }
    */

    return 0;
}