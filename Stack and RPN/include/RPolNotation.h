//  Copyright by Oganyan Robert

#include "../include/Token.h"

class RPolNotation {
   private:
     char* formula;     // исходная формула
     int size;
   public:
     RPolNotation() = delete;
     explicit RPolNotation(char *form = nullptr);  // конструктор
     RPolNotation(const RPolNotation& rpn);  //  Конструктор копирования
     ~RPolNotation();  //  Деструктор
     Token* Postfix(); // преобразование в постфиксную форму
     Token Next(int& ind); //  Вспомогательный метод для определения характеристик ячейки массива
     int FormulaChecker(int Brackets[],int size);  // проверка корректности скобок
     double Calculate();  //  вычисление формулы
};