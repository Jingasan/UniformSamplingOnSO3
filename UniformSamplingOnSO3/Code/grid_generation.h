/***** 関数の定義等 *****/


/*** インクルードファイル ***/

/* C++ */
#include <iostream>
#include <fstream>
#include <vector>

/* C */
#include <math.h>
#include <direct.h>
#include <string.h>


/*** 名前空間の宣言 ***/

/* C++ */
using namespace std;


/*** 関数の定義 ***/
long nside2npix( const long ); 
void pix2ang_nest( long, long, double*, double* );
void mk_pix2xy( int*, int* );
vector< double > grid_s1( int );
bool healpix_wrapper( int );
bool hopf2quat( vector< vector< double > >, int );
bool simple_grid( int );
 
