#ifndef __AST_H
#define __AST_H

#define MAX_NODE_TYPE 50
#define MAX_EXTRA_DATA 50
#define MAX_EXTRA_DATA_FIELDS 5
#define MAX_LEN_STRING 50

#define DECIMAL_BASE 10

typedef struct extraData {
	char nodeName[MAX_LEN_STRING];
	char production[MAX_LEN_STRING];
	char extra[MAX_LEN_STRING * 3];
}ExtraData;

typedef struct node {
	char type[MAX_NODE_TYPE];
	int numLinks;
	ExtraData extraData;
	struct node** links;
}Node;


Node* createNodeLeaf(const char* nodeName,
	const char* production,
	const char* extraData);

Node* createNodeLeafForConstant(const char* nodeName,
	const char* extraData,
	const int valueConst);

Node* createNodeOne(Node* firstNode,
	const char* nodeName,
	const char* production,
	const char* extraData);

Node* createNodeTwo(Node* firstNode,
	Node* secondNode,
	const char* nodeName,
	const char* production,
	const char* extraData);

Node* createNodeThree(Node* firstNode,
	Node* secondNode,
	Node* thirdNode,
	const char* nodeName,
	const char* production,
	const char* extraData);

Node* createNodeFour(Node* firstNode,
	Node* secondNode,
	Node* thirdNode,
	Node* fourthNode,
	const char* nodeName,
	const char* production,
	const char* extraData);

//Node* createNodeFive(Node* firstNode, Node* secondNode, Node* thirdNode, Node* fourthNode, Node* fifthNode, const char* extraData);

Node* createDefaultNode(const char* nodeName, unsigned int linksCount);
Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize);
Node* createListNode(const char* listName, Node* firstLink);
void addLinkToList(Node* listNode, Node* linkToAdd);
void printAst(Node* ast, int level);
#endif
