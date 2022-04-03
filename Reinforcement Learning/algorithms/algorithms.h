#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class QLearning {
public:
	QLearning(const int &s, const int &r, const int &a); // s(states): number of states we would have, a: number of actions we would have, r(range): values the states can have
	std::vector<int> indexFromMulti(int one_dimensional_index, int nn, int depth);
	void QtableLogic(int nn, int s, int a); // nn = r/2
	void show() const;
	float getEpsilon() const; // epsilon is how much we want the agent to take random values
	void setEpsilon(float e);
	

private:
	const int c_state_size;
	const int c_action_size;
	const int c_range;

	std::map<std::vector<int>, std::vector<float>> c_q_table; //
	bool init;
	float epsilon;
	static double s_discount; // if gamma is small, small discounts
	const static int s_episodes = 10;
	static float s_eps_decay;
	static double s_learning_rate; // how much steps to take until update de data
};