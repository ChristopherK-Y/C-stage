#include"MineClearance.h"

void ShowMineMenu() {
	printf("##########################\n");
	printf("###  1.Play    2.Exit  ###\n");
	printf("##########################\n");
	printf("Please enter your select# ");
}

void Init(char PlayerBoard[][COL], char MineBoard[][COL], int cow, int col) {
	memset(PlayerBoard, '*', sizeof(char) * cow * col);
	memset(MineBoard, '0', sizeof(char) * cow * col);
}

void LayingMines(char MineBoard[][COL], int row, int col) {
	int i = Mine_Nums;
	while (i > 0) {
		int mine_x = rand() % 10 + 1;
		int mine_y = rand() % 10 + 1;
		if (MineBoard[mine_x][mine_y] == '0') {
			MineBoard[mine_x][mine_y] = '1';
			i--;
		}
	}
}

void ShowBoard2(char Board[][COL], int row, int col) {
	system("cls");
	printf("  |");
	for (int i = 1; i <= col - 2; i++) {
		printf("%2d |", i);
	}
	printf("\n-------------------------------------------\n");
	for (int i = 1; i <= row - 2; i++) {
		printf("%2d| ", i);
		for (int j = 1; j <= col - 2; j++) {
			printf("%c | ", Board[i][j]);
		}
		printf("\n-------------------------------------------\n");
	}
}

void InputPlayerPost(int* player_x, int* player_y) {
	printf("Please enter your post# ");
	scanf("%d %d", player_x, player_y);
}
//非递归展开
/*int GetMineNumber(char Board[][COL], int player_x, int player_y) {
	return Board[player_x - 1][player_y - 1] + Board[player_x - 1][player_y] +\
		Board[player_x - 1][player_y + 1] + Board[player_x][player_y + 1] +\
		Board[player_x + 1][player_y + 1] + Board[player_x + 1][player_y] +\
		Board[player_x + 1][player_y - 1] + Board[player_x][player_y - 1] -\
		8 * '0';
}
*/

int GetMineNumber(char PlayerBoard[][COL], char Board[][COL], int player_x, int player_y) {
	int numbers = Board[player_x - 1][player_y - 1] + Board[player_x - 1][player_y] + \
		Board[player_x - 1][player_y + 1] + Board[player_x][player_y + 1] + \
		Board[player_x + 1][player_y + 1] + Board[player_x + 1][player_y] + \
		Board[player_x + 1][player_y - 1] + Board[player_x][player_y - 1] - \
		8 * '0';
	if (numbers == 0 && PlayerBoard[player_x][player_y] == '*') {
		PlayerBoard[player_x][player_y] = '0';
		if (player_x - 1 > 0 && player_y - 1 > 0 && PlayerBoard[player_x - 1][player_y - 1] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x - 1, player_y - 1);
		}
		if (player_x - 1 > 0 && player_y > 0 && PlayerBoard[player_x - 1][player_y] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x - 1, player_y);
		}
		if (player_x - 1 > 0 && player_y + 1 < COL && PlayerBoard[player_x - 1][player_y + 1] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x - 1, player_y + 1);
		}
		if (player_x > 0 && player_y + 1 < COL && PlayerBoard[player_x][player_y + 1] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x, player_y + 1);
		}
		if (player_x + 1 < ROW && player_y + 1 < COL && PlayerBoard[player_x + 1][player_y + 1] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x + 1, player_y + 1);
		}
		if (player_x + 1 < ROW && player_y > 0 && PlayerBoard[player_x + 1][player_y] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x + 1, player_y);
		}
		if (player_x + 1 < ROW && player_y - 1 > 0 && PlayerBoard[player_x + 1][player_y - 1] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x + 1, player_y - 1);
		}
		if (player_x > 0 && player_y - 1 > 0 && PlayerBoard[player_x][player_y - 1] == '*') {
			GetMineNumber(PlayerBoard, Board, player_x, player_y - 1);
		}
	}
	return numbers;
}

void MineGame() {
	char PlayerBoard[ROW][COL];
	char MineBoard[ROW][COL];
	int player_x = 0;
	int player_y = 0;
	int count = (ROW - 2) * (COL - 2) - Mine_Nums;//面板上剩余的非雷格子的数量
	srand((unsigned int)time(NULL));//播撒随机数种子
	Init(PlayerBoard, MineBoard, ROW, COL);//初始化2个面板
	LayingMines(MineBoard, ROW, COL);//随机的布设地雷
	do {
		ShowBoard2(PlayerBoard, ROW, COL);//显示扫雷面板
		InputPlayerPost(&player_x, &player_y);//玩家输入函数,仅仅修改x，y的值
		if (MineBoard[player_x][player_y] == '1') {
			break;
		}
		if (PlayerBoard[player_x][player_y] == '*') {
			PlayerBoard[player_x][player_y] = GetMineNumber(PlayerBoard, MineBoard, player_x, player_y) + '0';
			count--;
		}
		else {
			printf("Enter error,please enter again!\n");
		}
	} while (count > 0);
	if (count > 0) {
		ShowBoard2(MineBoard, ROW, COL);//显示地雷面板
		printf("You stepped on a mine!\n");
	}
	else {
		printf("You win the game!\n");
	}
}