/***** ���d�K�w�� *****/


/*** �C���N���[�h�t�@�C�� ***/

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** ���̉𑜓x�ɂ����đΉ�����_�� ID ���i�[ ***/
bool connectLayeredGrids(
	int resolution	// �𑜓x���x��	
){


	/* �ϐ��̐錾 */
	FILE *inputFile1;						// �t�@�C���^�ϐ��F�l����(.csv)
	FILE *inputFile2;						// �t�@�C���^�ϐ��F��(.csv)
	FILE *inputFile3;						// �t�@�C���^�ϐ��F���W�A��(.csv)
	vector< vector< float > > quaternions;	// �l�������i�[����z��
	vector< vector< float > > degrees;		// �p�x(Degree)���i�[����z��
	vector< vector< float > > radians;		// �p�x(Radian)���i�[����z��
	vector< float > quaternion;				// �l����
	vector< float > degree;					// �p�x(Degree)
	vector< float > radian;					// �p�x(Radian)
	char FileName[ 128 ];					// �t�@�C����
	
	/* �������̊m�� */
	quaternions.resize( 0 );	// �l�������i�[����z��
	quaternion.resize( 4 );		// �l����
	degrees.resize( 0 );		// �p�x(Degree)���i�[����z��
	degree.resize( 3 );			// �p�x(Degree)
	radians.resize( 0 );		// �p�x(Radian)���i�[����z��
	radian.resize( 3 );			// �p�x(Radian)

	/* �t�@�C���̓W�J�ƃG���[���� */
	if( ( inputFile1 = fopen( middleFileName1, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << middleFileName1 << endl; return false; }
	if( ( inputFile2 = fopen( middleFileName3, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << middleFileName3 << endl; return false; }
	if( ( inputFile3 = fopen( middleFileName5, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << middleFileName5 << endl; return false; }
	
	/* �t�@�C�����e�̓ǂݍ��� */
	while( fscanf( inputFile1, "%f,%f,%f,%f", &quaternion[ 0 ], &quaternion[ 1 ], &quaternion[ 2 ], &quaternion[ 3 ] ) != EOF ) quaternions.push_back( quaternion );
	while( fscanf( inputFile2, "%f,%f,%f", &degree[ 0 ], &degree[ 1 ], &degree[ 2 ] ) != EOF ) degrees.push_back( degree );
	while( fscanf( inputFile3, "%f,%f,%f", &radian[ 0 ], &radian[ 1 ], &radian[ 2 ] ) != EOF ) radians.push_back( radian );

	/* �������̉�� */
	fclose( inputFile1 );
	fclose( inputFile2 );
	fclose( inputFile3 );

	/* �ϐ��̐錾�Ə����� */
	ofstream output1;	// �t�@�C���o�͗p�ϐ��F�l����(.csv)
	ofstream output2;	// �t�@�C���o�͗p�ϐ��F�l����(.txt)
	ofstream output3;	// �t�@�C���o�͗p�ϐ��F�p�x(Degree)(.csv)
	ofstream output4;	// �t�@�C���o�͗p�ϐ��F�p�x(Degree)(.txt)
	ofstream output5;	// �t�@�C���o�͗p�ϐ��F�p�x(Radian)(.csv)
	ofstream output6;	// �t�@�C���o�͗p�ϐ��F�p�x(Radian)(.txt)

	/* �t�@�C���̓W�J */
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

	/* ������ */
	int n = 0;									// �C���f�b�N�X
	int size = quaternions.size();				// �l�����A�p�x( Degree & Radian )�̐�
	int square = pow( 2, (double)resolution );	// 2�̉𑜓x���x����
	int n2;										// �ʂ��ԍ���2�{
	int s66 = 0;
	int count = 0;
	int ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8;	// �o�� ID �l


	/* ���̉𑜓x�ɂ����đΉ�����_�� ID ���i�[ */
	while( n < size ){
	
		/* �ʂ��ԍ���2�{ */
		n2 = 2 * n;

		ID1 = n2 + s66 + 0;
		ID2 = n2 + s66 + 1;
		ID3 = n2 + s66 + 12 * square;
		ID4 = n2 + s66 + 12 * square + 1;
		ID5 = n2 + s66 + 24 * square;
		ID6 = n2 + s66 + 24 * square + 1;
		ID7 = n2 + s66 + 36 * square;
		ID8 = n2 + s66 + 36 * square + 1;

		/* �l����(.csv) */
		output1 << quaternions[ n ][ 0 ] << "," << quaternions[ n ][ 1 ] << "," << quaternions[ n ][ 2 ] << "," << quaternions[ n ][ 3 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* �l����(.txt) */
		output2 << quaternions[ n ][ 0 ] << "\t" << quaternions[ n ][ 1 ] << "\t" << quaternions[ n ][ 2 ] << "\t" << quaternions[ n ][ 3 ] << "\t" <<
		ID1 << "\t" << ID2  << "\t" << ID3 << "\t" << ID4 << "\t" << ID5 << "\t" << ID6 << "\t" << ID7 << "\t" << ID8 << endl;

		/* �p�x(Degree)(.csv) */
		output3 << degrees[ n ][ 0 ] << "," << degrees[ n ][ 1 ] << "," << degrees[ n ][ 2 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* �p�x(Degree)(.txt) */
		output4 << degrees[ n ][ 0 ] << "\t" << degrees[ n ][ 1 ] << "\t" << degrees[ n ][ 2 ] << "\t" <<
		ID1 << "\t" << ID2  << "\t" << ID3 << "\t" << ID4 << "\t" << ID5 << "\t" << ID6 << "\t" << ID7 << "\t" << ID8 << endl;

		/* �p�x(Radian)(.csv) */
		output5 << radians[ n ][ 0 ] << "," << radians[ n ][ 1 ] << "," << radians[ n ][ 2 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* �p�x(Radian)(.txt) */
		output6 << radians[ n ][ 0 ] << "\t" << radians[ n ][ 1 ] << "\t" << radians[ n ][ 2 ] << "\t" <<
		ID1 << "\t" << ID2  << "\t" << ID3 << "\t" << ID4 << "\t" << ID5 << "\t" << ID6 << "\t" << ID7 << "\t" << ID8 << endl;

		/* �J�E���^�̍X�V */
		n++;
		if( n % ( 6 * square ) == 0 ){
			count++;
			s66 = 6 * 6 * square * count;
		}
	}


	/* �������̉�� */
	output1.close();
	output2.close();
	output3.close();
	output4.close();
	output5.close();
	output6.close();


	/* �Ԃ�l */
	return true;
}