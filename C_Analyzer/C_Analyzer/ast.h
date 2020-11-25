#ifndef __AST_H
#define __AST_H

#define MAX_NODE_TYPE 50
#define MAX_EXTRA_DATA 50

typedef struct node {
	char type[MAX_NODE_TYPE];
	int numLinks;
	char extraData[MAX_EXTRA_DATA];
	struct node** links;
}Node;

Node* createTypeSpecifier(const char* typeName);
Node* createTranslationUnitNode(Node* declaration);
Node* createExternalDeclarationNode(Node* varFunDeclaration);
Node* createFunctionDeclarationNode(Node* typeSpecifier, const char* functionName, Node* paramsList, Node* compoundStatement);
Node* createVarDeclaration(Node* typeSpecifier, const char* varName, int value); //we need a version for each type of constant
Node* createStatement(Node* statement);
Node* createLabeledStatement(const char* labelName, Node* constStatement, Node* statement);
Node* createCompoundStatement(Node* localDeclList, Node* instructionsList);
Node* createExpressionStatement(Node* expression);

Node* createIfStatement(Node* expresionIf, Node* thenStatement, Node* elseStatement);
Node* createSwitchStatement(Node* expresionSwitch, Node* statement);
Node* createWhileStatement(Node* expresionWhile, Node* statement);
Node* createDoWhileStatement(Node* statement, Node* expresionWhile);
Node* createForStatement(Node* initForExpression, Node* cyclicCondition, Node* stepFor, Node* statement);

Node* createDefaultNode(const char* nodeName, unsigned int linksCount);
Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize);
Node* createListNode(const char* listName, Node* firstLink);
void addLinkToList(Node* listNode, Node* linkToAdd);
void printAst(Node* ast, int level);
#endif
