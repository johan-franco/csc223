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

LinkedList::LinkedList() {
        num_nodes = 0;
        head = nullptr;
}

void LinkedList::insert_at_front(int cargo) {
    Node* front = new Node(cargo, head);
    head = front;
    num_nodes++;
}

string render_list(Node* list) {
    Node* node = list; 
    string rl = "";
    while (node != nullptr) { // Stop at end of list
        rl += node->to_string();
        node = node->next; // Go to next part of list
        if (node != nullptr) //Add comma if more are linked
           rl += ", ";
    }
    return rl;
}

string render_backward_worker(Node* list, string br) {
    if (list == nullptr) return ""; //base case (theoretically all should return to this eventually)
    Node* head = list;
    Node* tail = list->next; 

    /*If the linked lists are 3 nodes with val 1,2,3 then the first time time it is ran node one is head and
    node 2 is tail. Then node 2 will turn into head and then finally node 3 will be head. At that turn the tail
    will be nullptr causing for render_list_backward to return "" + "" */
    br = render_backward_worker(tail, br) + br;
    if (head->next != nullptr) //When node 3 is head this will not run, which is what we want as br is "" at that point
        br += ", ";
    br += head->to_string(); //THis will add node 3 as the first in the string

    return br;
}
string render_list_backward(Node* list)
{
    return render_backward_worker(list, ""); //This is so render_pretty can properly run backward worker (needs "" as parameter)
}

string render_pretty(Node* list, string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")"; //renders linked nodes and adds ();
}

Node* remove_second(Node* list) {
    Node* first = list;
    Node* second = list->next;

    // make the first node point to the third
    first->next = second->next;

    // remove the second node from the list and return a pointer to it
    second->next = nullptr;
    return second;
}