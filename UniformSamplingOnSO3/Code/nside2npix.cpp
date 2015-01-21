/***** 2次元球面 S2 における点座標数の算出 *****/


/*** インクルードファイル ***/

/* C */
#include<stdio.h>

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** 2次元球面 S2 における点座標数の算出 ***/
long nside2npix( const long nside ){
	
	return 12 * nside * nside;
}
