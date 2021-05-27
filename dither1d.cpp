/* Manual DITHER1D/Value interpolation
 * Copyright 2021 jaggz.h {reachable at} gmail.com
 * License: GPL v3.0
 */
#include "dither1d.h"

dither1d_16::dither1d_16(uint16_t imax, uint16_t omax) {
	_imax = imax;
	_omax = omax;
	_err = 0;
}

void dither1d_16::init(uint16_t imax, uint16_t omax) {
	dither1d_16(imax, omax);
}

uint16_t dither1d_16::get(uint16_t target) {
	int16_t err;
	uint16_t val, rev;
	target += _err;
	val = (target * _omax) / _imax;
	#if DITHER1D_DEBUG > 0
		printf("Target(%3d) * omax(%d) / imax(%d) => val(%3d)\n",
			target, _omax, _imax, val);
	#endif
	rev = ((val * _imax) / _omax);
	err = target - rev;
	#if DITHER1D_DEBUG > 1
		printf("  Reversed: %d  -> Err: %d\n", rev, err);
	#endif
	_err = err;
	return val;
}
