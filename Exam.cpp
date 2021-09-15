#include<iostream>
using namespace std;
int std_count=0 , tch_count=0,crs_count = 0, tch_crs_count = 0 , std_crs_coun=0;  // student and instructor number
struct student{
	char std_no[15],fname [15],lname [15];
	int year,mo,day;
};
struct teacher{
	int tch_no, em_date;  			  //em_date exam date
	char fname [15], lname [15];
};
struct course{
	int crs_no;
	char crsname [20];
};
struct tch_crs{
	teacher t;
	int crs_no;
	float score;
	tch_crs(){
		score=111;
	}
};
struct std_crs{
	student s;
	int crs_no;
	float score;
	std_crs(){
		score=111;
	}
};
student std_list [200];
teacher tch_list [20];
course crs_list [40];
tch_crs tc_list [600];
std_crs sc_list [2000]
//int add_std(student , int);
//int add_tch(teacher , int);
**int add_tch_crs(tch_crs, int , teacher , int , course , int);
**int add_std_crs(std_crs, int , student , int , course , int );
**int rem_std_crs(std_crs , int);
//void disp_crs_std(std_crs , int , student , int);
--void student_crss(std_crs,char);
--void student_tchs(std_crs, tch_crs , char);
**void teacher_crss(int);
--float std_total(std_crs , char);
//float tch_crs_total(tch_crs);
--float teacher_total(tch_crs , int);
**void teacher_stds(tch_crs, std_crs , int , int , int);
--int main(){
}
int add_std(struct student *a , int std _count){
	int t,i,j;
	cout <<"how many std ?"<<endl; cin>>t;
	for (j=0;t>j;j++;i++){
		cout<<"please enter std_no : \n";
		cin>>a[i].std_no;
		cout<<"please enter std first name : \n";
		cin>>a[i].fname;
		cout<<"please enter std last name : \n";
		cin>>a[i].lname;
		cout<<"please enter std birthday info ; \n year :"; cin>>a[i].yaer; 
		cout<<"\n month : "; cin>>a[i].mo;
		cout<<"\n day :"; cin>>a[i].day;
	}
	std_count=std_count+t;
	return std_count;
}
int add_tch(struct teacher *b , int tch_count){
	int n,i,j;
	cout<<"how many tch ?"<<endl; cin>>n;
	for (j=0;n>j;j++;i++){
		cout<<"please enter tch_no : \n";
		cin>>b[i].tch_no;
		cout<<"please enter tch first name : \n";
		cin>>b[i].fname;
		cout<<"please enter tch last name : \n";
		cin>>b[i].lname;
		cout<<"please enter employment year : \n";
		cin>>b[i].em_date;
	}
	tch_count=tch_count+n;
	return tch_count;
}

