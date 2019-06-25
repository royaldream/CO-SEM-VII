#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define Size 50
using namespace std;
string decrypt(string text,string key)
{
    int i,j,ch;
    for(i=0;text[i]!=NULL;i++)
    {

            for(j=0;key[j]!=NULL;j++)
            {
                if(toupper(text[i])==key[j])
                {
                    if(isupper(text[i]))
                    {
                        text[i]=(char)(j%26+65);
                    }else if(islower(text[i]))
                    {
                        text[i]=(char)(j+97);
                    }
                    break;

                }
            }
        }

    //cout<<text;
    return text;
}
string encript(string text,string key)
{
    int i;
    int ch;
    for(i=0; text[i]!=NULL; i++)
    {
        ch=(int)text[i];
        if(isupper(text[i]))
        {
            ch=(ch-65)%26;
            //ch=ch%26;
            text[i]=toupper(key[ch]);
        }
        else if(islower(text[i]))
        {
            ch=(ch-97)%26;
            //ch=ch%26;
            text[i]=tolower(key[ch]);

        }
    }
    //cout<<text;
    return text;
}
int main()
{
    string key;
    key="MNBVCXZASDFGHJKLPOIUYTREWQ";
    fstream file;
    file.open("data.txt");
    string datas,cipherText,plain_text;
    while(file)
    {
        getline(file,datas);
        cipherText=encript(datas,key);
        cout<<cipherText<<endl;
        plain_text=decrypt(cipherText,key);
        cout<<plain_text<<endl;;
    }


}
