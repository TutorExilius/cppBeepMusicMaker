
#include <windows.h> // Beep(), Sleep()

#include "note.h"
using namespace BMM;

#include "spielEinheit.h"

Note::Note( const Notenname &note )
	: SpielEinheit{ note }
{
}

void Note::play( const float &laenge ) const
{
	if( laenge > 0.0f )
	{
		Beep( static_cast<DWORD>( this->beepFrequenz ), static_cast<DWORD>( this->basisLaenge * laenge ) );
	}
}