#include "option.h"

Option::Option( const std::string &optionName )
: optionName{ optionName }
{

}

void Option::addArgument( const std::string &argument )
{
	this->argumente.push_back( argument );
}

size_t Option::getArgSize() const
{
	return this->argumente.size();
}

std::string Option::getOptionName() const
{
	return this->optionName;
}

std::string Option::getArgument( size_t index ) const
{
	if( index < this->argumente.size() )
	{
		return this->argumente.at( index );
	}
	else
	{
		// throw ?!

		return "";
	}
}

const std::vector<std::string>& Option::getArguments() const
{
	return this->argumente;
}