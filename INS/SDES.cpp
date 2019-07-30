#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
char key[10],pText[8];
int ikey[10],ipText[8];
int IP[8],IPI[8],p10[10],p8[8],p4[4],EP[8],s0[4][4],s1[4][4];
void init()
{
    IP = {2,6,3,1,4,8,5,7};
    IPI= {4,1,3,5,7,2,8,6};
    p10= {3,5,2,7,4,10,1,9,8,6};
    p8 = {6,3,7,4,8,5,10,9};
    p4 = {2,4,3,1};
    EP = {4,1,2,3,2,3,4,1};
    s0 = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
    s1 = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
}
void convertp10(int key[],int np10[])
{
    for(int i=0;i<10;i++)
        np10[i]=key[p10[i]-1];
    cout<<"P10 : ";
    for(int i=0; i<10; i++)
        cout<<np10[i]<<" ";
    cout<<endl;
}
int main()
{
    init();
    cout<<"--------------SDES-----------------\n";
    //cout<<"Enter 10 bit Key :- ";
    //cin>>key;
    key={'1','0','1','1','0','1','1','1','0','0'};
  //  cout<<"Enter 8 bit Plain Text :- ";
    pText={'1','0','1','1','0','1','1','1'};
//cin>>pText;
    int np10[10];
    for(int i=0; i<10; i++)
        ikey[i]=key[i]-48;
    for(int i=0; i<8; i++)
        ipText[i]=pText[i]-48;
    cout<<"\nKey Generation Begin....\n";
    convertp10(ikey,np10);

    /*
    for(int i=0; i<8; i++)
        cout<<ipText[i]<<" "<<ikey[i]<<endl;
    */
    return 0;
}
