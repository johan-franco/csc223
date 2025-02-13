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

    string to_string() const    {
        return string(cargo);
    }

};

template <class T>
class LinkedList
{
    int num_nodes;
    Node<T>* head;

public:
    LinkedList(){
        num_nodes = 0;
        head = nullptr;
    }
    //LinkedList(Node* start, int num);

    void insert_in_front(T cargo){
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
        if(pos > num_nodes) {return "Position is higher than number of nodes";}
        Node<T>* traveler = this->head;
        for(int i = 1; i < pos; i++) {
            traveler = traveler->next;
        }
        T delivery = traveler->cargo;

        delete traveler;

        return delivery;
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