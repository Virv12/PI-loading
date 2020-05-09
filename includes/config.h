#include <map>

void quit();
void move_up();
void move_down();
void bold();

extern std::map<int, void(*)(void)> KB;
