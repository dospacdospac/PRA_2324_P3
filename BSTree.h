#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree {
private:
    int nelem;
    BSNode<T>* root;

    BSNode<T>* search(BSNode<T>* node, T e) const {
        if (node == nullptr) {
            throw runtime_error("Arbol vacio");
        } else if (node->elem < e) {
            return search(node->der, e);
        } else if (node->elem > e) {
            return search(node->izq, e);
        } else {
            return node;
        }
    }

    BSNode<T>* insert(BSNode<T>* node, T e) {
        if (node == nullptr) {
            return new BSNode<T>(e);
        } else if (e < node->elem) {
            node->izq = insert(node->izq, e);
        } else if (e > node->elem) {
            node->der = insert(node->der, e);
        } else {
            throw runtime_error("Duplicado");
        }
        return node;
    }

    void print_inorder(std::ostream& out, BSNode<T>* node) const {
        if (node == nullptr) {
            return;
        } else {
            print_inorder(out, node->izq);
            out << node->elem << ' ';
            print_inorder(out, node->der);
        }
    }

    BSNode<T>* remove(BSNode<T>* node, T e) {
        if (node == nullptr) {
            throw runtime_error("Árbol vacio");
        } else if (e < node->elem) {
            node->izq = remove(node->izq, e);
        } else if (e > node->elem) {
            node->der = remove(node->der, e);
        } else {
            if (node->izq != nullptr && node->der != nullptr) {
                node->elem = max(node->izq);
                node->izq = remove_max(node->izq);
            } else {
                node = (node->izq != nullptr) ? node->izq : node->der;
            }
        }
        return node;
    }

    T max(BSNode<T>* node) const {
        if (node == nullptr) {
            throw runtime_error("Elemento no encontrado");
        } else if (node->der != nullptr) {
            return max(node->der);
        } else {
            return node->elem;
        }
    }

    BSNode<T>* remove_max(BSNode<T>* node) {
        if (node->der == nullptr) {
            return node->izq;
        } else {
            node->der = remove_max(node->der);
            return node;
        }
    }

    void delete_cascade(BSNode<T>* node) {
        if (node == nullptr) {
            return;
        } else {
            delete_cascade(node->izq);
            delete_cascade(node->der);
            delete node;
        }
    }

public:
    BSTree() {
        this->root = nullptr;
        this->nelem = 0;
    }

    int size() const {
        return nelem;
    }

    T search(T e) const {
        return search(root, e)->elem;
    }

    T operator[](T e) const {
        return search(e);
    }

    void insert(T e) {
        root = insert(root, e);
        nelem++;
    }

    friend std::ostream& operator<<(std::ostream& out, const BSTree<T>& bst) {
        bst.print_inorder(out, bst.root);
        out << endl;
        return out;
    }

    void remove(T e) {
        root = remove(root, e);
        nelem--;
    }

    ~BSTree() {
        delete_cascade(root);
    }
};

#endif

