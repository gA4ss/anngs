//---------------------------------------------------------------------------

#pragma hdrstop

#include "Token.h"
#include "Public.h"
#include "ErrorHandle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

FILE *fpScript;

string strTokenBuf;

bool scaner( char *__szFileName ){
	if((fpScript = fopen( __szFileName, "rb" )) == NULL )return false;
	return true;
}/* end scaner */

int next_token(){
	char in_char;
	char szTmp_[1024]={0};
	while( !feof(fpScript) ){
		//in_char = fgetc( fpScript );
		FGETC(fpScript, in_char);
		//过滤无效字符
		if((in_char == ' ')||(in_char == '\r')||(in_char == '\n')|| \
				(in_char == '\t'))continue;
		//开始分析
		switch(in_char){
			case ';':{
            	return SEMICOLON;
			}break;
			case '@':{
				memset( szTmp_, 0, 1024 );
				strTokenBuf.clear();
				//in_char = fgetc( fpScript );
				FGETC(fpScript, in_char);
				if(in_char == 'a'){
					szTmp_[0] = 'a';
					FGETC(fpScript, in_char);
					szTmp_[1] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[2] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[3] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[4] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[5] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[6] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[7] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[8] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[9] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[10] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[11] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[12] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[13] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[14] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[15] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[16] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[17] = in_char;
                	FGETC(fpScript, in_char);
					szTmp_[18] = in_char;
					//szTmp_[1] = fgetc( fpScript );
					//szTmp_[2] = fgetc( fpScript );
					//szTmp_[3] = fgetc( fpScript );
					//szTmp_[4] = fgetc( fpScript );
					//szTmp_[5] = fgetc( fpScript );
					//szTmp_[6] = fgetc( fpScript );
					//szTmp_[7] = fgetc( fpScript );
					//szTmp_[8] = fgetc( fpScript );
					//szTmp_[9] = fgetc( fpScript );
					//szTmp_[10] = fgetc( fpScript );
					//szTmp_[11] = fgetc( fpScript );
					//szTmp_[12] = fgetc( fpScript );
					//szTmp_[13] = fgetc( fpScript );
					//szTmp_[14] = fgetc( fpScript );
					//szTmp_[15] = fgetc( fpScript );
					//szTmp_[16] = fgetc( fpScript );
					//szTmp_[17] = fgetc( fpScript );
					//szTmp_[18] = fgetc( fpScript );
					if( strncmp( szTmp_, "activation_function", 19 ) == 0){
						//PCharToStr( szTmp_, strTokenBuf );
						return ACTIVATIONFUNC;
					}/* end if */
					else{
						ungetc( szTmp_[18] ,fpScript );
						ungetc( szTmp_[17] ,fpScript );
						ungetc( szTmp_[16] ,fpScript );
						ungetc( szTmp_[15] ,fpScript );
						ungetc( szTmp_[14] ,fpScript );
						ungetc( szTmp_[13] ,fpScript );
						ungetc( szTmp_[12] ,fpScript );
						ungetc( szTmp_[11] ,fpScript );
						ungetc( szTmp_[10] ,fpScript );
						ungetc( szTmp_[9] ,fpScript );
						ungetc( szTmp_[8] ,fpScript );
						ungetc( szTmp_[7] ,fpScript );
						ungetc( szTmp_[6] ,fpScript );
						ungetc( szTmp_[5] ,fpScript );
						ungetc( szTmp_[4] ,fpScript );
						ungetc( szTmp_[3] ,fpScript );
						ungetc( szTmp_[2] ,fpScript );
						ungetc( szTmp_[1] ,fpScript );
						memset( szTmp_, 0, 1024 );
						szTmp_[0] = 'a';
						FGETC(fpScript, in_char);
						szTmp_[1] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[2] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[3] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[4] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[5] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[6] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[7] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[8] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[9] = in_char;
						//szTmp_[1] = fgetc( fpScript );
						//szTmp_[2] = fgetc( fpScript );
						//szTmp_[3] = fgetc( fpScript );
						//szTmp_[4] = fgetc( fpScript );
						//szTmp_[5] = fgetc( fpScript );
						//szTmp_[6] = fgetc( fpScript );
						//szTmp_[7] = fgetc( fpScript );
						//szTmp_[8] = fgetc( fpScript );
						//szTmp_[9] = fgetc( fpScript );
						if( strncmp( szTmp_, "activation", 10 ) == 0){
							//PCharToStr( szTmp_, strTokenBuf );
							return ACTIVATION;
						}/* end if */
						else{
							//error
							HANDLE_TOKEN_ERROR(TOKEN_ACTIVATIONFUNC_ERROR);
						}/* end else */
					}/* end if */
				}/* end if */
				//else if( in_char == 'v' ){
				//	szTmp_[0] = 'v';
				//	szTmp_[1] = fgetc( fpScript );
				// 	szTmp_[2] = fgetc( fpScript );
				//	szTmp_[3] = fgetc( fpScript );
				//	szTmp_[4] = fgetc( fpScript );
				//	szTmp_[5] = fgetc( fpScript );
				//	if( strncmp( szTmp_, "value", 5 ) == 0){
				//		//PCharToStr( szTmp_, strTokenBuf );
				//		return ACTIVATION;
				//	}/* end if */
				//	else{
				//		//error
				//	}/* end else */
				//}/* end else if */
				else if( in_char == 'w' ){
					szTmp_[0] = 'w';
					FGETC(fpScript, in_char);
					szTmp_[1] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[2] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[3] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[4] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[5] = in_char;
					//szTmp_[1] = fgetc( fpScript );
					//szTmp_[2] = fgetc( fpScript );
					//szTmp_[3] = fgetc( fpScript );
					//szTmp_[4] = fgetc( fpScript );
					//szTmp_[5] = fgetc( fpScript );
					if( strncmp( szTmp_, "weight", 6 ) == 0){
						//PCharToStr( szTmp_, strTokenBuf );
						return WEIGHT;
					}/* end if */
					else{
						//error
						HANDLE_TOKEN_ERROR(TOKEN_WEIGHT_ERROR);
					}/* end else */
				}/* end else if */
				else if( in_char == 'g' ){
					szTmp_[0] = 'g';
					FGETC(fpScript, in_char);
					szTmp_[1] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[2] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[3] = in_char;
					//szTmp_[1] = fgetc( fpScript );
					//szTmp_[2] = fgetc( fpScript );
					//szTmp_[3] = fgetc( fpScript );
					if( strncmp( szTmp_, "gate", 4 ) == 0){
						//PCharToStr( szTmp_, strTokenBuf );
						return GATE;
					}/* end if */
					else{
						//error
						HANDLE_TOKEN_ERROR(TOKEN_GATE_ERROR);
					}/* end else */
				}/* end else if */
				else if( in_char == 'e' ){
					szTmp_[0] = 'e';
					FGETC(fpScript, in_char);
					szTmp_[1] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[2] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[3] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[4] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[5] = in_char;
					//szTmp_[1] = fgetc( fpScript );
					//szTmp_[2] = fgetc( fpScript );
					//szTmp_[3] = fgetc( fpScript );
					//szTmp_[4] = fgetc( fpScript );
					//szTmp_[5] = fgetc( fpScript );
					if( strncmp( szTmp_, "excout", 6 ) == 0){
						//PCharToStr( szTmp_, strTokenBuf );
						return EXCOUT;
					}/* end if */
					else{
						//error
						HANDLE_TOKEN_ERROR(TOKEN_EXCOUT_ERROR);
					}/* end else */
				}/* end else if */
				else if( in_char == 'i' ){
					szTmp_[0] = 'i';
					FGETC(fpScript, in_char);
					szTmp_[1] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[2] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[3] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[4] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[5] = in_char;
					//szTmp_[1] = fgetc( fpScript );
					//szTmp_[2] = fgetc( fpScript );
					//szTmp_[3] = fgetc( fpScript );
					//szTmp_[4] = fgetc( fpScript );
					//szTmp_[5] = fgetc( fpScript );
					if( strncmp( szTmp_, "inhout", 6 ) == 0){
						//PCharToStr( szTmp_, strTokenBuf );
						return INHOUT;
					}/* end if */
					else{
						//error
						HANDLE_TOKEN_ERROR(TOKEN_INHOUT_ERROR);
					}/* end else */
				}/* end else if */
            	else{
					//error
					HANDLE_TOKEN_ERROR(TOKEN_ATTRIBUTE_ERROR);
                }/* end else */
			}break;
			case '.':{
				memset( szTmp_, 0, 1024 );
				in_char = fgetc( fpScript );
				if( in_char == 'c' ){
					szTmp_[0] = 'c';
					FGETC(fpScript, in_char);
					szTmp_[1] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[2] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[3] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[4] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[5] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[6] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[7] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[8] = in_char;
					//szTmp_[1] = fgetc( fpScript );
					//szTmp_[2] = fgetc( fpScript );
					//szTmp_[3] = fgetc( fpScript );
					//szTmp_[4] = fgetc( fpScript );
					//szTmp_[5] = fgetc( fpScript );
					//szTmp_[6] = fgetc( fpScript );
					//szTmp_[7] = fgetc( fpScript );
					//szTmp_[8] = fgetc( fpScript );
					if( strncmp( szTmp_, "configure", 9 ) == 0){
						PCharToStr( szTmp_, strTokenBuf );
						return CONFIGURE_LAB;
					}/* end if */
					else{
						//error
						HANDLE_TOKEN_FATAL_ERROR(TOKEN_CONFIGURE_ERROR);
					}/* end else */
				}/* end if */
				else if( in_char == 'n' ){
					szTmp_[0] = 'n';
					FGETC(fpScript, in_char);
					szTmp_[1] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[2] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[3] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[4] = in_char;
					FGETC(fpScript, in_char);
					szTmp_[5] = in_char;
					//szTmp_[1] = fgetc( fpScript );
					//szTmp_[2] = fgetc( fpScript );
					//szTmp_[3] = fgetc( fpScript );
					//szTmp_[4] = fgetc( fpScript );
					//szTmp_[5] = fgetc( fpScript );
					if( strncmp( szTmp_, "neurol", 6 ) == 0){
						PCharToStr( szTmp_, strTokenBuf );
						return NEUROL_LAB;
					}/* end if */
					else{
						//放回到输入流
						ungetc( szTmp_[5] ,fpScript );
						ungetc( szTmp_[4] ,fpScript );
						ungetc( szTmp_[3] ,fpScript );
						ungetc( szTmp_[2] ,fpScript );
						ungetc( szTmp_[1] ,fpScript );
						memset( szTmp_, 0, 1024 );
						szTmp_[0] = 'n';
						FGETC(fpScript, in_char);
						szTmp_[1] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[2] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[3] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[4] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[5] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[6] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[7] = in_char;
						FGETC(fpScript, in_char);
						szTmp_[8] = in_char;
						//szTmp_[1] = fgetc( fpScript );
						//szTmp_[2] = fgetc( fpScript );
						//szTmp_[3] = fgetc( fpScript );
						//szTmp_[4] = fgetc( fpScript );
						//szTmp_[5] = fgetc( fpScript );
						//szTmp_[6] = fgetc( fpScript );
						//szTmp_[7] = fgetc( fpScript );
						//szTmp_[8] = fgetc( fpScript );
						if( strncmp( szTmp_, "neuralnet", 9 ) == 0){
							PCharToStr( szTmp_, strTokenBuf );
							return NEURALNET_LAB;
						}/* end if */
						else{
							//error
							HANDLE_TOKEN_FATAL_ERROR(TOKEN_NEUROLANDNEURALNET_ERROR);
						}/* end else */
					}/* end else */
				}/* end else if */
				else{	//类名
					strTokenBuf.clear();
					//in_char = fgetc( fpScript );
					while((( in_char >= 'a' ) && ( in_char <= 'z' ))|| \
						  (( in_char >= 'A' ) && ( in_char <= 'Z' ))|| \
							(( in_char >= '0' ) && ( in_char <= '9' ))){
								strTokenBuf.push_back( in_char );
								//in_char = fgetc( fpScript );
								FGETC(fpScript, in_char);
					}/* end while */
					//多读一个退回
					ungetc( in_char, fpScript );
					return CLASS_LAB;
				}/* end else */
			}break;
			case '$':{
				strTokenBuf.clear();
            	strTokenBuf.push_back( in_char );
				//in_char = fgetc( fpScript );
				FGETC(fpScript, in_char);
				while((( in_char >= 'a' ) && ( in_char <= 'z' ))|| \
				   (( in_char >= '0' ) && ( in_char <= '9' ))|| \
				   (in_char == '_')){
					strTokenBuf.push_back( in_char );
				   //in_char = fgetc( fpScript );
				   FGETC(fpScript, in_char);
				}/* end while */
				//多读一个退回
				ungetc( in_char, fpScript );
				return ID;
			}break;
			case '=':{
				//清空右值
				strTokenBuf.clear();
				//in_char = fgetc( fpScript );
				FGETC(fpScript, in_char);
				while(in_char != ';'){
					//跳过无效字符
					while((in_char==' ')||(in_char=='\t')||(in_char=='\r')||\
						(in_char=='\n'))in_char=fgetc(fpScript);
					strTokenBuf.push_back( in_char );
					//in_char = fgetc( fpScript );
					FGETC(fpScript, in_char);
				}/* end while */
				ungetc( in_char, fpScript );
				return ASSIGNOP;
			}break;
			case '-':{
				//清空右值
				strTokenBuf.clear();
				//in_char = fgetc( fpScript );
				FGETC(fpScript, in_char);
				if( in_char == '>' ){
					//in_char = fgetc( fpScript );
					FGETC(fpScript, in_char);
					while(in_char != ';'){
						//跳过无效字符
						while((in_char==' ')||(in_char=='\t')||(in_char=='\r')||\
							(in_char=='\n'))in_char=fgetc(fpScript);
						strTokenBuf.push_back( in_char );
						//in_char = fgetc( fpScript );
						FGETC(fpScript, in_char);
					}/* end while */
					ungetc( in_char, fpScript );
					return FLINK;
				}/* end if */
				else{
					//error
					HANDLE_TOKEN_ERROR(TOKEN_FLINK_ERROR);
				}/* end else*/
			}break;
			case '<':{
				strTokenBuf.clear();
				//in_char = fgetc( fpScript );
				FGETC(fpScript, in_char);
				if( in_char == '-' ){
					//in_char = fgetc( fpScript );
					FGETC(fpScript, in_char);
					if( in_char == '>' ){
					//in_char = fgetc( fpScript );
					FGETC(fpScript, in_char);
						while(in_char != ';'){
							//跳过无效字符
							while((in_char==' ')||(in_char=='\t')||(in_char=='\r')||\
								(in_char=='\n'))in_char=fgetc(fpScript);
							strTokenBuf.push_back( in_char );
							//in_char = fgetc( fpScript );
							FGETC(fpScript, in_char);
						}/* end while */
						ungetc( in_char, fpScript );
						return DLINK;
					}/* end if */
					else{
						ungetc( in_char, fpScript );
						//in_char = fgetc( fpScript );
						FGETC(fpScript, in_char);
						while(in_char != ';'){
							//跳过无效字符
							while((in_char==' ')||(in_char=='\t')||(in_char=='\r')||\
								(in_char=='\n'))in_char=fgetc(fpScript);
							strTokenBuf.push_back( in_char );
							//in_char = fgetc( fpScript );
							FGETC(fpScript, in_char);
						}/* end while */
						ungetc( in_char, fpScript );
						return BLINK;
					}/* end else */
				}/* end if */
				else{
					//error
					HANDLE_TOKEN_ERROR(TOKEN_DBLINK_ERROR);
				}/* end else*/
			}break;
			case '{':{
				return BLPAREM;
			}break;
			case '}':{
            	return BRPAREM;
			}break;
			case ',':{
            	return COMMA;
			}break;
			case '#':{
				while(1){
					//in_char = fgetc( fpScript );
					FGETC(fpScript, in_char);
					if( in_char == '\n' )break;
				}/* end while */
			}break;
			case '(':{
				return LPAREM;
			}break;
			case ')':{
            	return RPAREM;
			}break;
			default:{
				//error
				HANDLE_TOKEN_WARNING(TOKEN_INVALID_ERROR);
			}
		}/* end switch */
	}/* end while */
	//关闭文件
	fclose( fpScript );
}/* end next_token */

