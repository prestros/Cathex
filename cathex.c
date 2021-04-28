// Programm zum Auslesen von Dateien und Ausgabe des Inhalts als Hexadezimalzahl
// Autor: Fabian Prestros
// Datum: 28.04.2021
#include <stdio.h>

void main()
{
	FILE* fp;
	char dateiname[255];
	char zeichen = { 0 };
	int zaehler = 0;

	// Dateiname einlesen
	printf("Bitte geben Sie den Dateinamen ein: ");
	gets_s(dateiname, 255);

	// Datei �ffnen
	fopen_s(&fp, dateiname, "r");

	// Pr�fen, ob Datei ge�ffnet werden konnte
	if (fp == NULL)
		printf("Datei konnte nicht ge\x94 \bffnet werden.\n");
	else
	{
		do
		{
			zeichen = fgetc(fp);						// Zeichen einlesen
			zaehler++;									// Zeichenz�hler erh�hen
			if (zeichen != EOF)							// Abfrage, ob das Dateiende erreicht wurde
			{
				printf("%02x ", abs(zeichen));			// Eingelesenes Zeichen als Hexadezimalzahl ausgeben
				if (0 == zaehler % 16)					// Zeilenumbruch nach 16 Zeichen
					printf("\n%08d: ", zaehler / 16);	// Zeilennummer ausgeben
			}
		} while (zeichen != EOF);						// Abfrage, ob das Dateiende erreicht ist
	}

	printf("\n\nDiese Datei enth\x84lt %d Zeichen.", zaehler);

	fclose(fp);											// Datei schlie�en
}