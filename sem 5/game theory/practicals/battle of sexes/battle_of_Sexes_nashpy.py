import nashpy as nash

def main():
    alice_payoffs = [[5, 1], [3, 4]]
    bob_payoffs = [[5, 3], [1, 4]]

    battle_of_sexes = nash.Game(alice_payoffs, bob_payoffs)

    lemke_howson_eqs = battle_of_sexes.lemke_howson(initial_dropped_label=0)

    print("Equilibrium strategies using Lemke-Howson algorithm:")
    for alice_eq, bob_eq in lemke_howson_eqs:
        print(f"Alice's equilibrium strategy: {alice_eq}")
        print(f"Bob's equilibrium strategy: {bob_eq}")

if __name__ == "__main__":
    main()
