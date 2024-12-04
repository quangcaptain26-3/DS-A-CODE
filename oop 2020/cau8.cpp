#include<iostream>
#include<string.h>

using namespace std;

class MatHang{
protected:
    string tenhang;
    int mahang;
    int gianhap;
    int giaban;
public:
    MatHang(){
        tenhang = "";
        mahang = 0;
        gianhap = 0;
        giaban = 0;
    }

    MatHang(string tenhang, int mahang, int gianhap, int giaban){
        this->tenhang = tenhang;
        this->mahang = mahang;
        this->gianhap = gianhap;
        this->giaban = giaban;
    }

    ~MatHang(){
        cout << "Da huy mat hang " << tenhang << endl;
    }

    void nhap(){
        cout << "Nhap ten hang: ";
        cin.ignore();
        getline(cin, tenhang);
        cout << "Nhap ma hang: ";
        cin >> mahang;
        cout << "Nhap gia nhap: ";
        cin >> gianhap;
        cout << "Nhap gia ban: ";
        cin >> giaban;
    }

    void xuat(){
        cout << "Ten hang: " << tenhang << endl;
        cout << "Ma hang: " << mahang << endl;
        cout << "Gia nhap: " << gianhap << endl;
        cout << "Gia ban: " << giaban << endl;
    }
};

//lớp hàng gia dụng nhập khẩu kế thừa lớp mặt hàng với thuê nhập khẩu là 10% giá nhập
class HangGiaDungNhapKhau: public MatHang{
private:
    int thuenhapkhau;
public:
    HangGiaDungNhapKhau(): MatHang(){
        thuenhapkhau = 0;
    }

    HangGiaDungNhapKhau(string tenhang, int mahang, int gianhap, int giaban, int thuenhapkhau): MatHang(tenhang, mahang, gianhap, giaban){
        this->thuenhapkhau = thuenhapkhau;
    }

    ~HangGiaDungNhapKhau(){
        cout << "Da huy hang gia dung nhap khau " << tenhang << endl;
    }

    void nhap(){
        MatHang::nhap();
        thuenhapkhau = gianhap * 0.1;
    }

    void xuat(){
        MatHang::xuat();
        cout << "Thue nhap khau: " << thuenhapkhau << endl;
    }
};

//lớp ô tô nhập khẩu kế thừa lớp mặt hàng với thuê nhập khẩu là 30% giá nhập
class OtoNhapKhau: public MatHang{
private:
    int thuenhapkhau;
public:
    OtoNhapKhau(): MatHang(){
        thuenhapkhau = 0;
    }

    OtoNhapKhau(string tenhang, int mahang, int gianhap, int giaban, int thuenhapkhau): MatHang(tenhang, mahang, gianhap, giaban){
        this->thuenhapkhau = thuenhapkhau;
    }

    ~OtoNhapKhau(){
        cout << "Da huy o to nhap khau " << tenhang << endl;
    }

    void nhap(){
        MatHang::nhap();
        thuenhapkhau = gianhap * 0.3;
    }

    void xuat(){
        MatHang::xuat();
        cout << "Thue nhap khau: " << thuenhapkhau << endl;
    }
};

//lớp máy móc nhập khẩu kế thừa lớp mặt hàng với thuê nhập khẩu là 12% giá nhập
class MayMocNhapKhau: public MatHang{
private:
    int thuenhapkhau;
public:
    MayMocNhapKhau(): MatHang(){
        thuenhapkhau = 0;
    }

    MayMocNhapKhau(string tenhang, int mahang, int gianhap, int giaban, int thuenhapkhau): MatHang(tenhang, mahang, gianhap, giaban){
        this->thuenhapkhau = thuenhapkhau;
    }

    ~MayMocNhapKhau(){
        cout << "Da huy may moc nhap khau " << tenhang << endl;
    }

    void nhap(){
        MatHang::nhap();
        thuenhapkhau = gianhap * 0.12;
    }

    void xuat(){
        MatHang::xuat();
        cout << "Thue nhap khau: " << thuenhapkhau << endl;
    }
};

int main(){
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    MatHang *a[n];
    int loai;
    for(int i = 0; i < n; i++){
        cout << "Nhap loai mat hang (1: hang gia dung, 2: o to, 3: may moc): ";
        cin >> loai;
        switch (loai)
        {
        case 1:
            a[i] = new HangGiaDungNhapKhau();
            a[i]->nhap();
            break;
        case 2:
            a[i] = new OtoNhapKhau();
            a[i]->nhap();
            break;
        case 3:
            a[i] = new MayMocNhapKhau();
            a[i]->nhap();
            break;
        default:
            break;
        }
    }
    cout <<"==============================" << endl;
    cout << "Danh sach mat hang: " << endl;
  
    for(int i = 0; i < n; i++){
        a[i]->xuat();
        cout <<"==============================" << endl;
    }
    return 0;

}