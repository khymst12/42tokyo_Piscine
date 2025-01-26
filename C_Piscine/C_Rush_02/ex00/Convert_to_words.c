#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1 * sign;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + (str[i++] - '0');
	return (sign * value);
}

size_t ft_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


// 数値を英語表記に変換する関数
void convert_to_words(const char *num, const char *value[])
{
    size_t num_len = ft_strlen(num); // 数字の桁数
    size_t group_count = (num_len + 2) / 3; // 3桁ごとに分割
    size_t remainder = num_len % 3; // 最初のグループの桁数
    char group[4]; // 3桁グループを保存
    size_t index = 0;
    int first_word = 1; // 最初の単語かどうかを判定
    size_t i;

    if (remainder == 0) 
        remainder = 3;
    i = 0;
    if (num[0] == '0' && num_len == 1) //0のみ例外処理
    {
        write(1, value[0], 4);
        write(1, "\n", 1);
        return ;
    }
    while (i < group_count) 
    {
        // グループを取得
        size_t group_size;
        if (i == 0)
            group_size = remainder;
        else
            group_size = 3;
        ft_strncpy(group, &num[index], group_size);
        group[group_size] = '\0'; // null終端
        index += group_size;

        // グループの数値を整数に変換
        int group_value = ft_atoi(group);
        if (group_value != 0) // 0はスキップ
        {
            // スペースを最初の単語以外に追加
            if (!first_word)
                write(1, " ", 1);
            first_word = 0;

            // 100の位
            if (group_size == 3 && group[0] != '0')
            {
                int hundreds = group[0] - '0';
                write(1, value[hundreds], ft_strlen(value[hundreds]));
                write(1, " ", 1);
                write(1, value[28], 8);
                group_value %= 100; // 上位の2桁にする
                if (group_value > 0)
                    write(1, " ", 1);
            }

            // 10の位と1の位
            int tens_and_ones = group_value % 100;
            if (tens_and_ones >= 20)
            {
                int tens = (tens_and_ones / 10) * 10; // 20, 30, ..., 90
                write(1, value[tens / 10 + 18], ft_strlen(value[tens / 10 + 18]));
                if (tens_and_ones % 10 != 0)
                {
                    write(1, "-", 1);
                    write(1, value[tens_and_ones % 10], ft_strlen(value[tens_and_ones % 10])); // 1～9
                }
            }
            else if (tens_and_ones > 0)
            {
                write(1, value[tens_and_ones], ft_strlen(value[tens_and_ones])); // 1～19
            }

            // 単位の追加 (thousand, million, ...)
            int unit_index = group_count - i - 1;
            if (unit_index > 0 && unit_index + 28 < 40) // 単位の範囲を確認
            {
                write(1, " ", 1);
                write(1, value[28 + unit_index], ft_strlen(value[28 + unit_index])); // 単位のインデックス
            }
        }
        i++;
    }

    // 最後に改行を追加
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "ERROR\n", 6);
        return 1;
    }

    // value配列の定義
    const char *value[] =
    {
        "zero", "one", "two", "three", "four", "five", "six", "seven", 
        "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", 
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", 
        "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", 
        "hundred", "thousand", "million", "billion", "trillion", "quadrillion", 
        "quintillion", "sextillion", "septillion", "octillion", "nonillion", 
        "decillion", "undecillion"
    };

    // 入力された数字を英語に変換
    convert_to_words(argv[1], value);

    return 0;
}

