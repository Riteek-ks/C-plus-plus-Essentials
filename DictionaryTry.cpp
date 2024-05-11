#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
template<typename K, typename V>
class KeyValuePair {
public:
    K key;
    V value;
};
 
template<typename K, typename V>
class Dictionary {
    vector<KeyValuePair<K, V>> KeyValuePairs;
public:
    void add(K key, V value) {
        // Check if the key already exists
        for (auto& pair : KeyValuePairs) {
            if (pair.key == key) {
                // Key already exists, update the value
                pair.value = value;
                return;
            }
        }
        // Key doesn't exist, add a new key-value pair
        KeyValuePairs.push_back({key, value});
    }
 
    V& operator[](K key) {
        // Search for the key
        for (auto& pair : KeyValuePairs) {
            if (pair.key == key) {
                // Return the value associated with the key
                return pair.value;
            }
        }
        // Key not found, add a default value
        V defaultValue{};
        KeyValuePairs.push_back({key, defaultValue});
        return KeyValuePairs.back().value; // Return a reference to the newly added value
    }
};
 
int main() {
    Dictionary<string, string> stringMap;
    stringMap.add("BLR", "Bengaluru");
    stringMap.add("CHN", "Chennai");
    string value = stringMap["BLR"];
    cout << value << endl;
 
    Dictionary<string, int> stringToIntMap;
    stringToIntMap.add("One", 1);
    stringToIntMap.add("Two", 2);
    int number = stringToIntMap["One"];
    cout << number << endl;
 
    return 0;
}