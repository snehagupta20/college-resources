#strategies for the auditor and taxpayer
auditor_strategies = ['dont audit', 'audit']
taxpayer_strategies = ['honest', 'deceptive']

#payoff matrix
auditor_payoff_matrix = [[0, 0], [-100, 40]]
taxpayer_payoff_matrix = [[20, 40], [40, 0]]

#payoff for each player
def calculate_payoff(auditor_strategy, taxpayer_strategy):
    if auditor_strategy == 'dont audit' and taxpayer_strategy == 'honest':
        return (0, 20)
    elif auditor_strategy == 'dont audit' and taxpayer_strategy == 'deceptive':
        return (-100, 40)
    elif auditor_strategy == 'audit' and taxpayer_strategy == 'honest':
        return (0, 40)
    elif auditor_strategy == 'audit' and taxpayer_strategy == 'deceptive':
        return (40, 0)

#pure Nash equilibria (if any)
nash_equilibria = []
for i, auditor_strategy in enumerate(auditor_strategies):
    for j, taxpayer_strategy in enumerate(taxpayer_strategies):
        if calculate_payoff(auditor_strategy, taxpayer_strategy) == (max([calculate_payoff(auditor_strategies[k], taxpayer_strategy)[0] for k in range(len(auditor_strategies))]), max([calculate_payoff(auditor_strategy, taxpayer_strategies[k])[1] for k in range(len(taxpayer_strategies))])):
            nash_equilibria.append((auditor_strategy, taxpayer_strategy))

print("Nash Equilibria:", nash_equilibria)

