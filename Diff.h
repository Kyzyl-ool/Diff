#include "tree_modified.h"

int simplified;

Node* d(Node* node); //Производнпая выражения
Node* c(Node* node); //Копия узла
int isexpression(Node* node);
Node* simplify(Node* node);

void Make_Report(char* file_name); //Отчет дифференцирования в LaTeX-формате
