//ヘッダーファイルが複数回includeされるのを防ぐ
#ifndef RUSH02_H
#define RUSH02_H

//必要なライブラリをinclude
#include <unistd.h> //write, close, read
#include <stdlib.h> //malloc, free
#include <fcntl.h> //openおよびファイルの操作モード（O_RDONLYなど）

//定義したい変数
#define DICT_SIZE 4096 // linuxでは1ページ4096バイトが一般的

//辞書の情報をこの構造体で扱う
typedef struct 
{
	unsigned long long int number;
	const char	*text;
}		dict_entry;

//大きい数値　long long int 以上
typedef struct {
    const char *number;   // 数値を文字列として扱う
    const char *text;     // 対応する名前
} larg_dict_ently;

//作成した関数を宣言
char    *load_dict(char *dict_path);//引数の辞書にアクセスし内容をchar *strで返す
dict_entry    *mach_num(int argc, char *argv[]);//引数の数字と辞書の数字を照合し文字列を→putnbr
larg_dict_ently  *mach_l_num(int argc, char *argv[]);//引数の数字と辞書の数字を照合し文字列を→putnbr
int     ft_strlen(char  *argv);
void	ft_putchar(int nb);//ASCIIで全ての文字出力
long long int	ft_atoi(char *str);//コマンドライン引数をintに変換
void put_err();
void put_dict_err();




static const dict_entry num_dict[] = {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "forty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"},
    {100, "hundred"},
    {1000, "thousand"},
    {1000000, "million"},
    {1000000000, "billion"},
    {1000000000000, "trillion"},
    {1000000000000000, "quadrillion"},
    {1000000000000000000, "quintillion"},
};

static const larg_dict_ently larg_dict[] = {
    {"1000000000000000000000", "sextillion"},
    {"1000000000000000000000000", "septillion"},
    {"1000000000000000000000000000", "octillion"},
    {"1000000000000000000000000000000", "nonillion"},
    {"1000000000000000000000000000000000", "decillion"},
    {"1000000000000000000000000000000000000", "undecillion"}
};
#endif
