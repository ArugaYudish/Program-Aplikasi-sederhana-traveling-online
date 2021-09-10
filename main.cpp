#include <iostream>

using namespace std;
    int milih;
    string user;
    int i,w;

struct login {
    string username;
    string password;

};
struct liburan{
    string tujuan;
    string hotel;
    string transportasi;
    int hari;
    int budget;
};

int main()
{
    login masuk;
    masuk.username;
    masuk.password;

    cout<<"silahkan masukan username : ";
    cin>>masuk.username;
    cout<<"silahkan masukan password : ";
    cin>>masuk.password;
    cout<<endl;


    liburan paket[5] = {{"Bali", "fourseason","kereta",4, 5000000},
                            {"Tanjung benoa", "Melati","bis",3, 4000000},
                                {"lombok", "Hotel Indonesia","kapal laut",4, 7000000},
                                 {"Jogja","Savoy homan","Travel",6,8000000},
                                 {"raja ampat","the lou","Pesawat",5,9000000}};
    for (i=0; i<5; i++) {
        cout << i+1 << ". " << paket[i].tujuan << endl;
    }

    cout << "Masukan Destinasi wisata : "; cin >> w;

    if (w == 1){

      cout<<"pilih bajet: "<<endl;
    for(int i=0; i<5; i++){
        cout<<i+1<<". "<<paket[i].budget<<endl;
    }
      cin>>milih;
    }

    if (w == 2){

      cout<<"pilih bajet: "<<endl;
    for(int i=0; i<5; i++){
        cout<<i+1<<". "<<paket[i].budget<<endl;
    }
      cin>>milih;
    }
    if (w == 3){

      cout<<"pilih bajet: "<<endl;
    for(int i=0; i<5; i++){
        cout<<i+1<<". "<<paket[i].budget<<endl;
    }
      cin>>milih;
    }
    if (w == 4){

      cout<<"pilih bajet: "<<endl;
    for(int i=0; i<5; i++){
        cout<<i+1<<". "<<paket[i].budget<<endl;
    }
      cin>>milih;
    }
    if (w == 5){

      cout<<"pilih bajet: "<<endl;
    for(int i=0; i<5; i++){
        cout<<i+1<<". "<<paket[i].budget<<endl;
    }
      cin>>milih;
    }
    return 0;
}
