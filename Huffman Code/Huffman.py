import sys
from pathlib import Path
from Graph import build_huffman_tree, generate_codes # type: ignore

def main(txt, coded):

    plain = open(txt, "r")
    plain = plain.read()

    print("In what term you desire to use this program: (choose number)")
    print("1.Encoding")
    print("2.Decoding")
    coding = int(input()) # What are we doing?
    alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
                "u", "v", "w", "x", "y", "z", " "]
    counter = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    letter = []
    density = []
    binFormat = ""

    match coding:

        case 1:
            for i in plain:
                if i.isalpha() or i == " ":

                    if i not in letter:
                        letter.append(i)
                        density.append(counter[alphabet.index(i.lower())] + 1)
                    
                    else:
                        density[letter.index(i)] = density[letter.index(i)] + 1 

            letterList = [(x, y) for x, y in zip(letter, density)]
            letterList = sorted(letterList, key=lambda x: x[1])

    # Build the Huffman Tree
    huffman_tree = build_huffman_tree(letterList)

    # Generate binary codes for each character
    codes = generate_codes(huffman_tree)

    # Print the binary codes
    for char, code in codes.items():
        print(f"Characters: {char}, Binary Code: {code}")

    for i in plain:
        if i.isalpha() or i == " ":
            for char, code in codes.items():
                if i == char:
                    binFormat += str(code)

        else:
            binFormat += i
            
    print(binFormat)


        #case 2:
    

try:
    if sys.argv[1] == "--help":
        # Here is how to use the system arguments for this program
        print("\nUsage of this Encoding system is like:\n    InputFile.txt OutputFile.txt")
        sys.exit()

    elif Path(sys.argv[1]).suffix.lower() != ".txt" or Path(sys.argv[2]).suffix.lower() != ".txt":
        print("I/O files should be in *.txt format!")
        sys.exit()

except IndexError: # Check if the argument values are passing correctly
    print("There are not enough arguments! (use --help)")
    sys.exit()

except FileNotFoundError: # Check if the input text file even exists
    print("Input file does not exist in this directory! (use -help)")
    sys.exit()

except EOFError:
    print("Program has been halted as you wished")
    sys.exit()

main(sys.argv[1], sys.argv[2]) # Pass two input and output text files to the main function
