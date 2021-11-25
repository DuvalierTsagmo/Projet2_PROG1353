/*
  Titre      : Production des factures
  Auteur     : Duvalier Tsagmo
  Date       : 24/11/2021
  Description: cree un programme qui cree le menu pour les factures
  Version    : 0.0.1
*/

#include <iostream>
#include <iomanip>
#include "fonction.h"

//Declaration des constantes
const double TAUX_TAXE = 0.15;
const int DUREE_MIN = 1;
const int DUREE_MAX = 14;
const int NBRE_ENF_MIN = 0;
const int NBRE_ENF_MAX = 12;
const char TYPE_SEJOUR1 = 'R';
const char TYPE_SEJOUR2 = 'T';
const int AGE_MIN = 1;
const int AGE_MAX = 12;

using namespace std;

//Prototypes des fonctions
int LireValiderEntierEntre(int min1, int max1);
int LireValider2Char(char typeSejour1, char typeSejour2);
int LireValiderEntierEntref(int min2, int max2);
int LireValiderEntierEntreg(int min, int max);
double retourRabaisEnfant(int ageEnfant);
void afficheRecapitulatif(int nbreFacture, double grandTotalFacture);

int main()
{
    //Declaration de variables
    int i = 0;
    char choix = NULL;
    string nomClient = "";
    char typeSejour = NULL;
    string nomSejour = "";
    int dureeSejour = 0;
    double tarifSejour = 0.0;
    int nbrEnfants = 0;
    int ageEnfant[12] = {0};
    double taxeTotal = 0.0;
    int nbreFacture = 0;
    double tarifRegulier = 0.0;
    double tarifInclus = 0.0;
    double rabaisAccorde = 0.0;
    double rabaisTotalAccorde = 0.0;
    double rabaisTotal = 0.0;
    double sousTotal = 0.0;
    double grandTotal = 0.0;        // grand total des  factures generees la journee.
    double grandTotalFacture = 0.0; // Le grand total d'une facture.

    //ENTREES DE DONNEES
    do
    {
        system("cls");

        cout << endl
             << endl
             << "FACTURATION CLUB MED " << endl
             << "1 - Entrer les informations pour produire une facture " << endl
             << "2 - Generer et afficher la facture " << endl
             << "3 - Afficher le recapitulatif de facturation pour la journee " << endl
             << "4 - Terminer le programme " << endl
             << "Entrez votre choix (1,2,3, ou 4) : ";
        cin >> choix;

        while (!cin || choix < '1' && choix > '4')
        {
            cin.clear();
            cin.ignore();
            cout << "Votre entree est incorrecte . S.V.P. reesayez : ";
            cin >> choix;
        }

        while (choix != '1' && choix != '4' && dureeSejour == 0)
        {
            system("cls");

            cin.clear();
            cin.ignore();

            cout << endl
                 << endl
                 << "Vous n'etes pas en mesure de traiter de l'information veuillez entrer les informations de facturation  en choissisant (1-): ";

            cin >> choix;
        }

        if (choix != '4')
        {
            system("cls");

            switch (choix)
            {
            case '1':
                cout << "=== ENTRER DES INFORMATIONS === " << endl
                     << endl
                     << endl
                     << "1 - Entrez le nom du client : ";
                cin >> nomClient;

                cout << "Entrez la duree du sejour (un nombre entier entre 1 et 14): ";
                dureeSejour = LireValiderEntierEntre(DUREE_MIN, DUREE_MAX);

                cout << "Entrer le  type de sejour (R - regulier ou T - tout inclus) : ";
                typeSejour = LireValider2Char(TYPE_SEJOUR1, TYPE_SEJOUR2);

                cout << endl
                     << endl
                     << "Entrez le nombre d'enfants (un nombre entier entre 0 et 12): ";
                nbrEnfants = LireValiderEntierEntref(NBRE_ENF_MIN, NBRE_ENF_MAX);

                for (i = 1; i <= nbrEnfants; i++)
                {

                    cout << "Entrez l'age (moins de 12) de l'enfant # " << i << " : ";
                    ageEnfant[i] = LireValiderEntierEntreg(AGE_MIN, AGE_MAX);
                }

                break;

            case '2':
                rabaisTotalAccorde = 0.0;

                if (dureeSejour <= 3)
                {
                    if (typeSejour == TYPE_SEJOUR1)
                        tarifRegulier = 250;
                    else
                        tarifInclus = 350;
                }
                else if (dureeSejour <= 7)
                {
                    if (typeSejour == TYPE_SEJOUR1)
                        tarifRegulier = 240;
                    else
                        tarifInclus = 340;
                }
                else
                {
                    if (typeSejour == TYPE_SEJOUR1)
                        tarifRegulier = 220;
                    else
                        tarifInclus = 320;
                }

                switch (typeSejour)
                {
                case 'R':
                    tarifSejour = tarifRegulier;
                    nomSejour = "Regulier";
                    break;
                default:
                    tarifSejour = tarifInclus;
                    nomSejour = "Tout inclus";
                    break;
                }

                tarifSejour *= dureeSejour;

                for (i = 1; i <= nbrEnfants; i++)
                {
                    rabaisAccorde = retourRabaisEnfant(ageEnfant[i]);
                    rabaisTotalAccorde += rabaisAccorde;
                }

                rabaisTotal = rabaisTotalAccorde * tarifSejour;
                sousTotal = tarifSejour - rabaisTotal;
                taxeTotal = TAUX_TAXE * sousTotal;
                grandTotalFacture = sousTotal + taxeTotal;

                cout << fixed << setprecision(2) << endl
                     << endl
                     << "\t\tCLUB MED FACTURE " << endl
                     << endl
                     << endl
                     << "Nom du client: " << nomClient << endl
                     << "Duree du sejour: " << dureeSejour << endl
                     << "Type de sejour: " << nomSejour << endl
                     << "Nombre d'enfants: " << nbrEnfants << endl
                     << "Cout du sejour : " << tarifSejour << " $" << endl
                     << endl
                     << "Rabais pour enfants "
                     << "(" << rabaisTotalAccorde * 100 << " %): " << rabaisTotal << " $" << endl
                     << endl
                     << "==================" << endl
                     << "Sous-total: " << sousTotal << " $" << endl
                     << "Taxe (" << TAUX_TAXE * 100 << " %):" << taxeTotal << "$" << endl
                     << "==================" << endl
                     << endl
                     << endl

                     << "Montant a payer: " << grandTotalFacture << " $" << endl
                     << endl
                     << endl;

                nbreFacture += 1;
                grandTotal += grandTotalFacture;

                break;

            default:

                afficheRecapitulatif(nbreFacture, grandTotal);

                break;
            }

            cout << endl
                 << endl
                 << "Appuyer sur une touche pour retourner au menu principal.";
            cin.clear();
            cin.ignore();
            getchar();
        }

    } while (choix != '4');

    cout << endl
         << endl
         << "Merci d'avoir utilise un logiciel de qualite cree par LogiProg inc. " << endl
         << endl;

    return (0);
}
