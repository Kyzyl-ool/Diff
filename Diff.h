#include "tree_modified.h"

int simplified;

Node* d(Node* node); //Производнпая выражения
Node* c(Node* node); //Копия узла
int if_depends_on_variable(Node* node);
Node* simplify(Node* node);
Node* simplifyfy(Node* node);
Node* d_s(Node* node);
int ifequal(Node* node1, Node* node2);
Node* d_complex_function(Node* node, Node* (*d)(Node* node));

void Make_Report(char* file_name); //Отчет дифференцирования в LaTeX-формате
