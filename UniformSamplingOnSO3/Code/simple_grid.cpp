/***** 1�F�P��𑜓x(Simple Grid)�w��̏ꍇ *****/


/*** �C���N���[�h�t�@�C�� ***/

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** 1(Simple Grid)�I�����F�w�肵���𑜓x���x���ɂ�����_���쐬�E�o�� ***/
bool simple_grid( int resol ){


	/* �ϐ��̐錾�Ə����� */
	vector< double > Psi_Points, temp;			// S1
	vector< vector< double > > Healpix_Points;	// S2
	vector< vector< double > > S3_Points;		// S3
	long int Nside = 0, numpixels = 0;			// 2�̉𑜓x���x����, 2�������� S2 �ɂ�����_���W��
	double theta = 0, pfi = 0;					// ��, ��
	bool result;								// ���s���ʂ̔��� �c 1�F����, 0�F���s
	
	/* �������̊m�� */
	Psi_Points.resize( 0 );
	

	/*** ��]���� S1 �̃T���v�����O ***/

	/* ��]���� S1 �ɂ�����_���W �� ���i�[�����z��̎擾 */
	Psi_Points = grid_s1( resol );	// ��]���� S1 �̓��Ԋu�T���v�����O

	/* ��]���� S1 �ɂ�����_���W �� ���i�[�����z�񂪋�̂Ƃ� */
	if( Psi_Points.size() == 0 ) return false;	// ���s�l 0 ��Ԃ�
	

	/*** 2�������� S2 �̃T���v�����O ***/

	/* 2�̉𑜓x���x���� */
	Nside = pow( 2, (double)resol );	// �𑜓x���x�� 0�F1, �𑜓x���x�� 1�F2, �𑜓x���x�� 2�F4, �𑜓x���x�� 3�F8, �c

	/* 2�������� S2 �ɂ�����_���W���̎擾 */
	numpixels = nside2npix( Nside );	// �𑜓x���x�� 0�F12, �𑜓x���x�� 1�F48, �𑜓x���x�� 2�F192, �𑜓x���x�� 3�F768, �c
	
	/* �������̊m�� */
	Healpix_Points.resize( 0 );
	
	/* 2�������� S2 �ɂ�����_���W( ��, �� )���i�[�����z��̎擾 */
	for( long int i = 0; i < numpixels; i++ ){
		
		/* �������̊m�� */
		temp.resize( 0 );
		
		/* ��]�p ��, �� �̎擾 */
		pix2ang_nest( Nside, i, &theta, &pfi );

		/* �_���W( ��, �� )�̍쐬 */
		temp.push_back( theta );
		temp.push_back( pfi );

		/* 2�������� S2 ��̓_���W( ��, �� )���i�[�����z�� */
		Healpix_Points.push_back( temp );
	}
	
	/* �������̊m�� */
	S3_Points.resize( 0 );
	

	/*** ��]��� SO(3) �ɂ�����ϓ��ȃT���v�����O�̍쐬 ***/
	for( int i = 0; i < Healpix_Points.size(); i++ ){
		for( int j = 0; j < Psi_Points.size(); j++ ){
			
			/* �������̊m�� */
			temp.resize( 0 );
			
			/* �_���W( ��, ��, �� )�̍쐬 */
			temp.push_back( Healpix_Points[ i ][ 0 ] );
			temp.push_back( Healpix_Points[ i ][ 1 ] );
			temp.push_back( Psi_Points[ j ] );

			/* 3�������� S3 ��̓_���W( ��, ��, �� )���i�[�����z�� */
			S3_Points.push_back( temp );
		}
	}
	

	/*** �T���v�����O���ʂƂȂ�l�����Q�̏o�� ***/
	result = hopf2quat( S3_Points );


	/* �Ԃ�l */
	return result;
}

