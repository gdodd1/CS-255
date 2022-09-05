#include "Poly.h"
// ***********************************************
// Shell code provided by Dr. Janet T. Jenkins
// You should comment each method and add
// header comments below these comments
// ***********************************************

/*
Name: 		Garrett Dodd
File: 		Polynomial Linked List Class
Date: 		Nov. 30
Professor: 	Dr. Jenkins
*/

Node::Node():coeff(0), degree(0), next(nullptr){}
Node::Node(int c, int d):coeff(c), degree(d), next(nullptr){}
Node::Node(int c, int d, Node* n):coeff(c), degree(d), next(n){}
    
Poly::Poly():head(nullptr){

}
/*
Name:			Copy
Description:	copies a polynomial to another polynomial
Input:			p1 and p2
Output:			N/A
Return:			N/A
*/
void Poly::Copy(const Poly& p){
    Node* t = p.head;
    if(&p != this){
        this->AddTerm(t->coeff, t->degree);
        t = t->next;
    }
}
/*
Name:			Poly(const Poly& p)
Description:	copies a polynomial to another polynomial
Input:			p1 and p2
Output:			N/A
Return:			new polynomial
*/
Poly::Poly(const Poly& p){
    Copy(p);
}
/*
Name:			operator = 
Description:	sets a polynomial equal to another polynomial
Input:			p1 and p2
Output:			N/A
Return:			the addes polynomials
*/
Poly& Poly::operator= (const Poly& p){
    if (this == &p)
        return *this;
    if (head != nullptr)
        Reset();
    Copy(p);
    return *this;
    
}

Poly::~Poly(){
    Reset();
}
/*
Name:			AddTerm
Description:	Adds a new Node to a Linked List and makes a new coeff and degree
Input:			coeff and degree
Output:			N/A
Return:			new Node
*/
void Poly::AddTerm(int c, int d){
    Node *newNode = new Node(c, d, nullptr);

    if(head->degree != d && head->degree < d){
        head = new Node(c, d, head);
    } else{
        Node *t = head;
        Node *p = t;

        while(t != nullptr && d < t->degree){
            p = t;
            t = t->next;
        }
        if(d != p->degree){
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}
/*
Name:			Eval
Description:	Plugs in x and solves the equation
Input:			Polynomial and x
Output:			N/A
Return:			total of the values
*/
double Poly::Eval(double x){
    Node *t = head;
	double total;
	while(t->next != nullptr){
		total += ( head->coeff * (pow(x, head->degree)));
	}
    
    return total;
}
/*
Name:			Reset
Description:	deletes a polynomial, preventing creating a data leak larger than Sony's back in 2011
Input:			polynomial
Output:			N/A
Return:			N/A
*/
void Poly::Reset(){
    Node* t = head;
    while(head != nullptr){
        t = head;
        delete t;
        head = head->next;
    }
    delete head;
}
/*
Name:			Derivative
Description:	Finds the derivative of a polynomial
Input:			A polynomial
Output:			N/A
Return:			N/A
*/
void Poly::Derivative(){
Node* t = head;
	while(t->next != nullptr){
		t->coeff = t->coeff * t->degree--;
		t = t->next;
	}
}
/*
Name:			operator>>
Description:	allows for inputs to polynomials
Input:			User Input
Output:			N/A
Return:			is
*/
istream& operator>>(istream& is, Poly& p){
    char t;
    int coefficient, degree;
    is >> t;
    	while(t != '>'){
			is >> coefficient;
			is >> t;
			is >> t;
			is >> degree;
			p.AddTerm(coefficient, degree);
			is >> t;
    	}
    return is;
}
/*
Name:			operator<<
Description:	Outputs the polynomial
Input:			polynomial
Output:			prints the polynomial
Return:			os
*/
ostream& operator<<(ostream& os, const Poly& p){
    Node *t = p.head;
	os << "<";
    	while(t != nullptr){
        	if(t->degree != 0 && t->degree != 1){
				os << t->coeff;
				os<<"x^";
				cout << t->degree;
        	}
        t = t->next;
    	}
	os << ">";

    return os;
}
/*
Name:			
Description:	
Input:			
Output:			
Return:			
*/
Poly operator+(const Poly& p1, const Poly& p2){
    Poly result;
	Node* iteration1 = p1.head;
	Node* iteration2 = p2.head;
	
	while(iteration1 != nullptr && iteration2 != nullptr){
		if(iteration1->degree == iteration2->degree){
			result.AddTerm(iteration1->coeff+iteration2->coeff, iteration1->degree);
			iteration1 = iteration1->next;
			iteration2 = iteration2->next;
        }
		else if(iteration1->degree > iteration2->degree){
			result.AddTerm(iteration1->coeff, iteration1->degree);
			iteration1 = iteration1->next;
			iteration2 = iteration2->next;
		}
		else if(iteration1->degree < iteration2->degree){
			result.AddTerm(iteration2->coeff, iteration2->degree);
			iteration1 = iteration1->next;
			iteration2 = iteration2->next;
		}
	}

    return result;
}