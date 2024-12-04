#include <iostream>
#include <string>

using namespace std;

class HangHoa {
private:
    int ma;
    string tenhang;
    int gianhap;
    int giaban;
    int soluong;

public:
    HangHoa() : ma(0), tenhang(""), gianhap(0), giaban(0), soluong(0) {}

    HangHoa(const HangHoa &a) : ma(a.ma), tenhang(a.tenhang), gianhap(a.gianhap), giaban(a.giaban), soluong(a.soluong) {}

    ~HangHoa() {}

    friend istream &operator>>(istream &is, HangHoa &a) {
        cout << "Nhap ma hang: ";
        is >> a.ma;
        cout << "Nhap ten hang: ";
        is.ignore();
        getline(is, a.tenhang);
        cout << "Nhap gia nhap: ";
        is >> a.gianhap;
        cout << "Nhap gia ban: ";
        is >> a.giaban;
        cout << "Nhap so luong: ";
        is >> a.soluong;
        return is;
    }

    friend ostream &operator<<(ostream &os, const HangHoa &a) {
        os << "Ma hang: " << a.ma << endl;
        os << "Ten hang: " << a.tenhang << endl;
        os << "Gia nhap: " << a.gianhap << endl;
        os << "Gia ban: " << a.giaban << endl;
        os << "So luong: " << a.soluong << endl;
        return os;
    }

    int LoiNhuan() const {
        return (giaban - gianhap) * soluong;
    }

    bool operator<(const HangHoa &a) const {
        return this->LoiNhuan() < a.LoiNhuan();
    }

    int getSoluong() const {
        return soluong;
    }
};

void bubbleSort(HangHoa arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    HangHoa *a = new HangHoa[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap hang hoa thu " << i + 1 << ":\n";
        cin >> a[i];
    }

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        totalProfit += a[i].LoiNhuan();
    }
    cout << "Tong loi nhuan cua cac hang hoa: " << totalProfit << endl;

    bubbleSort(a, n);

    int topPercent = max(1, n / 10); 
    cout << "Danh sach toi da 10% mat hang loi nhuan cao nhat co so luong ton kho lon hon 5:\n";
    for (int i = 0, count = 0; i < n && count < topPercent; i++) {
        if (a[i].getSoluong() < 5) {
            cout << a[i];
            count++;
        }
    }

    delete[] a;
    return 0;
}
