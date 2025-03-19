#include "LinkedList.h"
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 10
#include <stdexcept>


//Array Queue that does not use a circular buffer
//Essentially meaning we can't use % and need to shift the whole array when inserting a item
template <class T>
class Queue {
    int first;
    int last;
    T items[MAX_SIZE];

public:
    Queue() {
        first = 0;
        last = 0;
    }

    void insert(const T& value) {
        if (last - first + 1 >= MAX_SIZE) {
            throw std::overflow_error("No more space in queue");
        }
//This if statement shifts when array reaches the end
//This approach is likely better as shifting at each removal would be extremely long if MAX_SIZE was a large value.
//
        if (last == MAX_SIZE) {
            for(int i = first; i <= last; i++) {
                items[i-first] = items[i];
            }
            last = last - first;
            first = 0;
        }
        items[last] = value;
        last++;
    }

    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        T oldfirst = items[first];
        /* //shifts to beginning during beginning of the array whenever an item is removed from the queue
        for(int i = 0; i < last; i++) {
            items[i] = items[i+1];
        }*/
        first++; //isn't necessary if we shift to beggining at every removal
        //last--; necessary if we shift at begginning at every removal
        return oldfirst;
    }

    bool empty() const {
        return first == last;
    }
};
#endif // QUEUE_H