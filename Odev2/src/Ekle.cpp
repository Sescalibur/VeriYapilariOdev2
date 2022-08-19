#include "Ekle.hpp"
#include "Radix.hpp"
Ekle::Ekle(){};
void Ekle::DosyaOkuveEkle(BST *bst){
	ifstream dosyaOku("Sayilar.txt");
    string satir = "";
	string sayi;
	int i = 0;
	int number;
	int toplam;
	bool kontrol;
	int j=0;
	
	ArrayList *array = new ArrayList();
    if ( dosyaOku.is_open() ){
		
		while ( getline(dosyaOku, satir) ){
			for(int i =0 ;i<satir.length();i++){
				
				if(satir[i] != ' '){
					sayi += satir[i];
					kontrol = true;
				}
				if(satir[i] == ' ' && kontrol){
					stringstream ss;
					ss << sayi;
					ss>>number;
					toplam += number;
					array->add(number);
					sayi = "";
				}
			}
			
			Radix *duzen = new Radix(array);
			array= duzen->Sort();
			if(kontrol) {
				bst->Add(toplam,array);
				toplam=0;
				kontrol=false;
				array->clear();
				}			
		}
    dosyaOku.close();
	}
bst->preorder();
}






