#include "Maior.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include <windows.h>

using namespace std;

void Maior::calcula_maior() {
  string numeroUmString;
  string numeroDoisString;
  string numeroTresString;

  cout << "Digite 3 numeros inteiros" << endl;
  cin >> numeroUmString;
  // autentica entrada do usuario, se digitar fora do escopo manda digitar tudo
  // de novo
  if (!autentica_entrada(numeroUmString)) {
    calcula_maior();
  }
  // função para passar uma string de numero com retorn de um inteiro
  numeroUm = string_para_numero(numeroUmString);

  // recebe segundo numero
  cin >> numeroDoisString;

  if (!autentica_entrada(numeroDoisString)) {
    calcula_maior();
  }
  numeroDois = string_para_numero(numeroDoisString);

  cin >> numeroTresString;
  if (!autentica_entrada(numeroTresString)) {
    calcula_maior();
  }
  numeroTres = string_para_numero(numeroTresString);
  // fim autentica e conversão de string para int

  // fazer comparação do maior numero, começa recebendo um qualquer para
  // parametro
  maior = numeroUm;

  if (numeroDois > maior) {
    maior = numeroDois;
  } else if (numeroTres > maior) {
    maior = numeroTres;
  }
  if (numeroTres > numeroDois && numeroTres > numeroUm) {
    maior = numeroTres;
  }
  // fim comparação

  system("cls || clear");
  cout << "\nNumeros digitados= num 1:|" << numeroUm << "| num 2:|"
       << numeroDois << "| num 3:|" << numeroTres << "|" << endl;

  cout << "Numero maior e =|" << maior << "| " << endl;
}

bool Maior::autentica_entrada(string &numeroString) {
  negativo = 0; // toda chamada da função inicia com 0

  // se primeiro caracter for '-' ele seta negativo como positivo
  if (numeroString[0] == '-') {
    negativo = 1;
  }

  for (int i = 0; i < numeroString.length(); i++) {

    // se o numero for negativo ele coloca o indice(i) para começar da segunda
    // posição(i=1)
    if (negativo == 1) {
      i = 1;
      negativo = -1; // muda para não entrar nesse if mais de uma vez
    }

    // verificando se é numero, subtrai -48 pq na tabela asc um numero em char
    // -48 é o proprio numero em inteiro
    if ((numeroString[i] - 48 > 9 || numeroString[i] - 48 < 0)) {

      system("cls||clear");

      cout << "\nDigito |" << numeroString
           << "| e invalido, digite novamente\n";

      Sleep(2000);
      system("cls||clear");

      return false;
    }
  }
  return true;
}
long double Maior::string_para_numero(string &numeroString) {
  long double inteiro = 0;
  int expoente = 0;
  int tamanhoVet;

  // verifica se o numero for negativo, se for o tamanho do inteiro será menor,
  // para compensar o caracter '-' da string
  if (negativo == -1) {
    tamanhoVet = numeroString.length() - 1;
  } else {
    tamanhoVet = numeroString.length();
  }

  int *vetor = new int(tamanhoVet);

  // vetor que recebe uma string e converte cada char para um inteiro em um
  // vetor
  for (int i = 0, j = 0; j < tamanhoVet; i++, j++) {

    // se for negativo ele faz começar o indice da segunda posição do
    // numeroString
    if (negativo == -1) {
      i = 1;
      negativo = 1; // muda para não entrar nesse if mais de uma vez
    }
    vetor[j] = numeroString[i] - 48;
  }

  // laço que recebe um vetor de int e concatena em uma só variável
  for (int i = tamanhoVet - 1; i >= 0; i--) {
    inteiro += vetor[i] * pow(10, expoente);
    expoente++;
  }

  if (negativo == 1) {
    inteiro = inteiro * -1;
    negativo = 0;
  }

  delete vetor; // liberando espaço da memoria do vetor criado
  vetor = NULL; // liberando espaço da memoria do vetor criado

  return inteiro; // retorna a variavel concatenada
}

int main() {
  Maior maior;
  maior.calcula_maior();
  system("pause");
}