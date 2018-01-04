#include <iostream>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "musikBox.h"
#include "argumentParser.h"
using namespace BMM;

#include "myFunctions.h"

int main( int argc, char **argv )
{
	std::cin.get();

	vector<string> argumente;
	vector<Option> optionen;

	ArgumentParser argumentParser{ argc, argv, optionen, argumente };

	MusikBox musikBox{ optionen, argumente };
	musikBox.start();

	// pausiereKonsole();
	
	return 0;
}