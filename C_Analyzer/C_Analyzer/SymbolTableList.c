#include <stdio.h>
#include <string.h>

#include "SymbolTableList.h"

void insertSymNodeInList(SymTableEntry symNode)
{
	symTableEntryList[lengthList++] = symNode;
}

void createSymListFromSyntaxTree(Node* ast, int level)
{
	int flagInsert = 0;
	int idx = 0;
	static char context[MAX_LEN_STRING] = "GLOBAL";
	static char dataType[MAX_LEN_STRING] = "";

	SymTableEntry retSymListNode;
	/* init the new list node */
	strcpy(retSymListNode.symbolName, "");
	strcpy(retSymListNode.dataType, "");
	retSymListNode.symbolType = -1;
	retSymListNode.symbolScope = UNDEFINED_SCOPE;
	strcpy(retSymListNode.contextName, "");
	retSymListNode.numLinks = 0;
	
	if (ast)
	{
		if (ast->type)
		{
			if (strstr(ast->type, "TypeSpec"))
			{
				strcpy(dataType, ast->extraData.production);
			}
			if (strstr(ast->type, "DirectDeclarator")
				&& strstr(ast->extraData.extra, "( )"))
			{
				strcpy(retSymListNode.symbolName, ast->links[0]->extraData.production);

				strcpy(context, ast->links[0]->extraData.production);
				/* is a function */
				retSymListNode.symbolType = 0;

				flagInsert = 1;
			}
			else if (strstr(ast->type, "DirectDeclarator") 
				&& strstr(ast->extraData.extra, "IDENTIFIER"))
			{
				/* is a function */
				retSymListNode.symbolType = 1;
				strcpy(retSymListNode.symbolName, ast->extraData.production);
				flagInsert = 1;
			}
			
			
		}
		if (retSymListNode.symbolType == 0
			|| retSymListNode.symbolType == 1)
		{
			strcpy(retSymListNode.dataType, dataType);
		}
		if (!retSymListNode.symbolType)
		{
			retSymListNode.symbolScope = LOCAL;	
		}
		else
		{
			retSymListNode.symbolScope = GLOBAL;
		}
		strcpy(retSymListNode.contextName, context);

		if (ast->numLinks)
		{
			retSymListNode.numLinks = ast->numLinks;
		}

		if (flagInsert)
		{
			insertSymNodeInList(retSymListNode);
		}
		for (idx = 0; idx < retSymListNode.numLinks; idx++)
		{
			createSymListFromSyntaxTree(ast->links[idx], level + 1);
		}

	}
}

void printSymNodeList()
{
	unsigned int it;
	printf("\n");
	/* Header */
	printf("%-50s %-50s %-20s %-20s %-30s\n",
		"__________________________________________________",
		"__________________________________________________",
		"____________________",
		"____________________",
		"______________________________"
	);
	printf("%-50s %-50s %-20s %-20s %-30s\n",
		"Symbol Name",
		"Data Type",
		"Symbol Type",
		"Symbol Scope",
		"Context Name"
	);
	printf("%-50s %-50s %-20s %-20s %-30s\n",
		"__________________________________________________",
		"__________________________________________________",
		"____________________",
		"____________________",
		"______________________________"
	);
	printf("\n");
	for (it = 0; it < lengthList; it++)
	{
		printf("%-50s %-50s %-20d %-20d %-30s\n",
			symTableEntryList[it].symbolName,
			symTableEntryList[it].dataType,
			symTableEntryList[it].symbolType,
			symTableEntryList[it].symbolScope,
			symTableEntryList[it].contextName
		);
	}

	printf("%-50s %-50s %-20s %-20s %-30s\n",
		"__________________________________________________",
		"__________________________________________________",
		"____________________",
		"____________________",
		"______________________________"
	);
}