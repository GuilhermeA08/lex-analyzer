#include "parser.h"
#include "tokens.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using std::left;
using std::setw;
using std::cout;
using std::string;
using std::unordered_map;
using std::pair;

int ordinator = 1;
int tokenCounter = 0;
unordered_map<string, pair<int, string>> symbolTable;

unordered_map<int, string> tokensName {
    {SOME, "SOME"},
    {ALL, "ALL"}, 
    {VALUE, "VALUE"}, 
    {MIN, "MIN"},
    {MAX, "MAX"},
    {EXACTLY, "EXACTLY"},
    {THAT, "THAT"},
    {ONLY, "ONLY"},
    {NOT, "NOT"},
    {AND, "AND"},
    {OR, "OR"},
    {CLASS, "CLASS"},
    {PROPERTY, "PROPERTY"},
    {CARDINAL, "CARDINAL"},
    {PARENTHESIS, "PARENTHESIS"}
};

void Parser::Start()
{
    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        // verifica se o token já foi inserido na tabela de símbolos
        if (symbolTable.find(scanner.YYText()) == symbolTable.end()) {
            symbolTable[scanner.YYText()] = {++tokenCounter, tokensName[lookahead]};
        }

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
            case ONLY: cout << "ONLY\n"; break;
            case NOT: cout << "NOT\n"; break;
            case AND: cout << "AND\n"; break;
            case OR: cout << "OR\n"; break;
            case PARENTHESIS: cout << "PARENTHESIS\n"; break;
            case CARDINAL: cout << "CARDINAL: " << scanner.YYText() << "\n"; break;
            case PROPERTY: cout << "PROPERTY: " << scanner.YYText() << "\n"; break;
            case CLASS: cout << "CLASS: " << scanner.YYText() << "\n"; break;
        }
    }

    cout << "\nTabela de Símbolos\n";
    cout << left << setw(6) << "Id" << setw(20) << "Nome do Token" << "\t" << "Tipo\n";
    while (ordinator < symbolTable.size()) {
        for (auto [key, value] : symbolTable) {
            if(value.first == ordinator) {
                cout << left << setw(6) << value.first << setw(20) << key << "\t" << value.second << "\n";
                ordinator++;
            }
        }
    }
}
