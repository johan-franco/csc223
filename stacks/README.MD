# Evaluate Post-fix Expression

## What is a Post-fix Expression 
A postfix expression is a format that some scientific calculators use to evaluate expressions. The more normal format is infix, where operators are between two operands.  A post-fix expression has the operators follow the operand.

```cpp
int eval_postfix_expr(string s) {
    Stack<int> Operands;                        
    vector<string> proc = splitspaces(s);       //Splits the postfix expression into an array of strings
    for(int i = 0; i < proc.size(); i++) {      //For every element in the postfix expression
        string vecval = proc[i];                //Get the current element in the array
        int numoroperator = vecval[0] - '0';    //Convert Char into Int
    
        if(numoroperator >= 0) {                //If the ASCII value is positive (eg. is a number)
            int operand = stoi(vecval);         //"S"tring "TO" "I"nteger
            Operands.push(operand);             //Push to stack
        }

        else {                                          //If the ASCII value is negitive (eg. is a Operator)
            int num = Operands.pop();                   //First Out
            if(numoroperator == ADD) {                  //If Operator is +
                Operands.push(num + Operands.pop());    //Add the two most recent numbers
            }
            if(numoroperator == SUB) {                  //If Operator is -
                Operands.push(Operands.pop() - num);    //Sub the two most recent numbers
            }
            if(numoroperator == MULT) {                 //If Operator is *
                Operands.push(num * Operands.pop());    //Multiply the two most recent numbers
            }
            if(numoroperator == DIV) {                  //If Operator is /
                Operands.push(Operands.pop() / num);    //Divide the two most recent numbers
            }
        }
    }
    return Operands.top();            //Return evaluated result to top of stack
}
```
awdawd