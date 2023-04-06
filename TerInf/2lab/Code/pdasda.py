import math


class SymbolStat:
  def __init__(self, symbol):
    self.symbol = symbol
    self.count = 1


class SymbolCode:
  def __init__(self, symbol: str, probability: float):
    self.symbol = symbol
    self.probability = probability
    self.code = ''


def add_symbol_in_stats(symbol: str, symbol_stats: list[SymbolStat]):
  for i in range(len(symbol_stats)):
    if symbol == symbol_stats[i].symbol:
      symbol_stats[i].count += 1
      return

  symbol_stats.append(SymbolStat(symbol))
  return


def read_message(_message: str):
  list_of_symbol_stats = []
  count_all = 0
  for i in range(len(_message)):
    count_all += 1
    add_symbol_in_stats(_message[i], list_of_symbol_stats)
  return list_of_symbol_stats, count_all


def create_sorted_symbol_codes_table(symbol_stats: list[SymbolStat], count_all: int):
  symbol_codes_table = []
  for i in range(len(symbol_stats)):
    new_symbol_code = SymbolCode(symbol_stats[i].symbol,
                                 symbol_stats[i].count / count_all)
    symbol_codes_table.insert(i, new_symbol_code)

  return sorted(symbol_codes_table, key=lambda x: x.probability, reverse=True)


def get_symbol_codes_recursive(sorted_symbol_code_table: list[SymbolCode],
                               left_border: int, right_border: int):
  if right_border - left_border == 1:
    return

  sum_of_probabilities_total = 0
  i = left_border
  while i < right_border:
    sum_of_probabilities_total += sorted_symbol_code_table[i].probability
    i += 1

  i = left_border
  sum_of_probabilities_partial = 0
  while i < right_border and sum_of_probabilities_partial < sum_of_probabilities_total / 2:
    sum_of_probabilities_partial += sorted_symbol_code_table[i].probability
    i += 1

  for j in range(left_border, i):
    sorted_symbol_code_table[j].code += '0'

  for j in range(i, right_border):
    sorted_symbol_code_table[j].code += '1'

  get_symbol_codes_recursive(sorted_symbol_code_table, left_border, i)
  get_symbol_codes_recursive(sorted_symbol_code_table, i, right_border)

  return


def set_codes_for_symbol_codes_table(sorted_symbol_codes_table: list[SymbolCode]):
  get_symbol_codes_recursive(sorted_symbol_codes_table, 0,
                             len(sorted_symbol_codes_table))


def get_code_of_symbol(symbol: str, sorted_symbol_codes_table:
list[SymbolCode]):
  for i in sorted_symbol_codes_table:
    if i.symbol == symbol:
      return i.code

  return "???"


def get_message_in_code(message: str, encoding: list[SymbolCode]):
  encoded_message = ''
  for i in message:
    encoded_message += (get_code_of_symbol(i, encoding) + '\'')

  return encoded_message


def get_entropy(sorted_symbol_codes_table: list[SymbolCode]):
  entropy = 0
  for i in sorted_symbol_codes_table:
    entropy += math.log(i.probability, math.e) * i.probability

  return entropy


def get_dispersion(sorted_symbol_codes_table: list[SymbolCode]):
  m_of_squares = 0
  for i in sorted_symbol_codes_table:
    m_of_squares += (math.log(i.probability, math.e) ** 2) * i.probability

  return m_of_squares - get_entropy(sorted_symbol_codes_table) ** 2


def get_compression_ratio(message: str, sorted_symbol_codes_table:list[SymbolCode]):
  encoded_message_len = 0
  for i in message:
    encoded_message_len += len(get_code_of_symbol(i, sorted_symbol_codes_table))

  return encoded_message_len / len(message) / 8


if __name__ == '__main__':
  message = input('Input message:\n')
  sorted_symbol_codes_table = create_sorted_symbol_codes_table(*read_message(message))
  set_codes_for_symbol_codes_table(sorted_symbol_codes_table)
  for i in range(len(sorted_symbol_codes_table)):
    print(sorted_symbol_codes_table[i].symbol, " ", '%.4f' %
          sorted_symbol_codes_table[i].probability, " ",
          sorted_symbol_codes_table[i].code)

  print(get_message_in_code(message, sorted_symbol_codes_table))
  print("Коэффициент сжатия: ", get_compression_ratio(message,
                                                      sorted_symbol_codes_table))
  print("Дисперсия: ", get_dispersion(sorted_symbol_codes_table))
