%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <vector>
  #include <string>
  #include <iostream>
  #include <typeinfo>
  #include <stack>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);

  class instruction{
  public:
    instruction (const int &c,const double &v=0, const string &n="",const string &s="") {code = c,stringValue = s, value = v; name = n;};  
    int code;
    string stringValue; 
    double value;    
    string name;       
  };

  map<string,double> variables;
  map<string,string> variablesString;

  int ic = 0;

  map<string,int> adresses;

  vector <instruction> code_genere;    

  int add_instruction(const int &c, const double &v=0, const string &n="",const string &s="") {
      code_genere.push_back(instruction(c,v,n,s)); 
      ic++;
      return 0; 
   }; 


%}

%code requires
  {
    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  }

%union {
  double valeur;
  char nom[50];
  char valeurString[50];
  type_adresse adresse;  
}

%token <valeur> NUM
%token <valeurString> STRING
%token <nom> VAR
%type <valeur> expr 
%token SIN
%token COS
%token <adresse> SI
%token ALORS
%token ADDSTRING
%token SINON
%token FINSI
%token SUP
%token INF
%token SUPEG
%token INFEG
%token NEG
%token EGA
%token PRINT
%token PRINTSTRING
%token RAND
%token ASSIGN
%token ASSIGNSTRING
%token GOTO
%token <nom> LABEL
%token JMP
%token JMPCOND
%token FUNCTION
%token <adresse> TANTQUE
%token FINTANTQUE

%right ADD SUB   
%left MULT DIV

%%
bloc:  /* Epsilon */
     | bloc label instruction '\n'   

label : // Epsilon
      | LABEL ':'  { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses[$1] = ic;}

instruction :   /* Epsilon, ligne vide */
            | expr         {  }
            | PRINT expr   { add_instruction(PRINT); }
            | PRINT STRING { add_instruction(PRINTSTRING);}
            | RAND expr {add_instruction(RAND);}
            | VAR '=' expr { add_instruction(ASSIGN, 0, $1); }
            | VAR '=' STRING { add_instruction(STRING,0,"",$3);add_instruction(ASSIGNSTRING,0,$1,$3);}
            | GOTO LABEL   { add_instruction(JMP, -999, $2); }
            | SI '(' condition ')' '\n' { $1.jc = ic;
                                          add_instruction(JMPCOND); } 
                bloc                    { $1.jmp = ic;
                                          add_instruction(JMP);
                                          code_genere[$1.jc].value = ic;
                                        }
              SINON '\n' 
                bloc                                  
              FINSI                     { code_genere[$1.jmp].value = ic;} 
            |TANTQUE '(' condition ')' '\n' {$1.jc =ic ;
                                          add_instruction(JMPCOND);  
                                          }
                bloc                          {$1.jmp = ic;
                                          add_instruction(JMP);
                                          code_genere[$1.jc].value = ic;
                                          }
              FINTANTQUE                      {
                                              
                                             
                                                
                                                code_genere[$1.jmp].value=$1.jc-3;
                                              
                                              
                                              
                                              cout<<"salut"<<endl;
                                              
                                              
                                              }
                         

expr: NUM               { add_instruction (NUM, $1);   }
     | VAR               { add_instruction (VAR, 0, $1);  }
     | STRING { add_instruction(STRING,0,"",$1);}
     | SIN '(' expr ')'  {  }
     | COS '(' expr ')'  {  }
     | '(' expr ')'      {  }
     | expr ADD expr     { $$=$1+$3;cout<< $$<<endl; add_instruction(ADD); }
     | expr SUB expr     { $$=$1-$3;cout<<$$<<endl; add_instruction(SUB);  }   		
     | expr MULT expr    { $$=$1*$3;cout<<$$<<endl; add_instruction(MULT);}		
     | expr DIV expr     { $$=$1/$3;cout<<$$<<endl; add_instruction(DIV); }   
     | expr INF expr     { if($1<3){$$=true; cout<<1;} else{$$=false;cout<<0; }add_instruction(INF);}
     | expr SUP expr      { if($1>3){$$=true; cout<<1;} else{$$=false;cout<<0; }add_instruction(SUP);}
     | expr SUPEG expr      { if($1>=$3){$$=true; cout<<1;} else{$$=false;cout<<0; }add_instruction(SUPEG); }
     | expr INFEG expr      { if($1<=$3){$$=true; cout<<1;} else{$$=false;cout<<0; }add_instruction(INFEG); }
     | expr NEG expr      { if($1!=$3){$$=true; cout<<1;} else{$$=false;cout<<0; }add_instruction(NEG); }
     | expr EGA expr      { if($1==$3){$$=true; cout<<1;} else{$$=false;cout<<0; }add_instruction(EGA); }


condition :  expr          {}
          
%%

int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

string print_code(int ins) {
  switch (ins) {
    case STRING : return "STR";
    case ADD      : return "ADD";
    case ADDSTRING      : return "ADDSTR";
    case SUB      : return "SUB";
    case MULT     : return "MUL";
    case DIV     : return "DIV";    
    case NUM      : return "NUM";
    case VAR      : return "VAR";
    case PRINT    : return "PRINT";
    case RAND : return "RAND";
    case ASSIGN   : return "ASSIGN";
    case ASSIGNSTRING   : return "ASSIGNSTR";
    case JMP      : return "JMP";
    case JMPCOND  : return "JC ";
    default : return "";
  }
}

void execution ( const vector <instruction> &code_genere, 
                 map<string,double> &variables )
{
printf("\n------- Exécution du programme ---------\n");
stack<int> pile;
stack<string> pileString;

int ic = 0;  // compteur instruction
double r1, r2;  // des registres
string s1, s2;


  while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
      auto ins = code_genere[ic];
      switch (ins.code){
        case ADD:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r1+r2);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;

          break;
          case ADDSTRING:
            s1 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();

            s2 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();

            pileString.push(s1+s2);
            cout<< "Résultat du calcul: " << s1+s2<<endl;
            ic++;
          break;

        case SUB:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r2-r1);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;
          break;

        case MULT:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r1*r2);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;
          break;

        case DIV:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r2/r1);
            cout<< "Résultat du calcul: " << r1+r2<<endl;
            ic++;
          break;

        case SUP:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2>r1){pile.push(true);}
            else{pile.push(false); cout<<1<<endl;}
            ic++;
          break;

        case SUPEG:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2>=r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;

        case INF:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2<r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;

        case INFEG:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2<=r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;
          
        case EGA:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2==r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);cout<<0<<endl;}
            ic++;
          break;

        case NEG:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            if(r2!=r1){pile.push(true); cout<<1<<endl;}
            else{pile.push(false);}
            ic++;
          break;

        case ASSIGN:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();
            variables[ins.name] = r1;
            ic++;
          break;

        case ASSIGNSTRING:
            s1 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();
            variablesString[ins.name] = s1;
            ic++;
          break;

        case PRINT:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();
            cout << "" << r1 << endl; 
            ic++;
        break;

        case PRINTSTRING:
            s1 = pileString.top();    // Rrécupérer la tête de pile;
            pileString.pop();
            cout << s1 << endl; 
            ic++;
        break;

        case RAND:
          srand(time(NULL));
          r1 = pile.top();
          pile.pop();
          r1 = rand() % (int)r1;  
          cout << "Retour de la fonction aléatoire: " << r1 << endl;
          ic++;
        break;


        case NUM:   // pour un nombre, on empile
            pile.push(ins.value);
            ic++;
        break;

        case STRING:
            pileString.push(ins.stringValue);
            cout << ins.stringValue << endl;
            ic++;
        break;

        case JMP:
            if (ins.value != -999) // Est-ce un GoTo ?
              ic = ins.value;
            else
              // je récupère l'adresse à partir de la table
              ic = adresses[ins.name];
          break;

        case JMPCOND: 
             r1 = pile.top();    // Rrécupérer la tête de pile;
             pile.pop();
             if ( r1 != 0 ) 
                ic++;
             else 
                ic = (int)ins.value;             
          break;

        case VAR:    // je consulte la table de symbole et j'empile la valeur de la variable
             // Si elle existe bien sur... 
            
            try {
                pile.push(variables.at(ins.name));
                ic++;
            }
          catch(...) {
                variables[ins.name] = 0;
                pile.push(variables.at(ins.name));
                ic++;
            }
          break;
      }
  }
}


int main(int argc, char **argv) {

  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;


  


  yyparse();				

  for (int i = 0; i < code_genere.size(); i++){
    auto instruction = code_genere [i];
    cout << "instruction n°"<< i 
         << '\t'
         << "code: " << print_code(instruction.code) 
         << '\t'
         << " valeur: " << instruction.value 
         << '\t' 
         << " nom: " << instruction.name 
         << '\t'
         << " valeurStr: " << instruction.stringValue
         << endl;
  }

  execution(code_genere, variables);
  
  return 0;
}