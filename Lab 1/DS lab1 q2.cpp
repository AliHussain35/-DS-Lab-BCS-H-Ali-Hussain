#include<iostream>
using namespace std;
class Exam{
	private:
		string* studentName;
		string* examDate;
		int* score;
	public:
		Exam(string n, string d, int s){
			studentName = new string(n);
			examDate = new string(d);
			score = new int(s);
		}
		void setName(string name){
			*studentName = name;
		}
		void setExamDate(string date){
			*examDate = date;
		}
		void setScore(int s){
			*score = s;
		}
		void displayDetails(){
			cout<<"Student Name = "<<*studentName<<endl;
			cout<<"Exam Date = "<<*examDate<<endl;
			cout<<"Score = "<<*score<<endl;
		}
		~Exam(){
			delete studentName;
			delete examDate;
			delete score;
		}
};
int main(){
    Exam s1("Ali Hussain", "3/1/2026",90);
    s1.displayDetails();
    Exam s2 = s1;
    s2.displayDetails();
    s1.setName("Mohsin Ahmed");
    s1.setScore(88);
    cout<<"Student 1 displayed"<<endl;
    s1.displayDetails();
    cout<<"Student 2 Displayed"<<endl;
    s2.displayDetails();
}
