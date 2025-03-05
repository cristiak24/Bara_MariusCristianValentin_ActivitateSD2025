#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int anFabricatie;
	char* sofer;
	float kilometriiParcursi;
	char initialaProducator;
};

//initializare structura 
struct Masina initializare(int id, int anFabricatie, const char* sofer,
	float kilometriiParcursi, char initialaProducator)
{
	struct Masina m;
	m.id = id;
	m.anFabricatie = anFabricatie;
	m.sofer = (char*)malloc(strlen(sofer) + 1);
	strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
	m.kilometriiParcursi = kilometriiParcursi;
	m.initialaProducator = initialaProducator;
	return m;

}

//afisarea tuturor atributelor.
void afisare(struct Masina m) {
	printf("id: %d\n", m.id);
	printf("anFabricatie: %d\n", m.anFabricatie);
	printf("Sofer: %s\n", m.sofer);
	printf("KilometriiParcursi: %5.2f\n", m.kilometriiParcursi);
	printf("initialaProducator: %c\n", m.initialaProducator);
}

//modificarea unui atribut
void modifica_Sofer(struct Masina* m, const char* noulSofer) {
	if (strlen(noulSofer) > 2)
	{
		if (m->sofer != NULL) {
			free(m->sofer);
		}
		m->sofer = (char*)malloc(strlen(noulSofer) + 1);
		strcpy_s(m->sofer, strlen(noulSofer) + 1, noulSofer);
	}

}
//dezalocare campuri alocate dinamic
void dezalocare(struct Masina* m) {
	if (m->sofer != NULL) {
		free(m->sofer);
		m->sofer = NULL;
	}
}

int main() {
	struct Masina masina;
	masina = initializare(1, 2004, "Robert", 2000, 'P');// "P" afiseaza mai mult de un caracter
	afisare(masina);
	modifica_Sofer(&masina, "ion");
	afisare(masina);
	dezalocare(&masina);
	afisare(masina);
	return 0;
}