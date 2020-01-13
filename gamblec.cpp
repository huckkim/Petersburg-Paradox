#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

bool gamble(int cost, int wallet, int goal){
    int init_w = wallet;
    while(wallet > 0){
        wallet -= cost;
        int bet = 2;
        while(rand()%2 == 1){
            bet *= 2;
        }
        wallet += bet;
        if(wallet - init_w >= goal){
            return true;
        }
    }
    return false;
}

int find_wallet(int cost, int init_w, int goal, double thres, int games){
    int test_w = init_w;
    while(true){
        int outcomes[] = {0, 0};
        for(int i = 0; i < games; i ++){
            int result = int(gamble(cost, test_w, goal));
            outcomes[result] += 1;
        }
        if(double(outcomes[true]) / double(games) >= thres){
            //cout<<double(outcomes[true]) / double(games)<<endl; 
            return test_w;
        }
        else{
            // cout<<"wins: "<<outcomes[1]<<endl;
            // cout<<"losses: "<<outcomes[0]<<endl;
            test_w += 30;
        }
    }
}

int main(){
    srand(time(NULL));
    int flip;
    vector<int> costs;
    vector<int> goals;
    vector<int> wallets;

    ofstream myfile;
    
    double thres = 0.9;
    int cost_init = 10, cost_final = 23;
    int goal_init = 10, goal_final = 100;
    int games = 100;

    for(int cost = cost_init; cost < cost_final; cost++){
        int init_w = 10;
        for(int goal = goal_init; goal < goal_final; goal += 10){
            int calc = find_wallet(cost, init_w, goal, thres, games);
            init_w = calc;
            costs.push_back(cost);
            goals.push_back(goal);
            wallets.push_back(calc);
        }
        cout<<"done cost: "<<cost<<endl;
    }

    myfile.open("values.txt");
    for(int i = 0; i < costs.size()-1; i++){
        cout<<costs[i]<<" ";
        myfile <<costs[i] <<" ";
    } 
    myfile<<costs[costs.size()-1]<<" done ";
    cout<<costs[costs.size()-1]<<" done ";

    for(int i = 0; i < goals.size()-1; i++){
        cout<<goals[i]<<" ";
        myfile <<goals[i] <<" ";
    } 
    myfile<<goals[goals.size()-1]<<" done ";
    cout<<goals[goals.size()-1]<<" done ";

    for(int i = 0; i < wallets.size()-1; i++){
        cout<<wallets[i]<<" ";
        myfile <<wallets[i] <<" ";
    } 
    myfile<<wallets[wallets.size()-1]<<" done ";
    cout<<wallets[wallets.size()-1]<<" done ";

    myfile.close();
    return 0;
}
