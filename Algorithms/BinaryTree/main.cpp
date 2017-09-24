#include "binarytree.h"

using namespace std;

int main()
{
    Tree sinhvien;
    sinhvien = CreateTree();
    student* t;
    int NumberOfStudent;
    cin>>NumberOfStudent;
    char name[30];
    char id[10];
    int no;
    for (int i=1;i<=NumberOfStudent;i++)
    {
        cout<<"Name: ";
        cin.ignore(256,'\n');
        cin.getline(name,30);
        cout<<"ID: ";
        cin.getline(id,10);
        cout<<"Numbering: ";
        cin>>no;
        t = CreateNode(name,id,no);
        InsertToTree(sinhvien, t);
    }
    Tree sinhvien2 = CreateTree();
    Copy(sinhvien,sinhvien2);
    Remove(sinhvien2,12);
    cout<<CheckInherTree(sinhvien,sinhvien2);
    Release(sinhvien2);
    Release(sinhvien);
    return 0;
}