#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

json setup_json(json ghosts, string json_path);
void save(json ghosts, string json_path);

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
			ghosts = setup_json(ghosts, json_path);
		}
	}
	else
	{
		ghosts = setup_json(ghosts, json_path);
	}

	while (true)
	{
		for (json::iterator i = ghosts.begin(); i != ghosts.end(); ++i)
		{
			cout << i.key() << " : " << i.value() << endl;
		}
		string catched_ghost;
		cout << "\nWelchen Geist hast du gefangen? : ";
		cin >> catched_ghost;
		if (!ghosts.contains(catched_ghost))
		{
			cout << "\nDieser Geist existiert nicht! Bitte achte auf Gross- und Kleinschreibung.\n";
		}
		else
		{
			ghosts[catched_ghost] = ghosts[catched_ghost] + 1;
			save(ghosts, json_path);
			system("cls");
		}
	}
	return 0;
}

json setup_json(json ghosts, string json_path) {
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
	ofstream wghost_file(json_path);
	wghost_file << ghosts.dump(4);
	wghost_file.close();
	return ghosts;
};

void save(json ghosts, string json_path) {
	ofstream wghost_file(json_path);
	wghost_file << ghosts.dump(4);
	wghost_file.close();
};