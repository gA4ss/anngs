//---------------------------------------------------------------------------
#ifndef AnnGsToCppH
#define AnnGsToCppH
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct SAnnGsToCppArgu_Types{
	string strClassName;
	int nNumber;
	//int nInput;
	//int nOutput;
	string strDefActivationFunction;
	bool bActivationFunction;
	bool bNodeActivationFunction;
	bool bGate;
	bool bWeight;
	bool bExcOut;
	bool bInhOut;
	string gate;
	string weight;
	string excout;
	string inhout;
}SAnnGsToCppArgu;

typedef struct SNeurol_Types{
	string strNodeName;
	bool bNodeActivationFunc;
	bool bGate;
	bool bWeight;
	bool bExcOut;
	bool bInhOut;	
	bool bInput;
	bool bOutput;
	string code;
	string weight;
	string gate;
	//string activation;
	string activation_function;
	string excout;
	string inhout;
	//int nInput;
	//int nOutput;
	//vector<int> inputs;
	//vector<int> outputs;
	vector<string> inputs;
	vector<string> outputs;
}SNeurol;

//公共宏
#define LINEMARK(F)		fprintf( F, "%s\r\n", szLineMark )

//公共部分

#define CLASSHEAD(F)	fprintf( F, "class %s{\r\n", (AnnGsToCppArgu.strClassName).c_str() );
#define CLASSEND(F)     fprintf( F, "%s;\r\n", "}" );

#define CLASSNAME(F)	fprintf( F, "%s", (AnnGsToCppArgu.strClassName).c_str() );
#define CLASSCOMMA(F)   fprintf( F, "%s", "::" );

#define CLASSTITLE(F)   CLASSNAME(F);\
						CLASSCOMMA(F);

#define VOIDTYPE(F)     fprintf( F, "%s", "void" );

#define CHARTYPE(F)     fprintf( F, "%s", "char" );
#define SHORTTYPE(F)    fprintf( F, "%s", "short" );
#define INTTYPE(F)     	fprintf( F, "%s", "int" );
#define LONGTYPE(F)     fprintf( F, "%s", "long" );
#define FLOATTYPE(F)    fprintf( F, "%s", "float" );
#define DOUBLETYPE(F)   fprintf( F, "%s", "double" );
#define BOOLTYPE(F)		fprintf( F, "%s", "bool" );

#define UCHARTYPE(F)     fprintf( F, "%s", "unsigned char" );
#define USHORTTYPE(F)    fprintf( F, "%s", "unsigned short" );
#define UINTTYPE(F)      fprintf( F, "%s", "unsigned int" );
#define ULONGTYPE(F)     fprintf( F, "%s", "unsigned long" );
#define UFLOATTYPE(F)    fprintf( F, "%s", "unsigned float" );
#define UDOUBLETYPE(F)   fprintf( F, "%s", "unsigned double" );

#define ANNTYPE(F)       		fprintf( F, "%s", "an_t" );
#define WEIGHTTYPE(F)	 		fprintf( F, "%s", "weight_t" );
#define	UNITLEVELTYPE(F)        fprintf( F, "%s", "unit_level_t");
#define LEVELTYPE(F)	 		fprintf( F, "%s", "level_t" );

#define DEFANNTYPEMAC(F) 		fprintf( F, "%s", "#define an_t vector<double>" );
#define DEFWEIGHTTYPEMAC(F)  	fprintf( F, "%s", "#define weight_t vector<double>" );
#define DEFUNITLEVELTYPEMAC(F)	fprintf( F, "%s", "#define unit_level_t vector<int>");
#define DEFLEVELTYPEMAC(F)      fprintf( F, "%s", "#define level_t vector<vector<int> >" );

//#define DEFLEVELTYPEMAC(F)		fprintf( F, "%s", "#define level_t vector<SNeurol *>");

#define LPAREM_OPT(F)    fprintf( F, "%s", "(" );
#define RPAREM_OPT(F)    fprintf( F, "%s", ")" );

#define BLPAREM_OPT(F)   fprintf( F, "%s", "{" );
#define BRPAREM_OPT(F)   fprintf( F, "%s", "}" );

#define ASSIGNOP_OPT(F)  fprintf( F, "%s", "=" );
#define SEMICOLON_OPT(F) fprintf( F, "%s", ";" );

#define PUBLIC_OPT(F)    fprintf( F, "%s", "public:" );
#define PRIVATE_OPT(F)   fprintf( F, "%s", "private:" );

#define LN_OPT(F)        fprintf( F, "%s", "\r\n" );
#define TAB_OPT(F)       fprintf( F, "%c", '\t' );

#define BLNK_OPT(F)		 fprintf( F, "%c", ' ' );
#define COMMA_OPT(F)	 fprintf( F, "%c", ',' );

//函数名字
#define INIT_FUN_NAME(F)		 fprintf( F, "%s", (AnnGsToCppArgu.strClassName).c_str() );
#define FREE_FUN_NAME(F)		 fprintf( F, "~%s", (AnnGsToCppArgu.strClassName).c_str() );
//#define INPUTS_FUN_NAME(F)		 fprintf( F, "%s", "Inputs" );
//#define OUTPUTS_FUN_NAME(F)		 fprintf( F, "%s", "Outputs" );
#define CREATENEURALNET_FUN_NAME(F)       fprintf( F, "%s", "CreateNeuralNet" );
#define DEFFACTIVATIONFUNC_FUN_NAME(F)	 fprintf( F, "%s", "ActivationFuncDef" );
#define NODEXFACTIVATIONFUNC_FUN_NAME(F,N)	 fprintf( F, "%s%s", "ActivationFunc", N );
#define UPDATA_FUN_NAME(F)		 	fprintf( F, "%s", "Updata" );
#define INSERTLEVEL_FUN_NAME(F)		fprintf( F, "%s", "InsertLevel");
#define CHECKFIND_FUN_NAME(F)		fprintf( F, "%s", "CheckFind" );
#define PUTWEIGHT_FUN_NAME(F)		fprintf( F, "%s", "put_weight" );
#define RUN_FUN_NAME(F)				fprintf( F, "%s", "run" );

#define DEF_INIT_FUN(F)						INIT_FUN_NAME(F);LPAREM_OPT(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_FREE_FUN(F)         			FREE_FUN_NAME(F);LPAREM_OPT(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_CREATENEURALNET_FUN(F)    		VOIDTYPE(F);BLNK_OPT(F);CREATENEURALNET_FUN_NAME(F);LPAREM_OPT(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_DEFFACTIVATIONFUNC_FUN(F)   	DOUBLETYPE(F);BLNK_OPT(F);DEFFACTIVATIONFUNC_FUN_NAME(F);LPAREM_OPT(F);NEUROL_STRC_NAME(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_NODEXFACTIVATIONFUNC_FUN(F,N) 	DOUBLETYPE(F);BLNK_OPT(F);NODEXFACTIVATIONFUNC_FUN_NAME(F,N);LPAREM_OPT(F);NEUROL_STRC_NAME(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_UPDATA_FUN(F)               	DOUBLETYPE(F);BLNK_OPT(F);UPDATA_FUN_NAME(F);LPAREM_OPT(F);NEUROL_STRC_POINT(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_INSERTLEVEL_FUN(F)              VOIDTYPE(F);BLNK_OPT(F);INSERTLEVEL_FUN_NAME(F);LPAREM_OPT(F);ANNTYPE(F);COMMA_OPT(F);LEVELTYPE(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_CHECKFIND(F)                    BOOLTYPE(F);BLNK_OPT(F);CHECKFIND(F);LPAREM_OPT(F);ANNTYPE(F);COMMA_OPT(F);INTTYPE(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_PUTWEIGHT(F)                    VOIDTYPE(F);BLNK_OPT(F);PUTWEIGHT(F);LPAREM_OPT(F);WEIGHTTYPE(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_RUN(F)                          ANNTYPE(F);BLNK_OPT(F);RUN_FUN_NAME(F);LPAREM_OPT(F);ANNTYPE(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);

//结构定义
#define NEUROL_STRC_NAME(F)			fprintf( F, "%s", "SNeurol" );
#define NEUROL_STRC_POINT(F)		fprintf( F, "%s", "SNeurol *");
#define NEUROL_STRC_REF(F)			fprintf( F, "%s", "SNeurol &");

#define NEUROL_STRC_DEFINE_HEAD(F)	fprintf( F, "%s{", "typedef struct SNeurol_Types" );
#define NEUROL_STRC_FACT(F)		 	fprintf( F, "%s;", "double activation" );
#define NEUROL_STRC_GATE(F)			fprintf( F, "%s;", "double gate" );
#define NEUROL_STRC_WEIGHT(F)		fprintf( F, "%s;", "double weight" );
#define NEUROL_STRC_FACFUNC(F)		fprintf( F, "%s;", "double (*activation_function)(struct SNeurol_Types)" );
#define NEUROL_STRC_EXC_OUT(F)      fprintf( F, "%s;", "double exc_out" );
#define NEUROL_STRC_INH_OUT(F)      fprintf( F, "%s;", "double inh_out" );
//#define NEUROL_STRC_INSUM(F)		fprintf( F, "%s",  "int nInput" );
//#define NEUROL_STRC_OUTSUM(F)		fprintf( F, "%s",  "int nOutput" );
#define NEUROL_STRC_INPUTS(F)		fprintf( F, "%s;", "vector<int> inputs");
#define NEUROL_STRC_OUTPUTS(F)		fprintf( F, "%s;", "vector<int> outputs" );
#define NEUROL_STRC_VECINPUT(F)     fprintf( F, "%s;", "an_t anIn" );
#define NEUROL_STRC_DEFINE_END(F)	fprintf( F, "}%s;", "SNeurol" );

//宏定义
#define NEUROLTOTAL_NAME(F,N)			fprintf( F, "%s", "NEUROL_TOTAL );
#define NEUROLINPUTS_NAME(F,N)          fprintf( F, "%s", "NEUROL_INPUTS );
#define NEUROLOUTPUTS_NAME(F,N)         fprintf( F, "%s", "NEUROL_OUTPUTS );

#define NEUROLGATE_NAME(F,N)            fprintf( F, "%s", "GATE");
#define NEUROLWEIGHT_NAME(F,N)          fprintf( F, "%s", "WEIGHT");
#define NEUROLOUT_EXC_NAME(F,N)         fprintf( F, "%s", "OUT_EXC");
#define NEUROLOUT_INH_NAME(F,N)         fprintf( F, "%s", "OUT_INH");

#define NEUROLX_NAME(F,S)				fprintf( F, "%s", S );

#define NEUROLTOTAL(F,N)				fprintf( F, "#define NEUROL_TOTAL	%d", N );
#define NEUROLINPUTS(F,N)           	fprintf( F, "#define NEUROL_INPUTS	%d", N );
#define NEUROLOUTPUTS(F,N)          	fprintf( F, "#define NEUROL_OUTPUTS	%d", N );

#define NEUROLGATE(F,N)             	fprintf( F, "#define GATE	%s", N );
#define NEUROLWEIGHT(F,N)           	fprintf( F, "#define WEIGHT	%s", N );
#define NEUROLOUT_EXC(F,N)          	fprintf( F, "#define OUT_EXC	%s", N );
#define NEUROLOUT_INH(F,N)          	fprintf( F, "#define OUT_INH	%s", N );

#define NEUROLX(F,S,N)					fprintf( F, "#define %s	%d\r\n", S, N );

//私有变量定义
#define PRIVATE_NEUROLLIST_NAME(F)				fprintf( F, "%s", "m_root" );
#define PRIVATE_NEUROLINPUTS_NAME(F)			fprintf( F, "%s", "m_inputs" );
#define PRIVATE_NEUROLOUTPUTS_NAME(F)			fprintf( F, "%s", "m_outputs" );
#define PRIVATE_NEUROLHIDELEVEL_NAME(F)			fprintf( F, "%s", "m_hidelevels");

#define DEFNEUROLLIST(F)    			fprintf( F, "%s;", "SNeurol m_root[NEUROL_TOTAL]");
#define DEFNEUROLINPUTS(F)              fprintf( F, "%s;", "vector<int> m_inputs");
#define DEFNEUROLOUTPUTS(F)	            fprintf( F, "%s;", "vector<int> m_outputs");
#define DEFNEUROLHIDELEVEL(F)			fprintf( F, "%s;", "level_t m_hidelevels");

//函数定义
#define DEF_INIT_FUN_HEAD(F)						INIT_FUN_NAME(F);LPAREM_OPT(F);RPAREM_OPT(F);

#define DEF_FREE_FUN_HEAD(F)         				FREE_FUN_NAME(F);LPAREM_OPT(F);RPAREM_OPT(F);

#define DEF_CREATENEURALNET_FUN_HEAD(F)    			CREATENEURALNET_FUN_NAME(F);LPAREM_OPT(F);RPAREM_OPT(F);

#define DEFFACTIVATIONFUNC_ARGV_NEUROL(F)			fprintf( F, "%s", "__Neurol");
#define DEF_DEFFACTIVATIONFUNC_FUN_HEAD(F)   		DEFFACTIVATIONFUNC_FUN_NAME(F);LPAREM_OPT(F);NEUROL_STRC_NAME(F);BLNK_OPT(F);DEFFACTIVATIONFUNC_ARGV_NEUROL(F);RPAREM_OPT(F);

#define NODEXFACTIVATIONFUNC_ARGV_NEUROL(F)			fprintf( F, "%s", "__Neurol");
#define DEF_NODEXFACTIVATIONFUNC_FUN_HEAD(F,N) 		NODEXFACTIVATIONFUNC_FUN_NAME(F,N);LPAREM_OPT(F);NEUROL_STRC_NAME(F);BLNK_OPT(F);NODEXFACTIVATIONFUNC_ARGV_NEUROL(F);RPAREM_OPT(F);

#define INSERTLEVEL_ARGV_VECLEVEL(F)				fprintf( F, "%s", "__vecLevel" );
#define INSERTLEVEL_ARGV_MAINLEVEL(F)				fprintf( F, "%s", "__mainLevel");
#define DEF_INSERTLEVEL_FUN_HEAD(F)               	INSERTLEVEL_FUN_NAME(F);LPAREM_OPT(F);UNITLEVELTYPE(F);BLNK_OPT(F);INSERTLEVEL_ARGV_VECLEVEL(F);COMMA_OPT(F);LEVELTYPE(F);BLNK_OPT(F);INSERTLEVEL_ARGV_MAINLEVEL(F);RPAREM_OPT(F);

#define UPDATA_ARGV_CURRNEUROL(F)					fprintf( F, "%s", "__CurrNeurol" );
#define DEF_UPDATA_FUN_HEAD(F)               		UPDATA_FUN_NAME(F);LPAREM_OPT(F);NEUROL_STRC_POINT(F);BLNK_OPT(F);UPDATA_ARGV_CURRNEUROL(F);RPAREM_OPT(F);

#define CHECKFIND_ARGV_NEUROLLIST(F)				fprintf( F, "%s", "__NeurolList" );
#define CHECKFIND_ARGV_NEUROLTARGET(F)              fprintf( F, "%s", "__NeurolTarget" );
#define DEF_CHECKFIND_HEAD(F)                    	CHECKFIND_FUN_NAME(F);LPAREM_OPT(F);UNITLEVELTYPE(F);BLNK_OPT(F);CHECKFIND_ARGV_NEUROLLIST(F);COMMA_OPT(F);INTTYPE(F);BLNK_OPT(F);CHECKFIND_ARGV_NEUROLTARGET(F);RPAREM_OPT(F);

#define PUTWEIGHT_ARGV_WEIGHTLIST(F)				fprintf( F, "%s", "__WeightList" );
#define DEF_PUTWEIGHT_HEAD(F)                    	PUTWEIGHT_FUN_NAME(F);LPAREM_OPT(F);WEIGHTTYPE(F);BLNK_OPT(F);PUTWEIGHT_ARGV_WEIGHTLIST(F);RPAREM_OPT(F);

#define RUN_ARGV_INPUTLIST(F)						fprintf( F, "%s", "__InputList" );
#define DEF_RUN_HEAD(F)                          	RUN_FUN_NAME(F);LPAREM_OPT(F);ANNTYPE(F);BLNK_OPT(F);RUN_ARGV_INPUTLIST(F);RPAREM_OPT(F);

#define DEF_INIT_FUN_CPP(F)							CLASSNAME(F);CLASSCOMMA(F);DEF_INIT_FUN_HEAD(F);LN_OPT(F);
#define DEF_FREE_FUN_CPP(F)                         CLASSNAME(F);CLASSCOMMA(F);DEF_FREE_FUN_HEAD(F);LN_OPT(F);
#define DEF_CREATENEURALNET_FUN_CPP(F)              VOIDTYPE(F);BLNK_OPT(F);CLASSNAME(F);CLASSCOMMA(F);DEF_CREATENEURALNET_FUN_HEAD(F);LN_OPT(F);
#define DEF_DEFFACTIVATIONFUNC_FUN_CPP(F)           DOUBLETYPE(F);BLNK_OPT(F);DEF_DEFFACTIVATIONFUNC_FUN_HEAD(F);LN_OPT(F);
#define DEF_NODEXFACTIVATIONFUNC_FUN_CPP(F,N)       DOUBLETYPE(F);BLNK_OPT(F);DEF_NODEXFACTIVATIONFUNC_FUN_HEAD(F,N);LN_OPT(F);
#define DEF_INSERTLEVEL_FUN_CPP(F)					VOIDTYPE(F);BLNK_OPT(F);CLASSNAME(F);CLASSCOMMA(F);DEF_INSERTLEVEL_FUN_HEAD(F);LN_OPT(F);
#define DEF_UPDATA_FUN_CPP(F)               		DOUBLETYPE(F);BLNK_OPT(F);CLASSNAME(F);CLASSCOMMA(F);DEF_UPDATA_FUN_HEAD(F);LN_OPT(F);
#define DEF_CHECKFIND_CPP(F)                    	BOOLTYPE(F);BLNK_OPT(F);CLASSNAME(F);CLASSCOMMA(F);DEF_CHECKFIND_HEAD(F);LN_OPT(F);
#define DEF_PUTWEIGHT_CPP(F)                    	VOIDTYPE(F);BLNK_OPT(F);CLASSNAME(F);CLASSCOMMA(F);DEF_PUTWEIGHT_HEAD(F);LN_OPT(F);
#define DEF_RUN_CPP(F)                          	ANNTYPE(F);BLNK_OPT(F);CLASSNAME(F);CLASSCOMMA(F);DEF_RUN_HEAD(F);LN_OPT(F);
//函数定义
#define DEF_INIT_FUN_H(F)							DEF_INIT_FUN_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_FREE_FUN_H(F)                         	DEF_FREE_FUN_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_CREATENEURALNET_FUN_H(F)              	VOIDTYPE(F);BLNK_OPT(F);DEF_CREATENEURALNET_FUN_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_INSERTLEVEL_FUN_HEAD_H(F)               VOIDTYPE(F);BLNK_OPT(F);DEF_INSERTLEVEL_FUN_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_UPDATA_FUN_H(F)               			DOUBLETYPE(F);BLNK_OPT(F);DEF_UPDATA_FUN_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_CHECKFIND_H(F)                    		BOOLTYPE(F);BLNK_OPT(F);DEF_CHECKFIND_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_PUTWEIGHT_H(F)                    		VOIDTYPE(F);BLNK_OPT(F);DEF_PUTWEIGHT_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
#define DEF_RUN_H(F)                          		ANNTYPE(F);BLNK_OPT(F);DEF_RUN_HEAD(F);SEMICOLON_OPT(F);LN_OPT(F);
//函数实现
#define DEF_INIT_FUN_CODE(F)						DEF_INIT_FUN_CPP(F);\
													BLPAREM_OPT(F);LN_OPT(F);\
														TAB_OPT(F);CREATENEURALNET_FUN_NAME(F);LPAREM_OPT(F);RPAREM_OPT(F);SEMICOLON_OPT(F);LN_OPT(F);\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_FREE_FUN_CODE(F)         				DEF_FREE_FUN_CPP(F);\
													BLPAREM_OPT(F);LN_OPT(F);\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_CREATENEURALNET_FUN_CODE(F)    			DEF_CREATENEURALNET_FUN_CPP(F);


#define DEF_DEFFACTIVATIONFUNC_FUN_CODE(F,S)   		DEF_DEFFACTIVATIONFUNC_FUN_CPP(F);\
													BLPAREM_OPT(F);LN_OPT(F);\
														TAB_OPT(F);fprintf( F, "return %s;\r\n", S );\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_NODEXFACTIVATIONFUNC_FUN_CODE(F,N,S) 	DEF_NODEXFACTIVATIONFUNC_FUN_CPP(F,N);\
													BLPAREM_OPT(F);LN_OPT(F);\
														TAB_OPT(F);fprintf( F, "return %s;\r\n", S );\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_INSERTLEVEL_FUN_CODE(F)                 DEF_INSERTLEVEL_FUN_CPP(F);\
													BLPAREM_OPT(F);LN_OPT(F);\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "unit_level_t vecChange_");\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "unit_level_t vecNext_");\
														TAB_OPT(F);fprintf( F, "%s\r\n", "for(int i=0; i<__vecLevel.size(); i++)");\
														TAB_OPT(F);fprintf( F, "%s\r\n", "{");\
														TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s;\r\n", "if(!CheckFind(vecChange_, __vecLevel[i]))vecChange_.push_back(__vecLevel[i])");\
														TAB_OPT(F);fprintf( F, "%s\r\n", "}");\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "__mainLevel.push_back(vecChange_)");\
														TAB_OPT(F);fprintf( F, "%s\r\n", "for(int i=0; i<vecChange_.size(); i++)");\
														TAB_OPT(F);fprintf( F, "%s\r\n", "{");\
														TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s\r\n", "if(!(m_root[vecChange_[i]].outputs).empty())");\
														TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s\r\n", "{");\
														TAB_OPT(F);TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s\r\n", "for(int j=0; j<(m_root[vecChange_[i]].outputs).size(); i++)");\
														TAB_OPT(F);TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s\r\n", "{");\
														TAB_OPT(F);TAB_OPT(F);TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s;\r\n", "vecNext_.push_back(m_root[vecChange_[i]].outputs[j])" );\
														TAB_OPT(F);TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s\r\n", "}");\
														TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s\r\n", "}");\
														TAB_OPT(F);fprintf( F, "%s\r\n", "}");\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "if(vecNext_.empty())return");\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "else InsertLevel(vecNext_, __mainLevel)" );\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_UPDATA_FUN_CODE(F)               		DEF_UPDATA_FUN_CPP(F);\
													BLPAREM_OPT(F);LN_OPT(F);\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "double sum_ = 0" );\
														TAB_OPT(F);fprintf( F, "%s\r\n", "for(int i=0; i<(__CurrNeurol->nInput); i++)");\
														TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s\r\n", "sum_ += (__CurrNeurol->anIn[i])" );\
														TAB_OPT(F);fprintf( F, "return %s;\r\n", "sum_" );\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_CHECKFIND_CODE(F)                       DEF_CHECKFIND_CPP(F);\
													BLPAREM_OPT(F);LN_OPT(F);\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "int nList = 0" );\
		   												TAB_OPT(F);fprintf( F, "%s;\r\n", "nList = __NeurolList.size()" );\
														TAB_OPT(F);fprintf( F, "%s\r\n", "for(int i=0; i<nList; i++)" );\
														TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s;\r\n", "if(__NeurolList[i] == __NeurolTarget)return true" );\
														TAB_OPT(F);fprintf( F, "%s;\r\n", "return false" );\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_PUTWEIGHT_CODE(F)                    	DEF_PUTWEIGHT_CPP(F);\
													BLPAREM_OPT(F);LN_OPT(F);\
														TAB_OPT(F);fprintf( F, "%s\r\n", "for(int i=0; i<NEUROL_TOTAL; i++)" );\
														TAB_OPT(F);TAB_OPT(F);fprintf( F, "%s;\r\n", "m_root[i].weight = __WeightList[i]" );\
													BRPAREM_OPT(F);LN_OPT(F);

#define DEF_RUN_CODE(F)                          	DEF_RUN_CPP(F);\

//输出
#define OUT_FILE(F,S)								fprintf( F, "%s", S );
#define OUT_FILE_LINE(F,S)							fprintf( F, "%s\r\n", S );
#define OUT_FORMAT(F,M,S)							fprintf( F, M, S );
#define OUT_FORMAT_LINE(F,M,S)						fprintf( F, M, S );OUT_FILE(F, "\r\n");

//H文件摸版
	//H头模版
	#define HTITLE  strHHeader = "#ifndef ";\
					strHHeader += makeDefineHead(strFileName);\
					strHHeader += "\r\n";\
					strHHeader += "#define ";\
					strHHeader += makeDefineHead(strFileName);\
					strHHeader += "\r\n";\
					strHIncludeFile = "#include <iostream>\r\n";\
					strHIncludeFile += "#include <string>\r\n";\
					strHIncludeFile += "#include <vector>\r\n";\
					strHIncludeFile += "#include <math.h>\r\n";\
					strUsStd = "using namespace std;";\
                	fprintf( fpHCode, "%s", strHHeader.c_str());\
					fprintf( fpHCode, "\/\/%s\r\n", strHFileName.c_str() );\
					LINEMARK(fpHCode);\
					fprintf( fpHCode, "%s\r\n", strHIncludeFile.c_str() );\
					fprintf( fpHCode, "%s\r\n", strUsStd.c_str() );\
					LINEMARK(fpHCode);

	#define HEND    LINEMARK(fpHCode);\
					fprintf( fpHCode, "%s\r\n", "#endif" );

	#define HPUBLIC		PUBLIC_OPT(fpHCode);\
						LN_OPT(fpHCode);

	#define HPRIVATE	PRIVATE_OPT(fpHCode);\
						LN_OPT(fpHCode);

	#define HCLASSHEAD	CLASSHEAD(fpHCode);
	#define HCLASSEND	CLASSEND(fpHCode);
	#define HLINEMARK	LINEMARK(fpHCode);LN_OPT(fpHCode);

	//类型定义
	#define HDEFANNTYPEMAC 			DEFANNTYPEMAC(fpHCode);
	#define HDEFWEIGHTTYPEMAC   	DEFWEIGHTTYPEMAC(fpHCode);
	#define HDEFLEVELTYPEMAC		DEFLEVELTYPEMAC(fpHCode);
	#define HDEFDEFUNITLEVELTYPEMAC	DEFUNITLEVELTYPEMAC(fpHCode);

	//结构定义
	#define HNEUROL_STRC_NAME			NEUROL_STRC_NAME(fpHCode);
	#define HNEUROL_STRC_DEFINE_HEAD	NEUROL_STRC_DEFINE_HEAD(fpHCode);
	#define HNEUROL_STRC_FACT		 	NEUROL_STRC_FACT(fpHCode);
	#define HNEUROL_STRC_GATE			NEUROL_STRC_GATE(fpHCode);
	#define HNEUROL_STRC_WEIGHT			NEUROL_STRC_WEIGHT(fpHCode);	
	#define HNEUROL_STRC_FACFUNC		NEUROL_STRC_FACFUNC(fpHCode);
	#define HNEUROL_STRC_EXC_OUT     	NEUROL_STRC_EXC_OUT(fpHCode);
	#define HNEUROL_STRC_INH_OUT	    NEUROL_STRC_INH_OUT(fpHCode)
	//#define HNEUROL_STRC_INSUM       	NEUROL_STRC_INSUM(fpHCode);
	//#define HNEUROL_STRC_OUTSUM       NEUROL_STRC_OUTSUM(fpHCode);
	#define HNEUROL_STRC_INPUTS			NEUROL_STRC_INPUTS(fpHCode);
	#define HNEUROL_STRC_OUTPUTS		NEUROL_STRC_OUTPUTS(fpHCode);
	#define HNEUROL_STRC_VECINPUT     	NEUROL_STRC_VECINPUT(fpHCode);
	#define HNEUROL_STRC_DEFINE_END     NEUROL_STRC_DEFINE_END(fpHCode);

	//函数
	#define HINIT_FUN_NAME		 					INIT_FUN_NAME(fpHCode);
	#define HFREE_FUN_NAME		 					FREE_FUN_NAME(fpHCode);
	#define HINPUTS_FUN_NAME						INPUTS_FUN_NAME(fpHCode);
	#define HOUTPUTS_FUN_NAME						OUTPUTS_FUN_NAME(fpHCode);
	#define HCREATENEURALNET_FUN_NAME    			CREATENEURALNET_FUN_NAME(fpHCode);
	#define HDEFFACTIVATIONFUNC_FUN_NAME			DEFFACTIVATIONFUNC_FUN_NAME(fpHCode);
	#define HNODEXFACTIVATIONFUNC_FUN_NAME(N)	 	NODEXFACTIVATIONFUNC_FUN_NAME(fpHCode,N);
	#define HINSERTLEVEL_FUN_NAME                   INSERTLEVEL_FUN_NAME(fpHCode);
	#define HUPDATA_FUN_NAME		 				UPDATA_FUN_NAME(fpHCode);
	#define HCREATENEUROL_FUN_NAME(N)				CREATENEUROL_FUN_NAME(fpHCode,N);
	#define HRUN_FUN_NAME							RUN_FUN_NAME(fpHCode);
	#define HPUTWEIGHT                           	PUTWEIGHT(fpHCode);
	#define HCHECKFIND								CHECKFIND(fpHCode);

	//宏
	#define HNEUROLTOTAL(N)							NEUROLTOTAL(fpHCode, N);
	#define HNEUROLINPUTS(N)           				NEUROLINPUTS(fpHCode, N);
	#define HNEUROLOUTPUTS(N)          				NEUROLOUTPUTS(fpHCode, N);
	#define HNEUROLGATE(N)             				NEUROLGATE(fpHCode, N);
	#define HNEUROLWEIGHT(N)           				NEUROLWEIGHT(fpHCode, N);
	#define HNEUROLOUT_EXC(N)          				NEUROLOUT_EXC(fpHCode, N);
	#define HNEUROLOUT_INH(N)         				NEUROLOUT_INH(fpHCode, N);
	#define HNEUROLX(S,N)							NEUROLX(fpHCode, S, N);

    //私有变量定义
	#define HNEUROLLIST_NAME						PRIVATE_NEUROLLIST_NAME(fpHCode);
	#define HNEUROLINPUTS_NAME						PRIVATE_NEUROLINPUTS_NAME(fpHCode);
	#define HNEUROLOUTPUTS_NAME						PRIVATE_NEUROLOUTPUTS_NAME(fpHCode);
	#define HDEFNEUROLHIDELEVEL_NAME				PRIVATE_NEUROLHIDELEVEL_NAME(fpHCode)

	#define HDEFNEUROLLIST    						DEFNEUROLLIST(fpHCode);
	#define HDEFNEUROLINPUTS             			DEFNEUROLINPUTS(fpHCode);
	#define HDEFNEUROLOUTPUTS	        			DEFNEUROLOUTPUTS(fpHCode);
	#define HDEFNEUROLHIDELEVEL                     DEFNEUROLHIDELEVEL(fpHCode);
	
	//换行与制表
	#define HTAB_OPT                    			TAB_OPT(fpHCode);
	#define HLN_OPT                     			LN_OPT(fpHCode);

	//函数声明
	#define HDEF_INIT_FUN_HEAD						DEF_INIT_FUN_H(fpHCode);
	#define HDEF_FREE_FUN_HEAD         				DEF_FREE_FUN_H(fpHCode);
	#define HDEF_CREATENEURALNET_FUN_HEAD    		DEF_CREATENEURALNET_FUN_H(fpHCode);
	#define HDEF_INSERTLEVEL_FUN_HEAD              	DEF_INSERTLEVEL_FUN_HEAD_H(fpHCode);
	#define HDEF_UPDATA_FUN_HEAD               		DEF_UPDATA_FUN_H(fpHCode);
	#define HDEF_CHECKFIND_HEAD                   	DEF_CHECKFIND_H(fpHCode);
	#define HDEF_PUTWEIGHT_HEAD                    	DEF_PUTWEIGHT_H(fpHCode);
	#define HDEF_RUN_HEAD                          	DEF_RUN_H(fpHCode);

	//#define HDEF_DEFFACTIVATIONFUNC_FUN_HEAD   		DEF_DEFFACTIVATIONFUNC_FUN_H(fpHCode);
	//#define HDEF_NODEXFACTIVATIONFUNC_FUN_HEAD(N) 	DEF_NODEXFACTIVATIONFUNC_FUN_H(fpHCode,N);

	//输出
	#define HOUT(S)	  								OUT_FILE(fpHCode,S);
	#define HOUT_LINE(S)                            HOUT(S);HLN_OPT;

//CPP文件摸版
	//CPP头模版
	#define CPPTITLE    strCppIncludeFile = "#include ";\
						strCppIncludeFile += "\"";\
						strCppIncludeFile += strHFileName;\
						strCppIncludeFile += "\"";\
						fprintf( fpCppCode, "\/\/%s\r\n", strCppFileName.c_str() );\
						LINEMARK(fpCppCode);\
						fprintf( fpCppCode, "%s\r\n", strCppIncludeFile.c_str() );\
						LINEMARK(fpCppCode);

	#define CPPEND      LINEMARK(fpCppCode);

	#define CPPCLASSHEAD	CLASSHEAD(fpCppCode);
	#define CPPCLASSEND		CLASSEND(fpCppCode);

	//函数实现
	#define CPP_DEF_INIT_FUN_CODE					    DEF_INIT_FUN_CODE(fpCppCode);
	#define CPP_DEF_FREE_FUN_CODE         				DEF_FREE_FUN_CODE(fpCppCode);
	#define CPP_DEF_DEFFACTIVATIONFUNC_FUN_CODE(S)   	DEF_DEFFACTIVATIONFUNC_FUN_CODE(fpCppCode,S);
	#define CPP_DEF_NODEXFACTIVATIONFUNC_FUN_CODE(N,S) 	DEF_NODEXFACTIVATIONFUNC_FUN_CODE(fpCppCode,N,S);
	#define CPP_DEF_UPDATA_FUN_CODE               		DEF_UPDATA_FUN_CODE(fpCppCode);
	#define CPP_DEF_CHECKFIND_FUN_CODE                  DEF_CHECKFIND_CODE(fpCppCode);
	#define CPP_DEF_INSERTLEVEL_FUN_CODE				DEF_INSERTLEVEL_FUN_CODE(fpCppCode);
	#define CPP_DEF_PUTWEIGHT_CODE                    	DEF_PUTWEIGHT_CODE(fpCppCode);
	#define CPP_DEF_RUN_CODE_TITLE                      DEF_RUN_CODE(fpCppCode);
	#define CPP_DEF_CREATENEURALNET_FUN_CODE_TITLE    	DEF_CREATENEURALNET_FUN_CODE(fpCppCode);	
	//换行与制表
	#define CPP_LN_OPT			LN_OPT(fpCppCode);
	#define CPP_TAB_OPT			TAB_OPT(fpCppCode);
	#define CPP_LINEMARK		LINEMARK(fpCppCode);LN_OPT(fpCppCode);
	//符号
	#define CPP_BLPAREM_OPT		BLPAREM_OPT(fpCppCode);
	#define CPP_BRPAREM_OPT		BRPAREM_OPT(fpCppCode);
	//输入到文件
	#define CPP_OUT(S)					OUT_FILE(fpCppCode,S);
	#define CPP_OUT_LINE(S)     		OUT_FILE_LINE(fpCppCode,S);
	#define CPP_OUT_FORMAT(M,S)         OUT_FORMAT(fpCppCode, M, S);
	#define CPP_OUT_FORMAT_LINE(M,S)	OUT_FORMAT_LINE(fpCppCode, M, S );

//---------------------------------------------------------------------------
#endif
