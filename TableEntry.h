#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
	    std::string key;
	    V value;
	    
	    TableEntry(std::string key, V value){
		    this->key = key; 
		    this->value = value;
	    }
	    
	    TableEntry(std::string key){
		    this->key = key;
	    }

	    TableEntry(){
		    key = " ";
	    }

	    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
		
	    }

	    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){

	    }

	    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){

	    }
	    // miembros públicos
    
};

#endif
