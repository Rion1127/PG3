#include <stdio.h>


// �ċA�I�Ȓ���
int RecursiveWage(int value,int hour) {
	if (hour <= 0) {
		return value;
	}
	
	return (RecursiveWage(value * 2 - 50,hour - 1));
}
//��ʓI�Ȓ���
int GeneralWage(int value, int hour) {
	return value * hour;
}

int main() {
	int wage = 1072;	//��ʓI�Ȏ���
	int hour = 10;		//����
	int result;			//���ʂ���

	//��ʓI�Ȓ�������
	result = GeneralWage(wage, hour);
	printf("��ʓI�Ȓ���\n%d�~\n", result);
	//�ċA�I�Ȓ�������
	result = RecursiveWage(100,hour);
	printf("�ċA�I�Ȓ���\n%d�~\n", result);

	//��ʓI�Ȓ����̂ق��������Ƃ�
	if (RecursiveWage(100, hour) < GeneralWage(wage, hour))
	{
		printf("\n��ʓI�Ȓ����̕����ׂ���\n");
	}
	//�ċA�I�Ȓ����̂ق�������
	else if (RecursiveWage(100, hour) > GeneralWage(wage, hour))
	{
		printf("\n�ċA�I�Ȓ����̕����ׂ���\n");
	}
	else {
		printf("\n�ǂ�����ꏏ\n");
	}

	return 0;
}