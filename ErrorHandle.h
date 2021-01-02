//ErrorHandle.h
//行数
//extern int nLineCount;			/* Public.h */
//一行中的数量                      /* Public.h */
//extern int nLineCharCount;
//总工的错误
int nTotalError = 0;
//总共的警告
int nTotalWarning = 0;
//词法错误
#define SCAN_ERROR				-1
#define SCAN_FATAL_ERROR		-2
#define SCAN_WARNING			-3

#define TOKEN_ERROR						"<token error:>"
#define TOKEN_WARNING					"<token warning:>"
#define TOKEN_FATAL_ERROR				"<token fatal error:>"
#define TOKEN_ACTIVATIONFUNC_ERROR		"It's not current activation attribute."
#define TOKEN_WEIGHT_ERROR				"It's not current weight attribute."
#define TOKEN_GATE_ERROR				"It's not current gate attribute."
#define TOKEN_EXCOUT_ERROR				"It's not current exc out attribute."
#define TOKEN_INHOUT_ERROR				"It's not current inh out attribute."
#define TOKEN_ATTRIBUTE_ERROR			"It's not current attribute."
#define TOKEN_CONFIGURE_ERROR			"It's not current configure label."
#define TOKEN_NEUROLANDNEURALNET_ERROR	"It's not current neurol and neuralnet label."
#define TOKEN_FLINK_ERROR               "It's not current flink opt."
#define TOKEN_DBLINK_ERROR              "It's not current blink or dlink opt."
#define TOKEN_INVALID_ERROR				"It's a invalid token."

#define HANDLE_TOKEN_WARNING(S)     	printf("%s%s(line:%d-%d)\r\n", TOKEN_WARNING, S, nLineCount, nLineCharCount);\
										nTotalWarning++;\
										return SCAN_WARNING;

#define HANDLE_TOKEN_ERROR(S)			printf("%s%s(line:%d-%d)\r\n", TOKEN_ERROR, S, nLineCount, nLineCharCount);\
										nTotalError++;\
										return SCAN_ERROR;

#define HANDLE_TOKEN_ERROR2(M,S)    	printf("%s(line:%d-%d)\r\n", TOKEN_ERROR, nLineCount, nLineCharCount);\
										printf(M,S);\
										nTotalError++;\
										return SCAN_ERROR;

#define HANDLE_TOKEN_FATAL_ERROR(S)			printf("%s%s(line:%d-%d)\r\n",TOKEN_FATAL_ERROR,S, nLineCount, nLineCharCount);\
											nTotalError++;\
											HANDEL_ERROR_END;\
											exit(SCAN_FATAL_ERROR);
//语法错误
#define ANALYER_WARNING_BACK		-3
#define ANALYER_ERROR_BACK			-2
#define ANALYER_WARNING				"<analyer warning:>"
#define ANALYER_ERROR				"<analyer error:>"
#define ANALYER_FATAL_ERROR			"<analyer fatal error:>"

#define ANALYER_CLASSNAME_ERROR		"It must be classname."
#define ANALYER_BLPAREM_ERROR		"{"
#define ANALYER_BRPAREM_ERROR		"}"
#define ANALYER_ASSIGNOP_ERROR		"="
#define ANALYER_SEMICOLON_ERROR		";"
#define ANALYER_ATTRIBUTE_ERROR		"It's not current attribute for neurol."
#define ANALYER_ID_ERROR			"It must be neurol token"
#define ANALYER_INVALIDLABEL_ERROR	"invalid label."

#define HANDLE_ANALYER_WARNING(S)				printf("%s%s\r\n", ANALYER_WARNING, S);\
												nTotalWarning++;
#define HANDLE_ANALYER_ERROR(S)					printf("%s%s)\r\n", ANALYER_ERROR, S);\
												nTotalError++;
#define HANDLE_ANALYER_FATAL_ERROR(S)   		printf("%s%s\r\n", ANALYER_FATAL_ERROR, S);\
												nTotalError++;\
												HANDEL_ERROR_END;\
												exit(ANALYER_ERROR_BACK);

#define HANDEL_ERROR_END						printf("total of %d error, %d warning.", nTotalError, nTotalWarning);

