#include<iostream>

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

    string getHoten(){
        return hoten;
    }

    void setHoten(string hoten){
        this->hoten = hoten;
    }

    float getDtb() const{
        return dtb;
    }

    void setDtb(float dtb){
        this->dtb = dtb;
    }

    float getDiemAnh() const{
        return diemAnh;
    }

    void setDiemAnh(float diemAnh){
        this->diemAnh = diemAnh;
    }

    virtual void nhap(){
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
        cout << "Nhap diem anh: ";
        cin >> diemAnh;
    }

    virtual void xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Diem trung binh: " << dtb << endl;
        cout << "Diem Anh: " << diemAnh << endl;
    }

    virtual bool xetTuyen(){
        if(dtb >= 7.0 && diemAnh >= 400){
            return true;
        }
        return false;
    }
};

class ThiSinhUuTien : public ThiSinh{
protected:
    int vung;
public:
    ThiSinhUuTien() : ThiSinh(){
        vung = 0;
    }

    ThiSinhUuTien(string hoten, float dtb, float diemAnh, int vung) : ThiSinh(hoten, dtb, diemAnh){
        this->vung = vung;
    }

    //getter and setter
    int getVung(){
        return vung;
    }

    void setVung(int vung){
        this->vung = vung;
    }

    virtual double getDiemUuTien(){
        if(vung == 1){
            return dtb + 0.5;
        }
        else if(vung == 2){
            return dtb + 1.0;
        }
        else if(vung == 3){
            return dtb + 2.0;
        }
        return 0;
    }

    virtual void nhap(){
        ThiSinh::nhap();
        cout << "Nhap vung uu tien: ";
        cin >> vung;
    }

    virtual void xuat(){
        ThiSinh::xuat();
        cout << "Vung uu tien: " << vung << endl;
    }

    virtual bool xetTuyen(){
        if(getDiemUuTien() >= 7.0 && diemAnh >= 400){
            return true;
        }
        return false;
    }
};

int main(){
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    ThiSinh *a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
        int choice;
        cout << "Nhap 1 de nhap thong tin thi sinh thuong, 2 de nhap thong tin thi sinh uu tien: ";
        cin >> choice;
        if(choice == 1){
            a[i] = new ThiSinh();
            a[i]->nhap();
        }
        else if(choice == 2){
            a[i] = new ThiSinhUuTien();
            a[i]->nhap();
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "Danh sach cac thi sinh : " << endl;
    for(int i = 0; i < n; i++){
        a[i]->xuat();
    }


    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i]->xetTuyen()){
            count++;
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "Danh sach thi sinh trung tuyen khong vuot qua 30% tong so thi sinh: " << endl;
    for(int i = 0; i < n; i++){
        if(a[i]->xetTuyen()){
            a[i]->xuat();
            count--;
            if(count == 0){
                break;
            }
        }
    }
    return 0;
}