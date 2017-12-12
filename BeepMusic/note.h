#ifndef NOTE_H
#define NOTE_H

#include <string>

#include "spielEinheit.h"

namespace BMM
{
	class Note : public SpielEinheit
	{
	public:
		explicit Note( const Notenname &note );

		virtual void play( const float &laenge ) const override;
	};
}

#endif // NOTE_H