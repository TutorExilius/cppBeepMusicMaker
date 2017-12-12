#include "pause.h"
using namespace BMM;

#include "spielEinheit.h"

#include <Windows.h>

Pause::Pause()
: SpielEinheit{ Notenname::PAUSE }
{
}

void Pause::play( const float &laenge ) const
{
	if( laenge > 0.0f )
	{
		Sleep( SpielEinheit::basisLaenge * laenge );
	}
}
