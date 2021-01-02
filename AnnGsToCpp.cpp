//---------------------------------------------------------------------------

#pragma hdrstop

#include "AnnGsToCpp.h"
#include "HashTbl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//参数
SAnnGsToCppArgu AnnGsToCppArgu;
//文件指针
FILE *fpCppCode;
FILE *fpHCode;
//文件名
string strCppFileName;
string strHFileName;
string strFileName;

//符号表
vector<string> SymbolTbl;
//输入层
vector<string> InputLayer;
//输出层
vector<string> OutputLayer;

//模版所用数据
//H文件
string strHHeader;
string strHIncludeFile;
string strUsStd;
//CPP文件
string strCppIncludeFile;
//行注释
char szLineMark[]="//---------------------------------------------------------------------------";

extern bool CreateCppCode( const char *, SNeurol* );
extern void initAnnGsToCppArgu( SAnnGsToCppArgu& );

int getInputNumber();
int getOutputNumber();
string makeDefActivationFunc( string );
string makeActivationFunc( SNeurol& );
vector<string> getInputName();
vector<string> getOutputName();
string makeDefineHead(string);


void GenerateCppCode( const char *__szClassName ){
	//获取符号表
	SymbolTbl = printNodeName();
	//获取输入层与输出层
	InputLayer = getInputName();
	OutputLayer = getOutputName();
	//神经元节点宏
	vector<string> vecDefine_;
	//1产生head文件
	HTITLE;
		HOUT_LINE("/* Code By Artificial neural network Generate System */");
		HOUT_LINE("/* If you found some bugs,please mail to <logic.yan@gmail.com> */");
        HLN_OPT;
		//定义类型宏
		HDEFANNTYPEMAC;HLN_OPT;
		HDEFWEIGHTTYPEMAC;HLN_OPT;
		HDEFLEVELTYPEMAC;HLN_OPT;
		HDEFDEFUNITLEVELTYPEMAC;HLN_OPT;
		HLINEMARK;
		//定义神经网络所用宏
		HNEUROLTOTAL(AnnGsToCppArgu.nNumber);HLN_OPT;
		//HNEUROLINPUTS(getInputNumber);HLN_OPT;
		//HNEUROLOUTPUTS(getOutputNumber());HLN_OPT;
		HNEUROLGATE((AnnGsToCppArgu.gate).c_str());HLN_OPT;
		HNEUROLWEIGHT((AnnGsToCppArgu.weight).c_str());HLN_OPT;
		HNEUROLOUT_EXC((AnnGsToCppArgu.excout).c_str());HLN_OPT;
		HNEUROLOUT_INH((AnnGsToCppArgu.inhout).c_str());HLN_OPT;
		HLINEMARK;
		//定义神经元的宏
		vecDefine_ = printNodeCode();
		for( int i=0; i<vecDefine_.size(); i++ ){
			HOUT_LINE( vecDefine_[i].c_str() );
		}/* end for */
		HLINEMARK;
		//定义神经元结构
		HNEUROL_STRC_DEFINE_HEAD;HLN_OPT;
			HTAB_OPT;HNEUROL_STRC_FACT;HLN_OPT;
			HTAB_OPT;HNEUROL_STRC_GATE;HLN_OPT;
			HTAB_OPT;HNEUROL_STRC_WEIGHT;HLN_OPT;
			if(AnnGsToCppArgu.bActivationFunction){
				HTAB_OPT;HNEUROL_STRC_FACFUNC;HLN_OPT;
			}/* end if */
			HTAB_OPT;HNEUROL_STRC_EXC_OUT;HLN_OPT;
			HTAB_OPT;HNEUROL_STRC_INH_OUT;HLN_OPT;
			//HTAB_OPT;HNEUROL_STRC_INSUM;HLN_OPT;
			//HTAB_OPT;HNEUROL_STRC_OUTSUM;HLN_OPT;
			HTAB_OPT;HNEUROL_STRC_INPUTS;HLN_OPT;
			HTAB_OPT;HNEUROL_STRC_OUTPUTS;HLN_OPT;
			//HTAB_OPT;HNEUROL_STRC_VECINPUT;HLN_OPT;
		HNEUROL_STRC_DEFINE_END;HLN_OPT;
		HLINEMARK;
		//定义神经网络类
		HCLASSHEAD;
		HTAB_OPT;HPRIVATE;
				//SNeurol m_root[NEUROL_TOTAL];
		HTAB_OPT;HDEFNEUROLLIST;HLN_OPT;
				//vector<int> m_inputs[NEUROL_INPUTS];
		HTAB_OPT;HDEFNEUROLINPUTS;HLN_OPT;
				//vector<int> m_outputs[NEUROL_OUTPUTS];
		HTAB_OPT;HDEFNEUROLOUTPUTS;HLN_OPT;
				//level_t m_hidelevel;
		HTAB_OPT;HDEFNEUROLHIDELEVEL;HLN_OPT;
		HTAB_OPT;HDEF_INSERTLEVEL_FUN_HEAD;
		HTAB_OPT;HDEF_CREATENEURALNET_FUN_HEAD;
		//HTAB_OPT;HDEF_UPDATA_FUN_HEAD;
		HTAB_OPT;HDEF_CHECKFIND_HEAD;
		HTAB_OPT;HPUBLIC;
		HTAB_OPT;HDEF_INIT_FUN_HEAD;
		HTAB_OPT;HDEF_FREE_FUN_HEAD;
		HTAB_OPT;HDEF_PUTWEIGHT_HEAD;
		HTAB_OPT;HDEF_RUN_HEAD;
		HCLASSEND;
	HEND;
	fclose( fpHCode );
	//2产生cpp source文件
	CPPTITLE;
		//这里添加各个神经细胞自己的激励函数
		//第一个为默认的激励函数
		if(AnnGsToCppArgu.bActivationFunction){
			//CPP_DEF_DEFFACTIVATIONFUNC_FUN_CODE(((AnnGsToCppArgu.strDefActivationFunction).c_str()));
			CPP_DEF_DEFFACTIVATIONFUNC_FUN_CODE(makeDefActivationFunc(AnnGsToCppArgu.strDefActivationFunction).c_str());
			CPP_LINEMARK;
		}/* end if */
		//是否有自己的激励函数
		if( AnnGsToCppArgu.bNodeActivationFunction ){
			//获取自己的激励函数定义
			//历遍符号表
			SNeurol NodeValue_;
			for( int i=0; i<SymbolTbl.size(); i++ ){
				NodeValue_ = getNodeValue( SymbolTbl[i].c_str() );
				if(NodeValue_.bNodeActivationFunc){
					CPP_DEF_NODEXFACTIVATIONFUNC_FUN_CODE( ((NodeValue_.strNodeName).c_str()+1), \
															(makeActivationFunc(NodeValue_).c_str()) );
					CPP_LINEMARK;
				}/* end if */
			}/* end for */
		}/* end if */
		CPP_DEF_INIT_FUN_CODE;
			CPP_LINEMARK;
		CPP_DEF_FREE_FUN_CODE;
			CPP_LINEMARK;
		//CPP_DEF_UPDATA_FUN_CODE;
		//	CPP_LINEMARK;
		CPP_DEF_CHECKFIND_FUN_CODE;
			CPP_LINEMARK;
		CPP_DEF_PUTWEIGHT_CODE;
			CPP_LINEMARK;
		CPP_DEF_INSERTLEVEL_FUN_CODE;
            CPP_LINEMARK;
		CPP_DEF_CREATENEURALNET_FUN_CODE_TITLE;
		CPP_BLPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_OUT_LINE("vector<int> vecTmp_;");
			CPP_TAB_OPT;CPP_OUT_LINE("//Get default value set.");
			CPP_TAB_OPT;CPP_OUT_LINE("for(int i=0; i<NEUROL_TOTAL; i++)");
			CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("m_root[i].gate = GATE;");
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("m_root[i].weight = WEIGHT;");
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("m_root[i].exc_out = OUT_EXC;");
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("m_root[i].inh_out = OUT_INH;");
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("m_root[i].activation = 0;");
			if(AnnGsToCppArgu.bActivationFunction){
				CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("m_root[i].activation_function = ActivationFuncDef;");
			}/* end if */
			//当只有个别几个神经细胞有激励函数的情况
			else if((AnnGsToCppArgu.bActivationFunction==false)&&(AnnGsToCppArgu.bNodeActivationFunction==true)){
				CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("m_root[i].activation_function = NULL;");
			}/* end if */
			CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_OUT_LINE("//Make inputs layer and outputs layer.");
			for( int i=0; i<InputLayer.size(); i++ ){
				CPP_TAB_OPT;CPP_OUT_FORMAT("m_inputs.push_back(%s);\r\n", (InputLayer[i].c_str()+1) );
			}/* end for */
			for( int i=0; i<OutputLayer.size(); i++ ){
				CPP_TAB_OPT;CPP_OUT_FORMAT("m_outputs.push_back(%s);\r\n", (OutputLayer[i].c_str()+1) );
			}/* end for */
			CPP_TAB_OPT;CPP_OUT_LINE("//Init each neurol and link network.");
			SNeurol NeurolValue_;
			for(int i=0;i<SymbolTbl.size();i++){
				NeurolValue_ = getNodeValue( SymbolTbl[i].c_str() );
				if(NeurolValue_.bGate){
					CPP_TAB_OPT;
					CPP_OUT_FORMAT( "m_root[%s].gate =", ((NeurolValue_.strNodeName).c_str()+1) );
					CPP_OUT_FORMAT( "%s;\r\n", (NeurolValue_.gate).c_str() );
				}/* end if */
				if(NeurolValue_.bWeight){
					CPP_TAB_OPT;
					CPP_OUT_FORMAT( "m_root[%s].weight =", ((NeurolValue_.strNodeName).c_str()+1) );
					CPP_OUT_FORMAT( "%s;\r\n", (NeurolValue_.weight).c_str() );
				}/* end if */
				if(NeurolValue_.bExcOut){
					CPP_TAB_OPT;
					CPP_OUT_FORMAT( "m_root[%s].exc_out =", ((NeurolValue_.strNodeName).c_str()+1) );
					CPP_OUT_FORMAT( "%s;\r\n", (NeurolValue_.excout).c_str() );
				}/* end if */
				if(NeurolValue_.bInhOut){
					CPP_TAB_OPT;
					CPP_OUT_FORMAT( "m_root[%s].inh_out =", ((NeurolValue_.strNodeName).c_str()+1) );
					CPP_OUT_FORMAT( "%s;\r\n", (NeurolValue_.inhout).c_str() );
				}/* end if */
				if(NeurolValue_.bNodeActivationFunc){
					CPP_TAB_OPT;
					CPP_OUT_FORMAT( "m_root[%s].activation_function = ActivationFunc", ((NeurolValue_.strNodeName).c_str()+1) );
					CPP_OUT_FORMAT( "%s;\r\n", (SymbolTbl[i].c_str()+1) );
				}/* end if */
				for( int i=0; i<(NeurolValue_.inputs).size(); i++ ){
					CPP_TAB_OPT;
					CPP_OUT_FORMAT( "(m_root[%s].inputs).push_back", ((NeurolValue_.strNodeName).c_str()+1) );
					CPP_OUT_FORMAT( "(%s);\r\n", ((NeurolValue_.inputs[i]).c_str()+1) );
				}/* end for */
				for( int i=0; i<(NeurolValue_.outputs).size(); i++ ){
					CPP_TAB_OPT;
					CPP_OUT_FORMAT( "(m_root[%s].outputs).push_back", ((NeurolValue_.strNodeName).c_str()+1) );
					CPP_OUT_FORMAT( "(%s);\r\n", ((NeurolValue_.outputs[i]).c_str()+1) );
				}/* end for */
			}/* end for */              
			//获取隐藏层
			CPP_TAB_OPT;CPP_OUT_LINE("for(int i=0; i<m_inputs.size(); i++)");
			CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("if(!(m_root[m_inputs[i]].outputs).empty())");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("for(int j=0; j<(m_root[m_inputs[i]].outputs).size(); j++)");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("vecTmp_.push_back((m_root[m_inputs[i]]).outputs[j]);");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_OUT_LINE("InsertLevel(vecTmp_, m_hidelevels);");
		CPP_BRPAREM_OPT;CPP_LN_OPT;
			CPP_LINEMARK;

		//参数 an_t __InputList;
		CPP_DEF_RUN_CODE_TITLE;
		CPP_BLPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_OUT_LINE("double sum_ = 0;");
			CPP_TAB_OPT;CPP_OUT_LINE("double out_ = 0;");
			//CPP_TAB_OPT;CPP_OUT_LINE("int nCount_ = 0;");
            CPP_TAB_OPT;CPP_OUT_LINE("an_t result_;");
			//CPP_TAB_OPT;CPP_OUT_LINE("int nTmp_ = 0;");
			CPP_TAB_OPT;CPP_OUT_LINE("for( int i=0; i<__InputList.size(); i++ )");
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("sum_ += __InputList[i];");
			CPP_TAB_OPT;CPP_OUT_LINE("for( int i=0; i<m_inputs.size(); i++ )");
			CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("m_root[m_inputs[i]].activation = m_root[m_inputs[i]].weight * sum_;");
			if(((AnnGsToCppArgu.bActivationFunction == true)&& \
				(AnnGsToCppArgu.bNodeActivationFunction == true))|| \
				((AnnGsToCppArgu.bActivationFunction == true)&& \
				(AnnGsToCppArgu.bNodeActivationFunction == false)))
			{
				CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT("m_root[m_inputs[i]].activation = ");
				CPP_OUT_LINE("m_root[m_inputs[i]].activation_function(m_root[m_inputs[i]]);");
				CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("if( m_root[m_inputs[i]].activation > m_root[m_inputs[i]].gate)");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("out_ = m_root[m_inputs[i]].exc_out;");
				CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("else out_ = m_root[m_inputs[i]].inh_out;");
				CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("m_root[m_inputs[i]].activation = out_;");
			}/* end if */
			CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
			if((AnnGsToCppArgu.bActivationFunction == false)&& \
				(AnnGsToCppArgu.bNodeActivationFunction == true))
			{
				for( int i=0; i<InputLayer.size(); i++ ){
					NeurolValue_ = getNodeValue( InputLayer[i].c_str() );
					if(NeurolValue_.bNodeActivationFunc){
						CPP_TAB_OPT;
						CPP_OUT_FORMAT("m_root[m_input[%s]].activation = ", ((NeurolValue_.strNodeName).c_str()+1) );
						CPP_OUT_FORMAT("m_root[m_input[%s]].activation_function", ((NeurolValue_.strNodeName).c_str()+1) );
						CPP_OUT_FORMAT("(m_root[m_input[%s]]);\r\n", ((NeurolValue_.strNodeName).c_str()+1) );
					}/* end if */
				}/* end for */
				CPP_TAB_OPT;CPP_OUT_LINE("for( int i=0; i<m_inputs.size(); i++ )");
					CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
						CPP_TAB_OPT;CPP_TAB_OPT;
						CPP_OUT_LINE("if( m_root[m_inputs[i]].activation > m_root[m_inputs[i]].gate)");
						CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
						CPP_OUT_LINE("out_ = m_root[m_inputs[i]].exc_out;");
						CPP_TAB_OPT;CPP_TAB_OPT;
						CPP_OUT_LINE("else out_ = m_root[m_inputs[i]].inh_out;");
						CPP_TAB_OPT;CPP_TAB_OPT;
						CPP_OUT_LINE("m_root[m_inputs[i]].activation = out_;");
					CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
			}/* end if */
			CPP_TAB_OPT;CPP_OUT_LINE("//Do hide layers.");
			CPP_TAB_OPT;CPP_OUT_LINE("sum_ = 0;");
			CPP_TAB_OPT;CPP_OUT_LINE("out_ = 0;");
			CPP_TAB_OPT;CPP_OUT_LINE("for(int i=0; i<m_hidelevels.size(); i++)");
			CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("for(int n=0; n<m_hidelevels[i].size(); n++)");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
					CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("for(int m=0; m<(m_root[m_hidelevels[i][n]].inputs).size(); m++)");
					CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_BLPAREM_OPT;CPP_LN_OPT;
					CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("sum_ += (m_root[m_root[m_hidelevels[i][n]].inputs[m]]).activation;");
					CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
					CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("m_root[m_hidelevels[i][n]].activation = sum_ * m_root[m_hidelevels[i][n]].weight;");
			if(((AnnGsToCppArgu.bActivationFunction == true)&& \
				(AnnGsToCppArgu.bNodeActivationFunction == true))|| \
				((AnnGsToCppArgu.bActivationFunction == true)&& \
				(AnnGsToCppArgu.bNodeActivationFunction == false))|| \
				((AnnGsToCppArgu.bActivationFunction == false)&& \
				(AnnGsToCppArgu.bNodeActivationFunction == true)))
			{
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("if(m_root[m_hidelevels[i][n]].activation_function!=NULL)");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("m_root[m_hidelevels[i][n]].activation = m_root[m_hidelevels[i][n]].activation_function(m_root[m_hidelevels[i][n]]);");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("if( m_root[m_hidelevels[i][n]].activation > m_root[m_hidelevels[i][n]].gate)");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("out_ = m_root[m_hidelevels[i][n]].exc_out;");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("else out_ = m_root[m_hidelevels[i][n]].inh_out;");
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_TAB_OPT;
				CPP_OUT_LINE("m_root[m_hidelevels[i][n]].activation = out_;");
			}/* end if */
				CPP_TAB_OPT;CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_BRPAREM_OPT;CPP_LN_OPT;
			CPP_TAB_OPT;CPP_OUT_LINE("for(int i=0; i<m_outputs.size(); i++)");
			CPP_TAB_OPT;CPP_TAB_OPT;CPP_OUT_LINE("result_.push_back(m_root[m_outputs[i]].activation);");
			CPP_TAB_OPT;CPP_OUT_LINE("return result_;");
		CPP_BRPAREM_OPT;CPP_LN_OPT;
			//CPP_LINEMARK;
	CPPEND;
	fclose( fpCppCode );
}/* end GenerateCppCode */

bool CreateCppCode( const char *__szFileName ){
	strFileName = __szFileName;
	strCppFileName = __szFileName;
	strCppFileName += ".cpp";
	strHFileName = __szFileName;
	strHFileName += ".h";

	if( (fpHCode = fopen( strHFileName.c_str() , "wb" ))==NULL )return false;
	if( (fpCppCode = fopen( strCppFileName.c_str() , "wb" ))==NULL )return false;

	//产生代码
	GenerateCppCode( __szFileName );

	return true;
}/* end CreateCppCode */

void initAnnGsToCppArgu( SAnnGsToCppArgu& __A ){
	__A.nNumber = 0;
	//__A.nInput = 0;
	//__A.nOutput = 0;
	__A.bExcOut = false;
	__A.bGate = false;
	__A.bInhOut = false;
	__A.bNodeActivationFunction = false;
	__A.bActivationFunction = false;
	__A.bWeight = false;
	return;
}/* end initAnnGsToCppArgu */

int getInputNumber(){
	int nCount_ = 0;
	SNeurol NodeValue_;
	for(int i=0; i<SymbolTbl.size(); i++){
		NodeValue_ = getNodeValue( SymbolTbl[i].c_str() );
		if(NodeValue_.bInput)nCount_++;
	}/* end for */
	return nCount_;
}/* end getInputNumber */

int getOutputNumber(){
	int nCount_ = 0;
	SNeurol NodeValue_;
	for(int i=0; i<SymbolTbl.size(); i++){
		NodeValue_ = getNodeValue( SymbolTbl[i].c_str() );
		if(NodeValue_.bOutput)nCount_++;
	}/* end for */
	return nCount_;
}/* end getOutputNumber */

string makeDefActivationFunc( string __strSec ){
	string strOut_;
	char szTmp_[64]={0};
	char szNodeName_[32] = {0};
	char in_char;
	for( int i=0; i<__strSec.size(); i++){
		in_char = __strSec[i];
		if(in_char == '@'){
			memset( szTmp_, 0, sizeof(szTmp_) );
			//sprintf( szTmp_, "m_root[%s].", ((__NodeValue.strNodeName).c_str()+1) );
			sprintf( szTmp_, "%s.", "__Neurol"  );
			strOut_ += szTmp_;
		}/* end if */
		else{
			strOut_.push_back( in_char );
		}/* end else */
	}/* end for */
	return strOut_;
}/* end makeDefActivationFunc */

string makeActivationFunc( SNeurol& __NodeValue ){
	string strOut_;
	char szTmp_[64]={0};
	char szNodeName_[32] = {0};
	string strActivationFunc = __NodeValue.activation_function;
	char in_char;
	for( int i=0; i<strActivationFunc.size(); i++){
		in_char = strActivationFunc[i];
		if(in_char == '@'){
			memset( szTmp_, 0, sizeof(szTmp_) );
			//sprintf( szTmp_, "m_root[%s].", ((__NodeValue.strNodeName).c_str()+1) );
			sprintf( szTmp_, "%s.", "__Neurol"  );
			strOut_ += szTmp_;
		}/* end if */
		else{
			strOut_.push_back( in_char );
		}/* end else */
	}/* end for */
	return strOut_;
}/* end make ActivationFunc */

vector<string> getInputName(){
	vector<string> vecOut_;
	SNeurol NodeValue_;
	for(int i=0; i<SymbolTbl.size(); i++){
		NodeValue_ = getNodeValue( SymbolTbl[i].c_str() );
		if(NodeValue_.bInput)
			vecOut_.push_back( NodeValue_.strNodeName );
	}/* end for */
	return vecOut_;
}/* end getInputName */

vector<string> getOutputName(){
	vector<string> vecOut_;
	SNeurol NodeValue_;
	for(int i=0; i<SymbolTbl.size(); i++){
		NodeValue_ = getNodeValue( SymbolTbl[i].c_str() );
		if(NodeValue_.bOutput)
			vecOut_.push_back( NodeValue_.strNodeName );
	}/* end for */
	return vecOut_;
}/* end getOutputName */

string makeDefineHead(string __strHead){
	string strOut_;
	for(int i=0; i<__strHead.size(); i++){
		if((__strHead[i]>='a')&&(__strHead[i]<='z'))
			strOut_.push_back( __strHead[i]-32 );
	}/* end for */
	strOut_ += "_H";
	return strOut_;
}/* end makeDefineHead */



