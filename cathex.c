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

	// Datei öffnen
	fopen_s(&fp, dateiname, "r");

	// Prüfen, ob Datei geöffnet werden konnte
	if (fp == NULL)
		printf("Datei konnte nicht ge\x94 \bffnet werden.\n");
	else
	{
		do
		{
			zeichen = fgetc(fp);						// Zeichen einlesen
			zaehler++;									// Zeichenzähler erhöhen
			if (zeichen != EOF)							// Abfrage, ob das Dateiende erreicht wurde
			{
				printf("%02x ", abs(zeichen));			// Eingelesenes Zeichen als Hexadezimalzahl ausgeben
				if (0 == zaehler % 16)					// Zeilenumbruch nach 16 Zeichen
					printf("\n%08d: ", zaehler / 16);	// Zeilennummer ausgeben
			}
		} while (zeichen != EOF);						// Abfrage, ob das Dateiende erreicht ist
	}

	printf("\n\nDiese Datei enth\x84lt %d Zeichen.", zaehler);

	fclose(fp);											// Datei schließen
}