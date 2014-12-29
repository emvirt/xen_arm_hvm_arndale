/* testc - Test adpcm coder */

#include "adpcm.h"
#include <stdio.h>

struct adpcm_state state;

#define NSAMPLES 1000

char	abuf[NSAMPLES/2];
short	sbuf[NSAMPLES];

int main_rawcaudio() {
    int n;

    while(1) {
	//n = read(0, sbuf, NSAMPLES*2); /Miri
	if ( n < 0 ) {
	    //perror("input file"); // Miri
	    //exit(1); // Miri
	}
	if ( n == 0 ) break;
	adpcm_coder(sbuf, abuf, n/2, &state);
	//write(1, abuf, n/4); // Miri
    }
/*    fprintf(stderr, "Final valprev=%d, index=%d\n",
	    state.valprev, state.index);
    exit(0);
*/
	return 0; // Miri
}
