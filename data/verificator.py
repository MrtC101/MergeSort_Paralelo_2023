def is_order(lista: list) -> bool:
    for i in range(len(lista) - 1):
        if lista[i] > lista[i + 1]:
            return False
    return True

def to_int_list(line: str) -> list:
    tmp: list = line.split()
    return [int(_) for _ in tmp]

if __name__ == '__main__':
    with open("ordered.data", "r") as file:
        for line in file:
            check = to_int_list(line)
            if not is_order(check):
                print("Error")
                break;
