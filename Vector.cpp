#include<iostream>
using namespace std;
 
class IntVector {
    int size = 0;
    int capacity = 3;
    int* items;
public:
    IntVector() {
        items = new int[capacity];
    }
 
    ~IntVector() {
        delete[] items;
    }
 
    void push_back(int item) {
        if (size == capacity) {
            capacity *= 2;
            int* newItems = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
        }
        items[size++] = item;
    }
 
    int operator[](int index) const {
        return items[index];
    }
 
    void printItems() const {
        for (int i = 0; i < size; ++i) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
 
        int getItemAt(int index) const {
        if (index >= 0 && index < size)
            return items[index];
        else {
            cout << "Index out of bounds!" << endl;
            return -1; 
        }
    }
 
};
 
int main() {
    IntVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.printItems();
 
        int item = v.getItemAt(2);
    if (item != -1)
        cout << "Item at index 2: " << item << endl;
    return 0;
}
 