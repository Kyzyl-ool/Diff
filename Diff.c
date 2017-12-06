#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Diff.h"

//#define DEBUG_DIFF
//#define DEBUG_SIMPLIFY



Node* d(Node* node)
{
	Node* new_node = (Node* )calloc(1, sizeof(Node));
	new_node->parent = node->parent;
	new_node->left = NULL;
	new_node->right = NULL;
	#ifdef DEBUG_DIFF
	printf("Вызвана фунцкия d с типом [%s]...\n", type_to_string(node->t));
	#endif
	switch (node->t)
	{
		case NUMBER_DOUBLE:
		case NUMBER_INT:
		case CONSTANT:
		{
			#ifdef DEBUG_DIFF
			printf("Берется производная числа...\n");
			#endif
			new_node->t = NUMBER_INT;
			new_node->value.i = 0;
			
			#ifdef DEBUG_DIFF
			printf("...производная числа взята.\n");
			#endif
			break;
		}
		case VARIABLE:
		{
			#ifdef DEBUG_DIFF
			printf("Берется производная переменной...\n");
			#endif
			new_node->t = NUMBER_INT;
			new_node->value.i = 1;
			#ifdef DEBUG_DIFF
			printf("... производная переменной взята.\n");
			#endif
			break;
		}
		case OPERATOR:
		{
			#ifdef DEBUG_DIFF
			printf("Берется проиводная оператора [%s]...\n", operator_to_string(node->value.o));
			#endif
			switch (node->value.o)
			{
				case MULTIPLY:
				{
					#ifdef DEBUG_DIFF
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
					new_node->left->left = d(node->left);
					new_node->left->right = c(node->right);
					
					new_node->right->t = OPERATOR;
					new_node->right->value.o = MULTIPLY;
					new_node->right->left = c(node->left);
					new_node->right->right = d(node->right);
					
					#ifdef DEBUG_DIFF
					printf("... производная умножения взята.\n");
					#endif
					break;
				}
				case PLUS:
				{
					#ifdef DEBUG_DIFF
					printf("Берётся производная сложения...");
					#endif
					new_node->t = OPERATOR;
					new_node->value.o = PLUS;
					
					new_node->left = d(node->left);
					new_node->right = d(node->right);
					
					#ifdef DEBUG_DIFF
					printf("... производная сложения взята.\n");
					#endif
					
					break;
				}
				default:
				{
					printf("НЕ РЕАЛИЗОВАНО ВЗЯТИЕ ПРОИЗВОДНОЙ ДЛЯ [%s]\n", operator_to_string(node->value.o));
					assert(0);
					break;
				}
			}
			break;
		}
		default:
		{
			printf("НЕИЗВЕСТНЫЙ ТИП УЗЛА: [%s]\n", type_to_string(node->t));
			assert(0);
			break;
		}
	}
	#ifdef DEBUG_DIFF
	printf("...функция d с типом [%s] завершила работу.\n", type_to_string(node->t));
	#endif
	return new_node;
}

Node* c(Node* node)
{
	Node* copy = (Node* )calloc(1, sizeof(Node));
	copy->parent = node->parent;
	if (node->left)
		copy->left = c(node->left);
	if (node->right)
		copy->right = c(node->right);
	copy->t = node->t;
	copy->value = node->value;
	return copy;
}

int isexpression(Node* node)
{
	if (node->t == VARIABLE)
		return 1;
	
	if (node->left && isexpression(node->left) == 1)
			return 1;
	
	if (node->right && isexpression(node->right) == 1)
			return 1;
	
	return 0;
}

Node* simplify(Node* node)
{
	#ifdef DEBUG_SIMPLIFY
	printf("Получил узел с типом [%s]...\n", type_to_string(node->t));
	#endif
	if (node->t == OPERATOR)
	{
		#ifdef DEBUG_SIMPLIFY
		printf("Узел имеет оператор [%s]...\n", operator_to_string(node->value.o));
		#endif
		switch (node->value.o)
		{
			case MULTIPLY:
			{
				if ((node->left->value.i == 0 && node->left->t == NUMBER_INT) || (node->right->value.i == 0 && node->right->t == NUMBER_INT))
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Выполняется упрощение умножения на ноль...\n");
					#endif
					tree_Delete_node(node->left);
					tree_Delete_node(node->right);
					node->t = NUMBER_INT;
					node->value.i = 0;
					node->left = NULL;
					node->right = NULL;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("...упрощение умножения на ноль выполнено.\n");
					#endif
					break;
				}
				if (node->left->value.i == 1 && node->left->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение умножения на единицу...\n");
					#endif
					Node tmp = *node->right;
					free(node->left);
					free(node->right);
					*node = tmp;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("...упрощение умножения на единицу завершнено.\n");
					#endif
					break;
				}
				else if (node->right->value.i == 1 && node->right->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение умножения на единицу...\n");
					#endif
					Node tmp = *node->left;
					free(node->left);
					free(node->right);
					*node = tmp;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("...упрощение умножения на единицу завершнено.\n");
					#endif
					break;
				}
				break;
			}
			case DIVIDE:
			{
				if (node->right->value.i == 1 && node->right->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение деления на единицу...\n");
					#endif
					Node tmp = *node->left;
					free(node->left);
					free(node->right);
					*node = tmp;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("...упрощение деления на единицу выполнено.\n");
					#endif
					break;
				}
				if (node->left->value.i == 0 && node->left->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение частного с нулевым делимым...\n");
					#endif
					tree_Delete_node(node->left);
					tree_Delete_node(node->right);
					node->t = NUMBER_INT;
					node->value.i = 0;
					node->left = NULL;
					node->right = NULL;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("...упрощение частного с нулевым делимым завершено.\n");
					#endif
					break;
				}
				break;
			}
			case PLUS:
			{
				if (node->left->value.i == 0 && node->left->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение 0+a...\n");
					#endif
					Node tmp = *node->right;
					free(node->left);
					free(node->right);
					*node = tmp;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("...0+a упрощено.\n");
					#endif
					break;
				}
				if (node->right->value.i == 0 && node->right->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение a+0...\n");
					#endif
					Node tmp = *node->left;
					free(node->left);
					free(node->right);
					*node = tmp;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("...a+0 упрощено.\n");
					#endif
					break;
				}
				break;
			}
			case MINUS:
			{
				if (node->left->value.i == 0 && node->left->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение 0-a...\n");
					#endif
					node->t = OPERATOR;
					node->value.o = MULTIPLY;
					node->left->value.i = -1;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("0-a упрощено.\n");
					#endif
					break;
				}
				if (node->right->value.i == 0 && node->right->t == NUMBER_INT)
				{
					#ifdef DEBUG_SIMPLIFY
					printf("Упрощение a-0...\n");
					#endif
					node->t = node->left->t;
					node->value = node->left->value;
					tree_Delete_node(node->right);
					node = node->left;
					simplified += 1;
					#ifdef DEBUG_SIMPLIFY
					printf("а-0 упрощено.\n");
					#endif
					break;
				}
				break;
			}
			default:
			{
				#ifdef DEBUG_SIMPLIFY
				printf("НЕИЗВЕТСНО, КАК УПРОЩАТЬ ОПРЕТАОРЫ [%s]", operator_to_string(node->value.o));
				#endif
			}
		}
	}
	
	if (node->left)
		simplify(node->left);
	if (node->right)
		simplify(node->right);
	
	return node;
}
