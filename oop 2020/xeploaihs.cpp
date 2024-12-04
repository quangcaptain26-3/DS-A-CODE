#include<iostream>
#include<string.h>

using namespace std;

class HS{
private:
    string name;
    int msv;
    float toan;
    float triet;
    float ltc;
public:
    HS(){
        name = "";
        msv = 0;
        toan = 0;
        triet = 0;
        ltc = 0;
    }

    HS(string name, int msv, float toan, float triet, float ltc){
        this->name = name;
        this->msv = msv;
        this->toan = toan;
        this->triet = triet;
        this->ltc = ltc;
    }


    void setName(string name){
        this->name = name;
    }

    void setMsv(int msv){
        this->msv = msv;
    }

    void setToan(float toan){
        this->toan = toan;
    }

    void setTriet(float triet){
        this->triet = triet;
    }

    void setLtc(float ltc){
        this->ltc = ltc;
    }

    string getName(){
        return name;
    }

    int getMsv(){
        return msv;
    }

    float getToan(){
        return toan;
    }

    float getTriet(){
        return triet;
    }

    float getLtc(){
        return ltc;
    }

    void nhap(){
        cin >> name >> msv >> toan >> triet >> ltc;
    }

    void xuat(){
        cout << name << " " << msv << " " << toan << " " << triet << " " << ltc << endl;
    }


    bool hocLai(){
        if(toan < 4 && triet < 4){
            return true;
        }
        if(toan < 4 && ltc < 4){
            return true;
        }
        if(triet < 4 && ltc < 4){
            return true;
        }
        return false;
    }

};

int main(){
    int n;
    cin >> n;
    HS *hs = new HS[n];
    for(int i = 0; i < n; i++){
        hs[i].nhap();
    }
    int count = 0;
    cout << "Danh sach sinh vien hoc lai" << endl;
    for(int i = 0; i < n; i++){
        if(hs[i].hocLai()){
            hs[i].xuat();
            count++;
        }
    }
    if(count == 0){
        cout << "Khong co sinh vien hoc lai" << endl;
    }
    else{
        cout << "Co " << count << " sinh vien hoc lai" << endl;
    }
    return 0;
}