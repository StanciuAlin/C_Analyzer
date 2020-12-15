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
	: IDENTIFIER														{ $$ = createNodeLeaf("IDENTIFIER PrimaryExpr"); }
	| CONSTANT															{ $$ = createNodeLeaf("CONSTANT PrimaryExpr"); }
	| STRING_LITERAL													{ $$ = createNodeLeaf("STRING_LITERAL PrimaryExpr"); }
	| '(' expression ')'												{ $$ = createNodeOne($2, "Expression PrimaryExpr"); }
	;

postfix_expression
	: primary_expression												{ $$ = createNodeOne($1, "PrimaryExpr PostfixExpr"); }
	| postfix_expression '[' expression ']'								{ $$ = createNodeTwo($1, $3, "Expr PostfixExpr"); }
	| postfix_expression '(' ')'										{ $$ = createNodeOne($1, "Empty PostfixExpr"); }
	| postfix_expression '(' argument_expression_list ')'				{ $$ = createNodeTwo($1, $3, "ArgExprList PostfixExpr"); }
	| postfix_expression '.' IDENTIFIER									{ $$ = createNodeOne($1, "IDENTIFIER PostfixExpr"); }
	| postfix_expression PTR_OP IDENTIFIER								{ $$ = createNodeOne($1, "PTR_OP IDENTIFIER PostfixExpr"); }
	| postfix_expression INC_OP											{ $$ = createNodeOne($1, "INC_OP PostfixExpr"); }
	| postfix_expression DEC_OP											{ $$ = createNodeOne($1, "DEC_OP PostfixExpr"); }
	;

argument_expression_list
	: assignment_expression												{ $$ = createNodeOne($1, "AssignExpr ArgExprList"); }
	| argument_expression_list ',' assignment_expression				{ $$ = createNodeTwo($1, $3, "AssignExpr ArgExprList"); }
	;

unary_expression
	: postfix_expression												{ $$ = createNodeOne($1, "PostfixExpr UnaryExpression"); }
	| INC_OP unary_expression											{ $$ = createNodeOne($2, "INC_OP UnaryExpression"); }
	| DEC_OP unary_expression											{ $$ = createNodeOne($2, "DEC_OP UnaryExpression"); }
	| unary_operator cast_expression									{ $$ = createNodeTwo($1, $2, "CastExpr UnaryExpression"); }
	| SIZEOF unary_expression											{ $$ = createNodeOne($2, "SIZEOF UnaryExpression"); }
	| SIZEOF '(' type_name ')'											{ $$ = createNodeOne($3, "SIZEOF (typename) UnaryExpression"); }
	;

unary_operator
	: '&'																{ $$ = createNodeLeaf("& UnaryOperator"); }
	| '*'																{ $$ = createNodeLeaf("* UnaryOperator"); }
	| '+'																{ $$ = createNodeLeaf("+ UnaryOperator"); }
	| '-'																{ $$ = createNodeLeaf("- UnaryOperator"); }
	| '~'																{ $$ = createNodeLeaf("~ UnaryOperator"); }
	| '!'																{ $$ = createNodeLeaf("! UnaryOperator"); }
	;

cast_expression
	: unary_expression													{ $$ = createNodeOne($1, "UnaryExpr CastExpr"); }
	| '(' type_name ')' cast_expression									{ $$ = createNodeTwo($2, $4, "(typename) CastExpr"); }
	;

multiplicative_expression
	: cast_expression													{ $$ = createNodeOne($1, "CastExpr MultiplicativeExpr"); }
	| multiplicative_expression '*' cast_expression						{ $$ = createNodeTwo($1, $3, "* MultiplicativeExpr"); }
	| multiplicative_expression '/' cast_expression						{ $$ = createNodeTwo($1, $3, "/ MultiplicativeExpr"); }
	| multiplicative_expression '%' cast_expression						{ $$ = createNodeTwo($1, $3, "% MultiplicativeExpr"); }
	;

additive_expression
	: multiplicative_expression											{ $$ = createNodeOne($1, "MultiplicativeExpr AdditiveExpr"); }
	| additive_expression '+' multiplicative_expression					{ $$ = createNodeTwo($1, $3, "+ AdditiveExpr"); }
	| additive_expression '-' multiplicative_expression					{ $$ = createNodeTwo($1, $3, "- AdditiveExpr"); }
	;

shift_expression
	: additive_expression												{ $$ = createNodeOne($1, "AdditiveExpr ShiftExpr"); }
	| shift_expression LEFT_OP additive_expression						{ $$ = createNodeTwo($1, $3, "LEFT_OP ShiftExpr"); }
	| shift_expression RIGHT_OP additive_expression						{ $$ = createNodeTwo($1, $3, "RIGHT_OP ShiftExpr"); }
	;

relational_expression
	: shift_expression													{ $$ = createNodeOne($1, "ShiftExpr RelationalExpr"); }
	| relational_expression '<' shift_expression						{ $$ = createNodeTwo($1, $3, "< RelationalExpr"); }
	| relational_expression '>' shift_expression						{ $$ = createNodeTwo($1, $3, "> RelationalExpr"); }
	| relational_expression LE_OP shift_expression						{ $$ = createNodeTwo($1, $3, "LE_OP RelationalExpr"); }
	| relational_expression GE_OP shift_expression						{ $$ = createNodeTwo($1, $3, "GE_OP RelationalExpr"); }
	;

equality_expression
	: relational_expression												{ $$ = createNodeOne($1, "RelationalExpr EqualityExpr"); }
	| equality_expression EQ_OP relational_expression					{ $$ = createNodeTwo($1, $3, "EQ_OP EqualityExpr"); }
	| equality_expression NE_OP relational_expression					{ $$ = createNodeTwo($1, $3, "NE_OP EqualityExpr"); }
	;

and_expression
	: equality_expression												{ $$ = createNodeOne($1, "EqualityExpr AndExpr"); }
	| and_expression '&' equality_expression							{ $$ = createNodeTwo($1, $3, "& AndExpr"); }
	;

exclusive_or_expression
	: and_expression													{ $$ = createNodeOne($1, "AndExpr ExclusiveOrExpr"); }
	| exclusive_or_expression '^' and_expression						{ $$ = createNodeTwo($1, $3, "^ ExclusiveOrExpr"); }
	;

inclusive_or_expression
	: exclusive_or_expression											{ $$ = createNodeOne($1, "ExclusiveOrExpr InclusiveOrExpr"); }
	| inclusive_or_expression '|' exclusive_or_expression				{ $$ = createNodeTwo($1, $3, "| InclusiveOrExpr"); }
	;

logical_and_expression
	: inclusive_or_expression											{ $$ = createNodeOne($1, "InclusiveOrExpr LogicalAndExpr"); }
	| logical_and_expression AND_OP inclusive_or_expression				{ $$ = createNodeTwo($1, $3, "AND_OP LogicalAndExpr"); }
	;

logical_or_expression
	: logical_and_expression											{ $$ = createNodeOne($1, "LogicalAndExpr LogicalOrExpr"); }
	| logical_or_expression OR_OP logical_and_expression				{ $$ = createNodeTwo($1, $3, "OR_OP LogicalOrExpr"); }
	;

conditional_expression
	: logical_or_expression												{ $$ = createNodeOne($1, "LogicalOrExpr CondExpr"); }
	| logical_or_expression '?' expression ':' conditional_expression	{ $$ = createNodeThree($1, $3, $5, "? : CondExpr"); }
	;

assignment_expression
	: conditional_expression											{ $$ = createNodeOne($1, "CondExpr AssignExpr"); }
	| unary_expression assignment_operator assignment_expression        { $$ = createNodeThree($1, $2, $3, "UnaryExpression = AssignExpr"); }
	;

assignment_operator
	: '='																{ $$ = createNodeLeaf("= AssignmentOp"); }
	| MUL_ASSIGN														{ $$ = createNodeLeaf("MUL_ASSIGN AssignmentOp"); }
	| DIV_ASSIGN														{ $$ = createNodeLeaf("DIV_ASSIGN AssignmentOp"); }
	| MOD_ASSIGN														{ $$ = createNodeLeaf("MOD_ASSIGN AssignmentOp"); }
	| ADD_ASSIGN														{ $$ = createNodeLeaf("ADD_ASSIGN AssignmentOp"); }
	| SUB_ASSIGN														{ $$ = createNodeLeaf("SUB_ASSIGN AssignmentOp"); }
	| LEFT_ASSIGN														{ $$ = createNodeLeaf("LEFT_ASSIGN AssignmentOp"); }
	| RIGHT_ASSIGN														{ $$ = createNodeLeaf("RIGHT_ASSIGN AssignmentOp"); }
	| AND_ASSIGN														{ $$ = createNodeLeaf("AND_ASSIGN AssignmentOp"); }
	| XOR_ASSIGN														{ $$ = createNodeLeaf("XOR_ASSIGN AssignmentOp"); }
	| OR_ASSIGN															{ $$ = createNodeLeaf("OR_ASSIGN AssignmentOp"); }
	;

expression
	: assignment_expression												{ $$ = createNodeOne($1, "AssignExpr - Expr"); }
	| expression ',' assignment_expression								{ $$ = createNodeTwo($1, $3, ", Expr"); }
	;

constant_expression
	: conditional_expression											{ $$ = createNodeOne($1, "CondExpr ConstExpr"); }
	;

declaration
	: declaration_specifiers ';'										{ $$ = createNodeOne($1, "DeclSpecs Declaration"); }
	| declaration_specifiers init_declarator_list ';'					{ $$ = createNodeTwo($1, $2, "InitDeclList Declaration"); }
	;																	
																		
declaration_specifiers													
	: storage_class_specifier											{ $$ = createNodeOne($1, "StorageClassSpec DeclSpecs"); }                                          
	| storage_class_specifier declaration_specifiers					{ $$ = createNodeTwo($1, $2, "DeclSpecs"); }		
	| type_specifier													{ $$ = createNodeOne($1, "TypeSpec DeclSpecs"); }
	| type_specifier declaration_specifiers								{ $$ = createNodeTwo($1, $2, "DeclSpecs"); }
	| type_qualifier													{ $$ = createNodeOne($1, "TypeQual DeclSpecs"); }
	| type_qualifier declaration_specifiers								{ $$ = createNodeTwo($1, $2, "DeclSpecs"); }
	;

init_declarator_list
	: init_declarator													{ $$ = createNodeOne($1, "InitDeclarator InitDeclaratorList"); }
	| init_declarator_list ',' init_declarator							{ $$ = createNodeTwo($1, $3, ", InitDeclaratorList"); }
	;

init_declarator
	: declarator														{ $$ = createNodeOne($1, "Declarator InitDeclarator"); }
	| declarator '=' initializer										{ $$ = createNodeTwo($1, $3, "Initializer InitDeclarator"); }
	;

storage_class_specifier
	: TYPEDEF															{ $$ = createNodeLeaf("TYPEDEF StorageClassSpec"); }
	| EXTERN															{ $$ = createNodeLeaf("EXTERN StorageClassSpec"); }
	| STATIC															{ $$ = createNodeLeaf("STATIC StorageClassSpec"); }
	| AUTO																{ $$ = createNodeLeaf("AUTO StorageClassSpec"); }
	| REGISTER															{ $$ = createNodeLeaf("REGISTER StorageClassSpec"); }
	| RESTRICT															{ $$ = createNodeLeaf("RESTRICT StorageClassSpec"); }
	;

type_specifier
	: VOID																{ $$ = createNodeLeaf("VOID TypeSpec"); }
	| CHAR																{ $$ = createNodeLeaf("CHAR TypeSpec"); }
	| SHORT																{ $$ = createNodeLeaf("SHORT TypeSpec"); }
	| INT																{ $$ = createNodeLeaf("INT TypeSpec"); }
	| LONG																{ $$ = createNodeLeaf("LONG TypeSpec"); }
	| FLOAT                                                             { $$ = createNodeLeaf("FLOAT TypeSpec"); }
	| DOUBLE															{ $$ = createNodeLeaf("DOUBLE TypeSpec"); }
	| SIGNED															{ $$ = createNodeLeaf("SIGNED TypeSpec"); }
	| UNSIGNED															{ $$ = createNodeLeaf("UNSIGNED TypeSpec"); }
	| _BOOL																{ $$ = createNodeLeaf("_BOOL TypeSpec"); }
	| _COMPLEX															{ $$ = createNodeLeaf("_COMPLEX TypeSpec"); }
	| _IMAGINARY														{ $$ = createNodeLeaf("_IMAGINARY TypeSpec"); }
	| INLINE															{ $$ = createNodeLeaf("INLINE TypeSpec"); }
	| struct_or_union_specifier											{ $$ = createNodeOne($1, "StructOrUnion TypeSpec"); }
	| enum_specifier													{ $$ = createNodeOne($1, "Enum TypeSpec"); }
	| TYPE_NAME															{ $$ = createNodeLeaf("TYPE_NAME TypeSpec"); }
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
	: function_definition								{ $$ = createNodeOne($1, "Function Definition"); }														
	| declaration										{ $$ = createNodeOne($1, "Declaration"); }								
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement   { $$ = createNodeFour($1, $2, $3, $4, "Complete Function Definition"); }        
	| declaration_specifiers declarator compound_statement                    { $$ = createNodeThree($1, $2, $3, "Function DefinitionWithoutDeclarationList"); }       
	| declarator declaration_list compound_statement                          { $$ = createNodeThree($1, $2, $3, "Function DefinitionWithoutSpecifiers"); }       
	| declarator compound_statement                                           { $$ = createNodeTwo($1, $2, "Function Definition Short"); }       
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