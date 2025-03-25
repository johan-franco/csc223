#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include "Pair_Queue.h"
#define MAX_SIZE 10

using namespace std;

TEST_CASE("Test basic RGTPQ operations") {
    RGTPQ pq;
    
    CHECK(pq.empty() == true);
    
    //CHECK_THROWS_WITH(pq.remove(), "Cannot form a pair - missing one color");
    
    pq.insert({RED, "Red1"});
    pq.insert({GREEN, "Green1"});
    CHECK(pq.empty() == false);
    
    //RGTpair pair = pq.remove();
    //CHECK(pair.thing1.label == "Red1");
    //CHECK(pair.thing2.label == "Green1");
    //CHECK(pq.empty() == true);
}

TEST_CASE("Test multiple pairs with FIFO order") {
    RGTPQ pq;
    
    pq.insert({RED, "Red1"});
    pq.insert({GREEN, "Green1"});
    pq.insert({RED, "Red2"});
    pq.insert({GREEN, "Green2"});
    pq.insert({RED, "Red3"});
    /*
    RGTpair pair1 = pq.remove();
    CHECK(pair1.thing1.label == "Red1");
    CHECK(pair1.thing2.label == "Green1");
    
    RGTpair pair2 = pq.remove();
    CHECK(pair2.thing1.label == "Red2");
    CHECK(pair2.thing2.label == "Green2");
    
    CHECK_THROWS_WITH(pq.remove(), "Cannot form a pair - missing one color");
    
    pq.insert({GREEN, "Green3"});
    RGTpair pair3 = pq.remove();
    CHECK(pair3.thing1.label == "Red3");
    CHECK(pair3.thing2.label == "Green3");*/
}
/*
TEST_CASE("Test edge cases") {
    RGTPQ pq;
    
    pq.insert({RED, "Red1"});
    pq.insert({RED, "Red2"});
    CHECK_THROWS_WITH(pq.remove(), "Cannot form a pair - missing one color");
    
    pq.insert({GREEN, "Green1"});
    RGTpair pair = pq.remove();
    CHECK(pair.thing1.label == "Red1");
    CHECK(pair.thing2.label == "Green1");
}

TEST_CASE("Test many insertions") {
    RGTPQ pq;
    const int TEST_SIZE = 100;
    
    for (int i = 0; i < TEST_SIZE; i++) {
        pq.insert({RED, "Red" + to_string(i)});
        pq.insert({GREEN, "Green" + to_string(i)});
    }
    
    for (int i = 0; i < TEST_SIZE; i++) {
        RGTpair pair = pq.remove();
        CHECK(pair.thing1.label == "Red" + to_string(i));
        CHECK(pair.thing2.label == "Green" + to_string(i));
    }
    
    CHECK(pq.empty() == true);
}
*/