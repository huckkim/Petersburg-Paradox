# Petersburg-Paradox
Simulates the Saint Petersburg Paradox with an adjustable bankroll and cost. With graphing!

## The Paradox
The Saint Petersburg Paradox is a popular gambling paradox in which it is always profitable to play a certain game no matter what the cost of that game is. The game is as follows:
1. Pay the cost of the game
2. Set n = 2
3. Flip a coin 
    1. if it lands tails collect n dollars
    2. if it lands on heads set n = 2 * n and repeat step 3

Apparently if you play this game enough times (infinitely many times) you get an expect value of infinte. However unlike most people (like Bill Gates) this profit is rarely obtainable without a sizeable bankroll. This brings me to what I wanted to simulate

## The program
My goals was to find, given the cost of a single game and a desired profit, how much you must be willing to lose or your bankroll to obtain that profit. It does this by starting with an initial bankroll and then running an instance of the game, if it was able to reach the desired profit before losing all of it's money then it saved that value. However just in case it was a lucky chance it would then repeat the game a certain number of times and if the percentage of won games reached a certain threshold it would then consider it correct. 

Initially it was a python script however the computations became to heavy for it to do in reasonable time. So I switched to a cpp simulation while still graphing the results using Python. 

## The results
![Figure 1](/Figure_1.png)

After running the simulation for a range of profit between 10-100 dollars against a cost of 10-22 dollars we see that the cost grows at an unreason rate which again follows the idea that this game is only profitable with an already infinite bankroll.

## Playing around
If you for some reason want to play around with this thing then the features are all in gamble.py and the following are adjustable 

```cpp
    double thres = 0.9;                   // Threshold percent
    int cost_init = 10, cost_final = 23;  // Inital and final cost of each game values
    int goal_init = 10, goal_final = 100; // Initial and final target profit values
    int games = 100;                      // Games needed for each bankroll check
```
The results are outputted to values.txt.
