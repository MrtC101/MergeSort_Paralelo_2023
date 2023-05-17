import argparse
import random

def generator(size: int, length: int, max_n: int) -> list[list]:
    lists: list = []
    for _ in range(size):
        random_list = [random.randint(0, max_n) for __ in range(length)]
        lists.append(random_list)
    return lists

def write_to_file(nf: str, lists: list) -> None:
    if nf:
        with open(nf, 'a', encoding='utf-8') as file:
            # _: list
            # __: element in list
            for _ in lists:
                file.write(' '.join(str(__) for __ in _))
                file.write('\n')

    else:
        with open('input.data', 'w', encoding='utf-8') as file:
            for _ in lists:
                file.write(' '.join(str(__) for __ in _))
                file.write('\n')

if __name__ == '__main__':
    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="""
                                    Generador de listas con números aleatorios
                                    """)

    # Add arguments for the two numbers
    parser.add_argument('cant', type=int, help='Lists')
    parser.add_argument('length', type=int, help='Length of lists')
    parser.add_argument('max_number', type=int, help='Max number in list')
    parser.add_argument('-f', '--input_file', type=str, help='Append to file')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Access the parsed values
    cant: int = args.cant
    length: int = args.length
    max_n: int = args.max_number
    name_file: str = args.input_file

    lists: list[list] = generator(cant, length, max_n)
    write_to_file(name_file, lists)

