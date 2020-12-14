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

// functie care parcurge arborele (printAst) si preia pe rand, fiecare nod din arbore
// si il pune in arborele nou symTable