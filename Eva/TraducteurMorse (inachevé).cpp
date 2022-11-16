//J'ai d'abord rédigé le code sur un émulateur C++ puis j'ai essayé de l'adapter au langage arduino
//Mais je ne sais pas comment tout écrire pour arduino (désolée du coup tout est un peu mélangé car c'est encore en cours)

#include <iostream> //(Inutile sur Arduino)
#include <string>
using namespace std;

string TraducteurMorse(char lettre) //Création d'une fonction pour traduire de l'alphabet classique en alphabet morse
{
	//Après avoir trouvé la commande switch-case-default j'ai décidé de l'utiliser a la place de nombreux "if"
  // pour tester les lettres et renvoyer la traduction morse d'une lettre 
	switch (lettre) {
	case 'a':
		return ".-";
	case 'b':
		return "-...";
	case 'c':
		return "-.-.";
	case 'd':
		return "-..";
	case 'e':
		return ".";
	case 'f':
		return "..-.";
	case 'g':
		return "--.";
	case 'h':
		return "....";
	case 'i':
		return "..";
	case 'j':
		return ".---";
	case 'k':
		return "-.-";
	case 'l':
		return ".-..";
	case 'm':
		return "--";
	case 'n':
		return "-.";
	case 'o':
		return "---";
	case 'p':
		return ".--.";
	case 'q':
		return "--.-";
	case 'r':
		return ".-.";
	case 's':
		return "...";
	case 't':
		return "-";
	case 'u':
		return "..-";
	case 'v':
		return "...-";
	case 'w':
		return ".--";
	case 'x':
		return "-..-";
	case 'y':
		return "-.--";
	case 'z':
		return "--..";
  case ' ':
  return "  ";
	}
}

void Codemorse(string mot) //Affichage caractère par caractère d'un mot/phrase en morse
{
	for (int i = 0; mot[i]; i++)
		cout << TraducteurMorse(mot[i]);
}


//Partie propre à arduino (allumage de la led)

void setup() {  //Setup pour la carte arduino
  Serial.begin (9600);
  pinMode (LED_BUILTIN, OUTPUT);
}

void loop() { //Faire s'allumer pour chaque . ou - à un temps plus ou moins long selon le mot
  for (int i=0; mot[i]; i++) { 
    if (TraducteurMorse(mot[i]) == ".") { //si on a un . on allume une durée donnée puis on eteint
      digitalWrite(LED_BUILTIN, HIGH); 
      delay (400);
      digitalWrite(LED_BUILTIN, LOW);
    }
    if (TraducteurMorse(mot[i]) == "-") { //si on a un - on allume une durée plus longue que pour . puis on éteint
      digitalWrite(LED_BUILTIN, HIGH); 
      delay(800);
      digitalWrite(LED_BUILTIN, LOW); 
      }
  } 
  Serial.print ("\n"); //separer chaque mot pour meilleure visibilité
}
