# Lexer-Parser
语法分析表达式生成树
将输入字符流进行词法分析后得到Token流,并对不同类型的词进行染色
对Token流进行语法判断
已包含的表达式终结符包括:+ - * / % () [] == != < > <= >= sizeof()

DFA：![image](https://github.com/whx-prog/Lexer_Parser-TST-ING-2021-3/blob/main/DFA.png)



词法分析效果图：


![image](https://github.com/whx-prog/Lexer_Parser-TST-ING-2021-3/blob/main/Lexer.png)


语法分析文法： 
              E->A{,A}/n
              A->B{|=B|^=B|&=B|>>=B|<<=B|-=B|+=B|%=B|*=B|/=B|=B}/n
              B->C{!=C|==C}
              C->E{>E|>=E|<E|<=E}
              E->F{<<F|>>F}
              F->G{+G|-G}
              G->H{*H|/H|%H}
              H->SIZEOFI|~I|!I|&I|*I|--I|++I|+I|-I
              I->[E]|(E)|.标识符|->标识符


语法分析效果图：
![image](https://github.com/whx-prog/Lexer_Parser-TST-ING-2021-3/blob/main/Parser_picture/%E5%9B%BE%E7%89%871.png)
![image](https://github.com/whx-prog/Lexer_Parser-TST-ING-2021-3/blob/main/Parser_picture/%E5%9B%BE%E7%89%872.png)
![image](https://github.com/whx-prog/Lexer_Parser-TST-ING-2021-3/blob/main/Parser_picture/%E5%9B%BE%E7%89%873.png)
![image](https://github.com/whx-prog/Lexer_Parser-TST-ING-2021-3/blob/main/Parser_picture/%E5%9B%BE%E7%89%874.png)
![image](https://github.com/whx-prog/Lexer_Parser-TST-ING-2021-3/blob/main/Parser_picture/%E5%9B%BE%E7%89%875.png)


语法分析测试样例:

正确表达式：
[(1+2)],1!=((1-sizeof(1*1))/8-6%2)<=(2+3)*4+(&2!=1),1==12*4,1>=3*4,sizeof(sizeof(6+2)*6)!=2

[(1+2)],1!=((1-sizeof(1*1))/8-6%2)<=(2+3)*4+(&2!=1),1==12*4,1>=3*4

[(1+2)],1!=((1-sizeof(1*1))/8-6%2)<=(2+3)*4+(&2!=1),1==12*4,1>=3*4，1+2+3+4+5+6+7+8*（12%2）==3

[sizeof(1+2)],1!=((1-sizeof(1*1))/8-6%2)<=(2+3)*4+sizeof(&2!=1),1==12*4,1>=3*4，1+2+3+4+5+6+7+8*sizeof（12%2）==3

错误表达式：
(((([(1+2)],1!=((1-sizeof(1*1))/8-6%2)<=(2+3)*4+(&2!=1),1==12*4,1>=3*4,sizeof(sizeof(6+2)*6)!=2  

-=[(1+2)],1!=((1-sizeof(1*1))/8-6%2)<=(2+3)*4+(&2!=1),1==12*4,1>=3*4

sizeof1[(1+2)],1!=((1-sizeof(1*1))/8-6%2)<=(2+3)*4+sizeof(&2!=1),1==12*4,1>=3*4，1+2+3+4+5+6+7+8*sizeof（12%2）

=-=-=[((1+2))],1!=((1-sizeof(1*1))/8-6%2)<=(2/3)*4+sizeof(&2!=1),1==12*4,1>=3*4，1+2+3+4+5+6+7+8*sizeof（12%2）
/*
