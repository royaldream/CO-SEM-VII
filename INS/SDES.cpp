#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#define SIZE 50
using namespace std;
char key[10],pText[8];
int ikey[10],ipText[8];
int IP[8],IPI[8],p10[10],p8[8],p4[4],EP[8],s0[4][4],s1[4][4],key1[8],key2[8];
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
void leftShift(int data[],int n)
{
    int temp[SIZE];
    for(int i=0; i<n; i++)
    {
        temp[i]=data[i];
        if((i+1)==n)
            data[i]=temp[0];
        else
            data[i]=data[(i+1)%n];
    }
    for(int i=0; i<5; i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
void convertp10(int key[],int np10[])
{
    for(int i=0; i<10; i++)
        np10[i]=key[p10[i]-1];
    cout<<"P10 : ";
    for(int i=0; i<10; i++)
        cout<<np10[i]<<" ";
    cout<<endl;
}
void partitionLR(int np10[],int LS1[],int LS2[],int n)
{
    for(int i=0;i<n/2;i++)
    {
        LS1[i]=np10[i];
    }
    for(int i=n/2;i<n;i++)
    {
        LS2[i%(n/2)]=np10[i];
    }
}
void createKey(int np10[10],int key1[8],int key2[8])
{
    int temp[10];
    int LS1[5],LS2[5];
    partitionLR(np10,LS1,LS2,10);
    cout<<"LS1 L:";
    leftShift(LS1,5);
    cout<<"    R:";
    leftShift(LS2,5);
    for(int i=0;i<10;i++){
        if(i<5)
            temp[i]=LS1[i%5];
        else
            temp[i]=LS2[i%5];
    }
    for(int i=0;i<8;i++){
        key1[i]=temp[p8[i]-1];
    }
    cout<<"Key 1 : ";
    for(int i=0; i<8; i++)
        cout<<key1[i]<<" ";
    cout<<endl;
    leftShift(LS1,5);
    leftShift(LS2,5);
    cout<<"LS2 L:";
    leftShift(LS1,5);
    cout<<"    R:";
    leftShift(LS2,5);
    for(int i=0;i<10;i++){
        if(i<5)
            temp[i]=LS1[i%5];
        else
            temp[i]=LS2[i%5];
    }
    for(int i=0;i<8;i++){
        key2[i]=temp[p8[i]-1];
    }
    cout<<"Key 2 : ";
    for(int i=0; i<8; i++)
        cout<<key2[i]<<" ";
    cout<<endl;
}
void xorEPKey(int data1[],int data2[],int n){
    for(int i=0;i<n;i++){
        data1[i]=(data1[i]+data2[i])%2;
    }
}
void encryption(int ipText[],int key1[],int key2[]){
    int iIP[8],iEP[8],SBOX0[4],SBOX1[4];
    for(int i=0;i<8;i++)
        iIP[i]=ipText[IP[i]-1];
    cout<<"\nIP :";
    for(int i=0;i<8;i++)
        cout<<iIP[i]<<" ";
    for(int i=0;i<8;i++)
        iEP[i]=iIP[EP[i]+3];
    cout<<"\nEP :";
    for(int i=0;i<8;i++)
        cout<<iEP[i]<<" ";
    xorEPKey(iEP,key1,8);
    cout<<"\nEP' :";
    for(int i=0;i<8;i++)
        cout<<iEP[i]<<" ";
    partitionLR(iEP,SBOX0,SBOX1,8);

    cout<<endl;
    for(int i=0;i<4;i++)
        cout<<SBOX0[i]<<" "<<SBOX1[i]<<endl;
}
int main()
{
    init();
    cout<<"--------------SDES-----------------\n";
    //cout<<"Enter 10 bit Key :- ";
    //cin>>key;
    key= {'1','0','1','1','0','1','1','1','0','0'};
    //  cout<<"Enter 8 bit Plain Text :- ";
    pText= {'1','0','1','1','0','1','1','1'};
//cin>>pText;
    int np10[10];
    for(int i=0; i<10; i++)
        ikey[i]=key[i]-48;
    for(int i=0; i<8; i++)
        ipText[i]=pText[i]-48;
    cout<<"\n\tKey Generation Begin....\n\n";
    convertp10(ikey,np10);
    createKey(np10,key1,key2);
    cout<<"\n\tKey Generation END....\n";
    cout<<"\n\tEncryption Begin.....\n";
    encryption(ipText,key1,key2);
    /*
    for(int i=0; i<8; i++)
        cout<<ipText[i]<<" "<<ikey[i]<<endl;
    */
    return 0;
}
