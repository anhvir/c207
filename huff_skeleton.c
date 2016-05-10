/* immplement Alistair's algorithm to C
   Source: Alistair's COMP20007 guest lecture slides 
	 Anh Vo, May 2016

	 Note:
	 This program take inut data of the form
	 {<symbol> <frequency>}+

	 where symbol= single-character
	       frequency= int number
	 maximal: 256 symbols

*/

#include <stdio.h>
#include <stdlib.h>

#define N 256
typedef struct {
	char s;
	int f;
} freq_t;



void huff_len(int a[], int n);
int get_freq ( freq_t sf[], int a[]); 
void print_huff ( freq_t sf[], int a[], int n);


int main () {
  int n;
	freq_t t[N];
	int a[N];
	n= get_freq(t, a);
  huff_len(a, n);
  print_huff(t, a, n);
	return 0;
}



int fcmp(const void *aa, const void *bb) {
  freq_t *a= (freq_t *) aa;
  freq_t *b= (freq_t *) bb;
	return a->f < b->f? -1 : (a->f==b->f? 0 : 1);
}


/* reads pair (symbol, freq) into sf[], 
     supposing data in format: symbol freq 
	 sorts sf[] in increasing order of freq
	 copy sf[].f to a[]
	 return n= number of elems in table
*/

int get_freq ( freq_t sf[], int a[]) {
  int n, i;
  for (n=0; scanf("%c %d\n", &sf[n].s, &sf[n].f)== 2; n++);
	qsort(sf, n, sizeof(sf[0]), &fcmp);
  for (i=0; i<n; i++) a[i]= sf[i].f;
	return n;
}

void print_huff ( freq_t sf[], int a[], int n) {
  int i;
	for (i=0; i<n; i++) 
	  printf("%c %3d %d\n", sf[i].s, sf[i].f, a[i]);
}

/* input: a[] is frequencies, sorted in increasing order 
   output: a[i] is len of i-th codeword
	 this function was translated from Alistair's pseudocode
*/
void huff_len(int a[], int n) {
  int next, avail, used, depth;
	// Phase 1
	int leaf= 0, root= 0;

	// Phase 2

	// Phase 3
}
	


