#include "LinkedList.h"
#include <string>
#define MAX_ITEMS 5
using namespace std;

//Akshay Priority Queue Code:
template <class T>
class PriorityQueue : public LinkedList<T> {
    public:
        PriorityQueue() = default;

        void enqueue(T cargo) {
            if (LinkedList<T>::length() == 0) {
                LinkedList<T>::insert_at_front(cargo);
            } else {
                //position 
                int n = 1;
                //there are two parts, one makes sure that the length of linked list isnt more than the position (n)
                //The other part ensures that the item at that position (n) is greater than cargo
                //While statement will break due to length or when the cargo is greater than the item at position
                while (n <= LinkedList<T>::length() && LinkedList<T>::get_item_at(n) > cargo) {
                    n++;
                }

                LinkedList<T>::insert_item_at(cargo, n - 1);
            }
        }
        T dequeue() {
            if (empty())
                throw underflow_error("Error: Cannot dequeue from empty queue.");
            return LinkedList<T>::remove_from_front();
        }
        T top() {
            return LinkedList<T>::get_item_at(0);
        }
        bool empty() {
            return (LinkedList<T>::length() == 0);
        }
        string to_string() {
            string s = "(";
            int i;
            for (i = 1; i < LinkedList<T>::length(); i++) {
                s += std::to_string(LinkedList<T>::get_item_at(i));
                s += ", ";
            }
            s += std::to_string(LinkedList<T>::get_item_at(i));
            s += ")";
            return s;
        }
};

template <class T>
class ArrayPriorityQueue {
    private:
        int first;
        int last;
        int length;
        T items[MAX_ITEMS];
    public:
        ArrayPriorityQueue() {
            first = 0; // first and last store where exactly the items are in the array
            last = 0;
            length = 0; // Number of elements in the list
        }
        void enqueue(const T& val) {
            if ((last + 1) % MAX_ITEMS == first) {
                throw overflow_error("Error: No more space in queue.");
            }
            items[last] = val;
            int index1 = last;
            last = (last + 1) % MAX_ITEMS;
            length++;
            if (length == 1) return;

            int index2 = (index1 == 0) ? MAX_ITEMS - 1 : index1 - 1;
            T tempItem;
            int swapCounter = 1;
            while (items[index1] > items[index2] && swapCounter < length) {
                tempItem = items[index1];
                items[index1] = items[index2];
                items[index2] = tempItem;
                swapCounter++;

                index2 = (index2 == 0) ? MAX_ITEMS - 1 : index2 - 1;
                index1 = (index1 == 0) ? MAX_ITEMS - 1 : index1 - 1;
            }
        }
        T dequeue() {
            if (empty())
                throw underflow_error("Error: Cannot dequeue from empty queue.");
            
            int old1st = first;
            first = (first + 1) % MAX_ITEMS;
            return items[old1st];
        }
        T top() {
            return items[first];
        }
        bool empty() const {
            return (first == last);
        }
};