//Thông tin của nhân viên trong một công ty gồm: mã nhân viên, họ tên, lương. Hãy khai báo cấu trúc dữ liệu cây tìm kiếm nhị phân để lưu thông tin trên. Khóa là mã nhân viên

typedef struct NhanVien{
    char ten[30];
    int mnv;
    float hsl;
    int namsinh;
    struct NhanVien *next;
}NV;


typedef struct tagNode{
    NV data;
    struct tagNode *left;
    struct tagNode *right;
}Node;

