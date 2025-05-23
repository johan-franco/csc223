using namespace std;
#include <algorithm> 
#include <iostream>
#ifndef QUEUE_H
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

/*I've decidied to implement this as an two queue that is  array with a circular buffer (due to modulus). */
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
    RGTPQ() {
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

//Main difference is that we return pair and define the pair based on the front of both queues
    RGTpair remove() {
        if (redSize == 0 || greenSize == 0) {
            throw std::runtime_error("Cannot form a pair");
        }

        RGTpair pair;
        pair.thing1 = redQueue[redFront];
        pair.thing2 = greenQueue[greenFront];
        
        redFront = (redFront + 1) % MAX_SIZE;
        greenFront = (greenFront + 1) % MAX_SIZE;
        redSize--;
        greenSize--;

        return pair;
    }

    bool empty() const {
        return redSize == 0 && greenSize == 0;
    }

};


#endif // QUEUE_H