#include <stdio.h>


// �ċA�I�Ȏ���
int RecursiveWage(int value,int hour) {
	if (hour <= 0) {
		return value;
	}
	
	return (RecursiveWage(value * 2 - 50,hour - 1));
}
//��ʓI�Ȏ���
int GeneralWage(int value, int hour) {
	return value * hour;
}

int main() {
	int wage = 1072;	//��ʓI�Ȏ���
	int hour = 10;		//����
	int result;			//���ʂ���

	//��ʓI�Ȏ�������
	result = GeneralWage(wage, hour);
	printf("��ʓI�Ȏ���\n%d�~\n", result);
	//�ċA�I�Ȏ�������
	result = RecursiveWage(100,hour);
	printf("�ċA�I�Ȏ���\n%d�~\n", result);

	//��ʓI�Ȏ����̂ق��������Ƃ�
	if (RecursiveWage(100, hour) < GeneralWage(wage, hour))
	{
		printf("\n��ʓI�Ȏ����̕����ׂ���\n");
	}
	//�ċA�I�Ȏ����̂ق�������
	else if (RecursiveWage(100, hour) > GeneralWage(wage, hour))
	{
		printf("\n�ċA�I�Ȏ����̕����ׂ���\n");
	}
	else {
		printf("\n�ǂ�����ꏏ\n");
	}

	return 0;
}