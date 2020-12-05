%{
#include "ast.h"
#include <stdio.h>

Node* astRoot = NULL;
%}
%union{
	
	Node	*node;
	char* strings;
	int intVal;
}
%token <strings> IDENTIFIER 
%token <intVal> CONSTANT 
%token STRING_LITERAL 
%token SIZEOF
%token PTR_OP 
%token INC_OP 
%token DEC_OP 
%token LEFT_OP 
%token RIGHT_OP 
%token LE_OP 
%token GE_OP 
%token EQ_OP 
%token NE_OP
%token AND_OP 
%token OR_OP 
%token MUL_ASSIGN 
%token DIV_ASSIGN 
%token MOD_ASSIGN 
%token ADD_ASSIGN
%token SUB_ASSIGN 
%token LEFT_ASSIGN 
%token RIGHT_ASSIGN 
%token AND_ASSIGN
%token XOR_ASSIGN 
%token OR_ASSIGN 
%token TYPE_NAME
%token TYPEDEF 
%token EXTERN 
%token STATIC 
%token AUTO 
%token REGISTER
%token CHAR 
%token SHORT 
%token INT 
%token LONG 
%token SIGNED 
%token UNSIGNED 
%token FLOAT 
%token DOUBLE 
%token CONST 
%token VOLATILE 
%token VOID
%token STRUCT 
%token UNION 
%token ENUM 
%token ELLIPSIS
%token RESTRICT 
%token _BOOL 
%token _COMPLEX 
%token _IMAGINARY 
%token INLINE
%token CASE 
%token DEFAULT 
%token IF 
%token ELSE 
%token SWITCH 
%token WHILE 
%token DO 
%token FOR 
%token GOTO 
%token CONTINUE 
%token BREAK 
%token RETURN
%token COMM_MULTI_LINE
%token COMM_UNI_LINE

%type <node> translation_unit
%type <node> external_declaration
%type <node> declaration
%type <node> declarator
%type <node> function_definition
%type <node> parameter_list
%type <node> parameter_declaration
%type <node> compound_statement
%type <node> declaration_list
%type <node> labeled_statement
%type <node> expression_statement
%type <node> selection_statement
%type <node> iteration_statement
%type <node> jump_statement
%type <node> statement
%type <node> statement_list
%type <node> declaration_specifiers
%type <node> init_declarator
%type <node> init_declarator_list
%type <node> type_specifier
%type <node> type_qualifier
%type <node> type_name
%type <node> expression
%type <node> assignment_expression
%type <node> assignment_operator
%type <node> unary_expression
%type <node> unary_operator
%type <node> primary_expression
%type <node> storage_class_specifier
%type <node> struct_or_union_specifier
%type <node> direct_declarator
%type <node> conditional_expression
%type <node> postfix_expression
%type <node> argument_expression_list
%type <node> cast_expression
%type <node> multiplicative_expression
%type <node> additive_expression
%type <node> shift_expression
%type <node> relational_expression
%type <node> equality_expression
%type <node> and_expression
%type <node> exclusive_or_expression
%type <node> inclusive_or_expression
%type <node> logical_and_expression
%type <node> logical_or_expression
%type <node> constant_expression
%type <node> initializer
%type <node> initializer_list
%type <node> enum_specifier
%type <node> struct_or_union
%type <node> struct_declaration_list
%type <node> struct_declaration
%type <node> specifier_qualifier_list
%type <node> struct_declarator_list
%type <node> struct_declarator
%type <node> enumerator_list
%type <node> enumerator
%type <node> parameter_type_list
%type <node> identifier_list
%type <node> type_qualifier_list
%type <node> pointer
%type <node> abstract_declarator
%type <node> direct_abstract_declarator

%start translation_unit
%%

primary_expression
	: IDENTIFIER														{ $$ = createNode }
	| CONSTANT															{ $$ = createNode }
	| STRING_LITERAL													{ $$ = createNode }
	| '(' expression ')'												{ $$ = createNode }
	;

postfix_expression
	: primary_expression												{ $$ = createNode }
	| postfix_expression '[' expression ']'								{ $$ = createNode }
	| postfix_expression '(' ')'										{ $$ = createNode }
	| postfix_expression '(' argument_expression_list ')'				{ $$ = createNode }
	| postfix_expression '.' IDENTIFIER									{ $$ = createNode }
	| postfix_expression PTR_OP IDENTIFIER								{ $$ = createNode }
	| postfix_expression INC_OP											{ $$ = createNode }
	| postfix_expression DEC_OP											{ $$ = createNode }
	;

argument_expression_list
	: assignment_expression												{ $$ = createNode }
	| argument_expression_list ',' assignment_expression				{ $$ = createNode }
	;

unary_expression
	: postfix_expression												{ $$ = createNode }
	| INC_OP unary_expression											{ $$ = createNode }
	| DEC_OP unary_expression											{ $$ = createNode }
	| unary_operator cast_expression									{ $$ = createNode }
	| SIZEOF unary_expression											{ $$ = createNode }
	| SIZEOF '(' type_name ')'											{ $$ = createNode }
	;

unary_operator
	: '&'																{ $$ = createNodeLeaf("&"); }
	| '*'																{ $$ = createNodeLeaf("*"); }
	| '+'																{ $$ = createNodeLeaf("+"); }
	| '-'																{ $$ = createNodeLeaf("-"); }
	| '~'																{ $$ = createNodeLeaf("~"); }
	| '!'																{ $$ = createNodeLeaf("!"); }
	;

cast_expression
	: unary_expression													{ $$ = createNode }
	| '(' type_name ')' cast_expression									{ $$ = createNode }
	;

multiplicative_expression
	: cast_expression													{ $$ = createNode }
	| multiplicative_expression '*' cast_expression						{ $$ = createNode }
	| multiplicative_expression '/' cast_expression						{ $$ = createNode }
	| multiplicative_expression '%' cast_expression						{ $$ = createNode }
	;

additive_expression
	: multiplicative_expression											{ $$ = createNode }
	| additive_expression '+' multiplicative_expression					{ $$ = createNode }
	| additive_expression '-' multiplicative_expression					{ $$ = createNode }
	;

shift_expression
	: additive_expression												{ $$ = createNode }
	| shift_expression LEFT_OP additive_expression						{ $$ = createNode }
	| shift_expression RIGHT_OP additive_expression						{ $$ = createNode }
	;

relational_expression
	: shift_expression													{ $$ = createNode }
	| relational_expression '<' shift_expression						{ $$ = createNode }
	| relational_expression '>' shift_expression						{ $$ = createNode }
	| relational_expression LE_OP shift_expression						{ $$ = createNode }
	| relational_expression GE_OP shift_expression						{ $$ = createNode }
	;

equality_expression
	: relational_expression												{ $$ = createNode }
	| equality_expression EQ_OP relational_expression					{ $$ = createNode }
	| equality_expression NE_OP relational_expression					{ $$ = createNode }
	;

and_expression
	: equality_expression												{ $$ = createNode }
	| and_expression '&' equality_expression							{ $$ = createNode }
	;

exclusive_or_expression
	: and_expression													{ $$ = createNode }
	| exclusive_or_expression '^' and_expression						{ $$ = createNode }
	;

inclusive_or_expression
	: exclusive_or_expression											{ $$ = createNode }
	| inclusive_or_expression '|' exclusive_or_expression				{ $$ = createNode }
	;

logical_and_expression
	: inclusive_or_expression											{ $$ = createNode }
	| logical_and_expression AND_OP inclusive_or_expression				{ $$ = createNode }
	;

logical_or_expression
	: logical_and_expression											{ $$ = createNode }
	| logical_or_expression OR_OP logical_and_expression				{ $$ = createNode }
	;

conditional_expression
	: logical_or_expression												{ $$ = createNode }
	| logical_or_expression '?' expression ':' conditional_expression	{ $$ = createNode }
	;

assignment_expression
	: conditional_expression											{ $$ = createNode }
	| unary_expression assignment_operator assignment_expression        { $$ = createNode }
	;

assignment_operator
	: '='																{ $$ = createNodeLeaf("AssignmentOperator - ="); }
	| MUL_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - MUL_ASSIGN"); }
	| DIV_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - DIV_ASSIGN"); }
	| MOD_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - MOD_ASSIGN"); }
	| ADD_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - ADD_ASSIGN"); }
	| SUB_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - SUB_ASSIGN"); }
	| LEFT_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - LEFT_ASSIGN"); }
	| RIGHT_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - RIGHT_ASSIGN"); }
	| AND_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - AND_ASSIGN"); }
	| XOR_ASSIGN														{ $$ = createNodeLeaf("AssignmentOperator - XOR_ASSIGN"); }
	| OR_ASSIGN															{ $$ = createNodeLeaf("AssignmentOperator - OR_ASSIGN"); }
	;

expression
	: assignment_expression												{ $$ = createNodeOne($1, "Expression - AssignmentExpr"); }
	| expression ',' assignment_expression								{ $$ = createNodeTwo($1, $3, "Expression - Expr - AssignmentExpr"); }
	;

constant_expression
	: conditional_expression											{ $$ = createNodeOne($1, "ConstExpr - CondExpr"); }
	;

declaration
	: declaration_specifiers ';'										{ $$ = createNodeOne($1, "Declaration - DeclSpec"); }
	| declaration_specifiers init_declarator_list ';'					{ $$ = createNodeTwo($1, $2, "Declaration - DeclSpec - InitDeclList"); }
	;																	
																		
declaration_specifiers													
	: storage_class_specifier											{ $$ = createNodeOne($1, "StorageClassSpecifier"); }                                          
	| storage_class_specifier declaration_specifiers					{ $$ = createNodeTwo($1, $2, "StorageClassSpecifier"); }		
	| type_specifier													{ $$ = createNodeOne($1, "StorageClassSpecifier"); }
	| type_specifier declaration_specifiers								{ $$ = createNodeTwo($1, $2, "StorageClassSpecifier"); }
	| type_qualifier													{ $$ = createNodeOne($1, "StorageClassSpecifier"); }
	| type_qualifier declaration_specifiers								{ $$ = createNodeTwo($1, $2, "StorageClassSpecifier"); }
	;

init_declarator_list
	: init_declarator													{ $$ = createNodeOne($1, "InitDeclList - InitDecl"); }
	| init_declarator_list ',' init_declarator							{ $$ = createNodeTwo($1, $3, "InitDeclList - List"); }
	;

init_declarator
	: declarator														{ $$ = createNodeOne($1, "InitDecl - Declarator"); }
	| declarator '=' initializer										{ $$ = createNodeTwo($1, $3, "InitDecl - = Initializer"); }
	;

storage_class_specifier
	: TYPEDEF															{ $$ = createNodeLeaf("TYPEDEF"); }
	| EXTERN															{ $$ = createNodeLeaf("EXTERN"); }
	| STATIC															{ $$ = createNodeLeaf("STATIC"); }
	| AUTO																{ $$ = createNodeLeaf("AUTO"); }
	| REGISTER															{ $$ = createNodeLeaf("REGISTER"); }
	| RESTRICT															{ $$ = createNodeLeaf("RESTRICT"); }
	;

type_specifier
	: VOID																{ $$ = createNodeLeaf("TypeSpecifier - VOID"); }
	| CHAR																{ $$ = createNodeLeaf("TypeSpecifier - CHAR"); }
	| SHORT																{ $$ = createNodeLeaf("TypeSpecifier - SHORT"); }
	| INT																{ $$ = createNodeLeaf("TypeSpecifier - INT"); }
	| LONG																{ $$ = createNodeLeaf("TypeSpecifier - LONG"); }
	| FLOAT                                                             { $$ = createNodeLeaf("TypeSpecifier - FLOAT"); }
	| DOUBLE															{ $$ = createNodeLeaf("TypeSpecifier - DOUBLE"); }
	| SIGNED															{ $$ = createNodeLeaf("TypeSpecifier - SIGNED"); }
	| UNSIGNED															{ $$ = createNodeLeaf("TypeSpecifier - UNSIGNED"); }
	| _BOOL																{ $$ = createNodeLeaf("TypeSpecifier - _BOOL"); }
	| _COMPLEX															{ $$ = createNodeLeaf("TypeSpecifier - _COMPLEX"); }
	| _IMAGINARY														{ $$ = createNodeLeaf("TypeSpecifier - _IMAGINARY"); }
	| INLINE															{ $$ = createNodeLeaf("TypeSpecifier - INLINE"); }
	| struct_or_union_specifier											{ $$ = createNodeOne($1, "TypeSpecifier - StructOrUnion"); }
	| enum_specifier													{ $$ = createNodeOne($1, "TypeSpecifier - Enum"); }
	| TYPE_NAME															{ $$ = createNodeLeaf("TypeSpecifier - TYPE_NAME"); }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'        { $$ = createNodeTwo($1, $4, "StructUnion - IDENTIFIER {StructDeclList}"); }
	| struct_or_union '{' struct_declaration_list '}'                   { $$ = createNodeTwo($1, $3, "StructUnion - {StructDeclList}"); }
	| struct_or_union IDENTIFIER                                        { $$ = createNodeOne($1, "StructUnion - IDENTIFIER"); }
	;

struct_or_union
	: STRUCT															{ $$ = createNodeLeaf("STRUCT"); }
	| UNION																{ $$ = createNodeLeaf("UNION"); }
	;

struct_declaration_list
	: struct_declaration												{ $$ = createNodeOne($1, "StructDeclList - StructDecl"); }
	| struct_declaration_list struct_declaration						{ $$ = createNodeTwo($1, $2, "StructDeclList"); }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'				{ $$ = createNodeTwo($1, $2, "StructDecl - SpecQualifierList - StructDeclList"); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list							{ $$ = createNodeTwo($1, $2, "SpecQualifierList - TypeSpec - SpecQualifierList"); }
	| type_specifier													{ $$ = createNodeOne($1, "SpecQualifierList - TypeSpec"); }
	| type_qualifier specifier_qualifier_list							{ $$ = createNodeTwo($1, $2, "SpecQualifierList - TypeQualifier - SpecQulifierList"); }
	| type_qualifier													{ $$ = createNodeOne($1, "SpecQualifierList - TypeQualifier"); }
	;

struct_declarator_list
	: struct_declarator													{ $$ = createNodeOne($1, "StructDeclList - StructDecl"); }
	| struct_declarator_list ',' struct_declarator						{ $$ = createNodeTwo($1, $3, "StructDeclList"); }
	;

struct_declarator
	: declarator														{ $$ = createNodeOne($1, "StructDecl - Declarator"); }
	| ':' constant_expression											{ $$ = createNodeOne($2, "StructDecl - ConstExpr"); }
	| declarator ':' constant_expression								{ $$ = createNodeTwo($1, $3, "StrucDecl - Decl:ConstExpr"); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'									    { $$ = createNodeOne($3, "EnumSpecifier - ENUM {EnumeratorList}"); }
	| ENUM IDENTIFIER '{' enumerator_list '}'                           { $$ = createNodeOne($4, "EnumSpecifier - ENUM IDENTIFIER {EnumeratorList}"); }
	| ENUM IDENTIFIER												    { $$ = createNodeLeaf("ENUM IDENTIFIER"); }
	;

enumerator_list
	: enumerator														{ $$ = createNodeOne($1, "EnumList - Enumerator"); }
	| enumerator_list ',' enumerator									{ $$ = createNodeTwo($1, $3, "EnumList - List - Enumerator"); }
	;

enumerator
	: IDENTIFIER														{ $$ = createNodeLeaf("Enumerator - IDENTIFIER"); }
	| IDENTIFIER '=' constant_expression                                { $$ = createNodeOne($3, "Enumerator - ConstExpr"); }
	;

type_qualifier
	: CONST																{ $$ = createNodeLeaf("TypeQualifier - CONST"); }
	| VOLATILE															{ $$ = createNodeLeaf("TypeQualifier - VOLATILE"); }
	;

declarator
	: pointer direct_declarator											{ $$ = createNodeOne($1, "PointerDirectDeclarator"); }									
	| direct_declarator													{ $$ = createNodeOne($1, "DirectDeclarator"); }											
	;

direct_declarator
	: IDENTIFIER														{ $$ = createNodeLeaf("DirectDecl - IDENTIFIER"); }						
	| '(' declarator ')'												{ $$ = createNodeOne($2, "DirectDecl - (Declarator)"); }
	| direct_declarator '[' constant_expression ']'						{ $$ = createNodeTwo($1, $3, "DirectDecl - [ConstExpr]"); }
	| direct_declarator '[' ']'											{ $$ = createNodeOne($1, "DirectDecl - Empty[]"); }
	| direct_declarator '(' parameter_type_list ')'						{ $$ = createNodeTwo($1, $3, "DirectDecl - (ParamTypeList)"); }
	| direct_declarator '(' identifier_list ')'							{ $$ = createNodeTwo($1, $3, "DirectDecl - (IdentifierList)"); }
	| direct_declarator '(' ')'											{ $$ = createNodeLeaf("DirectDecl - Empty()"); }
	;

pointer
	: '*'																{ $$ = createNodeLeaf("Pointer"); }
	| '*' pointer														{ $$ = createNodeOne($2, "Pointer"); }
	| '*' type_qualifier_list											{ $$ = createNodeOne($2, "Pointer - TypeQualifierList"); }
	| '*' type_qualifier_list pointer									{ $$ = createNodeTwo($2, $3, "Pointer"); }
	;

type_qualifier_list
	: type_qualifier													{ $$ = createNodeOne($1, "TypeQualifier"); }
	| type_qualifier_list type_qualifier								{ $$ = createNodeTwo($1, $2, "TypeQualifierList"); }
	;															
																
																
parameter_type_list
	: parameter_list													{ $$ = createNodeOne($1, "ParamTypeList"); }
	| parameter_list ',' ELLIPSIS										{ $$ = createNodeOne($1, "ParamTypeList - ELLIPSIS"); }
	;

parameter_list
	: parameter_declaration												{ $$ = createNodeOne($1, "ParamList - ParamDecl"); }
	| parameter_list ',' parameter_declaration							{ $$ = createNodeTwo($1, $3, "ParamList - ParamDecl"); }	
	;

parameter_declaration
	: declaration_specifiers declarator									{ $$ = createNodeTwo($1, $2, "ParamDecl - Declarator"); }
	| declaration_specifiers abstract_declarator						{ $$ = createNodeTwo($1, $2, "ParamDecl - AbstrDecl"); }
	| declaration_specifiers											{ $$ = createNodeOne($1, "ParamDecl - DeclSpecifiers"); }
	;

identifier_list
	: IDENTIFIER														{ $$ = createNodeLeaf("IDENTIFIER"); }
	| identifier_list ',' IDENTIFIER									{ $$ = createNodeOne($1, "IdentifierList - IDENTIFIER"); }
	;

type_name
	: specifier_qualifier_list											{ $$ = createNodeOne($1, "TypeName - SpecQualifierList"); }
	| specifier_qualifier_list abstract_declarator						{ $$ = createNodeTwo($1, $2, "TypeName - AbstrDecl"); }
	;

abstract_declarator
	: pointer															{ $$ = createNodeOne($1, "AbstrDecl - Pointer"); }
	| direct_abstract_declarator										{ $$ = createNodeOne($1, "AbstrDecl - DirectAbstrDecl"); }
	| pointer direct_abstract_declarator								{ $$ = createNodeTwo($1, $2, "AbstrDecl - Pointer"); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'									{ $$ = createNodeOne($2, "DirectAbstrDecl - (AbstrDecl)"); }
	| '[' ']'														{ $$ = createNodeLeaf("DirectAbstrDecl - Empty[]"); }
	| '[' constant_expression ']'									{ $$ = createNodeOne($2, "DirectAbstrDecl - [ConstExpr]"); }
	| direct_abstract_declarator '[' ']'							{ $$ = createNodeOne($1, "DirectAbstrDecl - AbstrDecl[]"); }
	| direct_abstract_declarator '[' constant_expression ']'		{ $$ = createNodeTwo($1, $3, "DirectAbstrDecl - [ConstExpr]"); }
	| '(' ')'														{ $$ = createNodeLeaf("DirectAbstrDecl - Empty()"); }
	| '(' parameter_type_list ')'									{ $$ = createNodeOne($2, "DirectAbstrDecl - (ParamTypeList)"); }
	| direct_abstract_declarator '(' ')'							{ $$ = createNodeOne($1, "DirectAbstrDecl - AbstrDecl()"); }
	| direct_abstract_declarator '(' parameter_type_list ')'		{ $$ = createNodeTwo($1, $3, "DirectAbstrDecl - (ParamTypeList)"); }
	;

initializer
	: assignment_expression											{ $$ = createNodeOne($1, "Initializer - AssignExpr"); }							
	| '{' initializer_list '}'										{ $$ = createNodeOne($2, "Initializer - InitList"); }
   	| '{' initializer_list ',' '}'									{ $$ = createNodeOne($2, "Initializer - InitList"); }
	;

initializer_list
	: initializer													{ $$ = createNodeOne($1, "Initializer"); }											
	| initializer_list ',' initializer								{ $$ = createNodeTwo($1, $3, "InitializerList"); }
	;															
																
statement														
	: labeled_statement												{ $$ = createNodeOne($1, "Statement - labeled"); }									
	| compound_statement											{ $$ = createNodeOne($1, "Statement - compound"); }
	| expression_statement											{ $$ = createNodeOne($1, "Statement - expression"); }
	| selection_statement											{ $$ = createNodeOne($1, "Statement - selection"); }
	| iteration_statement											{ $$ = createNodeOne($1, "Statement - iteration"); }
	| jump_statement												{ $$ = createNodeOne($1, "Statement - jump"); }
	;

labeled_statement
	: IDENTIFIER ':' statement										{ $$ = createNodeOne($3, "LabeledSt - IDENTIFIER"); }                            
	| CASE constant_expression ':' statement						{ $$ = createNodeTwo($2, $4, "LabeledSt - CASE - ConstantExpr"); }
	| DEFAULT ':' statement											{ $$ = createNodeOne($3, "LabeledSt - DEFAULT"); }
	;

compound_statement
	: '{' '}'														{ $$ = createNodeLeaf("EmptyStatement"); }										
	| '{' statement_list '}'										{ $$ = createNodeOne($2, "CompoundStatement - StatementList"); }								
	| '{' declaration_list '}'									    { $$ = createNodeOne($2, "CompoundStatement - DeclarationList"); }
	| '{' declaration_list statement_list '}'					    { $$ = createNodeTwo($2, $3, "CompoundStatement - DeclList - StatementList"); }
	;

declaration_list
	: declaration													{ $$ = createNodeOne($1, "DeclarationList"); }								
	| declaration_list declaration									{ $$ = createNodeTwo($1, $2, "DeclarationList"); }						
	;

statement_list
	: statement														{ $$ = createNodeOne($1, "StatementList-Statement"); }
	| statement_list statement										{ $$ = createNodeTwo($1, $2, "StatementList"); }		
	;

expression_statement
	: ';'															{ $$ = createNodeLeaf("EmptyExpression"); }								
	| expression ';'											    { $$ = createNodeOne($1, "ExpressionStatement"); }
	;

selection_statement
	: IF '(' expression ')' compound_statement ELSE compound_statement		{ $$ = createIfStatement($3, $5, $7); } 
	| IF '(' expression ')' compound_statement								{ $$ = createIfStatement($3, $5, NULL); }
	| IF '(' expression ')' selection_statement                             { $$ = createIfStatement($3, $5, NULL); }
	| SWITCH '(' expression ')' statement									{ $$ = createSwitchStatement($3, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement                                             { $$ = createWhileStatement($3, $5); }
	| DO statement WHILE '(' expression ')' ';'                             		 { $$ = createDoWhileStatement($2, $5); }
	| FOR '(' expression_statement expression_statement ')' statement       		 { $$ = createForStatement($3, $4, $6, NULL); }
	| FOR '(' expression_statement expression_statement expression ')' statement     { $$ = createForStatement($3, $4, $5, $7); } 
	;

jump_statement	
	: GOTO IDENTIFIER ';'								{ $$ = createNodeLeaf("GO TO IDENTIFIER"); }						
	| CONTINUE ';'										{ $$ = createNodeLeaf("CONTINUE"); }							
	| BREAK ';'											{ $$ = createNodeLeaf("BREAK"); }
	| RETURN ';'										{ $$ = createNodeLeaf("RETURN"); }
	| RETURN expression ';'								{ $$ = createNodeOne($2, "RETURN"); }
	;

translation_unit
	: external_declaration								{ $$ = createTranslationUnitNode($1); astRoot = $$;}
	| translation_unit external_declaration             { $$ = $1; addLinkToList($$, $2); }														
	;

external_declaration
	: function_definition								{ $$ = createNodeOne($1, "FunctionDefinition"); }														
	| declaration										{ $$ = createNodeOne($1, "Declaration"); }								
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement   { $$ = createNodeFour($1, $2, $3, $4, "CompleteFunctionDefinition"); }        
	| declaration_specifiers declarator compound_statement                    { $$ = createNodeThree($1, $2, $3, "FunctionDefinitionWithoutDeclarationList"); }       
	| declarator declaration_list compound_statement                          { $$ = createNodeThree($1, $2, $3, "FunctionDefinitionWithoutSpecifiers"); }       
	| declarator compound_statement                                           { $$ = createNodeTwo($1, $2, "FunctionDefinitionShort"); }       
	;

%%

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}