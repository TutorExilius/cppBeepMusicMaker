#include "musikBox.h"
using namespace BMM;

#include <fstream>
#include <iostream>

MusikBox::MusikBox( const std::string &liederListe, const std::string &liederOrdner )
	: musikAbbruch{ false }
	, musikBoxAktiv{ true }
	, sinlgeMode{ false }
	, geradeAmAbpielen{ nullptr }
{
	std::ifstream inLieder( "lieder.txt", std::ios::in );

	if( !inLieder )
	{
		exit( -1 );
	}

	std::string zeile;
	while( std::getline( inLieder, zeile ) )
	{
		if( zeile.size() > 0 )
		{
			this->lieder.push_back( Lied{ liederOrdner + "\\" + zeile + ".txt" } );
		}
	}
}

MusikBox::MusikBox( const std::string &lied )
	: musikAbbruch{ false }
	, musikBoxAktiv{ true }
	, sinlgeMode{ true }
	, geradeAmAbpielen{ nullptr }
{
	this->lieder.push_back( Lied{ lied } );
}

void MusikBox::start()
{
	if( this->sinlgeMode )
	{
		this->lieder.at( 0 ).play();
	}
	else
	{
		int menuePunkt = 0;

		do
		{
			this->menue();

		} while( this->musikBoxAktiv );

		system( "CLS" );
		std::cout << "Porgramm beendet." << std::endl;
	}
}

void MusikBox::menueAusgabe() const
{
	system( "CLS" );

	std::cout << "Lieder:\n" << std::endl;

	for( int i = 0; i < lieder.size(); i++ )
	{
		std::cout << i + 1 << ". " << lieder.at( i ).getTitel() << std::endl;
	}

	std::cout << "\n0. Beenden" << std::endl;

	std::cout << std::endl;
}

void MusikBox::menue()
{
	this->menueAusgabe();
	this->menueFuehrung();
}

void MusikBox::menueFuehrung()
{
	int menueWahl = 0;

	std::cout << "Liednummer abspielen: ";
	std::cin >> menueWahl;

	if( menueWahl == 0 )
	{
		this->musikBoxAktiv = false;
	}
	else
	{
		this->liedAbspielen( menueWahl );
	}
}

void MusikBox::liedAbspielen( const int liedNummer ) const
{
	if( liedNummer - 1 < this->lieder.size() )
	{
		this->geradeAmAbpielen = const_cast<Lied*>( &( this->lieder.at( liedNummer - 1 ) ) );
		this->lieder.at( liedNummer - 1 ).play();
	}
}