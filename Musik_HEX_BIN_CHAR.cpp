// Musik_HEX_BIN_CHAR.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms. //

#include <iostream>					// Auslesen und Schreiben in Standard-Streams 
#include <filesystem>				// Zugriff auf Funktionen die Informationen zu Pfaden, Dateien und Verzeichnissen enthalten
#include <fstream>					// Definiert mehrere Klassen, die iostreams-Vorgänge für Sequenzen unterstützen, die in externen Dateien gespeichert sind
#include <vector>					// Standardbibliotheksvektorklasse für Sequenzcontainer
#include <bitset>					// unterstützt Vorgänge für Objekte vom Typ Bitset, die eine Auflistung von Bits enthalten, und bieten konstanten Zeitzugriff auf die einzelnen Bits
#include <iomanip>					// verschiedene Manipulatoren, die jeweils ein einzelnes Argument verwenden

namespace fs = std::filesystem;

// Unterprogramm zum Verschieben der txt Datei in den Projektordner HEX
void moveFileToHexFolder() {
	std::string currentPath = fs::current_path().string();
	std::string musicFilePath = currentPath + "/Audio_To_Hex.txt";
	std::string hexFolderPath = currentPath + "/HEX/Audio_To_Hex.txt";

	// Verschiebe die Musikdatei in den HEX-Ordner
	if (fs::exists(musicFilePath)) {
		// Erstelle den HEX-Ordner, falls er nicht existiert
		if (!fs::exists(currentPath + "/HEX")) {
			fs::create_directory(currentPath + "/HEX");
			std::cout << "DER ORDNER HEX WURDE IM PROGRAMMORDNER DES EDITORS ERFOLGREICH ERSTELLT." << std::endl;
		}

		// Verschiebe die Musikdatei in den HEX-Ordner
		fs::rename(musicFilePath, hexFolderPath);
		std::cout << "DIE DATEI Audio_To_Hex.txt WURDE ERFOLGREICH IN DEN HEX ORDNER VERSCHOBEN.\n" << std::endl;
	}
	else {
		std::cerr << "DIE DATEI Audio_To_Hex.txt EXISTIERT NICHT IM AKTUELLEN VERZEICHNIS.\nDAS PROGRAMM WIRD GESCHLOSSEN! BEGINNEN SIE BITTE VON VORNE!\n\n" << std::endl;
	}
}						
// Unterprogramm zum Verschieben der txt Datei in den Projektordner BIN
void moveFileToBINFolder() {
	std::string currentPath = fs::current_path().string();
	std::string musicFilePath = currentPath + "/Audio_To_Binary.txt";
	std::string BINFolderPath = currentPath + "/BIN/Audio_To_Binary.txt";

	// Verschiebe die Musikdatei in den BIN-Ordner
	if (fs::exists(musicFilePath)) {
		// Erstelle den BIN-Ordner, falls er nicht existiert
		if (!fs::exists(currentPath + "/BIN")) {
			fs::create_directory(currentPath + "/BIN");
			std::cout << "DER ORDNER BIN WURDE IM PROGRAMMORDNER DES EDITORS ERFOLGREICH ERSTELLT." << std::endl;
		}

		// Verschiebe die Musikdatei in den HEX-Ordner
		fs::rename(musicFilePath, BINFolderPath);
		std::cout << "DIE DATEI Audio_To_Binary.txt WURDE ERFOLGREICH IN DEN BIN ORDNER VERSCHOBEN.\n" << std::endl;
	}
	else {
		std::cerr << "DIE DATEI Audio_To_Binary.txt EXISTIERT NICHT IM AKTUELLEN VERZEICHNIS.\nDAS PROGRAMM WIRD GESCHLOSSEN! BEGINNEN SIE BITTE VON VORNE!\n\n" << std::endl;
	}
}
// Unterprogramm zum Verschieben der txt Datei in den Projektordner CHAR
void moveFileToCharFolder() {
	std::string currentPath = fs::current_path().string();
	std::string musicFilePath = currentPath + "/Audio_To_CHAR.txt";
	std::string CharFolderPath = currentPath + "/CHAR/Audio_To_CHAR.txt";

	// Verschiebe die Musikdatei in den CHAR-Ordner
	if (fs::exists(musicFilePath)) {
		// Erstelle den CHAR-Ordner, falls er nicht existiert
		if (!fs::exists(currentPath + "/CHAR")) {
			fs::create_directory(currentPath + "/CHAR");
			std::cout << "DER ORDNER CHAR WURDE IM PROGRAMMORDNER DES EDITORS ERFOLGREICH ERSTELLT." << std::endl;
		}

		// Verschiebe die Musikdatei in den HEX-Ordner
		fs::rename(musicFilePath, CharFolderPath);
		std::cout << "DIE DATEI Audio_To_CHAR.txt WURDE ERFOLGREICH IN DEN CHAR ORDNER VERSCHOBEN.\n" << std::endl;
	}
	else {
		std::cerr << "DIE DATEI Audio_To_CHAR.txt EXISTIERT NICHT IM AKTUELLEN VERZEICHNIS.\nDAS PROGRAMM WIRD GESCHLOSSEN! BEGINNEN SIE BITTE VON VORNE!\n\n" << std::endl;
	}
}


int main() {
	// Deklaration der Variablen
	std::string folderName = "HEREIN MIT DER MP3";
	std::string folderNameBin = "BIN";
	std::string folderNameChar = "CHAR";
	std::string folderNameHex = "HEX";
	int x = 0; int Ausgabe = 0;
	int b = 0; int c = 0; int h = 0;

	std::cout << "HERZLICH WILLKOMMEN BEIM MUSIK - BIN - CHAR - HEX - EDITOR" << std::endl;
	std::cout << "**********************************************************\n" << std::endl;

	std::cout << "WURDEN DIE PROJEKTORDNER BIN, CHAR UND HEX SOWIE DER ORDNER, IN DEN DIE MP3 HINEINGELEGT WIRD SCHON ERSTELLT?\n" << std::endl;
	std::cout << "1 = JA / 2 = NEIN	: ";
	std::cin >> x;
	//scanf_s("%i", &x);

	if (x == 1 || x == 2)				// Abfrage auf eine gültige Auswahl
	{
		if (x == 2)						// Abfragen auf Erstellvorgang und bei Nichtvorhandensein das Erstellen der Projektordner HEX, BIN, CHAR und dem MP3 Ordner
		{
			if (!fs::exists(folderName)) {
				fs::create_directory(folderName);
				fs::create_directory(folderNameBin);
				fs::create_directory(folderNameChar);
				fs::create_directory(folderNameHex);
				std::cout << "\nDER ORDNER '" << folderName << "' WURDE IM PROGRAMMORDNER DES EDITORS ERFOLGREICH ERSTELLT.\nBITTE ZIEHEN SIE DIE MP3 IN DEN NEU ERSTELLTEN ORDNER UND BENENNEN SIE SIE MIT audio.mp3.\nDAS IST NOTWENDIG, UM VORHER DIE ZU BEARBEITENDE MUSIKDATEI DEM PROGRAMM EINDEUTIG ZUR VERFUEGUNG ZU STELLEN.\nWEITERS IST DIE BEARBEITUNGSDAUER VON DER DATEIGROESSE ABHAENGIG (BSP: 3,2MB = CA. 30 SEK)\n" << std::endl;
				std::cout << "\nDER ORDNER '" << folderNameBin << "' WURDE IM PROGRAMMORDNER DES EDITORS ERFOLGREICH ERSTELLT.\n" << std::endl;
				std::cout << "\nDER ORDNER '" << folderNameChar << "' WURDE IM PROGRAMMORDNER DES EDITORS ERFOLGREICH ERSTELLT.\n" << std::endl;
				std::cout << "\nDER ORDNER '" << folderNameHex << "' WURDE IM PROGRAMMORDNER DES EDITORS ERFOLGREICH ERSTELLT.\n\n" << std::endl;
			}
			else {
				std::cout << "\nDIE PROJEKTORDNER SOWIE DER ORDNER '" << folderName << "' EXISTIERT BEREITS IM PROGRAMMORDNER DES EDITORS.\nBITTE ZIEHEN SIE DIE MP3 IN DEN NEU ERSTELLTEN ORDNER UND BENENNEN SIE SIE MIT audio.mp3.\n DAS IST NOTWENDIG, UM VORHER DIE ZU BEARBEITENDE MUSIKDATEI DEM PROGRAMM EINDEUTIG ZUR VERFUEGUNG ZU STELLEN.\nWEITERS IST DIE BEARBEITUNGSDAUER VON DER DATEIGROESSE ABHAENGIG (BSP: 3,2MB = CA. 30 SEK)\n" << std::endl;
			}
		}

		std::cout << "\nIN WELCHES FORMAT SOLL DIE MP3 ZERLEGT WERDEN?\n" << std::endl;	// in welches Format soll die MP3 formatiert werden?
		std::cout << "1 = CHAR / 2 = BIN / 3 = HEX	: ";
		std::cin >> Ausgabe;
		//scanf_s("%i", &Ausgabe);
		if (Ausgabe == 1 || Ausgabe == 2 || Ausgabe == 3)								// Abfrage ob Eingabe gültig
		{
			std::ifstream mp3File("HEREIN MIT DER MP3/audio.mp3", std::ios::binary);	// Annahme: Die MP3-Datei heißt "audio.mp3" im neu angelegten Ordner HEREIN MIT DER MP3

			switch (Ausgabe) {															// Abhängig der Eingabe wird ... erledigt
			case 1:std::cout << "\n1 = audio.mp3 --> CHAR\n" << std::endl;

				if (mp3File) {
					char ch;

					// Exportiere die ASCII-Darstellung in eine .txt-Datei
					mp3File.clear();													// Zurücksetzen des Dateizeigers für erneutes Lesen
					mp3File.seekg(0);													// Setze den Dateizeiger auf den Anfang der Datei

					std::ofstream txtFile("Audio_To_CHAR.txt");							// öffnet eine Datei mit dem Namen „Audio_To_CHAR.txt“ zum Beschreiben; Danach liest es Zeichen nacheinander aus dem mp3File-Stream und speichert sie in der Variablen „ch“.
					while (mp3File.get(ch)) {											// Jedes aus der mp3File gelesene Zeichen wird in den txtFile-Stream geschrieben, der das Zeichen in die Datei schreibt, bis keine Zeichen mehr aus dem mp3File-Stream gelesen werden können
						txtFile << ch;
					}
					txtFile.close();													// Datei wird wieder geschlossen

					std::cout << "\nCHAR-DARSTELLUNG WURDE ERFOLGREICH IN Audio_To_CHAR.txt EXPORTIERT.\n\n" << std::endl;
				}
				else {
					std::cerr << "\nFEHLER BEIM OEFFNEN DER MP3-DATEI.\nBITTE VERGEWISSERN SIE SICH, DASS DIE MP3 IM `HEREIN MIT DER MP3`-ORDNER LIEGT UND MIT audio.mp3 BENANNT WURDE\n\n" << std::endl;
				}

				moveFileToCharFolder();													// Aufrufen des Unterprogramms zum Verschieben der Datei in den Ordner CHAR

				system("pause");														// warte auf Tastendruck
				return 0;



				break;
			case 2:std::cout << "\n2 = audio.mp3 --> BIN\n" << std::endl;

				if (mp3File) {
					// Lese den Inhalt der MP3-Datei in einen Vektor ein
					std::vector<char> buffer(std::istreambuf_iterator<char>(mp3File), {});

					// Exportiere die Binärdaten in eine .txt-Datei
					std::ofstream txtFile("Audio_To_Binary.txt");						// öffnet eine Datei mit dem Namen „Audio_To_Binary.txt“ zum Schreiben; Danach wird jedes Zeichen durchlaufen (Byte) im Puffer
					for (char byte : buffer) {											// Für jedes Byte, wandelt es das Zeichen in eine binäre Darstellung von 8 Bits um; 
						txtFile << std::bitset<8>(byte) << " ";							// Die binäre Darstellung wird in die Datei geschrieben
					}
					txtFile.close();													// Datei wird geschlossen

					std::cout << "\nBINAERDATEN ERFOLGREICH IN Audio_To_Binary.txt EXPORTIERT.\n\n" << std::endl;
				}
				else {
					std::cerr << "\nFEHLER BEIM OEFFNEN DER MP3-DATEI.\nBITTE VERGEWISSERN SIE SICH, DASS DIE MP3 IM `HEREIN MIT DER MP3`-ORDNER LIEGT UND MIT audio.mp3 BENANNT WURDE\n\n" << std::endl;
				}
				moveFileToBINFolder();													// Aufrufen des Unterprogramms zum Verschieben der Datei in den Ordner BIN
				system("pause");
				return 0;
				break;
			case 3:std::cout << "\n3 = audio.mp3 --> HEX\n" << std::endl;

				if (mp3File) {
					// Hexadezimale Darstellung in der Konsole ausgeben
					unsigned char byte;

					// Exportiere die hexadezimale Darstellung in eine .txt-Datei
					mp3File.clear();																				// Zurücksetzen des Dateizeigers für erneutes Lesen
					mp3File.seekg(0);																				// Setze den Dateizeiger auf den Anfang der Datei

					std::ofstream txtFile("Audio_To_Hex.txt");														// Öffnet einen Dateistream mit dem NamentxtFilezum Schreiben in die Datei „Audio_To_Hex.txt“
					while (mp3File.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {							// Liest Daten von der mp3-Datei in eine Byte Variable, bis das Ende der Datei erreicht ist.
						txtFile << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";	// Schreibt den ganzzahligen Wert vom Byte zum txtFileStream im Hexadezimalformat mit einer Breite von 2 Zeichen und wenn notwendig führenden Nullen.
					}
					txtFile.close();																				// Schließt die Datei, nachdem alle Daten geschrieben wurden.

					std::cout << "\nHEXADEZIMALE DARSTELLUNG ERFOLGREICH IN Audio_To_hex.txt EXPORTIERT.\n\n" << std::endl;
				}
				else {
					std::cerr << "\nFEHLER BEIM OEFFNEN DER MP3-DATEI.\nBITTE VERGEWISSERN SIE SICH, DASS DIE MP3 IM `HEREIN MIT DER MP3`-ORDNER LIEGT UND MIT audio.mp3 BENANNT WURDE\n\n" << std::endl;
				}

				moveFileToHexFolder();																				// Aufrufen des Unterprogramms zum Verschieben der Datei in den Ordner HEX

				system("pause");
				return 0;
				break;
			default: std::cout << "\nDIE EINGABE IST UNGUELTIG! DAS PROGRAMM WIRD GESCHLOSSEN! BEGINNEN SIE BITTE VON VORNE!\n\n" << std::endl;
			}

		}
		else {
			std::cout << "\nDIE EINGABE IST UNGUELTIG! DAS PROGRAMM WIRD GESCHLOSSEN! BEGINNEN SIE BITTE VON VORNE!\n\n" << std::endl;
		}
	}
		else {
			std::cout << "\nDIE EINGABE IST UNGUELTIG! DAS PROGRAMM WIRD GESCHLOSSEN! BEGINNEN SIE BITTE VON VORNE!\n\n" << std::endl;
		}
		system("pause");
		return 0;
	
}