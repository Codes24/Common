#ifndef BINARY_H
#define BINARY_H
#include "iostream"
#include "cstring"

using namespace std;

typedef struct student
{
    char* Name; // Name of student
    char* ID;   // Student's ID
    int No; // Student' Numbering
    struct student* Right;  // pointer to right
    struct student* Left;   // pointer to left
}student;

typedef student* Tree;

Tree CreateTree();  // create a NULL tre
student* CreateNode(char* name,char* id,int no);    // create a node of tree
void InsertToTree(Tree &T,student* S);  // insert node in tree
void Display(Tree T);   // Display data of tree
void DisplayNode(student* S);   // Display only a node
void Search(Tree T,char* name,int &Temp); // search by name in tree
Tree Remove(Tree &T,int no);	// remove a anyNode of Tree by Studen't Numbering
student* SearchMinNode(Tree T);	// serach and return the node which minimum in Tree
void Release(Tree T);	// release the tree
void Copy(const Tree &T,Tree &S);	
	// copy data 1 Tree
int CheckInherTree(Tree T,Tree S);
	// check S Tree belong T Tree ?

#endif
