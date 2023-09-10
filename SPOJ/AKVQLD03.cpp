// How to Handle the Fans
// https://www.spoj.com/problems/AKVQLD03/en/
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

// Retorna a posição do bit significativo mais à direita, indexada em 1
int LSB(int x)
{
  return log2(x & (-1 * x)) + 1;
}

// Recebe um vetor de 1 a n e constrói a Fenwick Tree a partir do vetor
void constructFenwickTree(vector<ll> &tree)
{
  // Tamanho da árvore de Fenwick
  int n = tree.size();
  // Posição diretamente responsável
  int j;
  for (int i = 1; i < n; i++)
  {
    // j recebe a posição diretamente responsável por i
    j = pow(2, LSB(i) - 1) + i;
    // Se j não estiver fora do escopo, atualiza com o valor da posição i, do qual é responsável
    if (j < n)
      tree[j] += tree[i];
  }
}

// Recebe um intervalo [i, j] e retorna o valor correspondente a tal intervalo na árvore
ll queryFenwickTree(vector<ll> &tree, int l, int r)
{
  // Tamanho da árvore de Fenwick
  int n = tree.size();
  // Somas referentes às bordas do intervalo
  ll suml = 0, sumr = 0;
  // Posições relativas aos intervalos
  int i = l - 1, j = r;
  // suml recebe o valor do intervalo [1, l]
  while (i)
  {
    // Acrescenta-se o valor na posição i a suml
    suml += tree[i];
    // i segue para a posição que é responsabilidade direta de i
    i -= pow(2, LSB(i) - 1);
  }
  // sumr recebe o valor do intervalo [1, r]
  while (j)
  {
    // Acrescenta-se o valor na posição j a sumr
    sumr += tree[j];
    // j segue para a posição que é responsabilidade direta de j
    j -= pow(2, LSB(j) - 1);
  }
  // Retorna a diferença [1, r] - [1, l[ que equivale a [l, r]
  return sumr - suml;
}

// Atualiza o valor de uma posição pos para um valor val, atualizando a árvore
void updateFenwickTree(vector<ll> &tree, int pos, int val)
{
  // Tamanho da árvore
  int n = tree.size();
  // Posições a serem atualizadas
  int i = pos;
  // Atualiza as posições necessárias da árvore
  while (i < n)
  {
    // Atualiza o valor da árvore
    tree[i] += val;
    // Prossegue para a posição responsável por i
    i += pow(2, LSB(i) - 1);
  }
}

int main()
{
  int n, q;
  cin >> n >> q;
  vector<ll> a(n + 1, 0);
  while (q--)
  {
    string s;
    int x, y;
    cin >> s >> x >> y;
    if (s == "find")
    {
      cout << queryFenwickTree(a, x, y) << endl;
    }
    else if (s == "add")
    {
      updateFenwickTree(a, x, y);
    }
  }

  return 0;
}
