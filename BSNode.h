#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

using namespace std;

template <typename T>
class BSNode {
public:
    T elem;
    BSNode<T>* izq;
    BSNode<T>* der;

    BSNode(T elem, BSNode<T>* izq = nullptr, BSNode<T>* der = nullptr) {
        this->elem = elem;
        this->izq = izq;
        this->der = der;
    }

    friend std::ostream& operator<<(std::ostream& out, const BSNode<T>& bsn) {
        out << bsn.elem << endl;
        return out;
    }
};

#endif

