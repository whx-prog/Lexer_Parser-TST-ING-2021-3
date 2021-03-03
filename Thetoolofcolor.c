#include"Token.h"
void fun() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	printf("hahahahah\n");
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("hahahahah\n");
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
	printf("hahahahah\n");
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("hahahahah\n");
}
void ColorOutput(pWordList_t phead) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	pWordList_t pCur = phead;
	while (pCur!=NULL) {
		if (pCur->phashNode->token>= TK_IDENT) {
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//标识符
			printf("%s", pCur->phashNode->word);
		}
		else if (pCur->phashNode->token >= KW_CHAR) {
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);//关键字
			printf("%s", pCur->phashNode->word);
		}
		else if (pCur->phashNode->token >= TK_CINT) {
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED );//常量
			printf("%s", pCur->phashNode->word);
		}
		else {
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); //运算符
			printf("%s", pCur->phashNode->word);
		}
		pCur=pCur->next;
	}
}