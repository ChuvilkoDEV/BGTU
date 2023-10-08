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

def is_sh(c : str):
    return c.lower() in 'ьъ'

class ParseResult:
    def __init__(self, is_right, state, character) -> None:
        self.is_right = is_right
        self.state = state
        self.character = character

def is_splitted_right(line : str) -> ParseResult:
    line = line.strip()
    S = 0
    err = True
    char = ''
    for c in line:
        match S:
            case 0:
                if is_consonant_full(c):
                    S = 1
                elif is_vowel(c):
                    S = 2
                else:
                    err, char = report_error(S, c)
                    break
            case 1:
                if is_consonant_full(c):
                    S = 1
                elif is_sh(c):
                    S = 5
                elif is_vowel(c):
                    S = 6
                else:
                    err, char = report_error(S, c)
                    break
            case 2:
                if is_vowel(c):
                    S = 2
                elif c == 'й':
                    S = 3
                elif is_consonant(c):
                    S = 4
                else:
                    err, char = report_error(S, c)
                    break
            case 3:
                if is_vowel(c):
                    S = 2
                elif is_consonant_full(c):
                    S = 4
                else:
                    err, char = report_error(S, c)
                    break
            case 4:
                if is_vowel(c):
                    S = 6
                elif is_sh(c):
                    S = 7
                elif c == '-':
                    S = 10
                elif is_consonant_full(c):
                    S = 1
                else:
                    err, char = report_error(S, c)
                    break
            case 5:
                if is_consonant_full(c):
                    S = 1
                elif is_vowel(c):
                    S = 6
                else:
                    err, char = report_error(S, c)
                    break
            case 6:
                if is_consonant(c):
                    S = 4
                elif is_vowel(c):
                    S = 2
                elif c == 'й':
                    S = 8
                elif c == '-':
                    S = 9
                else:
                    err, char = report_error(S, c)
                    break
            case 7:
                if c == '-':
                    S = 10
                elif is_vowel(c):
                    S = 6
                elif is_consonant_full(c):
                    S = 1
                else:
                    err, char = report_error(S, c)
                    break
            case 8:
                if is_consonant_full(c):
                    S = 4
                elif is_vowel(c):
                    S = 2
                elif c == '-':
                    S = 9
                else:
                    err, char = report_error(S, c)
                    break
            case 9:
                if is_vowel(c):
                    S = 11
                else:
                    err, char = report_error(S, c)
                    break
            case 10:
                if is_consonant_full(c):
                    S = 14
                else:
                    err, char = report_error(S, c)
                    break
            case 11:
                if c == 'й':
                    S = 12
                elif is_sym(c):
                    S = 13
                else:
                    err, char = report_error(S, c)
                    break
            case 12:
                if is_sym(c):
                    S = 13
                else:
                    err, char = report_error(S, c)
                    break
            case 13:
                if is_sym(c):
                    S = 13
                    err = False
                else:
                    err, char = report_error(S, c)
                    break
            case 14:
                if is_consonant_full(c):
                    S = 14
                elif is_sh(c):
                    S = 15
                elif is_vowel(c):
                    S = 13
                else:
                    err, char = report_error(S, c)
                    break
            case 15:
                if is_vowel(c):
                    S = 13
                elif is_consonant_full(c):
                    S = 14
                else:
                    err, char = report_error(S, c)
                    break
    return ParseResult(not err, S, char)



def main():
    word = 'паррррррьез-вет'
    print('Разбираемое слово <{0}>'.format(word))
    res = is_splitted_right(word)
    if res.is_right:
        print("Слово разбито верно")
    else:
        print("Слово разбито неверно")
    if not res.is_right:
        print("Распознаватель был в состоянии S{0}, символ, вызвавший ошибку <{1}>.".format(res.state, res.character))

if __name__ == "__main__":
    main()