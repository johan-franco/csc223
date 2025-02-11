#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include "LinkedList.h"

using namespace std;


TEST_CASE("Test basic list of strings operations") {
    LinkedList<string> toppings;
    toppings.insert_in_front("cheese");
    CHECK(toppings.to_string() == "cheese");
    toppings.insert_in_front("anchovies");
    CHECK(toppings.to_string() == "anchovies, cheese");
    toppings.insert_in_front("onions");
    CHECK(toppings.to_string() == "onions, anchovies, cheese");
    CHECK(toppings.remove_from_front() == "onions");
    CHECK(toppings.to_string() == "anchovies, cheese");
}

TEST_CASE("Test can get cargo from certain places") {
    LinkedList<string> toppings;
    toppings.insert_in_front("cheese");
    toppings.insert_in_front("anchovies");
    toppings.insert_in_front("onions");
    CHECK(toppings.to_string() == "onions, anchovies, cheese");
    CHECK(toppings.get_item(3) == "cheese");
    CHECK(toppings.get_item(2) == "anchovies");
    CHECK(toppings.get_item(1) == "onions");
    CHECK(toppings.get_item(5) == "anchovies");
}

/*
TEST_CASE("Test can insert nodes") {
    LinkedList<string> toppings;
    toppings.insert_in_front("cheese");
    toppings.insert_in_front("anchovies");
    toppings.insert_in_front("onions");
    toppings.insert_item("pineapple", 2);
    CHECK(toppings.to_string() == "onions, anchovies, pineapple, cheese");

}
*/