/*****  *****/


/*** インクルードファイル ***/

/* C */
#include <math.h>

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/***  ***/
void mk_pix2xy( int *pix2x, int *pix2y ){

	/* =======================================================================
	* subroutine mk_pix2xy
	* =======================================================================
	* constructs the array giving x and y in the face from pixel number
	* for the nested (quad-cube like) ordering of pixels
	*
	* the bits corresponding to x and y are interleaved in the pixel number
	* one breaks up the pixel number by even and odd bits
	* =======================================================================
	*/

	/* 変数の宣言と初期化 */
	int i, kpix, jpix, IX, IY, IP, ID;
	for( i = 0; i < 1023; i++ ) pix2x[ i ] = 0;
	
	for( kpix = 0; kpix < 1024; kpix++ ){
		jpix = kpix;
		IX = 0;
		IY = 0;
		IP = 1;	// ! bit position (in x and y)
		while( jpix != 0 ){	// ! go through all the bits
			ID = (int)fmod( (double)jpix, 2 );	// ! bit value (in kpix), goes in ix
			jpix = jpix / 2;
			IX = ID * IP + IX;
			
			ID = (int)fmod( (double)jpix, 2 );	// ! bit value (in kpix), goes in iy
			jpix = jpix / 2;
			IY = ID * IP + IY;
			
			IP = 2 * IP;	// ! next bit (in x and y)
		}
		
		pix2x[ kpix ] = IX;	// ! in 0,31
		pix2y[ kpix ] = IY;	// ! in 0,31
	}
	
	/* Later */
	return;
}
