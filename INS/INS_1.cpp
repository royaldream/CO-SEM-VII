#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define Size 50
using namespace std;
void decription(string str,int key)
{
    int ch;
    int i;
//	cout<<key<<endl;
    for(i=0; str[i]!=NULL; i++)
    {

        ch=(int)str[i];

        if(isupper(str[i]))
        {
            ch=ch-key-65;
            if(ch<0)
                ch=ch+26;
            ch=ch%26+65;
        }
        else if(islower(str[i]))
        {
            ch=ch-key-97;
            if(ch<0)
                ch=ch+26;
            ch=ch%26+97;

        }
        //ch=ch-key;
        str[i]=(char)ch;

    }
    cout<<"Decription : "<<str<<endl;
}
void encript(string str,int key)
{

    int i,ch;
    for(i=0; str[i]!=NULL; i++)
    {

        ch=(int)str[i];
//        ch=ch+key;

        if(isupper(str[i]))
        {
            ch=ch+key-65;
            ch=ch%26+65;
        }
        else if(islower(str[i]))
        {
            ch=ch+key-97;
            ch=ch%26+97;

        }
        str[i]=(char)ch;
    }
    cout<<" Encript data : "<<str<<endl;
    decription(str,key);
}

int main()
{
    int key;
    cout<<"Enter Your Key :- ";
    cin>>key;
    cout<<"Key :"<<key<<endl;
    fstream file;
    file.open("data.txt");
    string datas;
    while(file)
    {
        string data;
        getline(file,datas);
        cout<<data;
        encript(datas,key);
//decription(datas,key);
//        strcpy(data,datas);
    }


}
