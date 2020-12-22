#include "ast.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
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

Node* createNodeLeafForConstant(const char* nodeName,
	const char* extraData, 
	const int valueConst)
{
	Node* retValue = createDefaultNode(nodeName, 0);
	const char* intValToString = malloc(sizeof(char) * MAX_LEN_STRING);

	if (intValToString)
	{
		itoa(valueConst, intValToString, 10);
	}

	if (retValue)
	{
		if (extraData)
		{
			sprintf(retValue->extraData.extra, "%s", intValToString);
		}
	}

	return retValue;
}

Node* createNodeLeaf(const char* nodeName,
	const char* production,
	const char* extraData)
{
	Node* retValue = createDefaultNode(nodeName, 0);

	if (retValue)
	{
		if (production)
		{
			sprintf(retValue->extraData.production, "%s", production);
		}

		if (extraData)
		{
			sprintf(retValue->extraData.extra, "%s", extraData);
		}
	}

	return retValue;
}

Node* createNodeOne(Node* firstNode, 
	const char* nodeName,
	const char* production,
	const char* extraData)
{
	Node* retNode = createDefaultNode(nodeName, 1);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		if (production)
		{
			sprintf(retNode->extraData.production, "%s", production);
		}

		if (extraData)
		{
			sprintf(retNode->extraData.extra, "%s", extraData);
		}
	}

	return retNode;
}

Node* createNodeTwo(Node* firstNode,
	Node* secondNode,
	const char* nodeName,
	const char* production,
	const char* extraData)
{
	Node* retNode = createDefaultNode(nodeName, 2);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		retNode->links[1] = secondNode;
		if (production)
		{
			sprintf(retNode->extraData.production, "%s", production);
		}

		if (extraData)
		{
			sprintf(retNode->extraData.extra, "%s", extraData);
		}
	}

	return retNode;
}

Node* createNodeThree(Node* firstNode,
	Node* secondNode, 
	Node* thirdNode,
	const char* nodeName,
	const char* production,
	const char* extraData)
{
	Node* retNode = createDefaultNode(nodeName, 3);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		retNode->links[1] = secondNode;
		retNode->links[2] = thirdNode;
		if (production)
		{
			sprintf(retNode->extraData.production, "%s", production);
		}

		if (extraData)
		{
			sprintf(retNode->extraData.extra, "%s", extraData);
		}
	}

	return retNode;
}

Node* createNodeFour(Node* firstNode,
	Node* secondNode, 
	Node* thirdNode, 
	Node* fourthNode,
	const char* nodeName,
	const char* production,
	const char* extraData)
{
	Node* retNode = createDefaultNode(nodeName, 4);

	if (retNode)
	{
		retNode->links[0] = firstNode;
		retNode->links[1] = secondNode;
		retNode->links[2] = thirdNode;
		retNode->links[3] = fourthNode;
		if (production)
		{
			sprintf(retNode->extraData.production, "%s", production);
		}

		if (extraData)
		{
			sprintf(retNode->extraData.extra, "%s", extraData);
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
			printf(" | %d | -> %s  %s\n", ast->numLinks, 
				ast->extraData.production,
				ast->extraData.extra);
		}
		else
		{
			printf(" -> %s %s\n", ast->extraData.production,
				ast->extraData.extra);
		}
		for (idx = 0; idx < ast->numLinks; idx++)
		{
			
			printAst(ast->links[idx], level + 1);			
		}
	}
}
