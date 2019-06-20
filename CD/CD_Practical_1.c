#include<stdio.h>
#include<string.h>
int isOperater(char c)
{
    int i=0;
    char op[]={'*','/','-','+','='};
    for(i=0;i<strlen(op);i++){
        if(op[i]==c)
        return 1;
        //printf("%c",op[i]);
    }
    return 0;
}
int isDel(char c)
{
    int i=0;
    char op[]={',',';',' ','\n','\t'};
    for(i=0;i<strlen(op);i++){
        if(op[i]==c)
        return 1;
        //printf("%c",op[i]);
    }
    return 0;
}
void main(){
    FILE *fin,*fout;
    char c;
    fin=fopen("data.c","r+");
    fout=fopen("data1.txt","w");
    //c=fgetc(fin);
    //printf("%c",c);
    while(1)
    {
        c=fgetc(fin);

        if(feof(fin))
            break;
        if(isOperater(c)||isDel(c)){
            if(c!='\n')
                fputc('\n',fout);
            if(c!=' '&&c!='\n')
            {
                printf("%c",c);
                fputc(c,fout);
                fputc('\n',fout);
            }
            //printf("%c",c);
        }else{
            fputc(c,fout);
        }
    }
    fclose(fin);
    fclose(fout);
    //printf("Hello World!");
}
