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
		    value = 0;
	    }

	    TableEntry(){
		    key = " ";
		    value = 0;
	    }

	    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
<<<<<<< HEAD
		return (te1.key == te2.key);	
	    }

	    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
		return !(te1.key == te2.key);
	    }

	    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
		out << "Key: " << te.key << ", Value: " << te.value;
		return out;
=======
		    return (te1.key == te2.key);		
	    }

	    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
		    return !(te1.key == te2.key);
	    }

	    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
		    out << "Key: " << te.key << ", Value: " << te.value;
		    return out;
>>>>>>> 6d9b89eaca2612ac3a9977421b51660bf11053c9
	    }
	    // miembros públicos
    
};

#endif
