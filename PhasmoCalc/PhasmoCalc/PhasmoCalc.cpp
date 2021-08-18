#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;


int main()
{
	string json_path = "ghosts.json";
	json ghosts;
	ifstream ghost_file(json_path);
	
	if (ghost_file)
	{
		ghost_file >> ghosts;
		ghost_file.close();
	}
	else
	{
		ghosts = {
			{"Spirit", 0},
			{"Gespenst", 0},
			{"Phantom", 0},
			{"Poltergeist", 0},
			{"Banshee", 0},
			{"Dschinn", 0},
			{"Mare", 0},
			{"Revenant", 0},
			{"Shade", 0},
			{"Demon", 0},
			{"Yurei", 0},
			{"Oni", 0},
			{"Yokai", 0},
			{"Hantu", 0}
		};
		ofstream ghost_file(json_path);
		ghost_file << ghosts.dump(4);
		ghost_file.close();
	}
	while (true)
	{
		for (json::iterator i = ghosts.begin(); i != ghosts.end(); ++i)
		{
			cout << i.key() << " : " << i.value() << endl;
		}
		
	}
	return 1;
}

