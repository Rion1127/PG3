#include "DxLib.h"
#include <list>
#include <vector>
#include <memory>
#include "Enemy.h"
#include "Player.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LE2A_�X�Y�L_���I��";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400;

bool BallCollision(const Vector2& a, const float& aSize, const Vector2& b, const float& bSize);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

	Player player_;
	player_.Ini();

	//�G
	std::vector< std::unique_ptr<Enemy>> enemies_;

	for (int i = 0; i < 5; i++) {
		std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();
		Vector2 pos = {
			(float)100 + 50 * i,
			(float)100
		};

		newEnemy->Ini(pos, &player_);

		enemies_.emplace_back(std::move(newEnemy));
	}

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = {0};

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = {0};

	// �Q�[�����[�v
	while (true) {
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		//�G�X�V
		for (std::unique_ptr<Enemy>& enemy : enemies_) {
			enemy->Update();
		}
		for (std::unique_ptr<Enemy>& enemy : enemies_) {
			if (enemy->GetAllDead()) {
				enemies_.clear();
			}
		}
		//�v���C���[�X�V
		player_.Update(keys);
		

		// �`�揈��
		
		//�G�`��
		for (std::unique_ptr<Enemy>& enemy : enemies_) {
			enemy->Draw();
		}
		//�v���C���[�`��
		player_.Draw();

		//����
		DrawFormatString(0, 0, 0xffffff, "WASD :�ړ�");

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}


bool BallCollision(const Vector2& a, const float& aSize, const Vector2& b, const float& bSize) {
	float x, y;
	float r;

	x = (float)pow(b.x - a.x, 2);
	y = (float)pow(b.y - a.y, 2);

	float pos = x + y;

	r = (float)pow(aSize + bSize, 2);
	if (pos <= r) {
		return true;
	}
	return false;
}