// AD SOYAD = MEDÝNE ÜRÜN


#include <iostream>
#include <fstream>
#include <string>
#include <locale.h> //türkçe karakterler için
using namespace std;

int secim;
int sehirsec;
int sefersaati;
string YolcuAdi;
string YolcuSoyadi;
string TcNo;
string Telefon;
string YolcuCinsiyet;
string TC;
string Tarih;
string SehirAdi;
string Saat;
double Ucret;
char cevap;
int koltuknumarasi;
string bilgi;

class sistem
{
	public : void yaz()
	{
		ifstream dosyaoku("sehirler.txt");
		string mtn;
		if(dosyaoku.is_open());
		{
			cout<<"SEHÝRLER"<<endl;
			while(getline(dosyaoku,mtn))
			{
				cout<<mtn<<endl;
			}
			dosyaoku.close();
		cout<<"LUTFEN GITMEK ISTEDIGINIZ SEHRI SECINIZ."<<sehirsec<<endl<<endl;
        cin>>sehirsec;
		}
		
	}
	
	
	public : void sec()
	{
		ifstream dosyaoku2("sefer.txt");
		string mtn2;
		if(dosyaoku2.is_open());
		{
			cout<<"SEFER"<<endl;
			while(getline(dosyaoku2,mtn2))
			{
				cout<<mtn2<<endl;
			}
			dosyaoku2.close();
			cout<<"SEFER SAATÝ SECÝNÝZ."<<endl;
			cin>>sefersaati;
		}
			
	}
	
	
	public : void bilgi()
	{
		cout<<"YOLCU KAYIT EKLEME"<<endl;
		
		ofstream DosyaYaz;
		DosyaYaz.open("kiþibilgi.txt");
		
		do
		{
			cout<<"\n Yolcu TC :"; cin>>TC; 
            cout<<"\n Yolcu Adi :"; cin>>YolcuAdi; 
            cout<<"\n Yolcu Soyadi :"; cin>>YolcuSoyadi; 
            cout<<"\n Yolcu Telefonu :"; cin>>Telefon; 
            cout<<"\n Yolcu Cinsiyeti :"; cin>>YolcuCinsiyet;
            
            DosyaYaz<<sehirsec<<TC<<" "<<YolcuAdi<<' '<<YolcuSoyadi<<' '<<Telefon<<' ' <<YolcuCinsiyet<<endl;
            
            cout<<"\n Baska kayit yapacak misiniz?(e/E) (h/H) ";cin>>cevap; 
            
            DosyaYaz.close(); 
            }
			while(cevap=='e' || cevap=='E');
 
 
	}
	
	
	public : void koltuk()
	{
		ifstream dosyaoku3("koltuklar.txt");
		string mtn3;
		
		if(dosyaoku3.is_open())
		{
			cout<<"KOLTUKLAR"<<endl;
			while(getline(dosyaoku3,mtn3))
			{
				cout<<mtn3<<endl;
			}
			dosyaoku3.close();
			cout<<"KOLTUK NUMARASI SECÝNÝZ."<<endl;
			cin>>koltuknumarasi;
		}
		
	}
	
};


class islem
{
	public : void sec()
	{
		
		do
		{
			cout<<"1- Yolcu kaydi düzeltme"<<endl; 
            cout<<"2- Yolcu silme"<<endl;
            cout<<"3- Ýslemi bitir"<<endl;
            
            cout<<"YAPMAK ÝSTEDÝGÝNÝZ ÝSLEMÝ SECÝNÝZ."<<endl;
            cin>>secim;
            
            switch(secim)
            {
            	case 1:
            		{
            			cout<<"1- Yolcu kaydý düzeltme"<<endl;
            			
                        ifstream dosyaoku;
                        //ofstream dosya1;
                        dosyaoku.open("kisibilgi.txt",ios::app);
                        ofstream dosya1("temp.txt");
                        
                        cout<< "\n Yolcu Bilgileri \n"; 
                        cout<<"TC no :";
                        cin>>TcNo;
                        cout<<"\n yeni bilgiyi giriniz";
                        cin>>bilgi;
                        int k=0;
                        if(dosyaoku.is_open()){
                        	do
                        	{
                        		getline(dosyaoku,TcNo);
                        		if(TcNo==bilgi)
                        		{
                        			dosya1<<bilgi<<endl;
                        			cout<<TcNo<<"güncellendi"<<endl;
                        			k=1;
                        			}
                        			else
                        			{
                        				dosya1<<TcNo<<endl;
									}
									}while(!dosyaoku.eof());
									dosyaoku.close();
									dosya1.close();
									int s=remove("kisibilgi.txt");
									int s1=rename("temp.txt","kisibilgi.txt");
									if(k==0)
									cout<<TcNo<<"listede yok"<<endl;
									
								
							}
						}
                        
                       
                        break;
					
						case 2:
				{
				
				
					cout<<"2- Yolcu silme"<<endl;
					ifstream DosyaOku;
                    DosyaOku.open("kisibilgi.txt");
                    cout<<"TC no:";
                    cin>>TcNo;
                    if(TC==TcNo)
                    {
                    	remove("kiþibilgi.txt");
					}
					break;
					}
					
				case 3:
				{
					cout<<"4-islemi bitir"<<endl;
 		            cout<<"KAYIT ÝSLEMÝNÝZ TAMAMLANMISTIR"<<endl;
				}
				break;
					
			}
			}while(cevap=='e' || cevap=='E');cout<<endl;
			}     
            
		
	};
	
	



int main() {
    cout<<"TURIZM ÞIRKETINE HOSGELDINIZ."<<endl;
	setlocale(LC_ALL, "Turkish"); 
	
	
	sistem s1;
	islem n1;
	s1.yaz();	
	s1.sec();
	s1.bilgi();
	s1.koltuk();

	n1.sec();


    cout<<"BÝZÝ TERCÝH ETTÝÐÝNÝZ ÝÇÝN TEÞEKKÜRLER"<<endl;
 
  
  return 0;
  

}




































