from main import is_splitted_right

def main():
    fileName = input("Введите имя файла: ")
    good = []
    lines = []
    with open(fileName, "r") as f:
        lines = f.readlines()
        for i in range(len(lines)):
            if not is_splitted_right(lines[i]).is_right:
                good.append(i)
    with open(fileName,"w") as f:
        for i in good:
            f.write(lines[i])

if __name__ == "__main__":
    main()