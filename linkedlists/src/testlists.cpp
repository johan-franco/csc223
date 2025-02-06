#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include "LinkedList.h"

using namespace std;

TEST_CASE("Test can create and render List Nodes") {
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
}

TEST_CASE("Test can create and render List Nodes") {
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
    Node* node2 = new Node(42);
    CHECK(node2->cargo == 42);
    CHECK(node1->to_string() == "0");
    CHECK(node2->to_string() == "42");
}

TEST_CASE("Test can link nodes together") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    CHECK(node2->next == node1);
    CHECK(node3->next == node2);
    CHECK(node3->next->next == node1);
}

TEST_CASE("Test can display linked nodes") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    CHECK(render_list(node3) == "3, 2, 1");
}

TEST_CASE("Test can display linked nodes backwards") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    Node* node4 = new Node(4, node3);
    CHECK(render_list(node4) == "4, 3, 2, 1");
    CHECK(render_list_backward(node4) == "1, 2, 3, 4");
}

TEST_CASE("Test can display linked nodes with parenthesis") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    Node* node4 = new Node(4, node3);
    CHECK(render_pretty(node4, &render_list) == "(4, 3, 2, 1)");
    CHECK(render_pretty(node4, &render_list_backward) == "(1, 2, 3, 4)");
}

TEST_CASE("Test can remove second node") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    Node* node4 = new Node(4, node3);
    CHECK(remove_second(node4)->to_string() == "3");
    CHECK(render_list(node4) == "4, 2, 1");
}

TEST_CASE("Test can insert nodes in front") {
    LinkedList list;
    CHECK(list.to_string() == "Empty list");
    list.insert_in_front(5);
    CHECK(list.to_string() == "5");
    list.insert_in_front(42);
    CHECK(list.to_string() == "42 -> 5");
    list.insert_in_front(9);
    CHECK(list.to_string() == "9 -> 42 -> 5");
}

TEST_CASE("Test can remove nodes in front") {
    LinkedList list;
    list.insert_in_front(5);
    list.insert_in_front(42);
    list.insert_in_front(9);
    CHECK(list.to_string() == "9 -> 42 -> 5");
    list.remove_from_front();
    CHECK(list.to_string() == "42 -> 5");
    list.remove_from_front();
    CHECK(list.to_string() == "5");
    list.remove_from_front();
    CHECK(list.to_string() == "Empty list");

}