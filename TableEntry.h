
#include <iostream>
#include <string>

using namespace std;

template <typename V>
class TableEntry {

public:
    string key;
    V value;
    TableEntry(string key, V value) {
        this->key=key;
        this->value=value;
    }

    TableEntry(string key){
        this->key=key;
    }
    
    TableEntry(){
        this->key=" ";
    }
    
    friend bool operator==(const TableEntry<V>& e1, const TableEntry<V>& e2) {
    return e1.key == e2.key;
    }
    
    friend bool operator!=(const TableEntry<V>& e1, const TableEntry<V>& e2) {
    return e1.key != e2.key;
    }
    
    
    friend ostream& operator<<(ostream &out, const TableEntry<V> &te){
        out << "Key: " << te.key << ", Value: " << te.value << endl;
        return out;
    }
    
    
    void printEntry() {
        cout << "Key: " << key << ", Value: " << value << endl;
    }
    
    
};


