/***** 2�������� S2 �ɂ�����_���W���̎Z�o *****/


/*** �C���N���[�h�t�@�C�� ***/

/* C */
#include<stdio.h>

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** 2�������� S2 �ɂ�����_���W���̎Z�o ***/
long nside2npix( const long nside ){
	
	return 12 * nside * nside;
}
