using namespace std;
#include <algorithm> 
#include <iostream>
#include <string>
#define MAX_SIZE 10


enum Color {RED, GREEN};

struct RGThing {
    Color color; 
    string label;
};

struct RGTpair {
    RGThing thing1;
    RGThing thing2;
};

/*I've decidied to implement this as an two queue that shifts after reaching the maximum. Soecifically 
the queue is an array that holds RGTpairs  */
class RGTPQ {
    RGThing redQueue[MAX_SIZE];
    int redFront;
    int redBack;
    int redSize;

    RGThing greenQueue[MAX_SIZE];
    int greenFront;
    int greenBack;
    int greenSize;

public:
    RGTpair RGTPG() {
        greenFront = 0;
        greenBack = 0;
        greenSize = 0;

        redFront = 0;
        redBack = 0;
        redSize = 0;
    }


//Same concept with previous circular queue insert but with another if statement due to using two queues
    void insert(RGThing thing) {
        if (thing.color == RED) {
            if (redSize == MAX_SIZE) {
                throw std::overflow_error("Red queue full");
            }
            redQueue[redBack] = thing;
            redBack = (redBack + 1) % MAX_SIZE;
            redSize++;
        } else {
            if (greenSize == MAX_SIZE) {
                throw std::overflow_error("Green queue full");
            }
            greenQueue[greenBack] = thing;
            greenBack = (greenBack + 1) % MAX_SIZE;
            greenSize++;
        }
    }
/*
    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        int oldfirst = first;
        first = (first + 1) % MAX_SIZE;
        return items[oldfirst];
    }
*/
    bool empty() const {
        return redSize == 0 && greenSize == 0;
    }

};


