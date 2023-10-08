
class SM:
    def __init__(self, alph, steps, memory) -> None:
        self.alph = alph
        self.memory = memory
        self.steps = steps
    
    def recognize(s : str) -> bool:
        count = 20000
        c = '!'
        index = 0
        while count != 0 and c != '.':
            count -= 1


def main():
    pass

if __name__ == "__main__":
    main()