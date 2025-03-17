#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include "queue.h"
//#include "LinkedQueue.h"
using namespace std;

TEST_CASE("Test basic queue operations on queue of strings") {
    Queue<string> queue;
    CHECK(queue.empty() == true);
    queue.insert("first");
    CHECK(queue.empty() == false);
    queue.insert("second");
    queue.insert("third");
    CHECK(queue.remove() == "first");
    queue.insert("forth");
    queue.insert("fifth");
    queue.insert("sixth");
    queue.insert("seventh");
    queue.insert("eight");
    queue.insert("nineth");
    CHECK(queue.remove() == "second");
    CHECK(queue.remove() == "third");
    queue.insert("tenth");
    queue.insert("eleventh");
    CHECK(queue.remove() == "forth");
    queue.insert("twelfth");
    queue.insert("thirteenth");
    CHECK(queue.remove() == "fifth");
}

//Max size had to be modified so that these tests with overflow and underflow would pass 
//If we wanted the tests to pass we could delete this test or modify for it to loop as long as i < MAX_SIZE
TEST_CASE("Test queue handles overflow and underflow") { 
    Queue<int> q;
    for (int i = 1; i < 10; i++)
        q.insert(i);
    CHECK(q.empty() == false);

    //For a linked list there is technically no max space (memory is added dynamically) but through modifying Linked Queue.h we can change that
    CHECK_THROWS_WITH(q.insert(11), "No more space in queue"); 
    for (int i = 1; i < 10; i++)
        CHECK(q.remove() == i);
    CHECK_THROWS_WITH(q.remove(), "Can't remove from empty queue"); 
}
