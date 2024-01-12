

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h"
#include "List.h"
#include "Node.h"

using namespace std;


template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;
        
        
        int h(std::string key){
            int sum = 0;
            for (int i = 0; i < key.length(); ++i) {
                sum += (int(key.at(i)));
            }
            int hashValue = sum % max;
            return hashValue;
        }


  /*void rehash(){
    int newMax = max*2;
    ListLinked<TableEntry<V>>* tableNew = new ListLinked<TableEntry<V>>[newMax];
  */
   

    for (int i = 0; i < max; i++) {
      while (!table[i].empty()) {
	TableEntry<V> entry = table[i].remove(0);
	int newIndex = h(entry.key);
	tableNew[newIndex].prepend(entry);
      }
    }

    delete[] table;
    table = tableNew;
    max = newMax;



      }



  

    public:
        HashTable(int size){
            n =0;
            max = size;
		    table = new ListLinked<TableEntry<V>>[size];
            
        }
        
        ~HashTable(){
            delete[] table;
        }
        
        int capacity(){
            return max;
        }
        
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
            out<< "TABLA HASH:\n ***************** \n";
            for(int i =0 ;i<th.max;i++){
                out<< "Cubeta " << i << "=" << th.table[i] <<endl;
            }
        return out;
        }

        V operator[](std::string key) {
            int posicion_encontrada = table[h(key)].search(key);
            if (posicion_encontrada < 0) {
                throw std::runtime_error("Posición no encontrada");
            } else {
            // Aquí deberías retornar el valor almacenado en la posición encontrada
            return table[h(key)].get(posicion_encontrada).value;
        }
    }
        
        void insert(std::string key, V value) override{	
    		int pos = table[h(key)].search(key);
            if(pos >= 0){   
                throw std::runtime_error("Ya introducido");
            }
	    if ((double)n / max > 0.5) {
	      rehash(); 
	    }
    		TableEntry<V> aux(key, value);
    		table[h(key)].prepend(aux);
    		n++;
	}
        
         V search(std::string key){
            int pos = table[h(key)].search(key);
            if(pos < 0){
                throw std::runtime_error("No encontrado");
            }
            V aux = table[h(key)].get(pos).value;
            return aux;    
        }
        
        int remove(std::string key){
            int posicion_columna = h(key);
            int posicion_fila = table[posicion_columna].search(key);
            if(posicion_fila < 0){
                throw std::runtime_error("No encontrado");
            }
            n--;
            int a = table[posicion_columna].get(posicion_fila).value;
            table[posicion_columna].remove(posicion_fila);
            return a;

        }
        
        int entries(){
            return n;
        }
};

#endif

