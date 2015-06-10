#include <iostream>
#include "carModel.h"

using namespace std;

int main()
{
  CarModel a ("Opel", "Corsa", "Hatchback", 12345, 3, "Siva", 973, "benzin");

  a.print();

  return 0;
}
