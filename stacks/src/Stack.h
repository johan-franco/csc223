#include "LinkedList.h"
#include <vector>
#define ADD  -5
#define MULT -6
#define SUB -3
#define DIV -1

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

vector<string> splitspaces(string input) {
    stringstream ss(input);
    vector<string> output;
    string nums;
    while (ss >> nums) {
        output.push_back(nums);
    }
    return output;
}


int eval_postfix_expr(string s) {
    Stack<int> Operands;
    vector<string> proc = splitspaces(s);
    for(int i = 0; i < proc.size(); i++) {
        string vecval = proc[i];
        int numoroperator = vecval[0] - '0'; 
        if(numoroperator >= 0) {
            int operand = stoi(vecval);
            Operands.push(operand);
        }
        else {
            int num = Operands.pop();
            if(numoroperator == ADD) {
                Operands.push(num + Operands.pop());
            }
            if(numoroperator == SUB) {
                Operands.push(num - Operands.pop());
            }
            if(numoroperator == MULT) {
                Operands.push(num * Operands.pop());
            }
            if(numoroperator == DIV) {
                Operands.push(num / Operands.pop());
            }
        }
    }
    return Operands.top();
}
