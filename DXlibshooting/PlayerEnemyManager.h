#pragma once

class PlayerEnemyManager
{
public:

	void LoadImages();
	//�G�̃p�^�[��������
	void BackGround1();
	void Enemy1();
	void Enemy2();
	void Enemy3();
	void Enemy4();
	void Enemy5();
	void Enemy6();
	void Boss();
	int  rang(int x);
	void Bossmove( int dist);
	//�v���C���\
	void Player();
	//�v���C���[�V���b�g
	void Player_Shooting();
	//�G�V���b�g
	void Enemy_Shooting();
	void Enemy_Shooting_H();
	void Enemy_Shooting_M();
	void Boss_Shooting();

	void Rotate();
	//�X�R�A
	void Score();
	//�p�^�[������
	void EnemyAppearPattern();
	void Attack_area(int character_x,int character_y,int g_handle,bool visible,int life,int x,int y);
	//�G�ɒe������������
	

};

