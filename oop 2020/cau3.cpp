#include<bits/stdc++.h>

using namespace std;

class HangHoa{
private:
    int maHang;
    string tenHang;
    int gianhap;
    int giaban;
    int soluong;
public:
    HangHoa(){
        maHang = 0;
        tenHang = "";
        gianhap = 0;
        giaban = 0;
        soluong = 0;
    }

    HangHoa(int maHang, string tenHang, int gianhap, int giaban, int soluong){
        this->maHang = maHang;
        this->tenHang = tenHang;
        this->gianhap = gianhap;
        this->giaban = giaban;
        this->soluong = soluong;
    }

    ~HangHoa(){
        cout << "Da huy" << endl;
    }

    //getter and setter
    int getMaHang(){
        return maHang;
    }

    void setMaHang(int maHang){
        this->maHang = maHang;
    }

    string getTenHang(){
        return tenHang;
    }

    void setTenHang(string tenHang){
        this->tenHang = tenHang;
    }

    int getGiaNhap(){
        return gianhap;
    }

    void setGiaNhap(int gianhap){
        this->gianhap = gianhap;
    }

    int getGiaBan(){
        return giaban;
    }

    void setGiaBan(int giaban){
        this->giaban = giaban;
    }

    int getSoLuong(){
        return soluong;
    }

    void setSoLuong(int soluong){
        this->soluong = soluong;
    }

    void nhap(){
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin.ignore();
        getline(cin, tenHang);
        cout << "Nhap gia nhap: ";
        cin >> gianhap;
        cout << "Nhap gia ban: ";
        cin >> giaban;
        cout << "Nhap so luong: ";
        cin >> soluong;
    }

    void xuat(){
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Gia nhap: " << gianhap << endl;
        cout << "Gia ban: " << giaban << endl;
        cout << "So luong: " << soluong << endl;
    }

    void tinhloinhuan(){
        cout << "Loi nhuan: " << (giaban - gianhap) * soluong << endl;
    }
};


void inDanhSachHangHoa(HangHoa *ds, int n){
    for(int i = 0; i < n; i++){
        cout << "Hang hoa thu " << i + 1 << endl;
        ds[i].xuat();
    }
}


void tongLoiNhuan(HangHoa *ds, int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        tong += (ds[i].getGiaBan() - ds[i].getGiaNhap()) * ds[i].getSoLuong();
    }
    cout << "Tong loi nhuan: " << tong << endl;
}


void sapXep(HangHoa *ds, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((ds[i].getGiaBan() - ds[i].getGiaNhap()) * ds[i].getSoLuong() < (ds[j].getGiaBan() - ds[j].getGiaNhap()) * ds[j].getSoLuong()){
                HangHoa temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void inDanhSachBanLaiNhat(HangHoa *ds, int n){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if((ds[i].getGiaBan() - ds[i].getGiaNhap()) * ds[i].getSoLuong() > 5){
            dem++;
        }
    }
    if(dem == 0){
        cout << "Khong co hang hoa nao ban lai" << endl;
    }else{
        cout << "Danh sach hang hoa ban lai nhieu nhat: " << endl;
        for(int i = 0; i < dem; i++){
            cout << "Hang hoa thu " << i + 1 << endl;
            ds[i].xuat();
        }
    }
}

int main(){
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    HangHoa *ds = new HangHoa[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap hang hoa thu " << i + 1 << endl;
        ds[i].nhap();
    }
    cout <<"------------------------------------" << endl;
    cout << "Danh sach hang hoa vua nhap: " << endl;
    inDanhSachHangHoa(ds, n);
    cout <<"------------------------------------" << endl;
    tongLoiNhuan(ds, n);
    cout <<"------------------------------------" << endl;
    sapXep(ds, n);
    inDanhSachBanLaiNhat(ds, n);
    delete[] ds;
    return 0;
}