#ifndef GEN_HPP
#define GEN_HPP
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

// a class that represents an representative
// that has its own set of genes, that will be randomly generated
// and has the fitness factor

class 	gen
{
private:
	std::vector<bool> 		gen_code;
	int						fitness;
	int						nb;
public:
							gen(void) = delete;
							gen(int nb);
							gen(const gen &g);
							~gen() { }
	gen 					&operator=(const gen &g);
	bool 					operator<(const gen &g);
	void 					mutation(void);
	void					crossing_over(const gen &g);
	void					print_genes(void);
	std::vector<bool>		get_genes(void);
	int						get_fitness(void);
	int						count_fitness(std::vector<bool> key);
	int 					get_nb(void);
};

#endif