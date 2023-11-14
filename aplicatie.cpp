#include <iostream>
#include <string>

using namespace std;

class Masina
{
private:
	string marca;
	char* model;
	string nr_inmatriculare;
	static int total_masini_fabricate;

public:
	Masina(string _marca, const char* _model, string _nr_inmatriculare) : marca(_marca), nr_inmatriculare(_nr_inmatriculare)
	{
		this->model = new char[strlen(_model) + 1];
		strcpy_s(model, strlen(_model) + 1, _model);
		total_masini_fabricate++;
	}

	~Masina()
	{
		delete[] model;
	}

	Masina(const Masina& masina)
	{
		this->marca = masina.marca;
		this->nr_inmatriculare = masina.nr_inmatriculare;
		this->model = new char[strlen(masina.model) + 1];
		strcpy_s(model, strlen(masina.model) + 1, masina.model);
	}

	Masina& operator=(const Masina& masina)
	{
		if (this != &masina)
		{
			delete[] model;
			this->marca = masina.marca;
			this->nr_inmatriculare = masina.nr_inmatriculare;
			this->model = new char[strlen(masina.model) + 1];
			strcpy_s(model, strlen(masina.model) + 1, masina.model);
		}
		return *this;
	}

	string getMarca()
	{
		return marca;
	}
	
	char* getModel()
	{
		char* tmp = new char[strlen(model) + 1];
		strcpy_s(tmp, strlen(model) + 1, model);
		return tmp;
	}

	string getNr_inmatriculare()
	{
		return nr_inmatriculare;
	}

	void setMarca(string _marca)
	{
		marca = _marca;
	}

	void setModel(const char* _model)
	{
		delete[] model;
		this->model = new char[strlen(_model) + 1];
		strcpy_s(model, strlen(_model) + 1, _model);
	}

	static void incrementNrMasini()
	{
		Masina::total_masini_fabricate++;
	}

	static int getTotalMasiniFabricate()
	{
		return total_masini_fabricate;
	}
};

int Masina::total_masini_fabricate = 0;

int main()
{
	Masina m("Dacia", "Spring", "B123AAA");
	Masina::incrementNrMasini();
	Masina m1("Ford", "Focus", "IF123BBB");
	Masina::incrementNrMasini();

	cout << "Total masini fabricate: " << Masina::getTotalMasiniFabricate() << endl;
	
	Masina m2 = m1;
	Masina m3("Dacia", "Logan", "IS123CCC");;
	return 0;
}