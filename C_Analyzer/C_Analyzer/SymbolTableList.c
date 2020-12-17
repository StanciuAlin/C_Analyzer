#include "SymbolTableList.h"


SymTableEntry createDefaultSymTableListNode(char* symbolName,
	char* dataType,
	int symbolType,
	enum IdentifierScope symbolScope,
	char* contextName,
	unsigned int linksCount)
{
	SymTableEntry retSymListNode;

	if (symbolName)
	{
		strcpy(retSymListNode.symbolName, symbolName);
	}
	if (dataType)
	{
		strcpy(retSymListNode.dataType, dataType);
	}
	if (symbolType)
	{
		strcpy(retSymListNode.symbolType, symbolType);
	}
	if (symbolScope)
	{
		strcpy(retSymListNode.symbolScope, symbolScope);
	}
	if (contextName)
	{
		strcpy(retSymListNode.contextName, contextName);
	}

	retSymListNode.numLinks = linksCount;


	return retSymListNode;
}


void insertSymNodeInList(SymTableEntry symNode)
{
	//symTableEntryList = realloc(++lengthList, lengthList * sizeof(SymTableEntry));
	symTableEntryList[lengthList++] = symNode;
}

void createSymTreeFromSyntaxList(Node* ast, int level)
{
	int flagInsert = 0;

	//static int symbolType;

	/*char symbolName[MAX_SYMBOL_NAME] = "";
	char dataType[MAX_DATATYPE_NAME] = "";
	enum IdentifierScope symbolScope;
	char contextName[MAX_SYMBOL_NAME] = "";
	int numLinks = 0;*/

	SymTableEntry retSymListNode;
	
	int idx = 0;
	if (ast)
	{
		if (ast->type)
		{
			strcpy(retSymListNode.symbolName, ast->type);
			if (strstr(ast->type, "Function")) {
				/* is a function */
				retSymListNode.symbolType = 0;
				flagInsert = 1;
			}
			if (strstr(ast->type, "TypeSpec")) {
				/* is a variable */
				retSymListNode.symbolType = 1;
				flagInsert = 1;
			}
		}
		if (ast->extraData)
		{
			strcpy(retSymListNode.dataType, ast->extraData);
		}
		if (!retSymListNode.symbolType)
		{
			retSymListNode.symbolScope = LOCAL;
		}
		else
		{
			retSymListNode.symbolScope = GLOBAL;
		}
		if (retSymListNode.symbolScope == LOCAL)
		{
			strcpy(retSymListNode.contextName, "Local context");
		}
		else
		{
			strcpy(retSymListNode.contextName, "Context not defined - Global");
		}


		if (ast->numLinks)
		{
			retSymListNode.numLinks = ast->numLinks;
		}

		if (flagInsert)
		{
			//SymTableEntry retSymListNode = createDefaultSymTableListNode(symbolName, dataType, symbolType, symbolScope, contextName, numLinks);

			insertSymNodeInList(retSymListNode);
		}
		for (idx = 0; idx < retSymListNode.numLinks; idx++)
		{
			createSymTreeFromSyntaxList(ast->links[idx], level + 1);
		}

	}
}

void printSymNodeList()
{
	int it;
	printf("\n");
	/* Header */
	printf("%-50s %-50s %-20s %-20s %-30s %-20s\n",
		"__________________________________________________",
		"__________________________________________________",
		"____________________",
		"____________________",
		"______________________________",
		"____________________"
	);
	printf("%-50s %-50s %-20s %-20s %-30s %-10s\n",
		"Symbol Name",
		"Data Type",
		"Symbol Type",
		"Symbol Scope",
		"Context Name",
		"Number of links"
	);
	printf("%-50s %-50s %-20s %-20s %-30s %-20s\n",
		"__________________________________________________",
		"__________________________________________________",
		"____________________",
		"____________________",
		"______________________________",
		"____________________"
	);
	printf("\n");
	for (it = 0; it < lengthList; it++)
	{
		printf("%-50s %-50s %-20d %-20d %-30s %-10d\n",
			symTableEntryList[it].symbolName,
			symTableEntryList[it].dataType,
			symTableEntryList[it].symbolType,
			symTableEntryList[it].symbolScope,
			symTableEntryList[it].contextName,
			symTableEntryList[it].numLinks
		);
	}

	printf("%-50s %-50s %-20s %-20s %-30s %-20s\n",
		"__________________________________________________",
		"__________________________________________________",
		"____________________",
		"____________________",
		"______________________________",
		"____________________"
	);
}

// functie care parcurge arborele (printAst) si preia pe rand, fiecare nod din arbore
// si il pune in arborele nou symTable
//void printSymTree(SymNode* symTree, int level)
//{
//	int idx = 0;
//	const char* scope = malloc(10);
//	const char* context = malloc(10);
//	const char* symbolTypeText = malloc(10);
//
//	if (symTree)
//	{
//		for (idx = 0; idx < level; idx++)
//		{
//			printf(" ");
//		}
//		if (symTree->symTableEntry.symbolName)
//			// && symTree->symTableEntry.dataType 
//			// && symTree->symTableEntry.symbolType)
//		{
//			if (symTree->symTableEntry.symbolScope)
//			{
//				switch (symTree->symTableEntry.symbolScope)
//				{
//				case 0:
//					strcpy(scope, "Local");
//					if (symTree->symTableEntry.contextName)
//					{
//						strcpy(context, symTree->symTableEntry.contextName);
//					}
//					break;
//				case 1:
//					strcpy(scope, "Global");
//					break;
//				default:
//					break;
//				}
//			}
//			printf("Symbol ---> %s <--- with data type %s ", 
//				symTree->symTableEntry.symbolName, 
//				symTree->symTableEntry.dataType);
//			if (symTree->symTableEntry.symbolType == 0)
//			{
//				strcpy(symbolTypeText, "Function");
//			}
//			else if (symTree->symTableEntry.dataType == 1)
//			{
//				strcpy(symbolTypeText, "Variable");
//			}
//		}
//		if (symTree->symTableEntry.numLinks)
//		{
//			printf(" | %d descendents |\n", symTree->symTableEntry.numLinks);
//		}
//		else
//		{
//			printf(" - %s\n", "Leaf node\n");
//		}
//		for (idx = 0; idx < symTree->symTableEntry.numLinks; idx++)
//		{
//			printSymTree(symTree->links[idx], level + 1);
//		}
//	}
//}
