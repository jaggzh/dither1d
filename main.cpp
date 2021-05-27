#include <stdio.h>
#include <stdint.h>
#include "dither1d.h"

#if DITHER1D_DEBUG < 1 // Locally output if debug output is disabled
	#define DB_PRINTINT(v) printf("%d\n", v)
#else
	#define DB_PRINTINT(v)
#endif

int main(int ac, char *av[]) {
	uint16_t val;

	#if DITHER1D_DEBUG < 1 // Locally output if debug output is disabled
		printf("Set DITHER1D_DEBUG>0 for more output...\n");
	#endif

	// Input range 0,10000. Output 0-255
	// 25%
	dither1d_16 dither(10000, 255);
	printf("[ Testing 25% ]\n");
	for (int i=0; i<15; i++) {
		val = dither.get(2500);   // 25% of 10000
		DB_PRINTINT(val);
	}

	// Literal .25   [0 ..  .25 .. 255]
	dither.init(10000, 255);
	printf("[ Testing literal .25 ]\n");
	for (int i=0; i<15; i++) {
		val = dither.get((.25 * 10000) / 255);
		DB_PRINTINT(val);
	}

	// 50%
	dither.init(10000, 255);
	printf("[ Testing 50% ]\n");
	for (int i=0; i<15; i++) {
		val = dither.get(5000);
		DB_PRINTINT(val);
	}

	return 0;
}
