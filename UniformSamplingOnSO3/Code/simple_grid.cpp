/***** 1：単一解像度(Simple Grid)指定の場合 *****/


/*** インクルードファイル ***/

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** 1(Simple Grid)選択時：指定した解像度レベルにおける点を作成・出力 ***/
bool simple_grid( int resol ){


	/* 変数の宣言と初期化 */
	vector< double > Psi_Points, temp;			// S1
	vector< vector< double > > Healpix_Points;	// S2
	vector< vector< double > > S3_Points;		// S3
	long int Nside = 0, numpixels = 0;			// 2の解像度レベル乗, 2次元球面 S2 における点座標数
	double theta = 0, pfi = 0;					// θ, Φ
	bool result;								// 実行結果の判定 … 1：成功, 0：失敗
	
	/* メモリの確保 */
	Psi_Points.resize( 0 );
	

	/*** 回転平面 S1 のサンプリング ***/

	/* 回転平面 S1 における点座標 Ψ を格納した配列の取得 */
	Psi_Points = grid_s1( resol );	// 回転平面 S1 の等間隔サンプリング

	/* 回転平面 S1 における点座標 Ψ を格納した配列が空のとき */
	if( Psi_Points.size() == 0 ) return false;	// 失敗値 0 を返す
	

	/*** 2次元球面 S2 のサンプリング ***/

	/* 2の解像度レベル乗 */
	Nside = pow( 2, (double)resol );	// 解像度レベル 0：1, 解像度レベル 1：2, 解像度レベル 2：4, 解像度レベル 3：8, …

	/* 2次元球面 S2 における点座標数の取得 */
	numpixels = nside2npix( Nside );	// 解像度レベル 0：12, 解像度レベル 1：48, 解像度レベル 2：192, 解像度レベル 3：768, …
	
	/* メモリの確保 */
	Healpix_Points.resize( 0 );
	
	/* 2次元球面 S2 における点座標( θ, Φ )を格納した配列の取得 */
	for( long int i = 0; i < numpixels; i++ ){
		
		/* メモリの確保 */
		temp.resize( 0 );
		
		/* 回転角 θ, Φ の取得 */
		pix2ang_nest( Nside, i, &theta, &pfi );

		/* 点座標( θ, Φ )の作成 */
		temp.push_back( theta );
		temp.push_back( pfi );

		/* 2次元球面 S2 上の点座標( θ, Φ )を格納した配列 */
		Healpix_Points.push_back( temp );
	}
	
	/* メモリの確保 */
	S3_Points.resize( 0 );
	

	/*** 回転空間 SO(3) における均等なサンプリングの作成 ***/
	for( int i = 0; i < Healpix_Points.size(); i++ ){
		for( int j = 0; j < Psi_Points.size(); j++ ){
			
			/* メモリの確保 */
			temp.resize( 0 );
			
			/* 点座標( θ, Φ, Ψ )の作成 */
			temp.push_back( Healpix_Points[ i ][ 0 ] );
			temp.push_back( Healpix_Points[ i ][ 1 ] );
			temp.push_back( Psi_Points[ j ] );

			/* 3次元球面 S3 上の点座標( θ, Φ, Ψ )を格納した配列 */
			S3_Points.push_back( temp );
		}
	}
	

	/*** サンプリング結果となる四元数群の出力 ***/
	result = hopf2quat( S3_Points );


	/* 返り値 */
	return result;
}

