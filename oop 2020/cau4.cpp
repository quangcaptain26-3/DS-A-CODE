#include<bits/stdc++.h>

using namespace std;

class ThiSinh{
protected:
    string hoten;
    float dtb;
    float diemAnh;
public:
    ThiSinh(){
        hoten = "";
        dtb = 0;
        diemAnh = 0;
    }

    ThiSinh(string hoten, float dtb, float diemAnh){
        this->hoten = hoten;
        this->dtb = dtb;
        this->diemAnh = diemAnh;
    }

    virtual bool dieukien(){
        return dtb >= 7 && diemAnh >= 400;
    }

    virtual void nhap(){
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
        cout << "Nhap diem anh: ";
        cin >> diemAnh;
    }

    virtual void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Diem trung binh: " << dtb << endl;
        cout << "Diem anh: " << diemAnh << endl;
    }
};


class ThiSinhUuTien : public ThiSinh{
private:
    int vung;
public:
    ThiSinhUuTien() : ThiSinh(){
        vung = 0;
    }

    ThiSinhUuTien(string hoten, float dtb, float diemAnh, int vung) : ThiSinh(hoten, dtb, diemAnh){
        this->vung = vung;
    }

    bool dieukien(){
        if(vung == 1){
            return dtb + 2 >= 7 && diemAnh >= 400;
        }
        else if(vung == 2){
            return dtb + 1 >= 7 && diemAnh >= 400;
        }
        else if(vung == 3){
            return dtb + 0.5 >= 7 && diemAnh >= 400;
        }
        else{
            return false;
        }
    }

    void nhap(){
        ThiSinh::nhap();
        cout << "Nhap vung uu tien: ";
        cin >> vung;
    }

    void xuat(){
        ThiSinh::xuat();
        cout << "Vung uu tien: " << vung << endl;
    }
};


int main(){
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    ThiSinh *a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
        cout << "Nhap 1 neu la thi sinh uu tien, 0 neu khong: ";
        int x;
        cin >> x;
        cin.ignore();
        if(x == 1){
            a[i] = new ThiSinhUuTien();
            a[i]->nhap();
        }else{
            a[i] = new ThiSinh();
            a[i]->nhap();
        }
    }
    cout << "------------------------------------" << endl;
    cout << "Danh sach thi sinh vua nhap: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Thi sinh thu " << i + 1 << endl;
        a[i]->xuat();
    }
    cout << "------------------------------------" << endl;
    cout << "Danh sach thi sinh trung tuyen khong vuot qua 30% so thi sinh: " << endl;
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i]->dieukien()){
            dem++;
        }
    }
    if(dem == 0){
        cout << "Khong co thi sinh nao trung tuyen" << endl;
    }else{
        for(int i = 0; i < n; i++){
            if(a[i]->dieukien()){
                cout << "Thi sinh thu " << i + 1 << endl;
                a[i]->xuat();
            }
        }
    }
    return 0;
}
