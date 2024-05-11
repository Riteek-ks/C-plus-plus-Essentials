#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
template <typename K, typename V>
class Dictionary {
private:
    struct KeyValue {
        K key;
        V value;
    };
 
    std::vector<KeyValue> data;
 
public:
    // Insert or update key-value pair
    void insert(const K& key, const V& value) {
        for (auto& kv : data) {
            if (kv.key == key) {
                kv.value = value;
                return;
            }
        }
        data.push_back({ key, value });
    }
 
    // Get value by key
    V& operator[](const K& key) {
        for (auto& kv : data) {
            if (kv.key == key) {
                return kv.value;
            }
        }
        throw std::out_of_range("Key not found");
    }
 
    //// Check if key exists
    //bool contains(const K& key) const {
    //    for (const auto& kv : data) {
    //        if (kv.key == key) {
    //            return true;
    //        }
    //    }
    //    return false;
    //}
 
    // Remove key-value pair
    /*void remove(const K& key) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->key == key) {
                data.erase(it);
                return;
            }
        }
    }*/
 
    // Get number of key-value pairs
    size_t size() const {
        return data.size();
    }
    friend std::ostream& operator<<(std::ostream& os, const Dictionary<K, V>& dict) {
        os << "{ ";
        for (const auto& kv : dict.data) {
            os << kv.key << ": " << kv.value << ", ";
        }
        os << "}";
        //cout << endl;
        return os;
    }
};
 
int main() {
    Dictionary<std::string, int> dict;
 
    dict.insert("apple", 10);
    dict.insert("banana", 20);
    dict.insert("orange", 15);
 
    std::cout << "Size of dictionary: " << dict.size() << std::endl;
 
    std::cout << "Value of 'apple': " << dict["apple"] << std::endl;
    std::cout << "Value of 'banana': " << dict["banana"] << std::endl;
 
    //std::cout << "Does dictionary contain 'grape'? " << (dict.contains("grape") ? "Yes" : "No") << std::endl;
 
    dict["banana"] = 25;
    std::cout << "Updated value of 'banana': " << dict["banana"] << std::endl;
 
    //dict.remove("orange");
 
  //  std::cout << "Size of dictionary after removing: " << dict.size() << std::endl;
 
    cout << "the whole dictionary looks like this : " << endl;
    cout << dict;
    return 0;
}       