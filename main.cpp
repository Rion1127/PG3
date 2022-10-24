#include <stdio.h>
#include <list>
#include <iostream>

int main() {

	std::list<const char*> list
	{
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaa",
		"Shin - Okuo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsuco",
		"Shimbashi",
		"Yurakucho",
	};

	std::cout << "1970年" << "\n";
	for (auto itr = list.begin(); itr != list.end(); itr++) {
		std::cout << *itr << "\n";
	}
	//西日暮里を挿入する
	list.insert(std::next(list.begin(), 7), "Nishi - Nippori");

	std::cout << "\n2019年" << "\n";
	for (auto itr = list.begin(); itr != list.end(); itr++) {
		std::cout << *itr << "\n";
	}
	//高輪ゲートウェイを挿入する
	list.insert(std::next(list.begin(),25), "Takanawa - Gatway");
	std::cout << "\n2022年" << "\n";

	for (auto itr = list.begin(); itr != list.end(); itr++) {
		std::cout << *itr << "\n";
	}
	return 0;
}