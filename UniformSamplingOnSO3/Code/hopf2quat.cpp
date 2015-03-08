/***** ��]��� SO(3) �ɂ�����ϓ��ȃT���v�����O�̌��ʏo�� *****/


/*** �C���N���[�h�t�@�C�� ***/

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** ��]��� SO(3) �ɂ�����ϓ��ȃT���v�����O�̌��ʏo�� ***/
bool hopf2quat(
	vector< vector< double > > Points,	// S3
	int level							// �𑜓x���x��
){
	
	/* �ϐ��̐錾�Ə����� */
	int n = 0;													// �C���f�b�N�X
	int square = pow( 2, (double)level );						// 2�̉𑜓x���x����
	int n2;														// �ʂ��ԍ���2�{
	int s66 = 0;												// 6 * 6 * square * count
	int count = 0;												// �J�E���^
	int ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8;					// ���̉𑜓x�ɂ�����Ή� ID
	int dirID;													// �f�B���N�g���ԍ�
	double element0, element1, element2, element3;				// �l�����̊e�v�f
	double element0S, element1S, element2S, element3S;			// �l�����̊e�v�f��2��
	double R11, R12, R13, R21, R22, R23, R31, R32, R33;			// ��]�s��̊e�v�f
	char dirPath[ 256 ], FileName1[ 128 ], FileName2[ 512 ];	// �t�@�C����
	const char *slash = "/";									// �X���b�V��
	ofstream output1;											// �t�@�C���o�͗p�ϐ��F�l����(.csv)
	ofstream output2;											// �t�@�C���o�͗p�ϐ��F��(.csv)
	ofstream output3;											// �t�@�C���o�͗p�ϐ��F���W�A��(.csv)

	/* �t�@�C���̓W�J */
	sprintf( dirPath, DirectoryPath2, level ); sprintf( FileName1, OutputFileName1 );			// �f�B���N�g���p�X�ƃt�@�C�����̎w��
	strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// �f�B���N�g���p�X + �t�@�C����
	output1.open( FileName2 );																	// �l�����o�͗p�t�@�C���̓W�J
	sprintf( dirPath, DirectoryPath2, level ); sprintf( FileName1, OutputFileName2 );			// �f�B���N�g���p�X�ƃt�@�C�����̎w��
	strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// �f�B���N�g���p�X + �t�@�C����
	output2.open( FileName2 );																	// Degree �o�͗p�t�@�C���̓W�J
	sprintf( dirPath, DirectoryPath2, level ); sprintf( FileName1, OutputFileName3 );			// �f�B���N�g���p�X�ƃt�@�C�����̎w��
	strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// �f�B���N�g���p�X + �t�@�C����
	output3.open( FileName2 );																	// Radian �o�͗p�t�@�C���̓W�J
	
	/* �_�Q�����������[�v */
	for( int i = 0; i < Points.size(); i++ ){

		printf( ">> Process: %d\r", i );

		/* �ʂ��ԍ���2�{ */
		n2 = 2 * n;

		/* ���̉𑜓x�ɂ�����Ή� ID �̎Z�o */
		ID1 = n2 + s66 + 0; ID2 = n2 + s66 + 1;
		ID3 = n2 + s66 + 12 * square; ID4 = n2 + s66 + 12 * square + 1;
		ID5 = n2 + s66 + 24 * square; ID6 = n2 + s66 + 24 * square + 1;
		ID7 = n2 + s66 + 36 * square; ID8 = n2 + s66 + 36 * square + 1;

		/* �z�b�v���W���\������l���� */
		// �� ( ���ʍ��W S2, �P�ʁF���W�A�� ) �c Points[ i ][ 0 ]
		// �� ( ���ʍ��W S2, �P�ʁF���W�A�� ) �c Points[ i ][ 1 ]
		// �� ( ��]���� S1, �P�ʁF���W�A�� ) �c Points[ i ][ 2 ]
		element3 = sin( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );
		element0 = cos( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 2 ] / 2 );
		element1 = cos( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 2 ] / 2 );
		element2 = sin( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );

		/* ���s���ʂ̃t�@�C���ւ̏o�� */
		output1 << element0 << "," << element1 << "," << element2 << "," << element3 << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;
		output2 << Points[ i ][ 0 ] * 180 / M_PI << "," << Points[ i ][ 1 ] * 180 / M_PI << "," << Points[ i ][ 2 ] * 180 / M_PI << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;
		output3 << Points[ i ][ 0 ] << "," << Points[ i ][ 1 ] << "," << Points[ i ][ 2 ] << "," <<
		ID1 << "," << ID2  << "," << ID3 << "," << ID4 << "," << ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;

		/* �f�B���N�g���ԍ��̎w�� */
		dirID = i / 10000;

		/* ��]�s��̕��� */
		element0S = pow( element0, 2 );								// �l������1�ڂ̗v�f��2��
		element1S = pow( element1, 2 );								// �l������2�ڂ̗v�f��2��
		element2S = pow( element2, 2 );								// �l������3�ڂ̗v�f��2��
		element3S = pow( element3, 2 );								// �l������4�ڂ̗v�f��2��
		R11 = element0S + element1S - element2S - element3S;		// 1�s1��ڂ̗v�f
		R12 = 2 * ( element1 * element2 - element0 * element3 );	// 1�s2��ڂ̗v�f
		R13 = 2 * ( element1 * element3 + element0 * element2 );	// 1�s3��ڂ̗v�f
		R21 = 2 * ( element1 * element2 + element0 * element3 );	// 2�s1��ڂ̗v�f
		R22 = element0S - element1S + element2S - element3S;		// 2�s2��ڂ̗v�f
		R23 = 2 * ( element2 * element3 - element0 * element1 );	// 2�s3��ڂ̗v�f
		R31 = 2 * ( element1 * element3 - element0 * element2 );	// 3�s1��ڂ̗v�f
		R32 = 2 * ( element2 * element3 + element0 * element1 );	// 3�s2��ڂ̗v�f
		R33 = element0S - element1S - element2S + element3S;		// 3�s3��ڂ̗v�f

		/* ��]�s��̏o�� */
		ofstream output4;																			// �t�@�C���o�͗p�ϐ��F��]�s��
		sprintf( dirPath, DirectoryPath6, level, dirID ); sprintf( FileName1, OutputFileName4, n );	// �f�B���N�g���p�X�ƃt�@�C�����̎w��
		strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// �f�B���N�g���p�X + �t�@�C����
		output4.open( FileName2 );																	// �t�@�C���̓W�J
		output4 << R11 << "," << R12 << "," << R13 << endl
				<< R21 << "," << R22 << "," << R23 << endl
				<< R31 << "," << R32 << "," << R33 << endl;											// �t�@�C�����e�̏�������
		output4.close();																			// �������̉��

		/* ���̉𑜓x�ɂ�����Ή� ID �̏o�� */
		ofstream output5;																			// �t�@�C���o�͗p�ϐ��F���̉𑜓x�ɂ�����Ή� ID
		sprintf( dirPath, DirectoryPath5, level, dirID ); sprintf( FileName1, OutputFileName5, n );	// �f�B���N�g���p�X�ƃt�@�C�����̎w��
		strcpy( FileName2, dirPath ); strcat( FileName2, slash ); strcat( FileName2, FileName1 );	// �f�B���N�g���p�X + �t�@�C����
		output5.open( FileName2 );																	// �t�@�C���̓W�J
		output5 << ID1 << "," << ID2 << "," << ID3 << "," << ID4 << "," <<
					ID5 << "," << ID6 << "," << ID7 << "," << ID8 << endl;							// �t�@�C�����e�̏�������
		output5.close();																			// �������̉��

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

	/* �Ԃ�l */
	return true;
}
