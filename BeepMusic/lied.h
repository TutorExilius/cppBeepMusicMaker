#ifndef LIED_H
#define LIED_H

#include <string>
#include <vector>

#include "spielEinheit.h"

namespace BMM
{
	class Lied
	{
	public:
		Lied( const std::string &filename );

		const std::string& getTitel() const;

		void play() const;
		void abbrechen() const;

	private:
		std::string titel;
		std::vector<std::pair<SpielEinheit*, float>> noten;
		mutable bool liedAbbrechen;
	};
}

#endif // LIED_H