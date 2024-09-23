#include <iostream>
#include "Pilha.h"
using namespace std;

// Função para verificar se o símbolo é um parêntese de abertura ou fechamento correspondente
bool SimbolosCorrespondentes(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']');
}

// Função para validar a expressão matemática
bool ValidarExpressao(string expressao) {
    Pilha_Construtor();  // Inicia a pilha
    TipoDado topoElemento;

    // Percorre cada caractere da expressão
    for (char simbolo : expressao) {
        if (simbolo == '(' || simbolo == '[') {
            // Empilha símbolos de abertura
            Pilha_Empilhar(simbolo);
        } else if (simbolo == ')' || simbolo == ']') {
            // Verifica se a pilha está vazia antes de tentar desempilhar
            if (Pilha_Vazia() || !Pilha_Topo(topoElemento) || !SimbolosCorrespondentes(topoElemento, simbolo)) {
                Pilha_Destrutor();
                return false; // Parênteses ou colchetes incorretos
            }
            Pilha_Desempilhar(topoElemento); // Remove o símbolo correspondente da pilha
        }
    }

    // Após a leitura da expressão, a pilha deve estar vazia para ser válida
    bool expressaoValida = Pilha_Vazia();
    Pilha_Destrutor();
    return expressaoValida;
}

int main() {
    string expressao;
    cout << "Digite uma expressao matematica: ";
    cin >> expressao;

    if (ValidarExpressao(expressao)) {
        cout << "OK" << endl;
    } else {
        cout << "Errado" << endl;
    }

    return 0;
}
