#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Task {
    int time;
    int benefit;

    Task(int t, int b) : time(t), benefit(b) {}
};
//ordena por tiempo
bool compareTasks(const Task& task1, const Task& task2) {
    return task1.time > task2.time;
}

vector<Task> scheduleTasks(const vector<Task>& tasks, int totalTime) {
    vector<Task> selectedTasks;

    // Ordenar las tareas por beneficio en orden descendente
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), compareTasks);

    int currentTime = 0;
    for (const auto& task : sortedTasks) {
        if (currentTime + task.time <= totalTime) {
            selectedTasks.push_back(task);
            currentTime += task.time;
        }
    }

    return selectedTasks;
}

int main() {
    //Lo estoy ordenando en base al beneficio
    vector<Task> tasks;
    tasks.push_back(Task(2, 50));
    tasks.push_back(Task(1, 30));
    tasks.push_back(Task(2, 15));
    tasks.push_back(Task(1, 10));

    int totalTime = 4;

    vector<Task> selectedTasks = scheduleTasks(tasks, totalTime);
    cout<<"Se esta ordenando por tiempo de mayor a menor"<<endl;
    cout<<"Y se agregaran mientras que el tiempo acumulado sea menor igual a totalTime (4)"<<endl;

    cout << "Tareas seleccionadas: \n";
    for (const auto& task : selectedTasks) {
        cout << "Tiempo: " << task.time << ", Beneficio: " << task.benefit << endl;
    }

    return 0;
}
