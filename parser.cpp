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
