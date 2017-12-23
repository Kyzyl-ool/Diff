#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Diff.h"

int main()
{
	tree* t1 = tree_Read_DED("expr.ded");
	tree* t2 = tree_Construct("Unnamed");
	
	tree_Print_GML(t1, "expr1.gml");
	
	t2->root = d(t1->root);
	
	
	tree_Print_GML(t2, "expr2.gml");
	Make_Report(t1->root, "test.tex");
	Make_Report(t2->root, "test_diff.tex");
	
	
	tree_Destroy(t1);
	tree_Destroy(t2);
	
	return 0;
}
