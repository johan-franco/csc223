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