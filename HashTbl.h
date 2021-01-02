//---------------------------------------------------------------------------

#ifndef HashTBLH
#define HashTBLH
#include <iostream>
#include <vector>
#include <string>
//相同节点名
#define ERR_SAMENODENAME			-1
//节点没有找到
#define ERR_NOTFOUNDNODE			-2
#define HASHNODENAME	64
#define HASH_PRIME		5
using namespace std;

#include "AnnGsToCpp.h"

typedef struct SHashTreeNode_Types{
	bool bEmpty;
	char szNodeName[HASHNODENAME];
	SNeurol value;
	int nIndex;
	struct SHashTreeNode_Types *left;
	struct SHashTreeNode_Types *right;
}SHashTreeNode;                            

extern void CreateHashTbl();
extern void FreeHashTbl();
extern int addNodeToTree( const char *, SNeurol );
extern int getNodeIndex( const char * );
extern bool ifFoundOnHashTbl( const char * );
extern int setValue( const char *, SNeurol );
extern SNeurol getValue( const char * );
extern int GetCurrentError();
extern int getNodeNum();
extern vector<string> printNodeCode();
extern void printAllNodes();
extern vector<string> getNodeInput( const char * );
extern vector<string> getNodeOutput( const char * );
extern string getNodeActivationFunc( const char * );
extern SNeurol getNodeValue( const char * );
extern vector<string> printNodeName();
//---------------------------------------------------------------------------
#endif

