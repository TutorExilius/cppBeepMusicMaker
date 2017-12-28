#include "argumentParser.h"
using namespace BMM;

#include <string>

ArgumentParser::ArgumentParser( const int argc, char **argv,
								std::vector<Option> &optionen,
								std::vector<std::string> &argumente )
{
	// Definition unserer Optionen und Anzahl der zu erwartenden Aegumente
	// File
	this->optionenArgumente["-f"] = 1;
	this->optionenArgumente["--file"] = 1;
	this->optionenArgumente["-r"] = 1;
	this->optionenArgumente["--repeat"] = 1;
	this->optionenArgumente["-l"] = 0; 
	this->optionenArgumente["--loop"] = 0;

	// Playlist
	this->optionenArgumente["-p"] = 1;
	this->optionenArgumente["--playlist"] = 1;
	this->optionenArgumente["-d"] = 1;
	this->optionenArgumente["--dir"] = 1;

	if( argc > 1 )
	{
		Option *lastOption = nullptr;
		size_t optionArgCounter = 0;

		bool missingMinimumOptions = true;

		for( int i = 1; i < argc; i++ )
		{
			std::string argument = argv[i];

			// ist es eine Option? (beginn mit '-')
			if( argument[0] == '-' )
			{
				if( argument == "-f" || argument == "--file" ||
					argument == "-p" || argument == "--playlist" )
				{
					missingMinimumOptions = false;
				}

				Option option{ argument };

				optionen.push_back( option );

				lastOption = &optionen.at( optionen.size() - 1 );
			}
			else
			{
				if( lastOption == nullptr )
				{
					argumente.push_back( argument );
				}
				else
				{
					if( lastOption->getArgSize() <
						this->optionenArgumente[lastOption->getOptionName()] )
					{
						lastOption->addArgument( argument );
					}
					else
					{
						argumente.push_back( argument );
					}
				}
			}
		}

		if( missingMinimumOptions )
		{
			/*
			Option playlist{ "-p" };
			playlist.addArgument( "lieder.txt" );

			Option dir{ "-d" };
			dir.addArgument( "lieder" );

			optionen.push_back( playlist );
			optionen.push_back( dir );
			*/

			this->defaultInitialisation( optionen, argumente );

		}
	}
	else
	{
		this->defaultInitialisation( optionen, argumente );
	}
}

void ArgumentParser::defaultInitialisation( std::vector<Option> &optionen,
									   std::vector<std::string> &argumente )
{
	Option playlist{ "-p" };
	playlist.addArgument( "lieder.txt" );

	Option dir{ "-d" };
	dir.addArgument( "lieder" );

	optionen.push_back( playlist );
	optionen.push_back( dir );
}