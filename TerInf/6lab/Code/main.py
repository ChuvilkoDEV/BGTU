from sys import getsizeof
from fractions import Fraction


def codeMessage(message: str, x) -> tuple[Fraction, dict[str, tuple[Fraction, Fraction]]]:
    message += "\0"
    alphabet: dict[str, Fraction] = {}
    decodeTable: dict[str, tuple[Fraction, Fraction]] = {}
    maxDenominator = 10 ** int(len(message) / x)

    for i in message:
        alphabet[i] = alphabet[i] + 1 if alphabet.__contains__(i) else 1

    old: tuple[Fraction, Fraction] = (Fraction(0), Fraction(0))
    for i in alphabet.keys():
        alphabet[i] /= Fraction(len(message))
        decodeTable[i] = (old[1], old[1] + alphabet[i])
        old = decodeTable[i]

    current: tuple[Fraction, Fraction] = (Fraction(0), Fraction(0))
    for i in message:
        t: tuple[Fraction, Fraction] = decodeTable[i]
        if current == (0, 0):
            current = t
        else:
            left = current[0].limit_denominator(maxDenominator)
            right = current[1].limit_denominator(maxDenominator)
            current = (left + (right - left) * t[0], left + (right - left) * t[1])

    return ((current[0] + current[1]) / 2).limit_denominator(maxDenominator), decodeTable


def decodeMessage(coded_message: Fraction, decode_table: dict[str, tuple[Fraction, Fraction]]) -> str:
    message: str = ""
    while True:
        t: tuple[str, tuple[Fraction, Fraction]] = ("", (Fraction(0),
                                                         Fraction(0)))
        for ch in decode_table.keys():
            if decode_table[ch][0] <= coded_message <= decode_table[ch][1]:
                t = (ch, decode_table[ch])
        if t[0] == "\0":
            break
        message += t[0]
        coded_message = (coded_message - t[1][0]) / (t[1][1] - t[1][0])
    return message


if __name__ == '__main__':
    # s = "в чащах юга жил бы цитрус? да но фальшивый экземпляр!"
    s = "Victoria nullaest, Quam quae confessos animo quoque subjugat hostes"
    undef = True
    last_x = x = 1
    while undef or decodeMessage(code, table) == s:
        code, table = codeMessage(s, x)
        if decodeMessage(code, table) != s:
            break
        last_x = x
        x *= 1.1
        undef = False
    code, table = codeMessage(s, last_x)
    # print(code)
    # for ch in table:
    #     print(f"\'{ch}\': ({table[ch][0]}; {table[ch][1]})")
    print(decodeMessage(code, table))
    print(getsizeof(code))
    print(len(s) / (getsizeof(code.numerator) +
                    getsizeof(code.denominator) - 48))
