/***** ��]��� SO(3) �ɂ�����ϓ��ȃT���v�����O�̌��ʏo�� *****/


/*** �C���N���[�h�t�@�C�� ***/

/* �萔�̐ݒ� */
#include "Configuration.h"

/* �֐��̒�`�� */
#include "grid_generation.h"


/*** ��]��� SO(3) �ɂ�����ϓ��ȃT���v�����O�̌��ʏo�� ***/
bool hopf2quat( vector< vector< double > > Points ){
	

	/* �ϐ��̐錾�Ə����� */
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;	// �l����
	ofstream output1;						// �t�@�C���o�͗p�ϐ��F�l����(.csv)
	ofstream output2;						// �t�@�C���o�͗p�ϐ��F�l����(.txt)
	ofstream output3;						// �t�@�C���o�͗p�ϐ��F��(.csv)
	ofstream output4;						// �t�@�C���o�͗p�ϐ��F��(.txt)
	ofstream output5;						// �t�@�C���o�͗p�ϐ��F���W�A��(.csv)
	ofstream output6;						// �t�@�C���o�͗p�ϐ��F���W�A��(.txt)

	/* �t�@�C���̓W�J */
	output1.open( middleFileName1 );	
	output2.open( middleFileName2 );
	output3.open( middleFileName3 );
	output4.open( middleFileName4 );
	output5.open( middleFileName5 );
	output6.open( middleFileName6 );
	
	/* �_�Q�����������[�v */
	for( int i = 0; i < Points.size(); i++ ){

		/* �z�b�v���W���\������l���� */
		// �� ( ���ʍ��W S2, �P�ʁF���W�A�� ) �c Points[ i ][ 0 ]
		// �� ( ���ʍ��W S2, �P�ʁF���W�A�� ) �c Points[ i ][ 1 ]
		// �� ( ��]���� S1, �P�ʁF���W�A�� ) �c Points[ i ][ 2 ]
		x4 = sin( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );
		x1 = cos( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 2 ] / 2 );
		x2 = cos( Points[ i ][ 0 ] / 2 ) * sin( Points[ i ][ 2 ] / 2 );
		x3 = sin( Points[ i ][ 0 ] / 2 ) * cos( Points[ i ][ 1 ] + Points[ i ][ 2 ] / 2 );

		/* ���s���ʂ̃t�@�C���ւ̏o�� */
		output1 << x1 << "," << x2 << "," << x3 << "," << x4 << endl;
		output2 << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << endl;
		output3 << Points[ i ][ 0 ] * 180 / M_PI << "," << Points[ i ][ 1 ] * 180 / M_PI << "," << Points[ i ][ 2 ] * 180 / M_PI << endl;
		output4 << Points[ i ][ 0 ] * 180 / M_PI << "\t" << Points[ i ][ 1 ] * 180 / M_PI << "\t" << Points[ i ][ 2 ] * 180 / M_PI << endl;
		output5 << Points[ i ][ 0 ] << "," << Points[ i ][ 1 ] << "," << Points[ i ][ 2 ] << endl;
		output6 << Points[ i ][ 0 ] << "\t" << Points[ i ][ 1 ] << "\t" << Points[ i ][ 2 ] << endl;
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
