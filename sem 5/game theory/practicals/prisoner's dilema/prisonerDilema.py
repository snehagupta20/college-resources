def prisoner_dilemma(player1_action, player2_action):
    # Payoff matrix
    payoff = {
        ("confess", "confess"): (3, 3),
        ("confess", "deny"): (0, 5),
        ("deny", "confess"): (5, 0),
        ("deny", "deny"): (1, 1),
    }

    # Retrieve the payoff for the given actions
    return payoff[(player1_action, player2_action)]

def main():
    print("Prisoner's Dilemma Simulation")
    print("Enter 'confess' or 'deny' for each player.")
    
    # Get input from player 1
    player1_action = input("Player 1's action: ").strip().lower()
    
    # Get input from player 2
    player2_action = input("Player 2's action: ").strip().lower()

    if player1_action not in {"confess", "deny"} or player2_action not in {"confess", "deny"}:
        print("Invalid input. Please enter 'cooperate' or 'betray'.")
        return

    # Calculate the payoffs
    player1_payoff, player2_payoff = prisoner_dilemma(player1_action, player2_action)

    # Print the results
    print(f"Player 1's payoff: {player1_payoff}")
    print(f"Player 2's payoff: {player2_payoff}")

if __name__ == "__main__":
    main()
