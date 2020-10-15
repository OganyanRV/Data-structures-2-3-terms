#include <iostream>

int main()
{
  std::cout << "The Sieve of Eratosthenes" << std::endl; // Решето Эратосфена
  std::cout << "Enter the upper bound for integer values: "; // Введите верхнюю границу целых значений
  int size=0;
  std::cin >> size;
  TBitField bfield(size + 1);
  /* Filling the Bit Field
  Заполнение битового поля   */
  for (size_t m = 2; m <= size; m++)
    bfield.SetBit(m);
  /* проверка до sqrt(n) и удаление кратных */
  for (size_t m = 2; m * m <= size; m++)
    // если m в s, удаление кратных
    if (bfield.GetBit(m))
      for (size_t k = 2 * m; k <= size; k += m)
        if (bfield.GetBit(k))
          bfield.ClrBit(k);
  // оставшиеся в s элементы - простые числа
  std::cout << "\n Печать множества некратных чисел \n" << s << std::endl;
  std::cout << " \n Печать простых чисел" << std::endl;
  int count = 0;
  int print_par = 1;
  for (size_t m = 2; m <= n; m++)
    if (bfield.GetBit(m))
    {
      count++;
      std::cout << std::setw(3) << m << " ";
      if (k++ % 10 == 0)
        std::cout << "\n";
    }
  std::cout << std::endl;
  std::cout << "В первых " << n << " числах " << count << " простых" << std::endl;
  system("pause");
}
#else

#include "tset.h"

int main()
{
  int n, m, k, count;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки множества" << endl;
  cout << "              Решето Эратосфена" << endl;
  cout << "Введите верхнюю границу целых значений - ";
  cin >> n;
  TSet s(n + 1);
  // заполнение множества
  for (m = 2; m <= n; m++)
    s.InsElem(m);
  // проверка до sqrt(n) и удаление кратных
  for (m = 2; m * m <= n; m++)
    // если м в s, удаление кратных
    if (s.IsMember(m))
      for (k = 2 * m; k <= n; k += m)
        if (s.IsMember(k))
          s.DelElem(k);
  // оставшиеся в s элементы - простые числа
  cout << endl << "Печать множества некратных чисел" << endl << s << endl;
  cout << endl << "Печать простых чисел" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.IsMember(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "В первых " << n << " числах " << count << " простых" << endl;
}

#endif

