/***** 多重階層化 *****/


/*** インクルードファイル ***/

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** 次の解像度において対応する点の ID を格納 ***/
bool connectLayeredGrids(
	int resolution	// 解像度レベル	
){


	/* 変数の宣言 */
	FILE *inputFile1;						// ファイル型変数：四元数(.csv)
	FILE *inputFile2;						// ファイル型変数：°(.csv)
	FILE *inputFile3;						// ファイル型変数：ラジアン(.csv)
	vector< vector< float > > quaternions;	// 四元数を格納する配列
	vector< vector< float > > degrees;		// 角度(Degree)を格納する配列
	vector< vector< float > > radians;		// 角度(Radian)を格納する配列
	vector< float > quaternion;				// 四元数
	vector< float > degree;					// 角度(Degree)
	vector< float > radian;					// 角度(Radian)
	char FileName[ 128 ];					// ファイル名
	
	/* メモリの確保 */
	quaternions.resize( 0 );	// 四元数を格納する配列
	quaternion.resize( 4 );		// 四元数
	degrees.resize( 0 );		// 角度(Degree)を格納する配列
	degree.resize( 3 );			// 角度(Degree)
	radians.resize( 0 );		// 角度(Radian)を格納する配列
	radian.resize( 3 );			// 角度(Radian)

	/* ファイルの展開とエラー処理 */
	if( ( inputFile1 = fopen( middleFileName1, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << middleFileName1 << endl; return false; }
	if( ( inputFile2 = fopen( middleFileName3, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << middleFileName3 << endl; return false; }
	if( ( inputFile3 = fopen( middleFileName5, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << middleFileName5 << endl; return false; }
	
	/* ファイル内容の読み込み */
	while( fscanf( inputFile1, "%f,%f,%f,%f", &quaternion[ 0 ], &quaternion[ 1 ], &quaternion[ 2 ], &quaternion[ 3 ] ) != EOF ) quaternions.push_back( quaternion );
	while( fscanf( inputFile2, "%f,%f,%f", &degree[ 0 ], &degree[ 1 ], &degree[ 2 ] ) != EOF ) degrees.push_back( degree );
	while( fscanf( inputFile3, "%f,%f,%f", &radian[ 0 ], &radian[ 1 ], &radian[ 2 ] ) != EOF ) radians.push_back( radian );

	/* メモリの解放 */
	fclose( inputFile1 );
	fclose( inputFile2 );
	fclose( inputFile3 );

	/* 変数の宣言と初期化 */
	ofstream output1;	// ファイル出力用変数：四元数(.csv)
	ofstream output2;	// ファイル出力用変数：四元数(.txt)
	ofstream output3;	// ファイル出力用変数：角度(Degree)(.csv)
	ofstream output4;	// ファイル出力用変数：角度(Degree)(.txt)
	ofstream output5;	// ファイル出力用変数：角度(Radian)(.csv)
	ofstream output6;	// ファイル出力用変数：角度(Radian)(.txt)

	/* ファイルの展開 */
	sprintf( FileName, outputFileName1, resolution );
	output1.open( FileName );
	sprintf( FileName, outputFileName2, resolution );
	output2.open( FileName );
	sprintf( FileName, outputFileName3, resolution );
	output3.open( FileName );
	sprintf( FileName, outputFileName4, resolution );
	output4.open( FileName );
	sprintf( FileName, outputFileName5, resolution );
	output5.open( FileName );
	sprintf( FileName, outputFileName6, resolution );
	output6.open( FileName );

	/* 初期化 */
	int n = 0;									// インデックス
	int size = quaternions.size();				// 四元数、角度( Degree & Radian )の数
	int square = pow( 2, (double)resolution );	// 2の解像度レベル乗
	int n2;										// 通し番号の2倍
	int s66 = 0;
	int count = 0;
	int ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8;	// 出力 ID 値


	/* 次の解像度において対応する点の ID を格納 */
	while( n < size ){
	
		/* 通し番号の2倍 */
		n2 = 2 * n;

		ID1 = n2 + s66 + 0;
		ID2 = n2 + s66 + 1;
		ID3 = n2 + s66 + 12 * square;
		ID4 = n2 + s66 + 12 * square + 1;
		ID5 = n2 + s66 + 24 * square;
		ID6 = n2 + s66 + 24 * square + 1;
		ID7 = n2 + s66 + 36 * square;
		ID8 = n2 + s66 + 36 * square + 1;

		/* 四元数(.csv) */
		output1 << quaternions[ n ][ 0 ] << "," << quaternions[ n ][ 1 ] << "," << quaternions[ n ][ 2 ] << "," << quaternions[ n ][ 3 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* 四元数(.txt) */
		output2 << quaternions[ n ][ 0 ] << "\t" << quaternions[ n ][ 1 ] << "\t" << quaternions[ n ][ 2 ] << "\t" << quaternions[ n ][ 3 ] << "\t" <<
		ID1 << "\t" << ID2  << "\t" << ID3 << "\t" << ID4 << "\t" << ID5 << "\t" << ID6 << "\t" << ID7 << "\t" << ID8 << endl;

		/* 角度(Degree)(.csv) */
		output3 << degrees[ n ][ 0 ] << "," << degrees[ n ][ 1 ] << "," << degrees[ n ][ 2 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* 角度(Degree)(.txt) */
		output4 << degrees[ n ][ 0 ] << "\t" << degrees[ n ][ 1 ] << "\t" << degrees[ n ][ 2 ] << "\t" <<
		ID1 << "\t" << ID2  << "\t" << ID3 << "\t" << ID4 << "\t" << ID5 << "\t" << ID6 << "\t" << ID7 << "\t" << ID8 << endl;

		/* 角度(Radian)(.csv) */
		output5 << radians[ n ][ 0 ] << "," << radians[ n ][ 1 ] << "," << radians[ n ][ 2 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* 角度(Radian)(.txt) */
		output6 << radians[ n ][ 0 ] << "\t" << radians[ n ][ 1 ] << "\t" << radians[ n ][ 2 ] << "\t" <<
		ID1 << "\t" << ID2  << "\t" << ID3 << "\t" << ID4 << "\t" << ID5 << "\t" << ID6 << "\t" << ID7 << "\t" << ID8 << endl;

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
	output4.close();
	output5.close();
	output6.close();


	/* 返り値 */
	return true;
}