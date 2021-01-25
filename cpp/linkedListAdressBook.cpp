// This Adress Book App Created By Ozan Peker#ghost
/*Projenin görev kapasitesi şöyle sıralanabilir;
1.İstenen kayıt silinebilir
2.Rehbere yeni kayıt eklenebilir
3.Her kaydın her bilgisi düzenlenebilir
4.Her kullanıcıya 2 email seçeneği sunulmuştur
5.Her kullanıcıya  3 telefon seçeneği sunulmuştur
6.Her değşiklikte veritabanı olan metin dosyası güncellenir
7.Adres defteri çalıştığı an txt dosyasındaki veritabanını içeri aktarılır
8.Kayıt arama esnasında isim ve telefon kullanarak arama seçeneklerinde tam isim ve tam numara gerekli değildir
9.Silme işlemlerinde arama kriterleri esas alınmıştır,ayrıca girdi ile eşleşen tüm sonuçlar kullnıcıya gösterilir ve kullanıcıdan hangi kaydı silmek istediği istenir
*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <clocale> 
#include <sstream>
#include <vector>
using namespace std;
struct Node
{ /* bu kısımda proje boyunca kullnılacak genel bir struct oluşturuldu.Bu struct içerisinde kişi bilgileri
    ve linked listteki kutuları birbirine bağlamak için pointer tanımlandı.*/
    string isim;
    string soyisim;
    string telefon;
    string adres;
    string mail;
    Node* next;
    string telefon2;
    string telefon3;
    string mail2;
};
class adres_defteri
{
private:
    Node* head, * tail;
public:
    adres_defteri()
    {
        head = NULL;
        tail = NULL;
    }
    void rehber() // Bu fonksiyonda rehberde kayıtlı olan tüm kullanıcılar ekrana basıldı.Tüm linked list gezildi
    {
        Node* temp = new Node;
        temp = head;
        if (head == NULL)//kök kısmı boş ise kullnıcıya geri dönüş yapıldı
        {
            cout << "Rehber Boş!" << endl;
        }
        while (temp != NULL)    //Null olana kadar döngü ile tüm node'lar ekrana bastırıldı
        {
            cout << "Ad:" << temp->isim << endl << "Soyad:" << temp->soyisim << endl << "Telefon Numarası(I):" << temp->telefon << endl << "Telefon Numarası(II):" << temp->telefon2 << endl << "Telefon Numarası:(III)" << temp->telefon3 << endl << "Adres:" << temp->adres << endl << "E-Mail(I):" << temp->mail << endl << "E-Mail(II):" << temp->mail2 << endl;
            cout << "********************************************************" << endl;
            temp = temp->next;
        }
    }
    void yeni_kayit(string firstname, string lastname, string telephone, string telefon2, string telefon3, string adress, string email, string email2)
    {/*Bu fonksiyon yeni kullnıcı oluşturmak için kullanılmaktadırHer kullnıcı için 3 telefon numarası ve 2 email halihazırda bulunmaktadır.
     Kullnıcıya input alınırken bu seçenekleri kullanıp kullanmayacağı sorulur
     kullnıcıdan alınan bilgiler oluşturulan yeni linked listin verilerine aktarılır*/
        Node* ghost = new Node;
        ghost->isim = firstname;
        ghost->soyisim = lastname;
        ghost->telefon = telephone;
        ghost->telefon2 = telefon2;
        ghost->telefon3 = telefon3;
        ghost->adres = adress;
        ghost->mail = email;
        ghost->mail2 = email2;
        ghost->next = NULL;
        if (head == NULL)
        {
            head = ghost;
            tail = ghost;
            ghost = NULL;
        }
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = ghost;
    }
    void sil(string x)
    {/* Bu fonskiyonda   silme işlemi gerçekleştirilmektedir.Silmek istenen düğümün kök yada farklı bir düğüm olması
        iki farklı silme işlemine sebep olur*/
        Node* eski = new Node;
        Node* current = head;
        if (head->telefon == x || head->telefon2 == x || head->telefon3 == x)
        {
            cout << "\nKişi Silindi" << endl;
            head = head->next;
            delete current;//gereksiz bilgileri hafızadan silme
        }
        else
        {
            while (current->next != NULL)
            {
                if (current->next->telefon == x || current->next->telefon2 == x || current->next->telefon3 == x)
                {
                    eski = current->next;
                    current->next = current->next->next;
                    cout << "\nKişi Silindi" << endl;
                    cout << eski->isim << endl;
                    free; eski->soyisim;//gereksiz bilgileri hafızadan silme
                    free; eski->isim;//gereksiz bilgileri hafızadan silme

                    free; eski->adres;//gereksiz bilgileri hafızadan silme
                    free; eski->telefon2;//gereksiz bilgileri hafızadan silme
                    free; eski->telefon3;//gereksiz bilgileri hafızadan silme

                    free; eski->mail;//gereksiz bilgileri hafızadan silme
                    free; eski->mail2;//gereksiz bilgileri hafızadan silme
                    free; eski->telefon;//gereksiz bilgileri hafızadan silme
                    delete eski;//gereksiz bilgileri hafızadan silme
                    break;
                }
                current = current->next;
            }

        }
    }
    void isme_gore_ara(string x, int check)
    {/*Bu fonksiyonda isme göre arama yapılmaktadır.İsmin tam girilmesine gerek yoktur.Bir parçası da girilebilir.Eşleşen tüm kişiler ekrana bastırılır.
     Silme işleminde de bu arama fonksiyonu kullnılır.*/
        int i;
        i = 0;
        string silinen;
        Node* current = head;
        if (head == NULL)
        {
            cout << "Rehber Boş!" << endl;
        }
        while (current != NULL)
        {
            size_t found = current->isim.find(x);
            if (found != string::npos)
            {
                cout << "Kişi Bilgileri;" << endl;
                cout << "Ad:" << current->isim << endl << "Soyad:" << current->soyisim << endl << "Telefon Numarası(I):" << current->telefon << endl << "Telefon Numarası(II):" << current->telefon2 << endl << "Telefon Numarası:(III)" << current->telefon3 << endl << "Adres:" << current->adres << endl << "E-Mail(I):" << current->mail << endl << "E-Mail(II):" << current->mail2 << endl;
                cout << "******************************************************************************" << endl;
                i = i++;
            }
            current = current->next;
        }
        if (i == 0)
        {
            cout << "\nKişi Bulunamadı " << endl;
        }
        if (check == 1 && i != 0)
        {
            cout << "Silmek İstedğiniz Kaydın Numarasını Tam Olarak Giriniz..." << endl;
            // numara silme işleminde tam girilmesi gereken bir girdi olarak alınmaktadır.
            cin >> silinen;
            sil(silinen);
        }
    }
    void numaraya_gore_ara(string x, int check)
    {//isme göre ara mantığının aynısı kullanılmıştır.3 numaraya göre arama gerçekleştirilir.
        int i;
        i = 0;
        string silinen;
        Node* current = head;
        if (head == NULL)
        {
            cout << "Rehber Bos!" << endl;
        }
        while (current != NULL)
        {
            size_t found = current->telefon.find(x);
            size_t found1 = current->telefon2.find(x);
            size_t found2 = current->telefon3.find(x);
            if (found != string::npos || found1 != string::npos || found2 != string::npos)
            {
                cout << "Kişi Bilgileri;" << endl;
                cout << " Ad: " << current->isim << endl << " Soyad: " << current->soyisim << endl << " Telefon Numarası: " << current->telefon << endl << " Telefon Numarası(II): " << current->telefon2 << endl << " Telefon Numarası(III): " << current->telefon3 << endl << " Adres: " << current->adres << " E-Mail(I): " << current->mail << endl << " E-Mail(II): " << current->mail2 << endl;
                i = i++;
            }
            current = current->next;
        }
        if (i == 0)
        {
            cout << "\nKişi Bulunamadı ";
        }
        if (check == 1)
        {
            cout << "\nSilmek İstedğiniz Kaydın Numarasını Tam Olarak Giriniz..." << endl;
            cin >> silinen;
            sil(silinen);
        }
    }
    void kaydi_duzenle()
    {/*Bu fonksiyonda düzenleme işlemi yapılır.Öncelikle tüm liste ekrana yazıdırılır ve başına index numarası eklenir.Kullanıcıdan hangi kişiyi silmesi gerektiği istenir ve ona göre o kişiye gidilir.
     Ardından o kişinin hangi bilgisinin düzenlenmesi gerektiğini sorar ve bu şeklilde yeni girdi alınır.*/
        Node* temp = new Node;
        Node* ghost = new Node;
        temp = head;
        ghost = head;
        int contactNum = 1;
        int choice;
        int index;
        string tmp;
        string yeni;
        if (head == NULL)
        {
            cout << "Rehber Bos!" << endl;
        }
        while (temp != NULL)
        {
            cout << contactNum << ")" << " Ad:" << temp->isim << endl << " Soyad:" << temp->soyisim << endl << " Telefon Numarası:" << temp->telefon << endl << " Telefon Numarası(II):" << temp->telefon2 << endl << " Telefon Numarası(III):" << temp->telefon3 << endl << " Adres:" << temp->adres << endl << " E-Mail(I):" << temp->mail << endl << " E-Mail(II):" << temp->mail2 << endl;
            ++contactNum;
            temp = temp->next;
        }
        cout << "\nDüzenlemek İstedeğiniz Kullanıcının Indeks Numarasını Giriniz( ilk kişi için 1)...";
        cin >> index;
        for (int i = 1; i < index; i++)
        {
            ghost = ghost->next;
        }
        cout << "\nDeğiştirmek İstediğiniz Bilgiyi Seçiniz:";
        cout << "\n1.) İsmi Düzenle";
        cout << "\n2.) Soyismi Düzenle";
        cout << "\n3.) Telefon Numarasını Düzenle";
        cout << "\n4.) İkinci Telefon Numarasını Ekle/Düzenle";
        cout << "\n5.) Üçüncü Telefon Numarasını Ekle/Düzenle";
        cout << "\n6.) Adresi Düzenle";
        cout << "\n7.) E-Mail Düzenle";
        cout << "\n8.) İkinci E-Mail Ekle/Düzenle";
        cout << "\n9.) Quit";
        cout << "\n";
        cin >> choice;
        switch (choice)
        {
        case 1: cout << "\nYeni İsmi Giriniz:";
            cin.ignore();
            getline(cin, yeni);
            tmp = ghost->isim;
            ghost->isim = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme
            break;
        case 2: cout << "\nYeni Soyismi Giriniz:";
            cin >> yeni;
            tmp = ghost->soyisim;
            ghost->soyisim = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme
            break;
        case 3: cout << "\nYeni Telefon Numarasını Giriniz:";
            cin >> yeni;
            tmp = ghost->telefon;
            ghost->telefon = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme
            break;
        case 4: cout << "\nYeni Telefon Numarasını Giriniz:";
            cin >> yeni;
            tmp = ghost->telefon2;
            ghost->telefon2 = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme
            break;
        case 5: cout << "\nYeni Telefon Numarasını Giriniz:";
            cin >> yeni;
            tmp = ghost->telefon3;
            ghost->telefon3 = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme
            break;
        case 6: cout << "\nYeni Adresi Giriniz:";
            cin.ignore();
            getline(cin, yeni);
            tmp = ghost->adres;
            ghost->adres = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme
            break;
        case 7: cout << "\nYeni E-Mail Giriniz:";
            cin >> yeni;
            tmp = ghost->mail;
            ghost->mail = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme
            break;
        case 8: cout << "\nYeni E-Mail Giriniz.:";
            cin >> yeni;
            tmp = ghost->mail2;
            ghost->mail2 = yeni;
            free; tmp;//gereksiz bilgileri hafızadan silme 
            break;
        case 9:
            break;
        default:
            cout << choice << " geçerli bir girdi değil.Lütfen geçerli bir girdi giriniz" << endl;
            break;
        }

    }
    void database()
    {
        fstream myfile;
        Node* kok = new Node;
        kok = head;
        myfile.open("database.txt", ios::out);
        while (kok != NULL) {
            if (myfile.is_open()) {
                myfile << kok->isim << endl;
                myfile << kok->soyisim << endl;
                myfile << kok->telefon << endl;
                myfile << kok->telefon2 << endl;
                myfile << kok->telefon3 << endl;
                myfile << kok->adres << endl;
                myfile << kok->mail << endl;
                myfile << kok->mail2 << endl;
            }
            kok = kok->next;
        }
        myfile.close();
    }
    void veritabanı_aktar()
    {//program ilk açıldığında txt veritabanının aktarılması sağlanır.İşleyiş şu şekildedir;
        //program açılınca txt soyasındaki her 8 gruplık satır alınır ve yeni ikşi ekle fonksiyonu kullanılarak linked list oluşturulur.
        int ozimozi;
        string line;
        string kayit[8];
        fstream myfile("database.txt");
        if (myfile.is_open())
            ozimozi = 10;
        {
            while (ozimozi == 10)
            {
                for (int i = 0; i < 8; i++)
                {
                    getline(myfile, line);
                    if (line == "")
                    {
                        ozimozi = 9;
                        break;
                    }
                    kayit[i] = line;
                }
                if (line != "")
                {
                    yeni_kayit(kayit[0], kayit[1], kayit[2], kayit[3], kayit[4], kayit[5], kayit[6], kayit[7]);
                }
            }
            myfile.close();
        }
    }
};
int main()
{
    setlocale(LC_ALL, "turkish");
    adres_defteri Contacts; 
    int choice, kont, kont1, kont2;
    int search_choice;
    string isim;
    string soyisim;
    string telefon, telefon2, telefon3;
    string adres;
    string mail, mail2;
    string x;
    string line;
    int i = 1;
    Contacts.veritabanı_aktar();
    cout << "**Adres Defterine Hoşgeldiniz**" << endl;
    while (1) {
        cout << "\nLütfen Yapılacak İşlemi Seçiniz: " << endl;
        cout << "1. Rehberi Göster" << endl;
        cout << "2. Kayıt Ara" << endl;
        cout << "3. Yeni Kişi Ekle" << endl;
        cout << "4. Kişi Sil" << endl;
        cout << "5. Kaydı Düzenle" << endl;
        cout << "6. Programdan Çık" << endl;
        cout << "(Büyük-Küçük Harf Duyarlılığı Vardır)" << endl;
        cin >> choice;
        switch (choice)//case durumu ile fonksiyon çağrılma gerçekleştirildi.Her case sonrası txt dosyası güncellendi.
        {
        case 1:
            cout << endl;
            Contacts.rehber();
            cout << endl;
            Contacts.database();
            break;
        case 2:
            cout << "\nİsme göre aramak için 1 , Telefon numarasına göre aramak için 2 giriniz: ";
            cin >> search_choice;
            
            if (search_choice==1) 
            {
                cout << "\nİsmi tam&kısım giriniz: ";
                cin >> x;
                Contacts.isme_gore_ara(x, 0);
                Contacts.database();
                break;
                
            }
            if (search_choice == 2)
            {
                cout << "\nTelefon numarasını tam&kısım giriniz: ";
                cin >> x;
                Contacts.numaraya_gore_ara(x, 0);
                Contacts.database();
                break;
            }
            //Contacts.database();
            //break;
        case 3:
            cout << "\nİsmi Giriniz: ";
            cin.ignore();
            getline(cin, isim);
            cout << "\nSoyismi Giriniz: ";
            cin >> soyisim;
            cout << "\nTelefon Numarasını Giriniz: ";
            cin >> telefon;
            cout << "\nİkinci Telefon Numarasını Girecek Misiniz?(EVET=>1,HAYIR=>2): ";
            cin >> kont;
            if (kont == 1) {
                cout << "\nİkinci Telefon Numarasını Giriniz: ";
                cin >> telefon2;
                cout << "\nÜçüncü Telefon Numarasını Girecek Misiniz?(EVET=>1,HAYIR=>2): ";
                cin >> kont1;
                if (kont1 == 1)
                {
                    cout << "\nÜçüncü Telefon Numarasını Giriniz: ";
                    cin >> telefon3;
                }
                if (kont1 == 2)
                {
                    telefon3 = "---";
                }
            }
            if (kont == 2)
            {
                telefon2 = "---";
                telefon3 = "---";
            }
            cin.clear();
            cin.sync();
            cout << "\nAdres Giriniz: ";
            cin.ignore();
            getline(cin, adres);
            cout << "\nE-Mail Giriniz: ";
            cin >> mail;
            cout << "\nİkinci Mail Adresi Girecek Misiniz?(EVET=>1,HAYIR=>2): ";
            cin >> kont2;
            if (kont2 == 1)
            {
                cout << "\nİkinci Mail Adresini Giriniz: ";
                cin >> mail2;
            }
            if (kont2 == 2)
            {
                mail2 = "---";
            }
            Contacts.yeni_kayit(isim, soyisim, telefon, telefon2, telefon3, adres, mail, mail2);
            cout << endl;
            Contacts.database();
            break;
        case 4:
            cout << "\nİsme göre silmek için 1 , Telefon numarasına göre silmek için 2 giriniz: ";
            cin >> search_choice;
            if (search_choice == 1)
            {
                cout << "Silmek İstediğiniz Kayıdın İsmini tam&kısım Giriniz ";
                cin >> x;
                Contacts.isme_gore_ara(x, 1);
                Contacts.database();
                break;
            }
            if (search_choice == 2)
            {
                cout << "Silmek İstediğiniz Kayıdın Telefon Numarasını tam&kısım Giriniz ";
                cin >> x;
                Contacts.numaraya_gore_ara(x, 1);//bu kısımda 1 flag 'ı ile arama fonksiyonuna string gönderildi.
                Contacts.database();
                break;
            }
            if (search_choice != 1 && search_choice != 2)
            {
                cout << "\nGeçersiz girdi...";
                break;
            }
            Contacts.database();
            break;
        case 5:
            cout << endl;
            Contacts.kaydi_duzenle();
            cout << endl;
            Contacts.database();
            break;
        case 6:
            exit(1);
            Contacts.database();
            break;
        default:
            cout << "\n" << choice << " geçerli bir girdi değil.Lütfen geçerli bir girdi giriniz" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
// Ozan PEKER
// Gazi University
// 151110051
