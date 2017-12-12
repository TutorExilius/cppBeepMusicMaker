#ifndef PAUSE_H
#define PAUSE_H

#include <string>

#include "spielEinheit.h"

namespace BMM
{
	class Pause : public SpielEinheit
	{
	public:
		Pause();
		virtual void play( const float &laenge ) const override;

	private:
	};
}

#endif // PAUSE_H