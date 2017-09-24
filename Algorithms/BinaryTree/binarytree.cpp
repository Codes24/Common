#include "binarytree.h"

Tree CreateTree()
{
    Tree T;
    T = NULL;
    return T;
}

student* CreateNode(char* name,char* id,int no)
{
    student* S;
    S = new student;
    S->Name = new char[strlen(name) + 1];
    strcpy(S->Name,name);
    S->ID = new char[strlen(id) + 1];
    strcpy(S->ID,id);
    S->No = no;
    S->Right = NULL;
    S->Left = NULL;
    return S;
}

void InsertToTree(Tree &T,student* S)
{
    /* This insert function will arrange student by student'No
        in a binary tree */
    if (T == NULL)
    {
        T = new student;
        T->Name = new char[strlen(S->Name)+1];
        strcpy(T->Name, S->Name);
        T->ID = new char[strlen(S->ID)+1];
        strcpy(T->ID, S->ID);
        T->No = S->No;
        T->Right = NULL;
        T->Left = NULL;
        return;
    }
    if (S->No > T->No) InsertToTree(T->Right,S);
    if (S->No < T->No) InsertToTree(T->Left,S);
    else if (S->No == T->No)
        cout<<"ERROR::NUMBERING::EXISTED"<<endl;
    return;
}

void Display(Tree T)
{
    /* Display' oder is small to large of Studen's Numbering */
    if (T != NULL)
    {
        Display(T->Left);
        cout<<"================="<<endl;
        cout<<"Numbering: "<<T->No<<endl;
        cout<<"Student's name: "<<T->Name<<endl;
        cout<<"Student's ID: "<<T->ID<<endl;
        Display(T->Right);
    }
    return;
}

void DisplayNode(student* S)
{
    cout<<"==========="<<endl;
    cout<<"Numbering: "<<S->No<<endl;
    cout<<"Name: "<<S->Name<<endl;
    cout<<"ID: "<<S->ID<<endl;
}

void Search(Tree T,char* name,int &Temp)
{
    if (T == NULL) return;
    if (strstr(T->Name, name))
    {
        Temp++;
        DisplayNode(T);
    }
    Search(T->Left, name,Temp);
    Search(T->Right, name,Temp);
}

student* SearchMinNode(Tree T)
{
    if (T->Left == NULL) return T;
    else
        return SearchMinNode(T->Left);
}

Tree Remove(Tree &T,int no)
{
    Tree TempTree;
    if (T == NULL)
    {
        cout<<"TREE::STATUS::NOT::FOUND"<<endl;
        return T;
    }
    else if (T->No > no)
    {
        T->Left = Remove(T->Left,no);
    }
    else if (T->No < no)
    {
        T->Right = Remove(T->Right,no);
    }
    else if (T->No == no)
    {
        if (T->Left != NULL && T->Right != NULL)
        {
            TempTree = SearchMinNode(T->Right);
            strcpy(T->Name,TempTree->Name);
            strcpy(T->ID,TempTree->ID);
            T->No = TempTree->No;
            T->Right = Remove(T->Right,TempTree->No);
        }
        else
        {
            TempTree = T;
            if (T->Left == NULL)
            {
                T = T->Right;
            }
            else if (T->Right == NULL)
            {
                T = T->Right;
            }
            delete TempTree;
        }
    }
    return T;
}

void Release(Tree T)
{
    if (T != NULL)
    {
        student* TempLeft = T->Left;
        student* TempRight = T->Right;
        delete T;
        Release(TempLeft);
        Release(TempRight);
    }   
}

void Copy(const Tree &T,Tree &S)
{
	student* i;
	if (T == NULL) return;
	if (T != NULL)
	{
		i = CreateNode(T->Name,T->ID,T->No);
		InsertToTree(S,i);
	}
	Copy(T->Left,S);
	Copy(T->Right,S);
}

int CheckInherTree(Tree T,Tree S)
{
	if (S == NULL) return 1;
	if (T == NULL) return 0;
	if (S->No == T->No)
	{
		int i = CheckInherTree(T->Left,S->Left);
		if (i == 1) return CheckInherTree(T->Right,S->Right);
		else return 0;
	}
	int i = CheckInherTree(T->Left,S);
	if (i == 1) return 1;
	else return CheckInherTree(T->Right,S);
	return 0;
}