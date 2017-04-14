//NIM dabs okt�ber 1997 <-- holy shit
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

//�etta fall � a� birta st��u allra eldsp�tnahr�gna (hr�gur � fleirt�lu eignarfalli)
void birta( int* hruga );

//�etta fall � a� reikna �t hversu margar eldsp�tur eru eftir � hr�gunum:
int samtals( int* hruga );

//�etta fall l�tur t�lvuna gera:
void tolva( int* hruga );

//�etta fall l�tur notandann gera:
void notandi( int* hruga );

//�etta fall birtir reglurnar � spilinu:
void hjalp( );

//�etta fall spilar spili�:
void spila( );

//�g leyfi m�r a� nota eina v��v�ra breytu af �v� a� forriti� notar alltaf
//mismargar hr�gur � hvert og eitt skipti:
int hrugufjoldi;

//H�r byrjar a�alforriti�:
int main( )
{
	int val;
	do
	{
		cout << endl << endl;
		cout << "        __  __  ______               " << endl;
		cout << "       /\\ \\/\\ \\/\\__  _\\   /'\\_/`\\    " << endl;
		cout << "       \\ \\ `\\\\ \\/_/\\ \\/  /\\      \\   " << endl;
		cout << "        \\ \\ , ` \\ \\ \\ \\  \\ \\ \\__\\ \\  " << endl;
		cout << "         \\ \\ \\`\\ \\ \\_\\ \\__\\ \\ \\_/\\ \\ " << endl;
		cout << "          \\ \\_\\ \\_\\/\\_____\\\\ \\_\\\\ \\_\\" << endl;
		cout << "           \\/_/\\/_/\\/_____/ \\/_/ \\/_/" << endl;
		cout << "                                     " << endl;
		cout << "                - you just got pwnd  " << endl;
		cout << "                                     " << endl << endl;
		cout << "                ADALVALMYND " << endl << endl;
		cout << "                      1. Spila NIM" << endl;
		cout << "                      2. Birta reglurnar i NIM" << endl;
		cout << "                      3. Haetta " << endl << endl;
		cout << "                      Veldu 1, 2 eda 3:" << endl << endl;
		cin >> val;
		switch ( val )
		{
		case 1:
			spila( );
			break;
		case 2:
			hjalp( );
			break;
		case 3:
			break;
		}
	}
	while ( val != 3 );

	return 0;
}

void spila( )
{
	cout << "*-------------------------------------------------------*" << endl;
	cout << "                   NU SPILUM VID NIM!!" << endl;
	cout << "*-------------------------------------------------------*" << endl;
	cout << endl << endl;
	cout << "Sladu inn fjolda hruga (0 til ad fa slembitolu): ";

	srand( time( 0 ) );

	cin >> hrugufjoldi;
	hrugufjoldi = hrugufjoldi <= 0 ? ( (rand( ) % 8 ) + 2 ) : hrugufjoldi;
	cout << "Vid spilum med " << hrugufjoldi << " hrugur. " << endl;

	int* hruga = new int[ hrugufjoldi ];
	for ( int i = 0; i < hrugufjoldi; i++ )
	{
		hruga[ i ]=( ( rand( ) % 14 ) + 1 );
	}

	cout << endl;
	birta ( hruga );

	do
	{
		notandi( hruga );
		birta( hruga );
		tolva( hruga );
		birta( hruga );
	}
	while ( samtals( hruga ) );

	delete[] hruga;
}

void hjalp( )
{
	cout << "              UM NIM - LEIKINN " << endl << endl;
	cout << "Leikurinn NIM er upprunninn fra Asiu thar sem hann var" << endl;
	cout << "leikinn med steinvolum.  Reglurnar eru thessar: " << endl;
	cout << "Keppendur setja einhvern fjolda af eldspytum i hrugur " << endl;
	cout << "(their akveda sjalfir hve margar hrugur og hve margar " << endl;
	cout << "eldspytur i hverri hrugu) og skiptast svo a um ad " << endl;
	cout << "draga eldspytur ur einhverri hrugunni.  Their mega " << endl;
	cout << "taka eina eldspytu, nokkrar eda allar ur einni " << endl;
	cout << "hrugunni en their mega aldrei taka ur fleiri en " << endl;
	cout << "einni hrugu i einu.  Sa sem tekur sidustu eldspytuna " << endl;
	cout << "ur sidustu hrugunni vinnur.  Gangi ykkur vel! " << endl << endl;
	cout << "Sladu a einhvern lykil... " << endl;
	getchar( );
}

void birta( int* hruga )
{
	if( !samtals( hruga ) )
	{
		return;
	}
	cout << "                         Hruga nr.: ";
	for (int i = 0; i < hrugufjoldi; i++ )
	{
		cout << " " << (i + 1) << "  ";
	}

	cout << endl << endl;
	cout << "Fjoldi eldspytna i hverri hrugu er: ";
	for ( int c = 0; c < hrugufjoldi; c++ )
	{
		if( hruga[c] < 10 )
		{
			cout << " " << hruga[ c ] << "  ";
		}
		else
		{
			cout << hruga[ c ] << "  ";
		}
	}
	cout << endl << endl;
}

void notandi( int* hruga )
{
	if ( samtals( hruga ) == 0 )
	{
		return;
	}
	int eldspytur;
	int hrugunumer;
	do
	{
		cout << "Sladu inn hve margar eldspytur thu vilt taka: ";
		cin >> eldspytur;
		cout << endl;
		if( eldspytur < 1 )
		{
			cout << "Thu verdur ad taka a.m.k. eina eldspytu. Veldu aftur. " << endl << endl;
			continue;
		}
		cout << "Sladu inn ur hvada hrugu: ";
		cin  >> hrugunumer;
		if( hrugunumer > hrugufjoldi )
		{
			cout << "Thad er engin hruga med thessu numeri.  Veldu aftur." <<endl<<endl;
			continue;
		}
		if( eldspytur > hruga[ (hrugunumer) - 1 ] )
		{
			cout <<"Thad eru ekki nogu margar eldspytur eftir i hrugunni. Veldu aftur."<<endl<<endl;
			continue;
		}
	}
	while ( eldspytur > hruga[ (hrugunumer) - 1 ] || eldspytur < 1 );

	hruga[ hrugunumer - 1 ] -= eldspytur;
	if( !samtals( hruga ) )
	{
		cout << endl << "Thu vannst.  Til hamingju!" << endl << endl;
		cout << "Sladu a einhvern lykil... " << endl;
		getchar( );
	}
	cout << endl;
}

void tolva( int* hruga )
{
	if( samtals( hruga ) == 0 )
	{
		return;
	}

	int eldspytur;
	int hrugunumer;

	do
	{
		eldspytur = ( ( rand( ) % 14 ) + 1 );
		hrugunumer = ( ( rand( ) % hrugufjoldi ) + 1 );
		if( eldspytur > hruga[(hrugunumer)-1] )
		{
			continue;
		}
	}
	while ( eldspytur > hruga[ (hrugunumer) - 1 ] );

	if ( eldspytur > 1 )
	{
		cout << "      Eg tek " << eldspytur << " eldspytur ur hrugu nr. ";
	}
	else 
	{
		cout << "      Eg tek " << eldspytur << " eldspytu ur hrugu nr. ";
	}
	cout << hrugunumer << "." << endl;

	hruga[ (hrugunumer) - 1 ] -= eldspytur;
	if( !samtals( hruga ) )
	{
		cout << endl << "Eg vann.  Thad gengur bara betur naest!" << endl << endl;
		cout << "Sladu a einhvern lykil...   " << endl;
		getchar( );
	}
	cout << endl;
}

int samtals( int* hruga )
{
	int samtala = 0;
	for( int i = 0; i < hrugufjoldi; i++ )
	{
		samtala += hruga[ i ];
	}

	return samtala;
}
