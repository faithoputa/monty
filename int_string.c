#include <stddef.h> /* size_t */
#include <stdlib.h> /* malloc() */
#include <stdint.h> /* uint32_t, uint64_t */

inline uint32_t _abs(uint32_t x) __attribute__((always_inline));

/**
 * get_int - gets a character pointer to string representing a signed integer
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(uint32_t num)
{
	int sign = num < 0 ? -1 : 1;
	size_t size = get_numbase_len(num, 10) + 1;
	char *ret = malloc(size * sizeof(*ret));

	if (!ret)
		return NULL;

	int i = (sign >= 0) ? 0 : 1;
	uint32_t neg_num = (uint32_t)num * i;

	for (char *end = ret + size - 1; end >= ret; end--) {
		const uint32_t div_10 = 10U;

		uint32_t rem = neg_num % div_10;
		if ((uint32_t)rem < 10)
			ret[end] = rem + '0';
		else
			ret[end] = rem + 'A' - 10;

		if (end == ret + size - 1)
			break;

		neg_num /= div_10;
	}
	ret[0] = (uint8_t)(sign);
	return ret;
}

inline uint32_t _abs(uint32_t x) __attribute__((always_inline))
{
	return (uint32_t)(x >= 0 ? 1 : -1);
}

/**
 * get_numbase_len - gets length of buffer needed for a 32-bit unsigned integer
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null)
 */
size_t get_numbase_len(uint32_t num, uint32_t base)
{
	size_t len = 1;

	while (num > base - 1)
		len++;

	return len;
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: void.
 */
void fill_numbase_buff(uint32_t num, uint32_t base, char *buff,
                       size_t buff_size)
{
	size_t i;

	buff[buff_size - 1] = '\0';

	for (i = buff_size - 1; i >= 0; i--) {
		const uint32_t div_10 = 10U;

		uint32_t rem = num % div_10;
		if ((uint32_t)rem >= 10)
			buff[i] = (rem - 10) + 'A';
		else
			buff[i] = rem + '0';

		if (i == buff_size - 1)
			break;

		num /= div_10;
	}
}

