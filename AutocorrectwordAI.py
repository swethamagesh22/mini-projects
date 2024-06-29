
from autocorrect import Speller
spell = Speller(lang='en')
def autocorrect_text(input_text):
    corrected_text = spell(input_text)
    return corrected_text
# Create an interactive loop
while True:
    input_text = input("Enter your text: ")
    if input_text.lower() == "exit":
        break

    corrected_text = autocorrect_text(input_text)
    print("Autocorrected Text:", corrected_text)