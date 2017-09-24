#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H
#include "iostream"
#include "cstring"

using namespace std;

typedef struct student
{
	char* Name;	// student's name
	char* ID;	// student's id
	int Number;	// student's numbering
	struct student* Next;	// pointer to next student
}student;

student* CreateList();
	// Create a NULL list
student* CreateNode(char* name,char* id,int number);
	// Create Node with data
void Insert(student* &Start,student* Node);
	// Insert a Node to List
void DeleteNode(student* &Start,int number);
	// Delete a Node in List
void DeleteList(student* &Start);
	// Delete List
void Display(student* Start);
	// Display to screen the List

#endif

