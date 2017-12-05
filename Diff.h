#include "tree_modified.h"

Node* d(Node* expr); //Производнпая выражения
Node* dComplex_Function(Node* complxfunc); //Производная сложной функции
Node* dSin(Node* expr); //Производная синуса
Node* dCos(Node* expr); //Производная косинуса
Node* dkx(Node* expr); //Производная переменной

void Make_Report(char* file_name); //Отчет дифференцирования в LaTeX-формате
