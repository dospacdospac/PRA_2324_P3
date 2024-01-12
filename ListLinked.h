#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T>* first;
	    int n;

    public:

	    ListLinked(){
	    	first = nullptr;
		n = 0;
	    }

	    ~ListLinked(){
		Node<T>* aux = first;
		while(aux != nullptr){
			Node<T>* next = aux->next;
			delete next;
			aux = next;
		}
	    }

	    T operator[](int pos){
	    	if(pos < 0 || pos >=n ){
			throw out_of_range("Posicion invalida");
		}
			
		Node<T>* aux = first;
		for(int i = 0;i < pos;i++){
			aux = aux->next;
		}

		return aux->data;
	    }

     

	    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		out << "List => [";
                Node<T>* aux = list.first;
		int sig = 0;
		while(aux != nullptr){
			out << "\n\t" << aux->data;
			aux = aux->next;
			sig = 1;
		}
		if(sig){
                        out << "\n";
                }
		
		out << "]";
                return out;
 
	    }

		// METODOS DE LA CLASE LIST A IMPLEMENTAR
                void insert(int pos, T e) {
                        if(pos < 0 || pos > n){
                                throw out_of_range("Posicion invalida");
                        }

                        //Creamos hueco para el array haciendo que el array principal se mueva a la derech
                        //la cantidad de elementos que el que insertamos tenga, a excepción de si se va a insertar al final

			Node<T>* aux = new Node<T>(e);
                        if(pos == 0){
                            aux->next = first;
			            	first = aux;
                        }else{
				Node<T>* act = first;
                                for(int i = 1 ; i < pos ; i++){
					act = act->next;
                                }

                                aux->next = act->next;
				act->next = aux;
                        }
                        n+=1;

                }

                void append(T e) {
                        insert(n,e);
                }

                void prepend(T e) {
                        insert(0,e);
                }

                T remove(int pos) {
                        if(pos < 0 || n == 0 || pos >n){
                                throw out_of_range("Posicion invalida");
                        }

                        T elemElim;
                        //Movemos el array desde la posc hacia la izq
                        if(pos == 0){
                                Node<T>* temp = first;
				first = first->next;
				elemElim = temp->data;
				delete temp;
                        }else{
				Node<T>* prev = first;
                                for(int i = 1; i < pos; i++){
					prev = prev->next;
				}

				Node<T>* temp = prev->next;
				prev->next = temp->next;
				elemElim = temp->data;
				delete temp;
                        }
                        n--;

                        return elemElim;
                }
                

                T get(int pos) {
                        if(pos < 0 || pos >= n){
                                throw out_of_range("Posicion invalida");
                        }
                        
			Node<T>* aux = first;
			for (int i = 0; i < pos; i++) {
				aux = aux->next;
			}
			return aux->data;
                }

                int search(T e) {
                        Node<T>* aux = first;
			
			for(int i = 0; i < n; i++){
				if(aux->data == e){
					return i;
				}
				aux = aux->next;
			}
                        return -1;
                }

                bool empty() {
                        return n == 0;
                }
  

                int size() {return n;}
  
};
