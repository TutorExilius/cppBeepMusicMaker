#include "myFunctions.h"

#include <cctype>
#include <iostream>

std::string &trim( std::string &str )
{
	size_t pos = str.find_first_not_of( " \t\r\n\v\f" );

	if( pos != std::string::npos )
	{
		str.erase( 0, pos );
	}

	pos = str.find_last_not_of( " \t\r\n\v\f" );

	if( pos != std::string::npos )
	{
		str.erase( pos + 1 );
	}

	return str;
}

void pausiereKonsole()
{
	std::cin.clear();
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	std::cin.get(); // wait
}