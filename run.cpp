				  // class size= +5
int tUID ;
char cho ;
int res=0 ;

int dprtmnt() ;
void start() ;
int authenticate() ;
void Register() ;
void printall() ;
void printone() ;
void edit_det() ;
void del_det() ;
void terminate() ;
void RegisterD() ;
void printallD() ;
void printoneD() ;
void edit_detD() ;
void del_detD() ;
void findadoctor() ;
void lookapatient() ;

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>

class Patient
{
 float age ;
 char Bgrp[5] ;
 char city[25] ;
 char sex ;
 float rmno ;

public :
 int UID   ;
 char name[25] ;
 char prblm[30] ;
 char doc[25] ;

 void input();
 void printal();
 void print1();
 int chkUID();
 void bgrp() ;
 void edit_input() ;
 Patient();
 int search() ;
}Pt ;

class Doctor
{
 float age ;
 char Bgrp[5] ;
 char city[25] ;
 char sex ;
 float rmno ;

public :
 int UID   ;
 char name[25] ;
 char spec[30] ;
 char pat[25] ;

 void input();
 void printal();
 void print1();
 int chkDUID();
 void bgrp() ;
 void edit_input() ;
 Doctor();
 int search() ;

}Dt ;


int Doctor::search()
{
  return(UID) ;
}

void Doctor::edit_input()
{
  cout<<"\n\n\t Enter Doctor Name  :  " ;
	gets(name) ;
  cout<<"\n\n\t Enter Age           :  " ;
	cin>>age ;
  cout<<"\n\n\t Enter City          :  " ;
	gets(city) ;
  bgrp() ;
  cout<<"\n\n\t Enter Gender( 1-M/2-F )  :  ";
	cin>>cho ;
	 if(cho=='1')
		 sex='M' ;
	 else if(cho=='2')
		 sex='F' ;
	 else
		 sex='N' ;

  UID=tUID ;
  rmno=UID-99 ;
  cout<<"\n\n\t Enter Your Speciality.............  " ;
  res=dprtmnt() ;

  switch(res)
	{
	 case 1 : strcpy(spec , "ENTSpecialist" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  getch() ;
					  break ;

	 case 2 : strcpy(spec , "Physiologist " ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  getch() ;
					  break ;

	 case 3 : strcpy(spec , "Dentist " ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  getch() ;
					  break ;

	 case 4 : strcpy(spec ,"InfectiousDeseaseSpecialist" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  getch() ;
					  break ;


	 case 5 : strcpy(spec , "Pediatrician" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  getch() ;
					  break ;

	 case 6 : strcpy(spec , "Surgeon" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  getch() ;
					  break ;

	 default : cout<<"\n\n\t Try Again>................. " ;
						exit(1) ;

	 }


}


Doctor::Doctor()
{
UID=0 ;
strcpy(Bgrp,"none") ;
strcpy(pat,"none" ) ;
strcpy(spec,"none") ;
}

void Doctor::input()
{
cout<<" _____________________________________________________________________________ \n" ;
cout<<" -----------------------------------------------------------------------------  \n" ;
cout<<"\t REGISTER DOCTOR  \n" ;
cout<<" _____________________________________________________________________________ " ;
cout<<" -----------------------------------------------------------------------------  " ;


  cout<<"\n\n\t Enter Doctor Name   :  " ;
	gets(name) ;
  cout<<"\n\n\t Enter Age           :  " ;
	cin>>age ;
  cout<<"\n\n\t Enter City          :  " ;
	gets(city) ;

	bgrp() ;

  cout<<"\n\n\t Enter Gender( 1-M/2-F )  :  ";
	cin>>cho ;
  if(cho=='1')
	sex='M' ;
  else if(cho=='2')
	sex='F' ;
  else
   sex='N' ;

  cout<<"\n\n\t Enter Your Speciality.............  " ;

  res=dprtmnt()  ;

  switch(res)
  {
	case 1 : strcpy(spec , "ENTSpecialist" ) ;                         // 14
				cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  break ;

	case 2 : strcpy(spec , "Physiologist " ) ;                           // 13
				cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  break ;

	case 3 : strcpy(spec , "Dentist " ) ;                               // 8
				cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  break ;

	case 4 : strcpy(spec ,"InfectiousDeseaseSpecialist" ) ;         //29
				cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  break ;

	case 5 : strcpy(spec , "Pediatrician" ) ;                        // 12
				cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  break ;

	case 6 : strcpy(spec , "Surgeon" ) ;                         // 7
				cout<<"\n>>>>>>>>: YOU CHOSE :  " <<spec ;
					  break ;

	default : cout<<"\n\n\t Try Again>................. " ;
					 exit(1) ;

	}

UID=chkDUID() ;
rmno=UID-99 ;

		cout<<"\n>>>>>>>>: YOUR UID NO. IS : "<<UID ;

		cout<<"\n>>>>>>>>: YOU ARE ALLOTED ROOM NO. : "<<rmno ;
}


void Doctor::print1()
{
cout<<"\n\n\t  Doctor Name      : "<<name  ;
cout<<"\n\n\t  Doctor UID No.   : "<<UID ;
cout<<"\n\n\t  Doctor Age       : "<<age ;
cout<<"\n\n\t  Sex              : "<<sex ;
cout<<"\n\n\t  Blood Group      : "<<Bgrp ;
cout<<"\n\n\t  From City        : "<<city ;
cout<<"\n\n\t  Room No.         : "<<rmno ;
cout<<"\n\n\t  Speciality       : "<<spec ;
cout<<"\n\n\t  Patient          : "<<pat ;
}

int Doctor::chkDUID()
{
  ifstream fin("Dpin.dat" , ios::in ) ;
  if(!fin)
  {
	 ofstream fout("Dpin.dat" , ios::out ) ;
	 fout<<"100" ;
	 fout.close() ;
	 fin.close() ;
	 return(100) ;
  }
  else
  {
	int ch ,temp ;
	ifstream fin("Dpin.dat") ;
	fin>>(ch) ;
	fin.close() ;
	ofstream fout("Dpin.dat") ;
	temp=ch+1 ;
	fout<<(temp) ;
	fout.close() ;
	return(temp) ;
  }
}

void Doctor::bgrp()
{
  cout<<"\n\t BLOOD GROUP :  \n\t" ;
  cout<<"1. A+ \n\t" ;
  cout<<"2. A- \n\t" ;
  cout<<"3. B+ \n\t" ;
  cout<<"4. B- \n\t" ;
  cout<<"5. AB+\n\t" ;
  cout<<"6. AB-\n\t" ;
  cout<<"7. O+ \n\t" ;
  cout<<"8. O- \n\t" ;
  cout<<"\n\t Enter Choice(1-8) : " ;
  cin>>cho ;
	switch(cho)
	 {
		case '1' : strcpy(Bgrp , "A+" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		case '2' :  strcpy(Bgrp , "A-" ) ;
						cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		case '3' :  strcpy(Bgrp , "B+" ) ;
						cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		case '4' :  strcpy(Bgrp , "B-" ) ;
						cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		case '5' :  strcpy(Bgrp , "AB+" ) ;
						cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		case '6' :  strcpy(Bgrp , "AB-" ) ;
						cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		case '7' :  strcpy(Bgrp , "O+" ) ;
						cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		case '8' :  strcpy(Bgrp , "O-" ) ;
						cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

		}
}

void Doctor::printal()
{
int y  ;
y=wherey() ;
gotoxy(1,y) ; cout<<"\f  ";
cout<<UID<<"   " ;
gotoxy(8,y ) ; cout<<"|";
cout<<"   "<<name<<"\t\t" ;
gotoxy(26,y) ; cout<<" | "<<Bgrp ;
gotoxy(32,y) ; cout<<" | "  ;
gotoxy(34,y) ;	cout<<age    ;
gotoxy(37,y) ; cout<<"  |"<<"\t"<<rmno<<"   |\t"<<sex<<"   | "<<city   ;
gotoxy(65,y) ; cout<<"| "<<spec ;
gotoxy(79,y) ; cout<<"\f" ;
cout<<"\n"  ;
cout<<"\f-----------------------------------------------------------------------------\f  "  ;
}

int Patient::search()
{
 return(UID) ;
}

void Patient::edit_input()
{
  cout<<"\n\n\t Enter Patient Name  :  " ;
	gets(name) ;
  cout<<"\n\n\t Enter Age           :  " ;
	cin>>age ;
  cout<<"\n\n\t Enter City          :  " ;
	gets(city) ;
	bgrp() ;
  cout<<"\n\n\t Enter Gender( 1-M/2-F )  :  ";
	cin>>cho ;
	if(cho=='1')
	 sex='M' ;
	else if(cho=='2')
	 sex='F' ;
	else
	 sex='N' ;

	UID=tUID ;
	rmno=UID-99 ;

	cout<<"\n\n\t Enter Your Problem..................  " ;

	res=dprtmnt()  ;

	switch(res)
	{
	 case 1 : strcpy(prblm , "ENTSpecialist" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 2 : strcpy(prblm , "Physiologist " ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;
	 case 3 : strcpy(prblm , "Dentist " ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 4 : strcpy(prblm ,"InfectiousDeseaseSpecialist" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 5 : strcpy(prblm , "Pediatrician" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 6 : strcpy(prblm , "Surgeon" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 default : cout<<"\n\n\t Try Again>................. " ;
						exit(1) ;

 }
}
Patient::Patient()
{
 UID=0 ;
 strcpy(Bgrp,"none") ;
 strcpy(prblm , "none" );
 strcpy(doc , "none");
 }

void Patient::input()
{
cout<<" _____________________________________________________________________________ \n" ;
cout<<" -----------------------------------------------------------------------------  \n" ;
cout<<"\t REGISTER PATIENT  \n" ;
cout<<" _____________________________________________________________________________ " ;
cout<<" -----------------------------------------------------------------------------  " ;

  cout<<"\n\n\t Enter Patient Name  :  " ;
	gets(name) ;
  cout<<"\n\n\t Enter Age           :  " ;
	cin>>age ;
  cout<<"\n\n\t Enter City          :  " ;
	gets(city) ;
  bgrp() ;
  cout<<"\n\n\t Enter Gender( 1-M/2-F )  :  ";
	cin>>cho ;
  if(cho=='1')
	sex='M' ;
  else if(cho=='2')
	sex='F' ;
  else
	cout<<"\n\n\t Try Again.........  " ;

	cout<<"\n\n\t What Kind Of Doctor Are You Looking For ???  " ;
	res=dprtmnt() ;

 switch(res)
  {
	 case 1 : strcpy(prblm , "ENTSpecialist" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 2 : strcpy(prblm , "Physiologist " ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break;

	 case 3 : strcpy(prblm , "Dentist " ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 4 : strcpy(prblm ,"InfectiousDeseaseSpecialist" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 5 : strcpy(prblm , "Pediatrician" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

	 case 6 : strcpy(prblm , "Surgeon" ) ;
					  cout<<"\n>>>>>>>>: YOU CHOSE :  " <<prblm ;
					  break ;

		  default : cout<<"\n\n\t Try Again>................. " ;
						exit(1) ;
	}

 UID=chkUID() ;
 rmno=UID-99 ;

 cout<<"\n>>>>>>>>: YOUR UID NO. IS : "<<UID ;

 cout<<"\n>>>>>>>>: YOU ARE ALLOTED ROOM NO. : "<<rmno ;


}
void Patient::print1()
{
cout<<"\n\n\t  Patient Name     : "<<name  ;
cout<<"\n\n\t  Patient UID No.  : "<<UID ;
cout<<"\n\n\t  Patient Age      : "<<age ;
cout<<"\n\n\t  Sex              : "<<sex ;
cout<<"\n\n\t  Blood Group      : "<<Bgrp ;
cout<<"\n\n\t  From City        : "<<city ;
cout<<"\n\n\t  Room No.         : "<<rmno ;
cout<<"\n\n\t  Admitted To      : "<<prblm ;
cout<<"\n\n\t  Reffered         : "<<doc ;
}

int Patient::chkUID()
{
 ifstream fin("pin.dat" , ios::in ) ;
 if(!fin)
 {
  ofstream fout("pin.dat" , ios::out ) ;
  fout<<"100" ;
  fout.close() ;
  fin.close() ;
  return(100) ;
 }
 else
 {
  int ch  , temp ;
  ifstream fin("pin.dat") ;
  fin>>(ch) ;
  fin.close() ;
  ofstream fout("pin.dat") ;
  temp=ch+1 ;
  fout<<(temp) ;
  fout.close() ;
  return(temp) ;
 }
}

void Patient::bgrp()
{
cout<<"\n\t BLOOD GROUP :  \n\n\t" ;
cout<<"1. A+ \n\t" ;
cout<<"2. A- \n\t" ;
cout<<"3. B+ \n\t" ;
cout<<"4. B- \n\t" ;
cout<<"5. AB+\n\t" ;
cout<<"6. AB-\n\t" ;
cout<<"7. O+ \n\t" ;
cout<<"8. O- \n\t" ;
cout<<"\n\t Enter Choice(1-8) : " ;
cin>>cho ;
  switch(cho)
	{
	  case '1' :  strcpy(Bgrp , "A+" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

	  case '2' :  strcpy(Bgrp , "A-" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

	  case '3' :  strcpy(Bgrp , "B+" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

	  case '4' :  strcpy(Bgrp , "B-" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

	  case '5' :  strcpy(Bgrp , "AB+" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

	  case '6' :  strcpy(Bgrp , "AB-" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

	  case '7' :  strcpy(Bgrp , "O+" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;

	  case '8' :  strcpy(Bgrp , "O-" ) ;
							 cout<<"\n>>>>>>>>: YOU CHOSE :  Blood Group   : "<<Bgrp  ;
							 break ;
	}
}

void Patient::printal()
{
int y  ;
y=wherey() ;
gotoxy(1,y) ; cout<<"\f  ";
cout<<UID<<"   " ;
gotoxy(8,y ) ; cout<<"|";
cout<<"   "<<name<<"\t\t" ;
gotoxy(26,y) ; cout<<" | "<<Bgrp ;
gotoxy(32,y) ;cout<<" | "  ;
gotoxy(34,y) ;	cout<<age  ;
gotoxy(37,y) ;cout<<"  |"<<"\t"<<rmno<<"  |\t"<<sex<<"   |\t"<<city   ;
gotoxy(65,y) ; cout<<"| "<<prblm ;
gotoxy(79,y) ; cout<<"\f" ;
cout<<"\n"  ;
cout<<"\f-----------------------------------------------------------------------------\f  "  ;
}


void main()
{
 start() ;

 if(authenticate()==1)
 {
  cout<<"\n\n\t Login Successful ! ( Press Any Key To Continue )   " ;
	  getch() ;
  clrscr() ;
  cout<<"\n\n\n\n\t\t";
  cout<<" 1. Patient Database  \n\n\n\t\t" ;
  cout<<" 2. Doctors Database  \n\n " ;
  cout<<"\n\n\t Enter Your Choice  :  " ;
	cin>>cho ;
  if(cho=='2')
	{
	 clrscr() ;
 do
  {  doctor :

	  clrscr() ;
	  cout<<"\n\n\t\t";
	  cout<<"  B.A.D Hospital Authority           \n\t\t";
	  cout<<"  ***** ******** *********           \n\n\t";
	  cout<<" 1.  Register Doctor                 \n\n\t";
	  cout<<" 2.  Print All Doctor Details        \n\n\t";
	  cout<<" 3.  Edit  Doctor Details            \n\n\t";
	  cout<<" 4.  Search Doctor (UID reqd.)       \n\n\t";
	  cout<<" 5.  Deleting Doctor Record          \n\n\t";
	  cout<<" 6.  Return To Patient Database      \n\n\t";
	  cout<<" 7.  Look At Patients                \n\n\t";
	  cout<<" 8.  Exit                            \n\n\t";


	  cout<<" Enter Your Choice  :  ";
	  cho=getch() ;

	  switch(cho)
				{

				case '1' :  clrscr();
								RegisterD();
										break ;

				case '2' :  clrscr();
								printallD();
										break ;

				case '3' :  clrscr();
								edit_detD();
										break ;

				case '4' :  clrscr();
								cout<<"\n\n\t Searching Doctor Record \n  " ;
								cout<<"\t ******** ******* ******  ";
								printoneD();
										break ;


				case '5' :  clrscr();
								cout<<"\n\n\t Deleting Doctor Record \n  " ;
								cout<<"\t ******** ******* ******  ";
								del_detD();
										break ;

				case '6' : goto patient ;


				case '7' :  clrscr();
                        cout<<"\n\n\t Assigning a Patient \n  " ;
								cout<<"\t ******** ******* ******  ";
								lookapatient();
										break ;

				default  :  clrscr() ;
								cout<<"\n\n\t Wrong Option Try Again.........  ";
				}

 }while(cho!='8');
	  }
	  else if(cho=='1')
	  {
do
{    patient :

	  clrscr() ;
	  cout<<"\n\n\t\t";
	  cout<<"  B.A.D Hospital Authority            \n\t\t";
	  cout<<"  ***** ******** *********            \n\n\t";
	  cout<<" 1.  Register Patient                 \n\n\t";
	  cout<<" 2.  Print All Patient Details        \n\n\t";
	  cout<<" 3.  Edit  Patient Details            \n\n\t";
	  cout<<" 4.  Search Patient (UID reqd.)       \n\n\t";
	  cout<<" 5.  Deleting Patient Record          \n\n\t";
	  cout<<" 6.  Return to Doctors Database       \n\n\t";
	  cout<<" 7.  Find A Doctor                    \n\n\t";
	  cout<<" 8.  Exit                             \n\n\t";



	  cout<<" Enter Your Choice  :  ";
	  cho=getch() ;

	  switch(cho)
				{

				case '1' :  clrscr();
										Register();
										break ;

				case '2' :  clrscr();
								printall();
										break ;

				case '3' :  clrscr();
								edit_det();
										break ;

				case '4' :  clrscr();
								cout<<"\n\n\t Searching Patient Record \n  " ;
								cout<<"\t ******** ******* ******  ";
								printone();
										break ;


				case '5' :  clrscr();
								cout<<"\n\n\t Deleting Patient Record \n  " ;
								cout<<"\t ******** ******* ****** " ;
								del_det();
										break ;

				case '6' :  goto doctor ;


				case '7' :  clrscr();
								cout<<"\n\n\t Assigning a Doctor \n" ;
								cout<<"\t ********* * ****** " ;
								findadoctor();
										break ;

				default  :  clrscr() ;
								cout<<"\n\n\t Wrong Option Try Again.........  ";
				}

 }while(cho!=8);

 }

  }  // if authencate==true

	else
	  {
		cout<<"\n\n\t  You Have Entered Wrong ID or Password . Kindly  \n" ;
		cout<<"\t  Execute The Program Again And Try Again Lator........  \n\n" ;
		cout<<"\t*** Thank You for being here. ***   " ;
		}


}   // main() Ends here..........

void Register()
{
 fstream fobj ;
 fobj.open("Patientt.dat" , ios::out | ios::app | ios::binary ) ;
do
  {  clrscr() ;
	  Pt.input() ;
	  fobj.write((char*)&Pt,sizeof(Patient) ) ;
	  cout<<"\n\n\t Patient Record Saved Successfully  " ;
	  cout<<"\n\n\t Want to Register 1 More Patient( Y/N )   :    " ;
			cin>>cho ;
  }while(cho=='Y' || cho=='y') ;

  fobj.close();
  cout<<"\n\n\t Please Press Any Key To Continue........ " ;
  getche() ;
}

void printall()
{
cout<<" _____________________________________________________________________________ \n" ;
cout<<" -----------------------------------------------------------------------------  \n" ;
cout<<"\t PRINTING ENTIRE PATIENT DETAILS  \n" ;
cout<<" _____________________________________________________________________________ " ;
cout<<" -----------------------------------------------------------------------------  " ;

fstream fobj ;
fobj.open("Patientt.dat" , ios::in , ios::binary );

cout<<"\n\n";
for( res=0 ; res<79 ; ++res )cout<<"\f" ;	cout<<"\n" ;
cout<<"\f UID  " ;
cout<<"|   NAME\t\t";
cout<<"  |" ;
cout<<" BG" ;
cout<<" | AGE |\tRMO. |\tSEX | City" ;
cout<<"      | LookingFOR  \f\n" ;
for( res=0 ; res<79 ; ++res )cout<<"\f" ; cout<<"\n" ;

while(fobj.read((char*)&Pt , sizeof(Patient) ))
{
  Pt.printal();
}
  fobj.close();

  for( res=0 ; res<79 ; ++res ) cout<<"\f" ; cout<<"\n" ;

  cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
  getche();

}

void RegisterD()
{
  fstream fobj ;
  fobj.open("Doctorr.dat" , ios::out | ios::app | ios::binary ) ;

do
{
  clrscr() ;
  Dt.input() ;
  fobj.write((char*)&Dt,sizeof(Doctor) ) ;
  cout<<"\n\n\t Saved Successfully  " ;
  cout<<"\n\n\t Want to Register 1 More Patient( Y/N )   :    " ;
  cin>>cho ;
}while(cho=='Y' || cho=='y') ;

fobj.close();
cout<<"\n\n\t Please Press Any Key To Continue........ " ;
getche() ;

}

void printallD()
{
cout<<" _____________________________________________________________________________ \n" ;
cout<<" -----------------------------------------------------------------------------  \n" ;
cout<<"\t PRINTING ENTIRE DOCTOR DETAILS  \n" ;
cout<<" _____________________________________________________________________________ " ;
cout<<" -----------------------------------------------------------------------------  " ;

fstream fobj ;
fobj.open("Doctorr.dat" , ios::in , ios::binary );

cout<<"\n\n";
for( res=0 ; res<79 ; ++res )cout<<"\f" ;cout<<"\n" ;
cout<<"\f UID  " ;
cout<<"|   NAME\t\t";
cout<<"  |" ;
cout<<" BG" ;
cout<<" | AGE |\tRMO. |\tSEX | City" ;
cout<<"      | Speciality  \f\n" ;
for( res=0 ; res<79 ; ++res )cout<<"\f" ;cout<<"\n" ;

while(fobj.read((char*)&Dt , sizeof(Doctor) ))
{
  Dt.printal();
}
fobj.close();


  for( res=0 ; res<79 ; ++res ) cout<<"\f" ; cout<<"\n" ;

 cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
 getche();

}

int authenticate()
{
  int i , x , y ;
  char id[25]="hell" , tid[25] ;
  char pas[25]="heaven" , tpas[25]="ooooooooo" ;

  cout<<"\n\n\n\t  USERNAME : " ;
  gets(tid) ;

  cout<<"\n\n\t  PASSWORD : " ;
  for(i=0 ; tpas[i]!='\0' ; ++i )
  {
	tpas[i]=getch();
	if(tpas[i]==13)
	break ;
	putch('*');
  }
  tpas[i]='\0' ;
  x=strcmp(tid , id ) ;
  y=strcmp(tpas , pas) ;
  if( x==0 && y==0 )
	  return(1) ;
  else
	  return(0) ;
}





void printone()
{
int l=0 ;
fstream fobj ;
fobj.open("Patientt.dat" , ios::in ) ;
cout<<"\n\n\t Enter Patient UID No. " ;
cin>>tUID ;
l=(((tUID-99)*121)-121) ;
fobj.seekg( l , ios::beg ) ;
fobj.read( (char*)&Pt , sizeof(Patient) ) ;
Pt.print1() ;
cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
getche();
fobj.close() ;
}

void printoneD()
{
int l=0 ;

fstream fobj ;
fobj.open("Doctorr.dat" , ios::in ) ;
cout<<"\n\n\t Enter Doctor UID No. " ;
cin>>tUID ;
l=(((tUID-99)*121)-121) ;
fobj.seekg( l , ios::beg ) ;
fobj.read( (char*)&Dt , sizeof(Doctor) ) ;
Dt.print1() ;
cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
getche();
fobj.close() ;
}


void edit_det()
{
cout<<" _____________________________________________________________________________ \n" ;
cout<<" -----------------------------------------------------------------------------  \n" ;
cout<<"\t EDITING A PATIENT RECORD  \n" ;
cout<<" _____________________________________________________________________________ " ;
cout<<" -----------------------------------------------------------------------------  " ;
int k ;
printone() ;
k=(((tUID-99)*121)-121) ;
fstream fobj ;
fobj.open("Patientt.dat" , ios::in | ios::out ) ;
cout<<"\n\t Are You Sure You Want To Edit This Record(y/n) " ;
cin>>cho ;
if(cho=='y' || cho=='Y' )
 {
  fobj.seekp( k , ios::beg ) ;
  cout<<"\n\n\t Now Re-input Patient Details " ;
  Pt.edit_input() ;
  fobj.write((char*)&Pt , sizeof(Patient) ) ;
  fobj.seekp(0 , ios::end ) ;
  fobj.close() ;
  cout<<"\n\n\tSuccessfully Done " ;
  cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
  getche();
 }
 else
 {
  cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
  getche();
 }
}

void edit_detD()
{
cout<<" _____________________________________________________________________________ \n" ;
cout<<" -----------------------------------------------------------------------------  \n" ;
cout<<"\t EDITING A DOCTOR RECORD  \n" ;
cout<<" _____________________________________________________________________________ " ;
cout<<" -----------------------------------------------------------------------------  " ;

int k ;
printoneD() ;
k=(((tUID-99)*121)-121) ;
fstream fobj ;
fobj.open("Doctorr.dat" , ios::in | ios::out ) ;
cout<<"\n\n\t Are You Sure You Want To Edit This Record(y/n) " ;
cin>>cho ;
if(cho=='y' || cho=='Y' )
  {
	fobj.seekp( k , ios::beg ) ;
	cout<<"\n\n\t Now Re-input Doctor Details " ;
	Dt.edit_input() ;
	fobj.write((char*)&Dt , sizeof(Doctor) ) ;
	fobj.seekp(0 , ios::end ) ;
	fobj.close() ;
	cout<<"\n\n\tSuccessfully Done " ;
	cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
	getche();
  }
  else
  {
	cout<<"\n\n  Please Enter Any Key To Continue \BE...... " ;
	getche();
  }
}

void del_det()
{
fstream fin,fout;
fin.open("Patientt.dat",ios::in|ios::binary);
fout.open("temp.dat",ios::out|ios::binary);
		int tUID;
		char found='f';
		int confirm=0 ;
		cout<<endl<<"Enter the UID. No. of the Student whose Record is to be Deleted:";
		cin>>tUID;

		while(fin.read((char*)&Pt,sizeof(Patient)))
		{
			if(tUID==Pt.search())
				{
					Pt.print1();
					found='t';
					cout<<"\nConfirmation of Deletion(1 to Delete, 0 to Cancel)";
					cin>>confirm;
					if(confirm==0)
						{
						fout.write((char*)&Pt,sizeof(Patient));
						}
					else
						{
						cout<<"\n\n\t The Student Record is Deleted...\n";
						ofstream fout("pin.dat") ;
						fout<<(tUID-1) ;
						fout.close() ;
						}
				}
			else
				fout.write((char*)&Pt,sizeof(Patient));
		}
		if(found=='f')
		cout<<endl<<"Student Record Not Found...\n";
		fin.close();
		fout.close();
		remove("Patientt.dat");
		rename("temp.dat","Patientt.dat");
		cout<<"\n Press any key to continue...";
		getche();
}
void del_detD()
{
fstream fin,fout;
fin.open("Doctorr.dat",ios::in|ios::binary);
fout.open("Dtemp.dat",ios::out|ios::binary);
int tUID;
char found='f';
int confirm=0;
cout<<endl<<"Enter the UID. No. of the Doctor whose Record is to be Deleted:";
cin>>tUID;
while(fin.read((char*)&Dt,sizeof(Doctor)))
{
	if(tUID==Dt.search())
	{
	  Dt.print1();
	  found='t';
	  cout<<"\nConfirm The Deletion(1 to Delete, 0 to Cancel)";
	  cin>>confirm;
	  if(confirm==0)
	  {
		fout.write((char*)&Dt,sizeof(Doctor));
	  }
	  else
	  {
		 cout<<"\n\n\t The Doctor Record is Deleted...\n";
		 ofstream fout("Dpin.dat") ;
		 fout<<(tUID-1) ;
		 fout.close() ;
		}
	  }
	  else
		 fout.write((char*)&Dt,sizeof(Doctor));
}
if(found=='f')
cout<<endl<<"Doctor Record Not Found...\n";
fin.close();
fout.close();
remove("Doctorr.dat");
rename("Dtemp.dat","Doctorr.dat");
cout<<"\n Press any key to continue...";
getche();
}

void start()
{
cout<<"\n\n\n";
cout<<"\n\n";
cout<<"\t\t\t B.A.D Hospital Authority                      \n" ;
cout<<"\t\t\t ***** ******** *********                   \n\n " ;
cout<<"\t\t  Please Verify Yourself Before Logging In . \n"  ;
cout<<"\t\t   Enter Your Username And Password below    \n" ;
cout<<"\t\t     Provided To You By The Programmer      \n"  ;
cout<<"\n\t Username : hell  \n";
cout<<"\t Password : heaven  ";
cout<<"\n\t( Press Enter After Typing the Password ) ";
}

int dprtmnt()
{
cout<<"\n\n\t " ;
cout<<" 1. ENT Specialist                \n\t " ;
cout<<" 2. Physiologist                  \n\t " ;
cout<<" 3. Dentist                       \n\t " ;
cout<<" 4. Infectious Desease Specialist \n\t " ;
cout<<" 5. Pediatrician                  \n\t " ;
cout<<" 6. Surgeon                       \n\t " ;
cout<<"\n\n\t Enter Your Choice :  " ;
cin>>cho ;
switch(cho)
  {
	 case '1' :  return(1) ;

	 case '2' :  return(2) ;

	 case '3' :  return(3) ;

	 case '4' :  return(4) ;

	 case '5' :  return(5) ;

	 case '6' :  return(6) ;

	 default :  cout<<"\n\n\t Enter Proper Choice  ,Now Exitting........ " ;
							exit(1) ;
	 }
	 return(-1) ;
}

void findadoctor()
{
  int l=0 ;
  fstream fobjP , fobjD ;
  fobjP.open("Patientt.dat" , ios::in|ios::out|ios::binary) ;
  cout<<"\n\n\t Enter Patient UID No. " ;
  cin>>tUID ;
  l=(((tUID-99)*121)-121) ;
  fobjP.seekg( l , ios::beg ) ;
  fobjP.read( (char*)&Pt , sizeof(Patient) ) ;
  fobjD.open("Doctorr.dat" , ios::in|ios::out|ios::binary ) ;

  while(fobjD.read((char*)&Dt , sizeof(Doctor) ))
  {
	  if( strcmp(Dt.pat,"none")==0 )
	  {
		  if(strcmp(Pt.prblm , Dt.spec)==0)
		  {
			  strcpy(Pt.doc,Dt.name) ;
			  strcpy(Dt.pat , Pt.name) ;
			  fobjD.seekg( (((Dt.UID-99)*121)-121) , ios::beg ) ;
			  fobjD.write((char*)&Dt,sizeof(Doctor) ) ;
			  fobjP.seekg( l , ios::beg ) ;
			  fobjP.write((char*)&Pt,sizeof(Patient) ) ;
			  strcpy(Dt.pat,"none") ;
			  cout<<"\n\n\t Doctor Found!!! \n\n" ;
			  cout<<"\n\t Doctor Details : \n\n" ;
			  Dt.print1() ;
			  break ;
		  }

	  }
	  else ;
  }  // while loop end
  getch() ;
  fobjD.close() ;
  fobjP.close() ;
}
void lookapatient()
{
  int l=0 ;
  fstream fobjD , fobjP ;
  fobjD.open("Doctorr.dat" , ios::in|ios::out|ios::binary ) ;
  fobjP.open("Patientt.dat" ,ios::in|ios::out|ios::binary ) ;
  cout<<"\n\n\t Enter Doctor UID No. " ;
  cin>>tUID ;
  l=(((tUID-99)*121)-121) ;
  fobjD.seekg( l , ios::beg ) ;
  fobjD.read( (char*)&Dt , sizeof(Doctor) ) ;

  while(fobjP.read( (char*)&Pt , sizeof(Patient) ) )
  {
	 if( strcmp( Pt.doc,"none")==0 )
	  {
		  if(strcmp(Pt.prblm,Dt.spec)==0)
			 {
				strcpy(Dt.pat,Pt.name) ;
				strcpy(Pt.doc,Dt.name);
				fobjP.seekg( (((Pt.UID-99)*121)-121) , ios::beg ) ;
				fobjP.write((char*)&Pt,sizeof(Patient) ) ;
				fobjD.seekg( l , ios::beg ) ;
				fobjD.write((char*)&Dt,sizeof(Doctor) ) ;
				strcpy(Pt.doc,"none") ;

				cout<<"\n\n\t Patient Found!!! \n\n" ;
				cout<<"\n\t Patient Details : \n\n" ;
				Pt.print1() ;
				break ;
			 }
		  }

	 }
getch() ;
fobjD.close() ;
fobjP.close() ;
}
