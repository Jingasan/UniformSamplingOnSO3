/***** 設定ファイル *****/


/*** 定数の定義 ***/

/* 円周率 */
#define M_PI 3.141592

/* 作成するディレクトリのパス */
const char DirectoryPath1[ 256 ] = "UniformSamplingSO3";
const char DirectoryPath2[ 256 ] = "UniformSamplingSO3/L%d";
const char DirectoryPath3[ 256 ] = "UniformSamplingSO3/L%d/nextID";
const char DirectoryPath4[ 256 ] = "UniformSamplingSO3/L%d/R";
const char DirectoryPath5[ 256 ] = "UniformSamplingSO3/L%d/nextID/%d0000";
const char DirectoryPath6[ 256 ] = "UniformSamplingSO3/L%d/R/%d0000";

/* 出力ファイルまでのパス */
const char OutputFileName1[ 128 ] = "quaternionID.csv";		// 四元数と次の解像度レベルにおける対応四元数 ID
const char OutputFileName2[ 128 ] = "degreeθΦΨID.csv";	// 角度(degree)と次の解像度レベルにおける対応角度 ID
const char OutputFileName3[ 128 ] = "radianθΦΨID.csv";	// 角度(Radian)と次の解像度レベルにおける対応角度 ID
const char OutputFileName4[ 128 ] = "%d.csv";				// 解像度レベル L における 72 * 8^L 個の回転行列 R
const char OutputFileName5[ 128 ] = "%d.csv";				// 次の解像度レベルにおける回転行列の対応 ID
