/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONSTANT = 259,                /* CONSTANT  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    SIZEOF = 261,                  /* SIZEOF  */
    PTR_OP = 262,                  /* PTR_OP  */
    INC_OP = 263,                  /* INC_OP  */
    DEC_OP = 264,                  /* DEC_OP  */
    LEFT_OP = 265,                 /* LEFT_OP  */
    RIGHT_OP = 266,                /* RIGHT_OP  */
    LE_OP = 267,                   /* LE_OP  */
    GE_OP = 268,                   /* GE_OP  */
    EQ_OP = 269,                   /* EQ_OP  */
    NE_OP = 270,                   /* NE_OP  */
    AND_OP = 271,                  /* AND_OP  */
    OR_OP = 272,                   /* OR_OP  */
    MUL_ASSIGN = 273,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 274,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 275,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 276,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 277,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 278,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 279,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 280,              /* AND_ASSIGN  */
    XOR_ASSIGN = 281,              /* XOR_ASSIGN  */
    OR_ASSIGN = 282,               /* OR_ASSIGN  */
    TYPE_NAME = 283,               /* TYPE_NAME  */
    TYPEDEF = 284,                 /* TYPEDEF  */
    EXTERN = 285,                  /* EXTERN  */
    STATIC = 286,                  /* STATIC  */
    AUTO = 287,                    /* AUTO  */
    REGISTER = 288,                /* REGISTER  */
    CHAR = 289,                    /* CHAR  */
    SHORT = 290,                   /* SHORT  */
    INT = 291,                     /* INT  */
    LONG = 292,                    /* LONG  */
    SIGNED = 293,                  /* SIGNED  */
    UNSIGNED = 294,                /* UNSIGNED  */
    FLOAT = 295,                   /* FLOAT  */
    DOUBLE = 296,                  /* DOUBLE  */
    CONST = 297,                   /* CONST  */
    VOLATILE = 298,                /* VOLATILE  */
    VOID = 299,                    /* VOID  */
    STRUCT = 300,                  /* STRUCT  */
    UNION = 301,                   /* UNION  */
    ENUM = 302,                    /* ENUM  */
    ELLIPSIS = 303,                /* ELLIPSIS  */
    RESTRICT = 304,                /* RESTRICT  */
    _BOOL = 305,                   /* _BOOL  */
    _COMPLEX = 306,                /* _COMPLEX  */
    _IMAGINARY = 307,              /* _IMAGINARY  */
    INLINE = 308,                  /* INLINE  */
    CASE = 309,                    /* CASE  */
    DEFAULT = 310,                 /* DEFAULT  */
    IF = 311,                      /* IF  */
    ELSE = 312,                    /* ELSE  */
    SWITCH = 313,                  /* SWITCH  */
    WHILE = 314,                   /* WHILE  */
    DO = 315,                      /* DO  */
    FOR = 316,                     /* FOR  */
    GOTO = 317,                    /* GOTO  */
    CONTINUE = 318,                /* CONTINUE  */
    BREAK = 319,                   /* BREAK  */
    RETURN = 320                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_AUTO = 32,                      /* AUTO  */
  YYSYMBOL_REGISTER = 33,                  /* REGISTER  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CONST = 42,                     /* CONST  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_ENUM = 47,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 48,                  /* ELLIPSIS  */
  YYSYMBOL_RESTRICT = 49,                  /* RESTRICT  */
  YYSYMBOL__BOOL = 50,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 51,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 52,                /* _IMAGINARY  */
  YYSYMBOL_INLINE = 53,                    /* INLINE  */
  YYSYMBOL_CASE = 54,                      /* CASE  */
  YYSYMBOL_DEFAULT = 55,                   /* DEFAULT  */
  YYSYMBOL_IF = 56,                        /* IF  */
  YYSYMBOL_ELSE = 57,                      /* ELSE  */
  YYSYMBOL_SWITCH = 58,                    /* SWITCH  */
  YYSYMBOL_WHILE = 59,                     /* WHILE  */
  YYSYMBOL_DO = 60,                        /* DO  */
  YYSYMBOL_FOR = 61,                       /* FOR  */
  YYSYMBOL_GOTO = 62,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 63,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 64,                     /* BREAK  */
  YYSYMBOL_RETURN = 65,                    /* RETURN  */
  YYSYMBOL_66_ = 66,                       /* '('  */
  YYSYMBOL_67_ = 67,                       /* ')'  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_70_ = 70,                       /* '.'  */
  YYSYMBOL_71_ = 71,                       /* ','  */
  YYSYMBOL_72_ = 72,                       /* '&'  */
  YYSYMBOL_73_ = 73,                       /* '*'  */
  YYSYMBOL_74_ = 74,                       /* '+'  */
  YYSYMBOL_75_ = 75,                       /* '-'  */
  YYSYMBOL_76_ = 76,                       /* '~'  */
  YYSYMBOL_77_ = 77,                       /* '!'  */
  YYSYMBOL_78_ = 78,                       /* '/'  */
  YYSYMBOL_79_ = 79,                       /* '%'  */
  YYSYMBOL_80_ = 80,                       /* '<'  */
  YYSYMBOL_81_ = 81,                       /* '>'  */
  YYSYMBOL_82_ = 82,                       /* '^'  */
  YYSYMBOL_83_ = 83,                       /* '|'  */
  YYSYMBOL_84_ = 84,                       /* '?'  */
  YYSYMBOL_85_ = 85,                       /* ':'  */
  YYSYMBOL_86_ = 86,                       /* '='  */
  YYSYMBOL_87_ = 87,                       /* ';'  */
  YYSYMBOL_88_ = 88,                       /* '{'  */
  YYSYMBOL_89_ = 89,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 90,                  /* $accept  */
  YYSYMBOL_primary_expression = 91,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 92,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 93,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 94,          /* unary_expression  */
  YYSYMBOL_unary_operator = 95,            /* unary_operator  */
  YYSYMBOL_cast_expression = 96,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 97, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 98,       /* additive_expression  */
  YYSYMBOL_shift_expression = 99,          /* shift_expression  */
  YYSYMBOL_relational_expression = 100,    /* relational_expression  */
  YYSYMBOL_equality_expression = 101,      /* equality_expression  */
  YYSYMBOL_and_expression = 102,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 103,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 104,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 105,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 106,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 107,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 108,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 109,      /* assignment_operator  */
  YYSYMBOL_expression = 110,               /* expression  */
  YYSYMBOL_constant_expression = 111,      /* constant_expression  */
  YYSYMBOL_declaration = 112,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 113,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 114,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 115,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 116,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 117,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 118, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 119,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 120,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 121,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 122, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 123,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 124,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 125,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 126,          /* enumerator_list  */
  YYSYMBOL_enumerator = 127,               /* enumerator  */
  YYSYMBOL_type_qualifier = 128,           /* type_qualifier  */
  YYSYMBOL_declarator = 129,               /* declarator  */
  YYSYMBOL_direct_declarator = 130,        /* direct_declarator  */
  YYSYMBOL_pointer = 131,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 132,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 133,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 134,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 135,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 136,          /* identifier_list  */
  YYSYMBOL_type_name = 137,                /* type_name  */
  YYSYMBOL_abstract_declarator = 138,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 139, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 140,              /* initializer  */
  YYSYMBOL_initializer_list = 141,         /* initializer_list  */
  YYSYMBOL_statement = 142,                /* statement  */
  YYSYMBOL_labeled_statement = 143,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 144,       /* compound_statement  */
  YYSYMBOL_declaration_list = 145,         /* declaration_list  */
  YYSYMBOL_statement_list = 146,           /* statement_list  */
  YYSYMBOL_expression_statement = 147,     /* expression_statement  */
  YYSYMBOL_selection_statement = 148,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 149,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 150,           /* jump_statement  */
  YYSYMBOL_translation_unit = 151,         /* translation_unit  */
  YYSYMBOL_external_declaration = 152,     /* external_declaration  */
  YYSYMBOL_function_definition = 153       /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,     2,     2,    79,    72,     2,
      66,    67,    73,    74,    71,    75,    70,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    87,
      80,    86,    81,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,    83,    89,    76,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    19,    19,    20,    21,    22,    26,    27,    28,    29,
      30,    31,    32,    33,    37,    38,    42,    43,    44,    45,
      46,    47,    51,    52,    53,    54,    55,    56,    60,    61,
      65,    66,    67,    68,    72,    73,    74,    78,    79,    80,
      84,    85,    86,    87,    88,    92,    93,    94,    98,    99,
     103,   104,   108,   109,   113,   114,   118,   119,   123,   124,
     128,   129,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   147,   148,   152,   156,   157,   161,   162,
     163,   164,   165,   166,   170,   171,   175,   176,   180,   181,
     182,   183,   184,   185,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     208,   209,   210,   214,   215,   219,   220,   224,   228,   229,
     230,   231,   235,   236,   240,   241,   242,   246,   247,   248,
     252,   253,   257,   258,   262,   263,   267,   268,   272,   273,
     274,   275,   276,   277,   278,   282,   283,   284,   285,   289,
     290,   295,   296,   300,   301,   305,   306,   307,   311,   312,
     316,   317,   321,   322,   323,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   339,   340,   341,   345,   346,   350,
     351,   352,   353,   354,   355,   359,   360,   361,   365,   366,
     367,   368,   372,   373,   377,   378,   382,   383,   387,   388,
     389,   390,   394,   395,   396,   397,   401,   402,   403,   404,
     405,   409,   410,   414,   415,   419,   420,   421,   422
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "RESTRICT", "_BOOL", "_COMPLEX", "_IMAGINARY",
  "INLINE", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'",
  "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    40,    41,    91,    93,
      46,    44,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    58,    61,    59,   123,   125
};
#endif

#define YYPACT_NINF (-232)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     945,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,     7,  -232,  -232,  -232,  -232,  -232,    57,   141,  -232,
      31,  1255,  1255,  -232,    23,  -232,  1255,  1117,   176,     8,
     843,  -232,  -232,   -65,    52,   -15,  -232,  -232,   141,  -232,
     -24,  -232,  1056,  -232,  -232,   -19,  1086,  -232,   285,  -232,
      31,  -232,  1117,   996,   231,   176,  -232,  -232,    52,    -4,
     -10,  -232,  -232,  -232,  -232,    57,  -232,   204,  -232,  1117,
    1086,  1086,   417,  -232,     4,  1086,    16,  -232,  -232,   749,
     765,   765,   789,    34,    72,    75,    83,   546,   115,   194,
     118,   139,   563,   639,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,  -232,  -232,   185,   197,   789,  -232,    66,   111,   291,
      45,   296,   157,   161,   171,   258,    18,  -232,  -232,    49,
    -232,  -232,  -232,   360,   435,  -232,  -232,  -232,  -232,   247,
    -232,  -232,  -232,  -232,    56,   275,   283,  -232,   131,  -232,
    -232,  -232,  -232,   298,    -3,   789,    52,  -232,  -232,   204,
    -232,  -232,  -232,  1030,  -232,  -232,  -232,   789,   101,  -232,
     290,  -232,   546,   639,  -232,   789,  -232,  -232,   294,   546,
     789,   789,   789,   317,   585,   293,  -232,  -232,  -232,   103,
     132,   114,   314,   379,  -232,  -232,   660,   789,   380,  -232,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,
     789,  -232,   789,   789,   789,   789,   789,   789,   789,   789,
     789,   789,   789,   789,   789,   789,   789,   789,   789,   789,
     789,   789,  -232,  -232,   471,  -232,  -232,   894,   690,  -232,
       5,  -232,   191,  -232,  1229,  -232,   381,  -232,  -232,  -232,
    -232,  -232,     9,  -232,  -232,     4,  -232,   789,  -232,   318,
     546,  -232,   133,   160,   189,   320,   585,  -232,  -232,  -232,
    1143,   196,  -232,   789,  -232,  -232,   198,  -232,   227,  -232,
    -232,  -232,  -232,  -232,    66,    66,   111,   111,   291,   291,
     291,   291,    45,    45,   296,   157,   161,   171,   258,   -23,
    -232,  -232,  -232,   341,   350,  -232,   358,   191,  1189,   714,
    -232,  -232,  -232,   510,  -232,  -232,  -232,  -232,  -232,    90,
     217,   546,   789,   735,  -232,  -232,   789,  -232,   789,  -232,
    -232,  -232,  -232,   361,  -232,   362,  -232,  -232,   330,  -232,
    -232,  -232,   201,   546,   228,  -232,  -232,  -232,  -232,   342,
     355,  -232,   546,  -232,  -232,  -232
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   138,   109,    88,    89,    90,    91,    92,    95,    96,
      97,    98,   101,   102,    99,   100,   134,   135,    94,   113,
     114,     0,    93,   103,   104,   105,   106,     0,   145,   214,
       0,    78,    80,   107,     0,   108,    82,     0,   137,     0,
       0,   211,   213,   129,     0,     0,   149,   147,   146,    76,
       0,    84,    86,    79,    81,   112,     0,    83,     0,   192,
       0,   218,     0,     0,     0,   136,     1,   212,     0,   132,
       0,   130,   139,   150,   148,     0,    77,     0,   216,     0,
       0,   119,     0,   115,     0,   121,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
     196,   188,     6,    16,    28,     0,    30,    34,    37,    40,
      45,    48,    50,    52,    54,    56,    58,    60,    73,     0,
     194,   179,   180,     0,     0,   181,   182,   183,   184,    86,
     193,   217,   158,   144,   157,     0,   151,   153,     0,     2,
     141,    28,    75,     0,     0,     0,     0,   127,    85,     0,
     174,    87,   215,     0,   118,   111,   116,     0,     0,   122,
     124,   120,     0,     0,    20,     0,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,   207,   208,   209,     0,
       0,   160,     0,     0,    12,    13,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    62,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   190,     0,   189,   195,     0,     0,   155,
     162,   156,   163,   142,     0,   143,     0,   140,   128,   133,
     131,   177,     0,   110,   125,     0,   117,     0,   185,     0,
       0,   187,     0,     0,     0,     0,     0,   206,   210,     5,
       0,   162,   161,     0,    11,     8,     0,    14,     0,    10,
      61,    31,    32,    33,    35,    36,    38,    39,    43,    44,
      41,    42,    46,    47,    49,    51,    53,    55,    57,     0,
      74,   191,   170,     0,     0,   166,     0,   164,     0,     0,
     152,   154,   159,     0,   175,   123,   126,    21,   186,     0,
       0,     0,     0,     0,    29,     9,     0,     7,     0,   171,
     165,   167,   172,     0,   168,     0,   176,   178,   199,   200,
     201,   202,     0,     0,     0,    15,    59,   173,   169,     0,
       0,   204,     0,   198,   203,   205
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -232,  -232,  -232,  -232,   -62,  -232,   -98,   137,   138,    65,
     147,   221,   203,   223,   237,   242,  -232,   -61,   -63,  -232,
     -90,   -68,    38,     1,  -232,   391,  -232,   -36,  -232,  -232,
     392,   -60,   -31,  -232,   218,  -232,   410,   325,    28,    -9,
     -34,   -12,  -232,   -59,  -232,   238,  -232,   310,   -79,  -231,
    -140,  -232,   -91,  -232,   -37,    76,   351,  -145,    58,  -232,
    -232,  -232,   445,  -232
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   112,   113,   276,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   210,
     129,   153,    59,    60,    50,    51,    31,    32,    33,    34,
      82,    83,    84,   168,   169,    35,    70,    71,    36,    37,
      38,    39,    48,   303,   146,   147,   148,   192,   304,   242,
     161,   252,   130,   131,   132,    62,   134,   135,   136,   137,
     138,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    30,   151,   152,   145,    65,   183,     1,     1,   307,
      43,     1,   189,   190,   160,    78,    47,   211,    45,   251,
      81,    52,   166,    68,   178,   141,    55,   174,   176,   177,
     151,   152,    53,    54,     1,   229,    74,    57,    29,   266,
     307,    30,   162,   236,    81,    81,    81,    75,   231,    81,
     164,   139,    72,   151,   171,    69,    46,   219,   220,     1,
       1,   156,   328,    76,   144,   241,   139,    81,   156,    80,
      27,   237,   191,   238,    27,   170,    73,    28,    29,   157,
     313,   258,   155,   190,    85,   190,   248,   249,   261,   167,
     262,   263,   264,   151,   152,    44,   160,    27,   314,   254,
     140,   172,   230,   166,    28,   151,   152,   278,    85,    85,
      85,    56,   272,    85,   281,   282,   283,   140,    49,   179,
     231,   323,   237,    27,   238,   221,   222,    81,    79,    28,
      28,    85,   240,   277,   133,   239,   232,    81,   180,   212,
     299,   181,   191,   236,   213,   214,    94,   280,    95,   182,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   300,   318,
     306,   140,   255,   337,   231,   324,   151,   152,    58,   271,
     270,   184,   238,    16,    17,   215,   216,    28,   256,   316,
     268,    85,   193,   194,   195,   151,   152,   185,   245,   269,
     319,    85,   246,   231,   231,   186,    65,   149,    87,    88,
      89,   151,    90,    91,    28,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   240,   187,   320,    45,   225,
     341,   231,   342,   344,   149,    87,    88,    89,   144,    90,
      91,   335,    63,   226,    64,   144,   170,   151,   152,   333,
     160,   196,   351,   197,   227,   198,   321,   308,   271,   309,
     231,   355,   270,   345,   238,   325,   151,   346,   350,   326,
     103,   144,   231,    94,   228,    95,   104,   105,   106,   107,
     108,   109,   338,   209,   288,   289,   290,   291,    86,    87,
      88,    89,   159,    90,    91,   352,   327,   103,   231,   231,
     150,   217,   218,   104,   105,   106,   107,   108,   109,   144,
     223,   224,   353,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    77,    22,    23,    24,    25,    26,    92,
      93,    94,   243,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   284,   285,   244,   286,   287,   104,   105,   106,
     107,   108,   109,    86,    87,    88,    89,   247,    90,    91,
     292,   293,   110,    58,   111,   257,   265,   339,   340,   260,
     267,   273,   274,   279,   312,   317,   322,   349,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   329,    22,
      23,    24,    25,    26,    92,    93,    94,   330,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   331,   347,   295,
      58,   348,   104,   105,   106,   107,   108,   109,    86,    87,
      88,    89,   354,    90,    91,     2,   294,   110,    58,   233,
     296,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   297,   158,    23,    24,    25,
      26,   298,   163,   315,    86,    87,    88,    89,   154,    90,
      91,   250,   311,   259,   234,    67,     0,     0,     0,    92,
      93,    94,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   165,   104,   105,   106,
     107,   108,   109,   149,    87,    88,    89,     0,    90,    91,
       0,     0,   110,    58,   235,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,    86,
      87,    88,    89,     0,    90,    91,     0,     0,   110,    58,
     301,     0,     0,     0,     0,     0,   149,    87,    88,    89,
       0,    90,    91,     0,     0,     0,   103,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   149,    87,
      88,    89,     0,    90,    91,     0,     0,     0,   159,   336,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   103,
       0,     0,     0,   110,    58,   104,   105,   106,   107,   108,
     109,     0,   149,    87,    88,    89,     0,    90,    91,     0,
     188,   103,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   149,    87,    88,    89,     2,    90,    91,
       0,     0,   110,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    23,
      24,    25,    26,   149,    87,    88,    89,     0,    90,    91,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   149,    87,    88,
      89,     0,    90,    91,     0,     0,   103,   275,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   149,    87,
      88,    89,     0,    90,    91,     0,     0,     0,     0,     0,
       0,     0,   149,    87,    88,    89,   103,    90,    91,   305,
       0,     0,   104,   105,   106,   107,   108,   109,   149,    87,
      88,    89,     0,    90,    91,     0,     0,     0,     0,     0,
     103,     0,     0,   334,     0,     0,   104,   105,   106,   107,
     108,   109,   149,    87,    88,    89,     0,    90,    91,     0,
       0,   103,   343,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,     0,   173,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,    66,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,    23,    24,    25,    26,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   302,   238,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,   143,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
      23,    24,    25,    26,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     2,     0,     0,     0,     0,   253,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,    23,    24,    25,    26,
       0,     0,    77,     0,    58,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,   270,
     302,   238,     0,     0,     0,     0,    28,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   332,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   310,    22,    23,
      24,    25,    26,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26
};

static const yytype_int16 yycheck[] =
{
      37,     0,    64,    64,    63,    39,    97,     3,     3,   240,
       3,     3,   102,   103,    77,    52,    28,   115,    27,   159,
      56,    30,    82,    88,    92,    62,     3,    89,    90,    91,
      92,    92,    31,    32,     3,    17,    48,    36,     0,   184,
     271,    40,    79,   134,    80,    81,    82,    71,    71,    85,
      81,    60,    67,   115,    85,     3,    28,    12,    13,     3,
       3,    71,    85,    87,    63,   144,    75,   103,    71,    88,
      66,    66,   103,    68,    66,    84,    48,    73,    40,    89,
      71,   172,    86,   173,    56,   175,    89,   155,   179,    85,
     180,   181,   182,   155,   155,    88,   159,    66,    89,   167,
      62,    85,    84,   163,    73,   167,   167,   197,    80,    81,
      82,    88,   191,    85,   212,   213,   214,    79,    87,    85,
      71,   266,    66,    66,    68,    80,    81,   163,    52,    73,
      73,   103,   144,   196,    58,   144,    87,   173,    66,    73,
     230,    66,   173,   234,    78,    79,    56,   210,    58,    66,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   231,   260,
     238,   133,    71,   313,    71,   273,   238,   238,    88,   191,
      66,    66,    68,    42,    43,    74,    75,    73,    87,   257,
      87,   163,     7,     8,     9,   257,   257,     3,    67,    67,
      67,   173,    71,    71,    71,    87,   240,     3,     4,     5,
       6,   273,     8,     9,    73,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   237,    87,    67,   237,    72,
     321,    71,   322,   323,     3,     4,     5,     6,   237,     8,
       9,   309,    66,    82,    68,   244,   255,   309,   309,   308,
     313,    66,   343,    68,    83,    70,    67,    66,   270,    68,
      71,   352,    66,   326,    68,    67,   328,   328,    67,    71,
      66,   270,    71,    56,    16,    58,    72,    73,    74,    75,
      76,    77,   319,    86,   219,   220,   221,   222,     3,     4,
       5,     6,    88,     8,     9,    67,    69,    66,    71,    71,
      69,    10,    11,    72,    73,    74,    75,    76,    77,   308,
      14,    15,   349,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    86,    49,    50,    51,    52,    53,    54,
      55,    56,    67,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   215,   216,    71,   217,   218,    72,    73,    74,
      75,    76,    77,     3,     4,     5,     6,    69,     8,     9,
     223,   224,    87,    88,    89,    85,    59,   319,   320,    85,
      87,    67,     3,     3,     3,    67,    66,    57,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    67,    49,
      50,    51,    52,    53,    54,    55,    56,    67,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    69,    67,   226,
      88,    69,    72,    73,    74,    75,    76,    77,     3,     4,
       5,     6,    87,     8,     9,    28,   225,    87,    88,    89,
     227,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   228,    75,    50,    51,    52,
      53,   229,    80,   255,     3,     4,     5,     6,    68,     8,
       9,   156,   244,   173,   133,    40,    -1,    -1,    -1,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    89,    72,    73,    74,
      75,    76,    77,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    87,    88,    89,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    88,    89,
      54,    55,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    87,    88,    72,    73,    74,    75,    76,
      77,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      87,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,     3,     4,     5,     6,    28,     8,     9,
      -1,    -1,    87,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    50,
      51,    52,    53,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    66,     8,     9,    69,
      -1,    -1,    72,    73,    74,    75,    76,    77,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,     0,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    53,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    67,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      50,    51,    52,    53,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    89,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    50,    51,    52,    53,
      -1,    -1,    86,    -1,    88,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    73,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,    50,    51,    52,    53,    66,    73,   112,
     113,   116,   117,   118,   119,   125,   128,   129,   130,   131,
     151,   152,   153,     3,    88,   129,   128,   131,   132,    87,
     114,   115,   129,   113,   113,     3,    88,   113,    88,   112,
     113,   144,   145,    66,    68,   130,     0,   152,    88,     3,
     126,   127,    67,   128,   131,    71,    87,    86,   144,   145,
      88,   117,   120,   121,   122,   128,     3,     4,     5,     6,
       8,     9,    54,    55,    56,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    72,    73,    74,    75,    76,    77,
      87,    89,    91,    92,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   110,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   129,
     112,   144,     3,    67,   113,   133,   134,   135,   136,     3,
      69,    94,   107,   111,   126,    86,    71,    89,   115,    88,
     108,   140,   144,   120,   122,    89,   121,    85,   123,   124,
     129,   122,    85,    66,    94,    66,    94,    94,   111,    85,
      66,    66,    66,   142,    66,     3,    87,    87,    87,   110,
     110,   122,   137,     7,     8,     9,    66,    68,    70,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    86,
     109,    96,    73,    78,    79,    74,    75,    10,    11,    12,
      13,    80,    81,    14,    15,    72,    82,    83,    16,    17,
      84,    71,    87,    89,   146,    89,   142,    66,    68,   129,
     131,   138,   139,    67,    71,    67,    71,    69,    89,   111,
     127,   140,   141,    89,   111,    71,    87,    85,   142,   137,
      85,   142,   110,   110,   110,    59,   147,    87,    87,    67,
      66,   131,   138,    67,     3,    67,    93,   108,   110,     3,
     108,    96,    96,    96,    97,    97,    98,    98,    99,    99,
      99,    99,   100,   100,   101,   102,   103,   104,   105,   110,
     108,    89,    67,   133,   138,    69,   111,   139,    66,    68,
      48,   135,     3,    71,    89,   124,   111,    67,   142,    67,
      67,    67,    66,   147,    96,    67,    71,    69,    85,    67,
      67,    69,    67,   133,    69,   111,    89,   140,   144,   148,
     148,   142,   110,    67,   110,   108,   107,    67,    69,    57,
      67,   142,    67,   144,    87,   142
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    97,    97,    98,    98,    98,    99,    99,    99,
     100,   100,   100,   100,   100,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   118,   119,   119,   120,   120,   121,   122,   122,
     122,   122,   123,   123,   124,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   135,   136,   136,
     137,   137,   138,   138,   138,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   140,   141,   141,   142,
     142,   142,   142,   142,   142,   143,   143,   143,   144,   144,
     144,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     148,   148,   149,   149,   149,   149,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   153,   153,   153,   153
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     3,     2,     1,
       2,     1,     1,     3,     1,     2,     3,     4,     5,     2,
       1,     3,     1,     3,     1,     1,     2,     1,     1,     3,
       4,     3,     4,     4,     3,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       3,     4,     1,     2,     1,     2,     1,     2,     7,     5,
       5,     5,     5,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     4,     3,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 1773 "c.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 425 "c.y"

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
