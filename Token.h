#define _CRT_SECURE_NO_WARNINGS
#define MAXKEY 1000
/*所用库*/
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>
#include<setjmp.h>
/*主要变量*/
extern jmpret;
extern jmp_buf envbuf;
extern int ident;
extern int fail;
extern int end;
extern jmp_buf envbuf;
extern int JmpRet;
extern int Row;

typedef struct hashTable {
	int token;                    //单词
	struct hashTable *next;      //哈希链表
	char *word;                 //存字符串
	int count;
}hashNode_t,*phashNode_t;

typedef struct WordList {
	struct WordList *next;                    //词链表
	struct hashTable *phashNode;              //指哈希节点
}WordList_t,*pWordList_t;



void Findhash(phashNode_t *hashNode, phashNode_t node);
void ColorOutput(pWordList_t phead); //颜色输出接口
void hashInsert(phashNode_t *hashNode, phashNode_t node);
int hash(char *key);      //hash函数，计算求余值
void WordTailInsert(pWordList_t *pphead, PWORD *pptail, phashNode_t pInsert);
void alp2word(char *str, int *pos, phashNode_t A);
int count(pWordList_t phead);
void print(pWordList_t *pCur);

void Next(pWordList_t *pCur);
void PR(pWordList_t *pCur);
void UN(pWordList_t *pCur);
void MU(pWordList_t *pCur);
void AD(pWordList_t *pCur);
void RE(pWordList_t *pCur);
void EQ(pWordList_t *pCur);
void A(pWordList_t *pCur);
void E(pWordList_t *pCur);
void print(pWordList_t phead);


enum Token
{
	/* 运算符及分隔符 */                    
	TK_PLUS=1, // + 加号1
	TK_MINUS, // - 减号2
	TK_STAR, // * 星号3
	TK_DIVIDE, // / 除号4
	TK_MOD, // % 求余运算符5
	TK_EQ, // == 等于号6
	TK_NEQ, // != 不等于号7
	TK_LT, // < 小于号8
	TK_LEQ, // <= 小于等于号9
	TK_GT, // > 大于号10
	TK_DE, //-=
	TK_GEQ, // >= 大于等于号11
	TK_ASSIGN, // = 赋值运算符12
	TK_POINTSTO, // -> 指向结构体成员运算符13
	TK_DOT, // . 结构体成员运算符14
	TK_AND, // & 地址与运算符15
	TK_OPENPA, // ( 左圆括号16
	TK_CLOSEPA, // ) 右圆括号17
	TK_OPENBR, // [ 左中括号18
	TK_CLOSEBR, // ] 右圆括号19
	TK_BEGIN, // { 左大括号20
	TK_END, // } 右大括号21
	TK_SEMICOLON, // ; 分号 22
	TK_COMMA, // , 逗号23
	TK_ELLIPSIS, // ... 省略号24
	TK_EOF, // 文件结束符25
	TK_AAND, //自增26
	TK_OR, //自增27
	TK_NO,//自增28
	TK_ADD,//自增29
	TK_REDUCE,//自增30
	TK_jing,  //#
	TK_MAOHAO,// "
	 /* 常量 */
	 TK_CINT, // 整型常量31
	 TK_CCHAR, // 字符常量32
	 TK_CSTR, // 字符串常量33
	 TK_FLOAT,// 字符串常量34
	/* 关键字 */
	KW_CHAR, // char关键字35
	KW_SHORT, // short关键字36
	KW_INT, // int关键字37
	KW_VOID, // void关键字 38
	KW_STRUCT, // struct关键字 39
	KW_IF, // if关键字40
	KW_ELSE, // else关键字41
	KW_FOR, // for关键字42
	KW_CONTINUE, // continue关键字43
	KW_BREAK, // break关键字 44
	KW_RETURN, // return关键字45
	KW_SIZEOF, // sizeof关键字46
	KW_ALIGN, // __align关键字47
	KW_CDECL, // __cdecl关键字 standard c call48
	KW_STDCALL, // __stdcall关键字 pascal c call49
	KW_main,
	/* 标识符 */
	TK_IDENT, //函数50
};



enum Error_type {
	PROGRAM_BEGIN,		//执行语法分析
	SUCC,			//成功
	SOMETHINGWRONG,	//未知错误
	LACK_SEMICOLON,	//缺少分号
	RETURN_LACK_SEMICOLON,	//return缺少分号
	BREAK_LACK_SEMICOLON,	//break缺少分号
	CONTINUE_LACK_SEMICOLON,	//continue缺少分号
	EXTER_DEC,		//外部声明处出现错误
	LACK_TYPE,		//缺少类型
	ARR_WRONG,		//数组声明错误
	LACK_IDENT,		//缺少标识符
	LACK_OPENPA,		//缺少左圆括号
	LACK_CLOSEPA,		//缺少右圆括号
	LACK_OPENBR,		//缺少左中括号
	LACK_CLOSEBR,		//缺少右中括号
	LACK_BEGIN,		//缺少左花括号
	LACK_END,			//缺少右花括号
	NESTED_FUNC_DECLEAR,//函数嵌套声明
	IF_LACK_OPENPA,	//if缺少左圆括号
	IF_LACK_CLOSEPA,	//if缺少右圆括号
	FOR_LACK_OPENPA,	//for缺少左圆括号
	FOR_LACK_CLOSEPA,	//for缺少右圆括号
	LACK_PRIMARY		//缺少初等表达式
};