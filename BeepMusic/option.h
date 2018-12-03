#ifndef OPTION_H
#define OPTION_H

#include <string>
#include <vector>

class Option
{
public:
	Option( const std::string &option );

	void addArgument( const std::string &argument );
	size_t getArgSize() const;
	std::string getOptionName() const;
	std::string getArgument( size_t index ) const;
	const std::vector<std::string>& getArguments() const;

private:
	const std::string optionName;
	std::vector<std::string> argumente;
};

#endif // OPTION_H