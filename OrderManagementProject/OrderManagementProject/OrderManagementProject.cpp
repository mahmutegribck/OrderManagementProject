#include <iostream>
#include <iomanip>
#include <fstream>		// Dosyalama islemleri yapabilmek icin <fstream> kutuphanesi eklendi.


using namespace std;


struct urunBilgi	 // Urun bilgilerinin saklanacagi yapi olusturuldu.
{
	int kod, genelFiyat, ozelFiyat, stokAdedi, kdvOrani, temniSuresi;
	string ad, uretici, uretimTarihi;

} urun;

struct musteriBilgi		// Musteri bilgilerinin saklanacagi yapi olusturuldu.
{
	int firmaNo, musteriNo;
	string firmaAdi, firmaTelefonu, firmaSorumlusu, musteriKategorisi, adres;
} musteri;

struct siparisBilgi		 // Siparis bilgilerinin saklanacagi yapi olusturuldu.
{
	int siparisNo, firmaNo, siparisTutariGenel, siparisTutariOzel, urunAdedi;
	string siparisTarihi, siparisiAlan;
}siparis;



bool urun_kontrol(int urunKodu) // Islem yapilacak olan urunun kaydinin olup olmadigini bulmaya yarayan fonksiyon olusturuldu.
{
	bool kontrol = 0;	// Urun kodu kayitli degilse 0 degeri aliyor.
	ifstream dosyaOku;
	dosyaOku.open("urun.txt");

	while (!dosyaOku.eof())
	{
		dosyaOku >> urun.kod >> urun.ad >> urun.uretici >> urun.temniSuresi >> urun.uretimTarihi >> urun.genelFiyat >> urun.ozelFiyat >> urun.kdvOrani >> urun.stokAdedi;

		if (urun.kod == urunKodu)	// Urun kodu kayitli ise 1 degeri aliyor.
		{
			kontrol = 1;
		}
	}
	return kontrol;
};

bool musteri_kontrol(int musteriKodu) // Islem yapilacak olan musteri kaydinin olup olmadigini bulmaya yarayan fonksiyon olusturuldu.
{
	bool kontrol = 0;	// Musteri kodu kayitli degilse 0 degeri aliyor.
	ifstream dosyaOku;
	dosyaOku.open("musteri.txt");

	while (!dosyaOku.eof())
	{

		dosyaOku >> musteri.musteriNo >> musteri.firmaNo >> musteri.firmaAdi >> musteri.firmaTelefonu >> musteri.firmaSorumlusu >> musteri.musteriKategorisi >> musteri.adres;

		if (musteri.musteriNo == musteriKodu)	// Urun kodu kayitli ise 1 degeri aliyor.
		{
			kontrol = 1;
		}
	}
	return kontrol;
};

bool siparis_kontrol(int siparisKodu) // Islem yapilacak olan siparis kaydinin olup olmadigini bulmaya yarayan fonksiyon olusturuldu.
{
	bool kontrol = 0;	// Siparis kodu kayitli degilse 0 degeri aliyor.
	ifstream dosyaOku;
	dosyaOku.open("siparis.txt");

	while (!dosyaOku.eof())
	{

		dosyaOku >> siparis.siparisNo >> siparis.firmaNo >> siparis.siparisTutariGenel >> siparis.siparisTutariOzel >> siparis.urunAdedi >> siparis.siparisTarihi >> siparis.siparisiAlan;

		if (siparis.siparisNo == siparisKodu)	// Siparis kodu kayitli ise 1 degeri aliyor.
		{
			kontrol = 1;
		}
	}
	return kontrol;
};

int main()
{
	do
	{
		int secim = 0;
		int urunKodu = 0;
		int musteriKodu = 0;
		int siparisKodu = 0;				// Gerekli degiskenler atandi.


		char islem;

		cout << "  Ne Yapmak Istiyorsunuz ? " << endl
			<< "  1) Urun Ekle" << endl
			<< "  2) Urun Ara" << endl
			<< "  3) Urun Listele" << endl												//	Islem menusu olusturuldu.
			<< "  4) Urun Guncelle" << endl
			<< "  5) Urun Sil" << endl
			<< "  6) Musteri Ekle" << endl
			<< "  7) Musteri Ara" << endl
			<< "  8) Musteri Guncelle" << endl
			<< "  9) Musteri Sil" << endl
			<< "  10) Siparis Ekle" << endl
			<< "  11) Siparis Ara" << endl
			<< "  12) Siparis Sil" << endl
			<< "  13) Siparis Guncelle" << endl
			<< "  14) Siparis Listele" << endl;
		cout << "SECIM :";
		cin >> secim;
		cout << endl;


		if (secim < 1 || secim > 14)					// Secilen numaranin olmasi gereken araliktan secilmesi saglanir.
		{
			cout << endl;
			cout << "........HATALI ISLEM........" << endl;
			cout << endl;
		}

		if (secim == 1)
		{
			do {

				ofstream dosyayaz;
				dosyayaz.open("urun.txt", ios::app);

				cout << "Urun Ekle" << endl;
				cout << "Eklenmek Isteten Urun Kodu.....: "; cin >> urunKodu;
				cout << endl;

				if (urun_kontrol(urunKodu) == 1) // Kayit kontrol fonksiyonu cagirilarak urun kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Urun Koduna Ait Kayitli Urun Var!\n\a";
				}
				else
				{
					cout << "Girilen Koda Ait Urun Bulunamadi. Urun Girisi Yapabilirsiniz" << endl;
					cout << endl;
					urun.kod = urunKodu;
					cout << "Urun Kodu.............: ";	cin >> urun.kod;
					cout << "Urun Adi..............: ";	cin >> urun.ad;
					cout << "Urun Ureticisi........: ";	cin >> urun.uretici;
					cout << "Urun Temin Suresi(Ay).: ";	cin >> urun.temniSuresi;
					cout << "Urun Uretim Tarihi....: ";	cin >> urun.uretimTarihi;
					cout << "Urun Genel Fiyati.....: ";	cin >> urun.genelFiyat;
					cout << "Urun Ozel Fiyati......: ";	cin >> urun.ozelFiyat;
					cout << "Urun Kdv Orani........: ";	cin >> urun.kdvOrani;
					cout << "Urun Stok Adedi.......: ";	cin >> urun.stokAdedi;

					dosyayaz << urun.kod << "\t" << urun.ad << "\t" << urun.uretici << "\t" << urun.temniSuresi << "\t" << urun.uretimTarihi << "\t" << urun.genelFiyat << "\t" << urun.ozelFiyat << "\t" << urun.kdvOrani << "\t" << urun.stokAdedi << "\n";

					cout << endl;
					cout << "Urun Basarili Bir Sekilde Eklendi!\n";
				}
				dosyayaz.close();

				do {
					cout << "\nBaska Urun Ekleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Urun Ekleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 2)
		{
			do {
				cout << "Urun Ara" << endl;
				cout << "Aranamak Istenen Urun Kodu.....: "; cin >> urunKodu;
				cout << endl;
				ifstream dosyaoku;
				dosyaoku.open("urun.txt");

				if (urun_kontrol(urunKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak urun kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Urun Koduna Ait Kayit Bulunamadi.\n";
				}
				else
				{
					if (urun_kontrol(urunKodu) == 1) // Daha onceden urun kaydi yapilmis ise gosterir.
					{
						while (!dosyaoku.eof())
						{
							dosyaoku >> urun.kod >> urun.ad >> urun.uretici >> urun.temniSuresi >> urun.uretimTarihi >> urun.genelFiyat >> urun.ozelFiyat >> urun.kdvOrani >> urun.stokAdedi;
							if (urun.kod == urunKodu)
							{
								cout << "Urun Kodu.............: " << urun.kod << endl;
								cout << "Urun Adi..............: " << urun.ad << endl;
								cout << "Urun Ureticisi........: " << urun.uretici << endl;
								cout << "Urun Temin Suresi(Ay).: " << urun.temniSuresi << endl;
								cout << "Urun Uretim Tarihi....: " << urun.uretimTarihi << endl;
								cout << "Urun Genel Fiyati.....: " << urun.genelFiyat << endl;
								cout << "Urun Ozel Fiyati......: " << urun.ozelFiyat << endl;
								cout << "Urun Kdv Orani........: " << urun.kdvOrani << endl;
								cout << "Urun Stok Adedi.......: " << urun.stokAdedi << endl;
								break;
							}
						}
					}
					else
					{
						cout << "Urun Kaydi Bulunamadi!\a\n";
					}
				}
				dosyaoku.close();

				do {
					cout << "\nBaska Urun Arama Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Urun Arama Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 3)
		{
			do
			{
				ifstream dosyaoku;
				dosyaoku.open("urun.txt");

				while (true)
				{
					dosyaoku >> urun.kod >> urun.ad >> urun.uretici >> urun.temniSuresi >> urun.uretimTarihi >> urun.genelFiyat >> urun.ozelFiyat >> urun.kdvOrani >> urun.stokAdedi;

					if (dosyaoku.eof())	break; // En son kaydin 2 kere yapilmamasi icin eklendi.
					cout << urun.kod << "\t" << urun.ad << "\t" << urun.uretici << "\t" << urun.temniSuresi << "\t" << urun.uretimTarihi << "\t" << urun.genelFiyat << "\t" << urun.ozelFiyat << "\t" << urun.kdvOrani << "\t" << urun.stokAdedi << "\n";
				}
				dosyaoku.close();

				do {
					cout << "\nBaska Urun Listeleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Urun Listeleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 4)
		{
			do
			{
				cout << "Urun Duzenleme" << endl;
				cout << "Duzenlenmek Istenen Urun Kodu : "; cin >> urunKodu;
				cout << endl;
				ifstream dosyaoku;
				ofstream dosyayaz;
				dosyaoku.open("urun.txt");
				dosyayaz.open("urun_duzenle.txt", ios::app);

				bool kontrol = 0;

				if (urun_kontrol(urunKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak urun kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Urun Koduna Ait Urun Kaydi Bulunamadi!\n\a";
				}
				else
				{
					kontrol = 1;
					while (true)
					{
						dosyaoku >> urun.kod >> urun.ad >> urun.uretici >> urun.temniSuresi >> urun.uretimTarihi >> urun.genelFiyat >> urun.ozelFiyat >> urun.kdvOrani >> urun.stokAdedi;
						if (urun.kod == urunKodu)
						{

							cout << "Urun Kodu.............: " << urun.kod << endl;
							cout << "Urun Adi..............: " << urun.ad << endl;
							cout << "Urun Ureticisi........: " << urun.uretici << endl;
							cout << "Urun Temin Suresi(Ay).: " << urun.temniSuresi << endl;
							cout << "Urun Uretim Tarihi....: " << urun.uretimTarihi << endl;
							cout << "Urun Genel Fiyati.....: " << urun.genelFiyat << endl;
							cout << "Urun Ozel Fiyati......: " << urun.ozelFiyat << endl;
							cout << "Urun Kdv Orani........: " << urun.kdvOrani << endl;
							cout << "Urun Stok Adedi.......: " << urun.stokAdedi << endl;
							cout << endl;
							cout << "Yeni Urun Bilgilerini Giriniz...." << endl;
							cout << endl;
							cout << "Urun Kodu.............: ";	cin >> urun.kod;
							cout << "Urun Adi..............: ";	cin >> urun.ad;
							cout << "Urun Ureticisi........: ";	cin >> urun.uretici;
							cout << "Urun Temin Suresi(Ay).: ";	cin >> urun.temniSuresi;
							cout << "Urun Uretim Tarihi....: ";	cin >> urun.uretimTarihi;
							cout << "Urun Genel Fiyati.....: ";	cin >> urun.genelFiyat;
							cout << "Urun Ozel Fiyati......: ";	cin >> urun.ozelFiyat;
							cout << "Urun Kdv Orani........: ";	cin >> urun.kdvOrani;
							cout << "Urun Stok Adedi.......: ";	cin >> urun.stokAdedi;

							if (dosyaoku.eof())	break; // En son kaydin 2 kere yapilmamasi icin eklendi.
							dosyayaz << urun.kod << "\t" << urun.ad << "\t" << urun.uretici << "\t" << urun.temniSuresi << "\t" << urun.uretimTarihi << "\t" << urun.genelFiyat << "\t" << urun.ozelFiyat << "\t" << urun.kdvOrani << "\t" << urun.stokAdedi << "\n";

							urunKodu++;  // Bir sonraki kaydin kontrol edilmesi icin girilen kod arttirilir.
						}
						else
						{
							if (dosyaoku.eof())	break; // En son kaydin 2 kere yapilmamasi icin eklendi.
							dosyayaz << urun.kod << "\t" << urun.ad << "\t" << urun.uretici << "\t" << urun.temniSuresi << "\t" << urun.uretimTarihi << "\t" << urun.genelFiyat << "\t" << urun.ozelFiyat << "\t" << urun.kdvOrani << "\t" << urun.stokAdedi << "\n";
						}
					}
					dosyaoku.close();
					dosyayaz.close();

					if (kontrol == 1)  // Programda kayit varsa degisikliklerin dosya uzerine yazilmasi saglandi.
					{
						remove("urun.txt");
						rename("urun_duzenle.txt", "urun.txt");
						cout << endl;
						cout << "Urun  Bilgileri Basarili Bir Sekilde Guncellendi!\n";
						cout << endl;
					}
					else
					{
						remove("urun_duzenle.txt");
					}
				}
				do {
					cout << "\nBaska Urun Guncelleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Urun Guncelleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 5)
		{
			do
			{
				cout << "Urun Silme" << endl;
				cout << "Silinmek Istenen Urun Kodu : "; cin >> urunKodu;
				cout << endl;
				ifstream dosyaoku;
				ofstream dosyayaz;
				dosyaoku.open("urun.txt");
				dosyayaz.open("urun_sil.txt", ios::app);


				bool kontrol = 0;

				if (urun_kontrol(urunKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak urun kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Koda Ait Urun Kaydi Bulunamadi!\n\a";
				}
				else
				{
					kontrol = 1;
					while (!dosyaoku.eof())	//Silinen kayit haricindeki kayitlarin yeni dosyaya yazilmasi saglandi.
					{
						dosyaoku >> urun.kod >> urun.ad >> urun.uretici >> urun.temniSuresi >> urun.uretimTarihi >> urun.genelFiyat >> urun.ozelFiyat >> urun.kdvOrani >> urun.stokAdedi;

						if (urun.kod != urunKodu)
						{
							if (dosyaoku.eof())	break; // En son kaydin 2 kere yazilmasini onlemek icin eklendi.
							dosyayaz << urun.kod << "\t" << urun.ad << "\t" << urun.uretici << "\t" << urun.temniSuresi << "\t" << urun.uretimTarihi << "\t" << urun.genelFiyat << "\t" << urun.ozelFiyat << "\t" << urun.kdvOrani << "\t" << urun.stokAdedi << "\n";
						}
					}
				}
				dosyaoku.close();
				dosyayaz.close();

				if (kontrol == 1) // Programda kayit varsa degisikliklerin dosya uzerine yazilmasi saglandi.
				{
					remove("urun.txt");
					rename("urun_sil.txt", "urun.txt");
					cout << endl;
					cout << "Urun Kaydi Basarili Bir Sekilde Silindi!\n";
					cout << endl;
				}
				else
				{
					remove("urun_sil.txt");
				}
				do {
					cout << "\nBaska Urun Silme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;


					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Urun Silme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 6)
		{
			do
			{
				ofstream dosyayaz;
				dosyayaz.open("musteri.txt", ios::app);

				cout << "Mussteri Ekle" << endl;
				cout << "Eklenmek Istenen Musteri Kodu.....: "; cin >> musteriKodu;
				cout << endl;

				if (musteri_kontrol(musteriKodu) == 1)	// Kayit kontrol fonksiyonu cagirilarak musteri kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Musteri Koduna Ait Urun Kaydi Var!\n\a";
				}
				else
				{
					cout << "Girilen Musteri Koduna Ait Musteri Bulunamadi. Musteri Kaydi Yapabilirsiniz" << endl;
					musteri.musteriNo = musteriKodu;
					cout << endl;
					cout << "Musteri No............: ";		cin >> musteri.musteriNo;
					cout << "Firma No..............: ";		cin >> musteri.firmaNo;
					cout << "Firma Adi.............: ";		cin >> musteri.firmaAdi;
					cout << "Firma Telefonu........: ";		cin >> musteri.firmaTelefonu;
					cout << "Firma Sorumlusu.......: ";		cin >> musteri.firmaSorumlusu;
					cout << "Musteri Kategorisi....: ";		cin >> musteri.musteriKategorisi;
					cout << "Musteri Adresi........: ";		cin >> musteri.adres;


					dosyayaz << musteri.musteriNo << "\t" << musteri.firmaNo << "\t" << musteri.firmaAdi << "\t" << musteri.firmaTelefonu << "\t" << musteri.firmaSorumlusu << "\t" << musteri.musteriKategorisi << "\t" << musteri.adres << "\n";
					cout << endl;
					cout << "Musteri Basarili Bir Sekilde Eklendi!\n";
					cout << endl;

				}
				dosyayaz.close();

				do {
					cout << "\nBaska Musteri Ekleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Musteri Ekleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 7)
		{
			do
			{
				cout << "Musteri Ara" << endl;
				cout << "Aranmak Istenen Musteri Kodu.....: "; cin >> musteriKodu;
				cout << endl;

				ifstream dosyaoku;
				dosyaoku.open("musteri.txt");

				if (musteri_kontrol(musteriKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak musteri kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Koda Ait Musteri Kaydi Bulunamadi.\n";
				}
				else
				{
					if (musteri_kontrol(musteriKodu) == 1) // Daha onceden musteri eklenmis ise gosterir.
					{
						while (!dosyaoku.eof())
						{
							dosyaoku >> musteri.musteriNo >> musteri.firmaNo >> musteri.firmaAdi >> musteri.firmaTelefonu >> musteri.firmaSorumlusu >> musteri.musteriKategorisi >> musteri.adres;

							if (musteri.musteriNo == musteriKodu)
							{
								cout << "Musteri No..........: " << musteri.musteriNo << endl;
								cout << "Firma No............: " << musteri.firmaNo << endl;
								cout << "Firma Adi...........: " << musteri.firmaAdi << endl;
								cout << "Firma Telefonu......: " << musteri.firmaTelefonu << endl;
								cout << "Firma Sorumlusu.....: " << musteri.firmaSorumlusu << endl;
								cout << "Musteri Kategorisi..: " << musteri.musteriKategorisi << endl;
								cout << "Musteri Adresi......: " << musteri.adres << endl;
								break;
							}
						}
					}
					else
					{
						cout << "Musteri Kaydi Bulunamadi!\a\n";
					}
				}
				dosyaoku.close();

				do {
					cout << "\nBaska Musteri Arama Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Musteri Arama Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 8)
		{
			do
			{
				cout << "Musteri Duzenleme" << endl;
				cout << "Duzenlenmek Istenen Musteri Kodu : "; cin >> musteriKodu;
				cout << endl;

				ifstream dosyaoku;
				ofstream dosyayaz;
				dosyaoku.open("musteri.txt");
				dosyayaz.open("musteri_duzenle.txt", ios::app);

				bool kontrol = 0;

				if (musteri_kontrol(musteriKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak musteri kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Koda Ait Musteri Kaydi Bulunamadi !\n\a";
				}
				else
				{
					kontrol = 1;
					while (true)
					{
						dosyaoku >> musteri.musteriNo >> musteri.firmaNo >> musteri.firmaAdi >> musteri.firmaTelefonu >> musteri.firmaSorumlusu >> musteri.musteriKategorisi >> musteri.adres;

						if (musteri.musteriNo == musteriKodu)
						{
							cout << "Musteri No..........: " << musteri.musteriNo << endl;
							cout << "Firma No............: " << musteri.firmaNo << endl;
							cout << "Firma Adi...........: " << musteri.firmaAdi << endl;
							cout << "Firma Telefonu......: " << musteri.firmaTelefonu << endl;
							cout << "Firma Sorumlusu.....: " << musteri.firmaSorumlusu << endl;
							cout << "Musteri Kategorisi..: " << musteri.musteriKategorisi << endl;
							cout << "Musteri Adresi......: " << musteri.adres << endl;
							cout << endl;
							cout << "Yeni Musteri Bilgilerini Giriniz...." << endl;
							cout << endl;
							cout << "Musteri No..........: ";	cin >> musteri.musteriNo;
							cout << "Firma No............: ";	cin >> musteri.firmaNo;
							cout << "Firma Adi...........: ";	cin >> musteri.firmaAdi;
							cout << "Firma Telefonu......: ";	cin >> musteri.firmaTelefonu;
							cout << "Firma Sorumlusu.....: ";	cin >> musteri.firmaSorumlusu;
							cout << "Musteri Kategorisi..: ";	cin >> musteri.musteriKategorisi;
							cout << "Musteri Adresi......: ";	cin >> musteri.adres;

							if (dosyaoku.eof())	break; // En son kaydin 2 kere yazilmasini onlemek icin eklendi.
							dosyayaz << musteri.musteriNo << "\t" << musteri.firmaNo << "\t" << musteri.firmaAdi << "\t" << musteri.firmaTelefonu << "\t" << musteri.firmaSorumlusu << "\t" << musteri.musteriKategorisi << "\t" << musteri.adres << "\n";

							musteriKodu++;  // Bir sonraki kaydin kontrol edilmesi icin girilen kod arttirilir.
						}
						else
						{
							if (dosyaoku.eof())	break; // En son kaydin 2 kere yazilmasini onlemek icin eklendi.
							dosyayaz << musteri.musteriNo << "\t" << musteri.firmaNo << "\t" << musteri.firmaAdi << "\t" << musteri.firmaTelefonu << "\t" << musteri.firmaSorumlusu << "\t" << musteri.musteriKategorisi << "\t" << musteri.adres << "\n";
						}
					}
					dosyaoku.close();
					dosyayaz.close();

					if (kontrol == 1) // Programda kayit varsa degisikliklerin dosya uzerine yazilmasi saglandi.
					{
						remove("musteri.txt");
						rename("musteri_duzenle.txt", "musteri.txt");
						cout << "Musteri Bilgileri Guncellendi!\n";
					}
					else
					{
						remove("musteri_duzenle.txt");
					}
				}
				do {
					cout << "\nBaska Musteri Guncelleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Musteri Guncelleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 9)
		{
			do
			{
				cout << "Musteri Silme" << endl;
				cout << "Silinmek Istenen Musteri Kodu : "; cin >> musteriKodu;
				cout << endl;
				ifstream dosyaoku;
				ofstream dosyayaz;
				dosyaoku.open("musteri.txt");
				dosyayaz.open("musteri_sil.txt", ios::app);


				bool kontrol = 0;

				if (musteri_kontrol(musteriKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak musteri kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Musteri Koduna Ait Musteri Kaydi Bulunamadi!\n\a";
				}
				else
				{
					kontrol = 1;
					while (!dosyaoku.eof())	//Silinen kayit haricindeki kayitlarin yeni dosyaya yazilmasi saglandi.
					{
						dosyaoku >> musteri.musteriNo >> musteri.firmaNo >> musteri.firmaAdi >> musteri.firmaTelefonu >> musteri.firmaSorumlusu >> musteri.musteriKategorisi >> musteri.adres;

						if (musteri.musteriNo != musteriKodu)
						{
							if (dosyaoku.eof())	break; // En son kaydin 2 kere eklenmesini onlemek icin eklendi.
							dosyayaz << musteri.musteriNo << "\t" << musteri.firmaNo << "\t" << musteri.firmaAdi << "\t" << musteri.firmaTelefonu << "\t" << musteri.firmaSorumlusu << "\t" << musteri.musteriKategorisi << "\t" << musteri.adres << "\n";
						}
					}
				}
				dosyaoku.close();
				dosyayaz.close();

				if (kontrol == 1) // Programda kayit varsa degisikliklerin dosya uzerine yazilmasi saglandi.
				{
					remove("musteri.txt");
					rename("musteri_sil.txt", "musteri.txt");
					cout << endl;
					cout << "Musteri Kaydi Basarili Bir Sekilde Silindi!\n";
					cout << endl;
				}
				else
				{
					remove("musteri_sil.txt");
				}
				do {
					cout << "\nBaska Musteri Silme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\naska Musteri Silme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 10)
		{
			do
			{
				ofstream dosyayaz;
				ifstream dosyaoku;
				dosyaoku.open("urun.txt");
				dosyayaz.open("siparis.txt", ios::app);

				cout << "Siparis Ekle" << endl;
				cout << "Eklenmek Istenen Siparis Kodu.....: "; cin >> siparisKodu;
				cout << endl;
				cout << "Siparis Verilmek Istenen Urun Kodu.."; cin >> urunKodu;


				if (siparis_kontrol(siparisKodu) == 1) // Kayit kontrol fonksiyonu cagirilarak siparis kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Siparis Koduna Ait Siparis Kaydi Var!\n\a";
				}
				else
				{
					while (true)
					{
						dosyaoku >> urun.kod >> urun.ad >> urun.uretici >> urun.temniSuresi >> urun.uretimTarihi >> urun.genelFiyat >> urun.ozelFiyat >> urun.kdvOrani >> urun.stokAdedi;
						if (urun.kod == urunKodu)     //Siparis edilecek urunun fiyatlari urun.txt dosyasindan alinir.
						{
							cout << endl;
							cout << "Girilen Koda Ait Siparis Bulunamadi. Siparis Girisi Yapabilirsiniz" << endl;
							cout << endl;


							siparis.siparisNo = siparisKodu;

							cout << "Siparis No................: ";		cin >> siparis.siparisNo;
							cout << "Firma No..................: ";		cin >> siparis.firmaNo;
							cout << "Urun Adedi................: ";		cin >> siparis.urunAdedi;
							//Siparis ucreti(genel/ozel) urun.txt dosyasindan alinan urun fiyatlari ve girilen siparis edilecek urun adedi kullanilarak belirlenir.
							siparis.siparisTutariGenel = urun.genelFiyat * siparis.urunAdedi;
							siparis.siparisTutariOzel = urun.ozelFiyat * siparis.urunAdedi;

							cout << "Siparis Genel Fiyati......: " << siparis.siparisTutariGenel << endl;
							cout << "Siparis Ozel Fiyati.......: " << siparis.siparisTutariOzel << endl;

							cout << "Siparis Tarihi............: ";		cin >> siparis.siparisTarihi;
							cout << "Siparis Veren.............: ";		cin >> siparis.siparisiAlan;

							dosyayaz << siparis.siparisNo << "\t" << siparis.firmaNo << "\t" << siparis.siparisTutariGenel << "\t" << siparis.siparisTutariOzel << "\t" << siparis.urunAdedi << "\t" << siparis.siparisTarihi << "\t" << siparis.siparisiAlan << "\n";

							cout << endl;
							cout << "Siparis Basarili Bir Sekilde Eklendi!\n";
							cout << endl;
							//break;
						}
						else
						{
							cout << endl;
							cout << "Girilen Urun Koduna Ait Urun Bulunamadi" << endl;
							break;
						}
					}
				}
				dosyayaz.close();
				do {
					cout << "\nBaska Siparis Ekleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Siparis Ekleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 11)
		{
			do
			{
				cout << "Siparis Ara" << endl;
				cout << "Aranmak Istenen Siparis Kodu.....: "; cin >> siparisKodu;
				cout << endl;

				ifstream dosyaoku;
				dosyaoku.open("siparis.txt");

				if (siparis_kontrol(siparisKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak siparis kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Koda Ait Siparis Kaydi Bulunamadi.\n";
				}
				else
				{
					if (siparis_kontrol(siparisKodu) == 1) // Daha onceden siparis kaydi yapilmis ise gosterir.
					{
						while (!dosyaoku.eof())
						{
							dosyaoku >> siparis.siparisNo >> siparis.firmaNo >> siparis.siparisTutariGenel >> siparis.siparisTutariOzel >> siparis.urunAdedi >> siparis.siparisTarihi >> siparis.siparisiAlan;

							if (siparis.siparisNo == siparisKodu)
							{
								cout << "Siparis No.............: " << siparis.siparisNo << endl;
								cout << "Firma No...............: " << siparis.firmaNo << endl;
								cout << "Siparis Genel Fiyati...: " << siparis.siparisTutariGenel << endl;
								cout << "Siparis Ozel Fiyati....: " << siparis.siparisTutariOzel << endl;
								cout << "Urun Adedi.............: " << siparis.urunAdedi << endl;
								cout << "Siparis Tarihi.........: " << siparis.siparisTarihi << endl;
								cout << "Siparis Veren..........: " << siparis.siparisiAlan << endl;
								break;
							}
						}
					}
					else
					{
						cout << "Siparis Kaydi Bulunamadi!\a\n";
					}
				}
				dosyaoku.close();
				do {
					cout << "\nBaska Siparis Arama Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Siparis Arama Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 12)
		{
			do
			{
				ifstream dosyaoku;
				ofstream dosyayaz;
				dosyaoku.open("siparis.txt");
				dosyayaz.open("siparis_sil.txt", ios::app);

				cout << "Siparis Silme" << endl;
				cout << "Silinmek Istenen Siparis Kodu : "; cin >> siparisKodu;
				cout << endl;

				bool kontrol = 0;

				if (siparis_kontrol(siparisKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak siparis kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Koda Ait Siparis Kaydi Bulunamadi!\n\a";
				}
				else
				{
					kontrol = 1;
					while (!dosyaoku.eof()) //Silinen kayit haricindeki kayitlarin yeni dosyaya yazilmasi saglandi.
					{
						dosyaoku >> siparis.siparisNo >> siparis.firmaNo >> siparis.siparisTutariGenel >> siparis.siparisTutariOzel >> siparis.urunAdedi >> siparis.siparisTarihi >> siparis.siparisiAlan;

						if (siparis.siparisNo != siparisKodu)
						{
							if (dosyaoku.eof())	break; // En son kaydin 2 kere yapilmamsi saglandi.
							dosyayaz << siparis.siparisNo << "\t" << siparis.firmaNo << "\t" << siparis.siparisTutariGenel << "\t" << siparis.siparisTutariOzel << "\t" << siparis.urunAdedi << "\t" << siparis.siparisTarihi << "\t" << siparis.siparisiAlan << "\n";
						}
					}
				}
				dosyaoku.close();
				dosyayaz.close();

				if (kontrol == 1) // Programda kayit varsa degisikliklerin dosya uzerine yazilmasi saglandi.
				{
					remove("siparis.txt");
					rename("siparis_sil.txt", "siparis.txt");
					cout << endl;
					cout << "Siparis Kaydi Basarili Bir Sekilde Silindi!\n";
					cout << endl;
				}
				else
				{
					remove("siparis_sil.txt");
				}

				do {
					cout << "\nBaska Siparis Silme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Siparis Silme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 13)
		{
			do
			{
				ifstream dosyaoku;
				ofstream dosyayaz;
				dosyaoku.open("siparis.txt");
				dosyayaz.open("siparis_duzenle.txt", ios::app);

				cout << "Siparis Duzenleme" << endl;
				cout << "Duzenlenmek Istenen Siparis Kodu : "; cin >> siparisKodu;

				bool kontrol = 0;

				if (siparis_kontrol(siparisKodu) == 0) // Kayit kontrol fonksiyonu cagirilarak siparis kaydinin olup olmadigi sorgulandi.
				{
					cout << "Girilen Siparis Koduna Ait Siparis Kaydi Bulunamadi !\n\a";
				}
				else
				{
					kontrol = 1;
					while (true)
					{
						dosyaoku >> siparis.siparisNo >> siparis.firmaNo >> siparis.siparisTutariGenel >> siparis.siparisTutariOzel >> siparis.urunAdedi >> siparis.siparisTarihi >> siparis.siparisiAlan;
						if (siparis.siparisNo == siparisKodu)
						{
							cout << "Siparis No.............: " << siparis.siparisNo << endl;
							cout << "Firma No...............: " << siparis.firmaNo << endl;
							cout << "Siparis Genel Fiyati...: " << siparis.siparisTutariGenel << endl;
							cout << "Siparis Ozel Fiyati....: " << siparis.siparisTutariOzel << endl;
							cout << "Urun Adedi.............: " << siparis.urunAdedi << endl;
							cout << "Siparis Tarihi.........: " << siparis.siparisTarihi << endl;
							cout << "Siparis Veren..........: " << siparis.siparisiAlan << endl;
							cout << endl;
							cout << "Yeni Siparis Bilgilerini Giriniz." << endl;
							cout << endl;
							cout << "Siparis No..............: ";	cin >> siparis.siparisNo;
							cout << "Firma No................: ";	cin >> siparis.firmaNo;
							cout << "Siparis Genel Fiyati....: ";	cin >> siparis.siparisTutariGenel;
							cout << "Siparis Ozel Fiyati.....: ";	cin >> siparis.siparisTutariOzel;
							cout << "Urun Adedi..............: ";	cin >> siparis.urunAdedi;
							cout << "Siparis Tarihi..........: ";	cin >> siparis.siparisTarihi;
							cout << "Siparis Veren...........: ";	cin >> siparis.siparisiAlan;

							if (dosyaoku.eof())	break; // En son kaydin 2 kere yapilmamasi saglandi.
							dosyayaz << siparis.siparisNo << "\t" << siparis.firmaNo << "\t" << siparis.siparisTutariGenel << "\t" << siparis.siparisTutariOzel << "\t" << siparis.urunAdedi << "\t" << siparis.siparisTarihi << "\t" << siparis.siparisiAlan << "\n";

							siparisKodu++;  // Bir sonraki kaydin kontrol edilmesi icin girilen kod arttirilir.
						}
						else
						{
							if (dosyaoku.eof())	break; // En son kaydin 2 kere yapilmamsi saglandi.
							dosyayaz << siparis.siparisNo << "\t" << siparis.firmaNo << "\t" << siparis.siparisTutariGenel << "\t" << siparis.siparisTutariOzel << "\t" << siparis.urunAdedi << "\t" << siparis.siparisTarihi << "\t" << siparis.siparisiAlan << "\n";
						}
					}
					dosyaoku.close();
					dosyayaz.close();

					if (kontrol == 1) // Programda kayit varsa degisikliklerin dosya uzerine yazilmasi saglandi.
					{
						remove("siparis.txt");
						rename("siparis_duzenle.txt", "siparis.txt");
						cout << endl;
						cout << "Siparis Bilgileri Guncellendi!\n";
						cout << endl;
					}
					else
					{
						remove("siparis_duzenle.txt");
					}
				}
				do {
					cout << "\nBaska Siparis Guncelleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Siparis Guncelleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}

		if (secim == 14)         // Siparis dosyasindaki butun kayitlar yazdirilir.
		{
			do
			{
				ifstream dosyaoku;
				dosyaoku.open("siparis.txt");

				while (true)
				{
					dosyaoku >> siparis.siparisNo >> siparis.firmaNo >> siparis.siparisTutariGenel >> siparis.siparisTutariOzel >> siparis.urunAdedi >> siparis.siparisTarihi >> siparis.siparisiAlan;

					if (dosyaoku.eof())	break; // En son kaydin 2 kere yapilmamasi icin eklendi.
					cout << siparis.siparisNo << "\t" << siparis.firmaNo << "\t" << siparis.siparisTutariGenel << "\t" << siparis.siparisTutariOzel << "\t" << siparis.urunAdedi << "\t" << siparis.siparisTarihi << "\t" << siparis.siparisiAlan << "\n";
				}
				dosyaoku.close();
				do {
					cout << "\nBaska Siparis Listeleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					cin >> islem;

					if (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H') {
						cout << "\nHatali Islem..\nBaska Siparis Listeleme Islemi Yapacak Misiniz ? (e/E - h/H)\n";
					}
					cout << endl;
				} while (islem != 'e' && islem != 'E' && islem != 'h' && islem != 'H');
			} while (islem == 'e' || islem == 'E');
		}
	} while (true);
}