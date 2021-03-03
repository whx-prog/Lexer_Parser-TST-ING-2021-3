#include"Token.h"
void alp2word(char *str, int *pos,phashNode_t pNew) {
	char ch = str[*pos];
	char prech;
	char *word = (char *)calloc(200, 1);
	int wordPos = 0;
	pNew->word = word;
	pNew->token= TK_IDENT;
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '='|| ch == '>'|| ch == '!') {
		word[wordPos++] = ch;
		prech = ch;
		ch = str[++*pos];
	  if (ch == '>'&&prech=='-') {
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
	else if (ch == ' ' || ch == '\n') {
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
	else if (ch == '_' || ch >= 'a' && ch <= 'z') {
		word[wordPos++] = ch;
		ch = str[++*pos];
		while (ch == '_' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9'|| ch >= 'A' && ch <= 'Z') {
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
		if (ch != '.') {
			pNew->token = TK_CINT;
			return;
		}
		word[wordPos++] = ch;
		ch = str[++*pos];
		while (ch >= '0' && ch <= '9') {
			word[wordPos++] = ch;
			ch = str[++*pos];
		}
		pNew->token = TK_CINT;
		return;
	}
	else if (ch == '.') {
		word[wordPos++] = ch;
		++*pos;
		return;
	}
	else if (ch == '"') {
		word[wordPos++] = ch;
		++*pos;
		return;
	}
	else if (ch == '"') {
		word[wordPos++] = ch;
		++*pos;
		pNew->token = TK_POINTSTO;
		return;
	}
	else if (ch == '#') {
		word[wordPos++] = ch;
		++*pos;
		return;
	}
	else if (ch == '_' || ch >= 'A' && ch <= 'Z') {
		word[wordPos++] = ch;
		ch = str[++*pos];
		while (ch == '_' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9'|| ch == '_' || ch >= 'a' && ch <= 'z') {
			word[wordPos++] = ch;
			ch = str[++*pos];
		}
		return;
	}
	else if (ch == ',') {
		word[wordPos++] = ch;
		++*pos;
		return;
	}
	else if (ch == '&') {
		word[wordPos++] = ch;
		++*pos;
		return;
	}
	else if (ch == '%') {
		word[wordPos++] = ch;
		++*pos;
		return;
	}
	else if (ch == ':') {
	word[wordPos++] = ch;
	++*pos;
	return;
	}
	else if (ch == ';') {
	word[wordPos++] = ch;
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
	else {
	word[wordPos] = ' ';
	pNew->token = -1;
	++*pos;
	return;
	}
}