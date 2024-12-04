#include<bits/stdc++.h>

using namespace std;

class HinhTron{
private:
    float x; 
    float y;
    double r;
public:
    HinhTron(){
        x = 0;
        y = 0;
        r = 0;
    }

    HinhTron(float x, float y, double r){
        this->x = x;
        this->y = y;
        this->r = r;
    }

    void nhap(){
        cout << "Nhap x: ";
        cin >> x;
        cout << "Nhap y: ";
        cin >> y;
        cout << "Nhap r: ";
        cin >> r;
    }

    void xuat(){
        cout << "Toa do tam: (" << x << ", " << y << ")" << endl;
        cout << "Ban kinh: " << r << endl;
    }

    double tinhDienTich(){
        return 3.14 * r * r;
    }

    bool kiemtraDiem(float x, float y){
        return (x - this->x) * (x - this->x) + (y - this->y) * (y - this->y) <= r * r;
    }
};


int main(){
    int n;
    cout << "Nhap so luong hinh tron: ";
    cin >> n;
    HinhTron *a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap hinh tron thu " << i + 1 << endl;
        a[i] = new HinhTron;
        a[i]->nhap();
    }
    cout << "Cac hinh tron vua nhap la: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Hinh tron thu " << i + 1 << endl;
        a[i]->xuat();
    }
    
    //sắp xếp các hình tròn theo diện tích giảm dần
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++)
            if(a[i]->tinhDienTich() < a[j]->tinhDienTich())
                swap(a[i], a[j]);
    }
    cout << "------------------------------------" << endl;
    cout << "Danh sach hinh tron sau khi sap xep: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Hinh tron thu " << i + 1 << endl;
        a[i]->xuat();
    }
    //in ra tối đa 10% diện tích lớn nhất và không chứa điểm đã nhập
    float x, y;
    cout << "Nhap toa do diem: ";
    cin >> x >> y;
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i]->kiemtraDiem(x, y) == false)
            dem++;
    }
    int k = dem / 10;
    if(dem % 10 != 0)
        k++;
    cout << "------------------------------------" << endl;
    cout << "Danh sach " << k << " hinh tron co dien tich lon nhat va khong chua diem (" << x << ", " << y << "): " << endl;
    for(int i = 0; i < k; i++){
        cout << "Hinh tron thu " << i + 1 << endl;
        a[i]->xuat();
    }
    
    return 0;
}
