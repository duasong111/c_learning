//这个是进行滚动的循环，缺点就是我没有掌握，我不会，这个是最大的缺点
#include <time.h>
#include <stdio.h>
#include <string.h>
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;
	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}
int main(void)
{
	int i;
	int cnt = 0;
	char name[] = "YOU ARE GREAT";
	int name_len = strlen(name);  //这个是用来进行计算字符的
	while (1) {
		putchar('\r');
		for (i = 0; i < name_len; i++) {
			if (cnt + i < name_len)
				putchar(name[cnt + i]);
			else
				putchar(name[cnt + i - name_len]);
		}
		fflush(stdout);
		sleep(500);
		if (cnt > 0)
			cnt--;
		else
			cnt = name_len - 1;
	}
	return 0;
}

//对这个你要多加的复习啊。
