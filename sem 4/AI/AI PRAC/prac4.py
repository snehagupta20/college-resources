# Experiment 4 (sneha gupta 2021UCA1859) 

import random

def objective_function (chromosome):
    return sum(chromosome)

def fitness_function (chromosome):
    return objective_function(chromosome)

def genetic_algorithm (population_size, chromosome_length, crossover_rate, mutation_rate, max_iterations): 
    population = [[random.randint(0, 1) for _ in range(chromosome_length)] for _ in range(population_size)] 
    for iteration in range(max_iterations):
        fitness_values = [fitness_function(chromosome) for chromosome in population] 
        parents = []
        for _ in range(population_size):
            candidatel=random.randint(0, population_size -1)
            candidate2 =random.randint(0, population_size - 1)
            parent=population[candidatel] if fitness_values[candidatel] > fitness_values[candidate2] else population[candidate2] 
            parents.append(parent)
        offspring = []
        for i in range(0, population_size, 2):
            parent1 = parents[i]
            parent2 =parents[i+1]
            if random.random() < crossover_rate:
                crossover_point=random.randit(1,chromosome_length-1)
                child1 = parent1[:crossover_point] + parent2 [crossover_point:] 
                child2 = parent2 [:crossover_point] + parent1 [crossover_point:]

            else:
                child1= parent1
                child2 = parent2 
            offspring.append(child1) 
            offspring.append(child2)
        for i in range(population_size): 
            chromosome = offspring[i]
            for j in range (chromosome_length):
                if random.random() < mutation_rate: 
                    chromosome[j]=1-chromosome[j]
        offspring_fitness_values=[fitness_function(chromosome) for chromosome in offspring]
        population=[]
        for i in range(population_size):
            if fitness_values[i]>=offspring_fitness_values[i]:
                population.append(parents[i])
            else:
                population.append(offspring[i])
    best_chromosome=max(population,key=fitness_function)
    return best_chromosome,fitness_function(best_chromosome)
population_size=100
chromosome_length=20
crossover_rate=0.8
mutation_rate=0.01
max_iterations=1000
best_chromosome,best_fitness=genetic_algorithm(population_size,chromosome_length,crossover_rate,mutation_rate,max_iterations)
print("best chromosome:",best_chromosome)
print("best fitness",best_fitness)

