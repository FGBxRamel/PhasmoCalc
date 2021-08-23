#include <iostream>
#include <fstream>
#include "json.hpp"
#include <thread>
#include <chrono>

using namespace std;
using json = nlohmann::json;

json setup_json(string &json_path);

int main()
{
	string json_path = "ghosts.json";
	json ghosts;
	ifstream rghost_file(json_path);

	if (rghost_file)
	{
		try
		{
			rghost_file >> ghosts;
			rghost_file.close();
		}
		catch (nlohmann::detail::parse_error&)
		{
			ghosts = setup_json(json_path);
		}
	}
	else
	{
		ghosts = setup_json(json_path);
	}

	while (true)
	{
		int number = 0;
		for (auto i : ghosts.items())
		{
			number ++;
			cout << number << ". " << i.key() << " : " << i.value() << endl;
		}
		string catched_ghost;
		cout << "\nWelchen Geist hast du gefangen? : ";
		cin >> catched_ghost;
		if (!ghosts.contains(catched_ghost))
		{
			cout << "\nDieser Geist existiert nicht! Bitte achte auf Gross- und Kleinschreibung.\n";
			this_thread::sleep_for(chrono::seconds(3));
		}
		else
		{
			ghosts[catched_ghost] = ghosts[catched_ghost] + 1;
			ofstream wghost_file(json_path);
			wghost_file << ghosts.dump(4) << endl;
		}
		system("cls");
	}
	return 0;
}

json setup_json(string &json_path) {
	json ghosts = {
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
	ofstream wghost_file(json_path);
	wghost_file << ghosts.dump(4) << endl;
	return ghosts;
};