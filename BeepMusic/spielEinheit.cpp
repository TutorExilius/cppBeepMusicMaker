#include "spielEinheit.h"
using namespace BMM;

#include <cmath>

SpielEinheit::SpielEinheit( const Notenname &note )
	: note( note )
	, frequenz{ frequenzBerechnen() }
	, beepFrequenz{ static_cast<size_t>( std::round( this->frequenz ) ) }
{
}

const float SpielEinheit::frequenzBerechnen() const
{
	const int tastennummer = static_cast<int>( this->note );
	const float frequenzBerechnet = static_cast<float>(std::pow( static_cast<float>(std::pow( 2, 1.0f / 12.0f )), tastennummer - 49 )) * 440.0f;

	return frequenzBerechnet;
}

Notenname SpielEinheit::getNotenname( const int tastennummer )
{
	switch( tastennummer )
	{
		case -8: return Notenname::C0;
		case -7: return Notenname::Db0;
		case -6: return Notenname::D0;
		case -5: return Notenname::Eb0;
		case -4: return Notenname::E0;
		case -3: return Notenname::F0;
		case -2: return Notenname::Gb0;
		case -1: return Notenname::G0;
		case 0: return Notenname::Ab0;
		case 1: return Notenname::A0;
		case 2: return Notenname::Bb0;
		case 3: return Notenname::B0;
		case 4: return Notenname::C1;
		case 5: return Notenname::Db1;
		case 6: return Notenname::D1;
		case 7: return Notenname::Eb1;
		case 8: return Notenname::E1;
		case 9: return Notenname::F1;
		case 10: return Notenname::Gb1;
		case 11: return Notenname::G1;
		case 12: return Notenname::Ab1;
		case 13: return Notenname::A1;
		case 14: return Notenname::Bb1;
		case 15: return Notenname::B1;
		case 16: return Notenname::C2;
		case 17: return Notenname::Db2;
		case 18: return Notenname::D2;
		case 19: return Notenname::Eb2;
		case 20: return Notenname::E2;
		case 21: return Notenname::F2;
		case 22: return Notenname::Gb2;
		case 23: return Notenname::G2;
		case 24: return Notenname::Ab2;
		case 25: return Notenname::A2;
		case 26: return Notenname::Bb2;
		case 27: return Notenname::B2;
		case 28: return Notenname::C3;
		case 29: return Notenname::Db3;
		case 30: return Notenname::D3;
		case 31: return Notenname::Eb3;
		case 32: return Notenname::E3;
		case 33: return Notenname::F3;
		case 34: return Notenname::Gb3;
		case 35: return Notenname::G3;
		case 36: return Notenname::Ab3;
		case 37: return Notenname::A3;
		case 38: return Notenname::Bb3;
		case 39: return Notenname::B3;
		case 40: return Notenname::C4;
		case 41: return Notenname::Db4;
		case 42: return Notenname::D4;
		case 43: return Notenname::Eb4;
		case 44: return Notenname::E4;
		case 45: return Notenname::F4;
		case 46: return Notenname::Gb4;
		case 47: return Notenname::G4;
		case 48: return Notenname::Ab4;
		case 49: return Notenname::A4;
		case 50: return Notenname::Bb4;
		case 51: return Notenname::B4;
		case 52: return Notenname::C5;
		case 53: return Notenname::Db5;
		case 54: return Notenname::D5;
		case 55: return Notenname::Eb5;
		case 56: return Notenname::E5;
		case 57: return Notenname::F5;
		case 58: return Notenname::Gb5;
		case 59: return Notenname::G5;
		case 60: return Notenname::Ab5;
		case 61: return Notenname::A5;
		case 62: return Notenname::Bb5;
		case 63: return Notenname::B5;
		case 64: return Notenname::C6;
		case 65: return Notenname::Db6;
		case 66: return Notenname::D6;
		case 67: return Notenname::Eb6;
		case 68: return Notenname::E6;
		case 69: return Notenname::F6;
		case 70: return Notenname::Gb6;
		case 71: return Notenname::G6;
		case 72: return Notenname::Ab6;
		case 73: return Notenname::A6;
		case 74: return Notenname::Bb6;
		case 75: return Notenname::B6;
		case 76: return Notenname::C7;
		case 77: return Notenname::Db7;
		case 78: return Notenname::D7;
		case 79: return Notenname::Eb7;
		case 80: return Notenname::E7;
		case 81: return Notenname::F7;
		case 82: return Notenname::Gb7;
		case 83: return Notenname::G7;
		case 84: return Notenname::Ab7;
		case 85: return Notenname::A7;
		case 86: return Notenname::Bb7;
		case 87: return Notenname::B7;
		case 88: return Notenname::C8;

		default: return Notenname::PAUSE;
	}
}