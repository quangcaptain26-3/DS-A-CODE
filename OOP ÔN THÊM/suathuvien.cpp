#include <iostream>
using namespace std;

class sach
{
	string tensach;
	string tacgia;
	int nam;
	string nxb;
	public:
		sach()
		{
			tensach = "";
			tacgia = "";
			nam = 0;
			nxb = "";
		}
		void nhap()
		{
			cout << "Ten sach: ";
			cin >> tensach;
			cout << "Tac gia: ";
			cin >> tacgia;
			cout << "Nam xuat ban: ";
			cin >> nam;
			cout << "Nha xuat ban: ";
			cin >> nxb;
		}		
		void xuat ()
		{
			cout << tensach << " " << tacgia << " " << nam << " " << endl;
		}
		friend class DocGia;
};
class DocGia
{
	string hoten;
	int ma;
	string khoa;
	string lop;
	int sosach;
	sach *a; 
	public:
	DocGia()
	{
		hoten = "";
		ma = 0;
		khoa = "";
		lop = "";
		sosach = 0;
		a = NULL;
	}
	void nhap()
	{
		cout << "Ho ten: "; 
		cin >> hoten;
		cout << "Ma: ";
		cin >> ma;
		cout << "Khoa: ";
		cin >> khoa;
		cout << "Lop: ";
		cin >> lop;
		cout << "So sach muon: ";
		cin >> sosach;
		a = new sach[sosach];
		for (int i = 0; i<sosach; i++)
		{
			a[i].nhap();
		}
	}
	void xuat()
	{
		cout << "Ho ten: " << hoten << endl;
		cout << "Ma: " << ma << endl;	
	}
	friend void max(DocGia[], int n);
};
void max(DocGia a[], int n)
	{
		DocGia max = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i].sosach>max.sosach) max = a[i];
		}
		max.xuat();
	}
int main()
{
	DocGia *a;
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		a[i].nhap();
	}
	for (int i = 0; i<n; i++)
	{
		a[i].xuat();
	}
	cout << "Sinh vien muon nhieu nhat: ";
	max(a, n);
}