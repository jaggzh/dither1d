/* Manual DITHER1D/Value interpolation
 * Copyright 2021 jaggz.h {reachable at} gmail.com
 * License: GPL v3.0
 */
#ifndef _DITHER1D16_H
#define _DITHER1D16_H
#include <stdio.h>
#include <stdint.h>

// Debugging: Comment out for no debug printf()
//            Or set to 0, 1, or 2
#define DITHER1D_DEBUG 1 // comment out for no debug printf()

#ifndef DITHER1D_DEBUG // safe to leave alone, just sets default=off
	#define DITHER1D_DEBUG 0
#endif

class dither1d_16 {
	private:
		uint16_t  _imax, _omax;
		int16_t   _err=0;
	public:
		         dither1d_16(uint16_t imax, uint16_t omax);
		uint16_t get(uint16_t target);
		// Reset io ranges
		void     init(uint16_t imax, uint16_t omax);
};

#endif // _DITHER1D16_H
