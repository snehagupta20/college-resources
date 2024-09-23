import re
#re module, which provides support for regular expressions.

class RomanNumeralParser:
    def __init__(self):
        #The __init__ method initializes the parser with the Context-Free Grammar (CFG) rules for Roman numerals.
        # Define the CFG rules
        self.rules = [
            ('M', 'M*'),
            ('CM', 'CM*'),
            ('D', 'D*'),
            ('CD', 'CD*'),
            ('C', 'C*'),
            ('XC', 'XC*'),
            ('L', 'L*'),
            ('XL', 'XL*'),
            ('X', 'X*'),
            ('IX', 'IX*'),
            ('V', 'V*'),
            ('IV', 'IV*'),
            ('I', 'I*')
        ]
        self.start_symbol = 'M'

    def parse(self, input_str):
        # Check if the input string is a valid Roman numeral
        if re.fullmatch(self.generate_regex(), input_str):
            return True
        else:
            return False

    def generate_regex(self):
        # Generate a regular expression based on CFG rules
        regex = self.start_symbol
        for rule in self.rules:
            regex = regex.replace(rule[0], rule[1])
        return f'^{regex}$'

# Example usage:
parser = RomanNumeralParser()
numeral = "XI"
if parser.parse(numeral):
    print(f"{numeral} is a valid Roman numeral.")
else:
    print(f"{numeral} is not a valid Roman numeral.")