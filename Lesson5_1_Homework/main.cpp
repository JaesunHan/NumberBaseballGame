#include <iostream>
#include <time.h>

using namespace std;

void init(int *c1, int *c2, int *c3, int *turn, int *strike, int *ball) {
	srand(time(NULL));
	*c1 = 0, *c2 = 0, *c3 = 0;
	*turn = 10;
	*strike = 0, *ball = 0;
	while (*c1 == *c2 || *c2 == *c3 || *c1 == *c3) {		//��ǻ�Ͱ� �� ���ڰ� �ߺ��Ǹ� �ȵǹǷ� �˻��ϱ�
		*c1 = rand() % 9 + 1;
		*c2 = rand() % 10;
		*c3 = rand() % 10;
	}
}

int main() {
//	srand(time(NULL)); 
	int c1=0, c2=0, c3=0, p1, p2, p3;
	float buf1, buf2, buf3;
	int turn = 10;
	int strike = 0, ball = 0;
	int oneMore;

	init(&c1, &c2, &c3, &turn, &strike, &ball);
	/*
	while (c1 == c2 || c2 == c3 || c1 == c3) {		//��ǻ�Ͱ� �� ���ڰ� �ߺ��Ǹ� �ȵǹǷ� �˻��ϱ�
		c1 = rand() % 9 + 1;
		c2 = rand() % 10;
		c3 = rand() % 10;
	}*/

	cout << "���� �߱� ����. �� 10���� ��ȸ�� �ֽ��ϴ�. " << endl;	
	while (turn >=0) {
		if (turn == 0) {
			cout << "You lose. Computer number is..." << endl << c1 << ", " << c2 << ", " << c3 << endl;
			cout << "���� �� ����??" << endl << "0. ���� �׸�.	1. ���� ���� ��! " << endl << "���� : ";
			cin >> oneMore;
			if (oneMore == 0) {
				return 0;
			}
			else if (oneMore == 1) {	// ���� �� �Ϸ���, strike, ball, turn�� �⺻������ �ٽ� �ʱ�ȭ����� ��.
				init(&c1, &c2, &c3, &turn, &strike, &ball);
				/*
				turn = 10, strike =0, ball =0;
				c1 = 0, c2 = 0, c3 = 0;
				while (c1 == c2 || c2 == c3 || c1 == c3) {
					c1 = rand() % 9 + 1;
					c2 = rand() % 10;
					c3 = rand() % 10;
				}*/
				continue;
			}
		}

		cout << "�� ���� ���ڸ� �Է��ϼ���.(���� ��ȸ : " << turn << " )" << endl;
		cin >> buf1 >> buf2 >> buf3;
		p1 = (int)buf1, p2 = (int)buf2, p3 = (int)buf3;
				
		if (p1 == p2 || p1==p3 || p2 == p3) {// ����ڰ� �Է��� ���ڰ� �ߺ��Ǹ� �ٽ� �Է� �ޱ�
			cout << "���ڸ� �ߺ� �Է� �ϼ̽��ϴ�. �ٽ� �Է��ϼ���." << endl;
			continue;
		}
		if (p1 == 0 ) {	
			cout << "ù��° �ڸ����� 0�� �� �� �����ϴ�." << endl;
			continue;
		} 
		if (p1<1 || p1>9 || p2<0 || p2>9 || p3<0 || p3>9 ) {
			cout << "0���� 9 ������ ���� �Է��ϼ���" << endl;
			continue;
		}
		//strike 
		if (c1 == p1) strike++;
		if (c2 == p2) strike++;
		if (c3 == p3) strike++;
		//ball
		if (c1 == p2)	ball++;
		if (c1 == p3)	ball++;
		if (c2 == p1)	ball++;	
		if (c2 == p3)	ball++;
		if (c3 == p1)	ball++;
		if (c3 == p2)	ball++;

		cout << strike << " strike " << ball << " ball! " << endl;
		
		if (strike == 3) {
			cout << "You win!" << endl;
			cout << "���� �� ����??" << endl << "0. ���� �׸�.	1. ���� ���� ��! " << endl << "���� : ";
			cin >> oneMore;
			if (oneMore == 0) {
				return 0;
			}
			else if (oneMore == 1) {	// ���� �� �Ϸ���, strike, ball, turn�� �⺻������ �ٽ� �ʱ�ȭ����� ��.
				init(&c1, &c2, &c3, &turn, &strike, &ball);
				/*
				turn = 10, strike =0, ball =0;
				c1 = 0, c2 = 0, c3 = 0;
				while (c1 == c2 || c2 == c3 || c1 == c3) {
					c1 = rand() % 9 + 1;
					c2 = rand() % 10;
					c3 = rand() % 10;
				}
				*/
				continue;
			}
			return 0;
		}
		strike = 0;
		ball = 0;
		turn--;
	}
	
	return 0;
}
