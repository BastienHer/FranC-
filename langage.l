%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "langage.bison.hpp"
%}

%%

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? { // s'il s'agit d'un nombre on le stocke dans le champ "valeur"
                                      yylval.valeur = atof(yytext);
                                      return NUM;
                                    }
\n     {  return '\n'; }
\r     { }
" "    { }
\t     { }
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos { return COS;  }
un      { yylval.valeur = 1. ; return NUM; }
deux    { yylval.valeur = 2. ; return NUM; }
trois   { yylval.valeur = 3. ; return NUM; }
plus    { return ADD;}
moins   { return SUB;}
fois    { return MULT; }
divise  { return DIV;}
si|ci  { return SI;}
finSi|finCi|faimSi|faimCi { return FINSI;}
sinon|sinon|cinon  { return SINON;}
imprime|unprime|imprim|unprim {return PRINT;}
tantQue|tempsQue|tentQue|tendQue|tenQue|tantQueue { return TANTQUE;}
finTantQue|finTempsQue|finTentQue|finTendQue|finTenQue|finTantQueue|faimTantQue|faimTempsQue|faimTentQue { return FINTANTQUE;}
moins|moin|moan { return SUB;}
GoTo { return GOTO;}
aleatoire|allezatoire { return RAND;}


"//".* { }

@[A-Za-z_][A-Za-z_0-9]* { strcpy( yylval.nom, yytext) ;
                          return LABEL;
                       }

[A-Za-z_][A-Za-z_0-9]* { // s'il s'agit d'une variable, on stocke son nom dans le champ "nom"
                         strcpy( yylval.nom, yytext) ;
                         return VAR;
                       }

\+     {  return ADD; }  
"-"    {  return SUB; }
"*"    {  return MULT; }
"/"    {  return DIV; }
"="|"<-"    {  return '='; }
">"    { return SUP; }
"<"    {return INF;}
">="   {return SUPEG;}
"<="   {return INFEG;}
"!="   {return NEG;}
"=="   {return EGA;}
":"    { return ':'; }   
\(     {  return '('; }
\)     {  return ')'; }
<<EOF>>  { printf("\nOMG ca marche\n"); return 0; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

\"[^\"\']+\" { strcpy(yylval.valeurString,yytext);return STRING;}

%%
