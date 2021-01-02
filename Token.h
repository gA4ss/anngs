//---------------------------------------------------------------------------

#ifndef TokenH
#define TokenH
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ID			0

#define ASSIGNOP    2
#define SEMICOLON	3
#define EXPRESSION	4
#define BLPAREM		5
#define BRPAREM		6
#define ACTIVATION	7
#define ACTIVATIONFUNC	8
#define WEIGHT		9
#define GATE		10
#define CONFIGURE_LAB	11
#define NEUROL_LAB      12
#define NEURALNET_LAB	13
#define CLASS_LAB		14
#define COMMA			15
#define LPAREM	 		16
#define RPAREM			17
#define FLINK			18
#define BLINK			19
#define DLINK			20
#define EXCOUT			21
#define INHOUT			22

bool scaner( char * );
int next_token();
//---------------------------------------------------------------------------
#endif
