#include <string>
#include "PriorityQueue.h"
using namespace std;

enum Color {RED, GREEN};

struct RGThing {
    Color color; 
    string label;

    string to_string() {
        return label;
    }
};

struct RGTpair {
    RGThing thing1;
    RGThing thing2;
};

class RGTPQ : public PriorityQueue<RGThing> {
    public:
        RGTPQ() = default;

        bool empty() {
            return PriorityQueue<RGThing>::LinkedList::length() == 0;
        }
        void insert(RGThing rgt) {
            if (empty()) {
                PriorityQueue<RGThing>::LinkedList::insert_at_front(rgt);
                return;
            }
            int counter;
            if (rgt.color == RED) {
                counter = PriorityQueue<RGThing>::LinkedList::length();
                while (counter > 0) {
                    if (PriorityQueue<RGThing>::LinkedList::get_item_at(counter).color == GREEN) {
                        if (counter == 1) {
                            PriorityQueue<RGThing>::LinkedList::insert_item_at(rgt, 0);
                            return;
                        }
                        if (PriorityQueue<RGThing>::LinkedList::get_item_at(counter - 1).color == GREEN) {
                            PriorityQueue<RGThing>::LinkedList::insert_item_at(rgt, counter - 1);
                            return;
                        } else {
                            counter -= 2;
                        }
                    } else {
                        counter--;
                    }
                }
                //Fixed previously was using insert_item_at with counter as location instead of insert at end 
                PriorityQueue<RGThing>::LinkedList::insert_at_end(rgt);
            }
            if (rgt.color == GREEN) {
                counter = 1;
                while (counter <= PriorityQueue<RGThing>::LinkedList::length()) {
                    if (PriorityQueue<RGThing>::LinkedList::get_item_at(counter).color == RED) {
                        if (counter == PriorityQueue<RGThing>::LinkedList::length()) {
                            PriorityQueue<RGThing>::LinkedList::insert_item_at(rgt, PriorityQueue<RGThing>::LinkedList::length());
                            return;
                        }
                        if (PriorityQueue<RGThing>::LinkedList::get_item_at(counter + 1).color == RED) {
                            PriorityQueue<RGThing>::LinkedList::insert_item_at(rgt, counter);
                            return;
                        } else {
                            counter += 2;
                        }
                    } else {
                        counter++;
                    }
                }
                PriorityQueue<RGThing>::LinkedList::insert_item_at(rgt, counter - 1);
            }
        }
        RGTpair remove() {
            if (empty())
                throw underflow_error("Error: Cannot dequeue from empty queue.");
            
            if (PriorityQueue<RGThing>::LinkedList::length() == 1) {
                if (PriorityQueue<RGThing>::LinkedList::get_item_at(1).color == GREEN)
                    throw underflow_error("Error: No red items left in queue.");
                else
                    throw underflow_error("Error: No green items left in queue.");
            }


            RGThing rgt1 = PriorityQueue<RGThing>::LinkedList::get_item_at(1);
            RGThing rgt2 = PriorityQueue<RGThing>::LinkedList::get_item_at(2);

            if (rgt1.color != RED) 
                throw underflow_error("Error: No red items left in queue.");
            if (rgt2.color != GREEN)
                throw underflow_error("Error: No green items left in queue.");
            
            RGTpair rgtp;
            rgtp.thing1 = PriorityQueue<RGThing>::dequeue();
            rgtp.thing2 = PriorityQueue<RGThing>::dequeue();

            return rgtp;
        }
        int size() {
            return PriorityQueue<RGThing>::LinkedList::length();
        }
};