import csv

with open('../../translations.csv') as csvfile:
    translations = {row[0]:row[1] for row in csv.reader(csvfile, delimiter=',')}
    while True:
        line = input()
        if line == '#':
            break
        items = [i.split('=') for i in line.split(',')]
        total = 0
        for item,qty in items:
            print(f'{qty} {translations[item] if int(qty) > 1 else item}')
            total += int(qty)
        print(f'total: {total} item{"s" if total > 1 else ""}')
