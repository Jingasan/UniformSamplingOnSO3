/***** �l��������̉�]�s��̕��� *****/


/*** �C���N���[�h�t�@�C�� ***/

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** ���̉𑜓x�ɂ����đΉ�����_�� ID ���i�[ ***/
bool generateRfromQuaternion(
	int resolution	// �𑜓x���x��	
){


	/* �ϐ��̐錾 */
	FILE *input1;				// �t�@�C�����͗p�ϐ��F�l����&ID(.csv)
	vector< float > quaternion;	// �l����
	vector< int > nextID;		// ���̉𑜓x�ɂ�����Ή�ID
	int n = 0;					// �J�E���^
	char FileName[ 128 ];		// �t�@�C����
	double element0, element1, element2, element3;		// �l�����̊e�v�f
	double element0S, element1S, element2S, element3S;	// �l�����̊e�v�f��2��
	double R11, R12, R13, R21, R22, R23, R31, R32, R33;	// ��]�s��̊e�v�f

	/* �������̊m�� */
	quaternion.resize( 4 );		// �l����
	nextID.resize( 8 );			//

	/* �t�@�C�����̎w�� */
	sprintf( FileName, outputFileName1, resolution );

	/* �t�@�C���̓W�J�ƃG���[���� */
	if( ( input1 = fopen( FileName, "r" ) ) == NULL ){ cout << ">> Cannot open File: " << FileName << endl; return false; }

	/* �t�@�C�����e�̓ǂݍ��� */
	while( fscanf(
		input1, "%f,%f,%f,%f,%d,%d,%d,%d,%d,%d,%d,%d",
		&quaternion[ 0 ], &quaternion[ 1 ], &quaternion[ 2 ], &quaternion[ 3 ],
		&nextID[ 0 ], &nextID[ 1 ], &nextID[ 2 ], &nextID[ 3 ], &nextID[ 4 ], &nextID[ 5 ], &nextID[ 6 ], &nextID[ 7 ] ) != EOF
	){
		
		/* ��]�s��̕��� */
		element0 = (double)quaternion[ 0 ];							// �l������1�ڂ̗v�f
		element1 = (double)quaternion[ 1 ];							// �l������2�ڂ̗v�f 
		element2 = (double)quaternion[ 2 ];							// �l������3�ڂ̗v�f
		element3 = (double)quaternion[ 3 ];							// �l������4�ڂ̗v�f
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

		/* ��]�s��Ǝ��̉𑜓x�ɂ�����Ή�ID�̏o�� */
		ofstream output1;										// �t�@�C���o�͗p�ϐ��F��]�s��(.csv)
		sprintf( FileName, outputFileName7, resolution, n );	// �t�@�C�����̎w��
		output1.open( FileName );								// �t�@�C���̓W�J
		output1 << R11 << "," << R12 << "," << R13 << endl
			<< R21 << "," << R22 << "," << R23 << endl
			<< R31 << "," << R32 << "," << R33 << endl;	// �t�@�C�����e�̏�������
		output1.close();										// �������̉��

		ofstream output2;										// �t�@�C���o�͗p�ϐ��F��]�s��(.txt)
		sprintf( FileName, outputFileName8, resolution, n );	// �t�@�C�����̎w��
		output2.open( FileName );								// �t�@�C���̓W�J
		output2 << nextID[ 0 ] << "," << nextID[ 1 ] << "," <<
			nextID[ 2 ] << "," << nextID[ 3 ] << "," <<
			nextID[ 4 ] << "," << nextID[ 5 ] << "," <<
			nextID[ 6 ] << "," << nextID[ 7 ] << endl;			// �t�@�C�����e�̏�������
		output2.close();										// �������̉��

		/* �J�E���^�̍X�V */
		n++;
	}

	/* �������̉�� */
	fclose( input1 );
	


	/* �Ԃ�l */
	return true;
}