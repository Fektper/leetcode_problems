#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct taskInfo{
    int taskId;
    int userId;
    int priority;
    bool valid;
};

class CompareTasksSmaller{
public:
    bool operator() (taskInfo& a, taskInfo& b) const{
        if (a.priority < b.priority){
            return true;
        }
        else if (a.priority > b.priority){
            return false;
        }
        else{
            return a.taskId < b.taskId;
        }
    }
};

class TaskManager {
public:
    unordered_map<int, taskInfo> taskInfoMap;
    priority_queue<taskInfo, vector<taskInfo>, CompareTasksSmaller> taskQueue;

    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> task: tasks){
            taskInfoMap[task[1]] = {task[1], task[0], task[2], true};
            taskQueue.push({task[1], task[0], task[2], true});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfoMap[taskId] = {.taskId = taskId, .userId = userId, .priority = priority, .valid = true};
        taskQueue.push({.taskId = taskId, .userId = userId, .priority = priority, .valid = true});
    }
    
    void edit(int taskId, int newPriority) {
        taskInfoMap[taskId].priority = newPriority;
        taskQueue.push(taskInfoMap[taskId]);
    }
    
    void rmv(int taskId) {
        taskInfoMap[taskId].valid = false;
    }
    
    int execTop() {
        taskInfo topQueue;
        taskInfo reference;
        while (taskQueue.size() > 0){
            topQueue = taskQueue.top();
            taskQueue.pop();

            reference = taskInfoMap[topQueue.taskId];
            if (!reference.valid){
                continue;
            }
            if (reference.priority != topQueue.priority || reference.userId != topQueue.userId){
                continue;
            }
            else{
                taskInfoMap[topQueue.taskId].valid = false;
                return topQueue.userId;
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */