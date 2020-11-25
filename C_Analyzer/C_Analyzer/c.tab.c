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




/* First part of user prologue.  */
#line 1 "c.y"

#include "ast.h"
#include <stdio.h>

Node* astRoot = NULL;

#line 78 "c.tab.c"

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

#include "c.tab.h"
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
  YYSYMBOL_COMM_MULTI_LINE = 66,           /* COMM_MULTI_LINE  */
  YYSYMBOL_COMM_UNI_LINE = 67,             /* COMM_UNI_LINE  */
  YYSYMBOL_68_ = 68,                       /* '('  */
  YYSYMBOL_69_ = 69,                       /* ')'  */
  YYSYMBOL_70_ = 70,                       /* '['  */
  YYSYMBOL_71_ = 71,                       /* ']'  */
  YYSYMBOL_72_ = 72,                       /* '.'  */
  YYSYMBOL_73_ = 73,                       /* ','  */
  YYSYMBOL_74_ = 74,                       /* '&'  */
  YYSYMBOL_75_ = 75,                       /* '*'  */
  YYSYMBOL_76_ = 76,                       /* '+'  */
  YYSYMBOL_77_ = 77,                       /* '-'  */
  YYSYMBOL_78_ = 78,                       /* '~'  */
  YYSYMBOL_79_ = 79,                       /* '!'  */
  YYSYMBOL_80_ = 80,                       /* '/'  */
  YYSYMBOL_81_ = 81,                       /* '%'  */
  YYSYMBOL_82_ = 82,                       /* '<'  */
  YYSYMBOL_83_ = 83,                       /* '>'  */
  YYSYMBOL_84_ = 84,                       /* '^'  */
  YYSYMBOL_85_ = 85,                       /* '|'  */
  YYSYMBOL_86_ = 86,                       /* '?'  */
  YYSYMBOL_87_ = 87,                       /* ':'  */
  YYSYMBOL_88_ = 88,                       /* '='  */
  YYSYMBOL_89_ = 89,                       /* ';'  */
  YYSYMBOL_90_ = 90,                       /* '{'  */
  YYSYMBOL_91_ = 91,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_primary_expression = 93,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 94,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 95,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 96,          /* unary_expression  */
  YYSYMBOL_unary_operator = 97,            /* unary_operator  */
  YYSYMBOL_cast_expression = 98,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 99, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 100,      /* additive_expression  */
  YYSYMBOL_shift_expression = 101,         /* shift_expression  */
  YYSYMBOL_relational_expression = 102,    /* relational_expression  */
  YYSYMBOL_equality_expression = 103,      /* equality_expression  */
  YYSYMBOL_and_expression = 104,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 105,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 106,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 107,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 108,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 109,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 110,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 111,      /* assignment_operator  */
  YYSYMBOL_expression = 112,               /* expression  */
  YYSYMBOL_constant_expression = 113,      /* constant_expression  */
  YYSYMBOL_declaration = 114,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 115,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 116,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 117,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 118,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 119,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 120, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 121,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 122,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 123,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 124, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 125,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 126,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 127,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 128,          /* enumerator_list  */
  YYSYMBOL_enumerator = 129,               /* enumerator  */
  YYSYMBOL_type_qualifier = 130,           /* type_qualifier  */
  YYSYMBOL_declarator = 131,               /* declarator  */
  YYSYMBOL_direct_declarator = 132,        /* direct_declarator  */
  YYSYMBOL_pointer = 133,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 134,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 135,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 136,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 137,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 138,          /* identifier_list  */
  YYSYMBOL_type_name = 139,                /* type_name  */
  YYSYMBOL_abstract_declarator = 140,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 141, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 142,              /* initializer  */
  YYSYMBOL_initializer_list = 143,         /* initializer_list  */
  YYSYMBOL_statement = 144,                /* statement  */
  YYSYMBOL_labeled_statement = 145,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 146,       /* compound_statement  */
  YYSYMBOL_declaration_list = 147,         /* declaration_list  */
  YYSYMBOL_statement_list = 148,           /* statement_list  */
  YYSYMBOL_expression_statement = 149,     /* expression_statement  */
  YYSYMBOL_selection_statement = 150,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 151,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 152,           /* jump_statement  */
  YYSYMBOL_translation_unit = 153,         /* translation_unit  */
  YYSYMBOL_external_declaration = 154,     /* external_declaration  */
  YYSYMBOL_function_definition = 155       /* function_definition  */
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
#define YYLAST   1347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
       2,     2,     2,    79,     2,     2,     2,    81,    74,     2,
      68,    69,    75,    76,    73,    77,    72,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    89,
      82,    88,    83,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,    85,    91,    78,     2,     2,     2,
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
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   148,   149,   150,   154,   155,   156,   157,
     158,   159,   160,   161,   165,   166,   170,   171,   172,   173,
     174,   175,   179,   180,   181,   182,   183,   184,   188,   189,
     193,   194,   195,   196,   200,   201,   202,   206,   207,   208,
     212,   213,   214,   215,   216,   220,   221,   222,   226,   227,
     231,   232,   236,   237,   241,   242,   246,   247,   251,   252,
     256,   257,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   275,   276,   280,   284,   285,   289,   290,
     291,   292,   293,   294,   298,   299,   303,   304,   308,   309,
     310,   311,   312,   313,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     336,   337,   338,   342,   343,   347,   348,   352,   356,   357,
     358,   359,   363,   364,   368,   369,   370,   374,   375,   376,
     380,   381,   385,   386,   390,   391,   395,   396,   400,   401,
     402,   403,   404,   405,   406,   410,   411,   412,   413,   417,
     418,   423,   424,   428,   429,   436,   437,   438,   442,   443,
     447,   448,   452,   453,   454,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   470,   471,   472,   476,   477,   481,
     482,   483,   484,   485,   486,   490,   491,   492,   496,   497,
     498,   499,   503,   504,   511,   512,   519,   520,   524,   525,
     526,   527,   531,   532,   533,   534,   538,   539,   540,   541,
     542,   546,   547,   554,   555,   559,   560,   561,   562
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
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "COMM_MULTI_LINE",
  "COMM_UNI_LINE", "'('", "')'", "'['", "']'", "'.'", "','", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
     315,   316,   317,   318,   319,   320,   321,   322,    40,    41,
      91,    93,    46,    44,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    58,    61,    59,
     123,   125
};
#endif

#define YYPACT_NINF (-207)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     992,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,     5,  -207,  -207,  -207,  -207,  -207,    44,    59,  -207,
      36,  1294,  1294,  -207,     7,  -207,  1294,  1152,   114,     6,
     890,  -207,  -207,   -64,    32,   -17,  -207,  -207,    59,  -207,
     -10,  -207,  1089,  -207,  -207,   -30,  1121,  -207,   285,  -207,
      36,  -207,  1152,  1043,   672,   114,  -207,  -207,    32,    -2,
     -33,  -207,  -207,  -207,  -207,    44,  -207,   571,  -207,  1152,
    1121,  1121,   421,  -207,    54,  1121,   -16,  -207,  -207,   786,
     805,   805,   838,    87,   125,   135,   166,   554,   169,   194,
     153,   155,   594,   651,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,   137,   195,   838,  -207,   106,   183,   138,
      56,   250,   180,   172,   177,   254,    -6,  -207,  -207,     9,
    -207,  -207,  -207,   362,   439,  -207,  -207,  -207,  -207,   192,
    -207,  -207,  -207,  -207,   115,   212,   211,  -207,   129,  -207,
    -207,  -207,  -207,   214,   -18,   838,    32,  -207,  -207,   571,
    -207,  -207,  -207,  1063,  -207,  -207,  -207,   838,    47,  -207,
     199,  -207,   554,   651,  -207,   838,  -207,  -207,   200,   554,
     838,   838,   838,   233,   632,   206,  -207,  -207,  -207,    99,
     131,   124,   227,   294,  -207,  -207,   709,   838,   295,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
     838,  -207,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,  -207,  -207,   477,  -207,  -207,   941,   728,  -207,
      58,  -207,   140,  -207,  1268,  -207,   296,  -207,  -207,  -207,
    -207,  -207,   -14,  -207,  -207,    54,  -207,   838,  -207,   231,
     554,  -207,   154,   162,   167,   234,   632,  -207,  -207,  -207,
    1178,   156,  -207,   838,  -207,  -207,   170,  -207,    50,  -207,
    -207,  -207,  -207,  -207,   106,   106,   183,   183,   138,   138,
     138,   138,    56,    56,   250,   180,   172,   177,   254,   -25,
    -207,  -207,  -207,   232,   235,  -207,   236,   140,  1226,   749,
    -207,  -207,  -207,   516,  -207,  -207,  -207,  -207,  -207,   122,
     554,   554,   838,   761,  -207,  -207,   838,  -207,   838,  -207,
    -207,  -207,  -207,   237,  -207,   239,  -207,  -207,   246,  -207,
    -207,  -207,   182,   554,   184,  -207,  -207,  -207,  -207,   215,
     219,  -207,   554,  -207,  -207,  -207
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
    -207,  -207,  -207,  -207,   -62,  -207,   -98,    61,    51,    53,
      55,    86,   107,   127,   123,   113,  -207,   -61,   -63,  -207,
     -90,   -68,    38,     1,  -207,   277,  -207,   -36,  -207,  -207,
     275,   -60,   -31,  -207,   101,  -207,   289,   202,    28,    -9,
     -34,   -12,  -207,   -59,  -207,   128,  -207,   196,  -121,  -206,
    -140,  -207,   -91,  -207,   -37,    72,   240,  -177,    60,  -207,
    -207,  -207,   337,  -207
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
      61,    30,   151,   152,   145,    65,   183,   266,    43,     1,
      55,   229,   189,   190,   160,    78,    47,   211,    45,   251,
      81,    52,   166,   241,   178,   141,    68,   174,   176,   177,
     151,   152,    53,    54,   307,    69,    74,    57,    29,     1,
     156,    30,   162,   236,    81,    81,    81,     1,   231,    81,
     164,   139,    72,   151,   171,   156,    46,     1,   157,   313,
      80,     1,   328,    75,   144,   307,   139,    81,   219,   220,
     272,   172,   191,   248,    27,   170,    73,   314,    29,    76,
     230,   258,   231,   190,    85,   190,   155,   249,   261,   323,
     262,   263,   264,   151,   152,    44,   160,    56,   232,   254,
     140,    16,    17,   166,    27,   151,   152,   278,    85,    85,
      85,    28,    27,    85,   281,   282,   283,   140,     1,    28,
     255,   327,    27,   231,    79,    49,   237,    81,   238,    28,
     133,    85,   240,   277,    28,   239,   256,    81,   221,   222,
     299,   167,   191,   236,   193,   194,   195,   280,   217,   218,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   300,   318,
     306,   140,   231,   337,   179,   324,   151,   152,    94,   271,
      95,   212,    63,   237,    64,   238,   213,   214,   268,   316,
      28,    85,   270,   180,   238,   151,   152,   185,   245,    28,
     269,    85,   246,   181,   231,   196,    65,   197,   308,   198,
     309,   151,    58,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   319,   270,   240,   238,   231,    45,   340,
     341,   320,   342,   344,   182,   231,   321,   184,   144,   325,
     231,   335,   186,   326,   187,   144,   170,   151,   152,   333,
     160,   350,   351,   352,   225,   231,   226,   231,   271,   215,
     216,   355,   227,   345,   223,   224,   151,   346,   286,   287,
     228,   144,   288,   289,   290,   291,   284,   285,   292,   293,
      77,   243,   338,   209,   244,   247,   257,   260,    86,    87,
      88,    89,   265,    90,    91,   267,   273,   274,   279,   312,
     317,   329,   322,   349,   330,    58,   347,   331,   354,   144,
     348,   294,   353,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   295,    22,    23,    24,    25,    26,    92,
      93,    94,   298,    95,    96,    97,    98,    99,   100,   101,
     102,   297,   158,   103,   296,   163,   315,   154,   250,   104,
     105,   106,   107,   108,   109,    86,    87,    88,    89,   259,
      90,    91,   311,   234,   110,    58,   111,    67,     0,   339,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
     103,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,    86,    87,    88,    89,     0,    90,    91,     2,
       0,   110,    58,   233,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,    91,     0,     0,     0,
       0,     0,     0,    92,    93,    94,     0,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,   103,     0,     0,
       0,     0,   165,   104,   105,   106,   107,   108,   109,   149,
      87,    88,    89,     0,    90,    91,     0,     0,   110,    58,
     235,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,   103,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,    86,    87,    88,
      89,     0,    90,    91,     0,     0,   110,    58,   301,     0,
       0,     0,     0,     0,   149,    87,    88,    89,     0,    90,
      91,     0,     0,     0,   103,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,     0,   149,    87,    88,
      89,     0,    90,    91,     0,     0,   159,   336,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,   103,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   149,    87,    88,    89,   103,
      90,    91,     0,   110,    58,   104,   105,   106,   107,   108,
     109,     0,     0,     0,   149,    87,    88,    89,     0,    90,
      91,   159,   103,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   149,    87,    88,    89,     2,
      90,    91,     0,   188,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
     103,    23,    24,    25,    26,     0,   104,   105,   106,   107,
     108,   109,   149,    87,    88,    89,     0,    90,    91,   103,
       0,   110,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   149,    87,    88,    89,     0,    90,    91,     0,     0,
     103,     0,     0,   150,     0,     0,   104,   105,   106,   107,
     108,   109,   149,    87,    88,    89,     0,    90,    91,     0,
       0,     0,     0,     0,   149,    87,    88,    89,     0,    90,
      91,     0,     0,     0,     0,     0,     0,   103,   275,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   149,
      87,    88,    89,     0,    90,    91,   103,     0,     0,   305,
       0,     0,   104,   105,   106,   107,   108,   109,   149,    87,
      88,    89,     0,    90,    91,     0,     0,   103,     0,     0,
     334,     0,     0,   104,   105,   106,   107,   108,   109,   103,
     343,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   149,    87,    88,    89,     0,    90,    91,     0,     0,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
      66,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    25,    26,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     302,   238,     0,     0,     0,     0,    28,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     2,    22,    23,    24,    25,    26,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,   143,    23,    24,    25,    26,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,   253,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,    23,    24,    25,    26,     0,     0,    77,     0,    58,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,   270,   302,   238,     0,
       0,     0,     0,    28,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   310,    22,    23,    24,
      25,    26,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,    23,    24,    25,    26
};

static const yytype_int16 yycheck[] =
{
      37,     0,    64,    64,    63,    39,    97,   184,     3,     3,
       3,    17,   102,   103,    77,    52,    28,   115,    27,   159,
      56,    30,    82,   144,    92,    62,    90,    89,    90,    91,
      92,    92,    31,    32,   240,     3,    48,    36,     0,     3,
      73,    40,    79,   134,    80,    81,    82,     3,    73,    85,
      81,    60,    69,   115,    85,    73,    28,     3,    91,    73,
      90,     3,    87,    73,    63,   271,    75,   103,    12,    13,
     191,    87,   103,    91,    68,    84,    48,    91,    40,    89,
      86,   172,    73,   173,    56,   175,    88,   155,   179,   266,
     180,   181,   182,   155,   155,    90,   159,    90,    89,   167,
      62,    42,    43,   163,    68,   167,   167,   197,    80,    81,
      82,    75,    68,    85,   212,   213,   214,    79,     3,    75,
      73,    71,    68,    73,    52,    89,    68,   163,    70,    75,
      58,   103,   144,   196,    75,   144,    89,   173,    82,    83,
     230,    87,   173,   234,     7,     8,     9,   210,    10,    11,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   231,   260,
     238,   133,    73,   313,    87,   273,   238,   238,    56,   191,
      58,    75,    68,    68,    70,    70,    80,    81,    89,   257,
      75,   163,    68,    68,    70,   257,   257,     3,    69,    75,
      69,   173,    73,    68,    73,    68,   240,    70,    68,    72,
      70,   273,    90,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    69,    68,   237,    70,    73,   237,   320,
     321,    69,   322,   323,    68,    73,    69,    68,   237,    69,
      73,   309,    89,    73,    89,   244,   255,   309,   309,   308,
     313,    69,   343,    69,    74,    73,    84,    73,   270,    76,
      77,   352,    85,   326,    14,    15,   328,   328,   217,   218,
      16,   270,   219,   220,   221,   222,   215,   216,   223,   224,
      88,    69,   319,    88,    73,    71,    87,    87,     3,     4,
       5,     6,    59,     8,     9,    89,    69,     3,     3,     3,
      69,    69,    68,    57,    69,    90,    69,    71,    89,   308,
      71,   225,   349,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   226,    49,    50,    51,    52,    53,    54,
      55,    56,   229,    58,    59,    60,    61,    62,    63,    64,
      65,   228,    75,    68,   227,    80,   255,    68,   156,    74,
      75,    76,    77,    78,    79,     3,     4,     5,     6,   173,
       8,     9,   244,   133,    89,    90,    91,    40,    -1,   319,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,     3,     4,     5,     6,    -1,     8,     9,    28,
      -1,    89,    90,    91,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    91,    74,    75,    76,    77,    78,    79,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    89,    90,
      91,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    89,    90,    91,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    90,    91,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,     3,     4,     5,     6,    68,
       8,     9,    -1,    89,    90,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    90,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,     3,     4,     5,     6,    28,
       8,     9,    -1,    89,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      68,    50,    51,    52,    53,    -1,    74,    75,    76,    77,
      78,    79,     3,     4,     5,     6,    -1,     8,     9,    68,
      -1,    89,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      68,    -1,    -1,    71,    -1,    -1,    74,    75,    76,    77,
      78,    79,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,     3,
       4,     5,     6,    -1,     8,     9,    68,    -1,    -1,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    68,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,    77,    78,    79,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
       0,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    51,    52,    53,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    28,    49,    50,    51,    52,    53,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    69,    50,    51,    52,    53,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    91,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    50,    51,    52,    53,    -1,    -1,    88,    -1,    90,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,    50,    51,    52,    53,    68,    75,   114,
     115,   118,   119,   120,   121,   127,   130,   131,   132,   133,
     153,   154,   155,     3,    90,   131,   130,   133,   134,    89,
     116,   117,   131,   115,   115,     3,    90,   115,    90,   114,
     115,   146,   147,    68,    70,   132,     0,   154,    90,     3,
     128,   129,    69,   130,   133,    73,    89,    88,   146,   147,
      90,   119,   122,   123,   124,   130,     3,     4,     5,     6,
       8,     9,    54,    55,    56,    58,    59,    60,    61,    62,
      63,    64,    65,    68,    74,    75,    76,    77,    78,    79,
      89,    91,    93,    94,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   112,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   131,
     114,   146,     3,    69,   115,   135,   136,   137,   138,     3,
      71,    96,   109,   113,   128,    88,    73,    91,   117,    90,
     110,   142,   146,   122,   124,    91,   123,    87,   125,   126,
     131,   124,    87,    68,    96,    68,    96,    96,   113,    87,
      68,    68,    68,   144,    68,     3,    89,    89,    89,   112,
     112,   124,   139,     7,     8,     9,    68,    70,    72,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    88,
     111,    98,    75,    80,    81,    76,    77,    10,    11,    12,
      13,    82,    83,    14,    15,    74,    84,    85,    16,    17,
      86,    73,    89,    91,   148,    91,   144,    68,    70,   131,
     133,   140,   141,    69,    73,    69,    73,    71,    91,   113,
     129,   142,   143,    91,   113,    73,    89,    87,   144,   139,
      87,   144,   112,   112,   112,    59,   149,    89,    89,    69,
      68,   133,   140,    69,     3,    69,    95,   110,   112,     3,
     110,    98,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   101,   102,   102,   103,   104,   105,   106,   107,   112,
     110,    91,    69,   135,   140,    71,   113,   141,    68,    70,
      48,   137,     3,    73,    91,   126,   113,    69,   144,    69,
      69,    69,    68,   149,    98,    69,    73,    71,    87,    69,
      69,    71,    69,   135,    71,   113,    91,   142,   146,   150,
     144,   144,   112,    69,   112,   110,   109,    69,    71,    57,
      69,   144,    69,   146,    89,   144
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,    99,    99,   100,   100,   100,   101,   101,   101,
     102,   102,   102,   102,   102,   103,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   120,   121,   121,   122,   122,   123,   124,   124,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   133,   133,   133,   133,   134,
     134,   135,   135,   136,   136,   137,   137,   137,   138,   138,
     139,   139,   140,   140,   140,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   142,   142,   142,   143,   143,   144,
     144,   144,   144,   144,   144,   145,   145,   145,   146,   146,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     150,   150,   151,   151,   151,   151,   152,   152,   152,   152,
     152,   153,   153,   154,   154,   155,   155,   155,   155
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
  case 76: /* declaration: declaration_specifiers ';'  */
#line 284 "c.y"
                                                                                                                { (yyval.node) = createVarDeclaration((yyvsp[-1].node), (yyvsp[-1].node), 0);}
#line 1699 "c.tab.c"
    break;

  case 77: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 285 "c.y"
                                                                                                { (yyval.node) = createVarDeclaration((yyvsp[-2].node), (yyvsp[-1].node), 0);}
#line 1705 "c.tab.c"
    break;

  case 80: /* declaration_specifiers: type_specifier  */
#line 291 "c.y"
                                                                                                                                { (yyval.node) = createVarDeclaration((yyvsp[0].node), (yyvsp[0].node), 0);}
#line 1711 "c.tab.c"
    break;

  case 94: /* type_specifier: VOID  */
#line 317 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("VOID");}
#line 1717 "c.tab.c"
    break;

  case 95: /* type_specifier: CHAR  */
#line 318 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("CHAR");}
#line 1723 "c.tab.c"
    break;

  case 96: /* type_specifier: SHORT  */
#line 319 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("SHORT");}
#line 1729 "c.tab.c"
    break;

  case 97: /* type_specifier: INT  */
#line 320 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("INT");}
#line 1735 "c.tab.c"
    break;

  case 98: /* type_specifier: LONG  */
#line 321 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("LONG");}
#line 1741 "c.tab.c"
    break;

  case 99: /* type_specifier: FLOAT  */
#line 322 "c.y"
                                                                            {(yyval.node) = createTypeSpecifier("FLOAT");}
#line 1747 "c.tab.c"
    break;

  case 100: /* type_specifier: DOUBLE  */
#line 323 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("DOUBLE");}
#line 1753 "c.tab.c"
    break;

  case 101: /* type_specifier: SIGNED  */
#line 324 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("SIGNED");}
#line 1759 "c.tab.c"
    break;

  case 102: /* type_specifier: UNSIGNED  */
#line 325 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("UNSIGNED");}
#line 1765 "c.tab.c"
    break;

  case 103: /* type_specifier: _BOOL  */
#line 326 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("_BOOL");}
#line 1771 "c.tab.c"
    break;

  case 104: /* type_specifier: _COMPLEX  */
#line 327 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("_COMPLEX");}
#line 1777 "c.tab.c"
    break;

  case 105: /* type_specifier: _IMAGINARY  */
#line 328 "c.y"
                                                                                                                                {(yyval.node) = createTypeSpecifier("_IMAGINARY");}
#line 1783 "c.tab.c"
    break;

  case 106: /* type_specifier: INLINE  */
#line 329 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("INLINE");}
#line 1789 "c.tab.c"
    break;

  case 109: /* type_specifier: TYPE_NAME  */
#line 332 "c.y"
                                                                                                                                        {(yyval.node) = createTypeSpecifier("TYPE_NAME");}
#line 1795 "c.tab.c"
    break;

  case 153: /* parameter_list: parameter_declaration  */
#line 428 "c.y"
                                                                                                        { (yyval.node) = createListNode("ParametersList", (yyvsp[0].node));}
#line 1801 "c.tab.c"
    break;

  case 154: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 429 "c.y"
                                                                                        { 
																	(yyval.node) = (yyvsp[-2].node);
																	addLinkToList((yyval.node), (yyvsp[0].node));
																}
#line 1810 "c.tab.c"
    break;

  case 179: /* statement: labeled_statement  */
#line 481 "c.y"
                                                                                                                  { (yyval.node) = createStatement((yyvsp[0].node)); }
#line 1816 "c.tab.c"
    break;

  case 180: /* statement: compound_statement  */
#line 482 "c.y"
                                                                                                          { (yyval.node) = createStatement((yyvsp[0].node)); }
#line 1822 "c.tab.c"
    break;

  case 181: /* statement: expression_statement  */
#line 483 "c.y"
                                                                                                          { (yyval.node) = createStatement((yyvsp[0].node)); }
#line 1828 "c.tab.c"
    break;

  case 182: /* statement: selection_statement  */
#line 484 "c.y"
                                                                                                          { (yyval.node) = createStatement((yyvsp[0].node)); }
#line 1834 "c.tab.c"
    break;

  case 183: /* statement: iteration_statement  */
#line 485 "c.y"
                                                                                                          { (yyval.node) = createStatement((yyvsp[0].node)); }
#line 1840 "c.tab.c"
    break;

  case 184: /* statement: jump_statement  */
#line 486 "c.y"
                                                                                                                  { (yyval.node) = createStatement((yyvsp[0].node)); }
#line 1846 "c.tab.c"
    break;

  case 185: /* labeled_statement: IDENTIFIER ':' statement  */
#line 490 "c.y"
                                                                       { (yyval.node) = createLabeledStatement("", NULL, (yyvsp[0].node)); }
#line 1852 "c.tab.c"
    break;

  case 186: /* labeled_statement: CASE constant_expression ':' statement  */
#line 491 "c.y"
                                                                       { (yyval.node) = createLabeledStatement("", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1858 "c.tab.c"
    break;

  case 187: /* labeled_statement: DEFAULT ':' statement  */
#line 492 "c.y"
                                                                                                           { (yyval.node) = createLabeledStatement("", NULL, (yyvsp[0].node)); }
#line 1864 "c.tab.c"
    break;

  case 188: /* compound_statement: '{' '}'  */
#line 496 "c.y"
                                                                                                                                { (yyval.node) = createCompoundStatement(NULL, NULL); }
#line 1870 "c.tab.c"
    break;

  case 189: /* compound_statement: '{' statement_list '}'  */
#line 497 "c.y"
                                                                                                                { (yyval.node) = createCompoundStatement((yyvsp[-1].node), NULL); }
#line 1876 "c.tab.c"
    break;

  case 190: /* compound_statement: '{' declaration_list '}'  */
#line 498 "c.y"
                                                                                                                { (yyval.node) = createCompoundStatement((yyvsp[-1].node), NULL); }
#line 1882 "c.tab.c"
    break;

  case 191: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 499 "c.y"
                                                                                                { (yyval.node) = createCompoundStatement((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1888 "c.tab.c"
    break;

  case 192: /* declaration_list: declaration  */
#line 503 "c.y"
                                                                                                                        { (yyval.node) = createListNode("LocalDeclarations", (yyvsp[0].node)); }
#line 1894 "c.tab.c"
    break;

  case 193: /* declaration_list: declaration_list declaration  */
#line 504 "c.y"
                                                                                                        {
																		(yyval.node) = (yyvsp[-1].node);
																		addLinkToList((yyval.node), (yyvsp[0].node));
																	}
#line 1903 "c.tab.c"
    break;

  case 194: /* statement_list: statement  */
#line 511 "c.y"
                                                                                                                                { (yyval.node) = createListNode("InstructionsList", (yyvsp[0].node));}
#line 1909 "c.tab.c"
    break;

  case 195: /* statement_list: statement_list statement  */
#line 512 "c.y"
                                                                                                                {
																		(yyval.node) = (yyvsp[-1].node);
																		addLinkToList((yyval.node), (yyvsp[0].node));
																	}
#line 1918 "c.tab.c"
    break;

  case 196: /* expression_statement: ';'  */
#line 519 "c.y"
                                                                                                                                { (yyval.node) = createExpressionStatement(NULL); }
#line 1924 "c.tab.c"
    break;

  case 197: /* expression_statement: expression ';'  */
#line 520 "c.y"
                                                                                                                        { (yyval.node) = createExpressionStatement((yyvsp[-1].node)); }
#line 1930 "c.tab.c"
    break;

  case 198: /* selection_statement: IF '(' expression ')' compound_statement ELSE compound_statement  */
#line 524 "c.y"
                                                                                        { (yyval.node) = createIfStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1936 "c.tab.c"
    break;

  case 199: /* selection_statement: IF '(' expression ')' compound_statement  */
#line 525 "c.y"
                                                                                                                { (yyval.node) = createIfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1942 "c.tab.c"
    break;

  case 200: /* selection_statement: IF '(' expression ')' selection_statement  */
#line 526 "c.y"
                                                                                { (yyval.node) = createIfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1948 "c.tab.c"
    break;

  case 201: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 527 "c.y"
                                                                                                                { (yyval.node) = createSwitchStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1954 "c.tab.c"
    break;

  case 202: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 531 "c.y"
                                                                                          { (yyval.node) = createWhileStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1960 "c.tab.c"
    break;

  case 203: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 532 "c.y"
                                                                                          { (yyval.node) = createDoWhileStatement((yyvsp[-5].node), (yyvsp[-2].node)); }
#line 1966 "c.tab.c"
    break;

  case 204: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 533 "c.y"
                                                                                          { (yyval.node) = createForStatement((yyvsp[-3].node), (yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 1972 "c.tab.c"
    break;

  case 205: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 534 "c.y"
                                                                                          { (yyval.node) = createForStatement((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1978 "c.tab.c"
    break;

  case 211: /* translation_unit: external_declaration  */
#line 546 "c.y"
                                                                                        { (yyval.node) = createTranslationUnitNode((yyvsp[0].node)); astRoot = (yyval.node);}
#line 1984 "c.tab.c"
    break;

  case 212: /* translation_unit: translation_unit external_declaration  */
#line 547 "c.y"
                                                            {							 
														  (yyval.node) = (yyvsp[-1].node); 
														  addLinkToList((yyval.node), (yyvsp[0].node));
														}
#line 1993 "c.tab.c"
    break;

  case 213: /* external_declaration: function_definition  */
#line 554 "c.y"
                                                                                        { (yyval.node) = createExternalDeclarationNode((yyvsp[0].node));}
#line 1999 "c.tab.c"
    break;

  case 214: /* external_declaration: declaration  */
#line 555 "c.y"
                                                                                                {(yyval.node) = createExternalDeclarationNode((yyvsp[0].node));}
#line 2005 "c.tab.c"
    break;

  case 215: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 559 "c.y"
                                                                                         { (yyval.node) = createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2011 "c.tab.c"
    break;

  case 216: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 560 "c.y"
                                                                                         { (yyval.node) = createFunctionDeclarationNode((yyvsp[-2].node), (yyvsp[-1].node), NULL, (yyvsp[0].node)); }
#line 2017 "c.tab.c"
    break;

  case 217: /* function_definition: declarator declaration_list compound_statement  */
#line 561 "c.y"
                                                                                         { (yyval.node) = createFunctionDeclarationNode(NULL, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2023 "c.tab.c"
    break;

  case 218: /* function_definition: declarator compound_statement  */
#line 562 "c.y"
                                                                                         { (yyval.node) = createFunctionDeclarationNode(NULL, (yyvsp[-1].node), NULL, (yyvsp[0].node)); }
#line 2029 "c.tab.c"
    break;


#line 2033 "c.tab.c"

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

#line 565 "c.y"


extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
