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
sin(us|) { return SIN;  } 
cos(inus|) { return COS;  } 
tan(ge(a|)(n|m)te) { return TAN; }
zero  { yylval.valeur = 1. ; return NUM; }
un      { yylval.valeur = 1. ; return NUM; }
deux    { yylval.valeur = 2. ; return NUM; }
trois   { yylval.valeur = 3. ; return NUM; }
quatre  { yylval.valeur = 4. ; return NUM; }
cinq  { yylval.valeur = 5. ; return NUM; }
six   { yylval.valeur = 6. ; return NUM; }
sept     { yylval.valeur = 7. ; return NUM; }
huit    { yylval.valeur = 8. ; return NUM; }
neuf   { yylval.valeur = 9. ; return NUM; }

plus    { return ADD;}
m(oi|oa)n(|s) { return SUB;} 
foi(s|)    { return MULT; } 
divi(s|z)e  { return DIV;}

(s|c)i  { return SI;}
f(in|aim)(C|S)i { return FINSI;} 
(s|c)inon  { return SINON;}
(u|i)(m|n)prim(e|) {return PRINT;}
t(a|e)(n|m)(t|p|d|)(s|)Que(ue|) { return TANTQUE;} 
f(in|aim)T(a|e)(n|m)(t|p|d|)(s|)Que(ue|) { return FINTANTQUE;} 
GoTo { return GOTO;} //mettre de la couleur sur goto
al(l|)e(z|)atoire { return RAND;} 


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