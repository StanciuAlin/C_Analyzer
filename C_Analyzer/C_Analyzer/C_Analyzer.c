#include <stdio.h>
#include "symbols.h"
#include <errno.h>

extern FILE* yyin;
extern int yylex(void);

const char* lexUnits[] = { "END", //0
													"INT", //1
													"LONG", //2
													"DOUBLE", //3
													"SHORT", //4
													"UNSIGNED", //5
													"VOID", //6
													"VOLATILE", //7
													"WHILE", //8
													"FLOAT", //9
													"IF", //10
													"ELSE", //11
													"RETURN", //12
													"CONSTANT", //13
													"STRING_LITERAL", //14
													"ASSIGN", //15
													"ADD", //16
													"SUBSTRACT", //17
													"IDENTIFIER", //18
													"END_OF_INSTRUCTION", //19
													"AUTO", //20
													"BREAK", //21
													"CASE", //22
													"CHAR", //23
													"CONST", //24
													"CONTINUE", //25
													"DEFAULT", //26
													"DO", //27
													"ENUM", //28
													"EXTERN", //29
													"FOR", //30
													"GOTO", //31
													"REGISTER", //32
													"SIGNED", //33
													"SIZEOF", //34
													"STATIC", //35
													"STRUCT", //36
													"SWITCH", //37
													"TYPEDEF", //38
													"ELLIPSIS", //39
													"RIGHT_ASSIGN", //40
													"LEFT_ASSIGN", //41
													"ADD_ASSIGN", //42
													"SUB_ASSIGN", //43
													"MUL_ASSIGN", //44
													"DIV_ASSIGN", //45
													"MOD_ASSIGN", //46
													"UNION", //47
													"AND_ASSIGN", //48
													"XOR_ASSIGN", //49
													"OR_ASSIGN", //50
													"RIGHT_OP", //51
													"LEFT_OP", //52
													"INC_OP", //53
													"DEC_OP", //54
													"PTR_OP", //55
													"AND_OP", //56
													"OR_OP", //57
													"LE_OP", //58
													"GE_OP", //59
													"EQ_OP", //60
													"NE_OP", //61
													"LT_OP", //62
													"GT_OP", //63
													"CURLY_BR_OPEN", //64
													"CURLY_BR_CLOSE", //65
													"COMMA", //66
													"DOUBLE_PT", //67
													"ROUND_BR_OPEN", //68
													"ROUND_BR_CLOSE", //69
													"SQUARE_BR_OPEN", //70
													"SQUARE_BR_CLOSE", //71
													"DOT", //72
													"AMPERSAND", //73
													"EXCLAMATION_MARK", //74
													"TILDA", //75
													"MINUS", //76
													"PLUS", //77
													"STAR", //78
													"SLASH", //79
													"PERCENT", //80
													"POWER", //81
													"PIPE", //82
													"QUESTION_MARK", //83
													"COMM_MULTI_LINE", //84
													"COMM_UNI_LINE", //85
													"INLINE", //86
													"RESTRICT", //87
													"_BOOL", //88
													"_COMPLEX", //89
													"_IMAGINARY" //90
};


int main()
{
	int tokenValue = 0;
	printf("|----------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|----------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|-------------------------------//////-----------------//////--------///////----///////////---/////////////------------------------|\n");
	printf("|-----------------------------//------//-------------//------//----//-------//--//---------//-//-----------------------------------|\n");
	printf("|---------------------------//---------------------//-------------//---------//-//---------//-//-----------------------------------|\n");
	printf("|---------------------------//---------------------//-------------//---------//-//---------//-//-----------------------------------|\n");
	printf("|---------------------------//---------------------//-------------//---------//-//---------//-/////////////------------------------|\n");
	printf("|---------------------------//---------------------//-------------//---------//-//---------//-//-----------------------------------|\n");
	printf("|---------------------------//---------------------//-------------//---------//-//---------//-//-----------------------------------|\n");
	printf("|---------------------------//---------------------//-------------//---------//-//---------//-//-----------------------------------|\n");
	printf("|-----------------------------//------//-------------//------//----//-------//--//---------//-//-----------------------------------|\n");
	printf("|-------------------------------//////-----------------//////--------///////----///////////---//////////////-----------------------|\n");
	printf("|----------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|----------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|----------//\\\\----------////--------//----------//\\\\-----------//------------//---/////////////--/////////////-//////////---------|\n");
	printf("|---------//--\\\\---------//-//-------//---------//--\\\\----------//------------//------------//----//------------//--------//-------|\n");
	printf("|--------//----\\\\--------//--//------//--------//----\\\\---------//------------//-----------//-----//------------//----------//-----|\n");
	printf("|-------//------\\\\-------//---//-----//-------//------\\\\--------//------------//----------//------//------------//--------//-------|\n");
	printf("|------//--------\\\\------//----//----//------//--------\\\\-------//------------//---------//-------/////////////-//------//---------|\n");
	printf("|-----//==========\\\\-----//-----//---//-----//==========\\\\------//------------//--------//--------//------------////////-----------|\n");
	printf("|----//------------\\\\----//------//--//----//------------\\\\-----//------------//-------//---------//------------//------//---------|\n");
	printf("|---//--------------\\\\---//-------//-//---//--------------\\\\----//------------//------//----------//------------//--------//-------|\n");
	printf("|--//----------------\\\\--//--------////--//----------------\\\\---//------------//-----//-----------//------------//---------//------|\n");
	printf("|-//------------------\\\\-//----------//-//------------------\\\\--/////////////-//---//////////////-/////////////-//----------//-----|\n");
	printf("|----------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|----------------------------------------------------------------------------------------------------------------------------------|\n");

	yyin = fopen("input.csrc", "rt");
	if (yyin != NULL)
	{
		while ((tokenValue = yylex()) != END)
		{
				printf(" -> TOKEN ID: %d; Token Value: %s \n", tokenValue, lexUnits[tokenValue]);
		}
	}
	else
	{
		printf("Fisierul de intrare nu poate fi deschis. Eroare: %d", errno);
	}


}