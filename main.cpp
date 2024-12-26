#include <iostream>

template <typename T>
class Vector {
private:
    T* data; // ������������ ������
    size_t capacity; // �����������
    size_t length; // �����

    // ��������� ������� �������
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < length; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    // ����������� �� ���������
    Vector() : data(nullptr), capacity(0), length(0) {}

    // ����������� � �������� � ��������� �� ���������
    Vector(size_t size, const T& value) : data(new T[size]), capacity(size), length(size) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    // ����������� �����������
    Vector(const Vector& other) : data(new T[other.capacity]), capacity(other.capacity), length(other.length) {
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    // �������� ������������
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.capacity];
            capacity = other.capacity;
            length = other.length;
            for (size_t i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // ����������
    ~Vector() {
        delete[] data;
    }

    // ���������� �������� � �����
    void push_back(const T& value) {
        if (length == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[length++] = value;
    }

    // ��������� ������� �������
    size_t size() const {
        return length;
    }

    // �������� ������� �� �������
    T& operator[](size_t index) {
        return data[index];
    }

    // ����� at � ��������� ������
    T& at(size_t index) {
        if (index >= length) {
            throw "Index out of bounds";
        }
        return data[index];
    }

    // ������� �������� �� �������
    void insert(size_t index, const T& value) {
        if (index > length) {
            throw "Index out of bounds";
        }
        if (length == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t i = length; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++length;
    }

    // �������� �������� �� �������
    void erase(size_t index) {
        if (index >= length) {
            throw "Index out of bounds";
        }
        for (size_t i = index; i < length - 1; ++i) {
            data[i] = data[i + 1];
        }
        --length;
    }

};

// ������ ��������� Point
struct Point {
    int x, y, z;

    Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

int main() {
    // ������������ ��� ������������ ���� (int)
    Vector<int> intVector(3, 333);
    intVector.push_back(67);
    intVector.push_back(0);

    std::cout << "intVector size: " << intVector.size() << std::endl;
    for (size_t i = 0; i < intVector.size(); ++i) {
        std::cout << intVector[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << "intVector.at(2): " << intVector.at(2) << std::endl;
        std::cout << "intVector.at(5): " << intVector.at(5) << std::endl; // ������
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    // ������������ insert ��� int
    try {
        intVector.insert(2, 15);
        std::cout << "intVector after insert(2, 15): ";
        for (size_t i = 0; i < intVector.size(); ++i) {
            std::cout << intVector[i] << " ";
        }
        std::cout << std::endl;

        intVector.insert(10, 100); // ������
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    // ������������ erase ��� int
    try {
        intVector.erase(3);
        std::cout << "intVector after erase(3): ";
        for (size_t i = 0; i < intVector.size(); ++i) {
            std::cout << intVector[i] << " ";
        }
        std::cout << std::endl;

        intVector.erase(10); // ������
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }


    // ������������ ��� ��������� Point
    Vector<Point> pointVector(2, Point(0, 12, 56));
    pointVector.push_back(Point(78, 2, 41));

    std::cout << "pointVector size: " << pointVector.size() << std::endl;
    for (size_t i = 0; i < pointVector.size(); ++i) {
        std::cout << pointVector[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << "pointVector.at(1): " << pointVector.at(1) << std::endl;
        std::cout << "pointVector.at(3): " << pointVector.at(3) << std::endl; // ������
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    // ������������ insert ��� Point
    try {
        pointVector.insert(1, Point(78, 6, 90));
        std::cout << "pointVector after insert(1, Point(7, 8, 9)): ";
        for (size_t i = 0; i < pointVector.size(); ++i) {
            std::cout << pointVector[i] << " ";
        }
        std::cout << std::endl;

        pointVector.insert(10, Point(100, 101, 120)); // ������
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    // ������������ erase ��� Point
    try {
        pointVector.erase(2);
        std::cout << "pointVector after erase(2): ";
        for (size_t i = 0; i < pointVector.size(); ++i) {
            std::cout << pointVector[i] << " ";
        }
        std::cout << std::endl;

        pointVector.erase(10); // ������
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

}