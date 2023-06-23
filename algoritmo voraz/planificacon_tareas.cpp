#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int time;
    int benefit;

    Task(int t, int b) : time(t), benefit(b) {}
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.benefit > task2.benefit;
}

std::vector<Task> scheduleTasks(const std::vector<Task>& tasks, int totalTime) {
    std::vector<Task> selectedTasks;

    // Ordenar las tareas por beneficio en orden descendente
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), compareTasks);

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
    std::vector<Task> tasks;
    tasks.push_back(Task(2, 10));
    tasks.push_back(Task(1, 5));
    tasks.push_back(Task(3, 15));
    tasks.push_back(Task(2, 8));
    tasks.push_back(Task(4, 12));
    tasks.push_back(Task(1, 6));

    int totalTime = 7;

    std::vector<Task> selectedTasks = scheduleTasks(tasks, totalTime);

    std::cout << "Tareas seleccionadas: \n";
    for (const auto& task : selectedTasks) {
        std::cout << "Tiempo: " << task.time << ", Beneficio: " << task.benefit << std::endl;
    }

    return 0;
}
