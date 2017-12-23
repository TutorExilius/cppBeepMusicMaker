#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

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
		ArgumentParser();

	private:
		ArgumentParser( const ArgumentParser &obj ) = delete;
		ArgumentParser& operator=( const ArgumentParser &obj ) = delete;
	};
}

#endif // ARGUMENTPARSER_H