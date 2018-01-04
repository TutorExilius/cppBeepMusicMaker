#include "musikBox.h"
using namespace BMM;

#include <fstream>
#include <iostream>

#include <string.h>

#include <cstdio>

#include "option.h"

MusikBox::MusikBox( const std::vector<Option> &optionen,
					const std::vector<std::string> &argumente )
	: musikAbbruch{ false }
	, musikBoxAktiv{ true }
	, playSingleSong{ false }
	, geradeAmAbpielen{ nullptr }
	, optionen{ optionen }
	, argumente{ argumente }
{
	std::string playlist;
	std::string liederOrdner;
	std::string file;

	// TODO: Bereinige optionen-vector: schmeiße alle Optionen raus, die wir nicht kennen/unterstützen

	for( const auto &option : optionen )
	{
		if( option.getOptionName() == "-p" ||
			option.getOptionName() == "--playlist" )
		{
			playlist = option.getArgument( 0 );
		}
		else if( option.getOptionName() == "-d" ||
				 option.getOptionName() == "--dir" )
		{
			liederOrdner = option.getArgument( 0 );
			this->liederOrdner = liederOrdner;
		}
		else if( option.getOptionName() == "-f" ||
				 option.getOptionName() == "--file" )
		{
			file = option.getArgument( 0 );
			this->singleFile = file;

			playSingleSong = true;

			// Single Sond erstmal NICHt i die Plaaylist aufnehmen,
			// sondern einfach abspielen und dann weiter mit Plylist
			// this->lieder.push_back( file );
		}
	}

	/*
	if( playlist == "" || liederOrdner == "" )
	{
		std::cerr << "Failed reading Option-Arguments in MusikBox(..)";
		return;
	}
	*/
	if( liederOrdner == "" )
	{
		liederOrdner = "lieder";
	}

	if( playlist != "" )
	{
		playSingleSong = false; // Doch nicht Singlemodus!

		std::ifstream inLieder( playlist, std::ios::in );

		if( !inLieder )
		{
			std::cerr << "Failed open " + playlist << std::endl;
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
}

void MusikBox::start()
{
	if( this->playSingleSong )
	{
		Lied singleSong{ this->singleFile };
		size_t repeat = 0;

		try // get --repeat arg
		{
			if( this->getArguments( "-r" ).size() > 0 )
			{
				repeat = std::stoi( this->getArguments( "-r" ).at( 0 ) );
			}
			else if( this->getArguments( "--repeat" ).size() > 0 )
			{
				repeat = std::stoi( this->getArguments( "--repeat" ).at( 0 ) );
			}
		}
		catch( ... )
		{
			std::cerr << "Exception in [get --repeat arg]" << std::endl;
		}

		if( repeat == 0 )
		{
			repeat = 1;
		}

		// play once + repeat
		for( size_t i = 0; i < repeat; i++ )
		{
			singleSong.play();
		}
	}
	else
	{
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

std::vector<std::string> MusikBox::getArguments( const std::string &optionName ) const
{
	for( const auto &option : this->optionen )
	{
		if( option.getOptionName() == optionName )
		{
			return option.getArguments();
		}
	}
	std::vector<std::string> empty;
	return empty;
}
