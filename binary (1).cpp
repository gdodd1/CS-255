/*
Name: Garrett Dodd
File: Project 4
Class: CS 255 - Computer Science II
Professor: Dr. Janet Jenkins
Date: 6 December 2021
*/

#include <iostream>

using namespace std;




/*
Name:			Node
Description:	Node struct that enables the BST to have leaves
Input:			N/A
Output:			N/A
Return:			N/A
*/
struct Node {
    int data = 0;
    Node* left = nullptr;
	Node* right = nullptr;
};
/*
Name:			BST
Description:	Binary Sorting Tree class
Input:			N/A
Output:			N/A
Return:			N/A
*/
class BST{
	Node* root;
	int height, numNodes;
	
	bool InsertPriv(int data, Node* &root);
    static void InorderPrint(Node* root);
    static void PrefixPrint(Node* root);
    static void PostfixPrint(Node* root);
    static int privHeight(Node* root);
	
	
public:
	BST();
	bool Insert(int value);
	void Inorder();
	void Prefix();
	void Postfix();
	int Height();
	void PrintNumNodes();
	
};
/*
Name:			InsertPriv
Description:	Inserts an integer into the BST by traversing the tree starting from the root
Input:			int data, Node* &root
Output:			BST with an added integer
Return:			boolean true/false
*/
bool BST::InsertPriv(int data, Node* &root){
	if(root == NULL){
		Node* newNode = new Node();
		newNode->data = data;
		root = newNode;
		numNodes += 1;
		return true;
	}
	else{
		if(data < root->data)
			InsertPriv(data, root->left);
			
		else if (data > root->data)
			InsertPriv(data, root->right);
			
		else return false;
	}
}
/*
Name:			InorderPrint
Description:	Prints the BST in order from least to greatest 
Input:			Node* root
Output:			BST in order
Return:			N/A
*/
void BST::InorderPrint(Node* root){
	if(root == NULL)
		return;
	InorderPrint(root->left);
	cout << root->data << "\t";
	InorderPrint(root->right);
}
/*
Name:			PrefixPrint
Description:	Prints the root int value then traverses down the left then right side of the tree, printing all values
Input:			Node* root
Output:			BST from node, left then right
Return:			N/A
*/
void BST::PrefixPrint(Node* root){
	if (root == NULL)
		return;
	cout << root->data << "\t";
	PrefixPrint(root->left);
	PrefixPrint(root->right);
}
/*
Name:			PostfixPrint
Description:	Prints the BST from left, then right, then the root
Input:			Node* root
Output:			BST from left, then right, then root
Return:			N/A
*/
void BST::PostfixPrint(Node* root){
	if (root == NULL)
		return;
	PostfixPrint(root->left);
	PostfixPrint(root->right);
	cout << root->data << "\t";
}
/*
Name:			privHeight
Description:	calculates the height of the BST by traversing down the longest sides and determining the max
Input:			Node* root
Output:			N/A
Return:			int of the height of the BST
*/
int BST::privHeight(Node* root){
	if (root == NULL)
		return -1;
	else{
		int lheight = privHeight(root->left);
		int rheight  = privHeight(root->right);
		
		return (lheight > rheight) ? lheight + 1 : rheight + 1;
	}
}
/*
Name:			BST
Description:	constructor for the BST object
Input:			N/A
Output:			N/A
Return:			N/A
*/
BST::BST(){
	root = NULL;
	this->height = 0;
}
/*
Name:			Insert
Description:	Calls insertPriv
Input:			int value
Output:			N/A
Return:			insertPriv(value, root)
*/
bool BST::Insert(int value){
	return InsertPriv(value, root);
}
/*
Name:			InOrder
Description:	calls InorderPrint
Input:			N/A
Output:			N/A
Return:			N/A
*/
void BST::Inorder(){
	InorderPrint(root);
}
/*
Name:			Prefix
Description:	calls PrefixPrint
Input:			N/A
Output:			N/A
Return:			N/A
*/
void BST::Prefix(){
	PrefixPrint(root);
}
/*
Name:			Postfix
Description:	calls PostfixPrint
Input:			N/A
Output:			N/A
Return:			N/A
*/
void BST::Postfix(){
	PostfixPrint(root);
}
/*
Name:			Height
Description:	calls PrivHeight
Input:			N/A
Output:			N/A
Return:			int of height of the BST
*/
int BST::Height(){
	return privHeight(root);
}
/*
Name:			printNumNodes
Description:	prints the number of nodes in a BST
Input:			N/A
Output:			the number of nodes in the BST
Return:			N/A
*/
void BST::PrintNumNodes(){
	(numNodes == 0) ? cout << "There are 0 nodes in the BST\n" 
	: (numNodes == 1) ? cout << "There is 1 node in the BST\n" 
	: cout << "There are " << numNodes << " nodes in the BST\n";
}



/*
Name:			menu
Description:	displays a menu and uses a switch statement to call BST methods
Input:			ints of which method to use
Output:			a menu format, and all method output
Return:			N/A
*/
void menu(){
	char letter = 'Y';
	int choice;
	int num;
	BST tree;
	while(toupper(letter) == 'Y'){
		cout << "\n\n ********** MENU **********\n\n";
		cout << "Enter the number of which function you'd like to perform:\n";
		cout << "\t1: Add to BST\n";
		cout << "\t2: Print Inorder\n";
		cout << "\t3. Print Prefix\n";
		cout << "\t4. Print Postfix\n";
		cout << "\t5: Print the number of nodes\n";
		cout << "\t6. Print the height of the BST\n";
		cout << "\t7. Clear the console\n";
		cout << "\t8. Exit the program\n\t";
		cin >> choice;
		switch (choice){
			case 1:	cout << "Enter the value you'd like to insert into the BST:\t";
					cin >> num;
					tree.Insert(num);
					break;
			case 2: cout << "\n\n ******** Printing the Binary Search Tree Inorder ********\n\n";
					
					tree.Inorder();
					break;
			case 3: cout << "\n\n ******** Printing the Binary Search Tree Prefix ********\n\n";
					tree.Prefix();
					break;
			case 4: cout << "\n\n ******** Printing the Binary Search Tree Postfix ********\n\n";
					tree.Postfix();
					break;		
			case 5:	cout << "\n\n ******** Printing the number of nodes in the Binary Search Tree ********\n\n";
					tree.PrintNumNodes();
					break;
			case 6:	cout << "\n\n********** Printing the height of the Binary Search Tree **********\n\n";
					cout << tree.Height();
					break;
			case 7:	system("CLS");
					break;
			case 8:	exit(1);
					break;
			default:	cout << "\n\nHaha idiot cant put in a number 1-8. Get some sleep lol\n\n";
		}
	cout << "\n\n Continue? (Y/N):\t"; cin >> letter;
	}
}

int main(){
	
	menu();
	return 0;
}


