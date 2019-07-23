#include<stdio.h>
#include<string.h>
#include<fstream>
#include<iostream>
#include <stdlib.h>
using namespace std;
string decryption(string text,string key,string pT)
{
    cout<<text.length()<<" : D key : "<<key.length()<<endl;
    string newKey,newText,pl;
    for(int i=0; i<key.length(); i++)
    {
        newKey+=toupper(key[i]);
        newText+=toupper(text[i]);
        int j=(newKey[i]-newText[i]-26);
        j=abs(j)%26;
        j+=65;
        pl+=(char)j;
        cout<<newKey[i]<<":"<<(int)newKey[i]<<" "<<(int)newText[i]<<" "<<(int)pT[i]<<" "<<j<<endl;
    }

    return pl;
}
string encript(string text,string key)
{


    string newKey,newText,ct;
    for(int i=0; i<key.length(); i++)
    {
        newKey+=toupper(key[i]);
        newText+=toupper(text[i]);
        int j=(newKey[i]-65+newText[i]-65)%26;
        j+=65;
        ct+=(char)j;
    }

    cout<<"Key : "<<newKey;
    return ct;
}
int main()
{
    string key;
    key="deceptive";
    fstream file;
    file.open("data.txt");
    string datas,cipherText,plain_text;
    while(file)
    {
        getline(file,datas);
        if(datas.length()>key.length())
        {
            int diff=datas.length()-key.length();
            //int j=0;
            for(int i=0; i<diff; i++)
            {
                key+=key[i%(key.length()-1)];
            }
        }
        cout<<"Plain Text :"<<datas<<endl;
        cipherText=encript(datas,key);
        cout<<endl<<"Cipher Text :"<<cipherText<<endl;
        plain_text=decryption(cipherText,key,datas);
        cout<<"Decryption Plain Text :"<<plain_text<<endl;
    }



}
