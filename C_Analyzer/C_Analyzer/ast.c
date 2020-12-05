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

Node* createExternalDeclarationNode(Node* externalDeclaration)
{
	Node* retNode = createDefaultNode("ExternalDeclaration", 1);
	if (retNode)
	{
		retNode->links[0] = externalDeclaration;
	}
	if (externalDeclaration->extraData == "declaration")
	{
		sprintf(retNode->extraData, "%s", "URAAA");
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

// unused function
Node* createDeclarationSpecifiers(Node* typeSpecifier, const char* varName, int value)
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

Node* createInitDeclarator(Node* declarator, Node* initializer)
{
	Node* retNode = createDefaultNode("InitDeclarator", 2);

	if (retNode)
	{
		retNode->links[0] = declarator;
		retNode->links[1] = initializer;
	}

	return retNode;
}

Node* createDeclarator(Node* pointer, Node* directDeclarator)
{
	Node* retNode;

	if (!pointer || !directDeclarator)
	{
		retNode = createDefaultNode("Declarator", 1);
		if (pointer)
		{
			retNode->links[0] = pointer;
		}
		else
		{
			retNode->links[0] = directDeclarator;
		}
	}
	else
	{
		retNode = createDefaultNode("Declarator", 2);
		
		if (retNode)
		{
			retNode->links[0] = pointer;
			retNode->links[1] = directDeclarator;
		}
	}

	

	return retNode;
}

Node* createDirectDeclarator(Node* directDeclarator, Node* declarators)
{
	Node* retNode;
	
	if (!directDeclarator || !declarators)
	{
		retNode = createDefaultNode("DirectDeclarator", 1);
		if (directDeclarator)
		{
			retNode->links[0] = directDeclarator;
		}
		else
		{
			retNode->links[0] = declarators;
		}
	}
	else
	{
		retNode = createDefaultNode("DirectDeclarator", 2);

		if (retNode)
		{
			retNode->links[0] = directDeclarator;
			retNode->links[1] = declarators;
		}
	}

	if (directDeclarator == NULL && declarators == NULL)
	{
		sprintf(retNode->extraData, "%s", "IDENTIFIER");
	}

	return retNode;
}

Node* createInitializer(Node* initializerType)
{
	Node* retNode = createDefaultNode("Initializer", 1);
	
	if (retNode)
	{
		retNode->links[0] = initializerType;
	}

	return retNode;
}

Node* createConstantExpression(Node* conditionalExpression)
{
	Node* retNode = createDefaultNode("ConditionalExpression", 1);

	if (retNode)
	{
		retNode->links[0] = conditionalExpression;
	}

	return retNode;
}

Node* createParameterTypeList(Node* paramTypeList, int flag)
{
	Node* retNode = createDefaultNode("ParameterTypeList", 1);

	if (retNode)
	{
		retNode->links[0] = paramTypeList;
		if (flag)
		{
			sprintf(retNode->links[0]->extraData, "%s", "ELLIPSIS");
		}
	}
	
	return retNode;
}

Node* createPointer(Node* typeQualifierList, Node* pointer)
{
	Node* retNode;

	if (!typeQualifierList || !pointer)
	{
		retNode = createDefaultNode("Pointer", 1);
		if (typeQualifierList)
		{
			retNode->links[0] = typeQualifierList;
		}
		else
		{
			retNode->links[0] = pointer;
		}
	}
	else
	{
		retNode = createDefaultNode("Pointer", 2);

		if (retNode)
		{
			retNode->links[0] = typeQualifierList;
			retNode->links[1] = pointer;
		}
	}

	if (retNode)
	{
		sprintf(retNode->extraData, "%s", "Pointer");
	}

	return retNode;
}

Node* createJumpStatement(Node* expression, int selector)
{
	Node* retNode = createDefaultNode("Statement", 1);

	switch (selector)
	{
	case 1:
		retNode = createDefaultNode("JumpStatement", 0);
		if (retNode)
		{
			sprintf(retNode->extraData, "%s", "GOTO IDENTIFIER");
		}
		break;
	case 2:
		retNode = createDefaultNode("JumpStatement", 0);
		if (retNode)
		{
			sprintf(retNode->extraData, "%s", "CONTINUE");
		}
		break;
	case 3:
		retNode = createDefaultNode("JumpStatement", 0);
		if (retNode)
		{
			sprintf(retNode->extraData, "%s", "BREAK");
		}
		break;
	case 4:
		retNode = createDefaultNode("JumpStatement", 0);
		if (retNode)
		{
			sprintf(retNode->extraData, "%s", "RETURN");
		}
		break;
	case 5:
		retNode = createDefaultNode("JumpStatement", 1);
		if (retNode)
		{
			retNode->links[0] = expression;
			sprintf(retNode->extraData, "%s", "RETURN");
		}
		break;
	default:
		break;
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

Node* createNodeLeaf(const char* extraData)
{
	Node* retValue = createDefaultNode("Keyword", 0);

	if (retValue)
	{
		sprintf(retValue->extraData, "%s", extraData);
	}

	return retValue;
}

Node* createNodeOne(Node* firstNode, const char* extraData)
{
	Node* retNode = createDefaultNode(extraData, 1);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		if (extraData)
		{
			sprintf(retNode->extraData, "%s", extraData);
		}
	}

	return retNode;
}

Node* createNodeTwo(Node* firstNode, Node* secondNode, const char* extraData)
{
	Node* retNode = createDefaultNode(extraData, 2);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		retNode->links[1] = secondNode;
		if (extraData)
		{
			sprintf(retNode->extraData, "%s", extraData);
		}
	}

	return retNode;
}

Node* createNodeThree(Node* firstNode, Node* secondNode, Node* thirdNode, const char* extraData)
{
	Node* retNode = createDefaultNode(extraData, 3);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		retNode->links[1] = secondNode;
		retNode->links[2] = thirdNode;
		if (extraData)
		{
			sprintf(retNode->extraData, "%s", extraData);
		}
	}

	return retNode;
}

Node* createNodeFour(Node* firstNode, Node* secondNode, Node* thirdNode, Node* fourthNode, const char* extraData)
{
	Node* retNode = createDefaultNode(extraData, 4);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		retNode->links[1] = secondNode;
		retNode->links[2] = thirdNode;
		retNode->links[3] = fourthNode;
		if (extraData)
		{
			sprintf(retNode->extraData, "%s", extraData);
		}
	}

	return retNode;
}

Node* createNodeFive(Node* firstNode, Node* secondNode, Node* thirdNode, Node* fourthNode, Node* fifthNode, const char* extraData)
{
	Node* retNode = createDefaultNode(extraData, 5);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		retNode->links[1] = secondNode;
		retNode->links[2] = thirdNode;
		retNode->links[3] = fourthNode;
		retNode->links[4] = fifthNode;
		if (extraData)
		{
			//sprintf(retNode->extraData, "%s", extraData);
		}
	}

	return retNode;
}

Node* createTypeSpecifier(const char* typeName, Node* typeSpecifier)
{
	Node* retNode;

	if (!typeSpecifier)
	{
		retNode = createDefaultNode("TypeSpecifier", 0);

		if (typeName)
		{
			sprintf(retNode->extraData, "%s", typeName);
		}
	}
	else
	{
		retNode = createDefaultNode("TypeSpecifier", 1);

		if (retNode)
		{
			retNode->links[0] = typeSpecifier;
			if (typeName)
			{
				sprintf(retNode->extraData, "%s", typeName);
			}
		}	
	}
	
	return retNode;
}

Node* createStructOrUnionSpecifier(Node* type, Node* list)
{
	//  !!!!!!!!!!!!!!!!!!
	Node* retNode = createDefaultNode("StructOrEnum", 2);

	if (type && list)
	{
		retNode = createDefaultNode("StructOrEnum", 2);
		if (retNode)
		{
			retNode->links[0] = type;
			retNode->links[1] = list;
		}
	}
	if (!list)
	{
		retNode = createDefaultNode("StructOrEnum", 1);
		if (retNode)
		{
			retNode->links[0] = type;
		}
	}

	return retNode;
}

Node* createStructOrUnionType(const char* typeName)
{
	Node* retVal = createDefaultNode("StructOrUnion", 0);

	if (typeName)
	{
		sprintf(retVal->extraData, "%s", typeName);
	}

	return retVal;
}

Node* createEnumSpecifier(Node* enumList)
{
	Node* retNode;
	const char* typeName = "ENUM";

	if (enumList)
	{
		retNode = createDefaultNode("EnumSpecifier", 1);
		if (retNode)
		{
			retNode->links[0] = enumList;
		}
	}
	else
	{
		retNode = createDefaultNode(typeName, 0);
		/*if (retNode)
		{
			sprintf(retNode->extraData, "%s", typeName);
		}*/
	}
}

Node* createEnumerator(Node* constantExpression)
{
	Node* retNode;
	const char* typeName = "IDENTIFIER";

	if (constantExpression)
	{
		retNode = createDefaultNode("Enumerator", 1);
		if (retNode)
		{
			retNode->links[0] = constantExpression;
		}
	}
	else
	{
		retNode = createDefaultNode("Enumerator", 0);
		if (retNode)
		{
			sprintf(retNode->extraData, "%s", typeName);
		}
	}
}

Node* createTypeQualifier(const char* typeName)
{
	Node* retVal = createDefaultNode("TypeQualifier", 0);

	if (typeName)
	{
		sprintf(retVal->extraData, "%s", typeName);
	}

	return retVal;
}

Node* createStorageClassSpecifier(const char* typeName)
{
	Node* retVal = createDefaultNode("StorageClassSpecifier", 0);
	
	if (typeName)
	{
		sprintf(retVal->extraData, "%s", typeName);
	}
	
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
