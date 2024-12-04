#include<bits/stdc++.h>

using namespace std;

class HinhTron{
private:
    float x;
    float y;
    float r;
public:
    //hảm khởi tạo
    HinhTron(){
        x = 0;
        y = 0;
        r = 0;
    }

    //cấu tử sao chép
    HinhTron(const HinhTron &h){
        x = h.x;
        y = h.y;
        r = h.r;
    }

    //quá tải >> để nhập
    friend istream &operator>>(istream &is, HinhTron &h){
        cout << "Nhap x: ";
        is >> h.x;
        cout << "Nhap y: ";
        is >> h.y;
        cout << "Nhap r: ";
        is >> h.r;
        return is;
    }

    //quá tải << để xuất
    friend ostream &operator<<(ostream &os, HinhTron &h){
        os << "x = " << h.x << endl;
        os << "y = " << h.y << endl;
        os << "r = " << h.r << endl;
        os << "Dien tich = " << h.dienTich() << endl;
        return os;
    }

    //hàm tính diện tích
    float dienTich(){
        return 3.14 * r * r;
    }

    //hàm kiểm tra 1 điểm có nằm trong hình tròn hay không
    bool kiemTraDiem(float x1, float y1){
        float kc = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
        if(kc <= r){
            return true;
        }
        return false;
    }
};

int main(){
    //nhập vào 1 mảng hình tròn và 1 điểm
    int n;
    cout << "Nhap n: ";
    cin >> n;
    HinhTron *a = new HinhTron[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap hinh tron thu " << i + 1 << endl;
        cin >> a[i];
    }
    float x1, y1;
    cout << "Nhap x1: ";
    cin >> x1;
    cout << "Nhap y1: ";
    cin >> y1;

    //in ra các hình tròn vừa nhập
    for(int i = 0; i < n; i++){
        cout << "Hinh tron thu " << i + 1 << endl;
        cout << a[i];
    }

    //sắp xếp các hình tròn theo diện tích giảm dần
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n ; j++){
            if(a[i].dienTich() < a[j].dienTich()){
                HinhTron temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    //in ra các hình tròn sau khi sắp xếp
    cout << "Cac hinh tron sau khi sap xep: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Hinh tron thu " << i + 1 << endl;
        cout << a[i];
    }

    //in ra các hình tròn có diện tích lớn nhất và không chứa điểm đã nhập
    cout << "Cac hinh tron co dien tich lon nhat va khong chua diem da nhap: " << endl;
    for(int i = 0; i < n; i++){
        if(a[i].kiemTraDiem(x1, y1) == false){
            cout << "Hinh tron thu " << i + 1 << endl;
            cout << a[i];
            break;
        }
    }
    return 0;
}