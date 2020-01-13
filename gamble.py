import matplotlib.pyplot as plt
import random

def gamble(wallet, cost, goal):
    games = []
    initial = wallet    
    while wallet >= 0:
        outcome = []
        wallet -= cost
        bet = 2
        flip = random.randint(0, 1)
        while flip != 1:
            bet *= 2
            flip = random.randint(0, 1)
        wallet += bet
        if wallet - initial >= goal:
            return True
    return False

def accurate(wallet, cost, goal):
    outcomes = {True:0, False:0}
    for _ in range(1000):
        outcomes[gamble(wallet, cost, goal)] += 1
        #print(outcomes)
    return outcomes[True]/1000

total_games = 50
cost = 10
threshold = 0.90

goal_values = [i*30 for i in range(10)]
goal_wallets = []
i = 0

for g in goal_values:
    if i == 0:
        init_wallet = 2
    else:
        init_wallet = goal_wallets[i-1]
    while True:
        outcomes = {True:0, False:0}
        for _ in range(total_games):
            outcome = gamble(init_wallet,cost, g)
            outcomes[outcome] += 1
        if outcomes[True] / total_games >= threshold:
            #print('outcomes: {}'.format(outcomes[True]/total_games))
            goal_wallets.append(init_wallet)
            break
        else:
            init_wallet += 50
    i+= 1


for i in range(len(goal_values)):
    print("goal_value: {} goal_wallet: {} acc: {}".format(goal_values[i], goal_wallets[i], accurate(goal_wallets[i], cost, goal_values[i])))

#plt.scatter(goal_values, goal_wallets)
#plt.show()

ax = plt.axes(projection='3d')


