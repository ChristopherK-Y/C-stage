#include"game.h"
void ShowGameMenu() {
	printf("###################################\n");
	printf("### 1.Play Number Guessing Game ###\n");
	printf("### 2.Play Three Chess Game     ###\n");
	printf("### 3.Play Mine Clearance Game  ###\n");
	printf("### 4.Exit                      ###\n");
	printf("###################################\n");
	printf("Plese enter your select# ");
}



int LoginNumber() {
	char id[64];
	char pw[64];
	int opportunity = OPPORTUNITY;
	printf("!!! You only have 3 opportunity to login in!!!\n");
	for (opportunity; opportunity > 0; opportunity--) {
		printf("Please enter ID# ");
		scanf("%s", id);
		printf("Please enter PassWord# ");
		scanf("%s", pw);
		if ((strcmp(CORRECT_ID, id) || strcmp(CORRECT_PASSWARD, pw)) == 0) {
			return 1;
		}
		else {
			printf("Login failed!Your have %d opportunities left!\n", opportunity - 1);
		}
	}
	return 0;
}

void ShowNumberMenu() {
	printf("############################\n");
	printf("##  1.Play        2.Exit  ##\n");
	printf("############################\n");
}

void GameNumber() {
	int your_num = 0;
	printf("Welcome to the game!\n");
	srand((unsigned int)time(NULL));
	int random_number = rand() % 100 + 1;
	while (1) {
		printf("Please enter your number# ");
		scanf("%d", &your_num);
		if (your_num == random_number) {
			printf("Congratulations on your guess!\n");
			break;
		}
		else if (your_num < random_number) {
			printf("Sorry, your guess is a little small!\n");
		}
		else {
			printf("Sorry, your guess is a little big!\n");
		}
	}
}



void ShowBoard(char ChessBoard[][COL], int row, int col) {
	printf("  | 1 | 2 | 3 |\n");
	printf("---------------\n");
	for (int i = 0; i < row; i++){
		printf("%d |", i + 1);
		for (int j = 0; j < col; j++) {
			printf(" %c |", ChessBoard[i][j]);
		}
		printf("\n---------------\n");
	}
}

void PlayerGo(char ChessBoard[][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1) {
		printf("Please enter you post# ");
		scanf("%d %d", &x, &y);
		if (ChessBoard[x - 1][y - 1] != ' ') {
			printf("Post error, please enter again!\n");
		}
		else {
			ChessBoard[x - 1][y - 1] = 'X';
			return;
		}
	}
}
char Judge(char ChessBoard[][COL], int row, int col) {
	int null = 0;
	for (int i = 0; i < row; i++) {//����3��
		if (ChessBoard[i][0] == ChessBoard[i][1] &&\
			ChessBoard[i][1] == ChessBoard[i][2] &&\
			ChessBoard[i][0] != ' ') {
			return ChessBoard[i][0];
		}
	}
	for (int i = 0; i < col; i++) {//����3��
		if (ChessBoard[0][i] == ChessBoard[1][i] &&\
			ChessBoard[1][i] == ChessBoard[2][i] &&\
			ChessBoard[0][i] != ' ') {
			return ChessBoard[0][i];
		}
	}
	if (ChessBoard[0][0] == ChessBoard[1][1] &&\
		ChessBoard[1][1] == ChessBoard[2][2] &&\
		ChessBoard[0][0] != ' ') {//�Խ���1
		return ChessBoard[0][0];
	}
	if (ChessBoard[0][2] == ChessBoard[1][1] &&\
		ChessBoard[1][1] == ChessBoard[2][0] &&\
		ChessBoard[0][2] != ' ') {//�Խ���2
		return ChessBoard[0][2];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (ChessBoard[i][j] == ' ') {
				null = 1;
			}
		}
	}
	if (null) {
		return 'N';//������Ϸ����������
	}
	return 'P';//ƽ��
}
void ComputerGO(char ChessBoard[][COL], int row, int col) {
	
	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		if (ChessBoard[x][y] == ' ') {
			ChessBoard[x][y] = 'O';
			return;
		}
	}
}

void ShowChessMenu() {
	printf("######################\n");
	printf("## 1.Play    2.Exit ##\n");
	printf("######################\n");
	printf("Plese enter your select# ");
}

int PorC() {
	char p[10];
	int _p;
	int _c;
	char stone[10] = "石头";
	char scissors[10] = "����";
	char cloth[10] = "��";

START:
	_c = rand() % 3;
	while (1) {
		printf("Please enter ʯͷ or ���� or ��# ");
		scanf("%s", &p);
		if (!(strcmp(stone, p))) {
			_p = 0;
			break;
		}
		else if (!(strcmp(scissors, p))) {
			_p = 1;
			break;
		}
		else if (!(strcmp(cloth, p))) {
			_p = 2;
			break;
		}
		else {
			printf("Enter error,please enter again!\n");
		}
	}
	if (_p > _c) {
		return 1;
	}
	else if (_p < _c) {
		return 0;
	}
	else {
		printf("Common , enter again!\n");
		goto START;
	}
}

void GameChess() {
	srand((unsigned int)time(NULL));
	char ChessBoard[ROW][COL];
	memset(ChessBoard, ' ', ROW * COL);
	
	int who = PorC();//1:Player 2:Computer
	ShowBoard(ChessBoard, ROW, COL);
	while (1) {
		char win = ' ';
		//ShowBoard(ChessBoard, ROW, COL);
		if (who) {
			printf("Because you win,so you go !\n");
			PlayerGo(ChessBoard, ROW, COL);//���who=1��������ߣ����������
			ShowBoard(ChessBoard, ROW, COL);
		}
		else {
			printf("Because you lose,so computer go !\n");
			ComputerGO(ChessBoard, ROW, COL);
			ShowBoard(ChessBoard, ROW, COL);
		}
		//ShowBoard(ChessBoard, ROW, COL);
		win = Judge(ChessBoard, ROW, COL);//reurn 'X' Player win; return 'O' Computer win; return 'P' ƽ��; return 'N' ����
		if (win != 'N') {
			switch (win) {
			case'X':
				printf("You win!\n");
				break;
			case'O':
				printf("Computer win!\n");
				break;
			case'P':
				printf("No winner!\n");
				break;
			default:
				break;
			}
			return;
		}
		if (who) {//���who=1��˵��������ߣ��������ڻ�����
			ComputerGO(ChessBoard, ROW, COL);
			ShowBoard(ChessBoard, ROW, COL);
		}
		else {
			PlayerGo(ChessBoard, ROW, COL);
			ShowBoard(ChessBoard, ROW, COL);
		}
		win = Judge(ChessBoard, ROW, COL);
		if (win != 'N') {
			switch (win) {
			case'X':
				printf("You win!\n");
				break;
			case'O':
				printf("Computer win!\n");
				break;
			case'P':
				printf("No winner!\n");
				break;
			default:
				break;
			}
			return;
		}
	}
}