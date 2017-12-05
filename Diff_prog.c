#include <stdio.h>
#include "Diff.h"

int main()
{
	tree* t = tree_Read_DED("expr.ded");
	
	tree_Print_GML(t, "expr.gml");
	
	tree_Destroy(t);
	return 0;
}
