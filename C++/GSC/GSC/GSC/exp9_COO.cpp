#include <stdlib.h>
#include <stdio.h>

struct Timer {
	int h;
	int s;
	int m;

	void (*set)(struct Timer *, int, int, int);
	void (*show)(struct Timer*);
};

void set(struct Timer* pTimer, int h, int m, int s) {
	pTimer->h = h;
	pTimer->m = m;
	pTimer->s = s;
}

void show(struct Timer* pTimer) {
	printf("%02d:%02d:%02d\n",pTimer->h,pTimer->m,pTimer->s);
}

int main_coo(int argc, char** argv) {
	struct Timer t = {10,12,3,set, show };//µÈ¼ÛÓÚ{0,0,3,show,tick,run};
	t.set(&t, 0, 0, 4);
	t.show(&t);
	system("pause");
	return 0;
}