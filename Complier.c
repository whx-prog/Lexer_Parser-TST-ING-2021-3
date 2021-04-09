#include"Token.h"

int ident;
int fail = 0;
int end = 0;
int ret = 0;
int match_ret(pWordList_t *pCur, int match_token) {
	if ((*pCur)->phashNode->token ==match_token) {
		Next(pCur);
		return 1;
	}
	else {
		return 0;
	}
}


int match_error(pWordList_t *pCur, int match_token) {
	if ((*pCur)->phashNode->token == match_token) {
		return 0;
	}
	else {
		return 1;
	}
}

void Next(pWordList_t *pCur)
{
	int i = 0;
	if ((*pCur)->next != NULL)
		(*pCur) = (*pCur)->next;
	while (((*pCur)->phashNode->token == OTHER_SPACE || -1 == (*pCur)->phashNode->token) && (*pCur)->next != NULL) {
		(*pCur) = (*pCur)->next;
	}
	/*if ((*pCur)->phashNode->token) {

	}*/

	//if ((*pCur) == NULL) {
		   //longjmp(envbuf, 1);
	//	}
}
	
	


void E(pWordList_t *pCur) {                           
	G(pCur);
	while (match_ret(pCur,TK_COMMA))   
	{
		G(pCur);
	}
}
void G(pWordList_t *pCur) {
	H(pCur);
	while (match_ret(pCur, TK_ASSIGN) || match_ret(pCur, TK_DIV_EQ) || match_ret(pCur, TK_MUL_EQ) || match_ret(pCur, TK_MOD_EQ) || match_ret(pCur, TK_PLU_EQ) || match_ret(pCur, TK_DE) || match_ret(pCur, TK_LEFT_MOVE_EQ) || match_ret(pCur, TK_RIGHT_MOVE_EQ) || match_ret(pCur, TK_AND_BIT_EQ) || match_ret(pCur, TK_AND_OR_BIT_EQ) || match_ret(pCur, TK_OR_BIT_EQ))
	{
		H(pCur);
	}
}

void H(pWordList_t *pCur) {
	I(pCur);
	while (match_ret(pCur, TK_EQ) || match_ret(pCur, TK_NEQ) )
	{
		I(pCur);
	}
}

void I(pWordList_t *pCur) {
	J(pCur);
	while (match_ret(pCur, TK_GEQ) || match_ret(pCur,TK_GT) || match_ret(pCur, TK_LEQ) || match_ret(pCur, TK_LT))
	{
		J(pCur);
	}
}

void J(pWordList_t *pCur) {
	K(pCur);
	while (match_ret(pCur, TK_RIGHT_MOVE) || match_ret(pCur, TK_LEFT_MOVE))
	{
		K(pCur);
	}
}

void K(pWordList_t *pCur) {
	L(pCur);
	while(match_ret(pCur,TK_PLUS)||match_ret(pCur,TK_MINUS))
	{
		L(pCur);
	}
}

void L(pWordList_t *pCur) {
	N(pCur);
	while(match_ret(pCur,TK_STAR)||match_ret(pCur,TK_DIVIDE)||match_ret(pCur,TK_MOD))
	{
		N(pCur);
	}
}
void N(pWordList_t *pCur) {    //�������ȼ����ҽ���ԣ����Բ���Ҫ������ݹ�
_switch:	
	switch ((*pCur)->phashNode->token)
	{
	case TK_MINUS:
		if((*pCur)->next==NULL)
			longjmp(envbuf, ERROR_SINGEL);
		match_ret(pCur, TK_MINUS);
		N(pCur);
		break;
	case TK_PLU_PLU:
		if ((*pCur)->next == NULL)
			longjmp(envbuf, ERROR_SINGEL);
		match_ret(pCur, TK_PLU_PLU);
		N(pCur);
		break;
	case TK_DIV_DIV:
		if ((*pCur)->next == NULL)
			longjmp(envbuf, ERROR_SINGEL);
		match_ret(pCur, TK_DIV_DIV);
		N(pCur);
		break;
	case TK_STAR:
		if ((*pCur)->next == NULL)
			longjmp(envbuf, ERROR_SINGEL);
		match_ret(pCur, TK_STAR);
		N(pCur);
		break;
	case TK_AND:
		if ((*pCur)->next == NULL)
			longjmp(envbuf, ERROR_SINGEL);
		match_ret(pCur, TK_AND);
		N(pCur);
		break;
	case TK_NO:
		if ((*pCur)->next == NULL)
			longjmp(envbuf, ERROR_SINGEL);
		match_ret(pCur, TK_NO);
		N(pCur);
		break;
	case KW_SIZEOF:
		if ((*pCur)->next == NULL)
			longjmp(envbuf, ERROR_SINGEL);
		match_ret(pCur, KW_SIZEOF);
		N(pCur);
		break;
	 default:
		M(pCur);
		if ((*pCur)->phashNode->token == TK_MINUS || (*pCur)->phashNode->token == TK_PLU_PLU || (*pCur)->phashNode->token == TK_DIV_DIV || (*pCur)->phashNode->token == TK_STAR || (*pCur)->phashNode->token == TK_AND || (*pCur)->phashNode->token == TK_NO || (*pCur)->phashNode->token == KW_SIZEOF)
			goto _switch;
	}
}

void M(pWordList_t *pCur)
{
	short button;
	button = match_error(pCur, TK_OPENBR) && match_error(pCur, TK_OPENPA) && match_error(pCur, TK_DOT) && match_error(pCur, TK_POINTSTO) && match_error(pCur, TK_CINT) && match_error(pCur, TK_CCHAR) && match_error(pCur, TK_CSTR) && match_error(pCur, TK_FLOAT ) && match_error(pCur, TK_IDENT);
	if(button)
	{
		longjmp(envbuf, ERROR_FACTORY);
	}
	if((*pCur)->phashNode->token== TK_CINT|| (*pCur)->phashNode->token == TK_CCHAR || (*pCur)->phashNode->token == TK_CSTR || (*pCur)->phashNode->token == TK_FLOAT|| (*pCur)->phashNode->token == TK_IDENT)
	{
		Next(pCur);
			if ((*pCur)->phashNode->token ==TK_IDENT )
				longjmp(envbuf, ERROR_IDENT);
		return;
	}
	else if((*pCur)->phashNode->token == TK_DOT&& (*pCur)->next->phashNode->token== TK_IDENT)
	{
		Next(pCur);
		Next(pCur);
		return;
	}
	else if ((*pCur)->phashNode->token == TK_POINTSTO && (*pCur)->next->phashNode->token == TK_IDENT) 
	{
		Next(pCur);
		Next(pCur);
		return;
	}
	else if (match_ret(pCur, TK_OPENPA))
	{
		E(pCur);
		ret=match_error(pCur, TK_CLOSEPA);
		if (ret == 1)
			longjmp(envbuf, TK_CLOSEPA);
		Next(pCur);
	}
	else if (match_ret(pCur, TK_OPENBR))
	{
		E(pCur);
		ret = match_error(pCur, TK_CLOSEBR);
		if (ret == 1)
			longjmp(envbuf, TK_CLOSEBR);
		Next(pCur);
	}
	else if (match_ret(pCur, TK_DOT)|| match_ret(pCur,TK_POINTSTO))
	{
		E(pCur);
		ret = match_error(pCur,TK_IDENT);
		if (ret == 1)
			longjmp(envbuf, TK_IDENT);
		Next(pCur);
	}
}


