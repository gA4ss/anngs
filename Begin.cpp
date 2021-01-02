//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
#include "Analyer.h"
#pragma hdrstop
//---------------------------------------------------------------------------

#pragma argsused

#define AUTHOR			"<Author:logic.yan@gmail.com>."
#define WEB				"<Web:http://www.0x07c00.org>."

void usage();
void handleAnnGsScript( char *, char * );

int main(int argc, char* argv[])
{
	if(argc!=3){
		usage();
		return -1;
	}/* end if */
	handleAnnGsScript( argv[1], argv[2] );
	cout << endl;
	cout << "Have Fun... ^_^" << endl;
	system("pause");
	return 0;
}

void usage(){
	cout << "\t\t-=Artificial neural network Generate System=-" << endl;
	cout << "Usage: anngs striptname cppname" << endl;
	cout << AUTHOR << endl;
	//cout << "人工智能玩家内部测试版!" << endl;
	system("pause");
}/* end usage */

void handleAnnGsScript( char *__szScript, char *__szCcode ){
	analyzer( __szScript, __szCcode );
}/* end handleAnnGsScript */
//---------------------------------------------------------------------------
