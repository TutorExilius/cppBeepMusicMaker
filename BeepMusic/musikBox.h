#ifndef MUSIKBOX_H
#define MUSIKBOX_H

#include <string>
#include <vector>

#include "argumentParser.h"
#include "lied.h"
#include "option.h"

namespace BMM
{
	class MusikBox
	{
	public:
		MusikBox( const std::vector<Option> &optionen,
				  const std::vector<std::string> &argumente );
		void start();

	private:
		MusikBox() = delete;
		MusikBox( const MusikBox &obj ) = delete;

		void menueAusgabe() const;
		void menueFuehrung();
		void liedAbspielen( const int liedNummer ) const;
		void menue();
		std::vector<std::string> getArguments( const std::string &optionName ) const;

		bool musikAbbruch;
		bool musikBoxAktiv;
		bool playSingleSong;
		std::string liederOrdner;
		std::string singleFile;

		std::vector<Lied> lieder;
		std::vector<Option> optionen;
		std::vector<std::string> argumente;

		mutable Lied *geradeAmAbpielen;
	};
}

#endif // MUSIKBOX_H