//#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include <os/lib.h>	// Miri
#include <os/xmalloc.h> // Miri
//#include <os/ctype.h> // Miri

//#define atoi simple_atoi // Miri

void main_FFT()
{}


extern void fft_double(unsigned  NumSamples, int InverseTransform, double *RealIn, double *ImagIn, double *RealOut, double *ImagOut);
/*
static int simple_atoi(char **s)
{
    int i=0;

    while (isdigit(**s))
        i = i*10 + *((*s)++) - '0';
    return i;
}
*/
//jjw
//int main_FFT(int argc, char *argv[]) {
int main_FFT_fu() {
	unsigned MAXSIZE;
	unsigned MAXWAVES;
	unsigned i,j;
	double *RealIn;
	double *ImagIn;
	double *RealOut;
	double *ImagOut;
	double *coeff;
	double *amp;

///jjw
	int invfft=0;

		MAXWAVES = 8;
		MAXSIZE=32768;
//jjw
/*
	if (argc<3)
	{
		printf("Usage: fft <waves> <length> -i\n");
		printf("-i performs an inverse fft\n");
		printf("make <waves> random sinusoids");
		printf("<length> is the number of samples\n");
		//exit(-1);
	}
	else if (argc==4)
		invfft = !strncmp(argv[3],"-i",2);
	MAXSIZE=atoi((char **)argv[2]);
	MAXWAVES=atoi((char **)argv[1]);
	*/	
 //srand(1); // Miri

 RealIn=(double*)malloc(sizeof(double)*MAXSIZE);
 ImagIn=(double*)malloc(sizeof(double)*MAXSIZE);
 RealOut=(double*)malloc(sizeof(double)*MAXSIZE);
 ImagOut=(double*)malloc(sizeof(double)*MAXSIZE);
 coeff=(double*)malloc(sizeof(double)*MAXWAVES);
 amp=(double*)malloc(sizeof(double)*MAXWAVES);

 /* Makes MAXWAVES waves of random amplitude and period */
	for(i=0;i<MAXWAVES;i++) 
	{
		coeff[i] = 1; // Miri //rand()%1000;
		amp[i] = 1; // Miri rand()%1000;
	}
 for(i=0;i<MAXSIZE;i++) 
 {
   /*   RealIn[i]=rand();*/
	 RealIn[i]=0;
	 for(j=0;j<MAXWAVES;j++) 
	 {
		 /* randomly select sin or cos */
		 if (1) //rand()%2) //Miri
		 {
		 		RealIn[i]+=coeff[j]*cos(amp[j]*i);
			}
		 else
		 {
		 	RealIn[i]+=coeff[j]*sin(amp[j]*i);
		 }
  	 ImagIn[i]=0;
	 }
 }

 /* regular*/
 fft_double(MAXSIZE,invfft,RealIn,ImagIn,RealOut,ImagOut);
 
 printf("RealOut:\n");
 for (i=0;i<MAXSIZE;i++)
   printf("%f \t", RealOut[i]);
 printf("\n");

printf("ImagOut:\n");
 for (i=0;i<MAXSIZE;i++)
   printf("%f \t", ImagOut[i]);
   printf("\n");

 free(RealIn);
 free(ImagIn);
 free(RealOut);
 free(ImagOut);
 free(coeff);
 free(amp);
 //exit(0);

 return 0;

}
