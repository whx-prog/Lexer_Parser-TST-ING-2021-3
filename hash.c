#include"Token.h"
int hash(char *key) {
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % MAXKEY;
}
void hashInsert(phashNode_t *hashNode,phashNode_t node) {
	int hashVal = hash(node->word);
	if (hashNode[hashVal] == NULL) {
		hashNode[hashVal] = node;
		node->next = NULL;
	}
	else if (hashNode[hashVal] != NULL) {
		node->next = hashNode[hashVal];
		hashNode[hashVal] = node;
	}
}
void Findhash(phashNode_t *hashNode, phashNode_t node) {
	int hashVal = hash(node->word);
	if (hashNode[hashVal] == NULL) {
		hashInsert(hashNode, node);
	}
	else if(hashNode[hashVal] != NULL){
		phashNode_t pCur = hashNode[hashVal];
		while (pCur != NULL) {
			if (strcmp(node->word, pCur->word) == 0) {
				node->token = pCur->token; break;
			}
			pCur = pCur->next;
		}
		if (pCur == NULL) {
			hashInsert(hashNode, node);
		}
	}
}
void WordTailInsert(pWordList_t *pphead, PWORD *pptail, phashNode_t pInsert) {
	pWordList_t pNew = (pWordList_t)calloc(1, sizeof(WordList_t));
	pNew->phashNode = pInsert;
	if (*pphead == NULL) {
		*pphead = pNew;
		*pptail = pNew;
	}
	else {
		pWordList_t pCur = *pphead;
		pWordList_t ptail = *pptail;
		while (pCur) {
			pCur = pCur->next;
		}
		if (pCur == NULL) {
			ptail->next = pNew;
			*pptail = pNew;
		}
	}
	pNew->next = NULL;
}