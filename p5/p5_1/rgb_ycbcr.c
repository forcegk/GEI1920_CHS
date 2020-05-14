void RGB_YCbCr(	unsigned char *RGB, 
						unsigned char *Y, unsigned char *Cb, unsigned char *Cr)
{

	#define OP3x1_1(D1, S1, S2, S3) asm volatile ("mlanv %0, %1, %2, %3" : "=&r"(D1) : "r"(S1), "r"(S2), "r"(S3));

	/*
	*Y = (RGB[0] * 19595 + RGB[1] * 38470 + RGB[2] * 7471 + 32768) >> 16;
	*Cb = (RGB[0] * (-11059) + RGB[1] * (-21709) + RGB[2] * 32768 + 8388608 + 32767) >> 16;
	*Cr = (RGB[0] * 32768 - RGB[1] * 27439 - RGB[2] * 5329 + 8388608 + 32767) >> 16;
	*/

	unsigned int temp;
	
	// Y
	OP3x1_1(temp, RGB[2], 7471,  32768);
	OP3x1_1(temp, RGB[1], 38470, temp );
	OP3x1_1(temp, RGB[0], 19595, temp );
	*Y  = (unsigned char) (temp >> 16);

	// Cb
	OP3x1_1(temp, RGB[2],  32768, 32767);
	OP3x1_1(temp, RGB[1], -21709, temp );
	OP3x1_1(temp, RGB[0], -11059, temp );
	//temp += 8388608;
	//*Cb = (unsigned char) (temp >> 16);
	*Cb = (unsigned char) ((temp+8388608) >> 16);

	// Cr
	OP3x1_1(temp, RGB[2], -5329,  32767);
	OP3x1_1(temp, RGB[1], -27439, temp );
	OP3x1_1(temp, RGB[0],  32768, temp );
	//temp += 8388608;
	//*Cr = (unsigned char) (temp >> 16);
	*Cr = (unsigned char) ((temp+8388608) >> 16);

	// Podríamos sustituir
	//    temp += 8388608;
	// por
	//    OP3x1_1(temp, temp, 1, 8388608);
	// pero produce más retardo que una suma en local

}

/*
void RGB_YCbCr(	unsigned char *R, unsigned char *G, unsigned char *B, 
						unsigned char *Y, unsigned char *Cb, unsigned char *Cr)
{
	int k;

	for(k=0; k<256; ++k){
		Y[k] = (R[k] * 19595 + G[k] * 38470 + B[k] * 7471 + 32768) >> 16;
		Cb[k] = (R[k] * (-11059) + G[k] * (-21709) + B[k] * 32768 + 8388608 + 32767) >> 16;
		Cr[k] = (R[k] * 32768 - G[k] * 27439 - B[k] * 5329 + 8388608 + 32767) >> 16;
	}

}*/
