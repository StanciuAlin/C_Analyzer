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
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'										{ $$ = createVarDeclaration($1, $1, 0);}
	| declaration_specifiers init_declarator_list ';'					{ $$ = createVarDeclaration($1, $2, 0);}
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier													{ $$ = createVarDeclaration($1, $1, 0);}
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	| RESTRICT
	;

type_specifier
	: VOID																{$$ = createTypeSpecifier("VOID");}
	| CHAR																{$$ = createTypeSpecifier("CHAR");}
	| SHORT																{$$ = createTypeSpecifier("SHORT");}
	| INT																{$$ = createTypeSpecifier("INT");}
	| LONG																{$$ = createTypeSpecifier("LONG");}
	| FLOAT                                                             {$$ = createTypeSpecifier("FLOAT");}
	| DOUBLE															{$$ = createTypeSpecifier("DOUBLE");}
	| SIGNED															{$$ = createTypeSpecifier("SIGNED");}
	| UNSIGNED															{$$ = createTypeSpecifier("UNSIGNED");}
	| _BOOL																{$$ = createTypeSpecifier("_BOOL");}
	| _COMPLEX															{$$ = createTypeSpecifier("_COMPLEX");}
	| _IMAGINARY														{$$ = createTypeSpecifier("_IMAGINARY");}
	| INLINE															{$$ = createTypeSpecifier("INLINE");}
	| struct_or_union_specifier											
	| enum_specifier													
	| TYPE_NAME															{$$ = createTypeSpecifier("TYPE_NAME");}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration										{ $$ = createListNode("ParametersList", $1);}
	| parameter_list ',' parameter_declaration					{ 
																	$$ = $1;
																	addLinkToList($$, $3);
																}
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement											  { $$ = createStatement($1); }
	| compound_statement										  { $$ = createStatement($1); }
	| expression_statement										  { $$ = createStatement($1); }
	| selection_statement										  { $$ = createStatement($1); }
	| iteration_statement										  { $$ = createStatement($1); }
	| jump_statement											  { $$ = createStatement($1); }
	;

labeled_statement
	: IDENTIFIER ':' statement                                     { $$ = createLabeledStatement("", NULL, $3); }
	| CASE constant_expression ':' statement                       { $$ = createLabeledStatement("", $2, $4); }
	| DEFAULT ':' statement										   { $$ = createLabeledStatement("", NULL, $3); }
	;

compound_statement
	: '{' '}'														{ $$ = createCompoundStatement(NULL, NULL); }
	| '{' statement_list '}'										{ $$ = createCompoundStatement($2, NULL); }
	| '{' declaration_list '}'										{ $$ = createCompoundStatement($2, NULL); }
	| '{' declaration_list statement_list '}'						{ $$ = createCompoundStatement($2, $3); }
	;

declaration_list
	: declaration													{ $$ = createListNode("LocalDeclarations", $1); }
	| declaration_list declaration									{
																		$$ = $1;
																		addLinkToList($$, $2);
																	}
	;

statement_list
	: statement														{ $$ = createListNode("InstructionsList", $1);}
	| statement_list statement										{
																		$$ = $1;
																		addLinkToList($$, $2);
																	}
	;

expression_statement
	: ';'															{ $$ = createExpressionStatement(NULL); }
	| expression ';'												{ $$ = createExpressionStatement($1); }
	;

selection_statement
	: IF '(' expression ')' compound_statement ELSE compound_statement		{ $$ = createIfStatement($3, $5, $7); }
	| IF '(' expression ')' compound_statement								{ $$ = createIfStatement($3, $5, NULL); }
	| IF '(' expression ')' selection_statement                             { $$ = createIfStatement($3, $5, NULL); }
	| SWITCH '(' expression ')' statement									{ $$ = createSwitchStatement($3, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement                                              { $$ = createWhileStatement($3, $5); }
	| DO statement WHILE '(' expression ')' ';'                                       { $$ = createDoWhileStatement($2, $5); }
	| FOR '(' expression_statement expression_statement ')' statement                 { $$ = createForStatement($3, $4, NULL, $6); }
	| FOR '(' expression_statement expression_statement expression ')' statement      { $$ = createForStatement($3, $4, $5, $7); }
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration								{ $$ = createTranslationUnitNode($1); astRoot = $$;}
	| translation_unit external_declaration             {							 
														  $$ = $1; 
														  addLinkToList($$, $2);
														}
	;

external_declaration
	: function_definition								{ $$ = createExternalDeclarationNode($1);}
	| declaration										{$$ = createExternalDeclarationNode($1);}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement          { $$ = createFunctionDeclarationNode($1, $2, $3, $4); }
	| declaration_specifiers declarator compound_statement                           { $$ = createFunctionDeclarationNode($1, $2, NULL, $3); }
	| declarator declaration_list compound_statement                                 { $$ = createFunctionDeclarationNode(NULL, $1, $2, $3); }
	| declarator compound_statement                                                  { $$ = createFunctionDeclarationNode(NULL, $1, NULL, $2); }
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