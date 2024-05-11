#include "Utils.h"
#include "Getnegatives.h"
#include <algorithm>
#include <regex>
using namespace std;

void GetNegatives::operator()(int i) {
    if (i < 0)
        negatives.append(to_string(i) + ",");
}

GetNegatives::operator string() {
    if (!negatives.empty())
        negatives.pop_back();

    return negatives;
}

void check_for_negatives(const vector<int>& numbers) {
    string negatives = for_each(numbers.begin(), numbers.end(), GetNegatives());

    if (!negatives.empty()) {
        throw invalid_argument("Negatives not allowed: " + negatives);
    }
}

void add_if_valid(vector<int>& numbers, const string& number_string) {
    int number = stoi(number_string);
    if (number <= 1000)
        numbers.push_back(number);
}

vector<int> get_numbers(const string& input) {
    regex numbers_only("(-?\\d+)+");

    vector<int> numbers;
    for_each(sregex_token_iterator(input.begin(), input.end(), numbers_only), sregex_token_iterator(),[&numbers](string s) { 
        add_if_valid(numbers, s); });

    return numbers;
}
