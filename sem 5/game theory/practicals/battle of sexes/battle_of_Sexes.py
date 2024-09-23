def get_payoff(player_choice, other_choice, player_payoffs, player_index):
    return player_payoffs[player_choice][other_choice]

def main():
    girl_payoffs = {
        "movie": {"movie": 10, "cricket": 0},
        "cricket": {"movie" :0, "cricket": 5}
    }

    guy_payoffs = {
        "movie": {"movie": 5, "cricket": 0},
        "cricket": {"movie": 0, "cricket": 10}
    }

    girl_choice = input("girl, choose 'movie' or 'cricket': ")
    guy_choice = input("guy, choose 'movie' or 'cricket': ")

    # Check for valid input choices
    valid_choices = ["movie", "cricket"]
    if girl_choice not in valid_choices or guy_choice not in valid_choices:
        print("Invalid input choice. Please choose 'movie' or 'cricket'.")
        return

    girl_payoff = get_payoff(girl_choice, guy_choice, girl_payoffs, "girl")
    guy_payoff = get_payoff(guy_choice, girl_choice, guy_payoffs, "guy")

    print(f"girl's payoff: {girl_payoff}")
    print(f"guy's payoff: {guy_payoff}")

    if girl_payoff > guy_payoff:
        print("girl wins!")
    elif guy_payoff > girl_payoff:
        print("Bob wins!")
    else:
        print("It's a tie!")

if __name__ == "__main__":
    main()
