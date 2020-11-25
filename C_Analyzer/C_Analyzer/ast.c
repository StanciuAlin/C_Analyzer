#include "ast.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
Node* createDefaultNode(const char* nodeName, unsigned int linksCount)
{
	Node* retNode = (Node*)malloc(sizeof(Node));
	if (retNode)
	{
		memset(retNode, 0, sizeof(Node));
		if (nodeName)
		{
			strcpy(retNode->type, nodeName);
		}
		retNode->numLinks = linksCount;
		if (linksCount > 0)
		{
			retNode->links = (Node**)malloc(linksCount * sizeof(Node*));
		}
	}
	return retNode;
}

Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize)
{
	if (nodeToResize->numLinks == 0)
	{
		nodeToResize->links = (Node**)malloc(newSize*sizeof(Node*));		
	}
	else
	{
		nodeToResize->links = (Node**)realloc(nodeToResize->links, newSize * sizeof(Node*));
	}
	nodeToResize->numLinks = newSize;
	return nodeToResize;
}

Node* createListNode(const char* listName, Node* firstLink)
{
	Node* retNode = createDefaultNode(listName, 1);
	retNode->links[0] = firstLink;
	return retNode;
}
void addLinkToList(Node* listNode, Node* linkToAdd)
{
	unsigned int numLinks = listNode->numLinks;	
	resizeNodeLinks(listNode, numLinks + 1);
	listNode->links[numLinks] = linkToAdd;
}

Node* createTranslationUnitNode(Node* declaration)
{
	Node* retNode = createDefaultNode("TranslationUnit", 1);
	if (retNode)
	{
		retNode->links[0] = declaration;
	}

	return retNode;

}

Node* createExternalDeclarationNode(Node* varFunDeclaration)
{
	Node* retNode = createDefaultNode("ExteranalDeclaration", 1);
	if (retNode)
	{
		retNode->links[0] = varFunDeclaration;
	}
	return retNode;
}

Node* createFunctionDeclarationNode(Node* typeSpecifier, const char* functionName, Node* paramsList, Node* compoundStatement)
{
	
	Node* retNode = createDefaultNode("FunctionDefinition", 3);
	
	if (retNode)
	{
		retNode->links[0] = typeSpecifier;
		retNode->links[1] = paramsList;
		retNode->links[2] = compoundStatement;
		if (functionName)
		strcpy(retNode->extraData, functionName);
	}

	return retNode;
}

Node* createVarDeclaration(Node* typeSpecifier, const char* varName, int value)
{
	Node* retNode = createDefaultNode("VariableDeclaration", 2);

	if (retNode)
	{
		retNode->links[0] = typeSpecifier;	
		if (varName)
			sprintf(retNode->extraData, "%s", varName);
		retNode->links[1] = createDefaultNode("IntValue", 0);		
		sprintf(retNode->links[1]->extraData, "%d", value);
	}

	return retNode;

}

Node* createStatement(Node* statement)
{
	Node* retNode = createDefaultNode("Statement", 1);
	
	if (retNode)
	{
		retNode->links[0] = statement;
	}
	return retNode;
}

Node* createLabeledStatement(const char* labelName, Node* constStatement, Node* statement)
{
	Node* retNode = createDefaultNode("LabeledStatement", 3);

	if (retNode)
	{
		retNode->links[0] = constStatement;
		if (labelName)
		{
			sprintf(retNode->extraData, "%s", labelName);
		}
		retNode->links[1] = createDefaultNode("Statement", 1);
		//sprintf(retNode->links[1]->extraData, "%d", value);
	}

	return retNode;
}

Node* createCompoundStatement(Node* localDeclList, Node* instructionsList)
{
	Node* retNode = createDefaultNode("CompoundStatement", 2);
	
	retNode->links[0] = localDeclList;
	retNode->links[1] = instructionsList;
	
	return retNode;
}

Node* createExpressionStatement(Node* expression)
{
	Node* retNode = createDefaultNode("Expression", 1);

	if (retNode)
	{
		retNode->links[0] = expression;
	}

	return retNode;
}

Node* createIfStatement(Node* expresionIf, Node* thenStatement, Node* elseStatement) 
{
	// in my case, I can not put an identifier between '(' and ')'

	Node* retNode = createDefaultNode("IfStatement", 3);
	
	retNode->links[0] = expresionIf;
	retNode->links[1] = thenStatement;
	retNode->links[2] = elseStatement;

	return retNode;
}

Node* createSwitchStatement(Node* expresionSwitch, Node* statement)
{
	Node* retNode = createDefaultNode("SwitchStatement", 2);

	retNode->links[0] = expresionSwitch;
	retNode->links[1] = statement;

	return retNode;
}

Node* createWhileStatement(Node* statement, Node* expresionWhile)
{
	Node* retNode = createDefaultNode("WhileStatement", 2);

	retNode->links[0] = expresionWhile;
	retNode->links[1] = statement;

	return retNode;
}

Node* createDoWhileStatement(Node* expresionDoWhile, Node* statement)
{
	Node* retNode = createDefaultNode("DoWhileStatement", 2);

	retNode->links[0] = expresionDoWhile;
	retNode->links[1] = statement;

	return retNode;
}

Node* createForStatement(Node* initForExpression, Node* cyclicCondition, Node* stepFor, Node* statement)
{
	Node* retNode = createDefaultNode("ForStatement", 4);

	retNode->links[0] = initForExpression;
	retNode->links[1] = cyclicCondition;
	retNode->links[2] = stepFor;
	retNode->links[3] = statement;

	return retNode;
}

Node* createTypeSpecifier(const char* typeName)
{
	Node* retVal = createDefaultNode("TypeSpecifier", 0);
	if (typeName)
	sprintf(retVal->extraData, "%s", typeName);
	return retVal;
}

void printAst(Node* ast, int level)
{
	int idx = 0;
	if (ast)
	{
		for (idx = 0; idx < level; idx++)
		{
			printf(" ");
		}
		if (ast->type)
		{
			printf("%s ", ast->type);
		}
		if (ast->numLinks)
		{
			printf(" - %d - %s\n", ast->numLinks, ast->extraData);
		}
		else
		{
			printf(" - %s\n",  ast->extraData);
		}
		for (idx = 0; idx < ast->numLinks; idx++)
		{
			
			printAst(ast->links[idx], level + 1);			
		}
	}
}
