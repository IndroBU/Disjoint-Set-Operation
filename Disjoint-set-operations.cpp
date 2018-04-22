/// God Help Me
/* Disjoint-set Operations */
#include<stdio.h>
#include<iostream>
#include<set>
#include<string>
using namespace std;
void MAKE_SET();
int FIND_SET(int);
void UNION();
int Set_Element=0;
int Set[100][100];
int Set_Index[100];
string String_Home[100];
int Search_Index(string s)
{
    int ck=0;
    for(int I=1; I<=Set_Element; I++)
    {
        if(String_Home[I]==s) {
            ck=1;
            return I;
        }
    }
    if(ck==0){
    Set_Element=Set_Element +1;
    String_Home[Set_Element] = s;
    return Set_Element;

    }
}
void MAKE_SET()
{

    for(int I=1; I<=Set_Element; I++ )
    {
        Set[I][1]=I;
        Set_Index[I]=1;
    }
}
int FIND_SET(int X)
{
    for(int I=1 ; I<= Set_Element; I++)
    {
        for(int J=1; J<=Set_Index[I]; J++)
        {
            if(X==Set[I][J])
            {
                return I;
            }
        }
    }
}

void UNION(int P, int Q)
{
    for(int I=Set_Index[P]+1,J=1; I<=Set_Index[Q], J<=Set_Index[Q]; I++, J++ )
    {
        Set_Index[P]=Set_Index[P] + 1;
        Set[P][I]=Set[Q][J];
        Set[Q][J]=0;
    }
}
int main()
{
    int V,E,NodeIndex;
    string Node1,Node2;
    cin>>V>>E;
    int A[100],B[100];
    for(int I=1; I<=E; I++)
    {
        cin>>Node1>>Node2;
        NodeIndex=Search_Index(Node1);
        A[I]=NodeIndex;
        NodeIndex=Search_Index(Node2);
        B[I]=NodeIndex;
    }

    int P,Q;
    MAKE_SET();




    for(int I=1; I<=E; I++)
    {
        P=FIND_SET(A[I]);
        Q=FIND_SET(B[I]);
        if(P!=Q)
        {
            UNION(P,Q);
        }
    }

    cout<<endl;

    for(int I=1; I<=Set_Element; I++)
    {
        cout<<String_Home[I]<<" : ";
        for(int J=1; J<=Set_Index[I]; J++)
        {
            if(Set[I][J]!=0)
            cout<<String_Home[Set[I][J]]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
