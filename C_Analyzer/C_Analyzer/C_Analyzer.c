#include <stdio.h>
//#include "symbols.h"
#include <errno.h>
//#include "ast.h"
#include "SymbolTable.h"

extern FILE* yyin;

extern int yylex(void);
extern int yyparse(void);
extern Node* astRoot;

extern int yydebug;

SymNode* symRoot = NULL;

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
	yyin = fopen("input.csrc", "rt");
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
		
		symRoot = createDefaultSymTableNode("Test",
			"test",
			0,
			LOCAL,
			"local",
			3);
		createSymTreeFromSyntax(astRoot, symRoot, 0);
		printSymTree(symRoot, 0);
		fclose(yyin);
	}
	else
	{
		printf("Fisier inexistent\n");
	}
}