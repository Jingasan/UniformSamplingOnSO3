/***** 回転平面 S1 の等間隔サンプリング *****/


/*** インクルードファイル ***/

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** 回転平面 S1 の等間隔サンプリング ***/
vector< double > grid_s1( int resol ){
	

	/* 変数の宣言と初期化 */
	int grids = 6;				// 回転平面(S1)におけるグリッド数
	vector< double > Points;	// 回転平面(S1)の回転角Ψの配列
	
	/* メモリの確保 */
	Points.resize( 0 );

	/* 点数の算出 */
	int number_points = pow( 2, (double)resol ) * grids;	// 2 の解像度レベル乗 × グリッド数( 6 )
	// 解像度レベル 0 のとき … 6 点
	// 解像度レベル 1 のとき … 12 点
	// 解像度レベル 2 のとき … 24 点
	// 解像度レベル 3 のとき … 48 点

	/* 点間の幅( ラジアン単位 ) */
	float interval = 2 * M_PI / number_points;

	/* 回転平面 S1 の等間隔サンプリング */
	for( int i = 0; i < number_points; i++ ) Points.push_back( interval / 2 + i * interval );

	/* 返り値 */
	return Points;
}
