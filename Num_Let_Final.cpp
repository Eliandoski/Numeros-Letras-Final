//Estudiante: Cifuentes González Elian
//Fecha de entrega: 24/07/2024
//Curso: 1ro de TI

//Programa que transforma un número entero en su equivalente en letras |FINAL|

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const string unidades[] = {"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis",
"Siete", "Ocho", "Nueve", "Diez", "Once", "Doce", "Trece", "Catorce", "Quince",
"Dieciséis", "Diecisiete", "Dieciocho", "Diecinueve"};

const string decenas[] = {"", "Diez", "Veinte", "Treinta", "Cuarenta", "Cincuenta",
"Sesenta", "Setenta", "Ochenta", "Noventa"};

const string centenas[] = {"", "Ciento", "Doscientos", "Trescientos", "Cuatrocientos", "Quinientos",
"Seiscientos", "Setecientos", "Ochocientos", "Novecientos"};

//Devuelve las unidades del array de string
string GetUnidades(int num) 
{
  return unidades[num];
}

//Devuelve las decenas del array de string
string GetDecenas(int num) 
{
  int x = num / 10;
  int resto = num % 10;
  string aux = "";

  if (num < 20) {
    aux = GetUnidades(num);
  } else {
    aux = decenas[x];
    aux = resto > 0 ? aux + " y " + GetUnidades(resto) : aux + "";
  }

  return aux;
}

//Devuelve las centenas del array string
string GetCentenas(int num) 
{
  int x = num / 100;
  int resto = num % 100;
  string aux = "";

  if (num < 100) {
    aux = GetDecenas(num);
  } else {
    aux = centenas[x];
    aux = resto > 0 ? aux + " " + GetDecenas(resto) : aux;
  }
  return aux;
}

//Devuelve en letras los números de mil en adelante
string GetMiles(int num) 
{
  int miles = num / 1000;
  int resto = num % 1000;
  string aux = "";

  if (num < 1000) {
    aux = GetCentenas(num);
  } else {
    if (miles == 1) {
      aux = "Mil";
    } else {
      aux = GetCentenas(miles) + " Mil";
    }
    if (resto > 0) {
      if (resto < 100) {
        aux = aux + " " + GetDecenas(resto);
      } else {
        aux = aux + " " + GetCentenas(resto);
      }
    }
  }

  return aux;
}

//Función que convierte un número entero en letras por partes (millones, miles, etc)
string Convertir(int num) 
{
  string partes[4] = {"", "Mil", "Millón", "Mil Millones"};
  string resultado = "";
  int parte = 0;

  while (num > 0) {
    int res = num % 1000;
    num /= 1000;
    string strParte = GetCentenas(res);

    if (parte == 2) {
      if (res == 1) {
        resultado = partes[parte] + " " + resultado;
      } else {
        resultado = strParte + " millones " + resultado;
      }
    } else if (parte == 1 && res == 1) {
      resultado = partes[parte] + " " + resultado;
    } else if (strParte != "") {
      resultado = strParte + " " + partes[parte] + " " + resultado;
    }
    parte++;
  }

  return resultado;
}

//Función que genera números aleatorios y los convierte en letras
void GenerarNumerosAleatorios() {
  srand(time(0));

  for (int i = 0; i < 100; ++i) {
    int num = rand() % 999999999 + 1;
    cout << num << " en letras es: " << Convertir(num) << endl;
  }
}

int main() 
{

  //Genera números aleatorios en letras 
  cout << "Números Aleatorios en Letras (100 Números): " << endl;
  GenerarNumerosAleatorios();

  return 0;
}
