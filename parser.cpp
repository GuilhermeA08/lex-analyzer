#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;

void Parser::Start()
{
    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch(lookahead)
        {
            case SOME: cout << "SOME\n"; break;
            case ALL: cout << "ALL\n"; break;
            case VALUE: cout << "VALUE\n"; break;
            case MIN: cout << "MIN\n"; break;
            case MAX: cout << "MAX\n"; break;
            case EXACTLY: cout << "EXACTLY\n"; break;
            case THAT: cout << "THAT\n"; break;
            case NOT: cout << "THAT\n"; break;
            case AND: cout << "AND\n"; break;
            case OR: cout << "OR\n"; break;
            case PARENTHESIS: cout << "PARENTHESIS\n"; break;
            case CARDINAL: cout << "CARDINAL: " << scanner.YYText() << "\n";; break;
            case PROPERTY: cout << "PROPERTY: " << scanner.YYText() << "\n";; break;
            case CLASS: cout << "CLASS: " << scanner.YYText() << "\n"; break;
        }
    }
}
