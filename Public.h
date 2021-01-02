//---------------------------------------------------------------------------

#ifndef PublicH
#define PublicH
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//行数
extern int nLineCount=0;
//一行中的数量
extern int nLineCharCount=0;
#define fgetchr(F, C)	{\
							C = fgetc(F);\
							while((C==' ')||(C=='\r')||(C=='\n')||(C=='\t')){\
								C = fgetc(F);\
							}\
							if((C>='A')&&(C<='Z'))C+=32;\
						}

#define PCharToStr(P,S)	{\
							int nLen_ = strlen(P);\
							S.clear();\
							for(int i=0;i<nLen_;i++)\
							{\
								S.push_back( P[i] );\
							}\
						}

#define INITFGETC		nLineCount = 0;\
                    	nLineCharCount = 0;

#define FGETC(F, C)		{\
							C = fgetc(F);\
							if(C=='\n'){\
								nLineCount++;\
								nLineCharCount=0;\
							}\
							nLineCharCount++;\
						}

string CharArrayToString( char * );
//---------------------------------------------------------------------------
#endif
