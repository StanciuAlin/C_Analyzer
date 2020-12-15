#include "SymbolTable.h"


SymNode* createDefaultSymTableNode(char* symbolName,
	char* dataType,
	int symbolType,
	enum IdentifierScope symbolScope,
	char* contextName,
	unsigned int linksCount)
{
	SymNode* retSymNode = (SymNode*)malloc(sizeof(SymNode));

	if (retSymNode)
	{
		memset(retSymNode, 0, sizeof(SymNode));
		if (symbolName)
		{
			strcpy(retSymNode->symTableEntry.symbolName, symbolName);
		}
		if (dataType)
		{
			strcpy(retSymNode->symTableEntry.dataType, dataType);
		}
		if (symbolType)
		{
			strcpy(retSymNode->symTableEntry.symbolType, symbolType);
		}
		if (symbolScope)
		{
			strcpy(retSymNode->symTableEntry.symbolScope, symbolScope);
		}
		if (contextName)
		{
			strcpy(retSymNode->symTableEntry.contextName, contextName);
		}

		retSymNode->symTableEntry.numLinks = linksCount;
		if (linksCount > 0)
		{
			retSymNode->links = (SymNode**)malloc(linksCount * sizeof(SymNode*));
		}
	}

	return retSymNode;
}

SymNode* resizeSymTableNodeLinks(SymNode* nodeToResize, unsigned int newSize)
{
	if (nodeToResize->symTableEntry.numLinks == 0)
	{
		nodeToResize->links = (SymNode**)malloc(newSize * sizeof(SymNode*));
	}
	else
	{
		nodeToResize->links = (SymNode**)realloc(nodeToResize->links, newSize * sizeof(SymNode*));
	}
	nodeToResize->symTableEntry.numLinks = newSize;

	return nodeToResize;
}


void createSymTreeFromSyntax(Node* ast, SymNode* symTree, int level)
{
	static int symbolType;

	char symbolName[MAX_SYMBOL_NAME] = "";
	char dataType[MAX_DATATYPE_NAME] = "";
	enum IdentifierScope symbolScope;
	char contextName[MAX_SYMBOL_NAME] = "";
	int numLinks = 0;
	
	int idx = 0;
	if (ast)
	{
		if (ast->type)
		{
			strcpy(symbolName, ast->type);
			if (strstr(ast->type, "Function")) {
				/* is a function */
				symbolType = 0;
			}
			if (strstr(ast->type, "TypeSpec")) {
				/* is a variable */
				symbolType = 0;
			}
		}
		if (ast->extraData)
		{
			strcpy(dataType, ast->extraData);
		}
		if (!symbolType)
		{
			symbolScope = LOCAL;
		}
		else
		{
			symbolScope = GLOBAL;
		}
		if (symbolScope == LOCAL)
		{
			strcpy(contextName, "Local context");
		}
		else
		{
			strcpy(contextName, "Context not defined");
		}


		if (ast->numLinks)
		{
			numLinks = ast->numLinks;
		}

		for (idx = 0; idx < numLinks; idx++)
		{

			SymNode* retSymNode = createDefaultSymTableListNode(symbolName, dataType, symbolType, symbolScope, contextName, numLinks);

			symTree->links[idx] = retSymNode;

			createSymTreeFromSyntax(ast->links[idx], symTree->links[idx], level + 1);
			printf("%d   ", idx);
		}

	}
}

// functie care parcurge arborele (printAst) si preia pe rand, fiecare nod din arbore
// si il pune in arborele nou symTable
void printSymTree(SymNode* symTree, int level)
{
	int idx = 0;
	const char* scope = malloc(10);
	const char* context = malloc(10);
	const char* symbolTypeText = malloc(10);

	if (symTree)
	{
		for (idx = 0; idx < level; idx++)
		{
			printf(" ");
		}
		if (symTree->symTableEntry.symbolName)
			// && symTree->symTableEntry.dataType 
			// && symTree->symTableEntry.symbolType)
		{
			if (symTree->symTableEntry.symbolScope)
			{
				switch (symTree->symTableEntry.symbolScope)
				{
				case 0:
					strcpy(scope, "Local");
					if (symTree->symTableEntry.contextName)
					{
						strcpy(context, symTree->symTableEntry.contextName);
					}
					break;
				case 1:
					strcpy(scope, "Global");
					break;
				default:
					break;
				}
			}
			printf("Symbol ---> %s <--- with data type %s ", 
				symTree->symTableEntry.symbolName, 
				symTree->symTableEntry.dataType);
			if (symTree->symTableEntry.symbolType == 0)
			{
				strcpy(symbolTypeText, "Function");
			}
			else if (symTree->symTableEntry.dataType == 1)
			{
				strcpy(symbolTypeText, "Variable");
			}
		}
		if (symTree->symTableEntry.numLinks)
		{
			printf(" | %d descendents |\n", symTree->symTableEntry.numLinks);
		}
		else
		{
			printf(" - %s\n", "Leaf node\n");
		}
		for (idx = 0; idx < symTree->symTableEntry.numLinks; idx++)
		{
			printSymTree(symTree->links[idx], level + 1);
		}
	}
}
