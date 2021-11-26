/*
  Titre      : la focntion du code
  Auteur     : Duvalier Tsagmo
  Date       : 25/11/2021
  Description: effectue les instructions programme
  Version    : 0.0.1
*/

#include <iostream>
#include <iomanip>

//Declaration des fonctions
int LireValiderEntierEntre(int min1, int max1)
{
    int dureeSejour = 0;
    cin >> dureeSejour;

    while (!cin || dureeSejour <= 1 || dureeSejour >= 14)
    {
        cin.clear();
        cin.ignore();
        cout << "Votre entree est incorrecte . S.V.P. reesayez : ";
        cin >> dureeSejour;
    }
    return dureeSejour;
}

int LireValider2Char(char typeSejour1, char typeSejour2)
{
    char typeSejourF = NULL;
    cin >> typeSejourF;

    typeSejourF = toupper(typeSejourF);

    while (!cin || typeSejourF != 'R' && typeSejourF != 'T')
    {

        cin.clear();
        cin.ignore();
        cout << "Votre entree est incorrecte . S.V.P. reesayez : ";
        cin >> typeSejourF;

        typeSejourF = toupper(typeSejourF);
    }

    return typeSejourF;
}

int LireValiderEntierEntref(int min2, int max2)
{
    int nbreEnft = 0;
    cin >> nbreEnft;

    while (!cin || nbreEnft <= 0 || nbreEnft >= 12)
    {
        cin.clear();
        cin.ignore();
        cout << "Votre entree est incorrecte . S.V.P. reesayez : ";
        cin >> nbreEnft;
    }
    return nbreEnft;
}

int LireValiderEntierEntreg(int min, int max)
{
    int agEnf = 0;
    cin >> agEnf;

    while (!cin || agEnf <= 1 || agEnf >= 12)
    {
        cin.clear();
        cin.ignore();
        cout << "Votre entree est incorrecte . S.V.P. reesayez : ";
        cin >> agEnf;
    }

    return agEnf;
}

//fonction pour retourRabaitEnfant
double retourRabaisEnfant(int ageEnfant)
{

    double rabaisAccordef = 0.0;
    double retourRabaisEnfant = 0.0;

    if (ageEnfant <= 5)
        rabaisAccordef = 0.04;
    else if (ageEnfant <= 8)
        rabaisAccordef = 0.03;
    else
        rabaisAccordef = 0.02;

    retourRabaisEnfant = rabaisAccordef;

    return retourRabaisEnfant;
}

void afficheRecapitulatif(int nbreFacturef, double grandTotalf)
{

    cout << endl
         << endl
         << "\t\t\tCLUB MED " << endl
         << "\t\tRecapitulatif de la journee " << endl
         << endl
         << "Nombre de factures produites: " << nbreFacturef << endl
         << "Total des montants a payer: " << grandTotalf << " $" << endl
         << endl
         << endl;
}