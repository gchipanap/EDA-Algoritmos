#include <iostream>
#include "generate.hpp"

int main ()
{
	std::ofstream fichero;
  fichero.open("fichero.csv",std::ios::app);
	sort_algorithms(fichero);
	fichero.close();
	
	return 0;
}