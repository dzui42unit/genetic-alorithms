#include <iostream>
#include <algorithm>
#include "gen.hpp"
#define POPULATION 	10
#define ELITE		3

std::vector<bool>	generate_key(int nb);
void				print_population(std::vector<gen> &population);
int 				genetic_algo(std::vector<gen> &popul, std::vector<bool> key);

// function that generates a key and prints it

std::vector<bool>	generate_key(int nb)
{
	std::vector<bool> key;

	std::cout << std::endl << "I am generating a key ..." << std::endl;
	for (int i = 0; i < nb; i++)
		key.push_back(0 + rand() % 2);
	std::cout << "key is: ";
	for (auto elem : key)
		std::cout << elem;
	std::cout << std::endl << std::endl;
	return (key);
}

// function that print the popualtion and its gene set

void	print_population(std::vector<gen> &population)
{	
	std::cout << std::endl;
	for (int i = 0; i < population.size(); i++)
		population[i].print_genes();
}

// function that performs a genetic algorithms

int 		genetic_algo(std::vector<gen> &popul, std::vector<bool> key)
{
	int 				epoch;
	bool				flag;
	int 				index;

	// generating a new population and printing its gen code

	flag = true;
	epoch = 0;
	while (flag)
	{
		std::cout << "EPOCH #" << epoch << std::endl;

		// going through the population
		// and counting the fintess of each object

		for (int i = 0; i < POPULATION; i++)
		{

			// if the fitness of one of the objects in the population
			// equals zero, it means that we have achieved result

			if (popul[i].count_fitness(key) == 0)
			{
				index = i;
				flag = false;
			}
		}

		// printing fitness of each object

		std::cout << "FITNESS OF EACH OBJECT IN THE POPULATION:" << std::endl;
		for (auto elem : popul)
			std::cout << " (" << elem.get_fitness() << ") ";
		std::cout << std::endl;
		
		// sorting the population, first ELITE elements are the objects with the best fitness

		std::sort(popul.begin(), popul.end());
		
		// ELITE objects do not change, other will perform crossingover with them

		for (int i = ELITE; i < POPULATION; i++)
		{
			popul[i].crossing_over(popul[0 + rand() % ELITE]);
			popul[i].mutation();
		}
		epoch++;
	}
	return (index);
} 	

int		main(void)
{
	// key - is a result that needs to be achieved
	// nb - is a number of elements that will represent a key

	std::vector<bool>	key;
	int					nb;

	// generating a key and printing it

	std::cout << "Enter a number of elements in a key: ";
	while (!(std::cin >> nb))
	{
		std::cout << "Invalid input, please enter a decimal number: ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue ;
	}

	srand(time(0));
	key = generate_key(nb);

	std::vector<gen> popul;

	for (int i = 0; i < POPULATION; i++)
		popul.push_back(gen(nb));
	int index = genetic_algo(popul, key);
	std::cout << "OBJECT #" << index << " is the best example out of " << POPULATION << std::endl;
	std::cout << "KEY: ";
	for (auto elem : key)
		std::cout << elem;
	std::cout << std::endl;
	popul[index].print_genes();
	return (0);
}