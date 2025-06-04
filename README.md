# 🚀 Data Structures & Algorithms (C) + Object-Oriented Programming (C++)

<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d4.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)

### 📚 Tài liệu học tập hoàn chỉnh về DS&A và OOP
### 🎯 Từ cơ bản đến nâng cao với ví dụ thực tế

[![Stars](https://img.shields.io/github/stars/username/repo?style=social)](https://github.com/username/repo)
[![Forks](https://img.shields.io/github/forks/username/repo?style=social)](https://github.com/username/repo)
[![Issues](https://img.shields.io/github/issues/username/repo)](https://github.com/username/repo/issues)

</div>

---

## 📋 Mục lục
- [🎯 Giới thiệu](#-giới-thiệu)
- [📁 Cấu trúc thư mục](#-cấu-trúc-thư-mục)
- [🔧 Data Structures & Algorithms (C)](#-data-structures--algorithms-c)
- [🏗️ Object-Oriented Programming (C++)](#️-object-oriented-programming-c)
- [🚀 Cách sử dụng](#-cách-sử-dụng)
- [⚙️ Yêu cầu hệ thống](#️-yêu-cầu-hệ-thống)
- [🤝 Đóng góp](#-đóng-góp)
- [📖 Tài liệu tham khảo](#-tài-liệu-tham-khảo)

---

## 🎯 Giới thiệu

<div align="center">

🎉 **Chào mừng đến với repository học tập tuyệt vời!** 🎉

</div>

Repository này chứa các implementation và ví dụ về:
- 🔢 **Data Structures & Algorithms** được viết bằng ngôn ngữ **C** 
- 🏛️ **Object-Oriented Programming** được viết bằng ngôn ngữ **C++**

### ✨ Tính năng nổi bật:
- 📝 Lý thuyết đầy đủ và dễ hiểu
- 💻 Code examples thực tế
- 🎯 Bài tập thực hành đa dạng
- 🔍 Phân tích độ phức tạp chi tiết
- 🚀 Từ cơ bản đến nâng cao

---

## 📁 Cấu trúc thư mục

```
📦 DSA-OOP-Repository/
├── 🔢 DSA_C/
│   ├── 📊 DataStructures/
│   │   ├── 🗂️ Array/
│   │   ├── 🔗 LinkedList/
│   │   ├── 📚 Stack/
│   │   ├── 🚶 Queue/
│   │   ├── 🌳 Tree/
│   │   └── 🕸️ Graph/
│   ├── ⚡ Algorithms/
│   │   ├── 🔄 Sorting/
│   │   ├── 🔍 Searching/
│   │   └── 🧮 DynamicProgramming/
│   └── 💡 Examples/
├── 🏗️ OOP_CPP/
│   ├── 📖 BasicConcepts/
│   ├── 🏛️ Classes/
│   ├── 👨‍👩‍👧‍👦 Inheritance/
│   ├── 🎭 Polymorphism/
│   ├── 🔒 Encapsulation/
│   └── 🚀 Projects/
└── 📋 README.md
```

---

# 🔢 Data Structures & Algorithms (C)

<div align="center">

## 🎯 **Chinh phục thế giới cấu trúc dữ liệu!** 

</div>

---

## 📊 Cấu trúc dữ liệu (Data Structures)

### 🗂️ 1. Array (Mảng)

<div align="center">

![Array](https://img.shields.io/badge/Complexity-O(1)%20Access-brightgreen?style=flat-square&logo=checkmarx)
![Memory](https://img.shields.io/badge/Memory-Contiguous-blue?style=flat-square&logo=memory)

</div>

**🔍 Khái niệm:** Tập hợp các phần tử cùng kiểu dữ liệu được lưu trữ liên tiếp trong bộ nhớ.

**✨ Đặc điểm:**
- ⚡ Truy cập ngẫu nhiên với độ phức tạp O(1)
- 📏 Kích thước cố định
- 🎯 Dữ liệu được lưu trữ liên tiếp

**💻 Ví dụ đơn giản:**
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // 🎯 Truy cập phần tử
    printf("🔢 Phần tử thứ 3: %d\n", arr[2]);
    
    // 🔄 Duyệt mảng
    printf("📋 Các phần tử: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
```

### 🔗 2. Linked List (Danh sách liên kết)

<div align="center">

![LinkedList](https://img.shields.io/badge/Complexity-O(1)%20Insert-green?style=flat-square&logo=link)
![Dynamic](https://img.shields.io/badge/Memory-Dynamic-orange?style=flat-square&logo=expand-arrows-alt)

</div>

**🔍 Khái niệm:** Cấu trúc dữ liệu động gồm các node, mỗi node chứa data và pointer trỏ đến node tiếp theo.

**✨ Đặc điểm:**
- 📈 Kích thước động
- ⚡ Chèn/xóa hiệu quả ở đầu danh sách O(1)
- 🔄 Truy cập tuần tự O(n)

**💻 Ví dụ đơn giản:**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 🆕 Tạo node mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    printf("✅ Đã tạo node với giá trị: %d\n", data);
    return newNode;
}

// 🖨️ In danh sách
void printList(Node* head) {
    printf("📋 Danh sách: ");
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```

### 📚 3. Stack (Ngăn xếp)

<div align="center">

![Stack](https://img.shields.io/badge/Type-LIFO-red?style=flat-square&logo=stack-overflow)
![Operations](https://img.shields.io/badge/Operations-Push%2FPop-blue?style=flat-square&logo=arrows-alt-v)

</div>

**🔍 Khái niệm:** Cấu trúc dữ liệu LIFO (Last In First Out) - phần tử cuối cùng được thêm vào sẽ được lấy ra đầu tiên.

**🎯 Các thao tác cơ bản:**
- ⬆️ `push()`: Thêm phần tử vào đỉnh stack
- ⬇️ `pop()`: Lấy phần tử ở đỉnh stack
- 👁️ `top()`: Xem phần tử ở đỉnh stack
- ❓ `isEmpty()`: Kiểm tra stack rỗng

**💻 Ví dụ đơn giản:**
```c
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// 🆕 Khởi tạo stack
void initStack(Stack* s) {
    s->top = -1;
    printf("✅ Stack đã được khởi tạo!\n");
}

// ⬆️ Push phần tử
void push(Stack* s, int data) {
    if(s->top < MAX_SIZE - 1) {
        s->arr[++s->top] = data;
        printf("📥 Đã push: %d\n", data);
    } else {
        printf("❌ Stack đầy!\n");
    }
}

// ⬇️ Pop phần tử
int pop(Stack* s) {
    if(s->top >= 0) {
        int data = s->arr[s->top--];
        printf("📤 Đã pop: %d\n", data);
        return data;
    }
    printf("❌ Stack rỗng!\n");
    return -1;
}
```

### 🚶 4. Queue (Hàng đợi)

<div align="center">

![Queue](https://img.shields.io/badge/Type-FIFO-green?style=flat-square&logo=queue)
![Operations](https://img.shields.io/badge/Operations-Enqueue%2FDequeue-blue?style=flat-square&logo=arrows-alt-h)

</div>

**🔍 Khái niệm:** Cấu trúc dữ liệu FIFO (First In First Out) - phần tử đầu tiên được thêm vào sẽ được lấy ra đầu tiên.

**🎯 Các thao tác cơ bản:**
- ➡️ `enqueue()`: Thêm phần tử vào cuối queue
- ⬅️ `dequeue()`: Lấy phần tử ở đầu queue
- 👁️ `front()`: Xem phần tử ở đầu queue
- ❓ `isEmpty()`: Kiểm tra queue rỗng

### 🌳 5. Tree (Cây)

<div align="center">

![Tree](https://img.shields.io/badge/Structure-Hierarchical-brown?style=flat-square&logo=tree)
![BST](https://img.shields.io/badge/BST-O(log%20n)-success?style=flat-square&logo=search)

</div>

**🔍 Khái niệm:** Cấu trúc dữ liệu phân cấp gồm các node được kết nối bởi các cạnh, có một node gốc và không có chu trình.

**🎯 Binary Search Tree (BST):**
- ⬅️ Node trái < Node gốc < Node phải ➡️
- 🔍 Tìm kiếm, chèn, xóa: O(log n) trung bình

### 🕸️ 6. Graph (Đồ thị)

<div align="center">

![Graph](https://img.shields.io/badge/Structure-Network-purple?style=flat-square&logo=project-diagram)
![Types](https://img.shields.io/badge/Types-Directed%2FUndirected-blue?style=flat-square&logo=code-branch)

</div>

**🔍 Khái niệm:** Tập hợp các đỉnh (vertices) được kết nối bởi các cạnh (edges).

**📊 Phân loại:**
- 🎯 Directed/Undirected Graph
- ⚖️ Weighted/Unweighted Graph

---

## ⚡ Thuật toán (Algorithms)

### 🔄 1. Thuật toán sắp xếp (Sorting)

#### 🫧 Bubble Sort
<div align="center">

![Bubble Sort](https://img.shields.io/badge/Complexity-O(n²)-red?style=flat-square&logo=sort-numeric-down)
![Stable](https://img.shields.io/badge/Stable-Yes-green?style=flat-square&logo=check-circle)

</div>

```c
void bubbleSort(int arr[], int n) {
    printf("🫧 Bắt đầu Bubble Sort...\n");
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // 🔄 Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                printf("🔄 Đã swap: %d <-> %d\n", arr[j+1], arr[j]);
            }
        }
    }
    printf("✅ Bubble Sort hoàn thành!\n");
}
```

#### ⚡ Quick Sort
<div align="center">

![Quick Sort](https://img.shields.io/badge/Complexity-O(n%20log%20n)-green?style=flat-square&logo=zap)
![InPlace](https://img.shields.io/badge/InPlace-Yes-blue?style=flat-square&logo=compress-arrows-alt)

</div>

#### 🔀 Merge Sort
<div align="center">

![Merge Sort](https://img.shields.io/badge/Complexity-O(n%20log%20n)-green?style=flat-square&logo=code-branch)
![Stable](https://img.shields.io/badge/Stable-Yes-green?style=flat-square&logo=check-circle)

</div>

### 🔍 2. Thuật toán tìm kiếm (Searching)

#### 📏 Linear Search
<div align="center">

![Linear Search](https://img.shields.io/badge/Complexity-O(n)-orange?style=flat-square&logo=search)
![Simple](https://img.shields.io/badge/Type-Simple-blue?style=flat-square&logo=eye)

</div>

```c
int linearSearch(int arr[], int n, int target) {
    printf("🔍 Tìm kiếm tuyến tính cho: %d\n", target);
    for(int i = 0; i < n; i++) {
        printf("👀 Kiểm tra vị trí %d: %d\n", i, arr[i]);
        if(arr[i] == target) {
            printf("✅ Tìm thấy tại vị trí: %d\n", i);
            return i;
        }
    }
    printf("❌ Không tìm thấy!\n");
    return -1;
}
```

#### 🎯 Binary Search
<div align="center">

![Binary Search](https://img.shields.io/badge/Complexity-O(log%20n)-brightgreen?style=flat-square&logo=bullseye)
![Sorted](https://img.shields.io/badge/Requirement-Sorted%20Array-red?style=flat-square&logo=sort-amount-up)

</div>

```c
int binarySearch(int arr[], int left, int right, int target) {
    printf("🎯 Binary Search cho: %d\n", target);
    while(left <= right) {
        int mid = left + (right - left) / 2;
        printf("📍 Kiểm tra giữa[%d]: %d\n", mid, arr[mid]);
        
        if(arr[mid] == target) {
            printf("🎉 Tìm thấy tại vị trí: %d\n", mid);
            return mid;
        }
        
        if(arr[mid] < target) {
            left = mid + 1;
            printf("➡️ Tìm bên phải\n");
        } else {
            right = mid - 1;
            printf("⬅️ Tìm bên trái\n");
        }
    }
    printf("❌ Không tìm thấy!\n");
    return -1;
}
```

### 🧮 3. Dynamic Programming
<div align="center">

![DP](https://img.shields.io/badge/Technique-Optimization-gold?style=flat-square&logo=chart-line)
![Memoization](https://img.shields.io/badge/Method-Memoization-purple?style=flat-square&logo=memory)

</div>

**🔍 Khái niệm:** Kỹ thuật giải quyết bài toán bằng cách chia nhỏ thành các bài toán con và lưu trữ kết quả để tránh tính toán lại.

---

# 🏗️ Object-Oriented Programming (C++)

<div align="center">

## 🎯 **Khám phá sức mạnh của OOP!** 

</div>

---

## 🏛️ Các khái niệm cơ bản OOP

### 📝 1. Class và Object

<div align="center">

![OOP](https://img.shields.io/badge/Paradigm-Object%20Oriented-blue?style=flat-square&logo=c%2B%2B)
![Encapsulation](https://img.shields.io/badge/Feature-Encapsulation-green?style=flat-square&logo=lock)

</div>

**🏛️ Class (Lớp):** Template hoặc blueprint để tạo ra objects.  
**🎯 Object (Đối tượng):** Instance của một class.

**💻 Ví dụ đơn giản:**
```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    float gpa;

public:
    // 🏗️ Constructor
    Student(string n, int a, float g) {
        name = n;
        age = a;
        gpa = g;
        cout << "🎓 Đã tạo sinh viên: " << name << endl;
    }
    
    // 📖 Getter methods
    string getName() { return name; }
    int getAge() { return age; }
    float getGPA() { return gpa; }
    
    // 📄 Method to display info
    void displayInfo() {
        cout << "\n📋 THÔNG TIN SINH VIÊN" << endl;
        cout << "👤 Tên: " << name << endl;
        cout << "🎂 Tuổi: " << age << endl;
        cout << "📊 GPA: " << gpa << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Student student1("Nguyễn Văn A", 20, 3.5);
    student1.displayInfo();
    return 0;
}
```

### 🔒 2. Encapsulation (Đóng gói)

<div align="center">

![Encapsulation](https://img.shields.io/badge/Principle-Data%20Hiding-red?style=flat-square&logo=eye-slash)
![Security](https://img.shields.io/badge/Benefit-Security-green?style=flat-square&logo=shield-alt)

</div>

**🔍 Khái niệm:** Ẩn chi tiết implementation và chỉ cung cấp interface cần thiết.

**🎯 Access Modifiers:**
- 🔒 `private`: Chỉ truy cập được trong class
- 🌐 `public`: Truy cập được từ bên ngoài
- 👨‍👩‍👧‍👦 `protected`: Truy cập được trong class và derived class

### 👨‍👩‍👧‍👦 3. Inheritance (Kế thừa)

<div align="center">

![Inheritance](https://img.shields.io/badge/Relationship-IS--A-blue?style=flat-square&logo=sitemap)
![Reusability](https://img.shields.io/badge/Benefit-Code%20Reuse-green?style=flat-square&logo=recycle)

</div>

**🔍 Khái niệm:** Một class có thể kế thừa properties và methods từ class khác.

**💻 Ví dụ:**
```cpp
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {
        cout << "👤 Đã tạo Person: " << name << endl;
    }
    
    void introduce() {
        cout << "👋 Xin chào, tôi là " << name 
             << ", " << age << " tuổi." << endl;
    }
};

class Student : public Person {
private:
    string studentId;
    float gpa;

public:
    Student(string n, int a, string id, float g) 
        : Person(n, a), studentId(id), gpa(g) {
        cout << "🎓 Đã tạo Student với ID: " << id << endl;
    }
    
    void study() {
        cout << "📚 " << name << " đang học bài." << endl;
    }
    
    void displayGPA() {
        cout << "📊 GPA của " << name << ": " << gpa << endl;
    }
};
```

### 🎭 4. Polymorphism (Đa hình)

<div align="center">

![Polymorphism](https://img.shields.io/badge/Feature-Many%20Forms-purple?style=flat-square&logo=shapes)
![Flexibility](https://img.shields.io/badge/Benefit-Flexibility-orange?style=flat-square&logo=expand-arrows-alt)

</div>

**🔍 Khái niệm:** Khả năng sử dụng một interface để đại diện cho các kiểu dữ liệu khác nhau.

#### 🔄 Function Overloading
```cpp
class Calculator {
public:
    // ➕ Cộng 2 số nguyên
    int add(int a, int b) {
        cout << "🔢 Cộng 2 số nguyên: " << a << " + " << b << endl;
        return a + b;
    }
    
    // ➕ Cộng 2 số thực
    double add(double a, double b) {
        cout << "🔢 Cộng 2 số thực: " << a << " + " << b << endl;
        return a + b;
    }
    
    // ➕ Cộng 3 số nguyên
    int add(int a, int b, int c) {
        cout << "🔢 Cộng 3 số: " << a << " + " << b << " + " << c << endl;
        return a + b + c;
    }
};
```

#### 🎪 Virtual Functions
```cpp
class Shape {
public:
    virtual double getArea() = 0; // 🎯 Pure virtual function
    virtual void draw() {
        cout << "🎨 Đang vẽ một hình" << endl;
    }
    
    virtual ~Shape() {
        cout << "🗑️ Destructor Shape" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        cout << "⭕ Đã tạo hình tròn bán kính: " << r << endl;
    }
    
    double getArea() override {
        double area = 3.14159 * radius * radius;
        cout << "📐 Diện tích hình tròn: " << area << endl;
        return area;
    }
    
    void draw() override {
        cout << "🎨 Đang vẽ hình tròn" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        cout << "📐 Đã tạo hình chữ nhật: " << w << "x" << h << endl;
    }
    
    double getArea() override {
        double area = width * height;
        cout << "📐 Diện tích hình chữ nhật: " << area << endl;
        return area;
    }
    
    void draw() override {
        cout << "🎨 Đang vẽ hình chữ nhật" << endl;
    }
};
```

### 🎯 5. Abstraction (Trừu tượng hóa)

<div align="center">

![Abstraction](https://img.shields.io/badge/Concept-Hide%20Complexity-indigo?style=flat-square&logo=eye-slash)
![Interface](https://img.shields.io/badge/Focus-Interface-blue?style=flat-square&logo=window-maximize)

</div>

**🔍 Khái niệm:** Ẩn các chi tiết phức tạp và chỉ hiển thị các tính năng cần thiết.

**🎯 Abstract Class:** Class chứa ít nhất một pure virtual function.

### 🏗️ 6. Constructor và Destructor

<div align="center">

![Constructor](https://img.shields.io/badge/Constructor-Object%20Creation-green?style=flat-square&logo=plus-circle)
![Destructor](https://img.shields.io/badge/Destructor-Cleanup-red?style=flat-square&logo=trash-alt)

</div>

```cpp
class MyClass {
private:
    int* data;
    string name;

public:
    // 🏗️ Default Constructor
    MyClass() {
        data = new int(0);
        name = "Default";
        cout << "🆕 Default constructor called for " << name << endl;
    }
    
    // 🎯 Parameterized Constructor
    MyClass(int value, string n) {
        data = new int(value);
        name = n;
        cout << "🆕 Parameterized constructor called for " << name << endl;
    }
    
    // 📋 Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
        name = other.name + "_copy";
        cout << "📋 Copy constructor called for " << name << endl;
    }
    
    // 🗑️ Destructor
    ~MyClass() {
        delete data;
        cout << "🗑️ Destructor called for " << name << endl;
    }
    
    // 📊 Display method
    void display() {
        cout << "📊 " << name << " - Value: " << *data << endl;
    }
};
```

---

## 🎨 Design Patterns cơ bản

### 🏆 1. Singleton Pattern

<div align="center">

![Singleton](https://img.shields.io/badge/Pattern-Singleton-gold?style=flat-square&logo=crown)
![Instance](https://img.shields.io/badge/Instances-One%20Only-red?style=flat-square&logo=numeric-1-circle)

</div>

```cpp
class Singleton {
private:
    static Singleton* instance;
    string data;
    
    // 🔒 Private constructor
    Singleton() {
        data = "Singleton Instance";
        cout << "🏆 Singleton instance created!" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        cout << "📋 Returning singleton instance" << endl;
        return instance;
    }
    
    void showData() {
        cout << "📊 Data: " << data << endl;
    }
    
    // 🚫 Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// 🎯 Initialize static member
Singleton* Singleton::instance = nullptr;
```

### 🏭 2. Factory Pattern

<div align="center">

![Factory](https://img.shields.io/badge/Pattern-Factory-blue?style=flat-square&logo=industry)
![Creation](https://img.shields.io/badge/Purpose-Object%20Creation-green?style=flat-square&logo=plus-circle)

</div>

```cpp
class Animal {
public:
    virtual void makeSound() = 0;
    virtual void getInfo() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "🐕 Gâu gâu!" << endl;
    }
    
    void getInfo() override {
        cout << "🐕 Tôi là một con chó" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "🐱 Meo meo!" << endl;
    }
    
    void getInfo() override {
        cout << "🐱 Tôi là một con mèo" << endl;
    }
};

class Bird : public Animal {
public:
    void makeSound() override {
        cout << "🐦 Tweet tweet!" << endl;
    }
    
    void getInfo() override {
        cout << "🐦 Tôi là một con chim" << endl;
    }
};

class AnimalFactory {
public:
    static Animal* createAnimal(string type) {
        if(type == "dog") {
            cout << "🏭 Đang tạo con chó..." << endl;
            return new Dog();
        }
        else if(type == "cat") {
            cout << "🏭 Đang tạo con mèo..." << endl;
            return new Cat();
        }
        else if(type == "bird") {
            cout << "🏭 Đang tạo con chim..." << endl;
            return new Bird();
        }
        else {
            cout << "❌ Không thể tạo loại động vật: " << type << endl;
            return nullptr;
        }
    }
};
```

### 🎭 3. Observer Pattern

<div align="center">

![Observer](https://img.shields.io/badge/Pattern-Observer-purple?style=flat-square&logo=eye)
![Notification](https://img.shields.io/badge/Purpose-Event%20Notification-orange?style=flat-square&logo=bell)

</div>

```cpp
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update(string message) = 0;
    virtual ~Observer() = default;
};

class Subject {
private:
    vector<Observer*> observers;
    string state;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
        cout << "👁️ Observer đã được đăng ký!" << endl;
    }
    
    void detach(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), 
                       observers.end());
        cout << "👋 Observer đã được gỡ bỏ!" << endl;
    }
    
    void notify() {
        cout << "📢 Thông báo cho " << observers.size() << " observers..." << endl;
        for(Observer* observer : observers) {
            observer->update(state);
        }
    }
    
    void setState(string newState) {
        state = newState;
        cout << "🔄 Trạng thái đã thay đổi: " << state << endl;
        notify();
    }
};

class ConcreteObserver : public Observer {
private:
    string name;

public:
    ConcreteObserver(string n) : name(n) {
        cout << "👁️ Observer " << name << " đã được tạo!" << endl;
    }
    
    void update(string message) override {
        cout << "📨 " << name << " nhận được thông báo: " << message << endl;
    }
};
```

---

## 🚀 Cách sử dụng

<div align="center">

### 💻 **Hướng dẫn biên dịch và chạy code**

</div>

### 🔧 Biên dịch code C:
```bash
# 🏗️ Biên dịch cơ bản
gcc -o program program.c

# 🚀 Chạy chương trình
./program

# 🐛 Biên dịch với debug info
gcc -g -Wall -Wextra -o program program.c

# 📊 Biên dịch với optimization
gcc -O2 -o program program.c
```

### ⚡ Biên dịch code C++:
```bash
# 🏗️ Biên dịch cơ bản
g++ -o program program.cpp

# 🚀 Chạy chương trình
./program

# 🐛 Biên dịch với debug info và C++17
g++ -std=c++17 -g -Wall -Wextra -o program program.cpp

# 📊 Biên dịch với optimization
g++ -std=c++17 -O2 -o program program.cpp
```

### 🔨 Makefile example:
```makefile
# 🎯 Variables
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c99
CXXFLAGS = -Wall -Wextra -std=c++17

# 📁 Directories
SRCDIR = src
BUILDDIR = build

# 🎯 Targets
all: c_programs cpp_programs

c_programs:
	@echo "🔧 Compiling C programs..."
	$(CC) $(CFLAGS) $(SRCDIR)/*.c -o $(BUILDDIR)/c_program

cpp_programs:
	@echo "⚡ Compiling C++ programs..."
	$(CXX) $(CXXFLAGS) $(SRCDIR)/*.cpp -o $(BUILDDIR)/cpp_program

clean:
	@echo "🧹 Cleaning build files..."
	rm -rf $(BUILDDIR)/*

.PHONY: all clean
```

---

## ⚙️ Yêu cầu hệ thống

<div align="center">

![Requirements](https://img.shields.io/badge/System-Requirements-lightblue?style=for-the-badge&logo=settings)

</div>

### 🖥️ **Compiler và Tools:**
- **🔧 C Compiler:** GCC 7.0+ hoặc Clang 6.0+
- **⚡ C++ Compiler:** G++ 7.0+ hoặc Clang++ 6.0+
- **📏 C Standard:** C99, C11, hoặc C18
- **🏗️ C++ Standard:** C++11, C++14, C++17, hoặc C++20
- **🛠️ Build Tools:** Make, CMake (tùy chọn)

### 🖥️ **Hệ điều hành được hỗ trợ:**

<div align="center">

![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)

</div>

### 💾 **IDE và Editor được khuyên dùng:**

<div align="center">

![VS Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d4.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-black?style=for-the-badge&logo=clion&logoColor=white)
![Code::Blocks](https://img.shields.io/badge/Code::Blocks-41AD48?style=for-the-badge&logo=codeblocks&logoColor=white)
![Dev-C++](https://img.shields.io/badge/Dev--C++-8B0000?style=for-the-badge&logo=cplusplus&logoColor=white)

</div>

---

## 🤝 Đóng góp

<div align="center">

### 🎉 **Chúng tôi rất hoan nghênh sự đóng góp của bạn!**

![Contributors](https://img.shields.io/github/contributors/username/repo?style=for-the-badge&logo=github)
![Pull Requests](https://img.shields.io/github/issues-pr/username/repo?style=for-the-badge&logo=github)

</div>

### 📝 **Quy trình đóng góp:**

1. 🍴 **Fork repository này**
   ```bash
   git clone https://github.com/quangcaptain26-3/DS-A-CODE.git
   ```

2. 🌿 **Tạo feature branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

3. ✍️ **Commit changes của bạn**
   ```bash
   git commit -m '✨ Add some AmazingFeature'
   ```

4. 🚀 **Push to branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

5. 🔄 **Tạo Pull Request**

### 📋 **Guidelines cho Contributors:**

- ✅ **Code Style:** Tuân thủ coding standards
- 📝 **Documentation:** Thêm comments và documentation
- 🧪 **Testing:** Test kỹ code trước khi submit
- 📊 **Examples:** Cung cấp ví dụ cụ thể
- 🐛 **Bug Reports:** Mô tả chi tiết lỗi và cách reproduce

---

## 📖 Tài liệu tham khảo

<div align="center">

### 📚 **Sách và tài liệu học tập chất lượng cao**

</div>

### 🔢 **Data Structures & Algorithms:**

<div align="center">

![Books](https://img.shields.io/badge/Books-Recommended-blue?style=for-the-badge&logo=book-open)

</div>

- 📖 **"Introduction to Algorithms"** - *Cormen, Leiserson, Rivest, Stein*
  - 🌟 Được coi là "bible" của algorithms
  - 📊 Phân tích độ phức tạp chi tiết
  - 🎯 Từ cơ bản đến nâng cao

- 📚 **"Data Structures and Algorithm Analysis in C"** - *Mark Allen Weiss*
  - 💻 Focus vào implementation bằng C
  - 🔍 Ví dụ thực tế và bài tập hay
  - ⚡ Phân tích performance chi tiết

- 🎯 **"Algorithms in C"** - *Robert Sedgewick*
  - 🏗️ Implementation patterns hiệu quả
  - 📈 Visualization algorithms
  - 💡 Practical approach

### 🏗️ **Object-Oriented Programming in C++:**

<div align="center">

![C++ Books](https://img.shields.io/badge/C%2B%2B-Books-red?style=for-the-badge&logo=c%2B%2B)

</div>

- 🏛️ **"Object-Oriented Programming in C++"** - *Robert Lafore*
  - 🎯 Dễ hiểu cho beginners
  - 💡 Ví dụ thực tế phong phú
  - 📊 Progressive learning approach

- ⚡ **"Effective C++"** - *Scott Meyers*
  - 🎨 Best practices và guidelines
  - 🐛 Common pitfalls và cách tránh
  - 🚀 Performance optimization tips

- 🏗️ **"The C++ Programming Language"** - *Bjarne Stroustrup*
  - 👑 Từ chính tác giả của C++
  - 📖 Comprehensive reference
  - 🔧 Advanced concepts và features

- 🎭 **"Design Patterns"** - *Gang of Four*
  - 🏗️ 23 classic design patterns
  - 💼 Real-world applications
  - 🎯 Problem-solving approaches

### 🌐 **Online Resources:**

<div align="center">

![Online](https://img.shields.io/badge/Online-Resources-green?style=for-the-badge&logo=internet-explorer)

</div>

- 🌟 **GeeksforGeeks** - [geeksforgeeks.org](https://geeksforgeeks.org)
- 💻 **LeetCode** - [leetcode.com](https://leetcode.com)
- 🎓 **Coursera** - Computer Science courses
- 📺 **YouTube** - Channels như MIT OpenCourseWare
- 📖 **cppreference.com** - C++ documentation



## 📜 License

<div align="center">

![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)

</div>

```
MIT License

Copyright (c) 2024 DSA-OOP Learning Repository

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

<div align="center">

## 🎉 **Thank You for Visiting!**

### 🌟 **Nếu repository này hữu ích, hãy cho chúng tôi một ⭐!**

![Thank You](https://img.shields.io/badge/Thank%20You-for%20visiting-red?style=for-the-badge&logo=heart)

---

**📧 Contact:** phamminhquang2603@gmail.com  
**💼 LinkedIn:** [Your LinkedIn](https://www.linkedin.com/in/minhquang2604/)

---

### 🚀 **Happy Coding! Chúc bạn học tập hiệu quả!** 🚀

</div>

---

<div align="center">

*⚡ Được tạo với ❤️ và ☕ bởi Minh Quang*

*📅 Cập nhật lần cuối: June 2025*

</div>
