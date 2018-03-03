#include "gen.hpp"

// constructor that takes a number and generates a set of genes of this length

gen::gen(int n)
{
	nb = n;
	for (int i = 0; i < nb; i++)
		gen_code.push_back(0 + rand() % 2);
	fitness = 0;
}

// copy construtor

gen::gen(const gen &g)
{
	nb = g.nb;
	fitness = g.fitness;
	gen_code.resize(nb);
	for (int i = 0; i < nb; i++)
		gen_code[i] = g.gen_code[i];
		//gen_code.push_back(g.gen_code[i]);
}

// operator '<' overloaded
// that makes a comparrison in the base of fitness value

bool	gen::operator<(const gen &g)
{
	return (fitness < g.fitness);
}

// a function that performs a mutation
// by taking a random element an changing it value

void	gen::mutation(void)
{
	int pos;

	pos = 0 + rand() % nb;
	gen_code[pos] = !gen_code[pos];
}

// a function that performs a crossingover operation
// it is performed in a random manner, the exchange of genes

void	gen::crossing_over(const gen &g)
{
	for (int i = 0; i < nb; i++)
	{
		if ((0 + rand() % 2) == 0)
			gen_code[i] = g.gen_code[i];
	}
}

// print the genes set

void	gen::print_genes(void)
{
	std::cout << "GENES SET OF THE OBJECT: ";
	for (auto elem : gen_code)
		std::cout << elem;
	std::cout << std::endl;
}

// returns a set of genes

std::vector<bool>	gen::get_genes(void)
{
	return (gen_code);
}

// returns a fitness of the object

int					gen::get_fitness(void)
{
	return (fitness);
}

// target function, check if out result is achived
// the lower fitness, the better is an object 

int					gen::count_fitness(std::vector<bool> key)
{
	int res;

	res = 0;
	for (int i = 0; i < nb; i++)
	{
		if (gen_code[i] != key[i])
			res++;
	}
	fitness = res;
	return (fitness);
}

// copy assignment operator overloaded

gen 	&gen::operator=(const gen &g)
{
	gen_code = g.gen_code;
	nb = g.nb;
	fitness = g.fitness;
	return (*this);
}

// returns the number of genes

int		gen::get_nb(void)
{
	return (nb);
}
