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
        items[last] = value;
        last++;
    }

    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        T oldfirst = items[first];
        last--;
        return oldfirst;
    }

    bool empty() const {
        return first == last;
    }
};
#endif // QUEUE_H