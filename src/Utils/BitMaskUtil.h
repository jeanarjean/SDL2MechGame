#pragma once

namespace BitMaskUtil
{
	bool IsBitActive(int bits, int bitPosition);

	inline bool IsBitActive(int bits, int bitPosition)
	{
		return(((bits) >> (bitPosition)) & 1);
	}

	bool IsBitInactive(int bits, int bitPosition);

	inline bool IsBitInactive(int bits, int bitPosition)
	{
		return(((bits) >> (bitPosition)) & 0);
	}
}
