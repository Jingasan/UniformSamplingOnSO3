/***** ��]���� S1 �̓��Ԋu�T���v�����O *****/


/*** �C���N���[�h�t�@�C�� ***/

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** ��]���� S1 �̓��Ԋu�T���v�����O ***/
vector< double > grid_s1( int resol ){
	

	/* �ϐ��̐錾�Ə����� */
	int grids = 6;				// ��]����(S1)�ɂ�����O���b�h��
	vector< double > Points;	// ��]����(S1)�̉�]�p���̔z��
	
	/* �������̊m�� */
	Points.resize( 0 );

	/* �_���̎Z�o */
	int number_points = pow( 2, (double)resol ) * grids;	// 2 �̉𑜓x���x���� �~ �O���b�h��( 6 )
	// �𑜓x���x�� 0 �̂Ƃ� �c 6 �_
	// �𑜓x���x�� 1 �̂Ƃ� �c 12 �_
	// �𑜓x���x�� 2 �̂Ƃ� �c 24 �_
	// �𑜓x���x�� 3 �̂Ƃ� �c 48 �_

	/* �_�Ԃ̕�( ���W�A���P�� ) */
	float interval = 2 * M_PI / number_points;

	/* ��]���� S1 �̓��Ԋu�T���v�����O */
	for( int i = 0; i < number_points; i++ ) Points.push_back( interval / 2 + i * interval );

	/* �Ԃ�l */
	return Points;
}
