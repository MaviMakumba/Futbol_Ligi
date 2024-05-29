/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: PROJE ÖDEVİ
**				ÖĞRENCİ ADI...............: EREN KARTAL
**				ÖĞRENCİ NUMARASI.: B231210065
**				DERS GRUBU…………: A GRUBU 1. ÖĞRETİM
****************************************************************************/

//15 futbolcu 16 takım
//Tüm yabancı futbolcular Türk vatandaşlığı almıştır
// UYARI   Programın çalışma dinamiği Bu Hafta/Karşılaşma Kaydı/Puan Durumu/Sonraki Hafta   şeklindedir
// UYARI   Karşılaşma Kaydı her hafta sadece 1 kere çalıştırılmalıdır

#include<iostream>
#include<iomanip>		//setw() komutu kullanımı amacıyla eklenmiştir.
#include <conio.h>		//_getch() komutu kullanımı amacıyla eklenmiştir.
#include<fstream>		//Dosyalama işlemleri için eklenmiştir.
#include<string>
#include<algorithm>		//sort ile büyükten küçüğe sıralama /puan durumu

using namespace std;

class Futbolcu
{
public:

	string futbolcuAdi;
	string futbolcuSoyadi;
	string futbolcuLisansNo;
	string futbolcuMevki;
	string futbolcuDogumTarihi;
	string futbolcuTakimAdi;
	long long int futbolcuTcNo;
	int futbolcuMaas;



	Futbolcu() :futbolcuAdi("Belirsiz"), futbolcuSoyadi("Belirsiz"), futbolcuLisansNo("Belirsiz"), futbolcuMevki("Belirsiz"),
		futbolcuDogumTarihi("Belirsiz"), futbolcuTakimAdi("Belirsiz"), futbolcuTcNo(0), futbolcuMaas(0)
	{

	}

	Futbolcu(string fAd, string fSoyAd, string fLisans, string fMevki, string fDogumT, string fTakımAd, long long int fTc, int fMaas) :
		futbolcuAdi(fAd), futbolcuSoyadi(fSoyAd), futbolcuLisansNo(fLisans), futbolcuMevki(fMevki), futbolcuDogumTarihi(fDogumT),
		futbolcuTakimAdi(fTakımAd), futbolcuTcNo(fTc), futbolcuMaas(fMaas)
	{

	}

	void futbolcuEkle()
	{
		cin.ignore(); // Önceki girişten kalan new line karakterini temizle
		cout << " Futbolcu adı giriniz: " << endl; getline(cin, futbolcuAdi);
		cout << " Futbolcu soyadı giriniz: " << endl;  getline(cin, futbolcuSoyadi);
		cout << " Futbolcu lisans no giriniz: " << endl;   getline(cin, futbolcuLisansNo);
		cout << " Futbolcu mevki giriniz: " << endl;   getline(cin, futbolcuMevki);
		cout << " Futbolcu doğum tarihi giriniz: " << endl;  getline(cin, futbolcuDogumTarihi);
		cout << " Futbolcu takım adı giriniz: " << endl;  getline(cin, futbolcuTakimAdi);
		cout << " Futbolcu TC No giriniz: " << endl; cin >> futbolcuTcNo;
		cout << " Futbolcu maaşını giriniz: " << endl; cin >> futbolcuMaas;
	}

	void futbolcuListele();

};

class Takim
{


public:

	string takimAdi;
	string takimAdresi;
	string takimTelefon;
	string takimYonetici;
	int takimNo;
	int takimOyuncuSayisi;
	int puan = 0;


	Takim() :takimAdi("Belirsiz"), takimAdresi("Belirsiz"), takimTelefon("Belirsiz"), takimYonetici("Belirsiz"), takimNo(0), takimOyuncuSayisi(0)
	{

	}

	Takim(string tAdi, string tAdresi, string tTel, string tYonetici, int tNo, int tOyuncuSayisi)
	{
		takimAdi = tAdi;
		takimAdresi = tAdresi;
		takimTelefon = tTel;
		takimYonetici = tYonetici;
		takimNo = tNo;
		takimOyuncuSayisi = tOyuncuSayisi;
	}

	void takimOlustur()
	{
		cout << " Takım adı giriniz: "; cin >> takimAdi;
		cout << " Takım adresi giriniz: "; cin >> takimAdresi;
		cout << " Takım telefon numarası giriniz: "; cin >> takimTelefon;
		cout << " Takım yöneticisi ismini giriniz:  "; cin >> takimYonetici;
		cout << " Takım no giriniz:  "; cin >> takimNo;
		cout << " Takım oyuncu sayısını giriniz "; cin >> takimOyuncuSayisi;

	}

	void takimListele()
	{
		cout << " Takım Adı: "; cout << takimAdi << endl;
		cout << " Takım Adresi: "; cout << takimAdresi << endl;
		cout << " Takım Telefon Numarası: "; cout << takimTelefon << endl;
		cout << " Takım Yöneticisi İsmi:  "; cout << takimYonetici << endl;
		cout << " Takım No:  "; cout << takimNo << endl;
		cout << " Takımın Oyuncu Sayısı:  "; cout << takimOyuncuSayisi << endl << endl;
	}

};

Takim takimlar[100];						//Takımlar için 100 elemanlı bir dizi tanımlanmıştır.
Futbolcu futbolcular[600];					//Futbolcular için 600 elemanlı bir dizi tanımlanmıştır.

int c = 1;

void Futbolcu::futbolcuListele()
{

	cout << " Futbolcu Adı: "; cout << futbolcuAdi << endl;
	cout << " Futbolcu Soyadı: "; cout << futbolcuSoyadi << endl;
	cout << " Futbolcu Lisans No: "; cout << futbolcuLisansNo << endl;
	cout << " Futbolcu Mevki: "; cout << futbolcuMevki << endl;
	cout << " Futbolcu Doğum Tarihi: "; cout << futbolcuDogumTarihi << endl;
	cout << " Futbolcu Takım Adı: "; cout << futbolcuTakimAdi << endl;
	cout << " Futbolcu TC No: "; cout << futbolcuTcNo << endl;
	cout << " Futbolcu Maaşı: "; cout << futbolcuMaas << endl << endl;

}




int main()
{

	setlocale(LC_ALL, "Turkish");		//Türkçe dil desteği
	system("Color 30");					//Konsol ekranı renk ayarlanması

	takimlar[1] = Takim("Besiktas JK", "İstanbul/Beşiktaş", "0534 111 19 03", "Hasan Arat", 1, 15);
	takimlar[2] = Takim("Darica Genclerbirligi", "Kocaeli/Darıca", "0541 745 51 68", "Muzaffer Bıyık", 2, 15);
	takimlar[3] = Takim("Corum FK", "Çorum/Merkez", "0519 111 19 87", "Hakan Kartal", 3, 15);
	takimlar[4] = Takim("Tuzlaspor ", "İstanbul/Tuzla", "0534 111 19 54", "Faruk Özdin", 4, 15);
	takimlar[5] = Takim("Kocaelispor ", "Kocaeli / İzmit", "0541 111 19 66", "Tahir Büyükakın", 5, 15);
	takimlar[6] = Takim("Menemen FK ", "İzmir/Menemen", "0535 111 19 42", "Yılmaz Vural", 6, 15);
	takimlar[7] = Takim("Gebzespor ", "Kocaeli/Gebze", "0541 111 19 55", "İbrahim Büyükgöz", 7, 15);
	takimlar[8] = Takim("Genclerbirligi", "Ankara/Eryaman", "0506 111 19 23", "Behzat Çarşaf", 8, 15);
	takimlar[9] = Takim("Keciorengucu ", "Ankara/Keçiören", "0506 111 19 45", "Eylem Çetin", 9, 15);
	takimlar[10] = Takim("Konyaspor", "Konya/Selçuklu", "0542 111 19 22", "Sabiha Hanım", 10, 15);
	takimlar[11] = Takim("Cerkeslispor ", "Kocaeli/Dilovası", "0541 111 19 53", "Aytekin Muhtar", 11, 15);
	takimlar[12] = Takim("Martispor ", "Kocaeli/Darıca", "0541 111 20 17", "Hacı Yılmaz Erdoğan", 12, 15);
	takimlar[13] = Takim("Adanaspor ", "Adana/Sarıçam", "0506 676 19 54", "Maraz Ali", 13, 15);
	takimlar[14] = Takim("Kangal Termik Spor ", "Sivas/Kangal", "0558 319 19 67", "Ali Yıldız", 14, 15);
	takimlar[15] = Takim("Yeni Malatyaspor ", "Malatya/Battalgazi", "0544 123 19 86", "İlhan Bayi", 15, 15);
	takimlar[16] = Takim("Sanliurfaspor", "Şanlıurfa/Haliliye", "0563 444 19 69", "Sema Korkmaz", 16, 15);


	futbolcular[1] = Futbolcu("Eren", "Kartal", "1", "Santrafor", "3 Eylül 2005", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[2] = Futbolcu("Hakan", "Kartal", "2", "Santrafor", "10 Ağustos 1978", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[3] = Futbolcu("Ahmet", "Kartal", "3", "Santrafor", "10 Temmuz 1960", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[4] = Futbolcu("Erkan", "Kartal", "4", "Orta Saha", "19 Mayıs 1982", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[5] = Futbolcu("Gökhan", "Kartal", "5", "Orta Saha", "2 Mart 1985", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[6] = Futbolcu("Kaan", "Kartal", "6", "Orta Saha", "6 Şubat 1997", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[7] = Futbolcu("Mehmet", "Kartal", "7", "Orta Saha", "3 Ekim 1965", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[8] = Futbolcu("Emin", "Kartal", "8", "Orta Saha", "31 Ağustos 2001", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[9] = Futbolcu("Şahin", "Kartal", "9", "Defans", "4 Kasım 1990", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[10] = Futbolcu("Murat", "Kartal", "10", "Defans", "21 Ocak 1986", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[11] = Futbolcu("Yusuf", "Kartal", "11", "Defans", "31 Mart 2017", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[12] = Futbolcu("Tunahan", "Kartal", "12", "Defans", "28 Eylül 1992", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[13] = Futbolcu("Serdar", "Kartal", "13", "Defans", "7 Aralık 1992", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[14] = Futbolcu("Dursun", "Kartal", "14", "Kaleci", "1 Aralık 1965", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[15] = Futbolcu("Mustafa", "Kartal", "15", "Kaleci", "3 Kasım 1965", "Besiktas JK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[16] = Futbolcu("Muhammed", "Purut", "16", "Santrafor", "3 Kasım 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[17] = Futbolcu("İrşad", "Yapıcı", "17", "Santrafor", "3 Ekim 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[18] = Futbolcu("Ertuğrul", "Fırtına", "18", "Santrafor", "10 Mayıs 2002", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[19] = Futbolcu("İbrahim", "Büyükgöz", "19", "Santrafor", "5 Şubat 2004", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[20] = Futbolcu("Muzaffer", "Öztürk", "20", "Orta Saha", "8 Kasım 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[21] = Futbolcu("Furkan", "Altaş", "21", "Orta Saha", "21 Ekim 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[22] = Futbolcu("Muhammed", "Özçelik", "22", "Orta Saha", "17 Haziran 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[23] = Futbolcu("Görkem", "Göksu", "23", "Defans", "25 Haziran 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[24] = Futbolcu("Taha Yasin", "Fırtına", "24", "Defans", "30 Temmuz 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[25] = Futbolcu("Faruk", "Özdin", "25", "Defans", "27 Temmuz 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[26] = Futbolcu("Salih", "Malkoç", "26", "Defans", "31 Ağustos 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[27] = Futbolcu("Murathan", "Silan", "27", "Defans", "31 Mayıs 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[28] = Futbolcu("Coşkun", "Purut", "28", "Kaleci", "3 Kasım 1972", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[29] = Futbolcu("Enes", "Moğulkoç", "29", "Kaleci", "31 Mart 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[30] = Futbolcu("Muhammed", "Boğa", "30", "Kaleci", "4 Şubat 2005", "Darica Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[31] = Futbolcu("Veysel", "Demir", "31", "Santrafor", "13 Temmuz 1960", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[32] = Futbolcu("Halil", "Demir", "32", "Santrafor", "5 Nisan 1990", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[33] = Futbolcu("Halim", "Demir", "33", "Santrafor", " 5 Nisan 1990", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[34] = Futbolcu("Hami", "Demir", "34", "Santrafor", "5 Nisan 1990", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[35] = Futbolcu("Ahmet", "Kartal", "35", "Santrafor", "13 Aralık 1960", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[36] = Futbolcu("Abdullah", "Çatlı", "36", "Santrafor", "20 Temmuz 1975", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[37] = Futbolcu("Polat", "Alemdar", "37", "Santrafor", "21 Temmuz 1975", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[38] = Futbolcu("Necati", "Şaşmaz", "38", "Santrafor", "22 Temmuz 1975", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[39] = Futbolcu("Memati", "Keser", "39", "Santrafor", "23 Temmuz 1975", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[40] = Futbolcu("Gürkan", "Uygun", "40", "Santrafor", "24 Temmuz 1975", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[41] = Futbolcu("Abdül", "Hey", "41", "Santrafor", "25 Temmuz 1975", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[42] = Futbolcu("Osman", "Bakır", "42", "Orta Saha", "4 Şubat 1969", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[43] = Futbolcu("İsmail", "Zulüm", "43", "Defans", "5 Şubat 1969", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[44] = Futbolcu("Namık", "Tanca", "44", "Defans", "31 Aralık 1969", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[45] = Futbolcu("Kemal", "Diri", "45", "Kaleci", "31 Mart 1969", "Corum FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[46] = Futbolcu("Şadi", "Yazıcı", "46", "Santrafor", "13 Temmuz 1970", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[47] = Futbolcu("Emin", "Başgan", "47", "Santrafor", "18 Mart 1972", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[48] = Futbolcu("Engin", "Dızcı", "48", "Santrafor", "11 Eylül 2001", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[49] = Futbolcu("Faysal", "Dayım", "49", "Orta Saha", "21 Temmuz 1977", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[50] = Futbolcu("Şaman", "İmamoğlu", "50", "Orta Saha", "31 Mart 1955", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[51] = Futbolcu("Eker", "İlyas", "51", "Orta Saha", "1 Haziran 1980", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[52] = Futbolcu("Osman", "Alim", "52", "Orta Saha", "2 Şubat 1970", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[53] = Futbolcu("Kubat", "Otuz", "53", "Orta Saha", "28 Şubat 1985", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[54] = Futbolcu("Emin", "Sağlam", "54", "Defans", "1 Mart 2005", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[55] = Futbolcu("Engin", "Altay", "55", "Defans", "1 Temmuz 1985", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[56] = Futbolcu("Mahmut", "Tekdemir", "56", "Defans", "4 Şubat 1990", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[57] = Futbolcu("Ahmed", "Zalimov", "57", "Defans", "12 Ocak 1987", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[58] = Futbolcu("Mustafa", "Mıstık", "58", "Defans", "28 Ocak 1990", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[59] = Futbolcu("Malik", "Ada", "59", "Kaleci", "13 Temmuz 1969", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[60] = Futbolcu("Abbas", "Yanlı", "60", "Kaleci", "13 Temmuz 1985", "Tuzlaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[61] = Futbolcu("Emre", "Önen", "61", "Santrafor", "14 Ocak 2000", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[62] = Futbolcu("Orhan", "Pamuk", "62", "Santrafor", "11 Temmuz 2000", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[63] = Futbolcu("Osman", "Kamut", "63", "Santrafor", "13 Haziran 1970", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[64] = Futbolcu("Osman", "Çalık", "64", "Santrafor", "13 Mart 1990", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[65] = Futbolcu("Ali", "Kılınç", "65", "Orta Saha", "13 Temmuz 1970", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[66] = Futbolcu("Eren", "İnci", "66", "Orta Saha", "8 Aralık 2003", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[67] = Futbolcu("Görkem", "Şahin", "67", "Orta Saha", "13 Temmuz 1985", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[68] = Futbolcu("İlyas", "Güneş", "68", "Defans", "1 Temmuz 1970", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[69] = Futbolcu("Mustafa", "Ramazan", "69", "Defans", "4 Temmuz 1970", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[70] = Futbolcu("Mahir", "Ünal", "70", "Defans", "19 Temmuz 1970", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[71] = Futbolcu("Ünal", "Erdem", "71", "Defans", "20 Temmuz 1970", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[72] = Futbolcu("Erdem", "Onur", "72", "Defans", "21 Temmuz 1970", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[73] = Futbolcu("Itri", "Bayban", "73", "Defans", "13 Mart 1990", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[74] = Futbolcu("Kıtır", "Etmen", "74", "Kaleci", "13 Mayıs 1990", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[75] = Futbolcu("Orhan", "Veli", "75", "Kaleci", "13 Mayıs 1990", "Kocaelispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[76] = Futbolcu("Tarkan", "Tarkanoğlu", "76", "Santrafor", "3 Ocak 2006", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[77] = Futbolcu("Hami", "Mandıralı", "77", "Santrafor", "22 Şubat 2007", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[78] = Futbolcu("Ulvi", "Meymen", "78", "Orta Saha", "13 Mart 2005", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[79] = Futbolcu("Elyesa", "Baybars", "79", "Orta Saha", "7 Nisan 2001", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[80] = Futbolcu("Zekeriya", "Baybars", "80", "Orta Saha", "7 Şubat 2001", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[81] = Futbolcu("Zahit", "Arf", "81", "Orta Saha", "17 Aralık 1980", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[82] = Futbolcu("Arif", "Calut", "82", "Orta Saha", "27 Aralık 1990", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[83] = Futbolcu("Talut", "Kınkız", "83", "Orta Saha", "18 Mayıs 1990", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[84] = Futbolcu("Calut", "Maan", "84", "Defans", "31 Temmuz 1999", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[85] = Futbolcu("Zaha", "Lwai", "85", "Defans", "13 Temmuz 1998", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[86] = Futbolcu("Clint", "Cannaber", "86", "Defans", "17 Şubat 1999", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[87] = Futbolcu("Mohamed", "Alyunus", "87", "Defans", "24 Eylül 1999", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[88] = Futbolcu("Yunus Emre", "Saraç", "88", "Defans", "30 Temmuz 1979", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[89] = Futbolcu("Ali Uğur", "Erdoğan", "89", "Kaleci", "5 Kasım 1999", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[90] = Futbolcu("Seyit Emirhan", "Uçar", "90", "Kaleci", "6 Temmuz 1999", "Menemen FK", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[91] = Futbolcu("İlyas", "Salman", "91", "Santrafor", "11 Temmuz 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[92] = Futbolcu("Yücel", "Koç", "92", "Santrafor", "31 Mayıs 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[93] = Futbolcu("Dinçer", "Koç", "93", "Santrafor", "14 Temmuz 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[94] = Futbolcu("Kamil", "Koç", "94", "Santrafor", "15 Mart 1952", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[95] = Futbolcu("Ender", "Koç", "95", "Santrafor", "13 Temmuz 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[96] = Futbolcu("İbrahim", "Koç", "96", "Orta Saha", "13 Ocak 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[97] = Futbolcu("Aslan", "Koç", "97", "Orta Saha", "13 Temmuz 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[98] = Futbolcu("Hüdavendigar", "Ermiş", "98", "Orta Saha", "13 Temmuz 1940", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[99] = Futbolcu("Mahmut", "Koç", "99", "Defans", "20 Ağustos 1958", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[100] = Futbolcu("Kılınç", "Ersoy", "100", "Defans", "5 Temmuz 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[101] = Futbolcu("Batu", "Akkan", "101", "Defans", "31 Nisan 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[102] = Futbolcu("Ajdar", "Pekkan", "102", "Kaleci", "5 Nisan 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[103] = Futbolcu("Selman", "Seçkin", "103", "Kaleci", "11 Nisan 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[104] = Futbolcu("Mervan", "Yetkin", "104", "Kaleci", "21 Mayıs 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[105] = Futbolcu("Kerim", "Duran", "105", "Kaleci", "13 Ocak 1970", "Gebzespor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[106] = Futbolcu("Emre", "Konaldeğil", "106", "Orta Saha", "17 Mayıs 2003", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[107] = Futbolcu("Abdülkerim", "Önül", "107", "Santrafor", "13 Haziran 1971", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[108] = Futbolcu("Fettah", "Medah", "108", "Santrafor", "13 Haziran 1972", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[109] = Futbolcu("Lucifer", "Mil", "109", "Santrafor", "13 Haziran 1973", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[110] = Futbolcu("Mikail", "Öttür", "110", "Santrafor", "13 Temmuz 1974", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[111] = Futbolcu("Dursun Ali", "Erzincanlı", "111", "Santrafor", "16 Şubat 1999", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[112] = Futbolcu("Namık", "Koç", "112", "Santrafor", "13 Temmuz 2001", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[113] = Futbolcu("Emre", "Konal", "113", "Santrafor", "17 Mayıs 2003", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[114] = Futbolcu("Orhan", "Gencebay", "114", "Santrafor", "13 Şubat 2010", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[115] = Futbolcu("Müslüm", "Gürses", "115", "Santrafor", "30 Temmuz 2009", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[116] = Futbolcu("Azer", "Bülbül", "116", "Santrafor", "30 Temmuz 2008", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[117] = Futbolcu("Ferdi", "Tayfur", "117", "Santrafor", "22 Temmuz 2005", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[118] = Futbolcu("Selehattin", "Özdemir", "118", "Santrafor", "21 Temmuz 2005", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[119] = Futbolcu("Özgür", "Demirtaş", "119", "Santrafor", "21 Şubat 2006", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[120] = Futbolcu("Mansur", "Başgan", "120", "Santrafor", "13 Temmuz 1970", "Genclerbirligi", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[121] = Futbolcu("Ramiz", "Karaeski", "121", "Santrafor", "1 Nisan 2001", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[122] = Futbolcu("Sait Faik", "Abasıyanık", "122", "Santrafor", "2 Ocak 1970", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[123] = Futbolcu("Fyodor Mihayloviç", "Dostoyevski", "123", "Santrafor", "14 Temmuz 1970", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[124] = Futbolcu("Lev", "Tolstoy", "124", "Santrafor", "13 Temmuz 1990", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[125] = Futbolcu("Fyodor", "Ivanoviç", "125", "Santrafor", "13 Mart 1970", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[126] = Futbolcu("Prens", "Mışkin", "126", "Orta Saha", "17 Mayıs 1999", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[127] = Futbolcu("Petr", "Check", "127", "Orta Saha", "13 Temmuz 1979", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[128] = Futbolcu("Jackie", "Chen", "128", "Orta Saha", "6 Şubat 1989", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[129] = Futbolcu("Nejat", "İşler", "129", "Orta Saha", "4 Temmuz 1999", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[130] = Futbolcu("Hayati", "Kalınbaş", "130", "Orta Saha", "21 Temmuz 2001", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[131] = Futbolcu("Necmettin", "Kıllıgil", "131", "Defans", "13 Aralık 2001", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[132] = Futbolcu("Hüsamettin", "Dayı", "132", "Defans", "17 Temmuz 2000", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[133] = Futbolcu("Barış", "Akarsu", "133", "Defans", "3 Temmuz 2000", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[134] = Futbolcu("Cem", "Karaca", "134", "Defans", "13 Temmuz 2000", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[135] = Futbolcu("Amir", "Zayn", "135", "Kaleci", "3 Mayıs 1987", "Keciorengucu", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[136] = Futbolcu("Baybars", "Koç", "136", "Santrafor", "20 Ocak 1999", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[137] = Futbolcu("Sami", "Atılgan", "137", "Orta Saha", "22 Şubat 1999", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[138] = Futbolcu("Mali", "Koçar", "138", "Orta Saha", "14 Ocak 1999", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[139] = Futbolcu("Lütfi", "Nil", "139", "Orta Saha", "25 Şubat 1978", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[140] = Futbolcu("Hüseyin", "Çetin", "140", "Orta Saha", "28 Şubat 1979", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[141] = Futbolcu("Martin", "Luther", "141", "Orta Saha", "31 Mart 1970", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[142] = Futbolcu("Ryan", "Gosling", "142", "Defans", "31 Temmuz 1988", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[143] = Futbolcu("Timberlank", "Dan", "143", "Defans", "1 Ocak 1989", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[144] = Futbolcu("Bob", "Ross", "144", "Defans", "1 Temmuz 1988", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[145] = Futbolcu("Timothee", "Ho", "145", "Defans", "1 Ocak 1989", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[146] = Futbolcu("Wu", "Ju", "146", "Defans", "1 Mart 1989", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[147] = Futbolcu("Oryx", "Tuue", "147", "Defans", "2 Temmuz 2000", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[148] = Futbolcu("Felix", "Nigra", "148", "Kaleci", "22 Mayıs 2009", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[149] = Futbolcu("Phantom", "Dancer", "149", "Kaleci", "12 Temmuz 2009", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[150] = Futbolcu("Egx", "Xyar", "150", "Kaleci", "15 Nisan 2009", "Konyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[151] = Futbolcu("Faik", "Tur", "151", "Santrafor", "1 Temmuz 1999", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[152] = Futbolcu("Emre", "Karagöz", "152", "Santrafor", "1 Temmuz 1999", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[153] = Futbolcu("Sinancan", "Ateş", "153", "Santrafor", "24 Temmuz 1999", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[154] = Futbolcu("Onur", "Tarı", "154", "Santrafor", "15 Temmuz 1999", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[155] = Futbolcu("Tarık", "Akan", "155", "Santrafor", "15 Temmuz 1999", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[156] = Futbolcu("Cüneyt", "Arkın", "156", "Santrafor", "3 Temmuz 1999", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[157] = Futbolcu("Kamil", "Koçar", "157", "Orta Saha", "23 Temmuz 2000", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[158] = Futbolcu("Erdi", "Kızgır", "158", "Orta Saha", "30 Temmuz 2000", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[159] = Futbolcu("Ermiş", "Kapçar", "159", "Orta Saha", "31 Temmuz 2000", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[160] = Futbolcu("Ferdi", "Koç", "160", "Orta Saha", "1 Temmuz 2000", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[161] = Futbolcu("Halim", "Koç", "161", "Defans", "1 Temmuz 1970", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[162] = Futbolcu("Turan", "Koç", "162", "Defans", "3 Temmuz 1970", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[163] = Futbolcu("Diran", "Koç", "163", "Defans", "3 Temmuz 1970", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[164] = Futbolcu("Uğuray", "Koç", "164", "Kaleci", "13 Temmuz 1970", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[165] = Futbolcu("Göksu", "Koç", "165", "Kaleci", "13 Temmuz 1970", "Cerkeslispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[166] = Futbolcu("Bora", "Kor", "166", "Santrafor", "1 Temmuz 1980", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[167] = Futbolcu("Berkay", "Kür", "167", "Santrafor", "2 Temmuz 1981", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[168] = Futbolcu("Berke", "Kur", "168", "Santrafor", "3 Temmuz 1982", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[169] = Futbolcu("Barkın", "Kır", "169", "Santrafor", "4 Temmuz 1983", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[170] = Futbolcu("Berk", "Kar", "170", "Orta Saha", "5 Temmuz 1984", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[171] = Futbolcu("Burak", "Ker", "171", "Orta Saha", "6 Temmuz 1985", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[172] = Futbolcu("Burhan", "Kol", "172", "Orta Saha", "7 Temmuz 1986", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[173] = Futbolcu("Barış", "Kot", "173", "Orta Saha", "8 Temmuz 1987", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[174] = Futbolcu("Bilal", "Kon", "174", "Defans", "9 Temmuz 1988", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[175] = Futbolcu("Buğra", "Kap", "175", "Defans", "10 Temmuz 1989", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[176] = Futbolcu("Bela", "Küp", "176", "Defans", "11 Temmuz 1990", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[177] = Futbolcu("Makbul", "Kul", "177", "Defans", "12 Temmuz 1991", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[178] = Futbolcu("Bülent", "Kel", "178", "Defans", "13 Temmuz 1992", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[179] = Futbolcu("Nebati", "Liş", "179", "Kaleci", "14 Temmuz 1993", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[180] = Futbolcu("Necati", "Ateş", "180", "Kaleci", "15 Temmuz 1994", "Martispor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[181] = Futbolcu("Tommy", "Angelo", "181", "Santrafor", "10 Mart 2000", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[182] = Futbolcu("Vito", "Scaletta", "182", "Santrafor", "8 Ocak 2000", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[183] = Futbolcu("Joe", "Barbarov", "183", "Santrafor", "6 Şubat 2000", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[184] = Futbolcu("Vin", "Diesel", "184", "Santrafor", "23 Aralık 2000", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[185] = Futbolcu("Michael", "Corleone", "185", "Santrafor", "3 Eylül 2007", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[186] = Futbolcu("Sam", "Petter", "186", "Santrafor", "3 Eylül 2007", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[187] = Futbolcu("Alex", "Texeria", "187", "Santrafor", "15 Eylül 2005", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[188] = Futbolcu("Claude", "Bitta", "188", "Orta Saha", "14 Eylül 2005", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[189] = Futbolcu("Tom", "Hanks", "189", "Orta Saha", "13 Ekim 2004", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[190] = Futbolcu("Barry", "Allen", "190", "Orta Saha", "30 Ekim 1990", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[191] = Futbolcu("Neo", "Anderson", "191", "Orta Saha", "1 Ekim 1970", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[192] = Futbolcu("Keanu", "Reauves", "192", "Defans", "23 Ekim 1979", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[193] = Futbolcu("Emin", "Şimşir", "193", "Defans", "13 Ekim 1978", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[194] = Futbolcu("Pekka", "Drax", "194", "Defans", "1 Kasım 1968", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[195] = Futbolcu("Ümitcan", "Şeker", "195", "Kaleci", "31 Ekim 1999", "Adanaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[196] = Futbolcu("Kadir", "Pekmez", "196", "Santrafor", "15 Ekim 2006", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[197] = Futbolcu("Christian", "Atsu", "197", "Santrafor", "17 Ekim 2005", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[198] = Futbolcu("Naingolan", "Sweedish", "198", "Santrafor", "19 Temmuz 2001", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[199] = Futbolcu("Baba", "Yan", "199", "Orta Saha", "13 Temmuz 1989", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[200] = Futbolcu("Obi Van", "Kenobi", "200", "Orta Saha", "21 Temmuz 2000", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[201] = Futbolcu("Anakin", "Skywalker", "201", "Orta Saha", "24 Temmuz 1979", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[202] = Futbolcu("Jessie", "Pinkman", "202", "Orta Saha", "27 Kasım 2000", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[203] = Futbolcu("Cenk", "Öğretici", "203", "Orta Saha", "30 Temmuz 2000", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[204] = Futbolcu("Fakor", "Snakehead", "204", "Orta Saha", "1 Temmuz 1999", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[205] = Futbolcu("Erhur", "Muhit", "205", "Defans", "3 Kasım 1999", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[206] = Futbolcu("Bodyla", "Paris", "206", "Defans", "31 Aralık 1999", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[207] = Futbolcu("Olric", "Jannnsy", "207", "Defans", "7 Temmuz 1999", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[208] = Futbolcu("Ceg", "Hennsy", "208", "Defans", "7 Kasım 1998", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[209] = Futbolcu("Mac", "Arthur", "209", "Defans", "7 Temmuz 1980", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[210] = Futbolcu("Lütfi", "Koçluk", "210", "Kaleci", "9 Kasım 1980", "Kangal Termik Spor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[211] = Futbolcu("Fahri", "Koç", "211", "Santrafor", "1 Haziran 1999", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[212] = Futbolcu("Osman", "Egin", "212", "Santrafor", "2 Haziran 1998", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[213] = Futbolcu("Nihat", "Hatipoğlu", "213", "Orta Saha", "3 Mayıs 1978", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[214] = Futbolcu("Arslan", "Arslanbek", "214", "Orta Saha", "4 Temmuz 1988", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[215] = Futbolcu("Bahtiyar", "Zauynitdinov", "215", "Orta Saha", "5 Temmuz 1988", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[216] = Futbolcu("Fazıl", "Sayan", "216", "Orta Saha", "13 Haziran 1987", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[217] = Futbolcu("İlber", "Ortaylı", "217", "Orta Saha", "13 Mart 1988", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[218] = Futbolcu("Celal", "Şengör", "218", "Orta Saha", "13 Temmuz 1989", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[219] = Futbolcu("İsa", "Koç", "219", "Orta Saha", "21 Ağustos 2000", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[220] = Futbolcu("Musa", "Faal", "220", "Defans", "3 Ağustos 1967", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[221] = Futbolcu("Yahya", "Beyaz", "221", "Defans", "3 Mayıs 1989", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[222] = Futbolcu("Zekeriya", "Ak", "222", "Defans", "3 Şubat 1990", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[223] = Futbolcu("İdris", "Sarı", "223", "Defans", "1 Mart 1990", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[224] = Futbolcu("Süleyman", "Kara", "224", "Kaleci", "1 Temmuz 1990", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[225] = Futbolcu("Falisi", "Kızıl", "225", "Kaleci", "1 Mayıs 1990", "Yeni Malatyaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	futbolcular[226] = Futbolcu("Serdar", "Ortalı", "226", "Santrafor", "10 Mart 1999", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[227] = Futbolcu("Semih", "Cenk", "227", "Santrafor", "9 Ağustos 1999", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[228] = Futbolcu("Atıf", "Atılgan", "228", "Santrafor", "6 Mart 1998", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[229] = Futbolcu("Fred", "J", "229", "Orta Saha", "13 Eylül 2000", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[230] = Futbolcu("Muffasala", "Dyolujinoyu", "230", "Orta Saha", "3 Ekim 2001", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[231] = Futbolcu("Jamal", "Finger", "231", "Orta Saha", "31 Aralık 2001", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[232] = Futbolcu("Alonso", "Tran", "232", "Orta Saha", "13 Kasım 2001", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[233] = Futbolcu("Odin", "Ulhyr", "233", "Orta Saha", "13 Temmuz 2002", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[234] = Futbolcu("Faysal", "Lokama", "234", "Defans", "13 Şubat 2002", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[235] = Futbolcu("Lionella", "Farolli", "235", "Defans", "25 Haziran 1989", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[236] = Futbolcu("Hons", "Horsy", "236", "Defans", "25 Aralık 1988", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[237] = Futbolcu("Pedro", "Franco", "237", "Defans", "12 Ocak 1977", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[238] = Futbolcu("Enverico", "Daladier", "238", "Defans", "30 Mayıs 1989", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[239] = Futbolcu("Franz", "Joseph", "239", "Kaleci", "20 Nisan 1978", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);
	futbolcular[240] = Futbolcu("Adolf", "Kindy", "240", "Kaleci", "10 Temmuz 1999", "Sanliurfaspor", rand() % 99999999999 + 10000000000, rand() % 9999 + 1000);


	char tamamMidevamMi = 0;			//Bir işlemden sonra yeniden işlem yapabilmemizi sağlayan değişken 
	char dogruSecim = 0;				//Menü seçiminin başarılı/başarısız olduğunu bildirdiğimiz değişken
	int secim;							//Menü seçimi yapmamızı sağlayan değişken
	int takimSayisi = 16;				//Takım sayısını tutmak için kullanılan değişken
	int futbolcuSayisi = 240;			//Futbolcu sayısını tutmak için kullanılan değişken
	int numara;							//Sorgu değişkeni
	string snumara;						//Sorgu değişkeni 
	int hafta = 1;
	int a = 80;							//Kaçamak değişken
	int b = 350;						//Kaçamak değişken 2
	int x = 1;							//Karşılaşma kaydı dizi değişkeni 1
	int y = 1;							//Karşılaşma kaydı dizi değişkeni 2
	int f = 1;							//Puan durumu yazdırma değişkeni
	string girTakimAd;					//Sorgu değişkeni
	string girLisansNo;					//Sorgu değişkeni
	int randomSayilar[100];
	int randomSayilar2[100];
	string takimDizi1[100];
	string takimDizi2[100];
	int takimlarPuan[100];
	int skor1;
	int skor2;
	int randomSayi = 0;
	int randomSayi2 = 0;
	int sayac1 = 0;


	ofstream bilgiYazdirTakim;
	bilgiYazdirTakim.open("Takim.txt", ios::out | ios::trunc);	//ios::trunc program kapanıp bir daha açılınca sonradan eklenen verilerin silinmesine dolaylı olarak yarıyor
	for (int i = 1; i <= takimSayisi; i++)
	{
		bilgiYazdirTakim << takimlar[i].takimAdi << ' ' << takimlar[i].takimAdresi << ' ' << takimlar[i].takimTelefon << ' ' << takimlar[i].takimYonetici <<
			' ' << takimlar[i].takimNo << ' ' << takimlar[i].takimOyuncuSayisi << "\n";
	}
	bilgiYazdirTakim.close();


	ofstream bilgiYazdirFutbolcu;
	bilgiYazdirFutbolcu.open("futbolcu.txt", ios::out | ios::trunc);
	for (int i = 1; i <= futbolcuSayisi; i++)
	{
		bilgiYazdirFutbolcu << futbolcular[i].futbolcuAdi << ' ' << futbolcular[i].futbolcuSoyadi << ' ' << futbolcular[i].futbolcuLisansNo << ' ' <<
			futbolcular[i].futbolcuMevki << ' ' << futbolcular[i].futbolcuDogumTarihi << ' ' << futbolcular[i].futbolcuTakimAdi << ' ' <<
			futbolcular[i].futbolcuTcNo << ' ' << futbolcular[i].futbolcuMaas << "\n";
	}
	bilgiYazdirFutbolcu.close();


	do									//Sonraki işleme geçmeye yarayan döngü
	{
		do								//Ana menü seçimi
		{


			system("CLS");				//Konsol ekranı temizleme

			//Menü yazdırma

			cout << setw(5) << hafta << ".HAFTA" << setw(40) << " TAKIM MENÜ " << endl << endl;

			cout << setw(40) << "1-" << "Takım Oluşturma" << endl;
			cout << setw(40) << "2-" << "Takım Silme" << endl;
			cout << setw(40) << "3-" << "Takıma Futbolcu Ekleme" << endl;
			cout << setw(40) << "4-" << "Takımdan Futbolcu Silme" << endl;
			cout << setw(40) << "5-" << "Takımları Listeleme" << endl;
			cout << setw(40) << "6-" << "Takımdaki Futbolcuları Listeleme" << endl;
			cout << setw(40) << "7-" << "Takımdaki Bir Futbolcuyu Güncelleme" << endl;


			cout << endl << setw(50) << " OYUNCU MENÜ " << endl << endl;

			cout << setw(40) << "8-" << "Oyuncu Ekleme" << endl;
			cout << setw(40) << "9-" << "Oyuncu Silme" << endl;
			cout << setw(40) << "10-" << "Oyuncu Güncelleme" << endl;
			cout << setw(40) << "11-" << "Oyuncuları Listeleme" << endl;

			cout << endl << setw(50) << " GENEL MENÜ " << endl << endl;
			cout << setw(40) << "12-" << "Karşılaşma Kaydı" << endl;
			cout << setw(40) << "13-" << "Bu Hafta" << endl;
			cout << setw(40) << "14-" << "Puan Durumu" << endl;

			cout << setw(40) << "15-" << "Sonraki Haftaya Geç" << endl;
			cout << setw(40) << "16-" << "Çıkış" << endl << endl;

			cout << setw(50) << "Seçiminiz ?" << endl;
			cin >> secim;	//Seçim 

			tamamMidevamMi = 0;


			switch (secim)
			{

			case 1:		//Takım Oluşturma

				dogruSecim = 'd';
				system("CLS");

				takimSayisi++;
				takimlar[takimSayisi].takimOlustur();

				//txt doyasına yazdırma
				bilgiYazdirTakim.open("Takim.txt", ios::out | ios::app);	//out veri yazar app sonradan ekler
				bilgiYazdirTakim << takimlar[takimSayisi].takimAdi << ' ' << takimlar[takimSayisi].takimAdresi << ' ' << takimlar[takimSayisi].takimTelefon <<
					' ' << takimlar[takimSayisi].takimYonetici << ' ' << takimlar[takimSayisi].takimNo << ' ' << takimlar[takimSayisi].takimOyuncuSayisi << "\n";
				bilgiYazdirTakim.close();

				cout << setw(50) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();		//_getch() fonksiyonu ile kullanıcıdan bir tuşa basmasını istedik ve (void) sayesinde dönen değeri kullanmayacağımızı bildirdik.
				tamamMidevamMi = 't';

				break;


			case 2:		//Takım Silme

				dogruSecim = 'd';
				system("CLS");


				cout << "Silmek isteiğiniz takımın numarasını giriniz: " << endl; cin >> numara;
				for (int i = 0; i <= takimSayisi; i++)
				{
					if (numara == takimlar[i].takimNo)
					{
						cout << "Takım: " << takimlar[i].takimAdi << endl;
						takimlar[i] = takimlar[a];
						a++;
					}

					else
					{

					}
				}


				cout << setw(50) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;


			case 3:		//Takıma Oyuncu Ekleme

				dogruSecim = 'd';
				system("CLS");


				cout << "Oyuncu eklemek istediğiniz takımın numarasını giriniz: " << endl; cin >> numara;
				for (int i = 1; i <= takimSayisi; i++)
				{
					if (numara == takimlar[i].takimNo)
					{
						takimlar[i].takimOyuncuSayisi++;
						futbolcuSayisi++;
						futbolcular[futbolcuSayisi].futbolcuEkle();
					}
				}
				//txt doyasına yazdırma
				bilgiYazdirFutbolcu.open("futbolcu.txt", ios::out | ios::app);
				bilgiYazdirFutbolcu << futbolcular[futbolcuSayisi].futbolcuAdi << ' ' << futbolcular[futbolcuSayisi].futbolcuSoyadi << ' ' <<
					futbolcular[futbolcuSayisi].futbolcuLisansNo << ' ' << futbolcular[futbolcuSayisi].futbolcuMevki << ' ' <<
					futbolcular[futbolcuSayisi].futbolcuDogumTarihi << ' ' << futbolcular[futbolcuSayisi].futbolcuTakimAdi << ' ' <<
					futbolcular[futbolcuSayisi].futbolcuTcNo << ' ' << futbolcular[futbolcuSayisi].futbolcuMaas << "\n";
				bilgiYazdirFutbolcu.close();

				bilgiYazdirTakim.open("Takim.txt", ios::out | ios::trunc);	//ios::trunc program kapanıp bir daha açılınca sonradan eklenen verilerin silinmesine dolaylı olarak yarıyor
				for (int i = 1; i <= takimSayisi; i++)
				{
					bilgiYazdirTakim << takimlar[i].takimAdi << ' ' << takimlar[i].takimAdresi << ' ' << takimlar[i].takimTelefon << ' ' << takimlar[i].takimYonetici <<
						' ' << takimlar[i].takimNo << ' ' << takimlar[i].takimOyuncuSayisi << "\n";
				}
				bilgiYazdirTakim.close();

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';


				break;


			case 4:			//Takımdan futbolcu silme

				dogruSecim = 'd';
				system("CLS");

				cout << "Silmek isteiğiniz oyuncunun lisans numarasını giriniz: " << endl; cin >> snumara;
				for (int i = 1; i <= futbolcuSayisi; i++)
				{
					if (snumara == futbolcular[i].futbolcuLisansNo)
					{
						cout << "Futbolcu: " << futbolcular[i].futbolcuAdi <<" "<<futbolcular[i].futbolcuSoyadi<< endl;
						futbolcular[i] = futbolcular[b];
						b++;
					}

					else
					{

					}
				}

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';


				break;


			case 5:			//Takımları listeleme


				dogruSecim = 'd';
				system("CLS");

				cout << setw(50) << "TAKIM LİSTESİ " << endl << endl;
				for (int c = 1; c <= takimSayisi; c++)
				{
					if (takimlar[c].takimNo == 0)
					{

					}
					else
					{
						takimlar[c].takimListele();
					}

				}

				cout << endl;

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;


			case 6:			//Takımdaki futbolcuları listeleme

				dogruSecim = 'd';
				system("CLS");

				cout << "Takım  adı giriniz: " << endl << endl;
				cin.ignore(); //getline'ı düzeltir
				getline(cin, girTakimAd); cout << endl;
				for (int i = 1; i <= futbolcuSayisi; i++)
				{
					if (girTakimAd == futbolcular[i].futbolcuTakimAdi)
					{
						futbolcular[i].futbolcuListele();
					}
				}

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 7:				//Takımdaki bir futbolcuyu güncelleme

				dogruSecim = 'd';
				system("CLS");
				cout << "Lisans no giriniz: " << endl << endl;
				cin.ignore(); //getline'ı düzeltir
				getline(cin, girLisansNo); cout << endl;
				for (int i = 1; i <= futbolcuSayisi; i++)
				{
					if (girLisansNo == futbolcular[i].futbolcuLisansNo)
					{
						cout << setw(50) << "Güncellenilecek Futbolcu" << endl << endl;
						futbolcular[i].futbolcuListele();
						cout << endl;
						futbolcular[i].futbolcuEkle();
					}
				}
				//txt doyasına yazdırma

				bilgiYazdirTakim.open("Takim.txt", ios::out | ios::trunc);	//ios::trunc program kapanıp bir daha açılınca sonradan eklenen verilerin silinmesine dolaylı olarak yarıyor
				for (int i = 1; i <= takimSayisi; i++)
				{
					bilgiYazdirTakim << takimlar[i].takimAdi << ' ' << takimlar[i].takimAdresi << ' ' << takimlar[i].takimTelefon << ' ' << takimlar[i].takimYonetici <<
						' ' << takimlar[i].takimNo << ' ' << takimlar[i].takimOyuncuSayisi << "\n";
				}
				bilgiYazdirTakim.close();


				bilgiYazdirFutbolcu.open("futbolcu.txt", ios::out | ios::trunc);
				for (int i = 1; i <= futbolcuSayisi; i++)
				{
					bilgiYazdirFutbolcu << futbolcular[i].futbolcuAdi << ' ' << futbolcular[i].futbolcuSoyadi << ' ' << futbolcular[i].futbolcuLisansNo << ' ' <<
						futbolcular[i].futbolcuMevki << ' ' << futbolcular[i].futbolcuDogumTarihi << ' ' << futbolcular[i].futbolcuTakimAdi << ' ' <<
						futbolcular[i].futbolcuTcNo << ' ' << futbolcular[i].futbolcuMaas << "\n";
				}
				bilgiYazdirFutbolcu.close();

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 8:				//Oyuncu Ekleme

				dogruSecim = 'd';
				system("CLS");


				cout << "Oyuncu eklemek istediğiniz takımın numarasını giriniz: " << endl; cin >> numara;
				for (int i = 1; i <= takimSayisi; i++)
				{
					if (numara == takimlar[i].takimNo)
					{
						takimlar[i].takimOyuncuSayisi++;
						futbolcuSayisi++;
						futbolcular[futbolcuSayisi].futbolcuEkle();
					}
				}

				//txt doyasına yazdırma

				bilgiYazdirFutbolcu.open("futbolcu.txt", ios::out | ios::app);
				bilgiYazdirFutbolcu << futbolcular[futbolcuSayisi].futbolcuAdi << ' ' << futbolcular[futbolcuSayisi].futbolcuSoyadi << ' ' <<
					futbolcular[futbolcuSayisi].futbolcuLisansNo << ' ' << futbolcular[futbolcuSayisi].futbolcuMevki << ' ' <<
					futbolcular[futbolcuSayisi].futbolcuDogumTarihi << ' ' << futbolcular[futbolcuSayisi].futbolcuTakimAdi << ' ' <<
					futbolcular[futbolcuSayisi].futbolcuTcNo << ' ' << futbolcular[futbolcuSayisi].futbolcuMaas << "\n";
				bilgiYazdirFutbolcu.close();

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 9:				//Oyuncu Silme

				dogruSecim = 'd';
				system("CLS");

				cout << "Silmek isteiğiniz oyuncunun lisans numarasını giriniz: " << endl; cin >> snumara;
				for (int i = 1; i <= futbolcuSayisi; i++)
				{
					if (snumara == futbolcular[i].futbolcuLisansNo)
					{
						cout << "Futbolcu: " << futbolcular[i].futbolcuAdi << " " << futbolcular[i].futbolcuSoyadi << endl;
						futbolcular[i] = futbolcular[b];
						b++;
					}

					else
					{

					}
				}

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 10:			//Oyuncu Güncelleme

				dogruSecim = 'd';
				system("CLS");
				cout << "Lisans no giriniz: " << endl << endl;
				cin.ignore(); //getline'ı düzeltir
				getline(cin, girLisansNo); cout << endl;
				for (int i = 1; i <= futbolcuSayisi; i++)
				{
					if (girLisansNo == futbolcular[i].futbolcuLisansNo)
					{
						cout << setw(50) << "Güncellenilecek Futbolcu" << endl << endl;
						futbolcular[i].futbolcuListele();
						cout << endl;
						futbolcular[i].futbolcuEkle();
					}
				}
				//txt doyasına yazdırma

				bilgiYazdirTakim.open("Takim.txt", ios::out | ios::trunc);	//ios::trunc program kapanıp bir daha açılınca sonradan eklenen verilerin silinmesine dolaylı olarak yarıyor
				for (int i = 1; i <= takimSayisi; i++)
				{
					bilgiYazdirTakim << takimlar[i].takimAdi << ' ' << takimlar[i].takimAdresi << ' ' << takimlar[i].takimTelefon << ' ' << takimlar[i].takimYonetici <<
						' ' << takimlar[i].takimNo << ' ' << takimlar[i].takimOyuncuSayisi << "\n";
				}
				bilgiYazdirTakim.close();


				bilgiYazdirFutbolcu.open("futbolcu.txt", ios::out | ios::trunc);
				for (int i = 1; i <= futbolcuSayisi; i++)
				{
					bilgiYazdirFutbolcu << futbolcular[i].futbolcuAdi << ' ' << futbolcular[i].futbolcuSoyadi << ' ' << futbolcular[i].futbolcuLisansNo << ' ' <<
						futbolcular[i].futbolcuMevki << ' ' << futbolcular[i].futbolcuDogumTarihi << ' ' << futbolcular[i].futbolcuTakimAdi << ' ' <<
						futbolcular[i].futbolcuTcNo << ' ' << futbolcular[i].futbolcuMaas << "\n";
				}
				bilgiYazdirFutbolcu.close();

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 11:			//Oyuncuları Listeleme

				dogruSecim = 'd';
				system("CLS");
				cout << setw(60) << "FUTBOLCU LİSTESİ " << endl << endl;
				cout << setw(50) << takimlar[1].takimAdi << " Oyuncuları" << endl;
				for (int c = 1; c <= futbolcuSayisi; c++)
				{
					futbolcular[c].futbolcuListele();
				}

				cout << endl;
				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 12:			//Karşılaşma Kaydı

				dogruSecim = 'd';
				system("CLS");

				
				for (int i = 1; i <= takimSayisi / 2; i++)
				{
					skor1 = rand() % 10 + 1;
					skor2 = rand() % 10;
					cout << setw(50) << takimDizi1[i] << " " << skor1 << "-" << skor2 << " " << takimDizi2[i] << endl;
					if (skor1 > skor2)
					{
						for (int k = 1; k <= takimSayisi; k++)
						{
							if (takimlar[k].takimAdi == takimDizi1[i])
							{
								takimlar[k].puan += 3;
								break;
							}
						}
					}

					else if (skor1 < skor2)
					{
						for (int k = 1; k <= takimSayisi; k++)
						{
							if (takimlar[k].takimAdi == takimDizi2[i])
							{
								takimlar[k].puan += 3;
								break;
							}
						}
					}

					else
					{
						for (int k = 1; k <= takimSayisi; k++)
						{
							if (takimlar[k].takimAdi == takimDizi2[i])
							{
								takimlar[k].puan++;
								break;
							}
						}

						for (int k = 1; k <= takimSayisi; k++)
						{
							if (takimlar[k].takimAdi == takimDizi1[i])
							{
								takimlar[k].puan++;
								break;
							}
						}
					}
				}

				for (int k = 1; k <= takimSayisi; k++)
				{
					takimlarPuan[k] = takimlar[k].puan;

				}

				cout << endl;
				cout << setw(70) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 13:			//Bu Hafta

				dogruSecim = 'd';
				system("CLS");
				srand(time(0));
			

				if (randomSayilar[1] == -858993460)		//başlangıç değeri (dizi boş mu kontrol)
				{
					for (int i = 1; i <= takimSayisi / 2; ++i)
					{

						do
						{
							randomSayi = rand() % takimSayisi / 2 + 1;
						} while (find(begin(randomSayilar), end(randomSayilar), randomSayi) != end(randomSayilar));

						int randomSayi2;
						do
						{
							randomSayi2 = rand() % (takimSayisi / 2) + (takimSayisi / 2) + 1;
						} while (find(begin(randomSayilar2), end(randomSayilar2), randomSayi2) != end(randomSayilar2));

						randomSayilar[i] = randomSayi;
						randomSayilar2[i] = randomSayi2;

						cout << endl;



					}

				}

				for (int i = 1; i <= takimSayisi / 2; i++)
				{
					int sayac1 = 0;
					do
					{
						sayac1++;
						if (randomSayilar[i] == takimlar[sayac1].takimNo)
						{
							cout << setw(50) << takimlar[sayac1].takimAdi << " vs ";
						}


					} while (randomSayilar[i] != takimlar[sayac1].takimNo);

					sayac1 = 0;

					do
					{
						sayac1++;
						if (randomSayilar2[i] == takimlar[sayac1].takimNo)
						{
							cout << takimlar[sayac1].takimAdi << endl;
						}


					} while (randomSayilar2[i] != takimlar[sayac1].takimNo);

				}


				x = 1;
				for (int i = 1; i <= takimSayisi/2; i++)
				{
					sayac1 =0 ;

					do
					{
						sayac1++;
						if (takimlar[sayac1].takimNo == randomSayilar[i])
						{
							takimDizi1[x] = takimlar[sayac1].takimAdi;
							x++;

						}



					} while (takimlar[sayac1].takimNo != randomSayilar[i]);

				}

				
				y = 1;
				for (int i = 1; i <= takimSayisi/2; i++)
				{
					sayac1 = 0;
					do
					{
						sayac1++;
						if (takimlar[sayac1].takimNo == randomSayilar2[i])
						{
							takimDizi2[y] = takimlar[sayac1].takimAdi;
							y++;

						}


					} while (takimlar[sayac1].takimNo != randomSayilar2[i]);

				}

				cout << endl << endl;
				cout << setw(70) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

			case 14:			//Puan Durumu

				dogruSecim = 'd';
				system("CLS");
				 f = 1;
				sort(begin(takimlarPuan), end(takimlarPuan), greater<int>());
				cout << setw(50) << "Puan Durumu" << endl << endl;
				for (int i = 0; i <= takimSayisi-1; i++)		//0. indise atadı sort
				{
					f = 0;
					do
					{
						f++;
						if (takimlarPuan[i] == takimlar[f].puan)
						{

							cout << i+1 << "- " << takimlar[i+1].takimAdi << " " << takimlarPuan[i] << endl;

						}
					} while (takimlarPuan[i] != takimlar[f].puan);
					
				}

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;


			case 15:		//Sonraki Hafta

				dogruSecim = 'd';
				system("CLS");
				hafta++;
				for (int i = 1; i <= takimSayisi; i++)		//dizilerin resetlenmesi
				{
					randomSayilar[i] = -858993460;
					randomSayilar2[i]= -858993460;
					takimDizi1[i]= -858993460;
					takimDizi2[i]= -858993460;
				}

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;


			case 16:		//Çıkış


				dogruSecim = 'd';
				cout << setw(50) << "Çıkış yapılıyor..." << endl;

				break;

			default:

				cout << setw(50) << "HATA" << endl << setw(60) << "Tekrar denemek için bir tuşa basınız" << endl;
				(void)_getch();
			}

		} while (dogruSecim == !'d');				//Ana menü seçimi

	} while (tamamMidevamMi == 't');			//Sonraki işleme geçiş


	return 0;
}