#include <unistd.h>

int	ft_atoi(const char *str)
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




void handle_zero_case(const char *num, size_t num_len, const char *value[])
{
    if (num[0] == '0' && num_len == 1) // 0のみ例外処理
    {
        write(1, value[0], ft_strlen(value[0]));
    }
}

void process_hundreds(int group_value, const char *group, size_t group_size, const char *value[])
{
    if (group_size == 3 && group[0] != '0')
    {
        int hundreds = group[0] - '0';
        write(1, value[hundreds], ft_strlen(value[hundreds]));
        write(1, " ", 1);
        write(1, value[28], ft_strlen(value[28])); // "hundred"
        group_value %= 100; // 上位の2桁にする
        if (group_value > 0)
            write(1, " ", 1);
    }
}

void process_tens_and_ones(int group_value, const char *value[])
{
    int tens_and_ones = group_value % 100;
    if (tens_and_ones >= 20)
    {
        int tens = (tens_and_ones / 10) * 10;
        write(1, value[tens / 10 + 18], ft_strlen(value[tens / 10 + 18]));
        if (tens_and_ones % 10 != 0)
        {
            write(1, "-", 1);
            write(1, value[tens_and_ones % 10], ft_strlen(value[tens_and_ones % 10]));
        }
    }
    else if (tens_and_ones > 0)
    {
        write(1, value[tens_and_ones], ft_strlen(value[tens_and_ones]));
    }
}

void process_unit(size_t group_count, size_t i, const char *value[])
{
    int unit_index = group_count - i - 1;
    if (unit_index > 0 && unit_index + 28 < 40)
    {
        write(1, " ", 1);
        write(1, value[28 + unit_index], ft_strlen(value[28 + unit_index]));
    }
}

void process_group(const char *group, size_t group_size, size_t group_count, size_t i, int *first_word, const char *value[])
{
    int group_value = ft_atoi(group);
    if (group_value != 0)
    {
        if (!*first_word)
            write(1, " ", 1);
        *first_word = 0;

        process_hundreds(group_value, group, group_size, value);
        process_tens_and_ones(group_value, value);
        process_unit(group_count, i, value);
    }
}

void convert_to_words(const char *num, const char *value[])
{
    size_t num_len = ft_strlen(num);
    size_t group_count = (num_len + 2) / 3;
    size_t remainder = num_len % 3;
    if (remainder == 0) remainder = 3;

    handle_zero_case(num, num_len, value);

    char group[4];
    size_t index = 0;
    int first_word = 1;

    for (size_t i = 0; i < group_count; i++)
    {
        size_t group_size = (i == 0) ? remainder : 3;
        ft_strncpy(group, &num[index], group_size);
        group[group_size] = '\0';
        index += group_size;

        process_group(group, group_size, group_count, i, &first_word, value);
    }

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
