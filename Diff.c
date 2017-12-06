#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Diff.h"
//#define DEBUG

Node* d(Node* expr)
{
	Node* new_node = (Node* )calloc(1, sizeof(Node));
	new_node->parent = expr->parent;
	new_node->left = NULL;
	new_node->right = NULL;
	#ifdef DEBUG
	printf("Вызвана фунцкия d с типом [%s]...\n", type_to_string(expr->t));
	#endif
	switch (expr->t)
	{
		case NUMBER_DOUBLE:
		case NUMBER_INT:
		case CONSTANT:
		{
			#ifdef DEBUG
			printf("Берется производная числа...\n");
			#endif
			new_node->t = NUMBER_INT;
			new_node->value.i = 0;
			
			#ifdef DEBUG
			printf("...производная числа взята.\n");
			#endif
			break;
		}
		case VARIABLE:
		{
			#ifdef DEBUG
			printf("Берется производная переменной...\n");
			#endif
			new_node->t = NUMBER_INT;
			new_node->value.i = 1;
			#ifdef DEBUG
			printf("... производная переменной взята.\n");
			#endif
			break;
		}
		case OPERATOR:
		{
			#ifdef DEBUG
			printf("Берется проиводная оператора [%s]...\n", operator_to_string(expr->value.o));
			#endif
			switch (expr->value.o)
			{
				case MULTIPLY:
				{
					#ifdef DEBUG
					printf("Берется производная умножения...\n");
					#endif
					new_node->t = OPERATOR;
					new_node->value.o = PLUS;
					
					new_node->left = (Node* )calloc(1, sizeof(Node));
					new_node->right = (Node*)calloc(1, sizeof(Node));
					new_node->left->parent = new_node;
					new_node->right->parent = new_node;
					
					new_node->left->t = OPERATOR;
					new_node->left->value.o = MULTIPLY;
					new_node->left->left = d(expr->left);
					new_node->left->right = c(expr->right);
					
					new_node->right->t = OPERATOR;
					new_node->right->value.o = MULTIPLY;
					new_node->right->left = c(expr->left);
					new_node->right->right = d(expr->right);
					
					#ifdef DEBUG
					printf("... производная умножения взята.\n");
					#endif
					break;
				}
				case PLUS:
				{
					#ifdef DEBUG
					printf("Берётся производная сложения...");
					#endif
					new_node->t = OPERATOR;
					new_node->value.o = PLUS;
					
					new_node->left = d(expr->left);
					new_node->right = d(expr->right);
					
					#ifdef DEBUG
					printf("... производная сложения взята.\n");
					#endif
					
					break;
				}
				default:
				{
					printf("НЕ РЕАЛИЗОВАНО ВЗЯТИЕ ПРОИЗВОДНОЙ ДЛЯ [%s]\n", operator_to_string(expr->value.o));
					assert(0);
					break;
				}
			}
			break;
		}
		default:
		{
			printf("НЕИЗВЕСТНЫЙ ТИП УЗЛА: [%s]\n", type_to_string(expr->t));
			assert(0);
			break;
		}
	}
	#ifdef DEBUG
	printf("...функция d с типом [%s] завершила работу.\n", type_to_string(expr->t));
	#endif
	return new_node;
}

Node* c(Node* expr)
{
	Node* copy = (Node* )calloc(1, sizeof(Node));
	copy->parent = expr->parent;
	if (expr->left)
		copy->left = c(expr->left);
	if (expr->right)
		copy->right = c(expr->right);
	copy->t = expr->t;
	copy->value = expr->value;
	return copy;
}
