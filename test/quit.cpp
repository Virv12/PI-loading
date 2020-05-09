#include <stdio.h>
#include <config.h>

int main() {
	for (const auto& [i, fn] : KB)
		if (fn == quit)
			return 0;

	puts("No binding for quit");
	return 1;
}
