/***** 回転空間 SO(3) における均等なサンプリングの結果出力 *****/


/*** インクルードファイル ***/

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** 回転空間 SO(3) における均等なサンプリングの結果出力 ***/
bool hopf2quat(
	vector< vector< double > > Points,	// S3
	int level							// 解像度レベル
){
	
	/* 変数の宣言と初期化 */
	int n = 0;													// インデックス
	int square = pow( 2, (double)level );						// 2の解像度レベル乗
	int n2;														// 通し番号の2倍
	int s66 = 0;												// 6 * 6 * square * count
	int count = 0;												// カウンタ
	int ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8;					// 次の解像度における対応 ID
	int dirID;													// ディレクトリ番号
	double element0, element1, element2, element3;				// 四元数の各要素
	double element0S, element1S, element2S, element3S;			// 四元数の各要素の2乗
	double R11, R12, R13, R21, R22, R23, R31, R32, R33;			// 回転行列の各要素
	char dirPath[ 256 ], FileName1[ 128 ], FileName2[ 512 ];	// ファイル名
	const char *slash = "/";									// スラッシュ
	ofstream output1;											// ファイル出力用変数：四元数(.csv)
	ofstream output2;											// ファイル出力用変数：°(.csv)
	ofstream output3;											// ファイル出力用変数：ラジアン(.csv)

	/* ファイルの展開 */
	sprintf( dirPath, DirectoryPath2, level ); sprintf( FileName1, OutputFileName1 );			// ディレクトリパスとファイル名の指定
	strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// ディレクトリパス + ファイル名
	output1.open( FileName2 );																	// 四元数出力用ファイルの展開
	sprintf( dirPath, DirectoryPath2, level ); sprintf( FileName1, OutputFileName2 );			// ディレクトリパスとファイル名の指定
	strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// ディレクトリパス + ファイル名
	output2.open( FileName2 );																	// Degree 出力用ファイルの展開
	sprintf( dirPath, DirectoryPath2, level ); sprintf( FileName1, OutputFileName3 );			// ディレクトリパスとファイル名の指定
	strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// ディレクトリパス + ファイル名
	output3.open( FileName2 );																	// Radian 出力用ファイルの展開
	
	/* 点群数分だけループ */
	for( int i = 0; i < Points.size(); i++ ){

		printf( ">> Process: %d\r", i );

		/* 通し番号の2倍 */
		n2 = 2 * n;

		/* 次の解像度における対応 ID の算出 */
		ID1 = n2 + s66 + 0; ID2 = n2 + s66 + 1;
		ID3 = n2 + s66 + 12 * square; ID4 = n2 + s66 + 12 * square + 1;
		ID5 = n2 + s66 + 24 * square; ID6 = n2 + s66 + 24 * square + 1;
		ID7 = n2 + s66 + 36 * square; ID8 = n2 + s66 + 36 * square + 1;

		/* ホップ座標を構成する四元数 */
		// θ ( 球面座標 S2, 単位：ラジアン ) … Points[ i ][ 0 ]
		// Φ ( 球面座標 S2, 単位：ラジアン ) … Points[ i ][ 1 ]
		// Ψ ( 回転平面 S1, 単位：ラジアン ) … Points[ i ][ 2 ]
		element3 = sin( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );
		element0 = cos( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 2 ] / 2 );
		element1 = cos( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 2 ] / 2 );
		element2 = sin( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );

		/* 実行結果のファイルへの出力 */
		output1 << element0 << "," << element1 << "," << element2 << "," << element3 << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;
		output2 << Points[ i ][ 0 ] * 180 / M_PI << "," << Points[ i ][ 1 ] * 180 / M_PI << "," << Points[ i ][ 2 ] * 180 / M_PI << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;
		output3 << Points[ i ][ 0 ] << "," << Points[ i ][ 1 ] << "," << Points[ i ][ 2 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* ディレクトリ番号の指定 */
		dirID = i / 10000;

		/* 回転行列の復元 */
		element0S = pow( element0, 2 );								// 四元数の1つ目の要素の2乗
		element1S = pow( element1, 2 );								// 四元数の2つ目の要素の2乗
		element2S = pow( element2, 2 );								// 四元数の3つ目の要素の2乗
		element3S = pow( element3, 2 );								// 四元数の4つ目の要素の2乗
		R11 = element0S + element1S - element2S - element3S;		// 1行1列目の要素
		R12 = 2 * ( element1 * element2 - element0 * element3 );	// 1行2列目の要素
		R13 = 2 * ( element1 * element3 + element0 * element2 );	// 1行3列目の要素
		R21 = 2 * ( element1 * element2 + element0 * element3 );	// 2行1列目の要素
		R22 = element0S - element1S + element2S - element3S;		// 2行2列目の要素
		R23 = 2 * ( element2 * element3 - element0 * element1 );	// 2行3列目の要素
		R31 = 2 * ( element1 * element3 - element0 * element2 );	// 3行1列目の要素
		R32 = 2 * ( element2 * element3 + element0 * element1 );	// 3行2列目の要素
		R33 = element0S - element1S - element2S + element3S;		// 3行3列目の要素

		/* 回転行列の出力 */
		ofstream output4;																			// ファイル出力用変数：回転行列
		sprintf( dirPath, DirectoryPath6, level, dirID ); sprintf( FileName1, OutputFileName4, n );	// ディレクトリパスとファイル名の指定
		strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// ディレクトリパス + ファイル名
		output4.open( FileName2 );																	// ファイルの展開
		output4 << R11 << "," << R12 << "," << R13 << endl
				<< R21 << "," << R22 << "," << R23 << endl
				<< R31 << "," << R32 << "," << R33 << endl;											// ファイル内容の書き込み
		output4.close();																			// メモリの解放

		/* 次の解像度における対応 ID の出力 */
		ofstream output5;																			// ファイル出力用変数：次の解像度における対応 ID
		sprintf( dirPath, DirectoryPath5, level, dirID ); sprintf( FileName1, OutputFileName5, n );	// ディレクトリパスとファイル名の指定
		strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// ディレクトリパス + ファイル名
		output5.open( FileName2 );																	// ファイルの展開
		output5 << ID1 << "," << ID2 << "," << ID3 << "," << ID4 << "," <<
					ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;							// ファイル内容の書き込み
		output5.close();																			// メモリの解放

		/* カウンタの更新 */
		n++;
		if( n % ( 6 * square ) == 0 ){
			count++;
			s66 = 6 * 6 * square * count;
		}
	}
	
	/* メモリの解放 */
	output1.close();
	output2.close();
	output3.close();

	/* 返り値 */
	return true;
}
