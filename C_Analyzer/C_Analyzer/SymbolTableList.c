#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SymbolTableList.h"

void AnalyzeCode()
{
	for (int i = 0; i < lengthList; i++)
	{
		
	}
}

char* getDataType(const char* symbolName, const char* context)
{
	for (int i = 0; i < lengthList; i++)
	{
		if (!strcmp(symTableEntryList[i].contextName, context))
		{
			if (!strcmp(symTableEntryList[i].symbolName, symbolName))
			{
				return symTableEntryList[i].dataType;
			}
		}
	}
}

/* check if a variable is declared more than one time in the same context */
int checkDoubleDecl(const char* symbolName, const char* context, int symbolType)
{
	int isDoubleDecl = 0;

	for (int i = 0; i < lengthList; i++)
	{
		if (!strcmp(symTableEntryList[i].contextName, context))
		{
			if (!strcmp(symTableEntryList[i].symbolName, symbolName))
			{
				if (symTableEntryList[i].symbolType == 1 && symbolType == 1)
				{
					isDoubleDecl = 1;
				}
			}
		}
	}
	if (isDoubleDecl)
	{
		return 1;
	}
	return 0;
}

void insertSymNodeInList(SymTableEntry symNode)
{
	char errorMessageRedeclaration[MAX_SYMBOL_NAME] = "Redeclaration of variable ";
	if (!checkDoubleDecl(symNode.symbolName, symNode.contextName, symNode.symbolType))
	{
		symTableEntryList[lengthList++] = symNode;
	}
	else 
	{
		strcat(errorMessageRedeclaration, symNode.symbolName);
		errorsList[lengthErrorsList].errorDescription = malloc(sizeof(char) * MAX_SYMBOL_NAME);
		errorsList[lengthErrorsList].errorContext = malloc(sizeof(char) * MAX_SYMBOL_NAME);
		if (errorsList[lengthErrorsList].errorDescription)
		{
			strcpy(errorsList[lengthErrorsList].errorDescription, errorMessageRedeclaration);
			if (errorsList[lengthErrorsList].errorContext)
			{
				strcpy(errorsList[lengthErrorsList].errorContext, symNode.contextName);
			}
			errorsList[lengthErrorsList].errorCode = 1;
			lengthErrorsList++;
		}
		/*printf("\nError 1: Redeclaration of variable %s in context %s and symType %d", symNode.symbolName, 
			symNode.contextName,
			symNode.symbolType);*/
		//exit(0);
	}
	
}

void createSymListFromSyntaxTree(Node* ast, int level)
{
	char errorMessageNoDeclaration[MAX_SYMBOL_NAME] = "Implicit declaration of variable ";
	int flagInsert = 0;
	int idx = 0;

	static char context[MAX_LEN_STRING] = "GLOBAL";
	static char dataType[MAX_LEN_STRING] = "";
	static int isExpr = 0;

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
			if (strstr(ast->type, "Expr"))
			{
				isExpr = 1;
			}

			if (strstr(ast->type, "DirectDeclarator")
				&& strstr(ast->extraData.extra, "( )"))
			{
				strcpy(retSymListNode.symbolName, ast->links[0]->extraData.production);

				strcpy(context, ast->links[0]->extraData.production);

				/* is a function */
				retSymListNode.symbolType = 0;

				flagInsert = 1;

				strcpy(retSymListNode.contextName, context);
			}
			else if (strstr(ast->type, "DirectDeclarator") 
				&& strstr(ast->extraData.extra, "IDENTIFIER"))
			{
				/* is a variable */
				retSymListNode.symbolType = 1;

				strcpy(retSymListNode.symbolName, ast->extraData.production);

				flagInsert = 1;

				strcpy(retSymListNode.contextName, context);	
			}

			if (isExpr)
			{
				isExpr = 0;
				char* ex = getDataType(retSymListNode.symbolName, retSymListNode.contextName);
				//printf("+++++++++ %s +++++++++", );
				if (strstr(ast->type, "PrimaryExpr"))
				{
					strcpy(retSymListNode.symbolName, ast->extraData.production);
					strcpy(retSymListNode.contextName, context);
				}
				if (!checkDoubleDecl(retSymListNode.symbolName, retSymListNode.contextName, 1))
				{
					if (strcmp(retSymListNode.symbolName, ""))
					{
						strcat(errorMessageNoDeclaration, retSymListNode.symbolName);
						errorsList[lengthErrorsList].errorDescription = malloc(sizeof(char) * MAX_SYMBOL_NAME);
						errorsList[lengthErrorsList].errorContext = malloc(sizeof(char) * MAX_SYMBOL_NAME);
						if (errorsList[lengthErrorsList].errorDescription)
						{
							strcpy(errorsList[lengthErrorsList].errorDescription, errorMessageNoDeclaration);
							if (errorsList[lengthErrorsList].errorContext)
							{
								strcpy(errorsList[lengthErrorsList].errorContext, retSymListNode.contextName);
							}
							errorsList[lengthErrorsList].errorCode = 2;
							lengthErrorsList++;
						}
					}
				}
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

void printErrorsList()
{
	printf("%-11s %-70s %-30s\n",
		"__________",
		"_____________________________________________________________________",
		"__________________________________________________"
	);
	printf("%-11s %-70s %-30s\n",
		"Code",
		"Description",
		"Context"
	);
	printf("%-11s %-70s %-30s\n",
		"__________",
		"_____________________________________________________________________",
		"__________________________________________________"
	);

	for (int i = 0; i < lengthErrorsList; i++)
	{
		printf("Error %-11d %-70s %-30s\n", errorsList[i].errorCode, 
			errorsList[i].errorDescription,
			errorsList[i].errorContext);
	}

	printf("%-11s %-70s %-30s\n",
		"__________",
		"_____________________________________________________________________",
		"__________________________________________________"
	);
}