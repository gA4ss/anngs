//---------------------------------------------------------------------------

#pragma hdrstop

#include "HashTbl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//数据
SHashTreeNode NodeList[HASH_PRIME];
int nErr;		//哈希树错误代码
int nNumber; 	//数量


void insertNode( SHashTreeNode **, const char *, SNeurol );
SHashTreeNode *findNode( SHashTreeNode *, const char * );
SHashTreeNode *queryHashNode( const char * );
int hash( const char * );
void deleteAllNodes( SHashTreeNode ** );
string makeMacroDefine( const char * );
void showNodeCode( SHashTreeNode *, vector<string>& );
void showNodeName( SHashTreeNode *, vector<string>& );
void showAllNodes( SHashTreeNode * );

void deleteAllNodes( SHashTreeNode ** __pLink ){
	if( *__pLink != NULL){
		if( ((*(*__pLink)).left)!=NULL ){
			deleteAllNodes( &((*(*__pLink)).left) );
		}/* end if */
		if( ((*(*__pLink)).right)!=NULL ){
			deleteAllNodes( &((*(*__pLink)).right) );
		}/* end if */
		delete *__pLink;
		*__pLink = NULL;
	}/* end link */
	return;
}/* end deleteAllNodes */

int hash( const char *__szNode ){

	unsigned char * p;
	unsigned h = 0, g;
	char szNode_[HASHNODENAME]={0};
	strcpy( szNode_, __szNode );
	for (p = (unsigned char * )szNode_; *p != '\0'; p = p + 1){
		h = (h << 4) + (*p);
		if (g = (h & 0xf0000000))
		{
			h = h ^ (g >> 24);
			h = h ^ g;
		}/* end if */
	}/* end for */
	return h % HASH_PRIME;
}/* end hash */

int getNodeIndex( const char *__szNode ){
	SHashTreeNode* pNode_ = queryHashNode(__szNode );
	if(pNode_ != NULL)
		return pNode_->nIndex;
	else return -1;		
}/* end getNodeIndex */

int addNodeToTree( const char *__szNode, SNeurol __value )
{
	int hash_value = hash( __szNode );
	nErr = 0;
	//如果节点为空
	if(NodeList[hash_value].bEmpty == true){
		strcpy( NodeList[hash_value].szNodeName, __szNode );
		NodeList[hash_value].bEmpty = false;
		NodeList[hash_value].value = __value;
		NodeList[hash_value].value.code = makeMacroDefine( __szNode );
        NodeList[hash_value].nIndex = nNumber;
		nNumber++;
	}/* end if */
	//如果相等
	else if( strcmp( __szNode, NodeList[hash_value].szNodeName )==0 ){
		nErr = ERR_SAMENODENAME;
	}/* end  if */
	//如果不为空,则比较
	else if( strcmp( __szNode, NodeList[hash_value].szNodeName )>0 ){
		insertNode( &(NodeList[hash_value].right), __szNode, __value );
	}/* end else if */
	else{
		insertNode( &(NodeList[hash_value].left), __szNode, __value );
	}/* end else */
	return nErr;
}/* end addNodeToTree */


void insertNode( SHashTreeNode **__pLink, const char *__szNode, SNeurol __value ){
	if(*__pLink==NULL){
		*__pLink = new SHashTreeNode;
		(*(*__pLink)).bEmpty = false;
		(*(*__pLink)).value = __value;
		(*(*__pLink)).value.code = makeMacroDefine( __szNode );
        (*(*__pLink)).nIndex = nNumber;
		memset( ((*(*__pLink)).szNodeName), 0, HASHNODENAME);
		strcpy( ((*(*__pLink)).szNodeName), __szNode );
		(*(*__pLink)).left = NULL;
		(*(*__pLink)).right = NULL;
		nNumber++;
		return;
	}/* end if */
	//如果相等
	else if( strcmp( __szNode, ((*(*__pLink)).szNodeName) )==0 ){
		nErr = ERR_SAMENODENAME;
	}/* end if */
	else if( strcmp( __szNode, ((*(*__pLink)).szNodeName) )>0 ){
		insertNode( &((*(*__pLink)).right), __szNode, __value );
	}/* end if */
	else{
		insertNode( &((*(*__pLink)).left), __szNode, __value );
	}/* end else */	
	return;
}/* end insertNode */


SHashTreeNode *queryHashNode( const char *__szNode )
{
	int hash_value = hash( __szNode );
	//如果为空
	if( NodeList[hash_value].bEmpty ){
		nErr = ERR_NOTFOUNDNODE;
		return NULL;
	}/* end if */
	else{
		if( strcmp( (NodeList[hash_value].szNodeName), __szNode ) == 0 ){
			nErr = 0;
			return &NodeList[hash_value];
		}/* end if */
		if( strcmp( __szNode, (NodeList[hash_value].szNodeName) ) > 0 ){
			return findNode( NodeList[hash_value].right, __szNode );
		}/* end if */
		else{
			return findNode( NodeList[hash_value].left, __szNode );
		}/* end else */
	}/* end else */
}/* end queryHashNode */


SHashTreeNode *findNode( SHashTreeNode *__pLink, const char *__szNode )
{
	nErr = 0;
	if(__pLink==NULL){
		nErr = ERR_NOTFOUNDNODE;
		return NULL;
	}/* end if */
	else if( strcmp( __szNode, ((*__pLink).szNodeName) ) == 0 ){
		return __pLink;
	}/* end else if */
	else if( strcmp( __szNode, ((*__pLink).szNodeName) ) > 0 ){
		return findNode( (*__pLink).right, __szNode );
	}/* end else if */
	else{
		return findNode( (*__pLink).left, __szNode );
	}/* end else */
}/* end findNode */

int setValue( const char *__szNode, SNeurol __value ){
	SHashTreeNode *pLink_ = queryHashNode( __szNode );
	if(pLink_!=NULL)
		(*pLink_).value = __value;
	return nErr;
}/* end setValue */


SNeurol getValue( const char *__szNode ){
	SHashTreeNode *pLink_ = queryHashNode( __szNode );
	if(pLink_!=NULL)
		return (*pLink_).value;
}/* end getValue */


bool ifFoundOnHashTbl( const char *__szNode ){
	SHashTreeNode *pLink_ = queryHashNode( __szNode );
	if(pLink_==NULL)
		return false;
	else
		return true;
}/* end ifFoundOnHashTbl */


int GetCurrentError(){
	return nErr;
}/* end GetCurrentError */


int getNodeNum(){
	return nNumber;
}/* end getNodeNum */

void CreateHashTbl(){
	nErr = 0;
	nNumber = 0;
	for( int i=0; i<HASH_PRIME; i++ ){
		NodeList[i].bEmpty = true;
		memset( NodeList[i].szNodeName, 0, HASHNODENAME );
		NodeList[i].left = NULL;
		NodeList[i].right = NULL;
	}/* end for */
}/* end CreateHashTbl */

void FreeHashTbl(){
	for( int i=0; i<HASH_PRIME; i++ ){
		deleteAllNodes( &(NodeList[i].left) );
		deleteAllNodes( &(NodeList[i].right) );
		NodeList[i].bEmpty = true;
		NodeList[i].left = NULL;
		NodeList[i].right = NULL;
	}/* end for */
	return;
}/* end ~CHashTbl */

string makeMacroDefine( const char *__szNode ){
	char szCode_[256] = {0};
	sprintf( szCode_, "#define %s\t\t%d", (__szNode+1), nNumber );
	string strCode_;
	strCode_ = szCode_;
	return strCode_;
}/* end makeMacroDefine */

vector<string> printNodeCode(){
	vector<string> vecDefine_;
	for( int i=0; i<HASH_PRIME; i++ ){
		if( !(NodeList[i].bEmpty) ){
			vecDefine_.push_back( (NodeList[i].value).code );
			if( (NodeList[i].left) != NULL )
				showNodeCode( (NodeList[i].left), vecDefine_ );
			if( (NodeList[i].right) != NULL )
				showNodeCode( (NodeList[i].right), vecDefine_ );
		}/* end if */
	}/* end for */
	return vecDefine_;
}/* end printNodeCode */

void showNodeCode( SHashTreeNode * __pLink, vector<string>& __vecDefine ){
	__vecDefine.push_back( ((*__pLink).value).code );
	if( ((*__pLink).left) != NULL )
		showNodeCode( ((*__pLink).left), __vecDefine );
	if( ((*__pLink).right) != NULL )
		showNodeCode( ((*__pLink).right), __vecDefine );
	return;
}/* end showNodeCode */

void showNodeName( SHashTreeNode * __pLink, vector<string>& __vecName ){
	__vecName.push_back( ((*__pLink).value).strNodeName );
	if( ((*__pLink).left) != NULL )
		showNodeName( ((*__pLink).left), __vecName );
	if( ((*__pLink).right) != NULL )
		showNodeName( ((*__pLink).right), __vecName );
	return;
}/* end shwoNodeName */

vector<string> printNodeName(){
	vector<string> vecName_;
	for( int i=0; i<HASH_PRIME; i++ ){
		if( !(NodeList[i].bEmpty) ){
			vecName_.push_back( (NodeList[i].value).strNodeName );
			if( (NodeList[i].left) != NULL )
				showNodeName( (NodeList[i].left), vecName_ );
			if( (NodeList[i].right) != NULL )
				showNodeName( (NodeList[i].right), vecName_ );
		}/* end if */
	}/* end for */
	return vecName_;
}/* end printNodeName */

vector<string> getNodeInput( const char *__szNode ){
	SHashTreeNode *pLink_ = queryHashNode( __szNode );
	return (pLink_->value).inputs;
}/* end getNodeInput */

vector<string> getNodeOutput( const char *__szNode ){
	SHashTreeNode *pLink_ = queryHashNode( __szNode );
	return (pLink_->value).outputs;
}/* end getNodeOutput */

string getNodeActivationFunc( const char *__szNode ){
	SHashTreeNode *pLink_ = queryHashNode( __szNode );
	return (pLink_->value).activation_function;
}/* end getNodeActivationFunc */

SNeurol getNodeValue( const char *__szNode ){
	SHashTreeNode *pLink_ = queryHashNode( __szNode );
	return pLink_->value;
}/* end getNodeValue */

void printAllNodes(){
	for( int i=0; i<HASH_PRIME; i++ ){
		if( !(NodeList[i].bEmpty) ){
			cout << "Name: " << NodeList[i].szNodeName << endl;
			cout << "weight: " << NodeList[i].value.weight << endl;
			cout << "gate: " << NodeList[i].value.gate << endl;
			//cout << "activation: " << NodeList[i].value.activation << endl;
			cout << "activation_function: " << NodeList[i].value.activation_function << endl;
			//cout << "Code: " << NodeList[i].value.code.c_str() << endl;
			cout << "Total of Input: " << ((NodeList[i].value).inputs).size() << endl;
			cout << "Total of Output: "<< ((NodeList[i].value).outputs).size() << endl;
			cout << "Input List: " << endl;

			for( int i=0; i<((NodeList[i].value).inputs).size(); i++ )
				cout << NodeList[i].value.inputs[i] << endl;
			cout << "Output List: " << endl;

			for( int i=0; i<((NodeList[i].value).outputs).size(); i++ )
				cout << NodeList[i].value.outputs[i] << endl;
			cout << "--------------------------------------------" << endl;
			if( (NodeList[i].left) != NULL )
				showAllNodes( (NodeList[i].left) );
			if( (NodeList[i].right) != NULL )
				showAllNodes( (NodeList[i].right) );
		}/* end if */
	}/* end for */
	return;
}/* end printAllNodes */

void showAllNodes( SHashTreeNode *__pLink ){
	if( __pLink!=NULL ){
		cout << "Name: " << (*__pLink).szNodeName << endl;
		cout << "weight: " << (*__pLink).value.weight << endl;
		cout << "gate: " << (*__pLink).value.gate << endl;
		//cout << "activation: " << (*__pLink).value.activation << endl;
		cout << "activation_function: " << (*__pLink).value.activation_function << endl;
		//cout << "Code: " << (*__pLink).value.code.c_str() << endl;
		cout << "Total of Input: " << (((*__pLink).value).inputs).size() << endl;
		cout << "Total of Output: "<< (((*__pLink).value).outputs).size() << endl;
		cout << "Input List: " << endl;
		for( int i=0; i<(((*__pLink).value).inputs).size(); i++ )
			cout << ((*__pLink).value).inputs[i] << endl;
		cout << "Output List: " << endl;
		for( int i=0; i<(((*__pLink).value).outputs).size(); i++ )
			cout << ((*__pLink).value).outputs[i] << endl;
		cout << "--------------------------------------------" << endl;
		if( ((*__pLink).left) != NULL )
			showAllNodes( ((*__pLink).left) );
		if( ((*__pLink).right) != NULL )
			showAllNodes( ((*__pLink).right) );
	}/* end if */
	return;
}/* end showAllNodes */


