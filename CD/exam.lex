ch  or|but|and
%{
int ccount=0;
int count=0;
%}

%%
[a-zA-Z0-9_ ]+{ch}[a-zA-Z0-9_ ]+[\n]  {ccount++;fprintf(yyout,"%s",yytext);}
[a-zA-Z0-9_ ]*[\n]   {count++;}
%%

int yywrap(){
    return 1;
}

int main(){
    yyin=fopen("data.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    printf("Compound :%d",ccount);
    printf("Non Compound :%d\n",count);
    fclose(yyin);
    fclose(yyout);
    return 0;
}
