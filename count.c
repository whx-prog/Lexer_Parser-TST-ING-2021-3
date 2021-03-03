#include"Token.h"
int count(pWordList_t phead) {
	pWordList_t pCur = NULL;
	pCur = phead;
	int count = 0;
	while (pCur!=NULL) {
		if (pCur->phashNode->token >= KW_CHAR&& pCur->phashNode->token <= TK_IDENT) {
			count++;
			printf("%s ", pCur->phashNode->word);
		}
		pCur = pCur->next;
	}
	return count;
}
