#include "LinkedList.h"

template <class T>
class Queue : public LinkedList<T>
{
  public:
    Queue() = default;

    static const int MAX_SIZE = 10;

    void insert(T item) {
        
        if ((LinkedList<T>::length()+1)% MAX_SIZE == 0) {
            throw std::runtime_error("No more space in queue");
        }
        if (this->empty()){
            LinkedList<T>::insert_at_front(item);
        }
        else  {
            LinkedList<T>::insert_at_end(item);
        }
    }

    T remove() {
        if (this->empty()) {
            throw std::runtime_error("Can't remove from empty queue");
        }
        return LinkedList<T>::remove_from_front();
    }

    bool empty() const {
        return (LinkedList<T>::length() == 0);
    }
};