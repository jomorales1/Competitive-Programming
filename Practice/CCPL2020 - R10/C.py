from sys import stdin

name = stdin.readline().strip()
n = int(stdin.readline().strip())
actions = []
for i in range(n):
    actions.append(stdin.readline().strip().split())
scores = {}

for i in range(n):
    if len(actions[i]) == 5:
        first = actions[i][0]
        second = actions[i][3][:-2]
        if first not in scores.keys():
            scores[first] = 0
        if second not in scores.keys():
            scores[second] = 0
        if actions[i][1] == 'posted' and (first == name or second == name):
            scores[first] += 15
            scores[second] += 15
        elif actions[i][1] == 'commented' and (first == name or second == name):
            scores[first] += 10
            scores[second] += 10
    else:
        first = actions[i][0]
        second = actions[i][2][:-2]
        if first not in scores.keys():
            scores[first] = 0
        if second not in scores.keys():
            scores[second] = 0
        if first == name or second == name:
            scores[first] += 5
            scores[second] += 5

results = {}

for nam, score in scores.items():
    if score not in results.keys():
        results[score] = []
    results[score].append(nam)

results_items = results.items()
sorted_items = sorted(results_items, reverse = True)

for s in sorted_items:
    names_sorted = sorted(s[1])
    for na in names_sorted:
        if na != name:
            print(na)