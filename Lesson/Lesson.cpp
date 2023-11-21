#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int ROWS = 3, COLS = 3;
string arr[ROWS][COLS]
{
	{"[ ]","[ ]","[ ]"},
	{"[ ]","[ ]","[ ]"},
	{"[ ]","[ ]","[ ]"}
};

vector<vector<bool>> cellOccupied(ROWS, vector<bool>(COLS, false));

int chooseCell ()
{
	cout << "Выберите ячейку!\nВаш выбор: ";
	int cell;
	cin >> cell;
	/*cout << endl;*/
	int row = (cell - 1) / COLS;
	int col = (cell - 1) % COLS;
	if (cin.fail())
	{
		cin.clear(); // Сбрасываем флаг ошибки
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем входной буфер до следующего знака, в этом случае до \n
		cout << "Введите корректное число (можно использовать только арабские цифры от 1 до 9)!\n";
		return chooseCell();
	}
	if (cell <= 9 && cell > 0)
	{
		if (cellOccupied[row][col]) {
			cout << "Эта ячейка уже занята. Выберите другую.\n";
			return chooseCell();
		}
		
		cellOccupied[row][col] = true;

		return cell;
	}
	else
	{
		cout << "Данной ячейки не существует, выберите ячейку от 1 до 9 включительно\n";
		return chooseCell();
	}
}

void arrOut()
{
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int checkWinX() {
	
	for (int i = 0; i < ROWS; ++i) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == "[x]") {
			return 1;
		}
	}

	for (int j = 0; j < COLS; ++j) {
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] == "[x]") {
			return 1;
		}
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == "[x]") {
		return 1;
	}

	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] == "[x]") {
		return 1;
	}
}

int checkWin0()
{
	for (int i = 0; i < ROWS; ++i) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == "[0]") {
			return 1;
		}
	}

	for (int j = 0; j < COLS; ++j) {
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] == "[0]") {
			return 1;
		}
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == "[0]") {
		return 1;
	}

	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] == "[0]") {
		return 1;
	}
}

bool checkDraw()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (!cellOccupied[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int playWithFriend()
{
	arrOut();
	while (true)
	{
		cout << "Ход игрока Х!\n";

		switch (chooseCell())
		{
		case 1:
			arr[0][0] = "[x]";
			arrOut();
			break;
		case 2:
			arr[0][1] = "[x]";
			arrOut();
			break;
		case 3:
			arr[0][2] = "[x]";
			arrOut();
			break;
		case 4:
			arr[1][0] = "[x]";
			arrOut();
			break;
		case 5:
			arr[1][1] = "[x]";
			arrOut();
			break;
		case 6:
			arr[1][2] = "[x]";
			arrOut();
			break;
		case 7:
			arr[2][0] = "[x]";
			arrOut();
			break;
		case 8:
			arr[2][1] = "[x]";
			arrOut();
			break;
		case 9:
			arr[2][2] = "[x]";
			arrOut();
			break;
		default:
			cout << "Данной ячейки не существует";
		}


		if (checkWinX())
		{
			cout << "Игрок Х победил!\n";
			return 0;
		}

		if (checkDraw())
		{
			cout << "Ничья!\n";
			return 0;
		}

		cout << "Ход игрока 0!\n";

		switch (chooseCell())
		{
		case 1:
			arr[0][0] = "[0]";
			arrOut();
			break;
		case 2:
			arr[0][1] = "[0]";
			arrOut();
			break;
		case 3:
			arr[0][2] = "[0]";
			arrOut();
			break;
		case 4:
			arr[1][0] = "[0]";
			arrOut();
			break;
		case 5:
			arr[1][1] = "[0]";
			arrOut();
			break;
		case 6:
			arr[1][2] = "[0]";
			arrOut();
			break;
		case 7:
			arr[2][0] = "[0]";
			arrOut();
			break;
		case 8:
			arr[2][1] = "[0]";
			arrOut();
			break;
		case 9:
			arr[2][2] = "[0]";
			arrOut();
			break;
		default:
			cout << "Данной ячейки не существует";
		}

		if (checkWin0())
		{
			cout << "Игрок 0 победил!\n";
			return 0;
		}

		if (checkDraw())
		{
			cout << "Ничья!\n";
			return 0;
		}
	}
}

int botChooseEasy()
{
	int cell = rand() % 9 + 1;
	int row = (cell - 1) / COLS;
	int col = (cell - 1) % COLS;

		if (cellOccupied[row][col]) {
			return botChooseEasy();
		}
		else
		{
			cellOccupied[row][col] = true;
			cout << "Выбор бота: " << cell<<endl;
			return cell;
		}
}

int playWithBotEasy()
{
	arrOut();
	while (true)
	{

		cout << "Ваш ход!\n";

		switch (chooseCell())
		{
		case 1:
			arr[0][0] = "[x]";
			arrOut();
			break;
		case 2:
			arr[0][1] = "[x]";
			arrOut();
			break;
		case 3:
			arr[0][2] = "[x]";
			arrOut();
			break;
		case 4:
			arr[1][0] = "[x]";
			arrOut();
			break;
		case 5:
			arr[1][1] = "[x]";
			arrOut();
			break;
		case 6:
			arr[1][2] = "[x]";
			arrOut();
			break;
		case 7:
			arr[2][0] = "[x]";
			arrOut();
			break;
		case 8:
			arr[2][1] = "[x]";
			arrOut();
			break;
		case 9:
			arr[2][2] = "[x]";
			arrOut();
			break;
		default:
			cout << "Данной ячейки не существует";
		}


		if (checkWinX())
		{
			cout << "Вы победили!\n";
			return 0;
		}

		if (checkWin0())
		{
			cout << "Бот победил!\n";
			return 0;
		}

		if (checkDraw())
		{
			cout << "Ничья!\n";
			return 0;
		}

		cout << "Ход бота!\n";

		switch (botChooseEasy())
		{
		case 1:
			arr[0][0] = "[0]";
			arrOut();
			break;
		case 2:
			arr[0][1] = "[0]";
			arrOut();
			break;
		case 3:
			arr[0][2] = "[0]";
			arrOut();
			break;
		case 4:
			arr[1][0] = "[0]";
			arrOut();
			break;
		case 5:
			arr[1][1] = "[0]";
			arrOut();
			break;
		case 6:
			arr[1][2] = "[0]";
			arrOut();
			break;
		case 7:
			arr[2][0] = "[0]";
			arrOut();
			break;
		case 8:
			arr[2][1] = "[0]";
			arrOut();
			break;
		case 9:
			arr[2][2] = "[0]";
			arrOut();
			break;
		default:
			cout << "Данной ячейки не существует";
		}

		if (checkWinX())
		{
			cout << "Вы победили!\n";
			return 0;
		}

		if (checkWin0())
		{
			cout << "Вы проиграли =(\n";
			return 0;
		}

		if (checkDraw())
		{
			cout << "Ничья!\n";
			return 0;
		}
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	cout << "Здравствуйте!\n";
	while (true)
	{
		int progNumb;
		cout << "Выберите как хотите сыграть: \n1) С другом \n2) C ботом \n0) Выход \nВаш выбор: ";
		cin >> progNumb;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите корректное число.\n";
			continue;
		}
		cout << endl;
		{
			switch (progNumb)
			{
			case 0:
				cout << "Спасибо за игру, до свидания!\n";
				return 0;
			case 1:
				playWithFriend();
				break;
			case 2:
				int diffLvl;
				cout << "Выберите на какой сложности хотите сыграть: \n1) Легкий \nВаш выбор: ";
				cin >> diffLvl;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Введите корректное число.\n";
					continue;
				}
				cout << endl;
				switch (diffLvl)
				{
				case 1:
					playWithBotEasy();
					break;
				default:
					cout << "Данного уровня сложности не существует \n";
				}

				break;
			default:
				cout << "Режима с такими номером не существует \n";
			}
		}
	}
}