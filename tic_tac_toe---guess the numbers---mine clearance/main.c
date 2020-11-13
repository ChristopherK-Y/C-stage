#include"game.h"
#include"MineClearance.h"

int main() {
	int gameselect = 0;
	int chessselect = 0;
	int numberselect = 0;
	int chessquit = 0;
	int numberquit = 0;
	int minequit = 0;
	int mineselect = 0;
	int quit = 0;
	while (!quit) {
		ShowGameMenu();
		scanf("%d", &gameselect);
		switch (gameselect) {
				case 1: {//猜数字游戏
					while (!numberquit) {
						if (!LoginNumber()) {//登陆函数（用户名:Bit;密码:Bits）
							printf("Login failed!\n");
							break;
						}

						ShowNumberMenu();
						printf("Please enter your select# ");
						scanf("%d", &numberselect);
						while (1) {
							switch (numberselect) {
							case 1:
								GameNumber();
								break;
							case 2:
								printf("Quit number guess game successfully\n");
								numberquit = 1;
								break;
							default:
								printf("Your select is illegal ! please enter 1 or 2.\n");
								break;
							}
							printf("Do you want to play again?\n");
							ShowNumberMenu();
							printf("Please enter your select# ");
							scanf("%d", &numberselect);
							if (numberselect == 2) {
								printf("Welcome to play again next time, quit successfully!\n");
								numberquit = 1;	
								break;
							}
						}
					}
				}
				break;
			case 2://三子棋游戏
				while (!chessquit) {
					ShowChessMenu();
					scanf("%d", &chessselect);
					switch (chessselect) {
					case 1:
						GameChess();
						printf("Dou you want to play again?\n");
						break;
					case 2:
						printf("Quit three chess successful!\n");
						chessquit = 1;
						break;
					default:
						printf("Select error,please enter again!");
						break;
					}
				}
				chessquit = 0;
				break;
			case 3: {
				while (!minequit) {
					ShowMineMenu();
					scanf("%d", &mineselect);
					switch (mineselect) {
					case 1:
						MineGame();
						printf("Do you want to play again?\n");
						break;
					case 2:
						printf("Quit successful!\n");
						minequit = 1;
						break;
					default:
						printf("Entre error,please enter again!\n");
						break;
					}
				}
				printf("Byebye.Welcome to play next time!\n");
			}
				  minequit = 0;
				break;
			case 4://退出
				printf("Quit successful!\n");
				quit = 1;
				break;
			default://输入不合法
				printf("Selectgame error,please enter again!");
				break;
		}
	}
	return 0;
}
