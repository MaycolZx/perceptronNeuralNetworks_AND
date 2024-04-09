#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int main() {
  // tenemos el AND
  //  x1 x2  AND
  //  0  0   0
  //  0  1   0
  //  1  0   0
  //  1  1   1
  float u;
  // Tenemos tres entradas
  vector<int> valoresx0 = {1, 1, 1, 1};
  vector<int> valoresX1 = {0, 0, 1, 1};
  vector<int> valoresX2 = {0, 1, 0, 1};
  // Deberia de haber 3 pesos para tres entradas
  vector<float> peso = {0, 0, 0};
  // El valor que deseamos recibir de las 3 entradas
  vector<float> valorD = {0, 0, 0, 1};

  int y = 0;
  float n = 0.5;

  // Epocas
  int epocas = 0;
  int contador = 0;
  while (true) {
    cout << "Epoca-" << ++epocas << endl;
    contador = 0;
    for (int i = 0; i < valoresx0.size(); i++) {
      u = (peso[0] * valoresx0[i]) + (peso[1] * valoresX1[i]) +
          (peso[2] * valoresX2[i]);
      cout << "Entrada(" << i << ") el valor en funcion de f(" << u << ") "
           << endl;
      if (u > 0) {
        y = 1;
      } else if (u <= 0) {
        y = 0;
      }

      cout << "If: " << y << " == " << valorD[i] << endl;
      if (y == valorD[i]) {
        contador++;
        continue;
      }
      contador = 0;
      // n*xi(di-yi) si d != y;
      cout << "w0 = " << peso[0] << " +(" << n << " * (" << valorD[i] - y
           << ") * " << valoresx0[i] << ") " << endl;
      peso[0] = peso[0] + (n * (valorD[i] - y) * valoresx0[i]);

      cout << "w0 = " << peso[1] << " +(" << n << " * (" << valorD[i] - y
           << ") * " << valoresx0[i] << ") " << endl;
      peso[1] = peso[1] + (n * (valorD[i] - y) * valoresX1[i]);

      cout << "w0 = " << peso[2] << " +(" << n << " * (" << valorD[i] - y
           << ") * " << valoresx0[i] << ") " << endl;
      peso[2] = peso[2] + (n * (valorD[i] - y) * valoresX2[i]);

      for (int i = 0; i < peso.size(); i++) {
        cout << "El peso de W" << i << ": " << peso[i] << endl;
      }
      cout << endl;
    }
    if (contador == 4) {
      break;
    }

    // nAciertos++;
  }

  return 0;
}
