//---------------------------------------------------------------------------

#pragma hdrstop

#include "Public.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

string CharArrayToString( char *__pChar ){
	int nLen_ = strlen( __pChar );
	string strTmp_;
	for(int i=0; i<nLen_; i++)
		strTmp_.push_back( __pChar[i] );
	return strTmp_;
}/* end CharArrayToString */
