#include "misc.h"
#include <cmath>
#include <vector>
#include <ctime>

void crossover(Solution s1, Solution s2) {
	std::vector<int> child(s1.size());
	int breakPoint = (int) round(child.size() / 2);
	for (int i = 0; i < child.size(); i++) {
		child[i] = i <= breakPoint ? s1[i] : s2[i];
	}
}

std::vector<Solution> getParents(Population &p, int mode) {
	p.sort();
	switch (mode) {
	case SEL_BEST:
	{
		Solution parent1 = p[0], parent2 = p[1];
		return { parent1, parent2 };
		break;
	}
	case SEL_RANDOM:
	{
		std::srand(std::time(nullptr));
		int max = p.size();
		int n1 = std::rand() % max, n2 = std::rand() % max;

		int i1 = n1 > n2 ? n1 : n2;
		Solution parent1 = p[i1];
		int i2;
		do {
			n1 = std::rand() % max; n2 = std::rand() % max;

			i2 = n1 > n2 ? n1 : n2;
		} while (i2 != i1);
		Solution parent2 = p[i2];
		break;
	}
	default:
		return {};
		break;
		//	should raise some exception, will do later
	}

}