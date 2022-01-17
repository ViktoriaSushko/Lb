#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

template<typename Tuple>
void printTupleOfThree(Tuple t) {
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ", "
        << get<2>(t) << ")" << endl;
}
auto get() {
	return  make_tuple("fred", 42);
}
struct Person {
	string name;
	uint32_t age;
	string city;
};

int main()
{
	setlocale(LC_ALL, "RU");
	int menu;
	srand(time(NULL));
	do {
		cout << "Выберите задание\n";
		cin >> menu;
		switch (menu) {
		case 1: {
			tuple<int, string> person(20, "Tim");
			cout << get<1>(person) << endl;
			get<1>(person) = "Vika";
			cout << get<1>(person) << endl;
			auto t = get();
			cout << get<0>(t)<<" : "<< get<1>(t)<< endl;

		}
			  break;
		case 2: {
			tuple<int, char, bool, float> thing;
			thing = make_tuple(23, 'H', true, 24.3);
			cout << get<0>(thing) << endl;
			cout << get<1>(thing) << endl;
			cout << get<2>(thing) << endl;
			cout << get<3>(thing) << endl;
		}
			  break;
		case 3: {
			tuple<int, double> t1 = make_tuple(1, 2.5);
			tuple<int, double> t2 = make_tuple(3, 4.5);
			t1.swap(t2);
			cout << get<0>(t1) << endl;
			cout << get<1>(t1) << endl;
			cout << get<0>(t2) << endl;
			cout << get<1>(t2) << endl;
			break;
		}
		case 4: {
			tuple<int, char> t1 = make_tuple(1, 'A');
			int x;
			char sym;
			tie(x, sym) = t1;
			cout << "x = " << x << ", s = " << sym << endl;

			//Структурированные привязка
			auto[name, age] = get();
			cout << name << " is " << age << endl;
			
			auto t2 = make_tuple(10, 20);
			auto& [first, second] = t2;
			first += 1;
			cout << "value is now " << get<0>(t2) << endl;

			Person p1{ "bill", 60, "New York" };
			auto [name, age, city] = p1;
			cout << name << "(" << age << ") lives in " << city << endl;

		}
			  break;
		case 5: {
			tuple<int, char> t1(20, 'T');
			tuple<char, string> t2('C', "Hello world");
			tuple<int, char, char, string> t3 = tuple_cat(t1, t2);//auto
			cout << get<0>(t3) << endl;
			cout << get<1>(t3) << endl;
			cout << get<2>(t3) << endl;
			cout << get<3>(t3) << endl;

		}
			  break;
		case 6: {
			vector<string> v1{ "one", "two", "three", "four", "five", "six" };
			vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
			vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

			auto t1 = make_tuple(v1[0], v1[1], v2[0]);
			auto t2 = make_tuple(v1[0], v1[1], v2[0], v3[0], v3[1]);
			printTupleOfThree(t1);
			printTupleOfThree(t2);
		}

			  break;


		}
	} while (menu != 0);

   

    return EXIT_SUCCESS;
}
