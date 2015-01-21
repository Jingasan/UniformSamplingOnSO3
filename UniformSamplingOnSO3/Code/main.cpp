/***** ��]��� SO(3) �̋ϓ��ȃT���v�����O *****/


//�y �R�}���h���C������ �z
// 1. �O���b�h�^�C�v �c 1�F�w�肵���𑜓x���x���ɂ�����_���o��(Simple Grid), 2�F�w�肵���𑜓x���x���܂ł̓_�����ׂďo��(Layered Grid)
// 2. �𑜓x���x�� �c 0 �� 1 �� 2 �� 3 �� �c �� 13�F���̏��ɉ𑜓x�����ɂȂ��Ă���( �ő�͉𑜓x���x�� 13 �܂� )

//�y �_�Q�� �z
// �R�}���h���C������ 1 0 �F �𑜓x���x�� 0 �ɂ�����_���� 72 �_
// �R�}���h���C������ 1 1 �F �𑜓x���x�� 1 �ɂ�����_���� 576 �_
// �R�}���h���C������ 1 2 �F �𑜓x���x�� 2 �ɂ�����_���� 4608 �_
// �R�}���h���C������ 1 3 �F �𑜓x���x�� 3 �ɂ�����_���� 36864 �_
// �R�}���h���C������ 2 0 �F �𑜓x���x�� 0 �ɂ�����_���� 72 �_
// �R�}���h���C������ 2 1 �F �𑜓x���x�� 0 + 1 �ɂ�����_���� 72 + 576 = 648 �_
// �R�}���h���C������ 2 2 �F �𑜓x���x�� 0 + 1 + 2 �ɂ�����_���� 72 + 576 + 4608 = 5256 �_
// �R�}���h���C������ 2 3 �F �𑜓x���x�� 0 + 1 + 2 + 3 �ɂ�����_���� 72 + 576 + 4608 + 36864 = 42120 �_


/*** �C���N���[�h�t�@�C�� ***/

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** ���C�������� ***/
int main( int argc, char** argv ){


	/* �v���O�����J�n�̃R�[�� */
	cout << "�y �v���O�����J�n �z" << endl;


	/* �R�}���h���C�������w��G���[�� */
	if( argc < 3 ){
		cout << "Usage: ./S3_Grid <type of grid> <resolution>" << endl;
		cout << "Grids types: 1.Simple Grid  2.Layered Grid" << endl;
		exit( -1 );
	}
	
	/* �ϐ��̐錾�Ə����� */
	int grid_choice = atoi( argv[ 1 ] );	// �O���b�h�^�C�v �c 1�FSimple Grid, 2�FLayered Grid
	int resolution = atoi( argv[ 2 ] );		// �𑜓x���x�� �c 0 �� 1 �� 2 �� 3 �� �c �̏��ɉ𑜓x�����ɂȂ�
	bool result;							// ���s���ʂ̔��� �c 1�F����, 0�F���s
	
	/* �O���b�h�^�C�v�̑I�� */
	switch( grid_choice ){
		
		/* 1�F�P��𑜓x( Simple Grid )�w��̏ꍇ */
		case SIMPLE_GRID:
			cout << ">> ��]��� SO(3) �̋ϓ��ȃT���v�����O( Simple Grid Version )" << endl;
			result = simple_grid( resolution );								// �w�肵���𑜓x���x���ɂ�����_���쐬�E�o��
			cout << ">> ���̉𑜓x�ɂ����đΉ�����_�� ID �t��" << endl;
			if( result ) result = connectLayeredGrids( resolution );		// ���̉𑜓x�ɂ����đΉ�����_�� ID ���i�[
			cout << ">> �l��������̉�]�s�� R �̕���" << endl;
			if( result ) result = generateRfromQuaternion( resolution );	// �l��������̉�]�s��̕���
			break;

		/* 2�F�����𑜓x( Layered Grid )�w��̏ꍇ */
		case LAYERED_GRID:
			cout << "�y ��]��� SO(3) �̋ϓ��ȃT���v�����O �zLayeredGridVersion" << endl;
			result = layered_grid( resolution );	// �w�肵���𑜓x���x���܂ł̓_�����ׂč쐬�E�o��
			break;
	}
	
	/* �v���O��������I���� */
	if( result ){
		cout << ">> Output file is generated." << endl;
		cout << "�y �v���O��������I�� �z" << endl;
		system( "pause" );
		exit( 0 );
	}

	/* �v���O�����ُ�I���� */
	else{
		cout << ">> Error: Terminating the program" << endl;
		cout << "�y �v���O�����ُ�I�� �z" << endl;
		system( "pause" );
		exit( 1 );
	}
}
		
