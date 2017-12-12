#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "lied.h"

using namespace BMM;

void printMenue( const std::vector<Lied> &lieder )
{
	std::cout << "Lieder:" << std::endl;

	for( int i = 0; i < lieder.size(); i++ )
	{
		std::cout << i + 1 << ". " << lieder.at( i ).getTitel() << std::endl;
	}

	int liedNummer = 0;

	std::cout << std::endl << "Liednummer: ";
	std::cin >> liedNummer;

	if( liedNummer - 1 < lieder.size() )
	{
		lieder.at( liedNummer - 1 ).play();
	}
}

int main( int argc, char **argv )
{
	std::ifstream inLieder( "lieder.txt", std::ios::in );

	if( !inLieder )
	{
		exit( -1 );
	}

	std::string liederOrdner = "lieder";
	std::vector<Lied> lieder;

	std::string zeile;
	while( std::getline( inLieder, zeile ) )
	{
		if( zeile.size() > 0 )
		{
			lieder.push_back( Lied( liederOrdner + "\\" + zeile + ".txt" ) );
		}
	}

	printMenue( lieder );

	std::cin.get(); // wait 

	return 0;
}