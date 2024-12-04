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

    //getter và setter
    string getTensach(){
        return tensach;
    }

    void setTensach(string tensach){
        this->tensach = tensach;
    }

    string getTacgia(){
        return tacgia;
    }

    void setTacgia(string tacgia){
        this->tacgia = tacgia;
    }

    int getNamxuatban(){
        return namxuatban;
    }

    void setNamxuatban(int namxuatban){
        this->namxuatban = namxuatban;
    }

    string getNhaxuatban(){
        return nhaxuatban;
    }

    void setNhaxuatban(string nhaxuatban){
        this->nhaxuatban = nhaxuatban;
    }
};

class DocGia{
private:
    string tendocgia;
    string maso;
    string khoa;
    string lop;
public:
    DocGia(){
        tendocgia = "";
        maso = "";
        khoa = "";
        lop = "";
    }

    DocGia(string tendocgia, string maso, string khoa, string lop){
        this->tendocgia = tendocgia;
        this->maso = maso;
        this->khoa = khoa;
        this->lop = lop;
    }

    //getter và setter
    string getTendocgia(){
        return tendocgia;
    }

    void setTendocgia(string tendocgia){
        this->tendocgia = tendocgia;
    }

    string getMaso(){
        return maso;
    }

    void setMaso(string maso){
        this->maso = maso;
    }

    string getKhoa(){
        return khoa;
    }

    void setKhoa(string khoa){
        this->khoa = khoa;
    }

    string getLop(){
        return lop;
    }
};

class MuonSach{
private:
    Sach s;
    DocGia dg;
    int soluong;
public:
    MuonSach(){
        soluong = 0;
    }

    MuonSach(Sach s, DocGia dg, int soluong){
        this->s = s;
        this->dg = dg;
        this->soluong = soluong;
    }

    //getter và setter
    Sach getS(){
        return s;
    }

    void setS(Sach s){
        this->s = s;
    }

    DocGia getDg(){
        return dg;
    }

    void setDg(DocGia dg){
        this->dg = dg;
    }

    int getSoluong(){
        return soluong;
    }

    void setSoluong(int soluong){
        this->soluong = soluong;
    }
};

class ThuVien{
private:
    MuonSach *a;
    int n;
public:
   ThuVien(){
       a = NULL;
       n = 0;
   }

   ThuVien(int n){
       this->n = n;
       a = new MuonSach[n];
   }

   void nhap(){
        cout << "Nhap so luong sach: ";
        cin >> n;
        a = new MuonSach[n];
        for(int i = 0; i < n; i++){
            cout << "Nhap quyen sach thu " << i + 1 << endl;
            cout << "Nhap ten sach: ";
            string tensach;
            cin.ignore();
            getline(cin, tensach);
            cout << "Nhap tac gia: ";
            string tacgia;
            getline(cin, tacgia);
            cout << "Nhap nam xuat ban: ";
            int namxuatban;
            cin >> namxuatban;
            cout << "Nhap nha xuat ban: ";
            string nhaxuatban;
            cin.ignore();
            getline(cin, nhaxuatban);
            Sach s(tensach, tacgia, namxuatban, nhaxuatban);
            cout << "Nhap ten doc gia: ";
            string tendocgia;
            getline(cin, tendocgia);
            cout << "Nhap ma so: ";
            string maso;
            getline(cin, maso);
            cout << "Nhap khoa: ";
            string khoa;
            getline(cin, khoa);
            cout << "Nhap lop: ";
            string lop;
            getline(cin, lop);
            DocGia dg(tendocgia, maso, khoa, lop);
            cout << "Nhap so luong: ";
            int soluong;
            cin >> soluong;
            MuonSach ms(s, dg, soluong);
            a[i] = ms;
        }
   }

   //hàm xuất
    void xuat(){
         for(int i = 0; i < n; i++){
              cout << "Quyen sach thu " << i + 1 << endl;
              cout << "Ten sach: " << a[i].getS().getTensach() << endl;
              cout << "Tac gia: " << a[i].getS().getTacgia() << endl;
              cout << "Nam xuat ban: " << a[i].getS().getNamxuatban() << endl;
              cout << "Nha xuat ban: " << a[i].getS().getNhaxuatban() << endl;
              cout << "Ten doc gia: " << a[i].getDg().getTendocgia() << endl;
              cout << "Ma so: " << a[i].getDg().getMaso() << endl;
              cout << "Khoa: " << a[i].getDg().getKhoa() << endl;
              cout << "Lop: " << a[i].getDg().getLop() << endl;
              cout << "So luong: " << a[i].getSoluong() << endl;
         }
    }

    //cho biết sinh viên nào mượn nhiều sách nhất
    void sinhVienMuonNhieuSachNhat(){
        int max = a[0].getSoluong();
        for(int i = 1; i < n; i++){
            if(a[i].getSoluong() > max){
                max = a[i].getSoluong();
            }
        }
        cout << "Danh sach sinh vien muon nhieu sach nhat la: " << endl;
        for(int i = 0; i < n; i++){
            if(a[i].getSoluong() == max){
                cout << "Ten doc gia: " << a[i].getDg().getTendocgia() << endl;
                cout << "Ma so: " << a[i].getDg().getMaso() << endl;
                cout << "Khoa: " << a[i].getDg().getKhoa() << endl;
                cout << "Lop: " << a[i].getDg().getLop() << endl;
            }
        }
    }
};

int main(){
    ThuVien tv;
    tv.nhap();
    tv.xuat();
    tv.sinhVienMuonNhieuSachNhat();
    return 0;
}