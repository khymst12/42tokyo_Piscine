//ヘッダーファイルが複数回includeされるのを防ぐ
#ifndef RUSH02_H
#define RUSH02_H

//必要なライブラリをinclude
#include <unistd.h> //write, close, read
#include <stdlib.h> //malloc, free
#include <fcntl.h> //openおよびファイルの操作モード（O_RDONLYなど）

//定義したい変数
#define DICT_SIZE 4096 // linuxでは1ページ4096バイトが一般的

//作成した関数を宣言
char    *load_dict(char *dict_path);

#endif