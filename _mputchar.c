#include <unistd.h>
#include "main.h"
/**
 * _mputchar - writes the character c to stdout
 * @mwrite: The character tp print
 * Return: On success 1
 * On error, -1 is returned, and error is set appropriately
 */
int _mputchar(char mwrite)
{
	return (write(1, &mwrite, 1));
}
