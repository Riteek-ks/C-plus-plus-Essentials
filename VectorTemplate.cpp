#include <iostream>
using namespace std;
template <typename T>
class Vector {
private:
    T* array;
    int capacity=3;
    int size=0;
 
public:
    Vector()  {
        array = new T[capacity];
    }
    /*Vector(initializer_list<int> l) {
        for (int i : l) {
            cout << i << endl;
        }
    }*/
  /*  Vector() : capacity(3), size(0) {
        array = new int[capacity];
    }*/
 
    ~Vector() {
        delete[] array;
    }
 
    void push_back(const T& element) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        array[size++] = element;
    }
 
    void resize(int newCapacity) {
        T* newArray = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
 
    int getSize() const {
        return size;
    }
 
    int getCapacity() const {
        return capacity;
    }
 
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }
 
    /*const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }*/
    friend ostream& operator<<(ostream& os, const Vector<T >& vec) {
        os << "[ ";
        for (int i = 0; i < vec.size; ++i) {
            os << vec.array[i] << " ";
        }
        os << "]";
        cout << endl;
        return os;
    }
};
 
int main() {
    /*Vector<int> vec = { 1,2,3,4,5,6,7,8,9 };*/
 
    Vector<string> vec;
    vec.push_back("1");
    vec.push_back("2");
    vec.push_back("3");
    vec.push_back("4");
    vec.push_back("5");
    cout << vec[3]<<endl;
    cout << vec;
    vec[3] = "222";
    cout << vec[3]<<endl;
 
    cout << vec;
 
    /*std::cout << "Size: " << vec.getSize() << std::endl;
    std::cout << "Capacity: " << vec.getCapacity() << std::endl;
 
    for (int i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;*/
 
    return 0;
}