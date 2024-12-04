#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ThiSinh
{
protected:
    string hoten;
    string ma;
    float d1, d2, d3;

public:
    ThiSinh(string hoten, string ma, float d1, float d2, float d3)
    {
        this->hoten = hoten;
        this->ma = ma;
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
    }
    virtual float tongDiem()
    {
        return d1 + d2 + d3;
    }
    virtual void nhap()
    {
        cout << "Nhap ho ten: ";
        cin >> hoten;
        cout << "Nhap ma: ";
        cin >> ma;
        cout << "Nhap diem 1: ";
        cin >> d1;
        cout << "Nhap diem 2: ";
        cin >> d2;
        cout << "Nhap diem 3: ";
        cin >> d3;
    }
    virtual void xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Ma: " << ma << endl;
        cout << "Diem 1: " << d1 << endl;
        cout << "Diem 2: " << d2 << endl;
        cout << "Diem 3: " << d3 << endl;
    }
};

class UuTien : public ThiSinh
{
private:
    int loai;

public:

    UuTien(string hoten, string ma, float d1, float d2, float d3, int loai) : ThiSinh(hoten, ma, d1, d2, d3)
    {
        this->loai = loai;
    }
    float tongDiem()
    {
        if (loai == 1)
            return d1 + d2 + d3 + 1.5;
        else if (loai == 2)
            return d1 + d2 + d3 + 1;
        else
            return d1 + d2 + d3 + 0.5;
    }
    void nhap()
    {
        ThiSinh::nhap();
        cout << "Nhap loai uu tien: ";
        cin >> loai;
    }
    void xuat()
    {
        ThiSinh::xuat();
        cout << "Loai uu tien: " << loai << endl;
    }
};

bool cmp(ThiSinh *a, ThiSinh *b)
{
    return a->tongDiem() > b->tongDiem();
}

int main()
{
    vector<ThiSinh *> list;
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int type;
        cout << "Nhap loai thi sinh (1: Uu tien, 2: Binh thuong): ";
        cin >> type;
        if (type == 1)
        {
            ThiSinh *ts = new UuTien("", "", 0, 0, 0, 0);
            ts->nhap();
            list.push_back(ts);
        }
        else
        {
            ThiSinh *ts = new ThiSinh("", "", 0, 0, 0);
            ts->nhap();
            list.push_back(ts);
        }
    }
    sort(list.begin(), list.end(), cmp);
    cout << "==========================";
    cout << "Danh sach thi sinh: " << endl;
    for (int i = 0; i < list.size(); i++)
    {
        list[i]->xuat();
        cout << "Tong diem: " << list[i]->tongDiem() << endl;
    }
    return 0;
}