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
	: IDENTIFIER														{ $$ = createNodeLeaf("PrimaryExpr", $1, NULL); }
	| CONSTANT															{ $$ = createNodeLeafForConstant("PrimaryExpr", "CONSTANT", $1); }
	| STRING_LITERAL													{ $$ = createNodeLeaf("PrimaryExpr", "STRING_LITERAL", NULL); }
	| '(' expression ')'												{ $$ = createNodeOne($2, "PrimaryExpr", "STRING_LITERAL", "(expr)"); }
	;

postfix_expression
	: primary_expression												{ $$ = createNodeOne($1, "PostfixExpr", "PrimaryExpr", NULL); }
	| postfix_expression '[' expression ']'								{ $$ = createNodeTwo($1, $3, "PostfixExpr", "[expr]", NULL); }
	| postfix_expression '(' ')'										{ $$ = createNodeOne($1, "PostfixExpr", "Empty PostfixExpr", "()"); }
	| postfix_expression '(' argument_expression_list ')'				{ $$ = createNodeTwo($1, $3, "PostfixExpr", "(ArgExprList)", NULL); }
	| postfix_expression '.' IDENTIFIER									{ $$ = createNodeOne($1, "PostfixExpr", $3, NULL); }
	| postfix_expression PTR_OP IDENTIFIER								{ $$ = createNodeOne($1, "PostfixExpr", $3, NULL); }
	| postfix_expression INC_OP											{ $$ = createNodeOne($1, "PostfixExpr", "INC_OP", NULL); }
	| postfix_expression DEC_OP											{ $$ = createNodeOne($1, "PostfixExpr", "DEC_OP", NULL); }
	;

argument_expression_list
	: assignment_expression												{ $$ = createNodeOne($1, "ArgExprList", "AssignExpr", NULL); }
	| argument_expression_list ',' assignment_expression				{ $$ = createNodeTwo($1, $3, "ArgExprList", "ArgExprList,AssignExpr", "List"); }
	;

unary_expression
	: postfix_expression												{ $$ = createNodeOne($1, "UnaryExpr", "PostfixExpr", NULL); }
	| INC_OP unary_expression											{ $$ = createNodeOne($2, "UnaryExpr", "INC_OP", NULL); }
	| DEC_OP unary_expression											{ $$ = createNodeOne($2, "UnaryExpr", "DEC_OP", NULL); }
	| unary_operator cast_expression									{ $$ = createNodeTwo($1, $2, "UnaryExpr", "CastExpr" ,"UnaryExpr-Cast"); }
	| SIZEOF unary_expression											{ $$ = createNodeOne($2, "UnaryExpr", "SIZEOF", NULL); }
	| SIZEOF '(' type_name ')'											{ $$ = createNodeOne($3, "UnaryExpr", "SIZEOF typename", "(typename)"); }
	;

unary_operator
	: '&'																{ $$ = createNodeLeaf("UnaryOperator", " &", NULL ); }
	| '*'																{ $$ = createNodeLeaf("UnaryOperator", " *", NULL ); }
	| '+'																{ $$ = createNodeLeaf("UnaryOperator", " +", NULL ); }
	| '-'																{ $$ = createNodeLeaf("UnaryOperator", " -", NULL ); }
	| '~'																{ $$ = createNodeLeaf("UnaryOperator", " ~", NULL ); }
	| '!'																{ $$ = createNodeLeaf("UnaryOperator", " !", NULL ); }
	;

cast_expression
	: unary_expression													{ $$ = createNodeOne($1, "CastExpr", "UnaryExpr", NULL); }
	| '(' type_name ')' cast_expression									{ $$ = createNodeTwo($2, $4, "CastExpr", "typename-CastExpr", NULL); }
	;

multiplicative_expression
	: cast_expression													{ $$ = createNodeOne($1, "MultiplicativeExpr", "CastExpr MultiplicativeExpr", NULL); }
	| multiplicative_expression '*' cast_expression						{ $$ = createNodeTwo($1, $3, "MultiplicativeExpr", " * ", "-cast"); }
	| multiplicative_expression '/' cast_expression						{ $$ = createNodeTwo($1, $3, "MultiplicativeExpr", " / ", "-cast"); }
	| multiplicative_expression '%' cast_expression						{ $$ = createNodeTwo($1, $3, "MultiplicativeExpr", " % ", "-cast"); }
	;

additive_expression
	: multiplicative_expression											{ $$ = createNodeOne($1, "AdditiveExpr", "MultiplicativeExpr", NULL); }
	| additive_expression '+' multiplicative_expression					{ $$ = createNodeTwo($1, $3, "AdditiveExpr", " + ", "MultiplicativeExpr"); }
	| additive_expression '-' multiplicative_expression					{ $$ = createNodeTwo($1, $3, "AdditiveExpr", " - ", "MultiplicativeExpr"); }
	;

shift_expression
	: additive_expression												{ $$ = createNodeOne($1, "ShiftExpr", "AdditiveExpr", NULL); }
	| shift_expression LEFT_OP additive_expression						{ $$ = createNodeTwo($1, $3, "ShiftExpr", " LEFT_OP ", "AdditiveExpr"); }
	| shift_expression RIGHT_OP additive_expression						{ $$ = createNodeTwo($1, $3, "ShiftExpr", " RIGHT_OP ", "AdditiveExpr"); }
	;

relational_expression
	: shift_expression													{ $$ = createNodeOne($1, "RelationalExpr", "ShiftExpr", NULL); }
	| relational_expression '<' shift_expression						{ $$ = createNodeTwo($1, $3, "RelationalExpr", " < ", "ShiftExpr"); }
	| relational_expression '>' shift_expression						{ $$ = createNodeTwo($1, $3, "RelationalExpr", " > ", "ShiftExpr"); }
	| relational_expression LE_OP shift_expression						{ $$ = createNodeTwo($1, $3, "RelationalExpr", " LE_OP ", "ShiftExpr"); }
	| relational_expression GE_OP shift_expression						{ $$ = createNodeTwo($1, $3, "RelationalExpr", " GE_OP ", "ShiftExpr"); }
	;

equality_expression
	: relational_expression												{ $$ = createNodeOne($1, "EqualityExpr", "RelationalExpr", NULL); }
	| equality_expression EQ_OP relational_expression					{ $$ = createNodeTwo($1, $3, "EqualityExpr", " EQ_OP ", "RelationalExpr"); }
	| equality_expression NE_OP relational_expression					{ $$ = createNodeTwo($1, $3, "EqualityExpr", " NE_OP ", "RelationalExpr"); }
	;

and_expression
	: equality_expression												{ $$ = createNodeOne($1, "AndExpr", "EqualityExpr", NULL); }
	| and_expression '&' equality_expression							{ $$ = createNodeTwo($1, $3, "AndExpr", " & ", "EqualityExpr"); }
	;

exclusive_or_expression
	: and_expression													{ $$ = createNodeOne($1, "ExclusiveOrOp", "AndExpr", NULL); }
	| exclusive_or_expression '^' and_expression						{ $$ = createNodeTwo($1, $3, "ExclusiveOrOp", " ^ ", "AndExpr"); }
	;

inclusive_or_expression
	: exclusive_or_expression											{ $$ = createNodeOne($1, "InclusiveOrOp", "ExclusiveOrOp", NULL); }
	| inclusive_or_expression '|' exclusive_or_expression				{ $$ = createNodeTwo($1, $3, "InclusiveOrOp", " | ", "ExclusiveOrOp"); }
	;

logical_and_expression
	: inclusive_or_expression											{ $$ = createNodeOne($1, "LogicalAndExpr", "InclusiveOrOp", NULL); }
	| logical_and_expression AND_OP inclusive_or_expression				{ $$ = createNodeTwo($1, $3, "LogicalAndExpr", " AND_OP ", "InclusiveOrOp"); }
	;

logical_or_expression
	: logical_and_expression											{ $$ = createNodeOne($1, "LogicalOrExpr", "LogicalAndExpr", NULL); }
	| logical_or_expression OR_OP logical_and_expression				{ $$ = createNodeTwo($1, $3, "LogicalOrExpr", " OR_OP ", "LogicalAndExpr"); }
	;

conditional_expression
	: logical_or_expression												{ $$ = createNodeOne($1, "CondExpr", "LogicalOrExpr", NULL); }
	| logical_or_expression '?' expression ':' conditional_expression	{ $$ = createNodeThree($1, $3, $5, "CondExpr", " LogicalOrExpr ? Expr : CondExpr ", NULL); }
	;

assignment_expression
	: conditional_expression											{ $$ = createNodeOne($1, "AssignExpr", "CondExpr", NULL); }
	| unary_expression assignment_operator assignment_expression        { $$ = createNodeThree($1, $2, $3, "AssignExpr", " UnaryExpr-AssignOp-AssignExpr ", NULL); }
	;

assignment_operator
	: '='																{ $$ = createNodeLeaf("AssignOp", " = ", NULL); }
	| MUL_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " MUL_ASSIGN ", NULL); }
	| DIV_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " DIV_ASSIGN ", NULL); }
	| MOD_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " MOD_ASSIGN ", NULL); }
	| ADD_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " ADD_ASSIGN ", NULL); }
	| SUB_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " SUB_ASSIGN ", NULL); }
	| LEFT_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " LEFT_ASSIGN ", NULL); }
	| RIGHT_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " RIGHT_ASSIGN ", NULL); }
	| AND_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " AND_ASSIGN ", NULL); }
	| XOR_ASSIGN														{ $$ = createNodeLeaf("AssignOp", " XOR_ASSIGN ", NULL); }
	| OR_ASSIGN															{ $$ = createNodeLeaf("AssignOp", " OR_ASSIGN ", NULL); }
	;

expression
	: assignment_expression												{ $$ = createNodeOne($1, "Expr", "AssignExpr", NULL); }
	| expression ',' assignment_expression								{ $$ = createNodeTwo($1, $3, ", Expr", "Expr , AssignExpr", NULL); }
	;

constant_expression
	: conditional_expression											{ $$ = createNodeOne($1, "ConstExpr", "CondExpr", NULL); }
	;

declaration
	: declaration_specifiers ';'										{ $$ = createNodeOne($1, "Declaration", "DeclSpecs", ";"); }
	| declaration_specifiers init_declarator_list ';'					{ $$ = createNodeTwo($1, $2, "Declaration", "DeclSpecs InitDeclList", "List"); }
	;																	
																		
declaration_specifiers													
	: storage_class_specifier											{ $$ = createNodeOne($1, "DeclSpecs", "StorageClassSpec", NULL); }                                          
	| storage_class_specifier declaration_specifiers					{ $$ = createNodeTwo($1, $2, "DeclSpecs", "StorageClassSpec DeclSpecs", NULL); }		
	| type_specifier													{ $$ = createNodeOne($1, "DeclSpecs", "TypeSpec", NULL); }
	| type_specifier declaration_specifiers								{ $$ = createNodeTwo($1, $2, "DeclSpecs", "TypeSpec DeclList", NULL); }
	| type_qualifier													{ $$ = createNodeOne($1, "DeclSpecs", "TypeQual", NULL); }
	| type_qualifier declaration_specifiers								{ $$ = createNodeTwo($1, $2, "DeclSpecs", "TypeQual DeclSpecs", NULL); }
	;

init_declarator_list
	: init_declarator													{ $$ = createNodeOne($1, "InitDeclaratorList", "InitDeclarator", NULL); }
	| init_declarator_list ',' init_declarator							{ $$ = createNodeTwo($1, $3, "InitDeclaratorList" , "InitDecl", NULL); }
	;

init_declarator
	: declarator														{ $$ = createNodeOne($1, "Declarator", "Declarator", NULL); }
	| declarator '=' initializer										{ $$ = createNodeTwo($1, $3, "Declarator", "Decl = InitDecl", NULL); }
	;

storage_class_specifier
	: TYPEDEF															{ $$ = createNodeLeaf("StorageClassSpec", " TYPEDEF ", NULL); }
	| EXTERN															{ $$ = createNodeLeaf("StorageClassSpec", " EXTERN ", NULL); }
	| STATIC															{ $$ = createNodeLeaf("StorageClassSpec", " STATIC ", NULL); }
	| AUTO																{ $$ = createNodeLeaf("StorageClassSpec", " AUTO ", NULL); }
	| REGISTER															{ $$ = createNodeLeaf("StorageClassSpec", " REGISTER ", NULL); }
	| RESTRICT															{ $$ = createNodeLeaf("StorageClassSpec", " RESTRICT ", NULL); }
	;

type_specifier
	: VOID																{ $$ = createNodeLeaf("TypeSpec", " VOID ", NULL); }
	| CHAR																{ $$ = createNodeLeaf("TypeSpec", " CHAR ", NULL); }
	| SHORT																{ $$ = createNodeLeaf("TypeSpec", " SHORT ", NULL); }
	| INT																{ $$ = createNodeLeaf("TypeSpec", " INT ", NULL); }
	| LONG																{ $$ = createNodeLeaf("TypeSpec", " LONG ", NULL); }
	| FLOAT                                                             { $$ = createNodeLeaf("TypeSpec", " FLOAT ", NULL); }
	| DOUBLE															{ $$ = createNodeLeaf("TypeSpec", " DOUBLE ", NULL); }
	| SIGNED															{ $$ = createNodeLeaf("TypeSpec", " SIGNED ", NULL); }
	| UNSIGNED															{ $$ = createNodeLeaf("TypeSpec", " UNSIGNED ", NULL); }
	| _BOOL																{ $$ = createNodeLeaf("TypeSpec", " _BOOL ", NULL); }
	| _COMPLEX															{ $$ = createNodeLeaf("TypeSpec", " _COMPLEX ", NULL); }
	| _IMAGINARY														{ $$ = createNodeLeaf("TypeSpec", " _IMAGINARY ", NULL); }
	| INLINE															{ $$ = createNodeLeaf("TypeSpec", " INLINE ", NULL); }
	| struct_or_union_specifier											{ $$ = createNodeOne($1, "TypeSpec", " StructOrUnion ", NULL); }
	| enum_specifier													{ $$ = createNodeOne($1, "TypeSpec", " Enum ", NULL); }
	| TYPE_NAME															{ $$ = createNodeLeaf("TypeSpec", "TYPE_NAME", NULL); }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'        { $$ = createNodeTwo($1, $4, "StructOrUnionSpec", $2, "{ StructDeclList }"); }
	| struct_or_union '{' struct_declaration_list '}'                   { $$ = createNodeTwo($1, $3, "StructOrUnionSpec", "{ StructDeclList }", "{ }"); }
	| struct_or_union IDENTIFIER                                        { $$ = createNodeOne($1, "StructOrUnionSpec", $2, NULL); }
	;

struct_or_union
	: STRUCT															{ $$ = createNodeLeaf("StructOrUnion", "STRUCT", NULL); }
	| UNION																{ $$ = createNodeLeaf("StructOrUnion", "UNION", NULL); }
	;

struct_declaration_list
	: struct_declaration												{ $$ = createNodeOne($1, "StructDeclList", " StructDecl ", NULL); }
	| struct_declaration_list struct_declaration						{ $$ = createNodeTwo($1, $2, "StructDeclList", " StructDecl ", NULL); }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'				{ $$ = createNodeTwo($1, $2, "StructDecl", " SpecQualList StructDeclList", ";"); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list							{ $$ = createNodeTwo($1, $2, "SpecQualList", " TypeSpec ", "SpecQualifierList"); }
	| type_specifier													{ $$ = createNodeOne($1, "SpecQualList", " TypeSpec ", NULL); }
	| type_qualifier specifier_qualifier_list							{ $$ = createNodeTwo($1, $2, "SpecQualList", " TypeQualifier ", "SpecQulifierList"); }
	| type_qualifier													{ $$ = createNodeOne($1, "SpecQualList", " TypeQualifier ", NULL); }
	;

struct_declarator_list
	: struct_declarator													{ $$ = createNodeOne($1, "StructDeclList", " StructDecl ", NULL); }
	| struct_declarator_list ',' struct_declarator						{ $$ = createNodeTwo($1, $3, "StructDeclList", " , StructDecl ", NULL); }
	;

struct_declarator
	: declarator														{ $$ = createNodeOne($1, " StructDecl", " Declarator ", NULL); }
	| ':' constant_expression											{ $$ = createNodeOne($2, " StructDecl", "ConstExpr", ":"); }
	| declarator ':' constant_expression								{ $$ = createNodeTwo($1, $3, "StrucDecl", " Declarator : ConstExpr ", NULL); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'									    { $$ = createNodeOne($3, "EnumSpecifier", " ENUM { EnumeratorList } ", "{ }"); }
	| ENUM IDENTIFIER '{' enumerator_list '}'                           { $$ = createNodeOne($4, "EnumSpecifier", $2, " ENUM IDENTIFIER { EnumeratorList } "); }
	| ENUM IDENTIFIER												    { $$ = createNodeLeaf("EnumSpecifier", $2, " ENUM IDENTIFIER "); }
	;

enumerator_list
	: enumerator														{ $$ = createNodeOne($1, "EnumeratorList", " Enumerator ", NULL); }
	| enumerator_list ',' enumerator									{ $$ = createNodeTwo($1, $3, "EnumeratorList", " Enumerator", ","); }
	;

enumerator
	: IDENTIFIER														{ $$ = createNodeLeaf("Enumerator",  $1, NULL); }
	| IDENTIFIER '=' constant_expression                                { $$ = createNodeOne($3, "Enumerator", $1, " IDENTIFIER = ConstExpr "); }
	;

type_qualifier
	: CONST																{ $$ = createNodeLeaf("TypeQualifier", " CONST ", NULL); }
	| VOLATILE															{ $$ = createNodeLeaf("TypeQualifier", " VOLATILE ", NULL); }
	;

declarator
	: pointer direct_declarator											{ $$ = createNodeOne($1, "Declarator", "PointerDirectDeclarator", NULL); }									
	| direct_declarator													{ $$ = createNodeOne($1, "Declarator", "DirectDeclarator", NULL); }											
	;

direct_declarator
	: IDENTIFIER														{ $$ = createNodeLeaf("DirectDeclarator", $1, "IDENTIFIER"); }						
	| '(' declarator ')'												{ $$ = createNodeOne($2, "DirectDeclarator", " (Declarator) ", "( d )"); }
	| direct_declarator '[' constant_expression ']'						{ $$ = createNodeTwo($1, $3, "DirectDeclarator", " DirectDecl [ConstExpr] ", "[ ]"); }
	| direct_declarator '[' ']'											{ $$ = createNodeOne($1, "DirectDeclarator", " DirectDecl [] ", NULL); }
	| direct_declarator '(' parameter_type_list ')'						{ $$ = createNodeTwo($1, $3, "DirectDeclarator", " DirectDecl (ParamTypeList) ", "( )"); }
	| direct_declarator '(' identifier_list ')'							{ $$ = createNodeTwo($1, $3, "DirectDeclarator", " DirectDecl (IdentifierList) ", "( )"); }
	| direct_declarator '(' ')'											{ $$ = createNodeLeaf("DirectDeclarator", " DirectDecl () ", NULL); }
	;

pointer
	: '*'																{ $$ = createNodeLeaf("Pointer", " * ", NULL); }
	| '*' pointer														{ $$ = createNodeOne($2, "Pointer", " * Pointer ", NULL); }
	| '*' type_qualifier_list											{ $$ = createNodeOne($2, "Pointer", " * TypeQualList ", NULL); }
	| '*' type_qualifier_list pointer									{ $$ = createNodeTwo($2, $3, "Pointer", " * TypeQualList Pointer ", NULL); }
	;

type_qualifier_list
	: type_qualifier													{ $$ = createNodeOne($1, "TypeQualList", " TypeQual ", NULL); }
	| type_qualifier_list type_qualifier								{ $$ = createNodeTwo($1, $2, "TypeQualList", " TypeQual ", "List"); }
	;															
																
																
parameter_type_list
	: parameter_list													{ $$ = createNodeOne($1, "ParamTypeList", " ParamList", NULL); }
	| parameter_list ',' ELLIPSIS										{ $$ = createNodeOne($1, "ParamTypeList" ," ParamList , ELLIPSIS ", NULL); }
	;

parameter_list
	: parameter_declaration												{ $$ = createNodeOne($1, "ParamList", " ParamDecl ", NULL); }
	| parameter_list ',' parameter_declaration							{ $$ = createNodeTwo($1, $3, "ParamList", " , ParamDecl ", "List"); }	
	;

parameter_declaration
	: declaration_specifiers declarator									{ $$ = createNodeTwo($1, $2, "ParamDecl", " DeclSpec Declarator ", NULL); }
	| declaration_specifiers abstract_declarator						{ $$ = createNodeTwo($1, $2, "ParamDecl", " DeclSpec AbstrDecl ", NULL); }
	| declaration_specifiers											{ $$ = createNodeOne($1, "ParamDecl", " DeclSpecifiers ", NULL); }
	;

identifier_list
	: IDENTIFIER														{ $$ = createNodeLeaf("IdentifierList", $1, NULL); }
	| identifier_list ',' IDENTIFIER									{ $$ = createNodeOne($1, "IdentifierList", $3, "List"); }
	;

type_name
	: specifier_qualifier_list											{ $$ = createNodeOne($1, "TypeName", " SpecQualList ", NULL); }
	| specifier_qualifier_list abstract_declarator						{ $$ = createNodeTwo($1, $2, "TypeName", " SpecQualList AbstrDecl ", NULL); }
	;

abstract_declarator
	: pointer															{ $$ = createNodeOne($1, "AbstrDecl", " Pointer ", NULL); }
	| direct_abstract_declarator										{ $$ = createNodeOne($1, "AbstrDecl", " DirectAbstrDecl ", NULL); }
	| pointer direct_abstract_declarator								{ $$ = createNodeTwo($1, $2, "AbstrDecl", " Pointer DirectAbstrDecl ", NULL); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'									{ $$ = createNodeOne($2, "DirectAbstrDecl", " (AbstrDecl) ", "( )"); }
	| '[' ']'														{ $$ = createNodeLeaf("DirectAbstrDecl", " [] ", NULL); }
	| '[' constant_expression ']'									{ $$ = createNodeOne($2, "DirectAbstrDecl", " [ConstExpr] ", "[ ]"); }
	| direct_abstract_declarator '[' ']'							{ $$ = createNodeOne($1, "DirectAbstrDecl", " DirectAbstrDecl [] ", NULL); }
	| direct_abstract_declarator '[' constant_expression ']'		{ $$ = createNodeTwo($1, $3, "DirectAbstrDecl", " DirectAbstrDecl [ConstExpr]", "[ ]"); }
	| '(' ')'														{ $$ = createNodeLeaf("DirectAbstrDecl", " () ", NULL); }
	| '(' parameter_type_list ')'									{ $$ = createNodeOne($2, "DirectAbstrDecl", " (ParamTypeList) ", "( )"); }
	| direct_abstract_declarator '(' ')'							{ $$ = createNodeOne($1, "DirectAbstrDecl", " DirectAbstrDecl () ", NULL); }
	| direct_abstract_declarator '(' parameter_type_list ')'		{ $$ = createNodeTwo($1, $3, "DirectAbstrDecl", " DirectAbstrDecl (ParamTypeList)", "( )"); }
	;

initializer
	: assignment_expression											{ $$ = createNodeOne($1, "Initializer", " AssignExpr ", NULL); }							
	| '{' initializer_list '}'										{ $$ = createNodeOne($2, "Initializer", " { InitList } ", "{ }"); }
   	| '{' initializer_list ',' '}'									{ $$ = createNodeOne($2, "Initializer", " { InitList , } ", "{ }"); }
	;

initializer_list
	: initializer													{ $$ = createNodeOne($1, "InitializerList", " Initializer ", NULL); }											
	| initializer_list ',' initializer								{ $$ = createNodeTwo($1, $3, "InitializerList", " , Initializer ", "List"); }
	;															
																
statement														
	: labeled_statement												{ $$ = createNodeOne($1, "Statement", " LabeledStatement ", NULL); }									
	| compound_statement											{ $$ = createNodeOne($1, "Statement", " CompoundStatement ", NULL); }
	| expression_statement											{ $$ = createNodeOne($1, "Statement", " ExprStatement ", NULL); }
	| selection_statement											{ $$ = createNodeOne($1, "Statement", " SelectionStatement ", NULL); }
	| iteration_statement											{ $$ = createNodeOne($1, "Statement", " IterationStatement ", NULL); }
	| jump_statement												{ $$ = createNodeOne($1, "Statement", " JumpStatement ", NULL); }
	;

labeled_statement
	: IDENTIFIER ':' statement										{ $$ = createNodeOne($3, "LabeledStatement", $1, " IDENTIFIER : Statement "); }                            
	| CASE constant_expression ':' statement						{ $$ = createNodeTwo($2, $4, "LabeledStatement", " CASE ConstantExpr : Statement", NULL); }
	| DEFAULT ':' statement											{ $$ = createNodeOne($3, "LabeledStatement", " DEFAULT : Statement ", NULL); }
	;

compound_statement
	: '{' '}'														{ $$ = createNodeLeaf("CompoundStatement", " {} ", NULL); }										
	| '{' statement_list '}'										{ $$ = createNodeOne($2, "CompoundStatement", " { StatementList } ", "{ }"); }								
	| '{' declaration_list '}'									    { $$ = createNodeOne($2, "CompoundStatement", " { DeclarationList } ", "{ }"); }
	| '{' declaration_list statement_list '}'					    { $$ = createNodeTwo($2, $3, "CompoundStatement", " { DeclList StatementList }", "{ }"); }
	;

declaration_list
	: declaration													{ $$ = createNodeOne($1, "DeclList", " Decl ", NULL); }								
	| declaration_list declaration									{ $$ = createNodeTwo($1, $2, "DeclList", " Decl ", "List"); }						
	;

statement_list
	: statement														{ $$ = createNodeOne($1, "StatementList", " Statement", NULL); }
	| statement_list statement										{ $$ = createNodeTwo($1, $2, "StatementList", "Statement", "List"); }		
	;

expression_statement
	: ';'															{ $$ = createNodeLeaf("ExprStatement", "EmptyExpression", ";"); }								
	| expression ';'											    { $$ = createNodeOne($1, "ExprStatement", "Expr", ";"); }
	;

selection_statement
	: IF '(' expression ')' compound_statement ELSE compound_statement		{ $$ = createNodeThree($3, $5, $7, "SelectionStatement", " if then else ", "CompStatement"); }
	| IF '(' expression ')' compound_statement								{ $$ = createNodeTwo($3, $5, "SelectionStatement", " if ", "CompStatement"); }
	| IF '(' expression ')' selection_statement                             { $$ = createNodeTwo($3, $5, "SelectionStatement", " if ", "SelectionStatement"); }
	| SWITCH '(' expression ')' statement									{ $$ = createNodeTwo($3, $5, "SelectionStatement", " switch ", "Statement"); }
	;

iteration_statement
	: WHILE '(' expression ')' statement                                             { $$ = createNodeTwo($3, $5, "IterationStatement", " while ", "Statement"); }
	| DO statement WHILE '(' expression ')' ';'                             		 { $$ = createNodeTwo($2, $5, "SelectionStatement", " do-while ", "Statement"); }
	| FOR '(' expression_statement expression_statement ')' statement       		 { $$ = createNodeThree($3, $4, $6, "SelectionStatement", " for ", "For without step expr"); }
	| FOR '(' expression_statement expression_statement expression ')' statement     { $$ = createNodeFour($3, $4, $5, $7, "SelectionStatement", "for", "Normal for loop"); }
	;

jump_statement	
	: GOTO IDENTIFIER ';'								{ $$ = createNodeLeaf("JumpStatement", $2, " GO TO "); }						
	| CONTINUE ';'										{ $$ = createNodeLeaf("JumpStatement", " CONTINUE ", ";"); }							
	| BREAK ';'											{ $$ = createNodeLeaf("JumpStatement", " BREAK ", ";"); }
	| RETURN ';'										{ $$ = createNodeLeaf("JumpStatement", " RETURN ", ";"); }
	| RETURN expression ';'								{ $$ = createNodeOne($2, "JumpStatement", " RETURN Expr ", ";"); }
	;

translation_unit
	: external_declaration								{ $$ = createNodeOne($1, "TransUnit", "Test", NULL); astRoot = $$;}
	| translation_unit external_declaration             { $$ = $1; addLinkToList($$, $2); }															
	;

external_declaration
	: function_definition								{ $$ = createNodeOne($1, "ExtDecl", " Function Definition ", NULL); }														
	| declaration										{ $$ = createNodeOne($1, "ExtDecl", " Declaration ", NULL); }								
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement   { $$ = createNodeFour($1, $2, $3, $4, "FunctionDefinition", " DeclSpec ", "Complete Function Definition"); }        
	| declaration_specifiers declarator compound_statement                    { $$ = createNodeThree($1, $2, $3, "FunctionDefinition", " DeclSpec ", "Function Definition Without Declaration List"); }       
	| declarator declaration_list compound_statement                          { $$ = createNodeThree($1, $2, $3, "FunctionDefinition", "Declarator", "Function Definition Without Specifiers"); }       
	| declarator compound_statement                                           { $$ = createNodeTwo($1, $2, "FunctionDefinition", "Declarator", "Function Definition Short"); }       
	;

%%

extern char yytext[];
extern int column;

int yyerror(char * s) 
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
	return 0;
}