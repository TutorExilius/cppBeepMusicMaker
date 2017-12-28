#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include "option.h"

#include <map>
#include <string>


/***************

Mögliche Argumente:

--file		[file.txt]
-f

--repeat	[0..n]
-r

***************/

namespace BMM
{
	class ArgumentParser
	{
	public:
		ArgumentParser( const int argc, char **argv, 
						std::vector<Option> &optionen,
						std::vector<std::string> &argumente );

	private:
		std::map<std::string, size_t> optionenArgumente;
		void defaultInitialisation( std::vector<Option> &optionen,
									std::vector<std::string> &argumente );

		ArgumentParser( const ArgumentParser &obj ) = delete;
		ArgumentParser& operator=( const ArgumentParser &obj ) = delete;
	};
}

#endif // ARGUMENTPARSER_H