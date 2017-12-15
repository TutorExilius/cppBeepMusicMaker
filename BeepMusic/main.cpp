#include <iostream>
#include <string>

#include "musikBox.h"
using namespace BMM;

#include "myFunctions.h"

int main( int argc, char **argv )
{
	if( argc > 1 )
	{
		const std::string liedPfad{ argv[1] };

		MusikBox musikBox{ liedPfad };
		musikBox.start();
	}
	else
	{
		const std::string liederListe = "lieder.txt";
		const std::string liederOrdner = "lieder";

		MusikBox musikBox{ liederListe, liederOrdner };
		musikBox.start();

		pausiereKonsole();
	}
	
	return 0;
}