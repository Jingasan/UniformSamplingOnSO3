/***** �ݒ�t�@�C�� *****/


/*** �萔�̒�` ***/

/* �~���� */
#define M_PI 3.141592

/* �쐬����f�B���N�g���̃p�X */
const char DirectoryPath1[ 256 ] = "UniformSamplingSO3";
const char DirectoryPath2[ 256 ] = "UniformSamplingSO3/L%d";
const char DirectoryPath3[ 256 ] = "UniformSamplingSO3/L%d/nextID";
const char DirectoryPath4[ 256 ] = "UniformSamplingSO3/L%d/R";
const char DirectoryPath5[ 256 ] = "UniformSamplingSO3/L%d/nextID/%d0000";
const char DirectoryPath6[ 256 ] = "UniformSamplingSO3/L%d/R/%d0000";

/* �o�̓t�@�C���܂ł̃p�X */
const char OutputFileName1[ 128 ] = "quaternionID.csv";		// �l�����Ǝ��̉𑜓x���x���ɂ�����Ή��l���� ID
const char OutputFileName2[ 128 ] = "degree�ƃ���ID.csv";	// �p�x(degree)�Ǝ��̉𑜓x���x���ɂ�����Ή��p�x ID
const char OutputFileName3[ 128 ] = "radian�ƃ���ID.csv";	// �p�x(Radian)�Ǝ��̉𑜓x���x���ɂ�����Ή��p�x ID
const char OutputFileName4[ 128 ] = "%d.csv";				// �𑜓x���x�� L �ɂ����� 72 * 8^L �̉�]�s�� R
const char OutputFileName5[ 128 ] = "%d.csv";				// ���̉𑜓x���x���ɂ������]�s��̑Ή� ID
