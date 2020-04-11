#include "config.h"

std::map<int, void(*)(void)> KB {
	{ 'q', quit      },
	{ 'j', move_down },
	{ 'k', move_up   },
	{ 'b', bold      },
};
