#include"Token.h"
void alp2word(char *str, int *pos, phashNode_t pNew) {
	char ch = str[*pos];
	char prech;
	char *word = (char *)calloc(200, 1);
	int wordPos = 0;
	pNew->word = word;
	pNew->token = TK_IDENT;
    if (ch == ' ' || ch == '\n') {  //跳过
	word[wordPos] = ch;
	pNew->token = -1;
	++*pos;
	return;
	}
	else if (ch == '(' || ch == ')') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == '[' || ch == ']') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == '{' || ch == '}') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == '.') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == '#') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == ',') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == '&') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == ':') {
		word[wordPos] = ch;
		++*pos;
		return;
	}
	else if (ch == ';') {
		word[wordPos] = ch;
		pNew->token = -1;
		++*pos;
		return;
	}
	else if (ch == '\t') {
		word[wordPos] = ch;
		pNew->token = -1;
		++*pos;
		return;
	}
	else if (ch == '\f') {
		word[wordPos] = ch;
		pNew->token = -1;
		++*pos;
		return;
	}
	else if (ch == '\b') {
		word[wordPos] = ch;
		pNew->token = -1;
		++*pos;
		return;
	}
	else if (ch == '\r') {
		word[wordPos] = ch;
		pNew->token = -1;
		++*pos;
		return;
	}
	else if (ch == '\v') {
		word[wordPos] = ch;
		pNew->token = -1;
		++*pos;
		return;
	}
	else if (ch == '?') {
		word[wordPos] = ch;
		pNew->token = -1;
		++*pos;
		return;
	}
	else if (ch == '\'') {
		int count = 3;
		word[wordPos++] = ch;
		ch=str[++*pos];
		while (ch != '\''&&count!=0) {
			word[wordPos++] = ch;
			ch=str[++*pos];
			count--;
		}
		if (count == 0) {
			*pos -= 3;
			wordPos -= 3;
			word[wordPos] = '\0';
			pNew->token = TK_DANG_YINGHAO;
			return;
		}
		word[wordPos] = ch;
		++*pos;
		pNew->token = TK_CCHAR;
		return;
	}
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '=' || ch == '>' || ch == '!'||ch=='%') {
		word[wordPos++] = ch;
		prech = ch;
		ch = str[++*pos];
		if (ch == '>'&&prech == '-') {
			word[wordPos] = ch;
			++*pos;
			return;
		}
		if (ch == '=') {
			word[wordPos] = ch;
			++*pos;
			return;
		}

		return;
	}
	else if (ch == '_' || ch >= 'a' && ch <= 'z' || ch >= 'A'&&ch <= 'Z') { //标识符
		word[wordPos++] = ch;
		ch = str[++*pos];
		while (ch == '_' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' || ch >= 'A' && ch <= 'Z') {
			word[wordPos++] = ch;
			ch = str[++*pos];
		}
		return;
	}
	else if (ch >= '0' && ch <= '9') {
		word[wordPos++] = ch;
		ch = str[++*pos];
		while (ch >= '0' && ch <= '9') {
			word[wordPos++] = ch;
			ch = str[++*pos];
		}
		if (ch != '.') {           //数值整型
			pNew->token = TK_CINT;
			return;
		}
		word[wordPos++] = ch;
		ch = str[++*pos];
		while (ch >= '0' && ch <= '9') {
			word[wordPos++] = ch;
			ch = str[++*pos];
		}
		pNew->token = TK_FLOAT;     //浮点型
		return;
	}
	else if (ch = '"') {   //字符串
	//int count = 0;
	word[wordPos++] = ch;
	ch = str[++*pos];
	while (ch != '"') {
		word[wordPos++] = ch;
		ch = str[++*pos];
	}
	word[wordPos++] = ch;
	++*pos;
	pNew->token = TK_CSTR;
	return;
	}
	
	/*else if (ch = '\''&&ch<='9'&&ch>='0') {   //字符串
	//int count = 0;
	word[wordPos++] = ch;
	ch = str[++*pos];
	while (ch != '\'') {
		word[wordPos++] = ch;
		ch = str[++*pos];
	}
	word[wordPos++] = ch;
	++*pos;
	pNew->token = TK_CSTR;
	return;
	}*/
	else {  
		word[wordPos] = ' ';  //还未识别的换成空格
		pNew->token = -1;
		++*pos;
		return;
	}
}