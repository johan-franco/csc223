using namespace std;
#include <algorithm> 
#include<iostream>
#include<string>

template <class T>
struct Node {
    T cargo;
    Node<T>* next;

    // constructors
    Node(){
        this->cargo = 0;
        this->next = nullptr;
    }
    Node(T cargo, Node<T>* next){
        this->cargo = cargo;
        this->next = next;
    }
    Node(T cargo){
        this->cargo = cargo;
        this->next = nullptr;
    }

    string to_string() const    {
        return string(cargo);
    }

};

template <class T>
struct LinkedList
{
    int num_nodes;
    Node<T>* head;

    LinkedList(){
        num_nodes = 0;
        head = nullptr;
    }
    //LinkedList(Node* start, int num);

    void insert_at_front(T cargo){
        Node<T>* front = new Node<T>(cargo, head);
        head = front;
        num_nodes++;
    };

    T remove_from_front() {
        if (head == nullptr)
            throw runtime_error("Can't remove from and empty list!");
        T cargo = head->cargo;
        Node<T>* front = head;
        head = head->next;
        delete front;
        num_nodes--;
        return cargo;
    }

    string to_string() const{
        Node<T>* node = head;
        string s = "";
        while (node != nullptr) {
            s += node->to_string();
            node = node->next;
            if (node != nullptr)
                s += ", ";
        }
        return s;
    }

    T get_item(int pos) {
        // If the position exceeds the number of nodes, reduce it to a valid position using modulo
        if(pos > num_nodes) {return "Position is higher than number of nodes";}

        // Initialize a pointer to traverse the linked list, starting from the head node
        Node<T>* traveler = this->head;

        // Traverse the linked list until reaching the desired position (pos)
        for(int i = 1; i < pos; i++) {
            traveler = traveler->next;
        }

        // Return the cargo (data) stored at the node at the specified position
        return traveler->cargo;
    }
    int length() const {
        return this->num_nodes;
    }
/*
    void insert_item(T cargo, int pos) {        
        Node<T>* traveler = this->head;
        for(int i = 1; i < pos; i++) {
            traveler=traveler->next;
        }
        Node<T>* newnode(cargo, traveler->next);
        traveler->next = newnode;


    }
*/
};

/*
    string render_list(Node* list);
    string render_backward_worker(Node* list, string= "");
    string render_list_backward(Node* list);
    string render_pretty(Node* list, string (*list_renderer)(Node*));
    Node* remove_second(Node* list);
*/