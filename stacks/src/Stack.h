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

bool is_valid_infix_expression(string input) {
    int parenum = 0;
    Stack<string> expression;
    vector<string> proc = splitspaces(input);
    for(int i = 0; i < proc.size() ; i++) {
        string vecval = proc[i];
        for(int j = 0; j < vecval.length();j++) {
            if(vecval[j] == '(') {
                parenum++;
                continue;
            }
            if(vecval[j] == ')') {
                parenum--;
                continue;
            }
        }
    }
    if(parenum == 0) {
        return true;
    }
    return false;
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
                Operands.push(Operands.pop() - num);
            }
            if(numoroperator == MULT) {
                Operands.push(num * Operands.pop());
            }
            if(numoroperator == DIV) {
                Operands.push(Operands.pop() / num);
            }
        }
    }
    return Operands.top();
}

string convertpost_to_infix(string s) {
    int prevop = -1;
    Stack<string> Equation;
    vector<string> proc = splitspaces(s);
    for(int i = 0; i < proc.size(); i++) {
        string vecval = proc[i];
        int numoroperator = vecval[0] - '0'; 
        if(numoroperator >= 0) {
            Equation.push(vecval);
        }
        else {
            string num = Equation.pop();
                if(numoroperator == ADD) {
                    Equation.push( "(" + Equation.pop() + " + "+ num + ")");
                }
                if(numoroperator == SUB) {
                    Equation.push("(" + Equation.pop() + " - " +  num + ")");
                }
                if(numoroperator == MULT) {
                    Equation.push("(" + num + " * "+ Equation.pop() + ")");
                }
                if(numoroperator == DIV) {
                    Equation.push("(" + Equation.pop() + " / " + num + ")");
                }
        }
    }    
    return Equation.top();
}
