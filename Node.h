#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T dat, Node<T>* nex = nullptr) {
        data = dat;
        next = nex;
    };

    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }
};

#endif

