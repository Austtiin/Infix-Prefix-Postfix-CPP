/*
Author: Austin Stephens

Date: 07/07/2022

FileName: AStephens_M01_LA_07052022

Purpous: 
    Module 01, Lab assignment display
    Utilize stacks and mathmatical expressions

Input: 
    Infix, Prefix or post fix based on number selection
    Enter mathmatical equaion

Exceptions:

Ask the user to enter the option to pick between infix, prefix, or postfix.

Allow the user to enter a mathematical expression per the option above.

Allow the user to enter the option to pick between infix, prefix, or postfix.

Ensure that the user does not pick the same exact option again.

Validate that the expression entered is correct per the option picked in step 1.

Evaluate the expression entered per the option selected in step 1.

Display the value produced in the above step.

Convert the expression to be represented per the option picked in step 3.

Display the new expression after being converted in the above step.

Evaluate the expression after being converted.

Display the value produced in the above step.
*/
#include <cstdlib>
#include <stack>
#include <bits/stdc++.h>
using namespace std;


// finding arithmics
int order(char op)
{
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

//cheak & value
int CheckFunc(int a, int b, char op)
{
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

//deter. value
int evaluate(string Check)
{
    int i;
    stack <int> Integers;
    stack <char> Number;
     
    for(i = 0; i < Check.length(); i++)
    {
        if(Check[i] == ' ')
            continue;
        
        else if(Check[i] == '(')
        {
            Number.push(Check[i]);
        }

        else if(isdigit(Check[i])){
            int val = 0;
            while(i < Check.length() &&
            isdigit(Check[i]))
            {
                val = (val*10) + (Check[i]-'0');
                i++;
            }

        Integers.push(val);
        i--;
        }

        else if(Check[i] == ')')
        {
            while(!Number.empty() && Number.top() != '(')
            {
                int Ints1 = Integers.top();
                Integers.pop();
                 
                int Ints2 = Integers.top();
                Integers.pop();
                 
                char op = Number.top();
                Number.pop();
                 
                Integers.push(CheckFunc(Ints2, Ints1, op));
            }

            if(!Number.empty())
               Number.pop();
        }

        else
        {
            while(!Number.empty() && order(Number.top())
                                >= order(Check[i])){
                int Ints1 = Integers.top();
                Integers.pop();
                 
                int Ints2 = Integers.top();
                Integers.pop();
                 
                char op = Number.top();
                Number.pop();
                 
                Integers.push(CheckFunc(Ints2, Ints1, op));
            }

            Number.push(Check[i]);
        }
    }

    while(!Number.empty()){
        int Ints1 = Integers.top();
        Integers.pop();
                 
        int Ints2 = Integers.top();
        Integers.pop();
                 
        char op = Number.top();
        Number.pop();
                 
        Integers.push(CheckFunc(Ints2, Ints1, op));
    }
    return Integers.top();
}

//run
int main()
{
    bool prec;
    string Expr;
    char alg[4] = {'+', '-', '*', '/'};  
    char Val; 
    int Choice;
    stack<int> Precheck;
    Precheck.push(0);

while(1)
{
    cout << " \n\nEnter Expression\n";
    std::getline (cin, Expr);
    
    for (int i = 0; i < 4; i++)
    {
        if (Expr.find(alg[i]) != std::string::npos)
        {
            if (prec = 1)
            {
                break;
            }
            
            cout << "Char found\n";
            prec = 1;
            Val = alg[i];
        }
        else
         prec = 0;
         break;
    }
    if (prec = 0)
    {
       cout << "No Arithmic Found Please Retry\n";
    }

    cout << "\n";
    cout << "\tMenu\t\n";
    cout << "1. Infix\n";
    cout << "2. Prefix\n";
    cout << "3. Postfix\n";
    cout << "4. Exit\n";
    cin >> Choice;
// check for redos
    switch (Choice)
    {
    case 1:
       {
        if (Precheck.top() == 1)
                {
                    cout << "Infix was just used!\n\n";
                    break;
                }

            else if (Precheck.top() != 1)
                {
                    Precheck.push(1);
                }
                cout << "\n\n" << evaluate(Expr);
                }
            break;
    case 2:
       {
        if (Precheck.top() == 2)
                {
                    cout << "Prefix was just used!\n\n";
                    break;
                }

            else if (Precheck.top() != 2)
                {
                    Precheck.push(2);
                }
                cout << "\n\n" << evaluate(Expr);
       }
       break;
    case 3:
        {
        if (Precheck.top() == 3)
                {
                    cout << "Postfix was just used!\n\n";
                    break;
                }

            else if (Precheck.top() != 3)
                {
                    Precheck.push(3);
                }
                cout << "\n\n" << evaluate(Expr);
       }
       break;
    case 4:
    {
        exit(0);
    }
    break;
    default:
        cout << "\n\n Please Enter 1, 2 3 or 4\n";
    }

}
return(0);
}