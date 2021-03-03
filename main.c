#include"Token.h"
jmp_buf envbuf;
int JmpRet = PROGRAM_BEGIN;
int Row = 0;

int main(int argc, char *argv[]) {                       //整型浮点型以及空格，标量不存
	phashNode_t hashTable[MAXKEY] = { 0 };               //文件读入字符默认为标识符。
	hashNode_t InsertNode[] = {
	{TK_PLUS,NULL,"+"},
	{TK_MINUS,NULL,"-"},
	{TK_STAR,NULL,"*"},
	{TK_DIVIDE,NULL,"/"},
	{TK_MOD,NULL,"%"},
	{TK_EQ,NULL,"=="},
	{TK_NEQ,NULL,"!="},
	{TK_LT,NULL,"<"},
	{TK_LEQ,NULL,"<="},
	{TK_GT,NULL,">"},
	{TK_GEQ,NULL,">="},
	{TK_ASSIGN,NULL,"="},
	{TK_POINTSTO,NULL,"->"},
	{TK_DOT,NULL,"."},
	{TK_AND,NULL,"&"},
	{TK_OPENPA,NULL,"("},
	{TK_CLOSEPA,NULL,")"},
	{TK_OPENBR,NULL,"["},
	{TK_CLOSEBR,NULL,"]"},
	{TK_BEGIN,NULL,"{"},
	{TK_END,NULL,"}"},
	{TK_SEMICOLON,NULL,";"},
	{TK_COMMA,NULL,","},
	{TK_ELLIPSIS,NULL,"..."},
	{TK_EOF,NULL,"EOF"},
	{TK_CINT,NULL,"整型常量"},
	{TK_CCHAR,NULL,"字符常量"},
	{TK_CSTR,NULL,"字符串常量"},
	{KW_CHAR,NULL,"char"},
	{KW_SHORT,NULL,"short"},
	{KW_INT,NULL,"int"},
	{KW_VOID,NULL,"void"},
	{KW_STRUCT,NULL,"struct"},
	{KW_IF,NULL,"if"},
	{KW_ELSE,NULL,"else"},
	{KW_FOR,NULL,"for"},
	{KW_CONTINUE,NULL,"continue"},
	{KW_BREAK,NULL,"break"},
	{KW_RETURN,NULL,"return"},
	{KW_SIZEOF,NULL,"sizeof"},
	{KW_ALIGN,NULL,"__align"},
	{KW_CDECL,NULL,"__cdecl"},
	{KW_STDCALL,NULL,"__stdcall"},
	{KW_main,NULL,"main"},
	{TK_jing,NULL,"#"},
	{TK_DE,NULL,"+="},
	{TK_MAOHAO,NULL,"\""},
	};
	for (int i = 0; i < sizeof(InsertNode) / sizeof(hashNode_t); i++) {
		hashInsert(hashTable, &InsertNode[i]);
	}
	/*----------------------------------------------------------------------*/
	pWordList_t pHead = NULL;
	pWordList_t pTail = NULL;
	pWordList_t pCur = NULL;

	char ch;
	int pos = 0;
	char *str = (char *)calloc(100000000, sizeof(char));
	FILE *fp = fopen("test.txt", "r+");
	if (fp == NULL) {
		perror("fopen");
		return -1;
	}
	while ((ch=fgetc(fp)) != EOF) {
		str[pos++] = ch;
	}
	fclose(fp);
	/*-------------------------------------------------------------------------*/
	//printf("%s", str);
	/*撞哈希表，同时将识别出来的元素入链表*/
	pos = 0;
	int i = 0;
//	int begin, end;
	//begin = time(NULL);
	//printf("%d", strlen(str));

	while ((unsigned)pos < (unsigned)strlen(str)) {
		phashNode_t pNew = (phashNode_t)calloc(1, sizeof(hashNode_t));
		alp2word(str, &pos, pNew);
		Findhash(hashTable, pNew);
		WordTailInsert(&pHead, &pTail, pNew);
		//printf("计算中....",i++);       
	}
	//ColorOutput(pHead);
	
	//i = count(pHead);      //计算任意词组的功能
	//end = time(NULL);      //用时计算
	//printf("\n");
	//printf("圣经单词数为：%d", i);
	//printf("\n");
	//printf("所用时间为=%d秒", end-begin);

	//void print();
	
	pCur = pHead;// JmpRet = setjmp(envbuf);
	//if (JmpRet) {
	//	goto AAA;
//	}
/*=------------------------语法分析--------------------------------------*/
	//Next(&pCur);
	E(&pCur);
//AAA:	
	if (fail == 0&& JmpRet==0) printf("正确表达式");
	else if (fail == 1||JmpRet==1) {

		printf("错误表达式");
	}
	printf("\n");
	ColorOutput(pHead);
	printf("\n");
	i = count(pHead);      //计算任意词组的功能
	//print(pHead);
	return 0;
}




