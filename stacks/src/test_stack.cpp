#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include "Stack.h"

using namespace std;

TEST_CASE("Test basic stack operations on stack of ints") {
    Stack<int> stack;
    stack.push(9);
    CHECK(stack.top() == 9);
    stack.push(11);
    CHECK(stack.top() == 11);
    stack.push(42);
    CHECK(stack.top() == 42);
    CHECK(stack.pop() == 42);
    CHECK(stack.top() == 11);
    CHECK(stack.empty() == false);
    stack.pop();
    CHECK(stack.pop() == 9);
    CHECK(stack.empty() == true);
}

TEST_CASE("Test basic stack operations on stack of strings") {
    Stack<string> stack;
    stack.push("cheese");
    CHECK(stack.top() == "cheese");
    stack.push("anchovies");
    CHECK(stack.top() == "anchovies");
    stack.push("onions");
    CHECK(stack.top() == "onions");
    CHECK(stack.pop() == "onions");
    CHECK(stack.top() == "anchovies");
    CHECK(stack.empty() == false);
    stack.pop();
    CHECK(stack.pop() == "cheese");
    CHECK(stack.empty() == true);
}


TEST_CASE("Test split_on_spaces") {
    string s = "1 2 3 4 5 6";
    vector<string> test = splitspaces(s);
    CHECK(test[0] == "1");
    CHECK(test[1] == "2");
    CHECK(test[2] == "3");
    CHECK(test[3] == "4");
    CHECK(test[4] == "5");
    CHECK(test[5] == "6");
}

TEST_CASE("Testing eval_postfix ") {
    CHECK(eval_postfix_expr("5 4 + 2 *" ) == 18);
    CHECK(eval_postfix_expr("12 2 * 4 +") == 28);
    CHECK(eval_postfix_expr("11 6 3 / 4 + -") == 5);
}

TEST_CASE("Test is_valid_infix_expression") {
    string expr1 = "(4 + a) / c";
    CHECK(is_valid_infix_expression(expr1) == true);
    string expr2 = "(x * ((5 - d) + c) - y) * 2";
    CHECK(is_valid_infix_expression(expr2) == true);
    string expr3 = "(x * ((5 - d) + c - y) * 2";
    CHECK(is_valid_infix_expression(expr3) == false);
}

/* work in progress
TEST_CASE("Test stack of user defined class") {
    Stack<Node<int>*> NumAnimals;
    Node<int>* cats = new Node(7);
    NumAnimals.push(cats);
    CHECK(NumAnimals.top()->to_string() == "7");
    Node<int>* dogs = new Node(3, cats);
    NumAnimals.push(dogs);
    CHECK(NumAnimals.top()->to_string() == "3");
    CHECK(NumAnimals.empty() == false);
    CHECK(NumAnimals.pop()->cargo == 3);
    CHECK(NumAnimals.pop()->cargo == 7);


}
*/

