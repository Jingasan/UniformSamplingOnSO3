/***** 回転空間 SO(3) の均等なサンプリング *****/


//【 コマンドライン引数 】
// 1. グリッドタイプ … 1：指定した解像度レベルにおける点を出力(Simple Grid), 2：指定した解像度レベルまでの点をすべて出力(Layered Grid)
// 2. 解像度レベル … 0 ⇒ 1 ⇒ 2 ⇒ 3 ⇒ … ⇒ 13：この順に解像度が密になっていく( 最大は解像度レベル 13 まで )

//【 点群数 】
// コマンドライン引数 1 0 ： 解像度レベル 0 における点数分 72 点
// コマンドライン引数 1 1 ： 解像度レベル 1 における点数分 576 点
// コマンドライン引数 1 2 ： 解像度レベル 2 における点数分 4608 点
// コマンドライン引数 1 3 ： 解像度レベル 3 における点数分 36864 点
// コマンドライン引数 2 0 ： 解像度レベル 0 における点数分 72 点
// コマンドライン引数 2 1 ： 解像度レベル 0 + 1 における点数分 72 + 576 = 648 点
// コマンドライン引数 2 2 ： 解像度レベル 0 + 1 + 2 における点数分 72 + 576 + 4608 = 5256 点
// コマンドライン引数 2 3 ： 解像度レベル 0 + 1 + 2 + 3 における点数分 72 + 576 + 4608 + 36864 = 42120 点


/*** インクルードファイル ***/

/* 定数の設定 */
#include "Configuration.h"

/* 関数の定義等 */
#include "grid_generation.h"


/*** メイン処理文 ***/
int main( int argc, char** argv ){


	/* プログラム開始のコール */
	cout << "【 プログラム開始 】" << endl;


	/* コマンドライン引数指定エラー時 */
	if( argc < 3 ){
		cout << "Usage: ./S3_Grid <type of grid> <resolution>" << endl;
		cout << "Grids types: 1.Simple Grid  2.Layered Grid" << endl;
		exit( -1 );
	}
	
	/* 変数の宣言と初期化 */
	int grid_choice = atoi( argv[ 1 ] );	// グリッドタイプ … 1：Simple Grid, 2：Layered Grid
	int resolution = atoi( argv[ 2 ] );		// 解像度レベル … 0 ⇒ 1 ⇒ 2 ⇒ 3 ⇒ … の順に解像度が密になる
	bool result;							// 実行結果の判定 … 1：成功, 0：失敗
	
	/* グリッドタイプの選択 */
	switch( grid_choice ){
		
		/* 1：単一解像度( Simple Grid )指定の場合 */
		case SIMPLE_GRID:
			cout << ">> 回転空間 SO(3) の均等なサンプリング( Simple Grid Version )" << endl;
			result = simple_grid( resolution );								// 指定した解像度レベルにおける点を作成・出力
			cout << ">> 次の解像度において対応する点の ID 付加" << endl;
			if( result ) result = connectLayeredGrids( resolution );		// 次の解像度において対応する点の ID を格納
			cout << ">> 四元数からの回転行列 R の復元" << endl;
			if( result ) result = generateRfromQuaternion( resolution );	// 四元数からの回転行列の復元
			break;

		/* 2：複数解像度( Layered Grid )指定の場合 */
		case LAYERED_GRID:
			cout << "【 回転空間 SO(3) の均等なサンプリング 】LayeredGridVersion" << endl;
			result = layered_grid( resolution );	// 指定した解像度レベルまでの点をすべて作成・出力
			break;
	}
	
	/* プログラム正常終了時 */
	if( result ){
		cout << ">> Output file is generated." << endl;
		cout << "【 プログラム正常終了 】" << endl;
		system( "pause" );
		exit( 0 );
	}

	/* プログラム異常終了時 */
	else{
		cout << ">> Error: Terminating the program" << endl;
		cout << "【 プログラム異常終了 】" << endl;
		system( "pause" );
		exit( 1 );
	}
}
		
