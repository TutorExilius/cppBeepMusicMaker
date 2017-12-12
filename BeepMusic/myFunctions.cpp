#include "myFunctions.h"

#include <cctype>

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

