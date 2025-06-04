# Data Structures & Algorithms (C) và Object-Oriented Programming (C++)

## Mục lục
- [Giới thiệu](#giới-thiệu)
- [Cấu trúc thư mục](#cấu-trúc-thư-mục)
- [Data Structures & Algorithms (C)](#data-structures--algorithms-c)
- [Object-Oriented Programming (C++)](#object-oriented-programming-c)
- [Cách sử dụng](#cách-sử-dụng)
- [Yêu cầu hệ thống](#yêu-cầu-hệ-thống)
- [Đóng góp](#đóng-góp)

## Giới thiệu

Repository này chứa các implementation và ví dụ về:
- **Data Structures & Algorithms** được viết bằng ngôn ngữ C
- **Object-Oriented Programming** được viết bằng ngôn ngữ C++

Mục tiêu là cung cấp tài liệu học tập đầy đủ với lý thuyết, code examples và các bài tập thực hành.
Còn lại ở các file, các em ấn vào file .c hoặc .cpp thui nhé, đừng ấn vào file .exe

## Cấu trúc thư mục

```
├── DSA_C/
│   ├── DataStructures/
│   │   ├── Array/
│   │   ├── LinkedList/
│   │   ├── Stack/
│   │   ├── Queue/
│   │   ├── Tree/
│   │   └── Graph/
│   ├── Algorithms/
│   │   ├── Sorting/
│   │   ├── Searching/
│   │   └── DynamicProgramming/
│   └── Examples/
├── OOP_CPP/
│   ├── BasicConcepts/
│   ├── Classes/
│   ├── Inheritance/
│   ├── Polymorphism/
│   ├── Encapsulation/
│   └── Projects/
└── README.md
```

---

# Data Structures & Algorithms (C)

## 📚 Cấu trúc dữ liệu (Data Structures)

### 1. Array (Mảng)
**Khái niệm:** Tập hợp các phần tử cùng kiểu dữ liệu được lưu trữ liên tiếp trong bộ nhớ.

**Đặc điểm:**
- Truy cập ngẫu nhiên với độ phức tạp O(1)
- Kích thước cố định
- Dữ liệu được lưu trữ liên tiếp

**Ví dụ đơn giản:**
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Truy cập phần tử
    printf("Phần tử thứ 3: %d\n", arr[2]);
    
    // Duyệt mảng
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
```

### 2. Linked List (Danh sách liên kết)
**Khái niệm:** Cấu trúc dữ liệu động gồm các node, mỗi node chứa data và pointer trỏ đến node tiếp theo.

**Đặc điểm:**
- Kích thước động
- Chèn/xóa hiệu quả ở đầu danh sách O(1)
- Truy cập tuần tự O(n)

**Ví dụ đơn giản:**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo node mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// In danh sách
void printList(Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```

### 3. Stack (Ngăn xếp)
**Khái niệm:** Cấu trúc dữ liệu LIFO (Last In First Out) - phần tử cuối cùng được thêm vào sẽ được lấy ra đầu tiên.

**Các thao tác cơ bản:**
- `push()`: Thêm phần tử vào đỉnh stack
- `pop()`: Lấy phần tử ở đỉnh stack
- `top()`: Xem phần tử ở đỉnh stack
- `isEmpty()`: Kiểm tra stack rỗng

**Ví dụ đơn giản:**
```c
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void push(Stack* s, int data) {
    if(s->top < MAX_SIZE - 1) {
        s->arr[++s->top] = data;
    }
}

int pop(Stack* s) {
    if(s->top >= 0) {
        return s->arr[s->top--];
    }
    return -1; // Stack rỗng
}
```

### 4. Queue (Hàng đợi)
**Khái niệm:** Cấu trúc dữ liệu FIFO (First In First Out) - phần tử đầu tiên được thêm vào sẽ được lấy ra đầu tiên.

**Các thao tác cơ bản:**
- `enqueue()`: Thêm phần tử vào cuối queue
- `dequeue()`: Lấy phần tử ở đầu queue
- `front()`: Xem phần tử ở đầu queue
- `isEmpty()`: Kiểm tra queue rỗng

### 5. Tree (Cây)
**Khái niệm:** Cấu trúc dữ liệu phân cấp gồm các node được kết nối bởi các cạnh, có một node gốc và không có chu trình.

**Binary Search Tree (BST):**
- Node trái < Node gốc < Node phải
- Tìm kiếm, chèn, xóa: O(log n) trung bình

### 6. Graph (Đồ thị)
**Khái niệm:** Tập hợp các đỉnh (vertices) được kết nối bởi các cạnh (edges).

**Phân loại:**
- Directed/Undirected Graph
- Weighted/Unweighted Graph

## 🔍 Thuật toán (Algorithms)

### 1. Thuật toán sắp xếp (Sorting)

#### Bubble Sort
**Độ phức tạp:** O(n²)
```c
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

#### Quick Sort
**Độ phức tạp:** O(n log n) trung bình, O(n²) worst case

#### Merge Sort
**Độ phức tạp:** O(n log n) trong mọi trường hợp

### 2. Thuật toán tìm kiếm (Searching)

#### Linear Search
**Độ phức tạp:** O(n)
```c
int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1; // Không tìm thấy
}
```

#### Binary Search
**Độ phức tạp:** O(log n)
```c
int binarySearch(int arr[], int left, int right, int target) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target) return mid;
        
        if(arr[mid] < target) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}
```

### 3. Dynamic Programming
**Khái niệm:** Kỹ thuật giải quyết bài toán bằng cách chia nhỏ thành các bài toán con và lưu trữ kết quả để tránh tính toán lại.

---

# Object-Oriented Programming (C++)

## 🏗️ Các khái niệm cơ bản OOP

### 1. Class và Object

**Class (Lớp):** Template hoặc blueprint để tạo ra objects.
**Object (Đối tượng):** Instance của một class.

**Ví dụ đơn giản:**
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
    // Constructor
    Student(string n, int a, float g) {
        name = n;
        age = a;
        gpa = g;
    }
    
    // Getter methods
    string getName() { return name; }
    int getAge() { return age; }
    float getGPA() { return gpa; }
    
    // Method to display info
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    Student student1("Nguyen Van A", 20, 3.5);
    student1.displayInfo();
    return 0;
}
```

### 2. Encapsulation (Đóng gói)
**Khái niệm:** Ẩn chi tiết implementation và chỉ cung cấp interface cần thiết.

**Access Modifiers:**
- `private`: Chỉ truy cập được trong class
- `public`: Truy cập được từ bên ngoài
- `protected`: Truy cập được trong class và derived class

### 3. Inheritance (Kế thừa)
**Khái niệm:** Một class có thể kế thừa properties và methods từ class khác.

**Ví dụ:**
```cpp
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    
    void introduce() {
        cout << "Hi, I'm " << name << ", " << age << " years old." << endl;
    }
};

class Student : public Person {
private:
    string studentId;
    float gpa;

public:
    Student(string n, int a, string id, float g) 
        : Person(n, a), studentId(id), gpa(g) {}
    
    void study() {
        cout << name << " is studying." << endl;
    }
};
```

### 4. Polymorphism (Đa hình)
**Khái niệm:** Khả năng sử dụng một interface để đại diện cho các kiểu dữ liệu khác nhau.

#### Function Overloading
```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

#### Virtual Functions
```cpp
class Shape {
public:
    virtual double getArea() = 0; // Pure virtual function
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    
    double getArea() override {
        return 3.14159 * radius * radius;
    }
    
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};
```

### 5. Abstraction (Trừu tượng hóa)
**Khái niệm:** Ẩn các chi tiết phức tạp và chỉ hiển thị các tính năng cần thiết.

**Abstract Class:** Class chứa ít nhất một pure virtual function.

### 6. Constructor và Destructor

```cpp
class MyClass {
private:
    int* data;

public:
    // Default Constructor
    MyClass() {
        data = new int(0);
        cout << "Default constructor called" << endl;
    }
    
    // Parameterized Constructor
    MyClass(int value) {
        data = new int(value);
        cout << "Parameterized constructor called" << endl;
    }
    
    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
        cout << "Copy constructor called" << endl;
    }
    
    // Destructor
    ~MyClass() {
        delete data;
        cout << "Destructor called" << endl;
    }
};
```

## 🎯 Design Patterns cơ bản

### 1. Singleton Pattern
```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // Private constructor

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};
```

### 2. Factory Pattern
```cpp
class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class AnimalFactory {
public:
    static Animal* createAnimal(string type) {
        if(type == "dog") {
            return new Dog();
        }
        return nullptr;
    }
};
```

---

## Cách sử dụng

### Biên dịch code C:
```bash
gcc -o program program.c
./program
```

### Biên dịch code C++:
```bash
g++ -o program program.cpp
./program
```

### Với debugging:
```bash
gcc -g -o program program.c
g++ -g -o program program.cpp
```

## Yêu cầu hệ thống

- **Compiler:** GCC 7.0+ hoặc Visual Studio 2017+
- **C Standard:** C99 hoặc C11
- **C++ Standard:** C++11 hoặc mới hơn
- **OS:** Windows, Linux, macOS

## Đóng góp

1. Fork repository này
2. Tạo feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Tạo Pull Request

## Tài liệu tham khảo

- **Data Structures & Algorithms:**
  - "Introduction to Algorithms" - Cormen, Leiserson, Rivest, Stein
  - "Data Structures and Algorithm Analysis in C" - Mark Allen Weiss

- **OOP in C++:**
  - "Object-Oriented Programming in C++" - Robert Lafore
  - "Effective C++" - Scott Meyers

## License

MIT License - xem file [LICENSE](LICENSE) để biết thêm chi tiết.

---

**Chúc các em học tập hiệu quả! 🚀**
