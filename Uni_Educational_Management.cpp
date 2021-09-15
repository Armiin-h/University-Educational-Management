// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<fstream>
using namespace std;

using namespace std;
int std_count = 0, tch_count = 0, crs_count = 0, tch_crs_count = 0, std_crs_count = 0;  // Student and Instructor number
struct student {
	char std_no[15], fname[15], lname[15];
	int year, mo, day;
	friend ostream &operator <<(ostream &out, student b);
};
ostream &operator <<(ostream &out, student b) {
	out << "name : " << b.fname << " " << b.lname << " || student number : " << b.std_no << " || born in : " << b.year << "/" << b.mo << "/" << b.day;
	return out;
}
struct teacher {
	int tch_no, em_date;  			  //em_date Hiring date
	char fname[15], lname[15];
	friend ostream &operator <<(ostream &out, teacher b);
};
ostream &operator <<(ostream &out, teacher b) {
	out << "name : " << b.fname << " " << b.lname << " || personal code : " << b.tch_no;
	return out;
}
struct course {
	int crs_no;
	char crsname[20];
	friend ostream &operator <<(ostream &out, course b);
};
ostream &operator <<(ostream &out, course b) {
	out << "Course name : " << b.crsname << " || Code :  " << b.crs_no;
	return out;
}
struct tch_crs {
	int tch_no, crs_no;
	float score;
	tch_crs() {
		score = 111;
		crs_no = 0;
	}
};
struct std_crs {
	char std_no[15];
	int crs_no;
	float score;
	std_crs() {
		score = 111;
		crs_no = 0;
	}
};
const int a = 40;
student std_list[a*5];
teacher tch_list[a/2];
course crs_list[a];
tch_crs tc_list[a*15];
std_crs sc_list[a*50];
int add_std(student *, int);
int add_tch(teacher *, int);
int add_crs(course *, int);
int rem_crs(course *, int);
int add_tch_crs(tch_crs *, int, teacher *, int, course *, int);
int add_std_crs(std_crs *, int, student *, char *, course *, int);
//**int rem_std_crs(std_crs *, int);
int check(char *a, char *b);
float std_avg(std_crs *, char *);
float tch_crs_avg(tch_crs);
float teacher_avg(tch_crs *, int );
void disp_crs_std(std_crs , int , student , int);
void student_crss(std_crs *, char *);
void student_tchs(std_crs *, tch_crs *, char *);
void teacher_crss(int);
//**void teacher_stds(tch_crs *, int, std_crs *, int, int);
void Dis_all_tch(void);
void Dis_all_std(void);
void Dis_all_crs(void);
void menu(void);
void menu_tch();
void menu_tch2(int code =0);
void menu_std();
void menu_std2(char *number =0 );
void menu_crs();
void give_score(int code);
int add_std(student *a, int std_count) {
	int t, i, j;
	cout << "How many students you want to add ?" << endl; cin >> t;
	for (j = 0;t>j;j++,i++) {
		cout << "Please enter student's number : \n";
		cin >> a[i].std_no;
		cout << "Please enter student's first name : \n";
		cin >> a[i].fname;
		cout << "Please enter student's last name : \n";
		cin >> a[i].lname;
		cout << "please enter student's birthday info ; \n year :"; cin >> a[i].year;
		cout << "\n month : "; cin >> a[i].mo;
		cout << "\n day :"; cin >> a[i].day;
	}
	std_count = std_count + t;
	return std_count;
}
int add_tch(teacher *b, int tch_count) {
	int n, i, j;
	cout << "How many teachers you want to add ?" << endl; 
	cin >> n;
	for (j = 0;n>j;j++,i++) {
		cout << "please enter teacher's personality code : \n";
		cin >> b[i].tch_no;
		cout << "please enter teacher's first name : \n";
		cin >> b[i].fname;
		cout << "please enter teacher's last name : \n";
		cin >> b[i].lname;
		cout << "please enter teacher's employment year : \n";
		cin >> b[i].em_date;
	}
	tch_count = tch_count + n;
	return tch_count;
}
int add_tch_crs(tch_crs *c, int tch_crs_count, teacher *b, int tch_count, course *, int){
	int n,i,j;
	cout<< "how many tch_crs you want to add ?" <<endl;
	cin>>n;
	for (j=0;n>j;j++,i++) {
		cout << "please enter teacher's personality code : \n";
		cin >> c[i].tch_no;
		cout << "please enter the course number : \n";
		cin >> c[i].crs_no;
	}
	tch_crs_count = tch_crs_count + n;
	return tch_crs_count ;
}
int add_std_crs(std_crs *d, int std_crs_count, student *a, char *, course *, int){
int n,i,j;
	cout<< "how many std_crs you want to add ?" <<endl;
	cin>>n;
	for (j=0;n>j;j++,i++) {
		cout << "Please enter student's number : \n";
		cin >> d[i].std_no;
		cout << "please enter the course number : \n";
		cin >> d[i].crs_no;
		cout << "Please enter the course score : \n";
		cin >> d[i].score;	
	}
	std_crs_count = std_crs_count + n;
	return std_crs_count ;
}
float tch_crs_avg(tch_crs *d , course *, int score,int tch_crs_count){
	int i, j=0;
	float avg=0;	
	for (i = 0;i <tch_crs_count;i++) {
				if (d[i].score >= 0 && d[i].score <= 20) {
					avg = avg + d[i].score;
					j++;
				}
			}
		avg = avg/j;
		return avg;
	}
void disp_crs_std(std_crs *d, int std_crs_count , student *a, int std_count){
	     int i,j;
		 cout << "Please enter course number : \n";
		 cin >> d[i].crs_no;
		 for (j=0;j<=std_crs_count;j++,i++) {
		 	cout << d[i].std_no; 
		}
}
void teacher_crss(tch_crs *d, char * number) {
	int i, v, j = 1, k,v2=0;
	for (i = 0;i < tch_count;i++) {
		v = check(number, d[i].tch_no);
		if (v == 1) {
			v2 = 1;
			break;
		}
	}
}
	if (v2 == 0) cout << "There is no teachers with this " << number << " code." << endl;
	else{
		v2 = 0;
		cout << "This teacher has : ";
		for (i = 0;i < tch_crs_count;i++) {
			v = check(b[i].tch_no, number);
			if (v == 0) continue;
			else {
				v2 = 1;
				for (k = 0;k < crs_count;k++) {
					if (b[i].crs_no == d[k].crs_no) {
						cout <<endl<< j++ << "- " << d[k].crs_no;
					}
				}
			}
		}
		if (v2 == 0) cout << " No Lessons." << endl;
		else cout << "Lessons." << endl;
	}



















void student_crss(std_crs *a, char * number) {
	int i, v, j = 1, k,v2=0;
	for (i = 0;i < std_count;i++) {
		v = check(number, std_list[i].std_no);
		if (v == 1) {
			v2 = 1;
			break;
		}
	}
	if (v2 == 0) cout << "There is no student with this " << number << " code." << endl;
	else{
		v2 = 0;
		cout << "This student has : ";
		for (i = 0;i < std_crs_count;i++) {
			v = check(a[i].std_no, number);
			if (v == 0) continue;
			else {
				v2 = 1;
				for (k = 0;k < crs_count;k++) {
					if (a[i].crs_no == crs_list[k].crs_no) {
						cout <<endl<< j++ << "- " << crs_list[k].crsname;
					}
				}
			}
		}
		if (v2 == 0) cout << " No Lessons." << endl;
		else cout << "Lessons." << endl;
	}
}
void student_tchs(std_crs *a, tch_crs *b, char * number) {
	int i, v, j = 1, k, v2 = 0;
	for (i = 0;i < std_count;i++) {
		v = check(number, std_list[i].std_no);
		if (v == 1) {
			v2 = 1;
			break;
		}
	}
	if (v2 == 0) cout << "There is no student with this " << number << " code." << endl;
	else {
		v2 = 0;
		cout << "This student has class with : ";
		for (i = 0;i < std_crs_count;i++) {
			v = check(a[i].std_no, number);
			if (v == 0) continue;
			else {
				for (j = 0;j < tch_crs_count;j++) {
					if (a[i].crs_no == b[j].crs_no)
						for (k = 0;k < tch_count;k++) {
							if (b[j].tch_no == tch_list[k].tch_no) {
								cout << endl << tch_list[k].fname << tch_list[k].lname;
								v2 = 1;
							}
						}
				}
			}
		}
		if (v2 == 0) cout << "No teacher";
		cout << endl;
	}
}
int check(char *a, char *b) {
	int i, j, v=1;
	for (i = 0;a[i];i++);
	for (j = 0;b[j];j++);
	if (i == j) {
		for (i = 0;i < j;i++) {
			if (a[i] != b[i]) {
				v = 0;
				break;
			}
		}
	}
	else v = 0;
	return v;
}
float std_avg(std_crs * a, char *number) {
	int i, v, j = 0, v2 = 0;
	float avg = 0;
	for (i = 0;i < std_count;i++) {
		v = check(number, std_list[i].std_no);
		if (v == 1) {
			v2 = 1;
			break;
		}
	}
	if (v2 == 0) {
		cout << "There is no student with this " << number << " code." << endl;
		return -1;
	}
	else {
		for (i = 0;i < std_crs_count;i++) {
			v = check(a[i].std_no, number);
			if (v == 0) continue;
			else {
				if (a[i].score >= 0 && a[i].score <= 20) {
					avg = avg + a[i].score;
					j++;
				}
			}
		}
		avg /= j;
		return avg;
	}
}
float teacher_avg(tch_crs * a, int number ) {
	int i, j=0,v=0;
	float avg=0;
	for (i = 0;i < tch_count;i++) {
		if (tch_list[i].tch_no == number) {
			v = 1;
			break;
		}
	}
	if (v == 0) {
		cout << "There is no teacher with " << number << " personal code." << endl;
		return -1;
	}
	else {
		for (i = 0;i < tch_crs_count;i++) {
			if (a[i].tch_no == number) {
				if(a[i].score>=0 && a[i].score<=20){
					avg += a[i].score;
					j++;
				}
			}
		}
		avg /= j;
		return avg;
	}
}
void Dis_all_tch(void) {
	int i=0;
	cout << "=============================" << endl;
	for (;i < tch_count;i++) cout << tch_list[i]<<endl;
}
void Dis_all_std() {
	int i = 0;
	cout << "----------------------------------" << endl;
	for (;i < std_count;i++) cout << std_list[i]<<endl;
}
void Dis_all_crs(){
	int i = 0;
	cout << "+++++++++++++++++++++++++++++++" << endl;
	for (;i < crs_count;i++) cout << crs_list[i] << endl;
}
int main()
{
	cout << "Welcome to the Portal"<<endl;
	menu();
    return 0;
}
void menu(void){
    int n;
    cout << "Which part you want to go (to exit enter 0) : 1-Teacher 2-Student 3-Course    ";
	do {
		cin >> n;
		if (n > 3 || n < 0) cout << "Wrong number. Enter again :";
	} while (n > 3 || n < 0);
	if (n == 0) exit;
	if (n == 1) {
		cout <<"++++++++++++++++++++++++++++++++++++"<<endl<< "Welcome to Teacher's Session" << endl;
		menu_tch();
		}
	if (n == 2) {
		cout << "***********************************" << endl << "Welcome to Student's Session" << endl;
		menu_std();
	}
	if (n == 3) {
		cout << "-------------------------------------------" << endl << "Welcome to Course's Session" << endl;
		menu_crs();
	}
}
void menu_crs(void) {
	int i, j, v, code;
	char answer;
	cout << "***********************************" << endl;
	cout << "What do you want to do (to go back enter 0) ? " << endl << "1-Add Course" << endl << "2-Remove Course" << endl << "3-Show all the Courses";
	do {
		cin >> j;
		if (j > 3 || j < 0) cout << "Wrong Number. Enter Again : ";
	} while (j > 3 || j < 0);
	if (j == 0) menu();
	if (j == 1) {
		crs_count = add_crs(crs_list, crs_count);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_crs();
		else menu();
	}
	if (j == 2) {
		crs_count = rem_crs(crs_list, crs_count);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_crs();
		else menu();
	}
	if (j == 3) {
		Dis_all_crs();
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_crs();
		else menu();
	}
}
void menu_std(void) {
	int i, j, v = 0,op;
	char number[15];
	char answer='y';
	cout << "======================================" << endl;
	cout << "What do you want to do (to go back enter 0) ? " << endl << "1-Sing up new Student" << endl << "2-Display all the studnets";
	cout << endl << "3-Sing in";
	do {
		cin >> op;
		if (op > 3 || op < 0) cout << "Wrong Number. Enter again : ";
	} while (op > 3 || op < 0);
	if (op == 0) menu();
	if (op == 1) {
		std_count = add_std(std_list, std_count);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_std();
		else menu();
	}
	if (op == 2) {
		Dis_all_std();
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_std();
		else menu();
	}
	if (op == 3) {
		cout << "Enter your Student's number : ";
		cin >> number;
		for (i = 0;i < std_count;i++) {
			v = check(std_list[i].std_no, number);
			if (v == 1) break;
		}
		if (v == 0) {
			cout << "There is no student with " << number << " number."<<endl;
			cout << "Do you want to do more ? (y/n)   ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') menu_std();
			else menu();
		}
		else {
			cout << "Hi " << std_list[i].fname << " " << std_list[i].lname << endl;
			menu_std2(number);
		}
	}
}
void menu_std2(char * number) {
	int i, j, v;
	char answer;
	float score;
	for (i = 0;i < std_count;i++) {
		v = check(std_list[i].std_no, number);
		if (v == 1) break;
	}
	cout << "++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "What Do you want to do (to go back enter 0) ? " << endl;
	cout << "1-Add a new Course" << endl << "2-Show all your Courses" << endl << "3-Remove a Course" << endl;
	cout << "4-Show your Teachers" << endl << "5-Your Score avrage" << endl;
	do {
		cin >> j;
		if (j > 5 || j < 0) cout << "Wrong Number. Enter again : ";
	} while (j > 5 || j < 0);
	if (j == 0) menu_std();
	if (j == 1) {
		std_crs_count= add_std_crs(sc_list,std_crs_count, std_list, number, crs_list, crs_count);
		cout << "Do you want to do more ? (y/n)  ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_std2(number);
		else menu();
	}
	if (j == 2) {
		student_crss(sc_list, number);
		cout << "Do you want to do more ? (y/n)  ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_std2(number);
		else menu();
	}
	if (j == 3) {
		rem_std_crs(sc_list, std_crs_count);
		cout << "Do you want to do more ? (y/n)  ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_std2(number);
		else menu();
	}
	if (j == 4) {
		student_tchs(sc_list, tc_list, number);
		cout << "Do you want to do more ? (y/n)  ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_std2(number);
		else menu();
	}
	if (j == 5) {
		score = std_avg(sc_list, number);
		cout << "Your Avrage Score at this point =" << score;
		cout << "Do you want to do more ? (y/n)  ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_std2(number);
		else menu();
	}
}
void menu_tch() {
	int i, op, j, v = 0,code;
	float score;
	char answer = 'y';
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "What do you want to do ? (to go back enter 0)" << endl << "1-Sing up a new Teacher" << endl << "2-Display all the teachers";
	cout << "3-Sing in" << endl;
	do {
		cin >> op;
		if (op > 3 || op < 0) cout << "Wrong number. Enter again :";
	} while (op > 3 || op < 0);
	if (op == 0) menu();
	if (op == 1) {
		tch_count = add_tch(tch_list, tch_count);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if(answer=='y' || answer=='Y' ) menu_tch();
		else menu();
	}
	if (op == 2) { 
		Dis_all_tch();
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_tch();
		else menu();
	}
	if (op == 3) {
		v = 0;
		cout << "Enter your personal code : ";
		cin >> code;
		for (i = 0;i < tch_count;i++) {
			if (tch_list[i].tch_no == code) v = 1;
		}
		if (v == 0) {
			cout << "Sorry the teacher with " << code << " personal code was not found :(" << endl;
			cout << "Do you want to do more ? (y/n)   ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') menu_tch();
			else menu();
		}
		if (v == 1) {
			cout << "Hi " << tch_list[i].fname << " " << tch_list[i].lname << endl;
			menu_tch2(code);
		}
	}
}
void menu_tch2(int code){
	int i, j, v = 0;
	float score;
	char answer = 'y';
	for (i = 0;tch_list[i].tch_no != code;i++);
	cout << "-----------------------------------" << endl;
	cout << "What do you want to do (to go back enter 0) : " << endl << "1-Add a new course" << endl << "2-Show your courses" << endl;
	cout << "3-Show your avrage score" << endl << "4-Show your students" << "5-Show your info" << endl<<"6-Give score"<<endl;
	do {
		cin >> j;
		if (j > 5 || j < 0) cout << "Wrong number. Enter again: ";
	} while (j > 5 || j < 0);
	if (j == 0) menu_tch();
	if (j == 1) {
		tch_crs_count = add_tch_crs(tc_list, tch_crs_count, tch_list, tch_count, crs_list, crs_count);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_tch2();
		else menu();
	}
	if (j == 2) {
		teacher_crss(code);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_tch2();
		else menu();
	}
	if (j == 3) {
		score = teacher_avg(tc_list, code);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_tch2();
		else menu();
	}
	if (j == 4) {
		teacher_stds(tc_list, tch_crs_count, sc_list, std_crs_count, code);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_tch2();
		else menu();
	}
	if (j == 5) {
		cout << "You are " << tch_list[i].fname << " " << tch_list[i].lname << " With " << tch_list[i].tch_no << " Personality code and have been employed since " << tch_list[i].em_date;
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_tch2();
		else menu();
	}
	if (j == 6) {
		give_score(code);
		cout << "Do you want to do more ? (y/n)   ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') menu_tch2();
		else menu();
	}
}
