#include <stdio.h>
//#include "symbols.h"
#include <errno.h>
//#include "ast.h"
#include "SymbolTableList.h"

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
		
		/*symRoot = createDefaultSymTableListNode("Test",
			"test",
			0,
			LOCAL,
			"local",
			3);*/
		symTableEntryList = malloc(sizeof(SymTableEntry) * 1000);
		/*createSymTreeFromSyntax(astRoot, symRoot, 0);
		printSymTree(symRoot, 0);*/
		createSymTreeFromSyntaxList(astRoot, 0);
		printSymNodeList();
		//printSymTree();
		fclose(yyin);
	}
	else
	{
		printf("Fisier inexistent\n");
	}
}