def is_consonant(c : str) -> bool:
    return c.lower() in 'бвгджзклмнпрстфхцчшщ'

def is_vowel(c : str) -> bool:
    return c.lower() in 'аяуюоеёэиы'

def is_consonant_full(c : str) -> bool:
    return c.lower() in 'бвгджзклмнпрстфхцчшщй'

def is_sym(c : str) -> bool:
    return c.lower() in 'бвгджзклмнпрстфхцчшщйаяуюоеёэиы'

def report_error(state_num : int, c : str) -> bool:
    print('{0}Error. S = {1}, character = <{2}>, {3}'.format("\033[31m", state_num, c, "\033[0m"))
    return True, c

def is_sh(c : str) -> bool:
    return c.lower() in 'ьъ'

def get_index(c : str) -> int:
    if is_vowel(c):
        return 0
    elif is_consonant(c):
        return 1
    elif c == 'й':
        return 2
    elif is_sh(c):
        return 3
    elif c == '-':
        return 4
    else:
        raise(Exception("Wrong index"))

class ParseResult:
    def __init__(self, is_right, state, character) -> None:
        self.is_right = is_right
        self.state = state
        self.character = character

class Parser:
    def __init__(self, fileName) -> None:
        self.matr = []
        self.S = 0
        self.status = ParseResult(False, -100, '')
        with open(fileName, "r") as f:
            lines = f.readlines()
            for i in range(len(lines)):
                self.matr.append([])
                line = lines[i].strip()
                states = line.split(' ')
                for state in states:
                    self.matr[i].append(int(state) if state != '.' else -100)

    def parse(self, str) -> ParseResult:
        for c in str:
            new_state = self.matr[get_index(c)][self.S]
            self.status.state = self.S
            self.status.character = c
            if new_state != -100:
                self.S = new_state
                if new_state == 13:
                    self.status.is_right = True
            else:
                report_error(self.S, c)
                self.status.is_right = False
                return
        self.status.character = ''



def main():
    word = 'прьий-евет'
    print('Разбираемое слово <{0}>'.format(word))
    parser = Parser("table.txt")
    parser.parse(word)
    res = parser.status
    if res.is_right:
        print("Слово разбито верно")
    else:
        print("Слово разбито неверно")
    if not res.is_right:
        print("Распознаватель был в состоянии S{0}, символ, вызвавший ошибку <{1}>.".format(res.state, res.character))

if __name__ == "__main__":
    main()