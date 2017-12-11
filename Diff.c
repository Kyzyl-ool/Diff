#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Diff.h"

#define DEBUG_DIFF
#define DEBUG_SIMPLIFY
#define _CREATE_CHILD(the_parent, the_node, the_type) Node* the_node = (Node* )calloc(1, sizeof(Node)); the_node->parent = the_parent; the_node->t = the_type;
#define _SET_NEWCHILD(the_parent, left_or_right, the_type) the_parent->left_or_right = (Node* )calloc(1, sizeof(Node)); the_parent->left_or_right->parent = the_parent; the_parent->left_or_right->t = the_type;
					

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
				case POWER:
				{
					if (isexpression(node->right))
					{
						//показательная функция
						#ifdef DEBUG_DIFF
						printf("Взятие производной показательной функции...\n");
						#endif
						assert(0);
						
						#ifdef DEBUG_DIFF
						printf("..производная показательной функции взята.\n");
						#endif
					}
					else
					{
						#ifdef DEBUG_DIFF
						printf("Взятие производной степенной функции...\n");
						#endif
						
						new_node->t = OPERATOR;
						new_node->value.o = MULTIPLY;
						
						new_node->left = (Node* )calloc(1, sizeof(Node));
						new_node->right = (Node* )calloc(1, sizeof(Node));
						new_node->left->parent = new_node;
						new_node->right->parent = new_node;
						new_node->left->left = NULL;
						new_node->left->right = NULL;
						
						new_node->left->t = node->right->t;
						if (new_node->left->t == NUMBER_INT)
							new_node->left->value.i = node->right->value.i;
						else if (new_node->left->t == NUMBER_DOUBLE)
							new_node->left->value.d = node->right->value.d;
						else
							assert(0);
						
						new_node->right->t = OPERATOR;
						new_node->right->value.o = POWER;
						new_node->right->left = (Node* )calloc(1, sizeof(Node));
						new_node->right->right = (Node* )calloc(1, sizeof(Node));
						new_node->right->left->parent = new_node->right;
						new_node->right->right->parent = new_node->right;
						
						new_node->right->left->left = NULL;
						new_node->right->left->right = NULL;
						new_node->right->right->left = NULL;
						new_node->right->right->right = NULL;
						
						new_node->right->left->t = VARIABLE;
						new_node->right->left->value.vt = node->left->value.vt;
						new_node->right->right->t = node->right->t;
						if (new_node->right->right->t == NUMBER_INT)
							new_node->right->right->value.i = node->right->value.i - 1;
						else if (new_node->right->right->t == NUMBER_DOUBLE)
							new_node->right->right->value.d = node->right->value.d - 1;
						else
							assert(0);

						#ifdef DEBUG_DIFF
						printf("...взятие производной степенной функции завершено.\n");
						#endif
						break;
					}
					break;
				}
				case DIVIDE:
				{
					#ifdef DEBUG_DIFF
					printf("Берется производная частного...\n");
					#endif
					Node* u = c(node->left);
					Node* v = c(node->right);
					
					new_node->t = OPERATOR;
					new_node->value.o = DIVIDE;
					
					_SET_NEWCHILD(new_node, left, OPERATOR)
					new_node->left->value.o = MINUS;
					
					_SET_NEWCHILD(new_node, right, OPERATOR)
					new_node->right->value.o = POWER;
					
					_SET_NEWCHILD(new_node->left, left, OPERATOR)
					new_node->left->left->value.o = MULTIPLY;
					
					_SET_NEWCHILD(new_node->left, right, OPERATOR)
					new_node->left->right->value.o = MULTIPLY;
					
					new_node->left->left->left = d(u);
					new_node->left->left->right = c(v);
					new_node->left->right->left = c(u);
					new_node->left->right->right = d(v);
					
					_SET_NEWCHILD(new_node->right, right, NUMBER_INT);
					new_node->right->right->value.i = 2;
					new_node->right->right->left = NULL;
					new_node->right->right->right = NULL;
					
					new_node->right->left = c(v);
					
					free(u);
					free(v);
					
					#ifdef DEBUG_DIFF
					printf("...взятие производной частного завершено.\n");
					#endif
					break;
				}
				case MINUS:
				{
					#ifdef DEBUG_DIFF
					printf("Взятие производной разности...\n");
					#endif
					
					new_node->t = OPERATOR;
					new_node->value.o = MINUS;
					
					new_node->left = d(node->left);
					new_node->right = d(node->right);
					
					
					#ifdef DEBUG_DIFF
					printf("...взятие производной разности завершено.\n");
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
					Node* tmp = node->parent;
					tree_node_Destroy(node);
					_CREATE_CHILD(tmp, node, NUMBER_INT);
					node->value.i = 0;
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
				if (ifequal(node->left, node->right))
				{
					#ifdef DEBUG_DIFF
					printf("Упрощение a-a...\n");
					#endif
					
					tree_Delete_node(node->left);
					tree_Delete_node(node->right);
					node->t = NUMBER_INT;
					node->value.i = 0;
					node->left = NULL;
					node->right = NULL;
					simplified += 1;
					
					
					#ifdef DEBUG_DIFF
					printf("...упрощение a-a выполнено.\n");
					#endif
					break;
				}
				break;
			}
			case POWER:
			{
				if (node->right->t == NUMBER_INT)
				{
					if (node->right->value.i == 1)
					{
						#ifdef DEBUG_DIFF
						printf("Упрощение выражения вида a^1...\n");
						#endif
						Node tmp = *node->left;
						free(node->right);
						*node = tmp;
						simplified += 1;
						#ifdef DEBUG_DIFF
						printf("...упрощение вида a^1 завершено.\n");
						#endif
						break;
					}
					else
					{
						if (node->right->value.i == 0)
						{
							#ifdef DEBUG_DIFF
							printf("Упрощение выражения вида a^0...\n");
							#endif
							Node* tmp = node->parent;
							tree_Delete_node(node);
							node = (Node* )calloc(1, sizeof(Node));
							node->t = NUMBER_INT;
							node->value.i = 1;
							node->left = NULL;
							node->right = NULL;
							node->parent = tmp;
							simplified += 1;
							#ifdef DEBUG_DIFF
							printf("...упрощение выражения вида a^0 завершено.\n");
							#endif
							break;
						}
					}
				}
				
				break;
			}
			default:
			{
				#ifdef DEBUG_SIMPLIFY
				printf("НЕИЗВЕТСНО, КАК УПРОЩАТЬ ОПРЕТАОРЫ [%s]\n", operator_to_string(node->value.o));
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

Node* d_s(Node* node)
{
	Node* tmp = simplify(d(node));
	simplified = 1;
	while (simplified != 0)
	{
		simplified = 0;
		tmp = simplify(tmp);
	}
	return tmp;
}

int ifequal(Node* node1, Node* node2)
{
	switch (node1->t)
	{
		case OPERATOR:
		{
			if (ifequal(node1->left, node2->left) && ifequal(node1->right, node2->right))
				return 1;
			else
				return 0;
		}
		case VARIABLE:
		{
			if (node1->value.vt == node2->value.vt)
				return 1;
			else
				return 0;
		}
		case NUMBER_INT:
		{
			if (node1->value.i == node2->value.i)
				return 1;
			else
				return 0;
		}
		case NUMBER_DOUBLE:
		{
			if (node1->value.d == node2->value.d)
				return 1;
			else
				return 0;
		}
		case CONSTANT:
		{
			if (node1->value.c == node2->value.c)
				return 1;
			else
				return 0;
		}
		default:
		{
			assert(0);
		}
	}
}
