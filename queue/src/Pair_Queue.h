using namespace std;
#include <algorithm> 
#include<iostream>
#include<string>

enum Color {RED, GREEN};

struct RGThing {
    Color color; 
    string label;
};

struct RGTpair {
    RGThing thing1;
    RGThing thing2;
};

/*I've decidied to implement this as an single queue that shifts after reaching the maximum. Soecifically 
the queue is an array that holds RGTpair */
template <class T>
class RGTPQ {
    int first;
    int last;
    int completed;
    //RGThing items[MAX_SIZE];
    RGTpair items[MAX_SIZE/2];

public:
    RGTPG() {
        first = 0;
        last = 0;
        completed = 0;
    }

    void insert(const T& value) {
        if ((last + 1) % MAX_SIZE == first) {
            throw std::overflow_error("No more space in queue");
        }
        int location = first;
        for(location < )
        items[last] = value;
        last = (last + 1) % MAX_SIZE;
    }
/*This insert function needs to take a thing and then place it into the first empty place in the items array

*/
    void insert(const RGThing value) {
        if (completed + 1 >= MAX_SIZE) {
            throw std::overflow_error("No more space in queue");
        }
        if (last == MAX_SIZE) {
            for(int i = first; i <= last; i++) {
                items[i-first] = items[i];
            }
            last = last - first;
            first = 0;
        }

        int i = 0;
        while(i <= last) {
            RGTpair pair = items[i];
            if(pair.thing1.label == NULL) {
                items[i].thing1 == value;
                break;
            }
            if (items[i].thing2 == NULL) {
                items[i].thing2 == value;
                break;
            }
            i++;
        }
        completed = i;
        last++;
    }

    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        int oldfirst = first;
        first = (first + 1) % MAX_SIZE;
        return items[oldfirst];
    }

    bool empty() const {
        return first == last;
    }
};
#endif // QUEUE_H