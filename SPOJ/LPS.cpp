//Manacher’s Algorithm
//LPS - Longest Palindromic Substring
//https://www.spoj.com/problems/LPS/
#include <bits/stdc++.h>

using namespace std;

int manacher (string x) {
  if (x.empty()) return 0;
  //Se string x possui apenas um caractere a única substring possível é a própria string
  if (x.length() == 1) return 1;
  //Vetor para armazenar o tamanho das substrings palindrômicas centradas em diferentes caracteres
  vector<int> LPS(2 * x.length() + 1);
  //Primeira posição possui tamanho zero por ser um caractere especial que não consegue expandir por estar no começo da string
  LPS[0] = 0;
  //Segunda posição não consegue expandir para esquerda por ser o primeiro caractere real da string, logo só é centro de si mesmo
  LPS[1] = 1;
  //Posição do centro, posição do centro da maior substring cujo domínio extende ao índice atual
  int cenPos = 1;
  //Posição direita do centro, limite direito do domínio da posição do centro
  int cenRig = 2;
  //Posição direita atual, índice que está sendo analisado no momento
  int curRig = 0;
  //Posição esquerda atual, posição espelhada da posição direita atual, em relação à posição do centro
  int curLef;
  //Tamanho da maior substring palindrômica no momento
  int maxLPSLength = 0;
  //Posição do centro da maior substrinf palindrômica no momento
  int maxLPSCenPos = 0;
  //Armazena a diferença entre os domínios das posições atuais e do centro
  int diff = -1;
  for (int i = 2; i <= 2 * x.length(); i++) {
    curRig = i;
    curLef = 2 * cenPos - curRig;
    LPS[curRig] = 0;
    diff = cenRig - curRig;
    if (LPS[curLef] < diff) {
      //Caso 1
      LPS[curRig] = LPS[curLef];
    } else if (LPS[curLef] == diff) {
      if (cenRig == 2 * x.length()) {
        //Caso 2
        LPS[curRig] = LPS[curLef];
      } else {
        //Caso 3
        LPS[curRig] = LPS[curLef];
        while (true) {
          //Caso passe da extremidade direita da string
          if (curRig + LPS[curRig] > 2 * x.length()) break;
          //Caso passe da extremidade esquerda da string
          if (curRig - LPS[curRig] < 1) break;
          //Se a próxima posição ter valor ímpar (representa caractere real, não especial) e
          //seu respectivo caractere é diferente do caractere espelhado, não formando palíndromo
          if ((curRig + LPS[curRig] + 1) % 2 && x[(curRig + LPS[curRig] + 1) / 2] != x[(curRig - LPS[curRig] - 1) / 2]) break;
          //Aumenta o tamanho da substring palindrômica centrada na posição direita atual
          LPS[curRig]++;
        }
      }
    } else {
      //Caso 4
      LPS[curRig] = diff;
      while (true) {
        //Caso passe da extremidade direita da string
        if (curRig + LPS[curRig] > 2 * x.length()) break;
        //Caso passe da extremidade esquerda da string
        if (curRig - LPS[curRig] < 1) break;
        //Se a próxima posição ter valor ímpar (representa caractere real, não especial) e
        //seu respectivo caractere é diferente do caractere espelhado, não formando palíndromo
        if ((curRig + LPS[curRig] + 1) % 2 == 1 && x[(curRig + LPS[curRig] + 1) / 2] != x[(curRig - LPS[curRig] - 1) / 2]) break;
        //Aumenta o tamanho da substring palindrômica centrada na posição direita atual
        LPS[curRig]++;
      }
    }
    //Se a nova substring for a nova maior substring
    if (LPS[curRig] > maxLPSLength) {
      maxLPSLength = LPS[curRig];
      maxLPSCenPos = curRig;
    }
    //Se o domínio da posição atual for maior que o da posição do centro
    if (curRig + LPS[curRig] > cenRig) {
      cenPos = curRig;
      cenRig = curRig + LPS[curRig];
    }
  }
  //Retorna o tamanho da maior substring palindrômica
  return maxLPSLength;
}

int main () {
  //Número de caracteres da string
  int n;
  //String a ser lida
  string st;
  cin >> n;
  cin >> st;
  cout << manacher(st) << endl;
  return 0;
}