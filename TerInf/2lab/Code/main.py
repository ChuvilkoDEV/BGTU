probabilities = [[]]
line = str()

if __name__ == '__main__':
  message = input()
  for i in line:
    if i in probabilities:
      probabilities[i] += 1
    else:
      probabilities[i] = 1

  for i in probabilities:
    probabilities[i] /= len(line)
    print(probabilities[i])

  tmp = {}

