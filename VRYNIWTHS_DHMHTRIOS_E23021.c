#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>

void user_singup(), user_login(), check_login(), view_routes(), book_trip(), generate_trip_ID(int d, int m, int y, char destid[5]), payment(), confirmed_trips();//dhlwsh sunarthsewn
int username_exists(), compare_trips( int d1, int m1, int y1, int d2, int m2, int y2), valid_date(int d, int m, int y);

struct user//dhlwsh struct stoixiwn user
{
    char name[20];
    char surname[20];
    int age;
    long long int card_number;
    int university_student;
    char username[20];
    char password[10];
};

 struct user customers[30];

 struct route
 {
    char limani[15];
    char kwdikos_lim[5];
    int katastroma;
    int aeroporiko;
    int kampina;
    int autokinhto;
 };

struct route proorismoi[13];

struct date
{
    int dd;
    int mm;
    int year;
};

struct booked_trip
{
    char username[20];
    char anagnwristiko[40];
    float kostos;
    struct date hmeromhnia;
    struct date hm_ep;
    int trip_type;
    int katastash;

};

struct booked_trip booked[30][50];

int ar_taksidiwn[30];//pinakas pou exei mesa ton arithmo tajidiwn pou exei kathe xrisths 



int plpelatwn = 0, userpointer, flag=0;// userpointer einai se poia thesh tou pinaka customers briskete to login pou ekane o xrisths



int main(void)
{   int i=0, j;

    for(i=0; i<30; i++)//arxikopoihsh arithmwn taksidiwn kathe xristh kai katastash opou katastash=0 shmainei oxi krathsh enw krathsh=1 shmainei exei aplhrwth krathsh
    {
        ar_taksidiwn[i]=0;
        for(j=0; j<50; j++)
        {
            booked[userpointer][ar_taksidiwn[userpointer]].katastash=0;
        }
    }


    //arxikopoihsh pinaka diadromwn
    strcpy(proorismoi[0].limani, "Kos");
    strcpy(proorismoi[1].limani, "Rodos");
    strcpy(proorismoi[2].limani, "Kalymnos");
    strcpy(proorismoi[3].limani, "Patmos");
    strcpy(proorismoi[4].limani, "Astypalaia");
    strcpy(proorismoi[5].limani, "Kasos");
    strcpy(proorismoi[6].limani, "Kastelorizo");
    strcpy(proorismoi[7].limani, "Leros");
    strcpy(proorismoi[8].limani, "Karpathos");
    strcpy(proorismoi[9].limani, "Symi");
    strcpy(proorismoi[10].limani, "Xalki");
    strcpy(proorismoi[11].limani, "Tilos");
    strcpy(proorismoi[12].limani, "Pserimos");

    strcpy(proorismoi[0].kwdikos_lim, "KOS");
    strcpy(proorismoi[1].kwdikos_lim, "RHO");
    strcpy(proorismoi[2].kwdikos_lim, "KAL");
    strcpy(proorismoi[3].kwdikos_lim, "PAT");
    strcpy(proorismoi[4].kwdikos_lim, "AST");
    strcpy(proorismoi[5].kwdikos_lim, "KAS");
    strcpy(proorismoi[6].kwdikos_lim, "KST");
    strcpy(proorismoi[7].kwdikos_lim, "LER");
    strcpy(proorismoi[8].kwdikos_lim, "KAR");
    strcpy(proorismoi[9].kwdikos_lim, "SYM");
    strcpy(proorismoi[10].kwdikos_lim, "XAL");
    strcpy(proorismoi[11].kwdikos_lim, "TIL");
    strcpy(proorismoi[12].kwdikos_lim, "PSE");

    proorismoi[0].katastroma=60;
    proorismoi[1].katastroma=80;
    proorismoi[2].katastroma=60;
    proorismoi[3].katastroma=55;
    proorismoi[4].katastroma=50;
    proorismoi[5].katastroma=65;
    proorismoi[6].katastroma=100;
    proorismoi[7].katastroma=60;
    proorismoi[8].katastroma=70;
    proorismoi[9].katastroma=80;
    proorismoi[10].katastroma=70;
    proorismoi[11].katastroma=75;
    proorismoi[12].katastroma=60;

    proorismoi[0].aeroporiko=80;
    proorismoi[1].aeroporiko=100;
    proorismoi[2].aeroporiko=80;
    proorismoi[3].aeroporiko=75;
    proorismoi[4].aeroporiko=70;
    proorismoi[5].aeroporiko=85;
    proorismoi[6].aeroporiko=120;
    proorismoi[7].aeroporiko=80;
    proorismoi[8].aeroporiko=90;
    proorismoi[9].aeroporiko=100;
    proorismoi[10].aeroporiko=90;
    proorismoi[11].aeroporiko=95;
    proorismoi[12].aeroporiko=80;

    proorismoi[0].kampina=120;
    proorismoi[1].kampina=140;
    proorismoi[2].kampina=120;
    proorismoi[3].kampina=115;
    proorismoi[4].kampina=110;
    proorismoi[5].kampina=125;
    proorismoi[6].kampina=160;
    proorismoi[7].kampina=120;
    proorismoi[8].kampina=130;
    proorismoi[9].kampina=140;
    proorismoi[10].kampina=130;
    proorismoi[11].kampina=135;
    proorismoi[12].kampina=120;

    proorismoi[0].autokinhto=100;
    proorismoi[1].autokinhto=100;
    proorismoi[2].autokinhto=100;
    proorismoi[3].autokinhto=100;
    proorismoi[4].autokinhto=100;
    proorismoi[5].autokinhto=100;
    proorismoi[6].autokinhto=120;
    proorismoi[7].autokinhto=100;
    proorismoi[8].autokinhto=100;
    proorismoi[9].autokinhto=120;
    proorismoi[10].autokinhto=100;
    proorismoi[11].autokinhto=100;
    proorismoi[12].autokinhto=100;


    int choice;
    do
    {
        do//epiloges arxikhs othonhs
        {
            printf("\n\n\n\nPress 0 to exit.\nPress 1 to Sign Up.\nPress 2 to Login:");
            scanf(" %d", &choice);
            if(choice != 0 && choice != 1 && choice != 2)
            {
                printf("\nInvcalid choice. PLease try again.\n");
            }
        } while (choice != 0 && choice != 1 && choice != 2);

        if(choice == 1)
        {
            user_singup();
        }
        if(choice == 2)
        {
            user_login();
        }
    

    } while (choice != 0 );// to programma termatizei mono an choice = 0


    return 0;
}


void user_singup()
{   
    char passwordcheck[10];
    int x;


    if(plpelatwn==30)//elegxos an oi eggrafes exoun kseperasei tis 30
    {
        printf("\n\nNo more sing ups. Limit of 30 customers.");
    }else
    {
        printf("\nPlease insert your firstname:");
        scanf(" %19s", customers[plpelatwn].name);
        printf("\nPlease insert your lastname:");
        scanf(" %19s", customers[plpelatwn].surname);    
        do//elegxos 18+
        {
            printf("\nPlease insert your age:");
            scanf(" %d", &customers[plpelatwn].age);
            if(customers[plpelatwn].age < 18)
            {
                printf("\nYou must be an adult to sing up");
            }
        }while(customers[plpelatwn].age < 18);
        printf("\nPlease insert your card number:");
        do//elegxos kartas 16 psifiwn
        {
            scanf(" %lld", &customers[plpelatwn].card_number);
            if(customers[plpelatwn].card_number>10000000000000000 || customers[plpelatwn].card_number<1000000000000000)
            {
                printf("\nThe card number is invalid. It must have 16 digits. Try again:");
            }
        }while(customers[plpelatwn].card_number>10000000000000000 || customers[plpelatwn].card_number<1000000000000000);
        do//elegxos an einai foithths
        {
            printf("\nIf you are university student press 0, otherwise press 1:");
            scanf(" %d", &customers[plpelatwn].university_student);
            if(customers[plpelatwn].university_student != 0 && customers[plpelatwn].university_student != 1)
            {
                printf("\nInvalid choice. Please try again:");
            }
        }while(customers[plpelatwn].university_student != 0 && customers[plpelatwn].university_student != 1);
        do
        {
            printf("Please insert your username:");
            scanf(" %19s", customers[plpelatwn].username);
            x=username_exists();//elegxos an yparxei hsh to username pou paei nma dwsei 
            if(x == 1)
            {
                printf("\n\nUsername is not available. Please give another username.");
            }
        }while(x == 1);
        printf("\nPlease give me your password(7 characters):");//elegxos kwdikou prepei na ton dwsei 2 fores
        do
        {

        do
        {
            printf("\nPassword(7 characters):");
            scanf(" %7s", customers[plpelatwn].password);
            if(strlen(customers[plpelatwn].password)!= 7)
            {
                printf("The password must have 7 characters:");
            }
        }while(strlen(customers[plpelatwn].password)!= 7);// strlen dinei ton aithmo twn xarakthrwn ths metablhths
        printf("Comfirm password:");
        scanf(" %7s", passwordcheck);
        if(strcmp(customers[plpelatwn].password, passwordcheck)== 1)
        {
            printf("Comfermetion failed");
        }
        }while(strcmp(customers[plpelatwn].password, passwordcheck)== 1);

        plpelatwn = plpelatwn + 1;//+1 users exoun kanei eggrafh
    }
};

int username_exists()// elegxos an yparxoun to username pou paeu na dwsei o xrhsths
{   int x=0;
    int i;
    if(plpelatwn>0)
    {
    for(i=0; i<plpelatwn; i++)
    {
        if(strcmp(customers[i].username, customers[plpelatwn].username)== 0)
        {
            x=1;
            continue;
        }

    }
    }
    return x;//epistrefei 1 an yparxei kai 0 an den yparxei
};


void user_login()//idiothtes login
{

    int x, i, counter=0;
    check_login();
    flag=0;
    do
    {
        printf("\n\nPress 1 to View Available Routes.\nPress 2 to Book Trip.\nPress 3 to Pay.\nPress 4 to Comfirm trips.\nPress 5 to logout:");
        scanf(" %d", &x);
        if(x==1)
        {
            view_routes();
        }
        if(x==2)
        {
            if(flag==0)//elegxoume an o xrisths exei dei prwta ta taksidia an ta exei dei proxwraei sthn krathsh
            {
                printf("\n\nYou have to check the routes first.");
            }else
            {
                book_trip();
            }
        }
        if(x==3)
        {
           if(ar_taksidiwn[userpointer]==0)//elegxos an exei klismena aplhrota tajidia
           {
                printf("\n\nYou have to book a trip first.");
           }else
           {
                for(i=0; i<ar_taksidiwn[userpointer]; i++)
                {
                    if(booked[userpointer][i].katastash==0)
                    {
                        counter++;
                    }
                }
                if(counter==0)
                {
                    printf("\n\nYou have to book a new trip.");
                }else
                {
                    payment();
                }
                
           }
        }

        counter=0;

        if(x==4)
        {
           if(ar_taksidiwn[userpointer]==0)//elegxos an exei plhromena tajidia
           {
                printf("\n\nYou must have payed at least one trip.");
           }else
           {
                for(i=0; i<ar_taksidiwn[userpointer]; i++)
                {
                    if(booked[userpointer][i].katastash==1)
                    {
                        counter++;
                    }
                }
                if(counter==0)
                {
                    printf("\n\nYou must pay a trip first.");
                }else
                {
                    confirmed_trips();
                }
                
           }
        }
    }while(x!=5);
  
};


void check_login()//elegxos login username kai password
{
      char checkname[20], checkpass[20];
    int x=0, i;

    do
    {
        printf("\n\n\nPlease insert your username:");
        scanf(" %19s", checkname);
        printf("\nPlease insert your password:");
        scanf(" %19s", checkpass);
        for(i=0; i<30; i++)
        {
            if(strcmp(checkname, customers[i].username)== 0 && strcmp(checkpass, customers[i].password)== 0)
            {
                x=1;
                userpointer=i;
                continue;
            }
        }
        if(x== 0)
        {
            printf("\nInvalid username or password. Please try again");
        }
    }while(x == 0);//prospathei mexris otou na balei egkiro username kai password
    
}

void view_routes()//emfanisei diadromwn kai kostoi 
{
    printf("\n\n\n\n\n Island       Code      Deck    Airplane   Cabin    Car");
    printf("\n %s            %s      %d      %d        %d      %d", proorismoi[0].limani, proorismoi[0].kwdikos_lim, proorismoi[0].katastroma, proorismoi[0].aeroporiko, proorismoi[0].kampina, proorismoi[0].autokinhto);
    printf("\n %s          %s      %d     %d        %d      %d", proorismoi[1].limani, proorismoi[1].kwdikos_lim, proorismoi[1].katastroma, proorismoi[1].aeroporiko, proorismoi[1].kampina, proorismoi[1].autokinhto);
    printf("\n %s       %s      %d      %d        %d      %d", proorismoi[2].limani, proorismoi[2].kwdikos_lim, proorismoi[2].katastroma, proorismoi[2].aeroporiko, proorismoi[2].kampina, proorismoi[2].autokinhto);
    printf("\n %s         %s      %d      %d        %d      %d", proorismoi[3].limani, proorismoi[3].kwdikos_lim, proorismoi[3].katastroma, proorismoi[3].aeroporiko, proorismoi[3].kampina, proorismoi[3].autokinhto);
    printf("\n %s     %s      %d      %d        %d      %d", proorismoi[4].limani, proorismoi[4].kwdikos_lim, proorismoi[4].katastroma, proorismoi[4].aeroporiko, proorismoi[4].kampina, proorismoi[4].autokinhto);
    printf("\n %s          %s      %d      %d        %d      %d", proorismoi[5].limani, proorismoi[5].kwdikos_lim, proorismoi[5].katastroma, proorismoi[5].aeroporiko, proorismoi[5].kampina, proorismoi[5].autokinhto);
    printf("\n %s    %s     %d     %d        %d      %d", proorismoi[6].limani, proorismoi[6].kwdikos_lim, proorismoi[6].katastroma, proorismoi[6].aeroporiko, proorismoi[6].kampina, proorismoi[6].autokinhto);
    printf("\n %s          %s      %d      %d        %d      %d", proorismoi[7].limani, proorismoi[7].kwdikos_lim, proorismoi[7].katastroma, proorismoi[7].aeroporiko, proorismoi[7].kampina, proorismoi[7].autokinhto);
    printf("\n %s      %s      %d      %d        %d      %d", proorismoi[8].limani, proorismoi[8].kwdikos_lim, proorismoi[8].katastroma, proorismoi[8].aeroporiko, proorismoi[8].kampina, proorismoi[8].autokinhto);
    printf("\n %s           %s      %d     %d        %d      %d", proorismoi[9].limani, proorismoi[9].kwdikos_lim, proorismoi[9].katastroma, proorismoi[9].aeroporiko, proorismoi[9].kampina, proorismoi[9].autokinhto);
    printf("\n %s          %s      %d      %d        %d      %d", proorismoi[10].limani, proorismoi[10].kwdikos_lim, proorismoi[10].katastroma, proorismoi[10].aeroporiko, proorismoi[10].kampina, proorismoi[10].autokinhto);
    printf("\n %s          %s      %d      %d        %d      %d", proorismoi[11].limani, proorismoi[11].kwdikos_lim, proorismoi[11].katastroma, proorismoi[11].aeroporiko, proorismoi[11].kampina, proorismoi[11].autokinhto);
    printf("\n %s       %s      %d      %d        %d      %d\n\n\n", proorismoi[12].limani, proorismoi[12].kwdikos_lim, proorismoi[12].katastroma, proorismoi[12].aeroporiko, proorismoi[12].kampina, proorismoi[12].autokinhto);

    flag=1;
}

void  book_trip()
{   int x=0, y=0, i=0;
    float cost1=0;
    char destid[5], tupos_theshs[15];

    strcpy(booked[userpointer][ar_taksidiwn[userpointer]].username, customers[userpointer].username);//bazoume to username tou xristh sthn krathsh pou kanei 
    do
    {
        printf("\n\nPlease insert the departure date(dd:mm:yyyy):");//o xrisths prepei na grapsei kai mera:mhna:xrono
        scanf(" %d:%d:%d", &booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.dd, &booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.mm, &booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.year );
        x=valid_date(booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.dd, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.mm, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.year);

        if(x==0)
        {
            printf("\n\nInvalid date. Please try again:");
        }
        y=1;
        if(ar_taksidiwn[userpointer]>0)//elegxoume an uphrxe prohgoumeno tajidi
        {
            if( booked[userpointer][ar_taksidiwn[userpointer]-1].hmeromhnia.year==0)//elegxoume an to prohgoumeno tajidi eixe epistrofh 
            {
                y=compare_trips(booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.dd, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.mm, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.year, booked[userpointer][ar_taksidiwn[userpointer]-1].hmeromhnia.dd, booked[userpointer][ar_taksidiwn[userpointer]-1].hmeromhnia.mm, booked[userpointer][ar_taksidiwn[userpointer]-1].hmeromhnia.year);
            }else
            {
                y=compare_trips(booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.dd, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.mm, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.year, booked[userpointer][ar_taksidiwn[userpointer]-1].hm_ep.dd, booked[userpointer][ar_taksidiwn[userpointer]-1].hm_ep.mm, booked[userpointer][ar_taksidiwn[userpointer]-1].hm_ep.year);
            }

            if(y==0)
            {
                printf("\n\nYou can book a new trip on a date after your previous booking.");
            }
        }
    
    }while(x==0 || y==0); 

    do//epilgei kwdiko nhsiou
    {
        printf("\n\nPlease give the code of your destination:");
        scanf(" %4s", destid);
    if(strcmp(destid, "KOS")!=0 && strcmp(destid, "RHO")!=0 && strcmp(destid, "KAL")!=0 && strcmp(destid, "PAT")!=0 && strcmp(destid, "AST")!=0 && strcmp(destid, "KAS")!=0 && strcmp(destid, "KST")!=0 && strcmp(destid, "LER")!=0 && strcmp(destid, "KAR")!=0 && strcmp(destid, "SYM")!=0 && strcmp(destid, "XAL")!=0 && strcmp(destid, "TIL")!=0 && strcmp(destid, "PSE")!=0 )
    {
        printf("\n\nInvalid destination code. Please try again.");
    }
    }while(strcmp(destid, "KOS")!=0 && strcmp(destid, "RHO")!=0 && strcmp(destid, "KAL")!=0 && strcmp(destid, "PAT")!=0 && strcmp(destid, "AST")!=0 && strcmp(destid, "KAS")!=0 && strcmp(destid, "KST")!=0 && strcmp(destid, "LER")!=0 && strcmp(destid, "KAR")!=0 && strcmp(destid, "SYM")!=0 && strcmp(destid, "XAL")!=0 && strcmp(destid, "TIL")!=0 && strcmp(destid, "PSE")!=0 );

    do//epilegei typo theshs
    {
        printf("\n\nPlease choose your seat type:\nDeck\nAirplane\nCabin:");
        scanf(" %14s", tupos_theshs);
        if(strcmp(tupos_theshs, "Deck")!=0 && strcmp(tupos_theshs, "Airplane")!=0 && strcmp(tupos_theshs, "Cabin")!=0)
        {
            printf("\nInvalid seat type. Please try again.");
        }
    }while(strcmp(tupos_theshs, "Deck")!=0 && strcmp(tupos_theshs, "Airplane")!=0 && strcmp(tupos_theshs, "Cabin")!=0);

    do//epilegei an thelei autokinhto
    {
       printf("\n\nWould you like a car ticket?(0.NO 1.YES)");
       scanf(" %d", &x);
       if(x!=0 && x!=1)
       {
            printf("\nInvalid choice. Please try again.");
       } 
    }while(x!=0 && x!=1);

    for(i=0; i<13; i++)//briskei poion kwdiko dialekse kai apothikeuei to arxiko kostos
    {
        if(strcmp(destid, proorismoi[i].kwdikos_lim)==0)
        {
            if(strcmp(tupos_theshs, "Deck")==0)
            {
                cost1=(float)proorismoi[i].katastroma;
            }else if(strcmp(tupos_theshs, "Airplane")==0)
            {
                cost1=(float)proorismoi[i].aeroporiko;
            }else
            {
                cost1=(float)proorismoi[i].kampina;
            }
            
            if(x==1)
            {
                cost1= cost1 + (float)proorismoi[i].autokinhto;
            }
        }
    }

    do//epilgei an thelei epistrofh
    {
        printf("\n\nDo you want a return ticket?(0.NO 1.YES)");
        scanf(" %d", &booked[userpointer][ar_taksidiwn[userpointer]].trip_type);
        if(booked[userpointer][ar_taksidiwn[userpointer]].trip_type!=0 && booked[userpointer][ar_taksidiwn[userpointer]].trip_type!=1)
        {
            printf("\nInvalid choice. Please try again.");
        }
    }while(booked[userpointer][ar_taksidiwn[userpointer]].trip_type!=0 && booked[userpointer][ar_taksidiwn[userpointer]].trip_type!=1);

    if(booked[userpointer][ar_taksidiwn[userpointer]].trip_type==1)
    {
    
        do//afou thelei epistrofh ypologizoume to teliko kostos
        {
            printf("\n\nPlease insert the return date(dd:mm:yyyy):");
            scanf(" %d:%d:%d", &booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.dd, &booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.mm, &booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.year );
            x=valid_date(booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.dd, booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.mm, booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.year);  
            if(x==0)
            {
                printf("\n\nInvalid date. Please try again:");
            }else
            {
                i=compare_trips(booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.dd, booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.mm, booked[userpointer][ar_taksidiwn[userpointer]].hm_ep.year, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.dd, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.mm, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.year );
                if(i==0)
                {
                    printf("\n\nReturn date must be after depasrture date.");
                }else
                {
                    cost1=1.75*cost1;
                }
            }
        
        }while(x!=1 || i!=1);

    }   

    if(customers[userpointer].university_student==0)//ekptwsh foititi
    {
        cost1=0.5*cost1;
    }

    booked[userpointer][ar_taksidiwn[userpointer]].kostos=cost1;//apothikeush sunolikou kostous kai arxikopoioume katastash se ekremh

    booked[userpointer][ar_taksidiwn[userpointer]].katastash=0;

    generate_trip_ID(booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.dd, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.mm, booked[userpointer][ar_taksidiwn[userpointer]].hmeromhnia.year, destid);

    ar_taksidiwn[userpointer]=ar_taksidiwn[userpointer]+1;//aujanete o arithmos tajidiwn tou xristh

    flag=2;

}


int valid_date(int d, int m, int y)//elegxos gia mhnes pou exoun 31 h 30 meres kai elegxos gia disekta etoi
{
    int x=0;
    if(y>=2024 && y<=2050 && m>0 && m<=12 && d>0 && d<=31)
    {

        if((m==2 || m==4 || m==6 || m==9 || m==11) && d==31)
        {
            return 0;	
        }else if (m==2 && d==30)
        {
            return 0;
        }else if (m==2 && d==29 && y%4!=0)
        {
            return 0;
        }else
        {
            return 1;
        }
    }else
    {
        return 0;
    }
}

int compare_trips(int d1, int m1, int y1, int d2, int m2, int y2)//ta 1 exoun tis hmerominies pou edwse twra o xrisths kai ta 2 tou prohgoumenou taksidiou tou idiou user kai elegxei an oihmerominia einai pio meta apo thn pohgoumenh
{
    if(y1>y2)//elegxei prwta etos meta mhna meta mera
    {
        return 1;
    }else if(y1<y2)
    {
        return 0;
    }else
    {
        if(m1>m2)
        {
            return 1;
        }else if(m1<m2)
        {
            return 0;
        }else
        {
            if(d1>d2)
            {
                return 1;
            }else if(d1<=d2)
            {
                return 0;
            }
        }
    }
}

void generate_trip_ID(int d, int m , int y, char destid[5])//dhmiourgia anagnwristikou
{
    char stra[40], str[5];
    sprintf(str, "%d", d);//h entolh sprintf metatrepei mia metablhth typou int se string
    if(d<10)
    {       
        strcat(stra, "0");//h entolh strcat sygxwnuei sto prwto orisma kai to deytero    
    }
    strcat(stra, str);//bazoume thn mera

    sprintf(str, "%d", m);
    if(m<10)
    {       
        strcat(stra, "0");      
    }
    strcat(stra, str);//bazoume ton mhna

    sprintf(str, "%d", y);
    strcat(stra, str);//bazoume ton xrono

    strcat(stra, destid);//bazoume ton kwdiko nhsiou
    strcat(stra, "-");
    strcat(stra, customers[userpointer].username);//bazoume to username

    strcpy(booked[userpointer][ar_taksidiwn[userpointer]].anagnwristiko, stra);//to apothikeuoyme sthn metablhth 

}

void payment()
{
    int i, x=0;
    char check[40];
    for(i=0; i<ar_taksidiwn[userpointer]; i++)//elegxoyme an yparxoun aplhrwta tajidia kai ta emfanizopume
    {
        if(booked[userpointer][i].katastash==0)
        {
            printf("\n\nUsername: %s", booked[userpointer][i].username);
            printf("\nUnique trip code: %s", booked[userpointer][i].anagnwristiko);
            printf("\nTotal cost: %.2f", booked[userpointer][i].kostos);
            printf("\nDeparture date: %d/%d/%d", booked[userpointer][i].hmeromhnia.dd, booked[userpointer][i].hmeromhnia.mm, booked[userpointer][i].hmeromhnia.year);
            if(booked[userpointer][i].trip_type==1)
            {
                printf("\nReturn date: %d/%d/%d", booked[userpointer][i].hm_ep.dd, booked[userpointer][i].hm_ep.mm, booked[userpointer][i].hm_ep.year);
            }
        }
    }

    do//dialegei poio tajidi tha plhrwsei
    {
        printf("\nPlease give the unique trip code you want to pay:");
        scanf(" %19s", check);
        i=0;
        do
        {
            if(strcmp(check, booked[userpointer][i].anagnwristiko)==0)
            {
                printf("\n\n\nPayment succeded.");
                booked[userpointer][i].katastash=1;
                x=1;
            }
            i++;
        }while(x==0 && i<ar_taksidiwn[userpointer]);
        if(x==0)
        {
            printf("\nInvalid unique trip code. Please try again.");
        }
    }while(x==0);
}

void confirmed_trips()
{
    char x[5];
    int i;
    do
    {
        printf("\n\nPlease press 'LOW' for decreasing or 'HIGH' for increasing list of your confirmed trips:");//epilegei aujousa h fthinousa seira emfaniseis plhrwmenwn tajidiwn 
        scanf(" %4s", x);
        if(strcmp(x, "LOW")!=0 && strcmp(x, "HIGH")!=0)
        {
            printf("/nPlease try again.");
        }
    }while(strcmp(x, "LOW")!=0 && strcmp(x, "HIGH")!=0);

    if(strcmp(x, "HIGH")==0)//emfanish kata aujousa arxikh hmerominia
    {
        for(i=0; i<ar_taksidiwn[userpointer]; i++)
        {
            if(booked[userpointer][i].katastash==1)
            {
                printf("\n\nUsername: %s", booked[userpointer][i].username);
                printf("\nUnique trip code: %s", booked[userpointer][i].anagnwristiko);
                printf("\nTotal cost: %.2f", booked[userpointer][i].kostos);
                printf("\nDeparture date: %d/%d/%d", booked[userpointer][i].hmeromhnia.dd, booked[userpointer][i].hmeromhnia.mm, booked[userpointer][i].hmeromhnia.year);
                if(booked[userpointer][i].trip_type==1)
                {
                    printf("\nReturn date: %d/%d/%d", booked[userpointer][i].hm_ep.dd, booked[userpointer][i].hm_ep.mm, booked[userpointer][i].hm_ep.year);
                }
            }
        }
    }else//emfanish kata fthinousa arxikh hmerominia
    {
        for(i=ar_taksidiwn[userpointer]-1; i>=0; i--)
        {
            printf("\n\nUsername: %s", booked[userpointer][i].username);
            printf("\nUnique trip code: %s", booked[userpointer][i].anagnwristiko);
            printf("\nTotal cost: %.2f", booked[userpointer][i].kostos);
            printf("\nDeparture date: %d/%d/%d", booked[userpointer][i].hmeromhnia.dd, booked[userpointer][i].hmeromhnia.mm, booked[userpointer][i].hmeromhnia.year);
            if(booked[userpointer][i].trip_type==1)
            {
                printf("\nReturn date: %d/%d/%d", booked[userpointer][i].hm_ep.dd, booked[userpointer][i].hm_ep.mm, booked[userpointer][i].hm_ep.year);
            }
        }
    }
}
