/***** 四元数からの回転行列の復元 *****/


/*** インクルードファイル ***/

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** 次の解像度において対応する点の ID を格納 ***/
bool generateRfromQuaternion(
	int resolution	// 解像度レベル	
){


	/* 変数の宣言 */
	FILE *input1;				// ファイル入力用変数：四元数&ID(.csv)
	vector< float > quaternion;	// 四元数
	vector< int > nextID;		// 次の解像度における対応ID
	int n = 0;					// カウンタ
	char FileName[ 128 ];		// ファイル名
	double element0, element1, element2, element3;		// 四元数の各要素
	double element0S, element1S, element2S, element3S;	// 四元数の各要素の2乗
	double R11, R12, R13, R21, R22, R23, R31, R32, R33;	// 回転行列の各要素

	/* メモリの確保 */
	quaternion.resize( 4 );		// 四元数
	nextID.resize( 8 );			//

	/* ファイル名の指定 */
	sprintf( FileName, outputFileName1, resolution );

	/* ファイルの展開とエラー処理 */
	if( ( input1 = fopen( FileName, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << FileName << endl; return false; }

	/* ファイル内容の読み込み */
	while( fscanf(
		input1, "%f,%f,%f,%f,%d,%d,%d,%d,%d,%d,%d,%d",
		&quaternion[ 0 ], &quaternion[ 1 ], &quaternion[ 2 ], &quaternion[ 3 ],
		&nextID[ 0 ], &nextID[ 1 ], &nextID[ 2 ], &nextID[ 3 ], &nextID[ 4 ], &nextID[ 5 ], &nextID[ 6 ], &nextID[ 7 ] ) != EOF
	){
		
		/* 回転行列の復元 */
		element0 = (double)quaternion[ 0 ];							// 四元数の1つ目の要素
		element1 = (double)quaternion[ 1 ];							// 四元数の2つ目の要素 
		element2 = (double)quaternion[ 2 ];							// 四元数の3つ目の要素
		element3 = (double)quaternion[ 3 ];							// 四元数の4つ目の要素
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

		/* 回転行列と次の解像度における対応IDの出力 */
		ofstream output1;										// ファイル出力用変数：回転行列(.csv)
		sprintf( FileName, outputFileName7, resolution, n );	// ファイル名の指定
		output1.open( FileName );								// ファイルの展開
		output1 << R11 << "," << R12 << "," << R13 << endl
			<< R21 << "," << R22 << "," << R23 << endl
			<< R31 << "," << R32 << "," << R33 << endl;	// ファイル内容の書き込み
		output1.close();										// メモリの解放

		ofstream output2;										// ファイル出力用変数：回転行列(.txt)
		sprintf( FileName, outputFileName8, resolution, n );	// ファイル名の指定
		output2.open( FileName );								// ファイルの展開
		output2 << nextID[ 0 ] << "," << nextID[ 1 ] << "," <<
			nextID[ 2 ] << "," << nextID[ 3 ] << "," <<
			nextID[ 4 ] << "," << nextID[ 5 ] << "," <<
			nextID[ 6 ] << "," << nextID[ 7 ] << endl;			// ファイル内容の書き込み
		output2.close();										// メモリの解放

		/* カウンタの更新 */
		n++;
	}

	/* メモリの解放 */
	fclose( input1 );
	


	/* 返り値 */
	return true;
}