#include"Token.h"

int ident;
int fail = 0;
int end = 0;


void Next(pWordList_t *pCur)
{  int i=0;
	if ((*pCur)->next != NULL) {
		(*pCur) = (*pCur)->next;
		/*if ((*pCur)->phashNode->token) {

		}*/
	}
	//if ((*pCur) == NULL) {
		   //longjmp(envbuf, 1);
//	}
	
	
}

void E(pWordList_t *pCur) {                           
	A(pCur);
	while ((*pCur)->phashNode->token == TK_COMMA)   //使用的是三级指针，对指针无深刻理解请勿修改
	{
		Next(pCur);
		A(pCur);
	}
}

void A(pWordList_t *pCur) {
	EQ(pCur);
	while ((*pCur)->phashNode->token == TK_ASSIGN)
	{
		Next(pCur);
		EQ(pCur);
	}
}

void EQ(pWordList_t *pCur) {
	RE(pCur);
	while ((*pCur)->phashNode->token == TK_EQ || (*pCur)->phashNode->token == TK_NEQ)
	{
		Next(pCur);
		RE(pCur);
	}
}

void RE(pWordList_t *pCur) {
	AD(pCur);
	while ((*pCur)->phashNode->token == TK_ASSIGN || (*pCur)->phashNode->token == TK_GT|| (*pCur)->phashNode->token == TK_LT
		|| (*pCur)->phashNode->token == TK_GEQ|| (*pCur)->phashNode->token == TK_LEQ)
	{

		Next(pCur);
		MU(pCur);
	}
}


// E → T { +T | -T } 
void AD(pWordList_t *pCur)
{
	MU(pCur);
	while ((*pCur)->phashNode->token== TK_PLUS|| (*pCur)->phashNode->token == TK_MINUS)
	{

		Next(pCur);
		MU(pCur);
	}
}

// T → F { *F | /F } 
void MU(pWordList_t *pCur)
{
	UN(pCur);
	while ((*pCur)->phashNode->token == TK_STAR || (*pCur)->phashNode->token == TK_DIVIDE|| (*pCur)->phashNode->token == TK_MOD)
	{
		Next(pCur);
		UN(pCur);
	}
}

void UN(pWordList_t *pCur) {
	if ((*pCur)->phashNode->token == TK_AND) {
		Next(pCur);
		UN(pCur);
	}
	else if ((*pCur)->phashNode->token == TK_STAR) {
		Next(pCur);
		UN(pCur);
	}
	else if ((*pCur)->phashNode->token == TK_MINUS) {
		Next(pCur);
		UN(pCur);
	}
	else if ((*pCur)->phashNode->token == KW_SIZEOF) {
		Next(pCur);
		UN(pCur);
	}
	else {
		PR(pCur);
	}
}


// F → (E) | d
void PR(pWordList_t *pCur)
{
	if ((*pCur)->phashNode->token >= TK_CINT && (*pCur)->phashNode->token <= TK_FLOAT)//整型
	{
		Next(pCur);
	}
	else if ((*pCur)->phashNode->token == TK_OPENPA) //（
	{
		Next(pCur);
		AD(pCur);
		if ((*pCur)->phashNode->token == TK_CLOSEPA)//）
		{
			Next(pCur);
		}
		else
		{
			fail = 1;
		}
	}
	else if ((*pCur)->phashNode->token == TK_OPENBR) //[
	{
		Next(pCur);
		AD(pCur);
		if ((*pCur)->phashNode->token == TK_CLOSEBR)//]
		{
			Next(pCur);
		}
		else
		{
			fail = 1;
		}
	}
	else
	{
		fail = 1;
		//printf("表达式错误");

	}
}


