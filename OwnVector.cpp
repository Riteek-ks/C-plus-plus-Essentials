#include <iostream>
#include <string>
using namespace std;

class IntVector
{

private:
    int *items = new int [3];
    int cnt = 0;

public:
    IntVector() {}
    ~IntVector() {delete[] items;}
    void push_back(int item)
    {
        cnt++;
        int length = sizeof(items) / sizeof(items[0]);
        if (cnt > length)
        {
            length++;
            int *temp = new int[length];
            for (int i = 0; i < cnt; ++i)
            {
                temp[i] = items[i];
            }
            delete[] items; 
            items = temp;
        }
        cnt--;
        items[cnt]= item;
    }

    friend ostream &operator<<(ostream& out, const IntVector &operandTwo)
    {
        out<<"your vector elements are"<<endl;
        int length = sizeof(operandTwo.items) / sizeof(operandTwo.items[0]);
        for(int i=0; i<length; ++i)
        out<<operandTwo.items[i]<<' ';
        out<<endl;

        return out;
    }
};

int main()
{
    IntVector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // int item = v[3];
    // cout << item << endl;
    cout << v << endl;
}
// this code was not working....see why?