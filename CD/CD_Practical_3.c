#include<stdio.h>
#include<string.h>
#define SIZE 100
int isOperater(char str[])
{
    /*
    char c[strlen(str)-1];
    strncpy(c, str, strlen(str)-1);
    printf("%s",c);*/
    int i=0;
    char op[5][SIZE]= {"*","/","-","+","="};
    for(i=0; i<5; i++)
    {
        if(strncmp(str,op[i],strlen(str)-1)==0)
        {
            //printf("%s",str);
            return 1;
        }
        //printf("%c",op[i]);
    }
    return 0;
}
void removeUnwantedChar(char *str,char *p)
{
    int i;
    for(i=0; i<strlen(str)-2; i++)
        p[i]=str[i];
    printf("%c",p[1]);
}
int isDel(char str[])
{
    int i=0;
    char op[2][SIZE]= {",",";"};
    for(i=0; i<2; i++)
    {
        if(strncmp(str,op[i],strlen(str)-1)==0)
        {
            //printf("%s",str);
            return 1;
        }
        //printf("%c",op[i]);
    }
    return 0;
}
int isKeyword(char str[])
{
    int i=0;
    char op[32][SIZE]= {"auto", 	"double", 	"int", 	"struct",
                        "break" ,	"else" ,	"long", 	"switch"
                        ,"case", 	"enum" 	,"register" ,	"typedef",
                        "char" ,	"extern" ,	"return" 	,"union",
                        "const" ,	"float" ,	"short", 	"unsigned",
                        "continue", 	"for", 	"signed" ,	"void"
                        "default", 	"goto", 	"sizeof" ,	"volatile"
                        "do" 	,"if" ,	"static" 	,"while"
                       };
    for(i=0; i<32; i++)
    {
        if(strncmp(str,op[i],strlen(op)-1)==0)
        {
            printf("%s",op[i]);
            return 1;
        }
        //printf("%c",op[i]);
    }
    return 0;
}
int isValidToken(char str[])
{
    int flag=0;
    int i=0;
    char op[12]= {'!','@','#','$','%','^','&','*','(',')','~','?'};
    char digit[10]= {'0','1','2','3','4','5','6','7','8','9'};
    for(i=0; i<12; i++)
    {
        if(str[0]==op[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag!=1)
    {
        for(i=0; i<10; i++)
        {
            if(str[0]==digit[i])
            {
                flag=1;
                break;
            }
        }
        int j;
        for( i=0;i<12;i++){
            for( j=0;j<strlen(str);j++)
            {
                if(str[j]==op[i])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag!=1)
            return 1;
    }
    return 0;
}
void main()
{
    FILE *fin,*fout,*fout2;
    char c[SIZE];
    fin=fopen("data1.txt","r+");
    fout=fopen("data3.txt","w+");
    fout2=fopen("error.txt","w+");
    //c=fgetc(fin);
    //printf("%c",c);
    while(1)
    {
        fgets(c,SIZE,fin);

        if(feof(fin))
            break;
        //printf("%s",c);
        if(isOperater(c))
        {
            c[strlen(c)-1]='\0';
            //strcat(c," - Operator\n");
            //fputs(c,fout);
        }
        else if(isDel(c))
        {
            c[strlen(c)-1]='\0';
            //strcat(c," - Delimiter\n");
            //fputs(c,fout);
        }
        else if(isKeyword(c))
        {
            c[strlen(c)-1]='\0';
            // strcat(c," - Keyword\n");
            // fputs(c,fout);
        }
        else if(isValidToken(c))
        {
            //c[strlen(c)-1]='\0';
            //strcat(c," - Identifier\n");
            fputs(c,fout);
        }else{
            c[strlen(c)-1]='\0';
            strcat(c," - Invalid Identifier\n");
            fputs(c,fout2);
        }
    }
    fclose(fin);
    fclose(fout);
    //printf("Hello World!");
}
