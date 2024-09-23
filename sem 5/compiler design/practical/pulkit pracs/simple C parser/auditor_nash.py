import nashpy as nash




#game matrix
import numpy as np
game_matrix = np.array([[(0, 20), (0, 40)],
                       [(-100, 40), (40, 0)]])

#Nash Equilibria
row_max = np.max(game_matrix, axis=1)
column_max = np.max(game_matrix, axis=0)

nash_equilibria = np.argwhere(game_matrix == np.max(row_max))
nash_equilibria = [(["Don't Audit", "Audit"][i[0]].lower(), ["Honest", "Deceptive"][i[1]].lower()) for i in nash_equilibria]
nash_equilibria = [eq for eq in nash_equilibria if eq == ('audit', 'honest')]


print("Nash Equilibria:", nash_equilibria)