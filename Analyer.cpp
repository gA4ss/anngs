//---------------------------------------------------------------------------

#pragma hdrstop

#include "Analyer.h"
#include "Token.h"
#include "AnnGsToCpp.h"
#include "HashTbl.h"
#include "ErrorHandle.h"
#include "Public.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

extern string strTokenBuf;						/* Token.cpp */
extern SAnnGsToCppArgu AnnGsToCppArgu;			/* AnnGsToCpp.cpp */
extern bool CreateCppCode( const char * );		/* AnnGsToCpp.cpp */
extern void initAnnGsToCppArgu( SAnnGsToCppArgu& ); /* AnnGsToCpp.cpp */

bool math( int );

void analyzer( char *__szScriptName, char *__szCcodeName ){
	SNeurol DefValue_;
	initAnnGsToCppArgu( AnnGsToCppArgu );
	if( __szScriptName == NULL )cout << "the script file is NULL." << endl;
	if( !scaner( __szScriptName ) ){
		cout << "can not open ann script:" << __szScriptName << endl;
		return;
	}/* end if */
	//开始代码分析
	//建立符号表
	CreateHashTbl();
	int token;
	if( !math( CLASS_LAB ) ){
		//error
		HANDLE_ANALYER_FATAL_ERROR(ANALYER_CLASSNAME_ERROR);
	}/* end if */
	//获取类名
	AnnGsToCppArgu.strClassName = strTokenBuf;
	if( !math( BLPAREM ) ){
		//error
		HANDLE_ANALYER_ERROR(ANALYER_BLPAREM_ERROR);
	}/* end if  */
	//默认值
	//DefValue_.nInput = 0;
	//DefValue_.nOutput = 0;
	DefValue_.bInput = true;
	DefValue_.bOutput = true;
	DefValue_.weight = "1";
	DefValue_.gate = "1";
	DefValue_.bNodeActivationFunc = false;
	//DefValue_.activation = AnnGsToCppArgu.activation;
	DefValue_.excout = "1";
	DefValue_.inhout = "0";
	//开始检测代码
		//配置标号
		if( math( CONFIGURE_LAB ) ){
			if( !math( BLPAREM ) ){
				//error
				HANDLE_ANALYER_ERROR(ANALYER_BLPAREM_ERROR);
			}/* end if  */
			while( (token=next_token()) != BRPAREM ){
				switch( token ){
					//case ACTIVATION:{
					//	if( !math(ASSIGNOP) ){
					//		//error
					//	}/* end if */
					//	DefConfigure.activation = strTokenBuf;
					//	if( !math(SEMICOLON) ){
					//		//error
					//	}/* end if */
					//}break;
					case ACTIVATIONFUNC:{
						if( !math(ASSIGNOP) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
						}/* end if */
						//DefConfigure.activation_function = strTokenBuf;
						AnnGsToCppArgu.bActivationFunction = true;
						AnnGsToCppArgu.strDefActivationFunction = strTokenBuf;
						if( !math(SEMICOLON) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
						}/* end if */
					}break;
					case WEIGHT:{
						if( !math(ASSIGNOP) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
						}/* end if */
						AnnGsToCppArgu.weight = strTokenBuf;
						if( !math(SEMICOLON) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
						}/* end if */
					}break;
					case GATE:{
						if( !math(ASSIGNOP) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
						}/* end if */
						AnnGsToCppArgu.gate = strTokenBuf;
						if( !math(SEMICOLON) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
						}/* end if */
					}break;
					case EXCOUT:{
						if( !math(ASSIGNOP) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
						}/* end if */
						AnnGsToCppArgu.excout  = strTokenBuf;
						if( !math(SEMICOLON) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
						}/* end if */
					}break;
					case INHOUT:{
						if( !math(ASSIGNOP) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
						}/* end if */
						AnnGsToCppArgu.inhout = strTokenBuf;
						if( !math(SEMICOLON) ){
							//error
							HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
						}/* end if */
					}break;
					default:{
						//error
						HANDLE_ANALYER_ERROR(ANALYER_ATTRIBUTE_ERROR);
					}/* end default */
				}/* end switch */
			}/* end while */
			//DefValue_.nInput = 0;
			//DefValue_.nOutput = 0;
			//DefValue_.activation = AnnGsToCppArgu.activation;            
			DefValue_.bInput = true;
			DefValue_.bOutput = true;
			DefValue_.weight = AnnGsToCppArgu.weight;
			DefValue_.gate = AnnGsToCppArgu.gate;
			DefValue_.bNodeActivationFunc = false;
			DefValue_.bExcOut = false;
			DefValue_.bInhOut = false;
			DefValue_.bGate = false;
			DefValue_.bWeight = false;
			DefValue_.excout = AnnGsToCppArgu.excout;
			DefValue_.inhout = AnnGsToCppArgu.inhout;
		}/* end if */
		//定义神经细胞
		if( math( NEUROL_LAB ) ){
			if( !math( BLPAREM ) ){
				//error
				HANDLE_ANALYER_ERROR(ANALYER_BLPAREM_ERROR);
			}/* end if  */
			while( (token=next_token()) != SEMICOLON ){
				if( token == ID ){
					//增加一个细胞
					DefValue_.strNodeName = strTokenBuf;
					if( addNodeToTree( (strTokenBuf.c_str()), DefValue_ )==0 ){
                    	(AnnGsToCppArgu.nNumber)++;
					}/* end if */
				}/* end else */
				else{
				}/* end else */
			}/* end while */
			if( !math( BRPAREM ) ){
				//error
				HANDLE_ANALYER_ERROR(ANALYER_BRPAREM_ERROR);
			}/* end if */
		}/* end else if */
		//定义神经网络
		if( math( NEURALNET_LAB ) ){
			SNeurol PrevN;
			SNeurol NextN;
			//int nIndex_;
			if( !math( BLPAREM ) ){
				//error
				HANDLE_ANALYER_ERROR(ANALYER_BLPAREM_ERROR);
			}/* end if  */
			while( (token=next_token()) != BRPAREM ){
				switch(token){
					case ID:{
						memset(&PrevN, 0, sizeof(PrevN));
						memset(&NextN, 0, sizeof(NextN));
						PrevN = getValue( (strTokenBuf.c_str()) );
						token = next_token();
						switch(token){
							case FLINK:{
								//PrevN = getValue( (strTokenBuf.c_str()) );
								NextN = getValue( (strTokenBuf.c_str()) );
								PrevN.bOutput= false;
								NextN.bInput = false;
								//nIndex_ = getNodeIndex((NextN.strNodeName).c_str());
								//(PrevN.outputs).push_back( nIndex_ );
								//nIndex_ = getNodeIndex((PrevN.strNodeName).c_str());
								//(NextN.inputs).push_back( nIndex_ );
								(PrevN.outputs).push_back( NextN.strNodeName );
								(NextN.inputs).push_back( PrevN.strNodeName );
								//(PrevN.nOutput)++;
								//(NextN.nInput)++;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								setValue( ((NextN.strNodeName).c_str()), NextN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							case BLINK:{
								//PrevN = getValue( (strTokenBuf.c_str()) );
								NextN = getValue( (strTokenBuf.c_str()) );
								PrevN.bInput= false;
								NextN.bOutput = false;
								//nIndex_ = getNodeIndex((NextN.strNodeName).c_str());
								//(PrevN.inputs).push_back( nIndex_ );
								//nIndex_ = getNodeIndex((PrevN.strNodeName).c_str());
								//(NextN.outputs).push_back( nIndex_ );
								(PrevN.inputs).push_back( NextN.strNodeName );
								(NextN.outputs).push_back( PrevN.strNodeName );
								//(PrevN.nInput)++;
								//(NextN.nOutput)++;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								setValue( ((NextN.strNodeName).c_str()), NextN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							case DLINK:{
								//PrevN = getValue( (strTokenBuf.c_str()) );
								NextN = getValue( (strTokenBuf.c_str()) );
								PrevN.bInput= false;
								PrevN.bOutput= false;
								NextN.bInput = false;
								NextN.bOutput = false;
								//nIndex_ = getNodeIndex((NextN.strNodeName).c_str());
								//(PrevN.inputs).push_back( nIndex_ );
								//nIndex_ = getNodeIndex((NextN.strNodeName).c_str());
								//(PrevN.outputs).push_back( nIndex_ );
								//nIndex_ = getNodeIndex((PrevN.strNodeName).c_str());
								//(NextN.inputs).push_back( nIndex_ );
								//nIndex_ = getNodeIndex((PrevN.strNodeName).c_str());
								//(NextN.outputs).push_back( nIndex_ );
								(PrevN.inputs).push_back( NextN.strNodeName );
								(PrevN.outputs).push_back( NextN.strNodeName );
								(NextN.inputs).push_back( PrevN.strNodeName );
								(NextN.outputs).push_back( PrevN.strNodeName );
								//(PrevN.nInput)++;
								//(PrevN.nOutput)++;
								//(NextN.nInput)++;
								//(NextN.nOutput)++;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								setValue( ((NextN.strNodeName).c_str()), NextN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							//case ACTIVATION:{
							//	if( !math(ASSIGNOP) ){
							//		//error
							//	}/* end if */
							//	//PrevN = getValue( (strTokenBuf.c_str()) );
							//	PrevN.activation = strTokenBuf;
							//	setValue( ((PrevN.strNodeName).c_str()), PrevN );
							//	if( !math(SEMICOLON) ){
							//		//error
							//	}/* end if */
							//}break;
							case ACTIVATIONFUNC:{
								if( !math(ASSIGNOP) ){
									//error
								}/* end if */
								//PrevN = getValue( strTokenBuf.c_str() );
								AnnGsToCppArgu.bNodeActivationFunction = true;
								PrevN.bNodeActivationFunc = true;
								PrevN.activation_function = strTokenBuf;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							case WEIGHT:{
								if( !math(ASSIGNOP) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
								}/* end if */
								//PrevN = getValue( strTokenBuf.c_str() );
								AnnGsToCppArgu.bWeight = true;
								PrevN.bWeight = true;
								PrevN.weight = strTokenBuf;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							case GATE:{
								if( !math(ASSIGNOP) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
								}/* end if */
								AnnGsToCppArgu.bGate = true;
								PrevN.bGate = true;
								//PrevN = getValue( (strTokenBuf.c_str()) );
								PrevN.gate = strTokenBuf;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							case EXCOUT:{
								if( !math(ASSIGNOP) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
								}/* end if */
								AnnGsToCppArgu.bExcOut = true;
								PrevN.bExcOut = true;
								PrevN.excout = strTokenBuf;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							case INHOUT:{
								if( !math(ASSIGNOP) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_ASSIGNOP_ERROR);
								}/* end if */
								AnnGsToCppArgu.bInhOut = true;
                                PrevN.bInhOut = true;
								PrevN.inhout = strTokenBuf;
								setValue( ((PrevN.strNodeName).c_str()), PrevN );
								if( !math(SEMICOLON) ){
									//error
									HANDLE_ANALYER_ERROR(ANALYER_SEMICOLON_ERROR);
								}/* end if */
							}break;
							default:{
								//error
								HANDLE_ANALYER_WARNING(ANALYER_ATTRIBUTE_ERROR);
							}/* end default */
						}/* end switch */
					}break;
					default:{
						HANDLE_ANALYER_WARNING(ANALYER_ID_ERROR);
					}/* end default */
				}/* end switch */
			}/* end while */
		}/* end else if */
		else{
			//error
			HANDLE_ANALYER_FATAL_ERROR(ANALYER_INVALIDLABEL_ERROR);
		}/* end else */
	if( !math( BRPAREM ) ){
		//error
		HANDLE_ANALYER_ERROR(ANALYER_BRPAREM_ERROR);
	}/* end if */
	//计算错误与警告的数量
	HANDEL_ERROR_END;
	//创建文件
	CreateCppCode( __szCcodeName );
	//释放符号表
	FreeHashTbl();

}/* end analyzer */

bool math( int __nToken ){
	if( __nToken != next_token() )return false;
	return true;
}/* end math */
