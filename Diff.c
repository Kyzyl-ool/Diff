#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Diff.h"

#define DEBUG_DIFF
#define DEBUG_SIMPLIFY

#define _CREATE_CHILD(the_parent, the_node, the_type) Node* the_node = (Node* )calloc(1, sizeof(Node)); the_node->parent = the_parent; the_node->t = the_type; the_node->left = NULL; the_node->right = NULL;
#define _CREATE_CHILD_OPERATOR(the_parent, the_node, the_value) Node* the_node = (Node* )calloc(1, sizeof(Node)); the_node->parent = the_parent; the_node->t = OPERATOR; the_node->left = NULL; the_node->right = NULL; the_node->value.o = the_value;

#define _SET_CHILD(the_parent, who_is_left, who_is_right) the_parent->left = (Node* )calloc(1, sizeof(Node)); the_parent->right = (Node* )calloc(1, sizeof(Node)); the_parent->left->parent = the_parent; the_parent->right->parent = the_parent; the_parent->left = who_is_left; the_parent->right = who_is_right;
#define _SET_CHILD_LEFT(the_parent, who_is_left) the_parent->left = (Node* )calloc(1, sizeof(Node)); the_parent->left->parent = the_parent; the_parent->left = who_is_left;
#define _SET_CHILD_RIGHT(the_parent, who_is_right) the_parent->right = (Node* )calloc(1, sizeof(Node)); the_parent->right->parent = the_parent; the_parent->right = who_is_right;

#define _SET_NEWCHILD_OPERATOR(the_parent, left_or_right, the_value) the_parent->left_or_right = (Node* )calloc(1, sizeof(Node)); the_parent->left_or_right->parent = the_parent; the_parent->left_or_right->t = OPERATOR; the_parent->left_or_right->left = NULL; the_parent->left_or_right->right = NULL; the_parent->left_or_right->value.o = the_value;
#define _SET_NEWCHILD_INTEGER(the_parent, left_or_right, the_value) the_parent->left_or_right = (Node* )calloc(1, sizeof(Node)); the_parent->left_or_right->parent = the_parent; the_parent->left_or_right->t = NUMBER_INT; the_parent->left_or_right->left = NULL; the_parent->left_or_right->right = NULL; the_parent->left_or_right->value.i = the_value;
#define _SET_NEWCHILD_DOUBLE(the_parent, left_or_right, the_value) the_parent->left_or_right = (Node* )calloc(1, sizeof(Node)); the_parent->left_or_right->parent = the_parent; the_parent->left_or_right->t = NUMBER_DOUBLE; the_parent->left_or_right->left = NULL; the_parent->left_or_right->right = NULL; the_parent->left_or_right->value.d = the_value;


Node* d(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Вызвана фунцкия d с типом [%s]...\n", type_to_string(node->t));
	#endif
	switch (node->t)
	{
		case NUMBER_DOUBLE:
		case NUMBER_INT:
		case CONSTANT:
		{
			return diff_Const(node);
		}
		case VARIABLE:
		{
			return diff_Variable(node);
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
					return diff_Multiply(node);
				}
				case PLUS:
				{
					return diff_Addition(node);
				}
				case POWER:
				{
					if (if_depends_on_variable(node->right))
					{
						return diff_Exponential_function(node);
					}
					else
					{
						//return diff_Power_function(node);
						return d_complex_function(node, diff_Power_function, node->left);
					}
				}
				case DIVIDE:
				{
					return diff_Division(node);
				}
				case MINUS:
				{
					return diff_Difference(node);
					//return d_complex_function(node, diff_Difference);
				}
				case SIN:
				{
					return diff_Sin(node);
				}
				case COS:
				{
					return diff_Cos(node);
				}
				case TAN:
				{
					return diff_Tan(node);
				}
				case SINH:
				{
					return diff_Sinh(node);
				}
				case COSH:
				{
					return diff_Cosh(node);
				}
				case TANH:
				{
					return diff_Tanh(node);
				}
				case LN:
				{
					return diff_Ln_function(node);
				}
				case LOG:
				{
					return diff_Logarithmic_function(node);
				}
				default:
				{
					printf("НЕ РЕАЛИЗОВАНО ВЗЯТИЕ ПРОИЗВОДНОЙ ДЛЯ [%s]\n", operator_to_string(node->value.o));
					assert(0);
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
	
	assert(0);
}

Node* c(Node* node)
{
	Node* copy = (Node* )calloc(1, sizeof(Node));
	*copy = *node;
	if (node->left)
		{
			copy->left = (Node* )calloc(1, sizeof(Node));
			*copy->left = *node->left;
		}
	if (node->right)
	{
			copy->right = (Node* )calloc(1, sizeof(Node));
			*copy->right = *node->right;
	}
		
	return copy;
}

Node* c_parent(Node* node)
{
	Node* copy = (Node* )calloc(1, sizeof(Node));
	*copy = *node;
	if (node->left)
		{
			copy->left = (Node* )calloc(1, sizeof(Node));
			*copy->left = *node->left;
		}
	if (node->right)
	{
			copy->right = (Node* )calloc(1, sizeof(Node));
			*copy->right = *node->right;
	}
	
	copy->parent = node->parent;
		
	return copy;
}

int if_depends_on_variable(Node* node)
{
	if (node->t == VARIABLE)
		return 1;
	
	if (node->left && if_depends_on_variable(node->left) == 1)
			return 1;
	
	if (node->right && if_depends_on_variable(node->right) == 1)
			return 1;
	
	return 0;
}

Node* diff_Const(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Берется производная числа...\n");
	#endif
			
	_CREATE_CHILD(node->parent, new_node, NUMBER_INT)
	new_node->value.i = 0;
	
	#ifdef DEBUG_DIFF
	printf("...производная числа взята.\n");
	#endif
	return new_node;
}

Node* diff_Variable(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Берется производная переменной...\n");
	#endif
			

	_CREATE_CHILD(node->parent, new_node, NUMBER_INT)
	new_node->value.i = 1;
	#ifdef DEBUG_DIFF
	printf("... производная переменной взята.\n");
	#endif
	
	return new_node;
}

Node* diff_Multiply(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Берется производная умножения...\n");
	#endif
				
	_CREATE_CHILD_OPERATOR(node->parent, new_node, PLUS)
	_SET_NEWCHILD_OPERATOR(new_node, left, MULTIPLY)
	_SET_NEWCHILD_OPERATOR(new_node, right, MULTIPLY)
	
	_SET_CHILD(new_node->left, d(node->left), c_parent(node->right))
	_SET_CHILD(new_node->right, c_parent(node->left), d(node->right))
		
	#ifdef DEBUG_DIFF
	printf("... производная умножения взята.\n");
	#endif
	return new_node;
}

Node* diff_Division(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Берется производная частного...\n");
	#endif
					
					

	#define u node->left
	#define v node->right
	
	_CREATE_CHILD_OPERATOR(node->parent, new_node, DIVIDE)
	
	_SET_NEWCHILD_OPERATOR(new_node, left, MINUS)
	_SET_NEWCHILD_OPERATOR(new_node, right, POWER)
	
	_SET_NEWCHILD_OPERATOR(new_node->left, left, MULTIPLY)
	_SET_NEWCHILD_OPERATOR(new_node->left, right, MULTIPLY)
	
	_SET_CHILD_LEFT(new_node->right, c_parent(v))
	_SET_NEWCHILD_INTEGER(new_node->right, right, 2);
	
	_SET_CHILD(new_node->left->left, d(u), c_parent(v))
	
	_SET_CHILD(new_node->left->right, c_parent(u), d(v))
	
	#undef u
	#undef v
	#ifdef DEBUG_DIFF
	printf("...взятие производной частного завершено.\n");
	#endif
	return new_node;
}

Node* diff_Addition(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Берётся производная сложения...\n");
	#endif
					
	#define u node->left
	#define v node->right
	_CREATE_CHILD_OPERATOR(node->parent, new_node, PLUS)
	_SET_CHILD(new_node, d(u), d(v))
	
	#undef u
	#undef v
	
	
	#ifdef DEBUG_DIFF
	printf("... производная сложения взята.\n");
	#endif
	return new_node;
}

Node* diff_Difference(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной разности...\n");
	#endif
	
	#define u node->left
	#define v node->right
	_CREATE_CHILD_OPERATOR(node->parent, new_node, MINUS)
	_SET_CHILD(new_node, d(u), d(v))
	
	#undef u
	#undef v
	
	#ifdef DEBUG_DIFF
	printf("...взятие производной разности завершено.\n");
	#endif
	return new_node;
}

Node* diff_Sin(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной sin...\n");
	#endif
	_CREATE_CHILD_OPERATOR(node->parent, new_node, COS)
	_SET_CHILD_LEFT(new_node, c_parent(node->left))
	
	#ifdef DEBUG_DIFF
	printf("...производная sin взята.\n");
	#endif
	return new_node;
}

Node* diff_Cos(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной cos..\n");
	#endif
	_CREATE_CHILD_OPERATOR(node->parent, new_node, MULTIPLY)
	
	_SET_NEWCHILD_INTEGER(new_node, left, -1)
	
	_SET_NEWCHILD_OPERATOR(new_node, right, SIN)
	
	_SET_CHILD_LEFT(new_node->right, c_parent(node->left))
	
	
	#ifdef DEBUG_DIFF
	printf("...производная cos взята.\n");
	#endif
	return new_node;
}

Node* diff_Tan(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной tan...\n");
	#endif
	
	
	assert(0);
	
	#ifdef DEBUG_DIFF
	printf("...производная tan взята.\n");
	#endif
}

Node* diff_Sinh(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной sinh...\n");
	#endif
	assert(0);
	
	#ifdef DEBUG_DIFF
	printf("...производная sinh взята.\n");
	#endif
}

Node* diff_Cosh(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной cosh...\n");
	#endif
	assert(0);
	
	#ifdef DEBUG_DIFF
	printf("...производная cosh взята.\n");
	#endif
}

Node* diff_Tanh(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной tanh...\n");
	#endif
	assert(0);
	
	#ifdef DEBUG_DIFF
	printf("...производная tanh взята.\n");
	#endif
}

Node* diff_Power_function(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной степенной функции...\n");
	#endif
						

	_CREATE_CHILD_OPERATOR(node->parent, new_node, MULTIPLY)
	
	_SET_CHILD_LEFT(new_node, c_parent(node->right))
	
	_SET_NEWCHILD_OPERATOR(new_node, right, POWER)
	
	_SET_CHILD_LEFT(new_node->right, c_parent(node->left))
	
	_SET_NEWCHILD_OPERATOR(new_node->right, right, MINUS)
	
	_SET_CHILD_LEFT(new_node->right->right, c_parent(node->right))
	_SET_NEWCHILD_INTEGER(new_node->right->right, right, 1)
	
	#ifdef DEBUG_DIFF
	printf("...взятие производной степенной функции завершено.\n");
	#endif
	return new_node;
}

Node* diff_Exponential_function(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной показательной функции...\n");
	#endif
						
	#define f node->left
	#define g node->right
	
	_CREATE_CHILD_OPERATOR(node->parent, new_node, MULTIPLY)
	_SET_CHILD_RIGHT(new_node, c_parent(node))
	_SET_NEWCHILD_OPERATOR(new_node, left, PLUS)
	
	_SET_NEWCHILD_OPERATOR(new_node->left, left, MULTIPLY)
	_SET_NEWCHILD_OPERATOR(new_node->left, right, MULTIPLY)
	
	_SET_NEWCHILD_OPERATOR(new_node->left->left, left, DIVIDE)
	_SET_CHILD_RIGHT(new_node->left->left, d(f))
	
	_SET_CHILD(new_node->left->left->left, g, f)
	
	_SET_CHILD_LEFT(new_node->left->right, d(g))
	_SET_NEWCHILD_OPERATOR(new_node->left->right, right, LN)
	
	_SET_CHILD_LEFT(new_node->left->right->right, c_parent(f))
	
	#undef f
	#undef g
	
	#ifdef DEBUG_DIFF
	printf("..производная показательной функции взята.\n");
	#endif
	return new_node;
}

Node* diff_Ln_function(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной натурального логарифма...\n");
	#endif
	_CREATE_CHILD_OPERATOR(node->parent, new_node, DIVIDE)
	
	_SET_NEWCHILD_INTEGER(new_node, left, 1)
	
	_SET_CHILD_RIGHT(new_node, node->left)
	
	#ifdef DEBUG_DIFF
	printf("...производная натурального логарифма взята.\n");
	#endif
	return new_node;
}

Node* diff_Logarithmic_function(Node* node)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной логарифма...\n");
	#endif
	_CREATE_CHILD_OPERATOR(node->parent, new_node, DIVIDE)
	
	_SET_NEWCHILD_INTEGER(new_node, left, 1)
	
	_SET_NEWCHILD_OPERATOR(new_node, right, MULTIPLY)
	
	_SET_CHILD_LEFT(new_node->right, c_parent(node->left))
	
	
	_SET_NEWCHILD_OPERATOR(new_node->right, right, LN)
	
	_SET_CHILD_LEFT(new_node->right->right, c_parent(node->right))
	
	
	#ifdef DEBUG_DIFF
	printf("...производная логарифма взята.\n");
	#endif
	return new_node;
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
					_CREATE_CHILD(tmp, node, NUMBER_INT)
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

Node* simplifyfy(Node* node)
{
	Node* tmp = simplify(node);
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



Node* d_complex_function(Node* node, Node* (*diff)(Node* node), Node* argument)
{
	#ifdef DEBUG_DIFF
	printf("Взятие производной сложной функции...\n");
	#endif
	_CREATE_CHILD_OPERATOR(node->parent, new_node, MULTIPLY)
	_SET_CHILD(new_node, diff(node), d(argument))
	
	#ifdef DEBUG_DIFF
	printf("...взятие производной сложной функции завершено.\n");
	#endif
	return new_node;
}
