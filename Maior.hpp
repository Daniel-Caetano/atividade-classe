// Autor: Daniel Caetano de Souza Ferreira
// Data: 08/12/2021
// Atividade sobre Classe
#include <iostream>
#include <string>
using namespace std;

class Maior {

private:
  long double numeroUm;
  long double numeroDois;
  long double numeroTres;

  int negativo; // criado apenas para ajudar na autentificação de numero
                // negativo

  long double maior;

public:
  void calcula_maior();
  bool autentica_entrada(string &numeroString);
  long double string_para_numero(string &numeroString);
};