/*
Name: Garrett Dodd
Class: CS 255 - Computer Science II
Description: A .cpp file that contains all the methods and functions 
            necessary to have a Polynomial data type
Date: 28 Oct 2021
*/
#include <iostream>
#include <string>
#include "Poly.h"

using namespace std;
//Name: Poly
//Description: Constructor for the poly class
//Input: N/A
//Output: N/A
//Return: N/A
    Poly::Poly(){
        for(int i = 0; i < MAX; i++){
            terms[i]= 0;
        }
        
    }
//Name: Eval
//Description: Evaluates the polynomial based of the inputted integer
//Input: N/A
//Output: N/A
//Return: solution of the evaluated polynomial
	double Poly::Eval(double x){
        double solution;
            for(int i = 0; i < MAX; i++){
                if(terms[i] != 0){
                    solution += (pow(x,i) * terms[i]);
                }
            }
            return solution;
    }
//Name: Reset
//Description: Restes the values of the polynomial to 0
//Input: N/A
//Output: reseetted poly variable
//Return: N/A
	void Poly::Reset(){
        for(int i = 0; i < MAX; i++){
            terms[i] = 0;
        }
    }
//Name: operator+=
//Description: Adds the polynomial on the right to the one on the left
//Input: 2 polynomials 
//Output: changes polynomial 1
//Return: N/A
	void Poly::operator+=(const Poly& p){
        for(int i = 0; i < MAX; i++){
            terms[i] += p.terms[i];
        }
    }
//Name: Derivative
//Description: finds the derivative of the polynomial
//Input: N/A
//Output: N/A
//Return: N/A
	void Poly::Derivative(){
        for(int i = 20; i >= 0; i--){
            if(terms[i] != 0){
                terms[i - 1] = terms[i] * i;
            }
        }
    }
//Name: operator>>
//Description: insertion operator, allows for input
//Input: N/A
//Output: N/A
//Return: data to form a polynomial
	istream& operator>>(istream& is, Poly& p){
        string input = "";
        string temps = "";
        int tempi;
        string tempsp = "";
        int tempip;
        is >> input;
        bool before = true;
        for(int i = 0; i < input.length(); i++){
            if(input[i] != '<' || input[i] != '>' || input[i] != ' '){
                if(before == true){
                    if(input[i+1] != 'x'){
                        temps = input[i] + input[i+1];
                        tempi = (int)temps;
                        before = false;
                    }
                    else{
                        tempi = (int)input[i];
                        before = false;
                    }
                } if(input[i] == 'x'){
                    before = false;
                }
                if(before == false){
                    if(input[i + 1] != ' '){
                        tempsp = input[i] + input[i+1];
                        tempip = (int)tempsp;
                        before = true;
                    }
                    else{
                        tempip = (int)input[i];
                        before = true;
                    }
                }
                p.terms[tempip] = tempi;
            }

        }
        return is;
    }
//Name: ooperator<<
//Description: extraction operator, allows for output
//Input: N/A
//Output: N/A
//Return: the data to output the polynomials
	ostream& operator<<(ostream& os, const Poly& p){
        os << "<";
            for(int i = 20; i >= 0; i--){
                if(p.terms[i] != 0){
                    if(p.terms[20] != 0){
                        os << p.terms[20] << "x^" << i;
                    }
                    if(p.terms[i] > 0 && i != 20){
                        os << " + " << p.terms[i] << "x^" << i;
                    } 
                    else if (p.terms[i] < 0 && i != 20){
                        os << p.terms[i] << "x^" << i;
                    }
                }
            }
        os << ">";
    return os;
    }
//Name: operator+
//Description: adds two polynomials
//Input: 2 polynomials 
//Output: the added polynomials
//Return: the added poluynomials
	Poly operator+(const Poly& p1, const Poly& p2){
        Poly temp;
        for(int i = 0; i < MAX; i++){
            temp.terms[i] = p1.terms[i] + p2.terms[i];
        }
        return temp;
    }
//Name: operator*
//Description: multiplies two polynomials
//Input: 2 polynomials 
//Output: N/A
//Return: the 2 multiplied polynomials
	Poly operator*(const Poly& p1, const Poly& p2){
        Poly temp;
        for(int i = 20; i >= 0; i--){
            if(p1.terms[i] != 0 || p2.terms[i] != 0){
                temp.terms[i * 2] = p1.terms[i] * p2.terms[i];
            }
        }
        return temp;
    }