#ifndef MUSIKBOX_H
#define MUSIKBOX_H

#include <string>
#include <vector>

#include "lied.h"

namespace BMM
{
	class MusikBox
	{
	public:
		MusikBox( const std::string &liederListe, const std::string &liederOrdner );
		MusikBox( const std::string &lied );
		void start();

	private:
		MusikBox() = delete;
		MusikBox( const MusikBox &obj ) = delete;

		void menueAusgabe() const;
		void menueFuehrung();
		void liedAbspielen( const int liedNummer ) const;
		void menue();

		bool musikAbbruch;
		bool musikBoxAktiv;
		bool sinlgeMode;
		const std::string liederOrdner;

		std::vector<Lied> lieder;
		mutable Lied *geradeAmAbpielen;
	};
}

#endif // MUSIKBOX_H