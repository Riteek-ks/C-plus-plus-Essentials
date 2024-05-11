#include "StringCalculator.h"
#include "Utils.h"
#include <numeric>
using namespace std;

int StringCalculator::add (const string& input) {
    if (input.empty())
        return 0;

    vector<int> numbers = get_numbers(input);

    check_for_negatives(numbers);

    return accumulate(numbers.begin(), numbers.end(), 0);
}
