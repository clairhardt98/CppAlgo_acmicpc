#include <iostream>
using namespace std;

int Array[128][128];

void check(int y, int x, int size);

int blue = 0, white = 0;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> Array[i][j];

	check(0, 0, N);

	cout << white << endl;
	cout << blue << endl;
}

void check(int y, int x, int size)
{
	int color = Array[y][x];

	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; j++)
		{
			if (Array[i][j] != color)
			{
				check(y, x, size / 2);
				check(y, x + size / 2, size / 2);
				check(y + size / 2, x, size / 2);
				check(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}

	if (color == 0)
		white++;
	else
		blue++;
	
	return;
}