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
    string render_list(Node* list);
};