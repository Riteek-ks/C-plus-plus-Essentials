#include <string>
using namespace std;

class GetNegatives {
private:
    string negatives;

public:
    void operator()(int i);
    operator string();
};