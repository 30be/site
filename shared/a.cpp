#include <iostream>
#include <cmath>
using namespace std;

int main( void )
{
  int Max;

  cout << "Введите размер таблицы Пифагора: ";
  cin >> Max;

  // Ширина столбца: логарифм от tableSize*tableSize, плюс 3 для пробелов
  int ColumnWidth = log10(Max * Max) + 3;

  // Печать строк таблицы
  for (int i = 0; i <= Max; i++)
  {
    if (i != 0)
    {
      cout << "|";
      for (int j = 1; j <= Max; j++)
        cout << string(ColumnWidth - (int)log10(i * j) - 2, ' ') << i * j << " |"; 
      cout << endl;
    }
    // Разделительная линия между строками
    cout << "+";
    for (int Separator = 0; Separator < Max; Separator++)
    {
      for (int j = 0; j < ColumnWidth; j++) 
        cout << "-";
      cout << "+";
    }
    cout << endl;
  }

  return 0;
}

