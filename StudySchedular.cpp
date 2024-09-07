#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Task{
    string name;
    float time;
    Task(string name, int time, int w): name(name), time(w/time) {}
};
class Scheduler{
    int parent(int n){ return (n)/2;};
    int leftChild(int n) { return 2*n+1;};
    int rightChild(int n) { return 2*n+2;};

    void heapifyup(){
        int i = tasks.size()-1;
        while (i > 0 && tasks[parent(i)]->time < tasks[i]->time) {
            swap(tasks[parent(i)], tasks[i]);
            i = parent(i);
        }
    }

    void heapifydown(int index){
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        if (left < tasks.size() && tasks[left]->time > tasks[smallest]->time) {
            smallest = left;
        }

        if (right < tasks.size() && tasks[right]->time > tasks[smallest]->time) {
            smallest = right;
        }

        if (smallest != index) {
            swap(tasks[index], tasks[smallest]);
            heapifydown(smallest);
        }
    }
    public:
    vector<Task*> tasks;
    void add_task(string n,int data,int w){
        Task* task = new Task(n,data,w);
        tasks.push_back(task);
        heapifyup();
    }
    Task* deletetask(){
        if (tasks.empty()) {
            throw runtime_error("Heap is empty");
        }
        Task* temp = tasks.front();
        tasks[0]=tasks.back();
        tasks.pop_back();
        heapifydown(0);
        return temp;
    }
};
int main(){
    Scheduler table;
    int n;
    cout<<"Enter number of chapters in your subject-";
    cin>>n;
    string name; int time,w;
    for(int i=0;i<n;i++){
        cout<<"Enter name of chapter-";
        cin>>name;
        cout<<"Enter time requiried to prepare and weightage of chapter-\n"; 
        cin>>time; cin>>w;
        table.add_task(name,time,w);
    }
    for(int i=0;i<n;i++){
    cout<<table.deletetask()->name<<endl;
    }
}