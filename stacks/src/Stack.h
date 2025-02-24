#include "LinkedList.h"


template <class T>
struct Stack : public LinkedList<T>
{
    void push(T item) {
        LinkedList<T>::insert_at_front(item);
    }

    T pop() {
        return LinkedList<T>::remove_from_front();
    }

    bool empty() const {
        return (LinkedList<T>::length() == 0);
    }

    T top() {
       if (LinkedList<T>::head == nullptr)
           throw runtime_error("Can't return top item of empty stack!");
       return LinkedList<T>::head->cargo;
    }
};

string remspaces(string input) {
    std::string::iterator end_pos = std::remove(input.begin(), input.end(), ' ');
    input.erase(end_pos, input.end());
    string output = input;
    return output;
}

int eval_postfix_expr(string s) {
    Stack<int> Operands;

}