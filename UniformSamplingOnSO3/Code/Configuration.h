/***** 設定ファイル *****/


/*** 定数の定義 ***/

/* SIMPLE_GRID と LAYERED_GRID に対する番号の割り当て */
#define SIMPLE_GRID 1
#define LAYERED_GRID 2

/* 円周率 */
#define M_PI 3.141592

/* 中間出力ファイルまでのパス */
const char middleFileName1[ 128 ] = "Output/quaternion.csv";	// 四元数と次の解像度レベルにおける対応四元数 ID
const char middleFileName2[ 128 ] = "Output/quaternion.txt";	// 四元数と次の解像度レベルにおける対応四元数 ID 
const char middleFileName3[ 128 ] = "Output/degree.csv";		// 角度θ,Φ,Ψ(degree)と次の解像度レベルにおける対応角度 ID
const char middleFileName4[ 128 ] = "Output/degree.txt";		// 角度θ,Φ,Ψ(degree)と次の解像度レベルにおける対応角度 ID
const char middleFileName5[ 128 ] = "Output/radian.csv";		// 角度θ,Φ,Ψ(Radian)と次の解像度レベルにおける対応角度 ID
const char middleFileName6[ 128 ] = "Output/radian.txt";		// 角度θ,Φ,Ψ(Radian)と次の解像度レベルにおける対応角度 ID

/* 出力ファイルまでのパス */
const char outputFileName1[ 128 ] = "Output/L%d/quaternionID.csv";	// 四元数と次の解像度レベルにおける対応四元数 ID
const char outputFileName2[ 128 ] = "Output/L%d/quaternionID.txt";	// 四元数と次の解像度レベルにおける対応四元数 ID 
const char outputFileName3[ 128 ] = "Output/L%d/degreeID.csv";		// 角度θ,Φ,Ψ(degree)と次の解像度レベルにおける対応角度 ID
const char outputFileName4[ 128 ] = "Output/L%d/degreeID.txt";		// 角度θ,Φ,Ψ(degree)と次の解像度レベルにおける対応角度 ID
const char outputFileName5[ 128 ] = "Output/L%d/radianID.csv";		// 角度θ,Φ,Ψ(Radian)と次の解像度レベルにおける対応角度 ID
const char outputFileName6[ 128 ] = "Output/L%d/radianID.txt";		// 角度θ,Φ,Ψ(Radian)と次の解像度レベルにおける対応角度 ID
const char outputFileName7[ 128 ] = "Output/L%d/R/%d.csv";			// 解像度レベル L における 72 * 8^L 個の回転行列 R
const char outputFileName8[ 128 ] = "Output/L%d/nextID/%d.csv";		// 次の解像度レベルにおける回転行列の対応 ID
