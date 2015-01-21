/***** 回転空間 SO(3) における均等なサンプリングの結果出力 *****/


/*** インクルードファイル ***/

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** 回転空間 SO(3) における均等なサンプリングの結果出力 ***/
bool hopf2quat( vector< vector< double > > Points ){
	

	/* 変数の宣言と初期化 */
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;	// 四元数
	ofstream output1;						// ファイル出力用変数：四元数(.csv)
	ofstream output2;						// ファイル出力用変数：四元数(.txt)
	ofstream output3;						// ファイル出力用変数：°(.csv)
	ofstream output4;						// ファイル出力用変数：°(.txt)
	ofstream output5;						// ファイル出力用変数：ラジアン(.csv)
	ofstream output6;						// ファイル出力用変数：ラジアン(.txt)

	/* ファイルの展開 */
	output1.open( middleFileName1 );	
	output2.open( middleFileName2 );
	output3.open( middleFileName3 );
	output4.open( middleFileName4 );
	output5.open( middleFileName5 );
	output6.open( middleFileName6 );
	
	/* 点群数分だけループ */
	for( int i = 0; i < Points.size(); i++ ){

		/* ホップ座標を構成する四元数 */
		// θ ( 球面座標 S2, 単位：ラジアン ) … Points[ i ][ 0 ]
		// Φ ( 球面座標 S2, 単位：ラジアン ) … Points[ i ][ 1 ]
		// Ψ ( 回転平面 S1, 単位：ラジアン ) … Points[ i ][ 2 ]
		x4 = sin( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );
		x1 = cos( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 2 ] / 2 );
		x2 = cos( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 2 ] / 2 );
		x3 = sin( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );

		/* 実行結果のファイルへの出力 */
		output1 << x1 << "," << x2 << "," << x3 << "," << x4 << endl;
		output2 << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
		output3 << Points[ i ][ 0 ] * 180 / M_PI << "," << Points[ i ][ 1 ] * 180 / M_PI << "," << Points[ i ][ 2 ] * 180 / M_PI << endl;
		output4 << Points[ i ][ 0 ] * 180 / M_PI << "\t" << Points[ i ][ 1 ] * 180 / M_PI << "\t" << Points[ i ][ 2 ] * 180 / M_PI << endl;
		output5 << Points[ i ][ 0 ] << "," << Points[ i ][ 1 ] << "," << Points[ i ][ 2 ] << endl;
		output6 << Points[ i ][ 0 ] << "\t" << Points[ i ][ 1 ] << "\t" << Points[ i ][ 2 ] << endl;
	}
	
	/* メモリの解放 */
	output1.close();
	output2.close();
	output3.close();
	output4.close();
	output5.close();
	output6.close();
	
	/* 返り値 */
	return true;
}
