#include "lied.h"

#include <algorithm>
#include <cctype>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "spielEinheit.h"
#include "note.h"
#include "pause.h"

#include "myFunctions.h"

using namespace BMM;

Lied::Lied( const std::string &filename )
	: liedAbbrechen{ false }
{
	std::ifstream file{ filename };

	if( !file.good() )
	{
		std::cerr << filename << " konnte nciht geoeffnet werden!" << std::endl;
		exit( -1 );
	}

	std::stringstream ss;
	std::string tmpStr;

	std::string noteStr;
	std::string tastennummerStr;
	std::string notenlaengeStr;

	std::string musikTitel;
	std::string bmpStr;
	// std::string takt; erstmal nicht nötig

	std::getline( file, tmpStr, ':' );
	std::getline( file, musikTitel );
	trim( musikTitel );

	this->titel = musikTitel;

	std::getline( file, tmpStr, ':' );
	std::getline( file, bmpStr );
	trim( bmpStr );

	/* Takt ist erstmal nicht nötig!
	std::getline( file, tmpStr, ':' );
	std::getline( file, takt );
	trim(takt);
	**/

	char tmp = ' ';

	while( file >> noteStr )
	{
		if( noteStr.size() > 0 )
		{
			ss << noteStr;
			std::getline( ss, tastennummerStr, ':' );
			ss >> notenlaengeStr;
			ss.clear();

			SpielEinheit *spieleinheit = nullptr;
			std::transform( tastennummerStr.begin(), tastennummerStr.end(),
							tastennummerStr.begin(),
							[]( unsigned char c ) -> unsigned char{ return static_cast<unsigned char>( std::tolower( c ) ); } );

			if( tastennummerStr != "pause" )
			{
				int tastennummer = -9;

				ss << tastennummerStr;
				ss >> tastennummer;
				ss.clear();

				Notenname note = SpielEinheit::getNotenname( tastennummer );

				spieleinheit = new Note{ note };
			}
			else
			{
				spieleinheit = new Pause;
			}

			ss << notenlaengeStr;

			float zaehler = 0.0f;
			int nenner = 0;

			ss >> zaehler >> tmp >> nenner;
			ss.clear();

			if( nenner == 0 )
			{
				nenner = 1;
			}

			ss << bmpStr;
			int bmp = 0;

			ss >> bmp;
			ss.clear();

			const float einVietelNotenLaenge = ( 60.0f / bmp );
			const float notenlaenge = einVietelNotenLaenge * ( ( zaehler / nenner ) / 0.25f );

			this->noten.push_back( std::make_pair( spieleinheit, notenlaenge ) );

			ss.clear();
		}
	}
}

const std::string& Lied::getTitel() const
{
	return this->titel;
}

void Lied::play() const
{
	for( const auto &spielEinheit : this->noten )
	{
		if( _kbhit() )
		{
			this->liedAbbrechen = true;
			break;
		}

		if( this->liedAbbrechen )
		{
			this->liedAbbrechen = false;
			break;
		}

		spielEinheit.first->play( spielEinheit.second );
	}
}

void Lied::abbrechen() const
{
	this->liedAbbrechen = true;
}