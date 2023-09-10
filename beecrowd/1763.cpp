// Tradutor do Papai Noel
// https://www.beecrowd.com.br/repository/UOJ_1763.html
#include <iostream>

using namespace std;

int main()
{
  string a[24] = {"brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos", "inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile", "mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria", "marrocos", "japao"};
  string b[24] = {"Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!", "Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!", "Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!", "Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!", "Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!"}, h;
  while (cin >> h)
  {
    for (int x = 0; x < 24; x++)
    {
      if (h == a[x])
      {
        cout << b[x] << endl;
        break;
      }
      else if (x == 23)
      {
        cout << "--- NOT FOUND ---" << endl;
      }
    }
  }

  return 0;
}
