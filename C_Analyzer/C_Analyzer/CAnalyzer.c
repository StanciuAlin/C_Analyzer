#include <stdio.h>
#include <malloc.h>
//#include "symbols.h"
#include <errno.h>
//#include "ast.h"
#include "SymbolTableList.h"
#include "CAnalizer.h"

extern FILE* yyin;

extern int yylex(void);
extern int yyparse(void);
extern Node* astRoot;
extern SymTableEntry* symTableEntryList;

extern int yydebug;

//SymNode* symRoot = NULL;

int main()
{
	printf("|                                                                                                                                  |\n");
	printf("|                                                                                                                                  |\n");
	printf("|                               //////                 //////        ///////    ///////////   /////////////                        |\n");
	printf("|                             //      //             //      //    //       //  //         // //                                   |\n");
	printf("|                           //                     //             //         // //         // //                                   |\n");
	printf("|                           //                     //             //         // //         // //                                   |\n");
	printf("|                           //                     //             //         // //         // /////////////                        |\n");
	printf("|                           //                     //             //         // //         // //                                   |\n");
	printf("|                           //                     //             //         // //         // //                                   |\n");
	printf("|                           //                     //             //         // //         // //                                   |\n");
	printf("|                             //      //             //      //    //       //  //         // //                                   |\n");
	printf("|                               //////                 //////        ///////    ///////////   //////////////                       |\n");
	printf("|                                                                                                                                  |\n");
	printf("|                                                                                                                                  |\n");
	printf("|          //\\\\          ////        //          //\\\\           //            //   /////////////  ///////////// //////////         |\n");
	printf("|         //  \\\\         // //       //         //  \\\\          //            //            //    //            //        //       |\n");
	printf("|        //    \\\\        //  //      //        //    \\\\         //            //           //     //            //          //     |\n");
	printf("|       //      \\\\       //   //     //       //      \\\\        //            //          //      //            //        //       |\n");
	printf("|      //        \\\\      //    //    //      //        \\\\       //            //         //       ///////////// //      //         |\n");
	printf("|     //==========\\\\     //     //   //     //==========\\\\      //            //        //        //            ////////           |\n");
	printf("|    //            \\\\    //      //  //    //            \\\\     //            //       //         //            //      //         |\n");
	printf("|   //              \\\\   //       // //   //              \\\\    //            //      //          //            //        //       |\n");
	printf("|  //                \\\\  //        ////  //                \\\\   //            //     //           //            //         //      |\n");
	printf("| //                  \\\\ //          // //                  \\\\  ///////////// //   ////////////// ///////////// //          //     |\n");
	printf("|                                                                                                                                  |\n");
	printf("|                                                                                                                                  |\n");

	yydebug = 1;

#if INPUT_PROGRAM_FILE
	yyin = fopen("input_err.csrc", "rt");
#else
	yyin = fopen("input.csrc", "rt");
#endif // INPUT_PROGRAM_FILE

	if (yyin != NULL)
	{
		int result = yyparse();
		switch (result)
		{
		case 0:
			printf("Parse successfull.\n");
			break;

		case 1:
			printf("Invalid input encountered\n");
			break;

		case 2:
			printf("Out of memory\n");
			break;

		default:
			break;
		}

		printAst(astRoot, 0);

		symTableEntryList = malloc(sizeof(SymTableEntry) * 1000);
		errorsList = malloc(sizeof(Error));
		
		createSymListFromSyntaxTree(astRoot, 0);
		if (lengthErrorsList > 0)
		{
			printErrorsList();
		}
		else
		{
			printSymNodeList();
		}
		
		fclose(yyin);
	}
	else
	{
		printf("Fisier inexistent\n");
	}
}