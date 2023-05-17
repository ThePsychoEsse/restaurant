#include <iostream>
#include <iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include <fstream>
#include <string>
using namespace std;
///Logic Functions

   /// Update VA Insert Function
void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);

/// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

///Delete VA Count Function
void deletefood(int serial);
int countitem();




/// design Function

void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);


///START Structure

struct Node {

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};

typedef struct Node node;

node *head, *list;

int main()
{
	system("fast food iran");
	system("mode con: cols=88 lines=30");


	loadingbar(); cls();
	pwellcome();
	Sleep(300);
	cls();

	int c = 0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order = 0;
	int uquantity;
	int citem;

	head = NULL;
	insertfirst(1, "hamberger", 23, 25000);
	insertend(2, "chiz berger", 13, 32000);
	insertend(3, "sandwich sosis", 8, 20000);
	insertend(4, "morgh berian", 46, 50000);
	insertend(5, "pizza makhsos", 46, 60000);
	insertend(6, "sib zamini", 34, 17000);



mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); scanf("%d", &main_menu_choice);

	if ((main_menu_choice >= 1 && main_menu_choice <= 3)) {

		if (main_menu_choice == 2) {

		foodlist:

			cls();
			printf("=> 0. menu asli  ");
			foodlist();


		}

		else if (main_menu_choice == 1) {

		adminpanelchoice:

			int admin_panel_choice;

			cls(); middle1();   pre(4);  printf("1. menu asli \n\n\t"); Sleep(300);
			printf("lotfan ramze panel modiriat ra vared konid va ya adad 1 ra bezani va be menu beravid : ");


			fflush(stdin);  scanf("%d", &admin_panel_choice);

			if (admin_panel_choice == 1) {



				node *temp;

				temp = list;

			adminchoise:

				cls();  br(3); pre(4); echo(">>>> Admin Section <<<<   \n\n");
				pre(4);
				printf(" 1. mizane dar amade emroz \n\n"); Sleep(250); pre(4);
				printf(" 2. moshahede pardakhti ha be vasile cart banki \n\n"); Sleep(250); pre(4);
				printf(" 3.ezafe kardan ghaza be menu asli \n\n"); Sleep(250); pre(4);
				printf(" 4. pak kardan ghaza ha \n\n"); Sleep(250); pre(4);
				printf(" 5. menu asli\n\n"); Sleep(250); pre(4);
				printf(" 6. tedad mojodi ghaza \n\n"); Sleep(250); pre(4);
				printf(" 7. backup giri sari az system\n\n"); Sleep(250); pre(4);
				printf(" 8. namayesh sefaresh ha ye dar hale amade sazi\n\n"); Sleep(250); pre(4);
				printf(" 0. menu asli \n\n");
				printf("gozine mored nazar khod ra vared konid [1-0]: ");
				Sleep(250);

				int adminchoise;



				fflush(stdin);   scanf("%d", &adminchoise);

				if (adminchoise == 1) {

					cls();  middle1(); pre(4);   printf("mizane kole dar amad : %0.2f  \n", totalmoney);

					Sleep(2000);

					goto adminchoise;
				}
				else if (adminchoise == 2) {

					if (c != 0) {

						cls();  br(3); pre(4);

						printf(" ____________________________\n"); pre(4);
						printf("|   bedone cart.   |   pol |\n"); pre(4);
						printf("------------------------------\n"); pre(4);

						for (int z = 1; z <= c; z++) {

							printf("|  %d  | %0.2f |\n", cardno[z], cardmoney[z]); pre(4);
							printf("------------------------------\n"); pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if (c == 0) {

						cls();  middle1(); pre(4);
						printf("hich pardakhti ba cart banki vojod nadarad\n");
					}
					Sleep(2500);
					goto adminchoise;
				}

				else if (adminchoise == 3) {

				foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3); pre(4);      printf(" esme ghaza ye mored nazar ra vared konid :  ");

					fflush(stdin);     scanf("%[^\n]s", ffoodname);
				fquantity:
					fflush(stdin);

					br(2); pre(4);
					printf(" mizane kole mojodi ghable sefaresh ra vared konid :  ");

					scanf("%d", &fquantity); fflush(stdin);

				foodserial:
					br(2); pre(4);  printf(" shenase adadi ghaza ro vared konid :  ");
					scanf("%d", &fdata);
					node *exist;
					exist = list;
					while (exist->data != fdata) {
						if (exist->next == NULL) {
							break;
						}
						exist = exist->next;
					}
					if (exist->data == fdata) {
						cls(); br(5); pre(3);  printf(" in qhaza dar hale hazer mojod ast lotfan mojadadn talash talash konid  "); Sleep(4000);
						goto foodserial;
					}

				fprice:
					fflush(stdin);

					br(2); pre(4);  printf(" gheimat ra vared konid:  "); fflush(stdin);

					scanf("%f", &fprice);



					br(2); pre(4);  printf("zakhire kardan mahsol "); for (int cs = 0; cs < 4; cs++) { printf(" ."); Sleep(500); }


					insertend(fdata, ffoodname, fquantity, fprice);

					br(2); pre(4);      printf("ghaza ye jadid be menu shoma ba movafaghiyat zakhire shod.......\n");

					Sleep(4500);

					goto adminchoise;

				}
				else if (adminchoise == 4) {

					cls();
					middle1(); pre(2);
					printf("code ghaza ye mored nazar khod ra baraye hazf vared konid: ");
				fdelete:
					int fdelete;
					fflush(stdin); scanf("%d", &fdelete);
					node *temp;
					temp = list;
					while (temp->data != fdelete) {
						temp = temp->next;
					}
					if (temp->data == fdelete) {
						deletefood(fdelete);
					}
					else {
						br(2); pre(2); printf("lotfan adadi ro vared konid ke tarif shode bashad :  "); Sleep(500);
						goto fdelete;
					}


					goto adminchoise;
				}

				else if (adminchoise == 5) {

					cls();    foodlist(); Sleep(1000);

					br(2); pre(4);  printf("1. <-- bazgasht  \n\n"); pre(5);



					fflush(stdin);   scanf("%d", &any);

					goto adminchoise;

				}

				else if (adminchoise == 6) {

					citem = countitem();
					cls();
					for (int cs = 1; cs <= citem; cs++) {
						middle1(); pre(4);
						printf("shomare mavared");
						printf(" %d ", cs);
						Sleep(150);
						cls();
					}
					cls();
					middle1(); pre(4);
					printf("mizane kole mojodi barabar as ba --> %d  \n", citem); Sleep(4000);
					goto adminchoise;

				}

				///Backup System
				else if (adminchoise == 7) {


					char date[35] = __DATE__;

					strcat(date, ".txt");
					FILE *fptr;
					fptr = fopen(date, "w");
					backuploader();
					if (fptr == NULL) {
						br(3); pre(3); printf("motasefane moshkeli vojod darad!"); Sleep(500);
						goto adminchoise;
					}
					fprintf(fptr, "mizan forosho kole emroz : %0.2f\n\n\n", totalmoney);
					fprintf(fptr, "shomare cart------- mizan kharid \n\n");
					for (int l = 1; l <= c; l++) {
						fprintf(fptr, "%d ------- %0.2f \n", cardno[l], cardmoney[l]);
					}
					br(2); pre(4); printf("backup giri ba movafaghiyat anjam shod..."); Sleep(2000);



					fclose(fptr);
					goto adminchoise;
				}
				else if (adminchoise == 8) {

					cls(); br(2); pre(2);
					ccolor(26);
					printf("\n\t\t"); ccolor(240);
					printf("______________________________________________________ "); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("|  shomare sefaresh.  |   name ghaza | tedad|  baghi mande|"); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("------------------------------------------------------"); ccolor(26);
					for (int o = 1; o <= order; o++) {
						order_view(total_order[o], order_quantity[o], o);
					}

					br(2); pre(4);  printf("1. <-- bazgasht  \n\n"); pre(5);

					fflush(stdin);   scanf("%d", &any);

					goto adminchoise;



				}
				else if (adminchoise == 0) {

					goto mainmenu;
				}

				else {
					br(2); pre(4); printf("lotfan az mavared dakhel list entekhab konid :  "); Sleep(500);
					goto adminchoise;
				}



			}

			else if (admin_panel_choice == 1) {
				goto mainmenu;
			}
			else {
				br(2); pre(4);  printf("lotfan yek mored ra entekhab konid ke mojod bashad");
				goto adminpanelchoice;
			}

		}

		else if (main_menu_choice == 3) {
			cls();
			middle1(); pre(3); printf("mamnon az ink systeme maro estefade kardid. \n\t\t\t code nevisi shode tavasote seyed sajjad noori \n\n\n\n\n\n\n");
			Sleep(1000);

			exit(1);

		}

	}
	else {
		br(2); pre(4); printf("lotfan ghaza ye mojod va motabar ra entekhab konid"); Sleep(300);
		goto mainmenu;
	}


	int get_food_choice;


	br(2); pre(3); fflush(stdin);
	printf("sefaresh khod ra sabt konid: ");
	scanf("%d", &get_food_choice);

	if (get_food_choice == 0) {
		goto mainmenu;
	}

	node *temp;

	temp = list;

	while (temp->data != get_food_choice) {

		temp = temp->next;
		if (temp == NULL) {
			br(2); pre(4);  echo("lotfan az mavared dakhel list entekhab konid: "); br(2); Sleep(1000);
			goto foodlist;
		}

	}
	if (get_food_choice == temp->data) {

	fcquantity:
		br(2); pre(4);
		printf("tedad sefaresh : ");

		int fcquantity;

		fflush(stdin); scanf("%d", &fcquantity); cls();



		if (fcquantity == 0) {
			cls(); middle1(); pre(3); printf("tedad sefaresh nemitavanad az 0 kamtar bashad "); Sleep(3000);
			cls();
			goto foodlist;
		}
		else if (fcquantity > temp->quantity) {
			cls(); middle1(); pre(3); printf("tedad mojodi kam tar az tedad darkhasti ast "); Sleep(3000);

			goto foodlist;
		}
		middle1(); pre(4);  printf("ghaza ye enetekhabi shoma %s  gheymat  %0.2f \n\n", temp->foodname, temp->price*fcquantity); pre(4);
		printf("1. taeed sefaresh \n\n"); pre(4);
		printf("2. baz gasht be menu \n\n");
		printf("baraye taeed sefaresh adad 1 ra vared konid dar gheir in sorat adad 2 vared konid:");

	confirm:
		int confirm;

		fflush(stdin); scanf("%d", &confirm);

		if (confirm == 1) {

			br(2); pre(4);
			printf(" 1. pardakht naghdi");
			br(2); pre(4);
			printf(" 2. pardakht ba cart banki \n");
			printf(" lotfan ravesh pardakht khod ra entekhab konid 1-2: ");
		payment:
			int payment;

			fflush(stdin);  scanf("%d", &payment);

			if (payment == 1) {


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order] = get_food_choice;
				order_quantity[order] = fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice, uquantity);


				cls(); middle1(); pre(4);  printf("===>tashakor az shoma<===");
				br(2); pre(4);  printf("sefaresh shoma ba movafaghiyat sabt shod ...");
				br(2); pre(4);  printf("1. sefaresh digari darid? ");
				br(2); pre(4);  printf("2.bazgash be menu asli \n");
				br(2); pre(4);   printf("entekhab konid: ");
			psmenu:
				int ps_menu;

				fflush(stdin);  scanf("%d", &ps_menu);

				if (ps_menu == 1) { goto foodlist; }
				else if (ps_menu == 2) { goto mainmenu; }
				else { br(2); pre(4); printf("lotfan az menu entekhab konid : "); goto psmenu; }

			}

			///Card

			else if (payment == 2) {

				int card_number[100];

				c++;

				cls(); middle1(); pre(4); printf("shomare cart khod ra vared konid : ");

				fflush(stdin);   scanf("%d", &card_number[c]);



				cardno[c] = card_number[c];

				int pin;

				br(2); pre(2);  printf("ramze cart khod ra vared konid [ma be hich vajh etelaat shoma ro zakhire nemikonim]  : ");

				fflush(stdin);     scanf("%d", &pin);

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order] = get_food_choice;
				order_quantity[order] = fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice, uquantity);

				br(2); pre(4);  printf("pardakht ba movafaghiyat anjam shod...");
				br(2); pre(4);    printf("1.aya sefaresh digari darid? ");
				br(2); pre(4);    printf("2.bazgasht be menu asli \n");
				br(2); pre(4);   printf("entekhab konid: ");
			psmenu2:
				int ps_menu2;

				scanf("%d", &ps_menu2);

				if (ps_menu2 == 1) { goto foodlist; }
				else if (ps_menu2 == 2) { goto mainmenu; }
				else { br(2); pre(4); printf("lotfan az dakhhel menu entekhab konid : "); goto psmenu2; }

			}

			else {

				br(2); pre(4);   printf("sefaresh khod raa az dakhel list entekhab konid: ");

				goto payment;


			}


		}    ///END Confirm



		else if (confirm == 2) {

			goto foodlist;

		}

		else {
			br(2); pre(4);    printf("adad ghaza ye morede nazar khod ra entekhab konid : ");

			goto confirm;


		}  ///end confirm;


	}  ///end get food choice


	else {

		br(2); pre(4);  echo("lotfan az dakhel list entekhab konid"); br(2); Sleep(400);

		goto foodlist;

	}  ///end get food choice
}

void cls() {

	system("cls");

}

void echo(char print[]) {

	printf("%s", print);
}

void br(int line) {
	for (int i = 0; i < line; i++) {
		printf("\n");
	}
}

void pre(int tab) {

	for (int i = 0; i < tab; i++) {
		printf("\t");
	}

}
void span(int space) {

	for (int i = 0; i < space; i++) {
		printf(" ");
	}

}

void main_menu() {

	cls();
	br(5); pre(3); echo(">> 1. modiriate barname"); Sleep(1000);
	br(2); pre(3); echo(">> 2. list ghaza ha"); Sleep(1000);
	br(2); pre(3); echo(">> 3. kharej shodan az barname");  Sleep(1000);
	// Admin Panel");

	br(1);

}

void insertend(int data, char foodname[25], int quantity, float price) {

	node *temp;

	temp = (node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp->quantity = quantity;

	strcpy(temp->foodname, foodname);

	temp->next = NULL;


	if (head == NULL) {
		head = temp;
		list = head;
	}
	else {

		while (head->next != NULL) {
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], int quantity, float price) {

	node *temp;

	temp = (node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	strcpy(temp->foodname, foodname);

	temp->quantity = quantity;


	temp->next = head;

	head = temp;

	list = head;

}

void insertmid(int pos, int data, char foodname[25], int quantity, float price) {

	node *temp;

	temp = (node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp->quantity = quantity;

	strcpy(temp->foodname, foodname);

	while (head->next->data != pos) {


		head = head->next;

	}

	temp->next = head->next;
	head->next = temp;


}

void deletefood(int serial) {

	node *temp;
	temp = (node *)malloc(sizeof(node));

	temp = list;


	if (temp->data != serial) {

		while (temp->next->data != serial) {
			temp = temp->next;
		}

		if (temp->next->data == serial) {

			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\t pak kardan item %d ", serial); for (int cs = 0; cs < 4; cs++) { printf(" ."); Sleep(400); }

			printf("\n\n\n\n\t\t\t ghaza morede nazar ba movafaghiyat sabt shod \n"); Sleep(500);

		}
		else {
			printf("\n\n\n\n\t\t\t qhaza ye morede nazar yaft nashod\n"); Sleep(500);
		}

		head = temp;

	}
	else {

		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\t pak kardan ghaza az menu %d ", serial); for (int cs = 0; cs < 4; cs++) { printf(" ."); Sleep(400); }

		printf("\n\n\n\n\t\t\t ghaza ye morede nazar ba movafaghiyat pak shod \n"); Sleep(500);

		head = temp;

		list = head;
	}
}

void updatefood(int udata, int uquantity) {

	node *temp;
	temp = list;

	while (temp->data != udata) {
		temp = temp->next;

	}
	if (temp->data == udata) {
		temp->quantity = uquantity;
	}

}

int countitem() {

	node *temp;

	temp = list;

	int countitem = 0;

	if (temp == NULL) {
		countitem = 0;
	}
	else {
		countitem = 1;
		while (temp->next != NULL) {
			countitem++;
			temp = temp->next;
		}

	}


	return countitem;

}
void foodlist() {

	ccolor(0);

	printf("\n\t\t"); ccolor(1000);
	printf("....................................................... "); ccolor(26);
	printf("\n\t\t"); ccolor(1000);
	printf("|  shomare   |  esme qhaza  |  qheymat |   tedad mojod   |"); ccolor(26);
	printf("\n\t\t"); ccolor(1000);
	printf("......................................................"); ccolor(26);

	node *temp;

	temp = list;

	while (temp != NULL) {

		ccolor(26);


		printf("\n\t\t"); ccolor(62);
		printf("|     %d      |    %s  |    %0.2f   |    %d    |", temp->data, temp->foodname, temp->price, temp->quantity);
		ccolor(26);
		printf("\n\t\t"); ccolor(62);
		printf("-------------------------------------------------------");


		temp = temp->next;

		Sleep(1000);

	}

	ccolor(26);



}


void order_view(int order, int quantity, int or_no) {



	ccolor(26);

	node *temp;

	temp = list;

	while (temp->data != order) {

		temp = temp->next;

	}
	if (temp->data == order) {

		ccolor(26);

		printf("\n\t\t"); ccolor(62);
		printf("|     %d      |    %s  |     %d     |     %d     |", or_no, temp->foodname, quantity, temp->quantity);
		ccolor(26);
		printf("\n\t\t"); ccolor(62);
		printf("-------------------------------------------------------");

		Sleep(100);

	}

	ccolor(26);

}

void ccolor(int clr) {

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}


///STYLE FUNCTION

void pwellcome() {
	ccolor(26);

	char welcome[50] = "khosh amadid ";
	char welcome2[50] = " be";
	char welcome3[50] = " fastfood iran";
	char welcome4[50] = " system modiriate restooran";
	printf("\n\n\n\n\n\t\t\t");
	for (int wlc = 0; wlc < strlen(welcome); wlc++) {

		printf(" %c", welcome[wlc]);
		Sleep(200);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for (int wlc2 = 0; wlc2 < strlen(welcome2); wlc2++) {

		printf(" %c", welcome2[wlc2]);
		Sleep(200);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for (int wlc3 = 0; wlc3 < strlen(welcome3); wlc3++) {
		if (welcome3[wlc3] != 'D') {

			printf(" %c", welcome3[wlc3]);
		}
		else {

			printf(" %c", welcome3[wlc3]);
		}

		Sleep(200);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t\t ");
	for (int wlc3 = 0; wlc3 < strlen(welcome4); wlc3++) {
		if (welcome4[wlc3] != 'A' && welcome4[wlc3] != 'E') {

			printf(" %c", welcome4[wlc3]);
		}
		else {

			printf(" %c", welcome4[wlc3]);
		}
		Sleep(200);
	}
	ccolor(26);

}
void loadingbar(void) {

	for (int i = 15; i <= 100; i += 5) {

		cls();

		printf("\n\n\n\n\t\t");
		printf("%d %% dar hale amade sazi barname lotfan sabr konid....\n\n\t\t", i);

		printf("");

		for (int j = 0; j < i; j += 2) {

			ccolor(160 + j);
			printf(" ");
			ccolor(26);

		}
		Sleep(100);
		if (i == 90 || i == 50 || i == 96 || i == 83) {
			Sleep(100);
		}

	}

}
void backuploader(void) {

	for (int i = 15; i <= 100; i += 5) {

		cls();
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% backup giri...\n\n\t\t", i);

		printf("");

		for (int j = 0; j < i; j += 2) {

			ccolor(120 + j);
			printf(" ");
			ccolor(26);

		}
		Sleep(50);
		if (i == 90 || i == 50 || i == 96 || i == 83) {
			Sleep(50);
		}
	}

}


void middle1(void) {

	printf("\n\n\n\n\n\n\n");
}

void middtab1(void) {
	printf("\t\t\t\t\t");
}
