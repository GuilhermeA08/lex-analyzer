%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
#include "tokens.h"
using std::cout;
%}

%option noyywrap
delim	[ \t\n]
brancos {delim}+
letra	[A-Za-z]
digito	[0-9]   
num	    {digito}+(\.{digito}+)?(E[+-]?{digito}+)?
comp    <|>|<>|=
prts    \(|\)
pprt    has[A-Z]{letra}*|is[A-Z]{letra}*Of
card    {num}|integer\[{comp}+\"{num}\"\]
class   [A-Z]{letra}*

%%
{brancos}	; // nenhuma ação e nenhum retorno
SOME		return  SOME; 
ALL		    return ALL;
VALUE		return VALUE;
MIN		    return MIN;
MAX		    return MAX;
EXACTLY		return EXACTLY;
THAT		return THAT;
NOT		    return NOT;
AND		    return AND;
OR		    return OR;
{prts}      return PARENTHESIS;
{card}      return CARDINAL;
{pprt}      return PROPERTY;
{class}     return CLASS;
{num}	    return NUM;
.           cout << YYText() << " é um token inválido!\n"; 
%%

// nenhuma função auxiliar é necessária
