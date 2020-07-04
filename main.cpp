


# include "Game.h"
# include "Snake.h"
#include <conio.h>

int main()
{


	printf("       Welcome to Snake 2020\n");
	system("color f4");
	char name[64];
	printf("\n\n Please enter your name: "); scanf("%s", name);


	

	int number; 
	pair p1{ 3, 3 };
	pair p2{ 4, 4 };
	std::vector<pair> pairs;
	pairs.push_back(p1);
	pairs.push_back(p2);
	Snake s = Snake(2, pairs);
	Game game{ name, s, 8, 8 };
	//Game game{ name, s, 8, 8 };
	while (1) {
		printf("               Menu      \n");
		printf("1.Start\n");
		printf("2.Change name\n");
		printf("3.Settings\n");
		printf("0.Exit\n");
		printf("Your choice is: "); scanf("%d", &number);
		switch (number) {
		case 1:
			game.run();
			break;
		case 2:
			printf("Enter new name: "); scanf("%s", name);
			game.name = name;
			printf("Name changed!\n");
			break;
		case 3:
			printf("To be done...\n");
			break;
		case 0:
			exit(0);

		}
	}

	return 0;
}