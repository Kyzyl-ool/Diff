#include "tree_modified.h"

int simplified;

Node* d(Node* node); //Производнпая выражения
Node* c(Node* node); //Копия узла
int isexpression(Node* node);
Node* simplify(Node* node);
Node* d_s(Node* node);
Node* node_Create(Node* parent, type t, data value);

void Make_Report(char* file_name); //Отчет дифференцирования в LaTeX-формате
