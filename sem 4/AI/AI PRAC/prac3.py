# Experiment 3 (sneha guota 2021UCA1859)

import random
import math

def distance(city1, city2):
    return math.sqrt((city1[0] - city2[0]) ** 2 + (city1[1] -city2[1]) ** 2)

def tour_length(coords, tour):
    return sum (distance (coords[tour[i]], coords[tour[i+1]]) for i in range(len(tour)-1)) + distance (coords[tour[-1]], coords[tour[0]])
                                                                                                       
def simulated_annealing_tsp(coords, temp=10000, cool=0.99, stopping_temp=1e-8, stopping_iter=1000):

    tour = random.sample (range(len(coords)), len(coords))
    curr_length = tour_length (coords, tour)
    i = 0
    while temp >= stopping_temp and i < stopping_iter:
        c1,c2=sorted(random.sample(range(len(coords)),2))
        new_tour=tour[:c1]+tour[c1:c2][::-1]+tour[c2:]
        new_length=tour_length(coords,new_tour)
        delta=new_length-curr_length 
        if delta<0 or math.exp(-delta/temp)>random.random():
            tour=new_tour
            curr_length=new_length
        temp*=cool
        i+=1
    return tour

random.seed(42)
cities=[(random.uniform (0, 1), random. uniform (0, 1)) for i in range(50)]
tour =simulated_annealing_tsp (cities)
print("Optimal tour:", tour)
print("Tour length:", tour_length(cities, tour))
