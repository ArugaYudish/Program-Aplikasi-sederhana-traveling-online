#include <iostream>
#include <conio.h>
#define MAX 10

using namespace std;
int pilih, pilih1;
string usernameIn,passwordIn,fNameTemp,lNameTemp,repassTemp,autenTemp;
char pil1Login;
bool loginState,state;
int i,j,penanda=1,x,retry;
const int maksimal_tumpukan = 10;
bool keluar = false;
char ya_tidak;
int pilihan;
string data_masuk;
char JK;
string alamatR;
string bali[4] = {"Pantai Kuta", "Pantai Pandawa", "Seminyak","Uluwatu"};
int busurbali[4][4] = {
{0,6,7,5},
{6,0,4,3},
{7,4,0,2},
{5,3,2,0}
};
string Lombok[4] = {"Gili Trawangan", "Pantai Pink", "Pura Meru","Gili Sudak"};
int busurLombok[4][4] = {
{0,4,7,5},
{4,0,3,7},
{7,3,0,2},
{5,7,2,0}
};
string Bandung[4] = {"Floating Market", "Farm House", "Gunung Tangkuban Perahu","Tebing Keraton"};
int busurBandung[4][4] = {
{0,2,4,10},
{2,0,3,7},
{4,3,0,8},
{10,7,8,0}
};
string Jakarta[4] = {"Taman Mini", "Monas", "Kota Tua","Dufan"};
int busurJakarta[4][4] = {
{0,5,4,8},
{5,0,3,5},
{4,3,0,6},
{8,5,6,0}
};
string Yogjakarta[4] = {"Candi Borobudur", "Candi Prambanan", "Pantai Parangtritis","Malioboro"};
int busurYogjakarta[4][4] = {
{0,3,4,5},
{3,0,3,5},
{4,3,0,4},
{5,5,4,0}
};
struct loginT {
    loginT *kiri;
    loginT *kanan;
    string username;
    string password;
    string autentik;
    string fName;
    string lName;
    int level;
};
loginT *root;
loginT *simpulLogin;
loginT *now;
loginT *alamat[256];
loginT *helperLogin;

char pil1beranda;
int levelUserOn=1;
string usernameOn="apahayo";

struct liburan{
    string tujuan;
    string hotel;
    string transportasi;
    int hari;
    int budget;
};

struct checkin {
   string nama;
   struct checkin *next;
};

struct checkin* depan = NULL;
struct checkin* belakang = NULL;
struct checkin* temp;


void Login(){
    i=1;j=1;
    simpulLogin=new loginT;
    simpulLogin->kanan=NULL;
    simpulLogin->kiri=NULL;
    simpulLogin->username="admin";
    simpulLogin->password="admin";
    simpulLogin->level=1;
    root=simpulLogin;
    alamat[i]=root;
    label1Login:
        system("cls");
        cout<<"\t\t ========================="<<endl;
        cout<<"\t\t\t LOGIN"<<endl;
        cout<<"\t\t ========================="<<endl<<endl;
        cout<<"\t\t Username : ";cin>>usernameIn;
        cout<<"\t\t Password : ";cin>>passwordIn;

        x=1;
        for(int x=1;x<=j;x++){
            now=alamat[x];
            if(now->username==usernameIn && now->password==passwordIn){
                loginState=1;
                usernameOn=now->username;
                levelUserOn=now->level;
                break;
            }else{
                loginState=0;
            }
        }

        if(loginState==0){
            cout<<endl;
            cout<<"\t\t USERNAME/PASSWORD SALAH"<<endl<<endl;
            cout<<"\t\t R - Retry"<<endl;
            cout<<"\t\t S - Sign Up"<<endl;
            cout<<"\t\t L - Lupa Password"<<endl;
            cout<<"\t\t E - Exit"<<endl<<endl;
            cout<<"\t\t R/S/L/R : ";cin>>pil1Login;
            if(retry==2){
                cout<<endl;
                cout<<"\t\t !! BATAS RETRY SUDAH HABIS, COBA LAGI NANTI"<<endl;
                getch();
                pil1Login='e';
            }
            pil1Login=tolower(pil1Login);
            switch(pil1Login){
            case 'r':
                retry++;
                goto label1Login;
            break;
            case 's':
                label2Login:
                system("cls");
                cout<<"\t\t ============================="<<endl;
                cout<<"\t\t\t S I G N  U P"<<endl;
                cout<<"\t\t ============================="<<endl<<endl;
                cout<<"\t First Name : ";cin>>fNameTemp;
                cout<<"\t Last Name  : ";cin>>fNameTemp;
                cout<<"\t Username   : ";cin>>usernameIn;
                for(int x=1;x<=j;x++){
                    now=alamat[x];
                    if(usernameIn==now->username){
                        state=1;
                        cout<<endl<<"\t !! USERNAME SUDAH DIGUNAKAN"<<endl;
                        getch();
                        goto label2Login;
                    }
                }
                cout<<"\t Password   : ";cin>>passwordIn;
                cout<<endl;
                cout<<"\t Masukkan Ulang Password : ";cin>>repassTemp;
                if(repassTemp!=passwordIn){
                    cout<<endl<<"\t !! ADA KESALAHAN INPUT PASSWORD"<<endl;
                    getch();
                    goto label2Login;
                }
                cout<<endl;
                cout<<"\t Hewan Peliharaan Pertama      : ";cin>>autenTemp;
                cout<<endl<<endl;
                cout<<"\t Apakah Data di atas Sudah Benar [Y/T] : ";cin>>pil1Login;
                pil1Login=tolower(pil1Login);
                if(pil1Login=='t'){
                    goto label2Login;
                }else if(pil1Login!='y'){
                    cout<<"";
                    getch();
                    goto label2Login;
                }

                if(penanda==1){
                    simpulLogin=new loginT;
                    simpulLogin->kanan=NULL;
                    simpulLogin->kiri=NULL;
                    simpulLogin->username=usernameIn;
                    simpulLogin->password=passwordIn;
                    simpulLogin->fName=fNameTemp;
                    simpulLogin->lName=lNameTemp;
                    simpulLogin->autentik=autenTemp;
                    simpulLogin->level=0;
                    now=alamat[i];
                    now->kiri=simpulLogin;
                    j++;
                    alamat[j]=simpulLogin;
                    penanda++;
                }else{
                    simpulLogin=new loginT;
                    simpulLogin->kanan=NULL;
                    simpulLogin->kiri=NULL;
                    simpulLogin->username=usernameIn;
                    simpulLogin->password=passwordIn;
                    simpulLogin->fName=fNameTemp;
                    simpulLogin->lName=lNameTemp;
                    simpulLogin->autentik=autenTemp;
                    simpulLogin->level=0;
                    now=alamat[i];
                    now->kanan=simpulLogin;
                    j++;
                    i++;
                    alamat[j]=simpulLogin;
                    penanda=1;
                }
                cout<<endl<<"\t AKUN BARU BERHASIL DIBUAT"<<endl;
                getch();
                goto label1Login;
            break;
        case 'l' :
            system("cls");
            cout<<"\t\t ====================================="<<endl;
            cout<<"\t\t\t L U P A  P A S S W O R D"<<endl;
            cout<<"\t\t ====================================="<<endl<<endl;
            cout<<"\t Username : ";cin>>usernameIn;
            for(int x=1;x<=j;x++){
                now=alamat[x];
                if(usernameIn==now->username){
                    state=1;
                    helperLogin=now;
                    break;
                }else{
                    state=0;
                }
            }
            if(state==0){
                cout<<"\t !! USERNAME TIDAK TERDAFTAR";
                getch();
                goto label1Login;
            }else{
                cout<<endl<<"\t AUTENTIKASI"<<endl;
                cout<<"\t Hewan Peliharaan Pertama : ";cin>>autenTemp;
                if(helperLogin->autentik!=autenTemp){
                    cout<<endl<<"\t !! Autentikasi Salah"<<endl;
                    getch();
                    goto label1Login;
                }else{
                    cout<<endl<<"\t Autentikasi Berhasil"<<endl;
                    cout<<"\t Password Baru : ";cin>>passwordIn;
                    helperLogin->password=passwordIn;
                    cout<<endl<<"\t RESET PASSWORD BERHASIL"<<endl;
                    getch();
                    goto label1Login;
                }
            }
            break;
        case 'e':
            break;
        default:
            cout<<"\t MASUKAN INVALID";
            getch();
            goto label1Login;
        }
    }
    cout<<endl;

};

liburan destinasi[5] = {{"Bali"},{"Lombok"},{"Jakarta"},{"Bandung"},{"Tanjung Benoa"}
};

liburan paket_bali[5] = {{"B1", "fourseason","alphard",4, 5000000},
                {"B2", "Melati","Mini Cooper",3, 3500000},
                {"B3", "Hotel Indonesia","Mio",4, 7000000},
                {"B4", "Hotel Savoy Homan", "BMW",3,4000000},
                {"B5", "Hotelia ", "Range Rover",4,10000000}
};
liburan paket_lombok[5] = {{"LOM1", "fourseason","alphard",4, 5000000},
                {"LOM2", "Melati","Mini Cooper",3, 3500000},
                {"LOM3", "Hotel Indonesia","Mio",4, 7000000},
                {"LOM4", "Hotel Savoy Homan", "BMW",3,4000000},
                {"LOM5", "Hotelia ", "Range Rover",4,10000000}
};
liburan paket_jakarta[5] = {{"J1", "fourseason","alphard",4, 5000000},
                {"J2", "Melati","Mini Cooper",3, 3500000},
                {"J3", "Hotel Indonesia","Mio",4, 7000000},
                {"J4", "Hotel Savoy Homan", "BMW",3,4000000},
                {"J5", "Hotelia ", "Range Rover",4,10000000}
};
liburan paket_bandung[5] = {{"BD1", "fourseason","alphard",4, 5000000},
                {"BD2", "Melati","Mini Cooper",3, 3500000},
                {"BD3", "Hotel Indonesia","Mio",4, 7000000},
                {"BD4", "Hotel Savoy Homan", "BMW",3,4000000},
                {"BD5", "Hotelia ", "Range Rover",4,10000000}
};
liburan paket_tanjungbenoa[5] = {{"TJ1", "fourseason","alphard",4, 5000000},
                {"TJ2", "Melati","Mini Cooper",3, 3500000},
                {"TJ3", "Hotel Indonesia","Mio",4, 7000000},
                {"TJ4", "Hotel Savoy Homan", "BMW",3,4000000},
                {"TJ5", "Hotelia ", "Range Rover",4,10000000}
};

void PaketLiburan(){
    system("cls");
    int wisata;
    for (int i=0; i<5; i++){
        cout<<i+1<<" . "<<destinasi[i].tujuan<<endl;
    }
    cout << "Masukan Pilihan Destinasi wisata : "; cin >> wisata;
    if (wisata==1){
        int budg;
        string kode,pembayaran;
        cout << "Budget :\n"
        << "1. < Rp. 4.000.000\n"
        << "2. Rp. 4.000.000 - Rp. 6.000.000\n"
        << "3. > Rp. 6.000.000\n"
        << "Pilih Budget Anda : "; cin >> budg;
        if (budg == 1){
            cout << "\n Berikut Daftar Paket Open Trip Ke Bali :\n";
            for (int k=0; k<5; k++){
                if (paket_bali[k].budget<4000000){
                    cout<< "- Kode Paket : " << paket_bali[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_bali[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_bali[k].transportasi << endl;
                    cout<< "- " << paket_bali[k].hari << " Hari "<< paket_bali[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_bali[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_bali[k].tujuan==kode){
                    cout<< "Paket : " << paket_bali[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_bali[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if(budg == 2){
            cout << "\n Berikut Daftar Paket Open Trip Ke Bali :\n";
            for (int k=0; k<5; k++){
                if (paket_bali[k].budget>=4000000 && paket_bali[k].budget<=6000000){
                    cout<< "- Destinasi : " << paket_bali[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_bali[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_bali[k].transportasi << endl;
                    cout<< "- " << paket_bali[k].hari << " Hari "<< paket_bali[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_bali[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_bali[k].tujuan==kode){
                    cout<< "Paket : " << paket_bali[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_bali[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if (budg == 3){
            cout << "\n Berikut Daftar Paket Open Trip Ke Bali :\n";
            for (int k=0; k<5; k++){
                if (paket_bali[k].budget>6000000){
                    cout<< "- Destinasi : " << paket_bali[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_bali[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_bali[k].transportasi << endl;
                    cout<< "- " << paket_bali[k].hari << " Hari "<< paket_bali[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_bali[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_bali[k].tujuan==kode){
                    cout<< "Paket : " << paket_bali[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_bali[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }

    }else if (wisata==2){
        int budg;
        string kode,pembayaran;
        cout << "Budget :\n"
        << "1. < Rp. 4.000.000\n"
        << "2. Rp. 4.000.000 - Rp. 6.000.000\n"
        << "3. > Rp. 6.000.000\n"
        << "Pilih Budget Anda : "; cin >> budg;
        if (budg == 1){
            cout << "\n Berikut Daftar Paket Open Trip Ke Lombok :\n";
            for (int k=0; k<5; k++){
                if (paket_lombok[k].budget<4000000){
                    cout<< "- Destinasi : " << paket_lombok[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_lombok[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_lombok[k].transportasi << endl;
                    cout<< "- " << paket_lombok[k].hari << " Hari "<< paket_lombok[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_lombok[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_lombok[k].tujuan==kode){
                    cout<< "Paket : " << paket_lombok[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_lombok[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if(budg == 2){
            cout << "\n Berikut Daftar Paket Open Trip Ke Lombok :\n";
            for (int k=0; k<5; k++){
                if (paket_lombok[k].budget>=4000000 && paket_lombok[k].budget<=6000000){
                    cout<< "- Destinasi : " << paket_lombok[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_lombok[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_lombok[k].transportasi << endl;
                    cout<< "- " << paket_lombok[k].hari << " Hari "<< paket_lombok[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_lombok[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_lombok[k].tujuan==kode){
                    cout<< "Paket : " << paket_lombok[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_lombok[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if (budg == 3){
            cout << "\n Berikut Daftar Paket Open Trip Ke Lombok :\n";
            for (int k=0; k<5; k++){
                if (paket_lombok[k].budget>6000000){
                    cout<< "- Destinasi : " << paket_lombok[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_lombok[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_lombok[k].transportasi << endl;
                    cout<< "- " << paket_lombok[k].hari << " Hari "<< paket_lombok[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_lombok[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_lombok[k].tujuan==kode){
                    cout<< "Paket : " << paket_lombok[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_lombok[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }
    }else if (wisata == 3){
        int budg;
        string kode, pembayaran;
        cout << "Budget :\n"
        << "1. < Rp. 4.000.000\n"
        << "2. Rp. 4.000.000 - Rp. 6.000.000\n"
        << "3. > Rp. 6.000.000\n"
        << "Pilih Budget Anda : "; cin >> budg;
        if (budg == 1){
            cout << "\n Berikut Daftar Paket Open Trip Ke Jakarta :\n";
            for (int k=0; k<5; k++){
                if (paket_jakarta[k].budget<4000000){
                    cout<< "- Kode : " << paket_jakarta[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_jakarta[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_jakarta[k].transportasi << endl;
                    cout<< "- " << paket_jakarta[k].hari << " Hari "<< paket_jakarta[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_jakarta[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_jakarta[k].tujuan==kode){
                    cout<< "Paket : " << paket_jakarta[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_jakarta[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if(budg == 2){
            cout << "\n Berikut Daftar Paket Open Trip Ke Jakarta :\n";
            for (int k=0; k<5; k++){
                if (paket_jakarta[k].budget>=4000000 && paket_jakarta[k].budget<=6000000){
                    cout<< "- Kode : " << paket_jakarta[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_jakarta[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_jakarta[k].transportasi << endl;
                    cout<< "- " << paket_jakarta[k].hari << " Hari "<< paket_jakarta[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_jakarta[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_jakarta[k].tujuan==kode){
                    cout<< "Paket : " << paket_jakarta[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_jakarta[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if (budg == 3){
            cout << "\n Berikut Daftar Paket Open Trip Ke Jakarta :\n";
            for (int k=0; k<5; k++){
                if (paket_jakarta[k].budget>6000000){
                    cout<< "- Kode : " << paket_jakarta[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_jakarta[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_jakarta[k].transportasi << endl;
                    cout<< "- " << paket_jakarta[k].hari << " Hari "<< paket_jakarta[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_jakarta[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_jakarta[k].tujuan==kode){
                    cout<< "Paket : " << paket_jakarta[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_jakarta[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }
    }else if (wisata == 4){
        int budg;
        string kode, pembayaran;
        cout << "Budget :\n"
        << "1. < Rp. 4.000.000\n"
        << "2. Rp. 4.000.000 - Rp. 6.000.000\n"
        << "3. > Rp. 6.000.000\n"
        << "Pilih Budget Anda : "; cin >> budg;
        if (budg == 1){
            cout << "\n Berikut Daftar Paket Open Trip Ke Bandung :\n";
            for (int k=0; k<5; k++){
                if (paket_bandung[k].budget<4000000){
                    cout<< "- Kode : " << paket_bandung[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_bandung[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_bandung[k].transportasi << endl;
                    cout<< "- " << paket_bandung[k].hari << " Hari "<< paket_bandung[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_bandung[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_bandung[k].tujuan==kode){
                    cout<< "Paket : " << paket_bandung[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_bandung[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if(budg == 2){
            cout << "\n Berikut Daftar Paket Open Trip Ke Bandung :\n";
            for (int k=0; k<5; k++){
                if (paket_bandung[k].budget>=4000000 && paket_bandung[k].budget<=6000000){
                    cout<< "- Kode : " << paket_bandung[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_bandung[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_bandung[k].transportasi << endl;
                    cout<< "- " << paket_bandung[k].hari << " Hari "<< paket_bandung[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_bandung[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_bandung[k].tujuan==kode){
                    cout<< "Paket : " << paket_bandung[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_bandung[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if (budg == 3){
            cout << "\n Berikut Daftar Paket Open Trip Ke Bandung :\n";
            for (int k=0; k<5; k++){
                if (paket_bandung[k].budget>6000000){
                    cout<< "- Kode : " << paket_bandung[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_bandung[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_bandung[k].transportasi << endl;
                    cout<< "- " << paket_bandung[k].hari << " Hari "<< paket_bandung[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_bandung[k].budget << endl << endl;
                }
            }
        }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_bandung[k].tujuan==kode){
                    cout<< "Paket : " << paket_bandung[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_bandung[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
    }else if (wisata == 5){
        int budg;
        string kode, pembayaran;
        cout << "Budget :\n"
        << "1. < Rp. 4.000.000\n"
        << "2. Rp. 4.000.000 - Rp. 6.000.000\n"
        << "3. > Rp. 6.000.000\n"
        << "Pilih Budget Anda : "; cin >> budg;
        if (budg == 1){
            cout << "\n Berikut Daftar Paket Open Trip Ke Tanjung Benoa :\n";
            for (int k=0; k<5; k++){
                if (paket_tanjungbenoa[k].budget<4000000){
                    cout<< "- Kode : " << paket_tanjungbenoa[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_tanjungbenoa[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_tanjungbenoa[k].transportasi << endl;
                    cout<< "- " << paket_tanjungbenoa[k].hari << " Hari "<< paket_tanjungbenoa[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_tanjungbenoa[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_tanjungbenoa[k].tujuan==kode){
                    cout<< "Paket : " << paket_tanjungbenoa[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_tanjungbenoa[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if(budg == 2){
            cout << "\n Berikut Daftar Paket Open Trip Ke Tanjung Benoa :\n";
            for (int k=0; k<5; k++){
                if (paket_tanjungbenoa[k].budget>=4000000 && paket_tanjungbenoa[k].budget<=6000000){
                    cout<< "- Kode : " << paket_tanjungbenoa[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_tanjungbenoa[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_tanjungbenoa[k].transportasi << endl;
                    cout<< "- " << paket_tanjungbenoa[k].hari << " Hari "<< paket_tanjungbenoa[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_tanjungbenoa[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_tanjungbenoa[k].tujuan==kode){
                    cout<< "Paket : " << paket_tanjungbenoa[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_tanjungbenoa[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }else if (budg == 3){
            cout << "\n Berikut Daftar Paket Open Trip Ke Tanjung Benoa :\n";
            for (int k=0; k<5; k++){
                if (paket_tanjungbenoa[k].budget>6000000){
                    cout<< "- Kode : " << paket_tanjungbenoa[k].tujuan << endl;
                    cout<< "- Hotel : " << paket_tanjungbenoa[k].hotel << endl;
                    cout<< "- Transportasi : " << paket_tanjungbenoa[k].transportasi << endl;
                    cout<< "- " << paket_tanjungbenoa[k].hari << " Hari "<< paket_tanjungbenoa[k].hari << " Malam" << endl;
                    cout<< "- Budget : " << paket_tanjungbenoa[k].budget << endl << endl;
                }
            }cout << "Masukan Kode Paket : "; cin>>kode;
            for (int k=0; k<5; k++){
                if (paket_tanjungbenoa[k].tujuan==kode){
                    cout<< "Paket : " << paket_tanjungbenoa[k].tujuan << endl;
                    cout<< "Harga : Rp." << paket_tanjungbenoa[k].budget << endl << endl;
                    cout << "Lanjut Pembayaran (y/t) : ";cin >> pembayaran;
                    if (pembayaran=="y"){
                        cout << "Kode Pembayaran :" << "20103134\n";
                    }else{
                        cout << "salah blog";
                    }
                }
            }
        }
    }
    char masih;
    cout<<"Kembali ke menu utama ? (y/t) :";
    cin>>masih;
    if (masih=='y'||masih=='Y'){
        keluar=true;
        system("cls");
    }else {
    keluar=false;
    }
}
void tampilLombok(){

    cout<<"Jarak Antar Pariwisata Di Lombok"<<endl;
    cout<<"-------------------------------"<<endl;
 if(Lombok && busurLombok){
 for(int baris = 0; baris < 4; baris++){
 cout<<Lombok[baris]<<" : ";
 for(int kolom = 0; kolom < 4; kolom++){
 if(busurLombok[baris][kolom] != 0){
 cout<<Lombok[kolom]<<"("<<busurLombok[baris][kolom]<<")"<<" ";
 }
 }
 cout<<endl;
 }
 }
}
void tampilBali(){

    cout<<"Jarak Antar Pariwisata Di Bali"<<endl;
    cout<<"-------------------------------"<<endl;
 if(bali && busurbali){
 for(int baris = 0; baris < 4; baris++){
 cout<<bali[baris]<<" : ";
 for(int kolom = 0; kolom < 4; kolom++){
 if(busurbali[baris][kolom] != 0){
 cout<<bali[kolom]<<"("<<busurbali[baris][kolom]<<")"<<" ";
 }
 }
 cout<<endl;
 }
 }
}
void tampilBandung(){

    cout<<"Jarak Antar Pariwisata Di Bandung"<<endl;
    cout<<"-------------------------------"<<endl;
 if(Bandung && busurBandung){
 for(int baris = 0; baris < 4; baris++){
 cout<<Bandung[baris]<<" : ";
 for(int kolom = 0; kolom < 4; kolom++){
 if(busurBandung[baris][kolom] != 0){
 cout<<Bandung[kolom]<<"("<<busurBandung[baris][kolom]<<")"<<" ";
 }
 }
 cout<<endl;
 }
 }
}
void tampilJakarta(){

    cout<<"Jarak Antar Pariwisata Di Jakarta"<<endl;
    cout<<"-------------------------------"<<endl;
 if(Jakarta && busurJakarta){
 for(int baris = 0; baris < 4; baris++){
 cout<<Jakarta[baris]<<" : ";
 for(int kolom = 0; kolom < 4; kolom++){
 if(busurJakarta[baris][kolom] != 0){
 cout<<Jakarta[kolom]<<"("<<busurJakarta[baris][kolom]<<")"<<" ";
 }
 }
 cout<<endl;
 }
 }
}
void tampilYogyakarta(){

    cout<<"Jarak Antar Pariwisata Di Yogjakarta"<<endl;
    cout<<"-------------------------------"<<endl;
 if(Yogjakarta && busurYogjakarta){
 for(int baris = 0; baris < 4; baris++){
 cout<<Yogjakarta[baris]<<" : ";
 for(int kolom = 0; kolom < 4; kolom++){
 if(busurYogjakarta[baris][kolom] != 0){
 cout<<Yogjakarta[kolom]<<"("<<busurYogjakarta[baris][kolom]<<")"<<" ";
 }
 }
 cout<<endl;
 }
 }
}

struct tumpukan{
int posisi;
string nama[maksimal_tumpukan];
char JenisKelamin[maksimal_tumpukan];
string alamatRumah[maksimal_tumpukan];
};
tumpukan biodata;
void inisialisasi(){
biodata.posisi = -1;
}
bool kosong(){
if(biodata.posisi == -1){
return true;
}else{
return false;
}
}
bool penuh(){
if(biodata.posisi == maksimal_tumpukan - 1){
return true;
}else{
return false;
}
}
void push_tumpukan(string data_masukkan,char JK,string alamat){
    if(kosong() == true){
        biodata.posisi++;
        biodata.nama[biodata.posisi] = data_masukkan;
        biodata.JenisKelamin[biodata.posisi]=JK;
        biodata.alamatRumah[biodata.posisi]=alamat;
        cout<<"Berhasil memasukkan : "<<data_masukkan<<endl;
    }else if(penuh() == false){
        biodata.posisi++;
        biodata.nama[biodata.posisi] = data_masukkan;
        biodata.JenisKelamin[biodata.posisi]=JK;
        biodata.alamatRumah[biodata.posisi]=alamat;
        cout<<"Berhasil memasukkan : "<<data_masukkan<<endl;
    }else{
        cout<<"Tumpukan sudah penuh"<<endl;
    }
}
void pop_tumpukan(){
    if(kosong() == true){
        cout<<"Tumpukan kosong"<<endl;
    }else{
        biodata.posisi--;
        cout<<"Data berhasil dihapus"<<endl;
    }
}
void tampil_data(){
    if(kosong() == true){
        cout<<"Tidak ada data"<<endl;
    }else{
        for(int c = biodata.posisi; c >= 0; c--){
        cout<<c+1<<". Nama :"<<biodata.nama[c];
        cout<<"\t Jenis Kelamin "<<biodata.JenisKelamin[c];
        cout<<"\t Alamat : "<<biodata.alamatRumah[c];
        cout<<endl;
        }cout<<endl;
    }
}
 void BiodataUser(){
     system("cls");

     cout<<"Hello Selamat Datang :)"<<endl;
     cout<<"Silahkan Lengkapi Biodata Kamu"<<endl;
     cout<<"-------------------------------"<<endl<<endl;
inisialisasi();
    do{
        cout<<"\     -===Menu Biodata==-"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Tambah Biodata"<<endl;
        cout<<"2. Hapus Biodata"<<endl;
        cout<<"3. Tampilkan semua Biodata"<<endl;
        cout<<"4. Kembali"<<endl;
        cout<<"Silahkan pilih (1-4) : ";
        cin>>pilihan;

        switch(pilihan){
        case 1 :
        cout<<"Silahkan masukkan Nama : ";
        cin>>data_masuk;
        cout<<"Silahkan masukkan Jenis kelamin : ";
        cin>>JK;
        cout<<"Silahkan masukkan Alamat : ";
        cin>>alamatR;

        push_tumpukan(data_masuk,JK,alamatR);
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<" Jumpa kembali "<<endl;
                keluar = true;
            }else{
            system("cls");
            }
        break;
        case 2 :
        pop_tumpukan();
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<" Terima kasih"<<endl;
                keluar = true;
            }else{
            system("cls");
            }
        break;
        case 3 :
        tampil_data();
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<" Terima kasih"<<endl;
                keluar = true;
            }else{
            system("cls");
            }
        break;
        case 4 :
        cout<<"Yakin ingin keluar (y/t) ? ";
        cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima kasih"<<endl;
            keluar = true;
        }
        system("cls");
        break;
        default :
        cout<<"Pilihan tidak tersedia..."<<endl;
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
        if(ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<" Terima kasih"<<endl;
            keluar = true;
        }else{
        system("cls");
        }
    }
    }while(keluar == false);
    }
void jarak(){
    string lanjut;
    int pilihkota;
    system("cls");

    cout<<"        -===Jarak Pariwisata===-        "<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1. Di Lombok "<<endl;
    cout<<"2. Di Bali "<<endl;
    cout<<"3. Di Bandung "<<endl;
    cout<<"4. Di Jakarta "<<endl;
    cout<<"5. Di Yogyakarta"<<endl;
    cout<<"Silahkan Pilih : ";
    cin>>pilihkota;
            system("cls");

        switch(pilihkota){
    case 1 : tampilLombok();
    break;
    case 2 :tampilBali();
    break;
    case 3 :tampilBandung();
    break;
    case 4 :tampilJakarta();
    break;
    case 5 :tampilYogyakarta();
    break;

            default: cout<<"Pilihan Tidak Tersedia"<<endl;
        }
    cout<<"Apakah Anda Masih Ingin Melanjutkan Program : (y/t) ";
    cin>>lanjut;

    if(lanjut=="y"||lanjut=="Y"){
        keluar=true;
        system("cls");
    }else {
        keluar=false;
    }

}
void Input_nama(){
   string nam;
   cout<<"Reservasi atas nama : "<<endl;
   cin>>nam;
   if (belakang == NULL) {
      belakang = (struct checkin *)malloc(sizeof(struct checkin));
      belakang->next = NULL;
      belakang->nama = nam;
      depan = belakang;
   } else {
      temp=(struct checkin *)malloc(sizeof(struct checkin));
      belakang->next = temp;
      temp->nama = nam;
      temp->next = NULL;
      belakang = temp;
   }
}
void Delete() {
   temp = depan;
   if (depan == NULL) {
      cout<<"Data Kosong"<<endl;
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Nama yang dihapus : "<<depan->nama<<endl;
      free(depan);
      depan = temp;
   } else {
      cout<<"Nama yang dihapus : "<<depan->nama<<endl;
      free(depan);
      depan = NULL;
      belakang = NULL;
   }
}

void tampil_nama() {
   temp = depan;
   if ((depan == NULL) && (belakang == NULL)) {
      cout<<"Belum ada Nama yang dimasukan"<<endl;
      return;
   }
   cout<<"Berikut daftar nama orang checkin : ";
   while (temp != NULL) {
      cout<<temp->nama<< endl;
      temp = temp->next;
   }
   cout<<endl;
}
void checkinnn(){
    system("cls");
    cout<<"Hello Selamat Datang :)"<<endl;
    cout<<"-------------------------------"<<endl<<endl;
    do{
        cout<<"\     -===Menu Checkin==-"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Konfirmasi Reservasi"<<endl;
        cout<<"2. Hapus Konfirmasi"<<endl;
        cout<<"3. Tampilkan Antrian Checkin"<<endl;
        cout<<"4. Kembali"<<endl;
        cout<<"Silahkan pilih (1-4) : ";
        cin>>pilihan;
        switch(pilihan){
        case 1 :
            Input_nama();
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Jumpa kembali "<<endl;
                    keluar = true;
                }else{
                system("cls");
                }
            break;
        case 2 :
            Delete();
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                system("cls");
                }
            break;
        case 3 :
            tampil_nama();
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
                if(ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<" Terima kasih"<<endl;
                    keluar = true;
                }else{
                system("cls");
                }
            break;
        case 4 :
            cout<<"Yakin ingin keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<" Terima kasih"<<endl;
                keluar = true;
            }
            system("cls");
            break;
            default :
            cout<<"Pilihan tidak tersedia..."<<endl;
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<" Terima kasih"<<endl;
                keluar = true;
            }else{
            system("cls");
            }
        }
    }while(keluar == false);
}


int main(){
    int pilihMenu;
    int pilihkota;

    Login();
    system("cls");
    MENU:
    cout<<" \t-===MENU UTAMA===- "<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"1. Masukan Nama dan Jumlah Traveller "<<endl;
    cout<<"2. Pilihan Wisata "<<endl;
    cout<<"3. Jarak Terdekat Wisata "<<endl;
    cout <<"4. Checkin" << endl;
    cout<<" Silahkan Pilih : ";
    cin>>pilihMenu;


    switch(pilihMenu){
    case 0 :return 0;
    case 1 : BiodataUser();
                if (keluar==true){
                    goto MENU;
                }

    break;
    case 2:PaketLiburan();
                if (keluar==true){
                    goto MENU;
                }
    break;
    case 3: jarak();
                if (keluar==true){
                    goto MENU;
                }

    break;
    case 4 : checkinnn();
        if (keluar==true){
            goto MENU;
        }
    default : cout<<"Pilihan Tidak Tersedia"<<endl;
        }
    return 0;
}
