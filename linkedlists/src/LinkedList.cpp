#include "LinkedList.h"

Node::Node()
{
    cargo = 0;
    next = nullptr;
}

Node::Node(int cargo)
{
    this->cargo = cargo;
    next = nullptr;
}

Node::Node(int cargo, Node* next)
{
    this->cargo = cargo;
    this->next = next;
}

string Node::to_string() const {
    return std::to_string(cargo);
}

string Node::render_list(Node* list) {
    Node* node = list;
    string rl = "";
    while (node != nullptr) {
        rl += node->to_string();
        node = node->next;
        if (node != nullptr)
           rl += ", ";
    }
    return rl;
}