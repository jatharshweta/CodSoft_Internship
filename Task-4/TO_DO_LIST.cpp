#include<iostream>
#include<string.h>
using namespace std;
struct Tasks{
	string name;
	bool isCompleted;
};
Tasks tasks[100];
int task_count=0;
void add_task()
{
	string name;
	cout<<"Enter Task name: ";
	cin>>name;
	tasks[task_count].name=name;
	tasks[task_count].isCompleted=false;
	task_count++;
	cout<<"Task Addes..!\n";
}
void view_task()
{
	if(task_count==0){
		cout<<"No task is available..";
		return;
	}
	for(int i=0;i<task_count;i++)
	{
	cout << i + 1 << ". " << tasks[i].name
     << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";

	}
}
void mark_completed(){
	view_task();
	if(task_count==0)
	{
	return;	
	} 
	int number;
	cout<<"Enter task number to mark as completed: ";
	cin>>number;
	if (number <= 0 || number > task_count) {
        cout << "Invalid number!\n";
    } else {
        tasks[number - 1].isCompleted = true;
        cout << "Task marked completed!\n";
    }
}
void remove_task()
{
	view_task();
	if(task_count==0)
	{
	return;	
	}
	int number;
    cout << "Enter task number to remove: ";
    cin >> number;
    if (number <= 0 || number > task_count) {
        cout << "Invalid number!\n";
    } else {
        // Shift tasks left to remove the selected task
        for (int i = number - 1; i < task_count - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        task_count--;
        cout << "Task removed!\n";
}
}
int main()
{
	int ch;
	while(true)
	{
		cout<<"\n--TO-DO LIST--\n";
		cout<<"1.Add Task\n";
		cout<<"2.View Tasks\n";
		cout<<"3.Mark Task as Completed\n";
		cout<<"4.Remove Task\n";
		cout<<"5.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		
		if(ch==1){
			add_task();
		}
		else if(ch==2)
		{
			view_task();
		}
		else if(ch==3)
		{
			mark_completed();
		}
		else if(ch==4)
		{
			remove_task();
		}
		else if(ch==5)
		{
			cout<<"Exiting..\n";
			break;
		}
		else{
			cout<<"Invalid Choice...Enter Correct Choice..";
		}
	}
	return 0;
}
