#include <iostream>
#include <time.h>

using namespace std;

void init(int *c1, int *c2, int *c3, int *turn, int *strike, int *ball) {
	srand(time(NULL));
	*c1 = 0, *c2 = 0, *c3 = 0;
	*turn = 10;
	*strike = 0, *ball = 0;
	while (*c1 == *c2 || *c2 == *c3 || *c1 == *c3) {		//컴퓨터가 고른 숫자가 중복되면 안되므로 검사하기
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
	while (c1 == c2 || c2 == c3 || c1 == c3) {		//컴퓨터가 고른 숫자가 중복되면 안되므로 검사하기
		c1 = rand() % 9 + 1;
		c2 = rand() % 10;
		c3 = rand() % 10;
	}*/

	cout << "숫자 야구 게임. 총 10번의 기회가 있습니다. " << endl;	
	while (turn >=0) {
		if (turn == 0) {
			cout << "You lose. Computer number is..." << endl << c1 << ", " << c2 << ", " << c3 << endl;
			cout << "한판 더 ㄱㄱ??" << endl << "0. ㄴㄴ 그만.	1. ㅇㅇ 한판 더! " << endl << "선택 : ";
			cin >> oneMore;
			if (oneMore == 0) {
				return 0;
			}
			else if (oneMore == 1) {	// 한판 더 하려면, strike, ball, turn을 기본값으로 다시 초기화해줘야 함.
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

		cout << "세 개의 숫자를 입력하세요.(남은 기회 : " << turn << " )" << endl;
		cin >> buf1 >> buf2 >> buf3;
		p1 = (int)buf1, p2 = (int)buf2, p3 = (int)buf3;
				
		if (p1 == p2 || p1==p3 || p2 == p3) {// 사용자가 입력한 숫자가 중복되면 다시 입력 받기
			cout << "숫자를 중복 입력 하셨습니다. 다시 입력하세요." << endl;
			continue;
		}
		if (p1 == 0 ) {	
			cout << "첫번째 자리수는 0이 올 수 없습니다." << endl;
			continue;
		} 
		if (p1<1 || p1>9 || p2<0 || p2>9 || p3<0 || p3>9 ) {
			cout << "0에서 9 사이의 수를 입력하세요" << endl;
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
			cout << "한판 더 ㄱㄱ??" << endl << "0. ㄴㄴ 그만.	1. ㅇㅇ 한판 더! " << endl << "선택 : ";
			cin >> oneMore;
			if (oneMore == 0) {
				return 0;
			}
			else if (oneMore == 1) {	// 한판 더 하려면, strike, ball, turn을 기본값으로 다시 초기화해줘야 함.
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
