#include <iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "ru");

	int row, col, Oneshiprow1, Oneshipcol1, Oneshiprow2, Oneshipcol2,
		Twoshiprow1, Twoshipcol1, Twoshiprow2, Twoshipcol2;

	{
		cout << "\t Вас приветсвует виртуальная игра \"Морской Бой\"!" << endl << endl
			<< "Суть игры заключается в уничтожении всех кораблей противника." << endl
			<< "Море обозначено клетками 3 на 3." << endl

			<< "Для первого игрока, введите числа моря , куда хотите поставить  первый корабль :";
		cin >> Oneshiprow1 >> Oneshipcol1;

		cout << "Для первого игрока, введите числа моря , куда хотите поставить  второй корабль :";
		cin >> Oneshiprow2 >> Oneshipcol2;

		if (Oneshiprow1 == Oneshiprow2 && Oneshipcol1 == Oneshipcol2) {
			cout << "Корабли не могут находится в одном месте! Введите данные еще раз!" << endl;
			cout << "Для первого игрока, введите числа моря , куда хотите поставить  второй корабль :";
			cin >> Oneshiprow2 >> Oneshipcol2;
		}

		cout << "Для второго игрока, введите числа моря , куда хотите поставить  первый корабль :";
		cin >> Twoshiprow1 >> Twoshipcol1;

		cout << "Для второго игрока, введите числа моря , куда хотите поставить  второй корабль :";
		cin >> Twoshiprow2 >> Twoshipcol2;

		if (Twoshiprow1 == Twoshiprow2 && Twoshipcol1 == Twoshipcol2) {
			while (Twoshiprow1 != Twoshiprow2 && Twoshipcol1 != Twoshipcol2) {
				cout << "Корабли не могут находится в одном месте! Введите данные еще раз!" << endl;
				cout << "Для первого игрока, введите числа моря , куда хотите поставить  второй корабль :";
				cin >> Twoshiprow2 >> Twoshipcol2;
			}
		}
	}
	//Постановка кораблей.

	{
		bool move = true, win = false;
		cout << "Введите числа клетки моря , куда хотите попасть. ";

		while (win == false) {
			cout << "\n\tСтреляйте!!!";
			if (move) {
				cout << "\tХодит Игрок №1 " << endl;
				cin >> row >> col;
				if ((row != Twoshiprow1 || col != Twoshipcol1) && (row != Twoshiprow2 || col != Twoshipcol2)) {
					cout << "\tМимо!" << endl << endl;
				}
				if (row == Twoshiprow1 && col == Twoshipcol1) {
					Twoshiprow1 = 0;
					Twoshipcol1 = 0;
					cout << "Поздравляем командир! Вы потопили первый корабль!" << endl;
				}
				if (row == Twoshiprow2 && col == Twoshipcol2) {
					Twoshiprow2 = 0;
					Twoshipcol2 = 0;
					cout << "Поздравляем командир! Вы потопили второй корабль!" << endl;
				}
				if (Twoshiprow1 == 0 && Twoshipcol1 == 0 && Twoshiprow2 == 0 && Twoshipcol2 == 0) {
					win = true;
					cout << "\n\tПоздравляем! Игрок №1 победил!" << endl;
					break;
				}
				move = false;
			}
			if (!move) {
				cout << "\tХодит Игрок №2 " << endl;
				cin >> row >> col;
				if ((row != Oneshiprow1 || col != Oneshipcol1) && (row != Oneshiprow2 || col != Oneshipcol2)) {
					cout << "\tМимо!" << endl << endl;
				}
				if (row == Oneshiprow1 && col == Oneshipcol1) {
					Oneshiprow1 = 0;
					Oneshipcol1 = 0;
					cout << "Поздравляем командир! Вы потопили первый корабль!" << endl;
				}
				if (row == Oneshiprow2 && col == Oneshipcol2) {
					Oneshiprow2 = 0;
					Oneshipcol2 = 0;
					cout << "Поздравляем командир! Вы потопили второй корабль!" << endl;
				}
				if (Oneshiprow1 == 0 && Oneshipcol1 == 0 && Oneshiprow2 == 0 && Oneshipcol2 == 0) {
					win = true;
					cout << "\n\tПоздравляем! Игрок №2 победил!" << endl;
					break;
				}
				move = true;
			}
		}
	}
}
//Механизм игры.
