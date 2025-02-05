using namespace std;
#include <algorithm> 
#include<iostream>
#include<string>
struct Node {
    int cargo;
    Node* next;

    // constructors
    Node();
    Node(int);
    Node(int, Node*);

    string to_string() const;

};

    string render_list(Node* list);
    string render_backward_worker(Node* list, string= "");
    string render_list_backward(Node* list);
    string render_pretty(Node* list, string (*list_renderer)(Node*));
    Node* remove_second(Node* list);
