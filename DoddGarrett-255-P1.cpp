/*
 Name: Garrett Dodd
 
 Due Date: 5 October 2021
 
 Course: CS-255-01
 
 File Name: DoddGarrett-255-P1.cpp
 
 Description: This program is a function calculator. It will display a menu and the user             will choose which function they'd like to use, then the function run, then             the user will specify whether or not they'd like to continue, while also               given the option to exit in the menu.
 
 */

#include <iostream>
#include "Fraction.h"
using namespace std;

//Function Prototypes

void menu();
void Arithmetic(Fraction f1, Fraction f2, string operation);
void Relational(Fraction f1, Fraction f2, string operation);
void Prefix(Fraction f1, string operation);
void Postfix(Fraction f1, string operation);
void cont(char& continueChoice);

//Main Function Driver

int main(){
    int choice;
    char continueChoice = 'Y';
    Fraction f1;
    Fraction f2;
    string operation;
    
    //Do-While loop to repeat the menu function and switch statement
    
    do{
        menu();
        cin >> choice;
        
        //Switch statement to determine the function to run after collecting user input
        
        switch (choice){
            case 1: cout << "\n *****ARITHMETIC***** \n";
                    Arithmetic(f1, f2, operation);
                    cont(continueChoice);
                    break;
            case 2: cout << "\n *****RELATIONAL***** \n";
                    Relational(f1, f2, operation);
                    cont(continueChoice);
                    break;
            case 3: cout << "\n *****PREFIX***** \n";
                    Prefix(f1, operation);
                    cont(continueChoice);
                    break;
            case 4: cout << "\n *****POSTFIX***** \n";
                    Postfix(f1, operation);
                    cont(continueChoice);
                    break;
            case 5: exit(1);
        }
    }while(toupper(continueChoice) == 'Y');
    
    return 0;
}
//***************************************
//Function Name: menu
//Brief Function Description: displays the menu and names of the functions
//Return Value: void
//Incoming Parameters: N/A
//Outgoing Parameters: N/A
//***************************************
void menu(){
    cout << "**********MENU**********" << endl;
    cout << "1. Arithmetic" << endl;
    cout << "2. Relational" << endl;
    cout << "3. Prefix" << endl;
    cout << "4. Postfix" << endl;
    cout << "5. Exit" << endl;
    cout << "Please Input A Number According To Which Function You'd Like To Use: " <<  endl;
}
//***************************************
//Function Name: Arithmetic
//Brief Function Description: The user will input their aritmetic expression and the                                  function will determine which it is, and solve the expression
//Return Value: N/A
//Incoming Parameters:  Fraction f1, Fraction f2, string operation
//Outgoing Parameters:  N/A
//***************************************
void Arithmetic(Fraction f1, Fraction f2, string operation){
    cout << "\nPlease input your problem in the form of: A/B +-*/ C/D\n";
    cin >> f1 >> operation >> f2;
    
    if(operation == "+"){
        f1 = f1 + f2;
        f1.reduce();
        cout << "\n \n Answer: " << f1;
    } else if (operation == "-"){
        f1 = f1 - f2;
        f1.reduce();
        cout << "\n \n Answer: " << f1;
    }else if (operation == "*"){
        f1 = f1 * f2;
        f1.reduce();
        cout << "\n \n Answer: " << f1;
    }else if (operation == "/"){
        f1 = f1 / f2;
        f1.reduce();
        cout << "\n \n Answer: " << f1;
    }
    
}
//***************************************
//Function Name: Relational
//Brief Function Description: The user will input their relational expression and the                                  function will determine which it is, and solve the expression
//Return Value: N/A
//Incoming Parameters:  Fraction f1, Fraction f2, string operation
//Outgoing Parameters:  N/A
//***************************************
void Relational(Fraction f1, Fraction f2, string operation){
    bool result;
    cout << "\nPlease input your problem in the form of: A/B <= C/D\n";
    cin >> f1 >> operation >> f2;
    
    if(operation == "<"){
        result = f1 < f2;
        if(result == true){
            cout << endl << "True";
        }else{
            cout << endl << "False";
        }
        cout << endl << result;
    }else if (operation == ">"){
        result = f1 > f2;
        if(result == true){
            cout << endl << "True";
        }else{
            cout << endl << "False";
        }
    }else if (operation == "=="){
        result = f1 == f2;
        if(result == true){
            cout << endl << "True";
        }else{
            cout << endl << "False";
        }
    } else if (operation == ">="){
        result = f1 >= f2;
        if(result == true){
            cout << endl << "True";
        }else{
            cout << endl << "False";
        }
    } else if (operation == "<="){
        result = f1 <= f2;
        if(result == true){
            cout << endl << "True";
        }else{
            cout << endl << "False";
        }
    } else if(operation == ">="){
        result = f1 >= f2;
        if(result == true){
            cout << endl << "True";
        }else{
            cout << endl << "False";
        }
    } else if(operation == "!="){
        result = f1 != f2;
        if(result == true){
            cout << endl << "True";
        }else{
            cout << endl << "False";
        }
    }
}
//***************************************
//Function Name: Prefix
//Brief Function Description: The user will input their prefix expression and the                                     function will determine which it is, and solve the expression
//Return Value: N/A
//Incoming Parameters:  Fraction f1, string operation
//Outgoing Parameters:  N/A
//***************************************
void Prefix(Fraction f1, string operation){
    cout << "\n *****PREFIX***** \n Please input your problem in the form: ++ A\n";
    
    cin >> operation >> f1;
    if(operation == "++"){
        cout << endl << ++f1;
    } else if(operation == "--"){
        cout << endl << --f1;
    }
}
//***************************************
//Function Name: Postfix
//Brief Function Description: The user will input their postfix expression and the                                    function will determine which it is, and solve the expression
//Return Value: N/A
//Incoming Parameters:  Fraction f1, string operation
//Outgoing Parameters:  N/A
//***************************************
void Postfix(Fraction f1, string operation){
    cout << "\n *****POSTFIX***** \n Please input your problem in the form: A ++\n";
    
    cin >> f1 >> operation;
    if (operation == "++") {
        f1++;
        cout << endl << f1;
    } else if (operation == "--"){
        f1--;
        cout << endl << f1;
    }
}
//***************************************
//Function Name: cont
//Brief Function Description: The function asks the user if they'd like to continue, and if                           they don't it will kill the program
//Return Value: N/A
//Incoming Parameters:  char& continuechoice
//Outgoing Parameters:  char& continueChoice
//***************************************
void cont(char& continueChoice){
    cout << "\n Would you like to choose another function? (Y/N)\n";
    cin >> continueChoice;
}
