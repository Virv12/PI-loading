#include <bits/stdc++.h>
#include <ncurses.h>
using namespace std;

void quit() {
	endwin();
	exit(0);
}

int y = 0;
void move_up()   { y = max(0, y-1);       }
void move_down() { y = min(LINES-1, y+1); }

void bold() {
	static bool b = false;
	if (b) attroff(A_BOLD);
	else   attron(A_BOLD);
	b ^= true;
}

long long gettime() {
	timespec t;
	clock_gettime(0, &t);
	return t.tv_sec * 1e9 + t.tv_nsec;
}

extern map<int, void(*)(void)> KB;

int main() {
	initscr();
	cbreak();
	noecho();
	timeout(50);
	curs_set(0);

	long long st = gettime();
	int ch;

	while (1) {
		if ((ch = getch()) != ERR) {
			auto it = KB.find(ch);
			if (it != KB.end())
				it->second();
		}

		erase();

		long long cnt = (gettime() - st) / 50e6;

		if (cnt >= COLS-2) {
			st += (COLS-2) * 50e6;
			cnt = 0;
		}

		wmove(stdscr, y, 0);
		addch('[');
		for (int i=0; i<COLS-2; i++)
			addch(i < cnt ? ACS_PI : ' ');
		addch(']');
		refresh();
	}
}
