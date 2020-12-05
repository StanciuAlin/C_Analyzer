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




Node* createTypeSpecifier(const char* typeName, Node* typeSpecifier);
Node* createStructOrUnionSpecifier(Node* type, Node* list);
Node* createStructOrUnionType(const char* typeName);
Node* createEnumSpecifier(Node* enumList);
Node* createEnumerator(Node* constantExpression);
Node* createTypeQualifier(const char* typeName);
Node* createStorageClassSpecifier(const char* typeName);
Node* createTranslationUnitNode(Node* declaration);
Node* createExternalDeclarationNode(Node* externalDeclaration);
Node* createFunctionDeclarationNode(Node* typeSpecifier, const char* functionName, Node* paramsList, Node* compoundStatement);
Node* createDeclarationSpecifiers(Node* typeSpecifier, const char* varName, int value); //we need a version for each type of constant
Node* createInitDeclarator(Node* declarator, Node* initializer);
Node* createDeclarator(Node* pointer, Node* directDeclarator);
Node* createDirectDeclarator(Node* directDeclarator, Node* declarators);
Node* createInitializer(Node* initializerType);
Node* createConstantExpression(Node* conditionalExpression);
Node* createParameterTypeList(Node* paramTypeList, int flag);
Node* createPointer(Node* typeQualifierList, Node* pointer);
Node* createJumpStatement(Node* expression, int selector);
Node* createStatement(Node* statement);
Node* createLabeledStatement(const char* labelName, Node* constStatement, Node* statement);
Node* createCompoundStatement(Node* localDeclList, Node* instructionsList);
Node* createExpressionStatement(Node* expression);

Node* createIfStatement(Node* expresionIf, Node* thenStatement, Node* elseStatement);
Node* createSwitchStatement(Node* expresionSwitch, Node* statement);
Node* createWhileStatement(Node* expresionWhile, Node* statement);
Node* createDoWhileStatement(Node* statement, Node* expresionWhile);
Node* createForStatement(Node* initForExpression, Node* cyclicCondition, Node* stepFor, Node* statement);

Node* createNodeLeaf(const char* extraData);
Node* createNodeOne(Node* firstNode, const char* extraData);
Node* createNodeTwo(Node* firstNode, Node* secondNode, const char* extraData);
Node* createNodeThree(Node* firstNode, Node* secondNode, Node* thirdNode, const char* extraData);
Node* createNodeFour(Node* firstNode, Node* secondNode, Node* thirdNode, Node* fourthNode, const char* extraData);
Node* createNodeFive(Node* firstNode, Node* secondNode, Node* thirdNode, Node* fourthNode, Node* fifthNode, const char* extraData);

Node* createDefaultNode(const char* nodeName, unsigned int linksCount);
Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize);
Node* createListNode(const char* listName, Node* firstLink);
void addLinkToList(Node* listNode, Node* linkToAdd);
void printAst(Node* ast, int level);
#endif
